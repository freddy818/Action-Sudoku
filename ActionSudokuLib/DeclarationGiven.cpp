/**
 * @file DeclarationGiven.cpp
 * @author Aion
 */

#include "pch.h"
#include "DeclarationGiven.h"
#include "ItemGiven.h"

/**
 * Constructor
 * @param game Game this declaration is a part of
 * @param node Xml node for data
 */
DeclarationGiven::DeclarationGiven(Game *game, wxXmlNode *node) : Declaration(game, node)
{
    double wid, hit;
    node->GetAttribute(L"value").ToInt(&mValue);
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
std::shared_ptr<Item> DeclarationGiven::Create(wxXmlNode *node)
{
    auto item = std::make_shared<ItemGiven>(this, node);
    item->SetWidth(GetImageWidth());
    item->SetHeight(GetImageHeight());

    return item;
}
