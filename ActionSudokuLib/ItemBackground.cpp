/**
 * @file ItemBackground.cpp
 * @author Aion
 */

#include "pch.h"
#include "ItemBackground.h"
#include "DeclarationBackground.h"

/**
 * Constructor
 * @param declaration declaration for the background
 * @param node wxXmlNode object
 */
ItemBackground::ItemBackground(DeclarationBackground *declaration, wxXmlNode *node) : Item(declaration, node)
{
    wxString path = L"images/" + declaration->GetImageName();
    mItemImage = std::make_unique<wxImage>(path);
}

/**
 * Draw the background
 * @param graphics the graphics context being drawn onto
 * @param tileWidth the tile width of the game
 * @param tileHeight the tile height of the game
 */
void ItemBackground::Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight)
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
