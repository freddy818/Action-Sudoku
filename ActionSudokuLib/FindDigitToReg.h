/**
 * @file FindDigitToReg.h
 * @author Aion
 *
 *
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_FINDDIGITTOREG_H
#define PROJECT1_ACTIONSUDOKULIB_FINDDIGITTOREG_H

#include "ItemVisitor.h"

/** Visitor to find the digit that is being regurgitated */
class FindDigitToReg : public ItemVisitor
{
private:

    /// digit to reg
    ItemDigit *mFoundDigit = nullptr;

    /// value to look for
    int mVal;

public:
    /**
     * constructor
     * @param value value of the digit
     */
    FindDigitToReg(int value) : mVal(value) {}

    /**
     * Getter for the digit
     * @return the found digit
     */
    ItemDigit *GetDigit() { return mFoundDigit; }

    void VisitDigit(ItemDigit *digit) override;
};

#endif //PROJECT1_ACTIONSUDOKULIB_FINDDIGITTOREG_H
