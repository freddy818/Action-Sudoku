/**
 * @file ItemTrap.h
 * @author adity
 *
 * Class for playable digits
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_ITEMTRAP_H
#define PROJECT1_ACTIONSUDOKULIB_ITEMTRAP_H

#include "Item.h"
#include "ItemVisitor.h"

class DeclarationTrap;

/**
 * Class for traps
 */
class ItemTrap : public Item
{
private:


    /// The underlying Item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap used to display the image
    wxGraphicsBitmap mItemBitmap;

    ///A bool representing if the trap is disabled
    bool mTrapDisabled = false;

    ///The amount of time that a trap will be disabled
    const double mTrapDisabledTime = 3.0;

    ///the amount of time that the trap has been disabled
    double mTrapDisabledElapsed = 0.0;

public:
    ItemTrap(DeclarationTrap *declaration, wxXmlNode *node);

    /// Default constructor (disabled)
    ItemTrap() = delete;

    /// Copy constructor (disabled)
    ItemTrap(const ItemTrap &) = delete;

    /// Assignment operator
    void operator=(const ItemTrap &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight) override;

    /**
     * Accept a visitor
     * @param visitor the visitor we accept
     */
    void Accept(ItemVisitor *visitor) override { visitor->VisitTrap(this); }

    /**
     * Getter for the disabled status for a trap
     * @return bool if trap is disabled or not
     */
    bool GetDisabledTrap()
    {
        return mTrapDisabled;
    }

    /**
     * Setter for a trap's disabled status
     * @param status the status of if the trap should be disabled or enabled
     */
    void SetTrapStatus(bool status)
    {
        mTrapDisabled = status;
    }

    /**
     * Getter for how long a trap is disabled
     * @return the amount of time a trap will be disabled for
     */
    double GetTrapDisabledTime()
    {
        return mTrapDisabledTime;
    }

    /**
     * Add to the amount of time the trap has been disabled
     * @param time the amount of time to add to the variable
     */
     void AddTimeToTrapDisabledElapsed(double time)
    {
         mTrapDisabledElapsed += time;
    }

    /**
     * Get the amount of time the trap has been disabled
     * @return the amount of time the trap has been disabled
     */
     double GetTrapDisabledElapsed()
    {
         return mTrapDisabledElapsed;
    }

    /**
     * Reset trap disabled elapsed to 0
     */
    void ResetTrapDisabledElapsed()
    {
        mTrapDisabledElapsed = 0;
    }
};

#endif //PROJECT1_ACTIONSUDOKULIB_ITEMTRAP_H
