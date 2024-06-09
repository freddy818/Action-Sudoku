/**
 * @file FindDigitToEat.h
 * @author Aion
 *
 * Visitor to hittest digits
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_FINDDIGITTOEAT_H
#define PROJECT1_ACTIONSUDOKULIB_FINDDIGITTOEAT_H

#include "ItemVisitor.h"

/**
 * Visitor to hittest the digit to eat
 */
class FindDigitToEat : public ItemVisitor
{
private:
    /// digit to eat
    ItemDigit *mFoundDigit = nullptr;

    /// x location to eat from
    double mCol;

    /// Y location to eat from
    double mRow;

public:
    /**
     * Constructor
     * @param col X location to eat from
     * @param row Y location to eat from
     */
    FindDigitToEat(double col, double row) : mCol(col), mRow(row) {}

    /**
     * Getter for the digit
     * @return
     */
    ItemDigit *GetDigit() { return mFoundDigit; }

    void VisitDigit(ItemDigit *digit) override;
};

#endif //PROJECT1_ACTIONSUDOKULIB_FINDDIGITTOEAT_H
