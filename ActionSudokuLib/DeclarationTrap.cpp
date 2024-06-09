/**
 * @file DeclarationTrap.cpp
 * @author Frederick Fan
 */

#include "pch.h"
#include "DeclarationTrap.h"
#include "ItemTrap.h"

/**
 * Constructor
 * @param game Game this declaration is a part of
 * @param node Xml node for data about declaration
 */
DeclarationTrap::DeclarationTrap(Game *game, wxXmlNode *node) : Declaration(game, node)
{
    double wid, hit;
    node->GetAttribute(L"width").ToDouble(&wid);
    node->GetAttribute(L"height").ToDouble(&hit);

    SetImageWidth(wid);
    SetImageHeight(hit);
    mImageName = node->GetAttribute(L"image");
}

/**
 * Create an item using this declaration
 * @param node Xml node
 * @return pointer to the item created
 */
std::shared_ptr<Item> DeclarationTrap::Create(wxXmlNode *node)
{
    auto item = std::make_shared<ItemTrap>(this, node);
    item->SetWidth(GetImageWidth());
    item->SetHeight(GetImageHeight());

    return item;
}
