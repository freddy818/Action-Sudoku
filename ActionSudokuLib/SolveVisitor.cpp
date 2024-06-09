/**
 * @file SolveVisitor.cpp
 * @author Aion
 */

#include "pch.h"
#include "SolveVisitor.h"
#include "Game.h"
#include "ItemContainer.h"
#include <utility>
#include <set>


///The number of rows
int const NumRows = 9;

///the number of columns
int const NumCols = 9;

/**
 * Set Solution array
 * @param arr what we are setting mSolutionArray to
 */
void SolveVisitor::SetSolutionArray(int (*arr)[9])
{
    mSolutionArray = arr;
}

/**
 * Solve the level
 */
void SolveVisitor::Solve()
{
    std::vector<ItemDigit *> alreadySeenDigits;
    std::set<std::pair<int, int>> givenLocations;
    std::set<std::shared_ptr<Item>> alreadySeenContainerDigits;

    for (ItemGiven* given : mGivens)
    {
        int givenCol = given->GetCol();
        int givenRow = given->GetRow();
        givenLocations.insert({givenCol, givenRow});
    }

    int initialCol = mGame->GetSolCol();
    int initialRow = mGame->GetSolRow();

    for (int row = 0; row < NumRows; ++row)
    {
        for (int col = 0; col < NumCols; ++col)
        {
            int solutionValue = mSolutionArray[row][col];

            int newCol = initialCol + col;
            int newRow = initialRow + row;

            if (givenLocations.find({newCol, newRow}) != givenLocations.end())
            {
                continue;
            }

            for (ItemDigit* digit : mDigits) {
                if (digit->GetValue() == solutionValue && !digit->GetEaten())
                {
                    auto it = std::find(alreadySeenDigits.begin(), alreadySeenDigits.end(), digit);
                    if (it != alreadySeenDigits.end())
                    {
                        continue;
                    }
                    else
                    {
                        digit->SetLocation(newCol, newRow);
                        alreadySeenDigits.push_back(digit);
                        break;
                    }
                }
            }
        }
    }
}

/**
 * Visitor for givens
 * @param given
 */
void SolveVisitor::VisitGiven(ItemGiven *given)
{
    mGivens.push_back(given);
}

/**
 * Visitor for givens
 * @param digit
 */
void SolveVisitor::VisitDigit(ItemDigit *digit)
{
    mDigits.push_back(digit);
}

/**
 * Visitor for containers
 * @param container
 */
void SolveVisitor::VisitContainer(ItemContainer *container)
{
    mContainers.push_back(container);
}
