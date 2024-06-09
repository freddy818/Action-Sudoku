/**
 * @file DeclarationContainer.cpp
 * @author Aion
 */

#include "pch.h"
#include "DeclarationContainer.h"
#include "ItemContainer.h"

/**
 * Constructor
 * @param game The game this declaration is a part of
 * @param node Xml node for data
 */
DeclarationContainer::DeclarationContainer(Game *game, wxXmlNode *node) : Declaration(game, node)
{
    double wid, hit;
    node->GetAttribute(L"width").ToDouble(&wid);
    node->GetAttribute(L"height").ToDouble(&hit);

    SetImageWidth(wid);
    SetImageHeight(hit);
    mImageName = node->GetAttribute(L"image");
    mFrontImageName = node->GetAttribute(L"front");
}

/**
 * Create the container item using this declaration
 * @param node
 * @return pointer to the item created
 */
std::shared_ptr<Item> DeclarationContainer::Create(wxXmlNode *node)
{
    auto item = std::make_shared<ItemContainer>(this, node);
    item->SetWidth(GetImageWidth());
    item->SetHeight(GetImageHeight());

    return item;
}
