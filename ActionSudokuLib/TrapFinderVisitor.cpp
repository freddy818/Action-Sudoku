/**
 * @file TrapFinderVisitor.cpp
 * @author Frederick Fan
 */

#include "pch.h"
#include "TrapFinderVisitor.h"
void TrapFinderVisitor::VisitTrap(ItemTrap *trap)
{
    ItemVisitor::VisitTrap(trap);

    mTrap = trap;
}
