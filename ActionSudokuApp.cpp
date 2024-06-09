/**
 * @file ActionSudokuApp.cpp
 * @author Frederick Fan
 */

#include "pch.h"
#include "ActionSudokuApp.h"
#include <MainFrame.h>

/**
 * Initialize the application
 * @return bool
 */
bool ActionSudokuApp::OnInit()
{
    if (!wxApp::OnInit())
    {
        return false;
    }

    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new MainFrame();
    frame -> Initialize();
    frame ->Show(true);

    return true;
}