/**
 * @file LoadTest.cpp
 * @author Aion
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <iostream>

#include <Game.h>
#include <LevelLoader.h>
#include <Item.h>

using namespace std;

class LoadTest : public ::testing::Test
{
protected:

};

TEST_F(LoadTest, Construct)
{
    Game game;
}

TEST_F(LoadTest, Traversing)
{
    wxString path = L"levels/level1.xml";

    wxXmlDocument doc;
    ASSERT_EQ(doc.Load(path), true) << L"Test XML file opens";

    auto root = doc.GetRoot();
    int levelWidth, levelHeight, tileWidth, tileHeight;
    root->GetAttribute(L"width").ToInt(&levelWidth);
    root->GetAttribute(L"height").ToInt(&levelHeight);
    root->GetAttribute(L"tilewidth").ToInt(&tileWidth);
    root->GetAttribute(L"tileheight").ToInt(&tileHeight);
    ASSERT_EQ(levelWidth, 20) << L"Test correct attribute values";
    ASSERT_EQ(levelHeight, 15) << L"Test correct attribute values";
    ASSERT_EQ(tileWidth, 48) << L"Test correct attribute values";
    ASSERT_EQ(tileHeight, 48) << L"Test correct attribute values";

    int declarationCount = 0;
    int itemCount = 0;

    auto child = root->GetChildren();
    for(; child; child = child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"declarations")
        {
            auto node = child->GetChildren();
            for (; node; node = node->GetNext())
            {
                declarationCount++;
            }
        }
        else if(name == L"game")
        {
            auto content = child->GetContent();
        }
        else if(name == L"items")
        {
            auto node = child->GetChildren();
            for (; node; node = node->GetNext())
            {
                itemCount++;
            }
        }
    }

    ASSERT_EQ(declarationCount, 21) << L"Load can traverse all declarations";
    ASSERT_EQ(itemCount, 84) << L"Load can traverse all items";
}

