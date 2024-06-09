/**
 * @file Banner.cpp
 * @author Aion
 */

#include "pch.h"
#include "Banner.h"

/**
 * Create the graphics for the start banner
 * @param graphics the graphics context being drawn to
 * @param level the level we are loading
 */
void Banner::StartBanner(std::shared_ptr<wxGraphicsContext> graphics, const wxString level)
{
    //
    // Draw a filled rectangle
    //
    graphics->SetPen(*wxTRANSPARENT_PEN);
    wxBrush rectBrush(wxColour(24, 69, 59));
    graphics->SetBrush(rectBrush);
    graphics->DrawRectangle(0, 0, 900, 300);
    graphics->SetBrush(rectBrush);
    rectBrush.SetColour(*wxWHITE);
    graphics->SetBrush(rectBrush);
    graphics->DrawRectangle(10, 10, 880, 280);

    // Define the title and lines of text
    wxString titleText = level + " Begin";
    wxString line2 = "Space: Eat";
    wxString line3 = "0-8: Regurgitate";
    wxString line4 = "B: Headbutt";

    int titleFontSize = 100;
    wxFont titleFont(titleFontSize, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    graphics->SetFont(titleFont, wxColour(24, 69, 59));

    // Draw the title text on the panel
    graphics->DrawText(titleText, 10, 10);

    // Calculate the text font size relative to the panel size
    int textFontSize = 30;
    wxFont textFont(textFontSize, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    graphics->SetFont(textFont, wxColour(0, 0, 0));

    // Draw the lines of text on the panel
    graphics->DrawText(line2, 20, titleFontSize + 50);
    graphics->DrawText(line3, 20, titleFontSize + textFontSize + 60);
    graphics->DrawText(line4, 20, titleFontSize + (2 * textFontSize) + 70);
}

/**
 * Display the solve banner graphics
 * @param graphics the graphics context being drawn to
 * @param solved true if puzzle is solve, false if puzzle is in incorrect state
 */
void Banner::SolveBanner(std::shared_ptr<wxGraphicsContext> graphics, bool solved)
{
    wxColour color = wxColour();
    wxString text = "";
    int size = 0;
    // correct or incorrect
    if(solved)
    {
        color.Set(24, 69, 59);
        text = "Correct!";
        size = 550;
    }
    else
    {
        color.Set(255, 0, 0);
        text = "Incorrect!";
        size = 650;
    }

    //
    // Draw a filled rectangle
    //
    graphics->SetPen(*wxTRANSPARENT_PEN);
    wxBrush rectBrush(color);
    graphics->SetBrush(rectBrush);
    graphics->DrawRectangle(200, 0, size, 160);
    graphics->SetBrush(rectBrush);
    rectBrush.SetColour(*wxWHITE);
    graphics->SetBrush(rectBrush);
    graphics->DrawRectangle(210, 10, size - 20, 140);

    int titleFontSize = 100;
    wxFont titleFont(titleFontSize, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    graphics->SetFont(titleFont, color);

    // Draw the title text on the panel
    graphics->DrawText(text, 210, 10);
}
