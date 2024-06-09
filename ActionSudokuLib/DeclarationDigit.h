/**
 * @file DeclarationDigit.h
 * @author adity
 *
 *
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_DECLARATIONDIGIT_H
#define PROJECT1_ACTIONSUDOKULIB_DECLARATIONDIGIT_H

#include "Declaration.h"

/**
 * Class for declaring digits
 */
class DeclarationDigit : public Declaration
{
private:
    int mValue; ///< value for this digit

    wxString mImageName;    ///< image name

public:
    DeclarationDigit(Game *game, wxXmlNode *node);

    /// Default constructor (disabled)
    DeclarationDigit() = delete;

    /// Copy constructor (disabled)
    DeclarationDigit(const DeclarationDigit &) = delete;

    /// Assignment operator
    void operator=(const DeclarationDigit &) = delete;

    std::shared_ptr<Item> Create(wxXmlNode *node) override;

    /**
     * Getter for the value of this digit
     * @return int: value
     */
    int GetValue() const { return mValue; }

    /**
     * Getter for the image name for this digit
     * @return wxString: image name
     */
    wxString GetImageName() const { return mImageName; }
};

#endif //PROJECT1_ACTIONSUDOKULIB_DECLARATIONDIGIT_H
