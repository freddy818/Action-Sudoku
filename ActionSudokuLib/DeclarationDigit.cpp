/**
 * @file DeclarationDigit.cpp
 * @author Aion
 */

#include "pch.h"
#include "DeclarationDigit.h"
#include "ItemDigit.h"

/**
 * Constructor
 * @param game Game this declaration is a part of
 * @param node Xml node for data about declaration
 */
DeclarationDigit::DeclarationDigit(Game *game, wxXmlNode *node) : Declaration(game, node)
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
 * @param node Xml node
 * @return pointer to the item created
 */
std::shared_ptr<Item> DeclarationDigit::Create(wxXmlNode *node)
{
    auto item = std::make_shared<ItemDigit>(this, node);
    item->SetWidth(GetImageWidth());
    item->SetHeight(GetImageHeight());

    return item;
}
