/**
 * @file ItemXray.cpp
 * @author Aion
 */

#include "pch.h"
#include "ItemXray.h"
#include "DeclarationXray.h"
#include "ItemDigit.h"
#include "FindDigitToReg.h"
#include "Game.h"

using namespace std;

/// Constant for scaling eaten digits
const double SCALE = 1.5;

/// Constant for offset for xray
const double OFFSET = 20;

/**
 * Constructor
 * @param declaration the declaration for Xrays
 * @param node a wxXmlNode object
 */
ItemXray::ItemXray(DeclarationXray *declaration, wxXmlNode *node) : Item(declaration, node)
{
    wxString path = L"images/" + declaration->GetImageName();
    mItemImage = std::make_unique<wxImage>(path);

    mCapacity = declaration->GetCapacity();

    // Seed the random number generator
    random_device rd;
    mRandom.seed(rd());
}

/**
 * Drawing the X-Ray
 * @param graphics the graphics context being drawn on to
 * @param tileWidth the width of the tiles
 * @param tileHeight the height of the tiles
 */
void ItemXray::Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight)
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
 * Add a digit to the stomach is the stomach is not full
 * @param digit Digit to add
 * @return true if the item was added
 */
bool ItemXray::Add(ItemDigit *digit)
{
    if(mStomachItems.size() >= mCapacity)
        return false;

    mStomachItems.push_back(digit);

    std::uniform_real_distribution<> distributionX(0, GetWidth() - OFFSET);
    std::uniform_real_distribution<> distributionY(0, GetHeight() - OFFSET);

    double x = GetCol() + (distributionX(mRandom)) / GetGame()->GetTileWidth();
    double y = GetRow() - (distributionY(mRandom)) / GetGame()->GetTileHeight();

    digit->SetWidth(digit->GetWidth() / SCALE);
    digit->SetHeight(digit->GetHeight() / SCALE);

    digit->SetLocation(x, y);
    digit->SetEaten(true);
    return true;
}

/**
 * Xray will no longer display number when regurgitated
 * @param number number being regurgitated
 * @param x target X location of the regurgitate
 * @param y target Y location of the regurgitate
 */
void ItemXray::Regurgitate(int number, double x, double y)
{
    FindDigitToReg visitor(number);

    for(auto digitIter = mStomachItems.begin(); digitIter != mStomachItems.end(); ++digitIter)
    {
        (*digitIter)->Accept(&visitor);

        if(visitor.GetDigit() == *digitIter)
        {
            (*digitIter)->SetLocation(x, y);
            (*digitIter)->SetWidth((*digitIter)->GetWidth() * SCALE);
            (*digitIter)->SetHeight((*digitIter)->GetHeight() * SCALE);
            (*digitIter)->SetEaten(false);

            mStomachItems.erase(digitIter);
            break;
        }
    }
}
