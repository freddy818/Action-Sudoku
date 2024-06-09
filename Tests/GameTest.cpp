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

//using a visitor to help with counting up the items for the clear test
class TestVisitor : public ItemVisitor
{
public:
    void VisitDigit(ItemDigit *digit) override { mNumDigits++; }
    void VisitGiven(ItemGiven *given) override { mNumGivens++; }

    int mNumDigits = 0;
    int mNumGivens = 0;
};


TEST(GameTest, Clear)
{
    Game game;

    LevelLoader loader;
    TestVisitor visitor;
    loader.LoadLevel(&game, L"levels/level1.xml");
    game.Clear();
    game.Accept(&visitor);
    ASSERT_EQ(0, visitor.mNumDigits + visitor.mNumGivens);

    LevelLoader loader2;
    TestVisitor visitor2;
    loader.LoadLevel(&game, L"levels/level2.xml");
    game.Clear();
    game.Accept(&visitor2);
    ASSERT_EQ(0, visitor.mNumDigits + visitor.mNumGivens);

    LevelLoader loader3;
    TestVisitor visitor3;
    loader.LoadLevel(&game, L"levels/level3.xml");
    game.Clear();
    game.Accept(&visitor3);
    ASSERT_EQ(0, visitor.mNumDigits + visitor.mNumGivens);

}
