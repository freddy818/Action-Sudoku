/**
 * @file LoadTest.cpp
 * @author Aion
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <iostream>

#include <Game.h>
#include <LevelLoader.h>
#include <Item.h>

using namespace std;

class SpartyTest : public ::testing::Test
{
protected:

};


TEST_F(SpartyTest, SetLocation)
{
    Game game;
    LevelLoader loader;
    loader.LoadLevel(&game, L"levels/level1.xml");

    game.GetSparty()->SetLocation(11, 2);
    ASSERT_EQ(2, game.GetSparty()->GetRow());
    ASSERT_EQ(11, game.GetSparty()->GetCol());

}

TEST_F(SpartyTest, Movemment)
{
    Game game;
    LevelLoader loader;
    loader.LoadLevel(&game, L"levels/level1.xml");

    //When spartys target is set and it is moved, its  set at the location minus an amt dependent on
    // sparty's width and the scale, i just plugged the relevant values into the equation to determine
    //where sparty is moving rather than rewriting the equation for the assertion
    game.GetSparty()->SetMoveTarget(11, 2);
    ASSERT_EQ(1.4167, game.GetSparty()->GetCol() );
    ASSERT_EQ(10.8333, game.GetSparty()->GetRow() );

}

