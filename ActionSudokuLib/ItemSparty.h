/**
 * @file ItemSparty.h
 * @author Aion
 *
 *  Item class for the sparty item
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_ITEMSPARTY_H
#define PROJECT1_ACTIONSUDOKULIB_ITEMSPARTY_H

#include "Item.h"

class DeclarationSparty;

/**
 * Item class for sparty item
 */
class ItemSparty : public Item
{
private:
    ///an integer that determines whether the mouth or face is drawn last
    int mFront = 0;

    ///Angle at which the head will pivot when headbutting
    double mHeadPivotAngle = 0;

    ///The point at which the head will pivot when headbutting
    wxPoint mHeadPivot = wxPoint(0,0);

    ///The angle at which the mouth will pivot when eating
    double mMouthPivotAngle = 0;

    ///The point at which the mouth will pivot when eating
    wxPoint mMouthPivot = wxPoint(0,0);

    ///A value that will determine how much sparty is offset from the cursor click in the x direction
    int mTargetX = 0;

    ///A value that will determine how much sparty is offset from the cursor click in the y direction
    int mTargetY = 0;

    ///Determine if sparty is currently moving
    bool mIsMoving = false;

    ///A target point that sparty is trying to move to
    wxPoint2DDouble mMoveTarget = {GetCol(), GetRow()};

    ///A bool to determine if sparty is currently headbutting
    bool mHeadbutting = false;

    ///Determines how much time has elapsed since sparty started headbutting
    double mHeadbuttElapsed = 0;

    ///A bool to determine if sparty is currently eating
    bool mEating = false;

    ///Determines how much time has elapsed since sparty started eating
    double mEatingElapsed = 0;

    /// The underlying Item image
    std::shared_ptr<wxImage> mHeadImage = nullptr;

    /// The bitmap used to display the image
    wxGraphicsBitmap mHeadBitmap;

    /// The underlying Item image
    std::shared_ptr<wxImage> mMouthImage  = nullptr;

    /// The bitmap used to display the image
    wxGraphicsBitmap mMouthBitmap;

    /// A bool representing is sparty is trapped
    bool mTrapped = false;

    ///A double representing how long sparty has been trapped
    double mTrappedElapsed = 0.0;

    ///A bool representing if sparty is full
    bool mIsFull = false;

    /// The amount of time the "I'm full" message has been displayed
    double mMessageDisplayTime = 0.0;

    /// The duration for which the "I'm full" message will be displayed (5 seconds)
    const double MessageDisplayDuration = 5.0;

    /// The offset for the "I'm full" message
    double mMessageBoxOffset = 0.0;


public:
    ItemSparty(DeclarationSparty *declaration, wxXmlNode *node);

    /// Default constructor (disabled)
    ItemSparty() = delete;

    /// Copy constructor (disabled)
    ItemSparty(const ItemSparty &) = delete;

    /// Assignment operator
    void operator=(const ItemSparty &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight) override;

    void Update(double elapsed) override;

    void SetMoveTarget(double virtualX, double virtualY);

    /**
     * Accept a visitor
     * @param visitor the visitor we accept
     */
    void Accept(ItemVisitor *visitor) override { visitor->VisitSparty(this); }

    /**
     * Getter to check if sparty is in motion
     * @return
     */
    bool IsMoving() { return mIsMoving; }

    /**
     * Getter for the target point sparty is trying to move to
     * @return the point that sparty is moving to
     */
    const wxPoint2DDouble &GetMoveTarget() const
    {
        return mMoveTarget;
    }


    void SetHeadbutting(bool Headbutting);

    void Eat();

    void Regurgitate(int number);

    void DrawFullMessage(std::shared_ptr<wxGraphicsContext> graphics);
};

#endif //PROJECT1_ACTIONSUDOKULIB_ITEMSPARTY_H
