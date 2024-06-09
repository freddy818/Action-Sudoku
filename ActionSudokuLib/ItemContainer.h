/**
 * @file ItemContainer.h
 * @author Aion
 *
 * Item class for handling containers
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_ITEMCONTAINER_H
#define PROJECT1_ACTIONSUDOKULIB_ITEMCONTAINER_H

#include "Item.h"
#include "Game.h"

class DeclarationContainer;

/**
 * Class for the container items
 */
class ItemContainer : public Item
{
private:
    /// The underlying Item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap used to display the image
    wxGraphicsBitmap mItemBitmap;

    /// The front image
    std::shared_ptr<wxImage> mFrontImage;

    /// Bitmap used to display front image
    wxGraphicsBitmap mFrontBitmap;

    ///vector of the digits inside containers
    std::vector<std::shared_ptr<Item>> mDigits;

    ///New random location for the digits inside the container
    double mDigitX = 0;

    ///New random location for the digits inside the container
    double mDigitY = 0;


public:
    ItemContainer(DeclarationContainer *declaration, wxXmlNode *node);

    /// Default constructor (disabled)
    ItemContainer() = delete;

    /// Copy constructor (disabled)
    ItemContainer(const ItemContainer &) = delete;

    /// Assignment operator
    void operator=(const ItemContainer &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight) override;

    /**
     * Accept a visitor
     * @param visitor the visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitContainer(this); }

    /**
     * push a digit into the mDigits vector
     * @param item the digit being pushed
     */
    void SetItem(std::shared_ptr<Item> item) override {mDigits.push_back(item);}

    void ContainerHit();

};

#endif //PROJECT1_ACTIONSUDOKULIB_ITEMCONTAINER_H
