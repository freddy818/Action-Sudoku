/**
 * @file ItemDigit.cpp
 * @author adity
 */

#include "pch.h"
#include "ItemDigit.h"
#include "DeclarationDigit.h"

/**
 * Constructor
 * @param declaration item declarations
 * @param node wxXmlNode object
 */
ItemDigit::ItemDigit(DeclarationDigit *declaration, wxXmlNode *node) : Item(declaration, node)
{
    wxString path = L"images/" + declaration->GetImageName();
    mItemImage = std::make_unique<wxImage>(path);

    mValue = declaration->GetValue();
}

/**
 * Draw a digit
 * @param graphics the graphics context being drawn to
 * @param tileWidth the tile width of the game
 * @param tileHeight the tile height of the game
 */
void ItemDigit::Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight)
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

/**
 * Test to see if we hit this object
 * @param x X position to test in columns
 * @param y Y position to test in rows
 * @return true if hit
 */
bool ItemDigit::HitTest(double x, double y)         // remove hardcoded values
{
    double testX = (x - GetCol())*48 + GetWidth()/2;
    double testY = (y - GetRow())*48 + GetHeight()/2;

    if(testX < 0 || testY < 0 || testX >= GetWidth() || testY >= GetHeight())
    {
        return false;
    }
    return true;
}
