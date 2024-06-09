/**
 * @file ItemBackground.h
 * @author Aion
 *
 * Class for a background item
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_ITEMBACKGROUND_H
#define PROJECT1_ACTIONSUDOKULIB_ITEMBACKGROUND_H

#include "Item.h"

class DeclarationBackground;

/**
 * Background Item Class
 */
class ItemBackground : public Item
{
private:
    /// The underlying Item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap used to display the image
    wxGraphicsBitmap mItemBitmap;

public:
    ItemBackground(DeclarationBackground *declaration, wxXmlNode *node);

    /// Default constructor (disabled)
    ItemBackground() = delete;

    /// Copy constructor (disabled)
    ItemBackground(const ItemBackground &) = delete;

    /// Assignment operator
    void operator=(const ItemBackground &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight) override;

    /**
     * Accept a visitor
     * @param visitor the visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitBackground(this); }
};

#endif //PROJECT1_ACTIONSUDOKULIB_ITEMBACKGROUND_H
