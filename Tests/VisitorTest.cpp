/**
 * @file VisitorTest.cpp
 * @author Frederick Fan
 */
/**
 * @file GameTest.cpp
 * @author Aion
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Game.h>
#include <LevelLoader.h>
#include <ItemDigit.h>
#include <ItemGiven.h>

class TestVisitor : public ItemVisitor
{
public:
    void VisitDigit(ItemDigit *digit) override { mNumDigits++; }
    void VisitGiven(ItemGiven *given) override { mNumGivens++; }

    int mNumDigits = 0;
    int mNumGivens = 0;
};

TEST(TestVisitor, Visitor)
{
    Game game;

    TestVisitor visitor;
    game.Accept(&visitor);
    ASSERT_EQ(0, visitor.mNumDigits);
    ASSERT_EQ(0, visitor.mNumGivens);

    LevelLoader loader;
    loader.LoadLevel(&game, L"levels/level1.xml");
    game.Accept(&visitor);
    ASSERT_EQ(81, visitor.mNumDigits + visitor.mNumGivens);

    Game game2;
    TestVisitor visitor2;
    LevelLoader loader2;
    loader2.LoadLevel(&game2, L"levels/level2.xml");
    game2.Accept(&visitor2);
    ASSERT_EQ(65, visitor2.mNumDigits + visitor2.mNumGivens);

    Game game3;
    TestVisitor visitor3;
    LevelLoader loader3;
    loader3.LoadLevel(&game3, L"levels/level3.xml");
    game3.Accept(&visitor3);
    ASSERT_EQ(81, visitor3.mNumDigits + visitor3.mNumGivens);


}