/**
 * @file ItemTrap.cpp
 * @author Frederick Fan
 */

#include "pch.h"
#include "ItemTrap.h"
#include "DeclarationTrap.h"

/**
 * Constructor
 * @param declaration item declarations
 * @param node wxXmlNode object
 */
ItemTrap::ItemTrap(DeclarationTrap *declaration, wxXmlNode *node) : Item(declaration, node)
{
    wxString path = L"images/" + declaration->GetImageName();
    mItemImage = std::make_unique<wxImage>(path);

}

/**
 * Draw a digit
 * @param graphics the graphics context being drawn to
 * @param tileWidth the tile width of the game
 * @param tileHeight the tile height of the game
 */
void ItemTrap::Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight)
{
    if(mItemBitmap.IsNull())
    {
        mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
    }

    graphics->DrawBitmap(mItemBitmap,
                         GetCol() * tileWidth,
                         (GetRow() + 1) * tileHeight - GetHeight(),
                         GetWidth(),
                         GetHeight());
}