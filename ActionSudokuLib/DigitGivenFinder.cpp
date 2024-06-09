/**
 * @file DigitGivenFinder.cpp
 * @author Aion
 */

#include "pch.h"
#include "DigitGivenFinder.h"
#include "ItemDigit.h"
#include "ItemGiven.h"

/**
 * Check if digit is in position
 * @param digit the digit we are checking
 */
void DigitGivenFinder::VisitDigit(ItemDigit *digit)
{
    if(digit->GetCol() == mLocationX && digit->GetRow() == mLocationY)
    {
        mOccupied = true;
    }
}

/**
 *
 * Check if given is in position
 * @param given the given we are checking
 */
void DigitGivenFinder::VisitGiven(ItemGiven *given)
{
    if(given->GetCol() == mLocationX && given->GetRow() == mLocationY)
    {
        mOccupied = true;
    }
}