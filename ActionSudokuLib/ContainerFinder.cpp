/**
 * @file ContainerFinder.cpp
 * @author Frederick Fan
 */

#include "pch.h"
#include "ContainerFinder.h"

/**
  * Visit the ItemContainer object
  * @param container container we are visiting
  */
void ContainerFinder::VisitContainer(ItemContainer *container)
{
    ItemVisitor::VisitContainer(container);
    double xDist = abs(container->GetGame()->GetSparty()->GetRow() - container->GetRow());
    double yDist = abs(container->GetGame()->GetSparty()->GetCol() - container->GetCol());
    if(xDist < container->GetWidth() / 2 / container->GetGame()->GetTileWidth()
        && yDist < container->GetHeight() / 2 / container->GetGame()->GetTileHeight())
        // I think using literal constant should be fine here since I am just getting half the height/width
    {
        mContainer = container;
    }
}
