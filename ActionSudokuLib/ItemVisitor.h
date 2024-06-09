/**
 * @file ItemVisitor.h
 * @author Aion
 *
 * The visitor base class
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_ITEMVISITOR_H
#define PROJECT1_ACTIONSUDOKULIB_ITEMVISITOR_H

class ItemDigit;
class ItemGiven;
class ItemContainer;
class ItemBackground;
class ItemXray;
class ItemSparty;
class ItemTrap;

/**
 * Class for visiting items
 */
class ItemVisitor
{
protected:
    /**
     * Constructor
     * This is an abstract class
     */
    ItemVisitor() {}

public:

    /**
     * Destructor
     */
    virtual ~ItemVisitor() {}

    /**
     * Visit an ItemDigit object
     * @param digit
     */
    virtual void VisitDigit(ItemDigit* digit) {}

    /**
     * Visit an ItemGiven object
     * @param given
     */
    virtual void VisitGiven(ItemGiven *given) {}

    /**
     * Visit an ItemBackground object
     * @param background
     */
    virtual void VisitBackground(ItemBackground *background) {}

    /**
     * Visit an ItemContainer object
     * @param container
     */
    virtual void VisitContainer(ItemContainer *container) {}

    /**
     * Visit an ItemSparty object
     * @param sparty
     */
    virtual void VisitSparty(ItemSparty *sparty) {}

    /**
     * Visit an ItemXray object
     * @param xray
     */
    virtual void VisitXray(ItemXray *xray) {}

    /**
     * Visit an ItemTrap object
     * @param trap trap being visited
     */
    virtual void VisitTrap(ItemTrap *trap) {}
};

#endif //PROJECT1_ACTIONSUDOKULIB_ITEMVISITOR_H
