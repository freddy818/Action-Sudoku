/**
 * @file ItemTest.cpp
 * @author Frederick Fan
 */


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

class ItemTest : public ::testing::Test
{
protected:

};

TEST_F(ItemTest, GetWidth)
{
    Game game;
    LevelLoader loader;
    loader.LoadLevel(&game, L"levels/level1.xml");

    ASSERT_EQ( 96,  game.GetSparty()->GetWidth());
}

TEST_F(ItemTest, GetCol)
{
    Game game;
    LevelLoader loader;
    loader.LoadLevel(&game, L"levels/level1.xml");

    ASSERT_EQ( 1.4167,  game.GetSparty()->GetCol());
}

TEST_F(ItemTest, GetRow)
{
    Game game;
    LevelLoader loader;
    loader.LoadLevel(&game, L"levels/level1.xml");

    ASSERT_EQ( 10.8333,  game.GetSparty()->GetRow());
}
TEST_F(ItemTest, GetHeight)
{
    Game game;
    LevelLoader loader;
    loader.LoadLevel(&game, L"levels/level1.xml");
    ASSERT_EQ( 96,  game.GetSparty()->GetHeight());
}

TEST_F(ItemTest, SetWidth)
{
    Game game;
    LevelLoader loader;
    loader.LoadLevel(&game, L"levels/level1.xml");

    game.GetSparty()->SetWidth(20);

    ASSERT_EQ(20, game.GetSparty()->GetWidth());
}

TEST_F(ItemTest, SetHeight)
{
    Game game;
    LevelLoader loader;
    loader.LoadLevel(&game, L"levels/level1.xml");

    game.GetSparty()->SetHeight(10);

    ASSERT_EQ(10, game.GetSparty()->GetHeight());
}