/**
 * @file DeclarationBackground.h
 * @author Aion
 *
 * Declaration for background images
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_DECLARATIONBACKGROUND_H
#define PROJECT1_ACTIONSUDOKULIB_DECLARATIONBACKGROUND_H

#include "Declaration.h"
#include "ItemBackground.h"

/**
 * Class for declaring backgrounds
 */
class DeclarationBackground : public Declaration
{
private:
    /// Image name
    wxString mImageName;

protected:

public:
    DeclarationBackground(Game *game, wxXmlNode *node);

    /// Default constructor (disabled)
    DeclarationBackground() = delete;

    /// Copy constructor (disabled)
    DeclarationBackground(const DeclarationBackground &) = delete;

    /// Assignment operator
    void operator=(const DeclarationBackground &) = delete;

    std::shared_ptr<Item> Create(wxXmlNode *node) override;

    /**
     * Getter for the image name
     * @return wxString: image name
     */
    wxString GetImageName() const { return mImageName; }
};

#endif //PROJECT1_ACTIONSUDOKULIB_DECLARATIONBACKGROUND_H
