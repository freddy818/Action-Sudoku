/**
 * @file FindDigitToEat.cpp
 * @author Aion
 */

#include "pch.h"
#include "FindDigitToEat.h"
#include "ItemDigit.h"

/**
 * Visit the digits
 * @param digit
 */
void FindDigitToEat::VisitDigit(ItemDigit *digit)
{
    double testX = (mCol - digit->GetCol()) * 48 + digit->GetWidth() / 2;
    double testY = (mRow - digit->GetRow()) * 48 + digit->GetHeight() / 2;

    if(testX < 0 || testY < 0 || testX >= digit->GetWidth() || testY >= digit->GetHeight() || digit->GetEaten())
        return;
    else
        mFoundDigit = digit;
}
