/**
 * @file DeclarationSparty.h
 * @author Aion
 *
 * class for creating declarations for sparty
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_DECLARATIONSPARTY_H
#define PROJECT1_ACTIONSUDOKULIB_DECLARATIONSPARTY_H

#include "Declaration.h"
#include "ItemSparty.h"

/**
 * Class for declaring sparty
 */
class DeclarationSparty : public Declaration
{
private:
    int front;              ///< what image should be drawn first
    double headPivotAngle;  ///< pivot angle for the head
    wxPoint headPivot;         ///< pivot value x for head
    double mouthPivotAngle; ///< pivot angle for the mouth
    wxPoint mouthPivot;        ///< pivot value x for head
    int targetX;            ///< offset x value for drawing sparty
    int targetY;            ///< offset y value for drawing sparty
    wxString headImage;     ///< file name of sparty head image
    wxString mouthImage;    ///< file name of sparty mouth image

public:
    DeclarationSparty(Game *game, wxXmlNode *node);

    ///Default constructor (disabled)
    DeclarationSparty() = delete;

    ///Copy constructor (disabled)
    DeclarationSparty(const DeclarationSparty &) = delete;

    /// Assignment operator
    void operator=(const DeclarationSparty &) = delete;

    std::shared_ptr<Item> Create(wxXmlNode *node) override;

    /**
     * Getter for sparty head image name
     * @return wxString: image name
     */
    wxString GetHeadImageName() const { return headImage; }

    /**
     * Getter for sparty mouth image name
     * @return wxString: image name
     */
    wxString GetMouthImageName() const { return mouthImage; }

    /**
     * Getter for front value
     * @return int: front
     */
    int GetFront() const { return front; }

    /**
     * Getter for sparty head pivot angle
     * @return double: head pivot angle
     */
    double GetHeadPivotAngle() const { return headPivotAngle; }

    /**
     * Getter for sparty head pivot x value
     * @return int: head pivot x
     */
    wxPoint GetHeadPivot() const { return headPivot; }

    /**
     * Getter for sparty mouth pivot angle
     * @return double: mouth pivot angle
     */
    double GetMouthPivotAngle() const { return mouthPivotAngle; }

    /**
     * Getter for sparty mouth pivot x value
     * @return int: mouth pivot x
     */
    wxPoint GetMouthPivot() const { return mouthPivot; }

    /**
     * Getter for the sparty draw offset x
     * @return int: target x
     */
    int GetTargetX() const { return targetX; }

    /**
     * Getter for the sparty draw offset y
     * @return int: target y
     */
    int GetTargetY() const { return targetY; }

};

#endif //PROJECT1_ACTIONSUDOKULIB_DECLARATIONSPARTY_H
