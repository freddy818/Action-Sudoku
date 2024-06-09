/**
 * @file ItemGiven.cpp
 * @author adity
 */

#include "pch.h"
#include "ItemGiven.h"
#include "DeclarationGiven.h"

/**
 * constructor
 * @param declaration given declaration
 * @param node wxXmlNode object
 */
ItemGiven::ItemGiven(DeclarationGiven *declaration, wxXmlNode *node) : Item(declaration, node)
{
    wxString path = L"images/" + declaration->GetImageName();
    mItemImage = std::make_unique<wxImage>(path);

    mValue = declaration->GetValue();
}

/**
 * Draw the given digit
 * @param graphics graphics context being drawn to
 * @param tileWidth tile width of game
 * @param tileHeight tile height of game
 */
void ItemGiven::Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight)
{
    if(mItemBitmap.IsNull())
    {
        mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
    }

    graphics->DrawBitmap(mItemBitmap,
                         GetCol() * tileWidth,
                         GetRow() * tileHeight,
                         GetWidth(),
                         GetHeight());
}
