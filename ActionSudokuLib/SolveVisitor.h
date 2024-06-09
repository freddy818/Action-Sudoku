/**
 * @file SolveVisitor.h
 * @author Aion
 *
 * Visitor for the solve functionality
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_SOLVEVISITOR_H
#define PROJECT1_ACTIONSUDOKULIB_SOLVEVISITOR_H

#include "ItemVisitor.h"
#include "DeclarationGiven.h"
#include "DeclarationDigit.h"
#include "ItemGiven.h"
#include "ItemDigit.h"

/** Visitor for the solve functionality */
class SolveVisitor : public ItemVisitor
{
private:
    /// the Game Object
    Game *mGame = nullptr;

    /// vector of Givens
    std::vector<ItemGiven *> mGivens;
    /// vector of digits
    std::vector<ItemDigit *> mDigits;
    /// vector of containers
    std::vector<ItemContainer *> mContainers;

    /// the array of the solution
    int (*mSolutionArray)[9];

public:
    /**
     * Set Game object
     * @param game the game object
     */
    void SetGame(Game *game) { mGame = game; }

    virtual void VisitGiven(ItemGiven *given) override;
    virtual void VisitDigit(ItemDigit *digit) override;
    void VisitContainer(ItemContainer *container) override;

    void SetSolutionArray(int (*arr)[9]);
    void Solve();


};

#endif //PROJECT1_ACTIONSUDOKULIB_SOLVEVISITOR_H

