/**
 * @file DeclarationContainer.h
 * @author Aion
 *
 * Class for declaring containers
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_DECLARATIONCONTAINER_H
#define PROJECT1_ACTIONSUDOKULIB_DECLARATIONCONTAINER_H

#include "Declaration.h"

/**
 * Declaration for containers in the game
 */
class DeclarationContainer : public Declaration
{
private:
    wxString mImageName;        ///< image name
    wxString mFrontImageName;   ///< front image name
public:
    DeclarationContainer(Game *game, wxXmlNode *node);

    /// Default constructor (disabled)
    DeclarationContainer() = delete;

    /// Copy constructor (disabled)
    DeclarationContainer(const DeclarationContainer &) = delete;

    /// Assignment operator
    void operator=(const DeclarationContainer &) = delete;

    std::shared_ptr<Item> Create(wxXmlNode *node) override;

    /**
     * Getter for the image name
     * @return wxString: image name
     */
    wxString GetImageName() const { return mImageName; }

    /**
     * Getter for the front image name
     * @return wxString: front image name
     */
    wxString GetFrontImageName() const { return mFrontImageName; }

};

#endif //PROJECT1_ACTIONSUDOKULIB_DECLARATIONCONTAINER_H
