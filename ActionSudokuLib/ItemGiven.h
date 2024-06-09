/**
 * @file ItemGiven.h
 * @author Aion
 *
 * Class for given/static digits
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_ITEMGIVEN_H
#define PROJECT1_ACTIONSUDOKULIB_ITEMGIVEN_H

#include "Item.h"

class DeclarationGiven;

/**
 * Class for given/static digits
 */
class ItemGiven : public Item
{
private:

    ///Value of the given digit
    int mValue;


    /// The underlying Item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap used to display the image
    wxGraphicsBitmap mItemBitmap;

public:
    ItemGiven(DeclarationGiven *declaration, wxXmlNode *node);

    /// Default constructor (disabled)
    ItemGiven() = delete;

    /// Copy constructor (disabled)
    ItemGiven(const ItemGiven &) = delete;

    /// Assignment operator
    void operator=(const ItemGiven &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight) override;

    /**
     * Accept a visitor
     * @param visitor the visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitGiven(this); }

    /**
     * Set the value of the digit
     * @param value value of the digit
     */
    void SetValue(int value)  { mValue = value; }

    /**
     * Getter for the given digit value
     * @return digit value
     */
    int GetValue() const  { return mValue; }
};

#endif //PROJECT1_ACTIONSUDOKULIB_ITEMGIVEN_H
