/**
 * @file DeclarationSparty.cpp
 * @author Aion
 */

#include "pch.h"
#include "DeclarationSparty.h"
#include "Game.h"

/**
 * Constructor for the sparty
 * @param game Game this declaration is a part of
 * @param node Xml node for data
 */
DeclarationSparty::DeclarationSparty(Game *game, wxXmlNode *node) : Declaration(game, node)
{
    double wid, hit;
    node->GetAttribute(L"width").ToDouble(&wid);
    node->GetAttribute(L"height").ToDouble(&hit);

    SetImageWidth(wid);
    SetImageHeight(hit);

    node->GetAttribute(L"front").ToInt(&front);
    node->GetAttribute(L"head-pivot-angle").ToDouble(&headPivotAngle);
    node->GetAttribute(L"head-pivot-x").ToInt(&headPivot.x);
    node->GetAttribute(L"head-pivot-y").ToInt(&headPivot.y);
    headImage = node->GetAttribute(L"image1");
    mouthImage = node->GetAttribute(L"image2");
    node->GetAttribute(L"mouth-pivot-angle").ToDouble(&mouthPivotAngle);
    node->GetAttribute(L"mouth-pivot-x").ToInt(&mouthPivot.y);
    node->GetAttribute(L"mouth-pivot-y").ToInt(&mouthPivot.y);
    node->GetAttribute(L"target-x").ToInt(&targetX);
    node->GetAttribute(L"target-y").ToInt(&targetY);
}

/**
 * Create the sparty item
 * @param node the xml node
 * @return pointer to the created sparty
 */
std::shared_ptr<Item> DeclarationSparty::Create(wxXmlNode *node)
{
    auto item = std::make_shared<ItemSparty>(this, node);
    item->SetWidth(GetImageWidth());
    item->SetHeight(GetImageHeight());

    GetGame()->SetSparty(item);

    return item;
}
