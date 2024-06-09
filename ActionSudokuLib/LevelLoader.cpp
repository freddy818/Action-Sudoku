/**
 * @file LevelLoader.cpp
 * @author Aion
 */

#include "pch.h"
#include "LevelLoader.h"
#include "DeclarationBackground.h"
#include "DeclarationDigit.h"
#include "Item.h"
#include "DeclarationTrap.h"
#include "DeclarationSparty.h"
#include "DeclarationGiven.h"
#include "DeclarationXray.h"
#include "DeclarationContainer.h"
#include <algorithm>
#include <wx/tokenzr.h>

///The Number of rows
int const NumRows = 9;
///The number of columns
int const NumCols = 9;
/**
 * Load the level from an xl file
 * @param gameToLoad the game that is being loaded
 * @param filename name of the file to load
 */
void LevelLoader::LoadLevel(Game *gameToLoad, const wxString &filename)
{
    std::vector<std::shared_ptr<Item>> items;

    mGame = gameToLoad;

    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Level file");
        throw std::exception();
    }

    mGame->Clear();
    mDeclarations.clear();

    auto root = xmlDoc.GetRoot();
    int levelWidth, levelHeight, tileWidth, tileHeight;
    root->GetAttribute(L"width").ToInt(&levelWidth);
    root->GetAttribute(L"height").ToInt(&levelHeight);
    root->GetAttribute(L"tilewidth").ToInt(&tileWidth);
    root->GetAttribute(L"tileheight").ToInt(&tileHeight);
    mGame->SetLevelWidth(levelWidth);
    mGame->SetLevelHeight(levelHeight);
    mGame->SetTileWidth(tileHeight);
    mGame->SetTileHeight(tileWidth);

    auto child = root->GetChildren();
    for(; child; child = child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"declarations")
        {
            CreateDeclarations(child);
        }
        else if(name == L"game")
        {
            CreateSolution(child, mGame->GetSolArr());
        }
        else if(name == L"items")
        {
            mGame->ResetContainers();
            mGame->ResetTraps();
            items = CreateItems(child);
        }
    }
    mGame->SetItems(items);
    //reset scoreboard
    mGame->StartScoreBoard();
    mGame->SetCurrentLevelTitle(filename);
}

/**
 * Parse through the declarations and put them into map with key as ID;
 * @param declRoot the declaration root in the xml file
 */
void LevelLoader::CreateDeclarations(wxXmlNode *declRoot)
{
    wxString id;
    auto child = declRoot->GetChildren();
    for(; child; child = child->GetNext())
    {
        id = child->GetAttribute(L"id");
        auto name = child->GetName();
        if(name == L"background")
        {
            mDeclarations.insert({id, std::make_shared<DeclarationBackground>(mGame, child)});
        }
        else if(name == L"digit")
        {
            mDeclarations.insert({id, std::make_shared<DeclarationDigit>(mGame, child)});
        }
        else if(name == L"sparty")
        {
            mDeclarations.insert({id, std::make_shared<DeclarationSparty>(mGame, child)});
        }
        else if(name == L"given")
        {
            mDeclarations.insert({id, std::make_shared<DeclarationGiven>(mGame, child)});
        }
        else if(name == L"xray")
        {
            mDeclarations.insert({id, std::make_shared<DeclarationXray>(mGame, child)});
        }
        else if(name == L"container")
        {
            mDeclarations.insert({id, std::make_shared<DeclarationContainer>(mGame, child)});
        }
        else if (name == L"trap")
        {
            mDeclarations.insert({id, std::make_shared<DeclarationTrap>(mGame,child)});
        }
    }
}

/**
 * Parse the items to be created, create them and add to mItems
 * @param itemRoot item root in the xml file
 * @return a vector of items
 */
std::vector<std::shared_ptr<Item>> LevelLoader::CreateItems(wxXmlNode *itemRoot)
{
    std::vector<std::shared_ptr<Item>> items;

    wxString id;
    wxString cId;
    auto child = itemRoot->GetChildren();
    for(; child; child = child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"background" || name == L"digit" || name == L"sparty" || name == L"given" || name == L"xray"
            || name == L"trap")
        {
            if (name == L"trap")
            {
                mGame->AddTrapCount();
            }

            id = child->GetAttribute(L"id");
            auto declaration = mDeclarations[id];
            auto item = declaration->Create(child);
            items.push_back(item);
        }
        else if( name == L"container")
        {
            id = child->GetAttribute(L"id");
            auto declaration = mDeclarations[id];
            std::shared_ptr<Item> item = declaration->Create(child);
            items.push_back(item);

            auto containerChildren = child->GetChildren();
            for (; containerChildren; containerChildren = containerChildren->GetNext())
            {
                cId = containerChildren->GetAttribute(L"id");
                auto cDeclaration = mDeclarations[cId];
                auto cItem = cDeclaration->Create(containerChildren);
                item->SetItem(cItem);
                mGame->AddContainer();
            }
        }
    }
    return items;
}

/**
 * Parse the solution and store it in game in a 9x9 int array
 * @param solutionRoot the root of the solution in the xml file
 * @param sol an array
 */
void LevelLoader::CreateSolution(wxXmlNode *solutionRoot, int (*sol)[NumRows])
{
    int col, row;
    solutionRoot->GetAttribute(L"col").ToInt(&col);
    solutionRoot->GetAttribute(L"row").ToInt(&row);
    mGame->SetSolCol(col);
    mGame->SetSolRow(row);

    wxString solText = solutionRoot->GetNodeContent();
    wxStringTokenizer tokenizer(solText, " ");

    std::vector<int> numbers;
    while(tokenizer.HasMoreTokens())
    {
        wxString token = tokenizer.GetNextToken();
        numbers.push_back(wxAtoi(token));
    }

    int index = 0;
    for(int i = 0; i < NumRows; i++)
    {
        for (int j = 0; j < NumCols; j++)
        {
            sol[i][j] = numbers[index];
            index++;
        }
    }
}
