/**
 * @file ContainerFinder.h
 * @author Frederick Fan
 *
 * Visitor for finding containers
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_CONTAINERFINDER_H
#define PROJECT1_ACTIONSUDOKULIB_CONTAINERFINDER_H

#include "ItemVisitor.h"
#include "Game.h"
#include "ItemSparty.h"
#include "ItemContainer.h"
#include "Item.h"

/** Visitor for finding containers */
class ContainerFinder : public ItemVisitor
{
private:
    ///A container item
    ItemContainer *mContainer = nullptr;

public:

    /**
      * Visit the ItemContainer object
      * @param container container we are visiting
      */
    void VisitContainer(ItemContainer *container) override;

    /**
     * Getter for the container being visited
     * @return container being visited
     */
    ItemContainer *GetContainer() const
    {
        return mContainer;
    }
};

#endif //PROJECT1_ACTIONSUDOKULIB_CONTAINERFINDER_H
