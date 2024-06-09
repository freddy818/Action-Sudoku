/**
 * @file Item.cpp
 * @author Aion
 */

#include "pch.h"
#include "Item.h"
#include "Declaration.h"
#include "Game.h"

/**
 * Constructor
 * @param declaration
 * @param node
 */
Item::Item(Declaration *declaration, wxXmlNode *node) : mDeclaration(declaration)
{
    node->GetAttribute(L"col").ToDouble(&mCol);
    node->GetAttribute(L"row").ToDouble(&mRow);
    mGame = declaration->GetGame();
}


/**
 * Draws the item on to the screen
 * @param graphics context being drawn onto
 * @param tileWidth the tile width of the game
 * @param tileHeight the tile height of the game
 */
void Item::Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight)
{

}

