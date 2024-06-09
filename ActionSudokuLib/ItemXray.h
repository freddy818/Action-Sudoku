/**
 * @file ItemXray.h
 * @author adity
 *
 * Class for xray/stomach
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_ITEMXRAY_H
#define PROJECT1_ACTIONSUDOKULIB_ITEMXRAY_H

#include "Item.h"
#include <random>

class DeclarationXray;

/**
 * Class for xray/stomach
 */
class ItemXray : public Item
{
private:
    int mCapacity;  ///< capacity of the stomach

    /// The underlying Item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap used to display the image
    wxGraphicsBitmap mItemBitmap;

    /// vector to store stomach contents
    std::vector<ItemDigit*> mStomachItems;

    /// Random generator
    std::mt19937 mRandom;

public:
    ItemXray(DeclarationXray *declaration, wxXmlNode *node);

    /// Default constructor (disabled)
    ItemXray() = delete;

    /// Copy constructor (disabled)
    ItemXray(const ItemXray &) = delete;

    /// Assignment operator
    void operator=(const ItemXray &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight) override;

    /**
     * Accept a visitor
     * @param visitor the visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitXray(this); }

    bool Add(ItemDigit* digit);

    void Regurgitate(int number, double x, double y);
};

#endif //PROJECT1_ACTIONSUDOKULIB_ITEMXRAY_H
