/**
 * @file SolveCheck.h
 * @author Aion
 *
 * Check weather a position has correct value
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_SOLVECHECK_H
#define PROJECT1_ACTIONSUDOKULIB_SOLVECHECK_H

#include "ItemVisitor.h"

/**
 * Concrete visitor to check if all the cells are filled and if they are correct
 */
class SolveCheck : public ItemVisitor
{
private:
    bool mFound = false;    ///< bool if correct value is found in the cell
    double mLocationX;  ///< x location to check
    double mLocationY;  ///< y location to check
    int mNum;   ///< value to check
    bool mFull = false; ///< bool if the board is full

public:
    /**
     * Constructor
     * @param num
     * @param x
     * @param y
     */
    SolveCheck(int num, double x, double y) : mNum(num), mLocationX(x), mLocationY(y) {}

    /**
     * Getter to check if the digits are placed correctly
     * @return
     */
    bool GetFound() { return mFound; }

    /**
     * Getter to check if the cell is occupied
     * @return
     */
    bool GetFull() { return mFull; }

    void VisitDigit(ItemDigit *digit) override;

    void VisitGiven(ItemGiven *given) override;

};

#endif //PROJECT1_ACTIONSUDOKULIB_SOLVECHECK_H
