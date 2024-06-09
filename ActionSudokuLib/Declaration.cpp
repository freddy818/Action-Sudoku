/**
 * @file Declaration.cpp
 * @author Aion
 */

#include "pch.h"
#include "Declaration.h"

/**
 * Constructor
 * @param game Game this declaration is a part of
 * @param node Xml node for this declaration
 */
Declaration::Declaration(Game *game, wxXmlNode *node) : mGame(game)
{

}

/**
 * Destructor
 */
Declaration::~Declaration()
{

}
