/**
 * @file SolveCheck.cpp
 * @author Aion
 */

#include "pch.h"
#include "SolveCheck.h"
#include "ItemDigit.h"
#include "ItemGiven.h"

/**
 * Visitor for digits
 * @param digit
 */
void SolveCheck::VisitDigit(ItemDigit *digit)
{
    if(digit->GetCol() == mLocationX && digit->GetRow() == mLocationY)
    {
        mFull = true;
        if(digit->GetValue() == mNum)
        {
            mFound = true;
        }
    }
}

/**
 * Visitor for givens
 * @param given
 */
void SolveCheck::VisitGiven(ItemGiven *given)
{
    if(given->GetCol() == mLocationX && given->GetRow() == mLocationY)
    {
        mFull = true;
        if(given->GetValue() == mNum)
        {
            mFound = true;
        }
    }
}
