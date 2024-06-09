/**
 * @file Declaration.h
 * @author Aion
 *
 * Base Declaration Class for creating items
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_DECLARATION_H
#define PROJECT1_ACTIONSUDOKULIB_DECLARATION_H

#include "Item.h"

class Game;

/**
 * Class for loading the declaration of items
 */
class Declaration
{
private:
    /// Current game
    Game *mGame;

    /// Image width
    double mImageWidth;

    /// Image height
    double mImageHeight;

protected:
    Declaration(Game *game, wxXmlNode *node);

public:
    virtual ~Declaration();

    /// Default constructor (disabled)
    Declaration() = delete;

    /// Copy constructor (disabled)
    Declaration(const Declaration &) = delete;

    /// Assignment operator
    void operator=(const Declaration &) = delete;

    /**
     * Create specific item for its declaration (pure virtual)
     * @param node
     * @return shared pointer to the item created
     */
    virtual std::shared_ptr<Item> Create(wxXmlNode *node) = 0;

    /**
     * Getter for the image width
     * @return double: image width
     */
    double GetImageWidth() const { return mImageWidth; }

    /**
     * Getter for the image height
     * @return double: image height
     */
    double GetImageHeight() const { return mImageHeight; }

    /**
     * Setter for the image width
     * @param width double: image width
     */
    void SetImageWidth(double width) { mImageWidth = width; }

    /**
     * Setter for the image height
     * @param height double: image height
     */
    void SetImageHeight(double height) { mImageHeight = height; }

    /**
     * Getter for the game this declaration is a part of
     * @return pointer to the game
     */
    Game *GetGame() { return mGame; }
};

#endif //PROJECT1_ACTIONSUDOKULIB_DECLARATION_H
