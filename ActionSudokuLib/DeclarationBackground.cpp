/**
 * @file DeclarationBackground.cpp
 * @author Aion
 */

#include "pch.h"
#include "DeclarationBackground.h"

/**
 * Constructor
 * @param game Game this declaration is a part of
 * @param node Xml node with information about the background
 */
DeclarationBackground::DeclarationBackground(Game *game, wxXmlNode *node) : Declaration(game, node)
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
 * @param node
 * @return pointer to the item created
 */
std::shared_ptr<Item> DeclarationBackground::Create(wxXmlNode *node)
{
    auto item = std::make_shared<ItemBackground>(this, node);
    item->SetWidth(GetImageWidth());
    item->SetHeight(GetImageHeight());

    return item;
}
