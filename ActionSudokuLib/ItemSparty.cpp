/**
 * @file ItemSparty.cpp
 * @author Aion
 */

#include "pch.h"
#include "ItemSparty.h"
#include "DeclarationSparty.h"
#include "XrayFinder.h"
#include "ItemXray.h"
#include "FindDigitToEat.h"
#include "ContainerFinder.h"
#include "ItemDigit.h"
#include "TrapFinderVisitor.h"
#include "DigitGivenFinder.h"

/// Character speed in pixels per second
const double MaxSpeed = 400.0;

/// The time for an eating cycles in seconds
const double EatingTime = 0.5;

/// The time for a headbutt cycle in seconds
const double HeadbuttTime = 0.25;

/// The amount of time that sparty will be trapped
const double TrapTime = 5.0;

/**
 * Constructor
 * @param declaration the sparty declaration values
 * @param node a wxXmlNode object
 */
ItemSparty::ItemSparty(DeclarationSparty *declaration, wxXmlNode *node) : Item(declaration, node)
{
    wxString path = L"images/" + declaration->GetHeadImageName();
    mHeadImage = std::make_unique<wxImage>(path);

    path = L"images/" + declaration->GetMouthImageName();
    mMouthImage = std::make_unique<wxImage>(path);

    mFront = declaration->GetFront();
    mHeadPivotAngle = declaration->GetHeadPivotAngle();
    mHeadPivot = declaration->GetHeadPivot();
    mMouthPivotAngle = declaration->GetMouthPivotAngle();
    mMouthPivot = declaration->GetMouthPivot();
    mTargetX = declaration->GetTargetX();
    mTargetY = declaration->GetTargetY();
}

/**
 * Draw function for sparty
 * @param graphics graphics context being drawn onto
 * @param tileWidth the tile width of the level
 * @param tileHeight the tile height of the level
 */
void ItemSparty::Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight)
{
    if(mHeadBitmap.IsNull())
    {
        mHeadBitmap = graphics->CreateBitmapFromImage(*mHeadImage);
    }
    if(mMouthBitmap.IsNull())
    {
        mMouthBitmap = graphics->CreateBitmapFromImage(*mMouthImage);
    }

    double xPos = GetCol() * tileWidth;
    double yPos = (GetRow() + 1) * tileHeight - GetHeight();
    double wid = GetWidth();
    double hit = GetHeight();

    if(mHeadbutting)
    {
        graphics->PushState();
        wxPoint headPivot = wxPoint(xPos - wid / 8 + mHeadPivot.x, yPos - hit / 8 + mHeadPivot.y);
        double speed = mHeadbuttElapsed / HeadbuttTime;
        graphics->Translate(headPivot.x, headPivot.y);
        graphics->Rotate(mHeadPivotAngle * speed);
        graphics->Translate(-headPivot.x, -headPivot.y);
        graphics->DrawBitmap(mFront == 2 ? mHeadBitmap : mMouthBitmap, xPos, yPos, wid, hit);
        graphics->DrawBitmap(mFront == 2 ? mMouthBitmap : mHeadBitmap, xPos, yPos, wid, hit);
        graphics->PopState();
    }
    else if(mEating)
    {
        graphics->PushState();
        double x = xPos + mMouthPivot.x;

        double y = yPos  + mMouthPivot.y;
        graphics->Translate(x, y);
        graphics->Rotate(mMouthPivotAngle*mEatingElapsed*EatingTime);
        graphics->Translate(-x, -y);

        graphics->DrawBitmap(mMouthBitmap, xPos, yPos, wid, hit);
        graphics->PopState();

        graphics->PushState();
        graphics->DrawBitmap(mHeadBitmap, xPos, yPos, wid, hit);
        graphics->PopState();
    }
    else
    {
        graphics->DrawBitmap(mFront == 2 ? mHeadBitmap : mMouthBitmap, xPos, yPos, wid, hit);
        graphics->DrawBitmap(mFront == 2 ? mMouthBitmap : mHeadBitmap, xPos, yPos, wid, hit);
    }

    if (mIsFull)
    {
        DrawFullMessage(graphics);
    }


}

/**
 * Update function for Sparty to move on click
 * @param elapsed Time elapsed
 */
void ItemSparty::Update(double elapsed)
{

    if(GetGame()->GetNumTraps() > 0)
    {
        TrapFinderVisitor visitor;
        GetGame()->Accept(&visitor);
        auto trap = visitor.GetTrap();

        double xDist = abs(trap->GetGame()->GetSparty()->GetRow() - trap->GetRow());
        double yDist = abs(trap->GetGame()->GetSparty()->GetCol() - trap->GetCol());
        if(xDist < trap->GetWidth() / 2 / trap->GetGame()->GetTileWidth()
            && yDist < trap->GetHeight() / 2 / trap->GetGame()->GetTileHeight())
        {
            if(!trap->GetDisabledTrap())
            {
                mTrapped = true;
                if(mTrapped)
                {
                    mTrappedElapsed += elapsed;
                    if(mTrappedElapsed > TrapTime)
                    {
                        mTrapped = false;
                        mTrappedElapsed = 0;
                        trap->SetTrapStatus(true);
                    }
                    else
                    {
                        this->SetMoveTarget(trap->GetCol() * GetGame()->GetTileWidth(),
                                            trap->GetRow() * GetGame()->GetTileHeight());
                    }
                }
            }
        }
        else
        {
            if(trap->GetDisabledTrap())
            {
                trap->AddTimeToTrapDisabledElapsed(elapsed);
                if(trap->GetTrapDisabledElapsed() > trap->GetTrapDisabledTime())
                {
                    trap->SetTrapStatus(false);
                    trap->ResetTrapDisabledElapsed();
                }
            }
        }

    }
    //headbutting will be set to true whenever b is hit
    if(mHeadbutting)
    {
        //Add the elapsed time into the headbutt elapsed
        mHeadbuttElapsed += elapsed;

        //When headbutt elapsed is greater than the headbutt time we set, the headbutt should have finished by now
        // so we reset the headbutt elapsed and headbutting member variables

        if(mHeadbuttElapsed > HeadbuttTime)
        {

            if(GetGame()->GetNumContainers() > 0)
            {
                ContainerFinder visitor;
                GetGame()->Accept(&visitor);
                auto container = visitor.GetContainer();
                if(container)
                {

                    container->ContainerHit();
                }
            }
            mHeadbuttElapsed = 0;
            mHeadbutting = false;
        }
    }

    if(mEating)
    {
        mEatingElapsed += elapsed;
        if(mEatingElapsed > EatingTime)
        {
            mEatingElapsed = 0;
            mEating = false;
        }
    }

    wxPoint2DDouble d = mMoveTarget - wxPoint2DDouble(GetCol(), GetRow());

    double distance = d.GetVectorLength();

    if(distance != 0)
    {
        d.Normalize();
        d = d * MaxSpeed * elapsed / GetGame()->GetTileWidth();
    }
    // Reached the position
    if(distance <= d.GetVectorLength())
    {
        mIsMoving = false;
        SetLocation(mMoveTarget.m_x, mMoveTarget.m_y);
    }
    else
    {
        mIsMoving = true;
        SetLocation(GetCol() + d.m_x, GetRow() + d.m_y);
    }

    if (mMessageBoxOffset < GetGame()->GetTileHeight() * GetGame()->GetLevelHeight())
    {
        mMessageBoxOffset += MaxSpeed * elapsed;
    }
    else
    {
        mMessageBoxOffset = 0.0;
        mIsFull = false;
    }

    if(mIsFull)
    {
        mMessageDisplayTime += elapsed;
        if(mMessageDisplayTime >= MessageDisplayDuration)
        {
            mIsFull = false;
            mMessageDisplayTime = 0.0;
        }
    }

}

/**
 * Setter for the target sparty is moving to
 * @param virtualX the X point sparty is moving to in virtual coords
 * @param virtualY the Y point sparty is moving to in virtual coords
 */
void ItemSparty::SetMoveTarget(double virtualX, double virtualY)
{
    if(mTrapped)
    {
        mMoveTarget.m_x = (virtualX) / GetGame()->GetTileWidth();
        mMoveTarget.m_y = (virtualY) / GetGame()->GetTileHeight();
    }
    else
    {
        mMoveTarget.m_x = (virtualX - mTargetX) / GetGame()->GetTileWidth();
        mMoveTarget.m_y = (virtualY - mTargetY) / GetGame()->GetTileHeight();
    }
}

/**
 * Setter for the mHeadbutting bool
 * @param Headbutting set the mHeadbutting to this value
 */
void ItemSparty::SetHeadbutting(bool Headbutting)
{
    mHeadbutting = Headbutting;
}

/**
 * Eat the digit
 */
void ItemSparty::Eat()
{
    bool added;
    mEating = true;

    FindDigitToEat eatVisitor(GetCol() + 1, GetRow());
    GetGame()->Accept(&eatVisitor);
    auto digit = eatVisitor.GetDigit();

    if(digit != nullptr)
    {
        XrayFinder visitor;
        GetGame()->Accept(&visitor);
        auto xray = visitor.GetXray();

        added = xray->Add(digit);
        if(!added)
        {
            mIsFull = true;
            mMessageDisplayTime = 0.0;
            mMessageBoxOffset = 0.0;
        }
    }
}

/**
 * Regurgitate a number
 * @param number digit being regurgitated
 */
void ItemSparty::Regurgitate(int number)
{
    mEating = true;
    XrayFinder visitor;
    GetGame()->Accept(&visitor);
    auto xray = visitor.GetXray();

    double x = ((GetCol() * GetGame()->GetTileWidth()) + mTargetX) / GetGame()->GetTileWidth();
    double y = ((GetRow() * GetGame()->GetTileHeight()) + mTargetY) / GetGame()->GetTileHeight();

    if(x >= GetGame()->GetSolCol() && x < GetGame()->GetSolCol() + 9 && y >= GetGame()->GetSolRow()
        && y < GetGame()->GetSolRow() + 9)
    {
        DigitGivenFinder visitor1(x, y);
        GetGame()->Accept(&visitor1);
        if(visitor1.IsOccupied())
        {
            // print banner
            return;
        }
        xray->Regurgitate(number, x, y);
    }
    else
    {
        xray->Regurgitate(number, GetCol() + 1, GetRow());
    }
}


/**
 * Draw the "I'm full" message
 * @param graphics graphics context being drawn onto
 */
void ItemSparty::DrawFullMessage(std::shared_ptr<wxGraphicsContext> graphics)
{
    double x = (GetGame()->GetTileWidth() * GetGame()->GetLevelWidth()) / 2.0 - 100;
    double y = (GetGame()->GetTileHeight() * GetGame()->GetLevelHeight()) - mMessageBoxOffset;
    double width = 250;
    double height = 70;
    wxString text = L"I\'m Full\!";

    graphics->SetBrush(*wxWHITE_BRUSH);

    wxPen thickBlackPen(*wxBLACK, 5);

    graphics->SetPen(thickBlackPen);

    graphics->DrawRectangle(x, y, width, height);

    graphics->SetFont(wxFont(40, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD), *wxRED);
    graphics->DrawText(text, x + 24, y + 7.5);
}



