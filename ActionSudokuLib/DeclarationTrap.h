/**
 * @file DeclarationTrap.h
 * @author Aion
 *
 *
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_DECLARATIONTRAP_H
#define PROJECT1_ACTIONSUDOKULIB_DECLARATIONTRAP_H

#include "Declaration.h"

/**
 * Class for declaring trap
 */
class DeclarationTrap : public Declaration
{
private:

    wxString mImageName;    ///< Item image name

public:
    DeclarationTrap(Game *game, wxXmlNode *node);

    /// Default constructor (disabled)
    DeclarationTrap() = delete;

    /// Copy constructor (disabled)
    DeclarationTrap(const DeclarationTrap &) = delete;

    /// Assignment operator
    void operator=(const DeclarationTrap &) = delete;

    std::shared_ptr<Item> Create(wxXmlNode *node) override;

    /**
     * Getter for the name of stomach image
     * @return wxString: image name
     */
    wxString GetImageName() const { return mImageName; }
};

#endif //PROJECT1_ACTIONSUDOKULIB_DECLARATIONTRAP_H
