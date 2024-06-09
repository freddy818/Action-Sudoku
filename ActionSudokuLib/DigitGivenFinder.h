/**
 * @file DigitGivenFinder.h
 * @author Aion
 *
 * Check if a digit or given is already present in the block to regurgitate in
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_DIGITGIVENFINDER_H
#define PROJECT1_ACTIONSUDOKULIB_DIGITGIVENFINDER_H

#include "ItemVisitor.h"

/** Check if a digit or given is already present in the block to regurgitate in */
class DigitGivenFinder : public ItemVisitor
{
private:
    /// x location to check if the cell is occupied
    double mLocationX;
    /// y location to check if the cell is occupied
    double mLocationY;

    /// bool to check if the cell is occupied
    bool mOccupied = false;

public:
    /**
     * Constructor
     * @param x position of given on x coordinate
     * @param y position of given on y coordinate
     */
    DigitGivenFinder(double x, double y) : mLocationX(x), mLocationY(y) {}

    /**
     * Getter for occupied bool
     * @return mOccupied
     */
    bool IsOccupied() { return mOccupied; }

    void VisitDigit(ItemDigit *digit) override;

    void VisitGiven(ItemGiven *given) override;
};

#endif //PROJECT1_ACTIONSUDOKULIB_DIGITGIVENFINDER_H
