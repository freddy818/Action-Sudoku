/**
 * @file DeclarationXray.h
 * @author Aion
 *
 *
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_DECLARATIONXRAY_H
#define PROJECT1_ACTIONSUDOKULIB_DECLARATIONXRAY_H

#include "Declaration.h"

/**
 * Class for declaring xray
 */
class DeclarationXray : public Declaration
{
private:
    int mCapacity;   ///< capacity of the stomach

    wxString mImageName;    ///< Item image name

public:
    DeclarationXray(Game *game, wxXmlNode *node);

    /// Default constructor (disabled)
    DeclarationXray() = delete;

    /// Copy constructor (disabled)
    DeclarationXray(const DeclarationXray &) = delete;

    /// Assignment operator
    void operator=(const DeclarationXray &) = delete;

    std::shared_ptr<Item> Create(wxXmlNode *node) override;

    /**
     * Getter for the capacity of the stomach
     * @return int: capacity of the stomach
     */
    int GetCapacity() const { return mCapacity; }

    /**
     * Getter for the name of stomach image
     * @return wxString: image name
     */
    wxString GetImageName() const { return mImageName; }
};

#endif //PROJECT1_ACTIONSUDOKULIB_DECLARATIONXRAY_H
