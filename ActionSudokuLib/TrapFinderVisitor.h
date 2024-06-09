/**
 * @file TrapFinderVisitor.h
 * @author Frederick Fan
 *
 *
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_TRAPFINDERVISITOR_H
#define PROJECT1_ACTIONSUDOKULIB_TRAPFINDERVISITOR_H

#include "ItemVisitor.h"
#include "Game.h"
#include "ItemSparty.h"
#include "ItemTrap.h"
#include "Item.h"

/** Visit and find the trap on the board */

class TrapFinderVisitor : public ItemVisitor
{
private:

    ///Trap item that the visitor has found
    ItemTrap *mTrap = nullptr;

public:

    /**
     * Visit a trap
     * @param trap the trap we are visiting
    **/
    void VisitTrap(ItemTrap *trap) override;


    /**
     * Get the trap being visited
     * @return the trap that was visited
     */
    ItemTrap *GetTrap()
    {
        return mTrap;
    }
};

#endif //PROJECT1_ACTIONSUDOKULIB_TRAPFINDERVISITOR_H
