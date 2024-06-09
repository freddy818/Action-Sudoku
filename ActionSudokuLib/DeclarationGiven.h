/**
 * @file DeclarationGiven.h
 * @author Aion
 *
 * Class for the Declaration of givens
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_DECLARATIONGIVEN_H
#define PROJECT1_ACTIONSUDOKULIB_DECLARATIONGIVEN_H

#include "Declaration.h"

/**
 * Class for declaring givens
 */
class DeclarationGiven : public Declaration
{
private:
    int mValue; ///< value for this given

    wxString mImageName;    ///< image name for this given

public:
    DeclarationGiven(Game *game, wxXmlNode *node);

    /// Default constructor (disabled)
    DeclarationGiven() = delete;

    /// Copy constructor (disabled)
    DeclarationGiven(const DeclarationGiven &) = delete;

    /// Assignment operator
    void operator=(const DeclarationGiven &) = delete;

    std::shared_ptr<Item> Create(wxXmlNode *node) override;

    /**
     * Getter for the value of this given
     * @return int: value
     */
    int GetValue() const { return mValue; }

    /**
     * Getter for the image name of this given
     * @return wxString: image name
     */
    wxString GetImageName() const { return mImageName; }
};

#endif //PROJECT1_ACTIONSUDOKULIB_DECLARATIONGIVEN_H
