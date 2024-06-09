/**
 * @file Item.h
 * @author Aion
 *
 * Item class to handle all the drawable items
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_ITEM_H
#define PROJECT1_ACTIONSUDOKULIB_ITEM_H

#include <wx/graphics.h>
#include <wx/xml/xml.h>

#include "ItemVisitor.h"

class Declaration;
class Game;

/** Class for an Item in the game */
class Item
{
private:
    double mCol;  ///< column location for the item
    double mRow;  ///< row location for the item
    Declaration *mDeclaration;  ///< Declaration used for this item
    double mWidth; ///< width of the item
    double mHeight; ///< height of the item
    Game *mGame; ///< game that the item is a part of

protected:
    Item(Declaration *declaration, wxXmlNode *node);

public:
    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Assignment operator
    void operator=(const Item &) = delete;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    virtual void Accept(ItemVisitor* visitor) = 0;

    /**
     * Setter for the position of the item
     * @param x column position
     * @param y row position
     */
    void SetLocation(double x, double y)
    {
        mCol = x;
        mRow = y;
    }

    /**
     * getter for the row of an item
     * @return the row value
     */
    double GetRow() { return mRow; }

    /**
     * getter for the col of an item
     * @return the col value
     */
    double GetCol() { return mCol; }

    /**
     * Setter for the width of an item
     * @param width width of item
     */
    void SetWidth(double width) { mWidth = width; }

    /**
     * Setter for height of item
     * @param height item height
     */
    void SetHeight(double height) { mHeight = height; }

    /**
     * Getter for the width of an item
     * @return item width
     */
    double GetWidth() { return mWidth; }

    /**
     * Getter for the height of an item
     * @return item height
     */
    double GetHeight() { return mHeight; }

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int tileWidth, int tileHeight) = 0;

    /**
     * handles updates for animation
     * @param elapsed the time since the last update
     */
    virtual void Update(double elapsed) {}

    /**
     * Getter for the game the item is a part of
     * @return the game the item is a part of
     */
    Game *GetGame() { return mGame; }

    /**
     * hit test for an item
     * @param x x value of the hit
     * @param y
     * @return false
     */
    virtual bool HitTest(double x, double y) { return false; }

    /**
     * Set an item
     * @param item item being set
     */
    virtual void SetItem(std::shared_ptr<Item> item) {}
};

#endif //PROJECT1_ACTIONSUDOKULIB_ITEM_H
