/**
 * @file ItemContainer.cpp
 * @author Aion
 */

#include "pch.h"
#include "ItemContainer.h"
#include "DeclarationContainer.h"
#include <random>

/**
 * Constructor for container
 * @param declaration
 * @param node
 */
ItemContainer::ItemContainer(DeclarationContainer *declaration, wxXmlNode *node) : Item(declaration, node)
{
    wxString path = L"images/" + declaration->GetImageName();
    mItemImage = std::make_unique<wxImage>(path);

    path = L"images/" + declaration->GetFrontImageName();
    mFrontImage = std::make_unique<wxImage>(path);


}

/**
 * Draw container and the numbers it contain
 * @param graphics
 * @param tileWidth
 * @param tileHeight
 */
void ItemContainer::Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight)
{
    if(mItemBitmap.IsNull())
    {
        mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
    }
    if(mFrontBitmap.IsNull())
    {
        mFrontBitmap = graphics->CreateBitmapFromImage(*mFrontImage);
    }

    double xPos = GetCol() * tileWidth;
    double yPos = (GetRow() + 1) * tileHeight - GetHeight();
    double wid = GetWidth();
    double hit = GetHeight();

    graphics->DrawBitmap(mItemBitmap, xPos, yPos, wid, hit);

    // TO DO draw the numbers it includes
    for(auto item : mDigits)
    {
        item->Draw(graphics, tileWidth, tileHeight);
    }

    graphics->DrawBitmap(mFrontBitmap, xPos, yPos, wid, hit);


}

/**
 * Handling when a container gets hit by a headbutt
 */
void ItemContainer::ContainerHit()
{
    for (auto digit : mDigits)
    {
        std::uniform_real_distribution<> xDistribution(GetCol()-GetWidth()/2.0/GetGame()->GetTileWidth(),
                                                       GetCol()+GetWidth()/2.0/GetGame()->GetTileWidth() );
        //using literal constant here because i just want half the width
        mDigitX = xDistribution(GetGame()->GetRandom());


        std::uniform_real_distribution<> yDistribution(GetRow()-GetHeight()*2.0/GetGame()->GetTileHeight(),
                                                       GetRow()-GetHeight()/GetGame()->GetTileHeight());
                                        //using literal constant here because i just want double the height
        mDigitY = yDistribution(GetGame()->GetRandom());

        digit->SetLocation(mDigitX, mDigitY);

        GetGame()->ItemPushBack(digit);

    }
    mDigits.clear();
}


