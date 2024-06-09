/**
 * @file FindDigitToReg.cpp
 * @author Aion
 */

#include "pch.h"
#include "FindDigitToReg.h"
#include "ItemDigit.h"

/**
 * Visit a digit that will be regurgitated
 * @param digit digit being visited
 */
void FindDigitToReg::VisitDigit(ItemDigit *digit)
{
    if(digit->GetValue() == mVal){
        mFoundDigit = digit;
    }
}
