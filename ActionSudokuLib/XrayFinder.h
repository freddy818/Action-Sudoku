/**
 * @file XrayFinder.h
 * @author Aion
 *
 * Visitor to locate the Xray
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_XRAYFINDER_H
#define PROJECT1_ACTIONSUDOKULIB_XRAYFINDER_H

#include "ItemVisitor.h"

/**
 * Visitor to find the xray
 */
class XrayFinder : public ItemVisitor
{
private:
    /// found Xray
    ItemXray *mXray;

public:
    /**
     * Visit the ItemXray object
     * @param xray xray we are visiting
     */
    void VisitXray(ItemXray *xray) override { mXray = xray; }

    /**
     * Getter for the xray
     * @return the first found xray (should only be one per game)
     */
    ItemXray *GetXray() { return mXray; }
};

#endif //PROJECT1_ACTIONSUDOKULIB_XRAYFINDER_H
