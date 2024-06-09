/**
 * @file ItemDigit.h
 * @author adity
 *
 * Class for playable digits
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_ITEMDIGIT_H
#define PROJECT1_ACTIONSUDOKULIB_ITEMDIGIT_H

#include "Item.h"
#include "ItemVisitor.h"

class DeclarationDigit;

/**
 * Class for playable digits
 */
class ItemDigit : public Item
{
private:
    ///The value of the digit
    int mValue;

    /// The underlying Item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap used to display the image
    wxGraphicsBitmap mItemBitmap;

    /// if the digit is eaten;
    bool mEaten = false;

public:
    ItemDigit(DeclarationDigit *declaration, wxXmlNode *node);

    /// Default constructor (disabled)
    ItemDigit() = delete;

    /// Copy constructor (disabled)
    ItemDigit(const ItemDigit &) = delete;

    /// Assignment operator
    void operator=(const ItemDigit &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight) override;

    /**
     * Accept a visitor
     * @param visitor the visitor we accept
     */
    void Accept(ItemVisitor *visitor) override { visitor->VisitDigit(this); }

    /**
     * Setter for the value of a digit
     * @param value value being set to
     */
    void SetValue(int value) { mValue = value; }

    /**
     * Getter for value of a digit
     * @return digit value
     */
    int GetValue() const { return mValue; }

    bool HitTest(double x, double y) override;

    /**
     * Setter for eaten bool
     * @param eaten
     */
    void SetEaten(bool eaten) { mEaten = eaten; }

    /**
     * Getter for the eaten bool
     * @return eaten
     */
    bool GetEaten() { return mEaten; }
};

#endif //PROJECT1_ACTIONSUDOKULIB_ITEMDIGIT_H
