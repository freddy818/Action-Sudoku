/**
 * @file DeclarationXray.cpp
 * @author adity
 */

#include "pch.h"
#include "DeclarationXray.h"
#include "ItemXray.h"

/**
 * Constructor
 * @param game Game this declaration is a part of
 * @param node Xml node for data
 */
DeclarationXray::DeclarationXray(Game *game, wxXmlNode *node) : Declaration(game, node)
{
    double wid, hit;
    node->GetAttribute(L"width").ToDouble(&wid);
    node->GetAttribute(L"height").ToDouble(&hit);
    node->GetAttribute(L"capacity").ToInt(&mCapacity);

    SetImageWidth(wid);
    SetImageHeight(hit);
    mImageName = node->GetAttribute(L"image");
}

/**
 * Create an item using this declaration
 * @param node
 * @return pointer to the created item
 */
std::shared_ptr<Item> DeclarationXray::Create(wxXmlNode *node)
{
    auto item = std::make_shared<ItemXray>(this, node);
    item->SetWidth(GetImageWidth());
    item->SetHeight(GetImageHeight());

    return item;
}
