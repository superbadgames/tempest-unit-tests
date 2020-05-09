#include "stdafx.h"
#include <Boxes/BoxesFactory.h>

using namespace Boxes;

BoxesFactory::BoxesFactory(void)
{

}

BoxesFactory::~BoxesFactory(void)
{

}

TE::p_GameObject2D BoxesFactory::v_Create(string type, const TM::Point2& pos, F32 scale, F32 pixelSize, U32 textureID)
{
    if(strcmp(type.c_str(), "box") == 0)
    {
        p_Box box = make_shared<Box>();
        box->SetPosition(pos);
        box->SetTexture(TE::TextureManager::Instance()->GetTexture(textureID));
        box->SetDefaultPixelSize(pixelSize);
        box->SetScale(scale);

        return box;
    }
    else
    {
        TE::ErrorManager::Instance()->SetError(TE::APPLICATION, "BoxesFactory::Create unable to create object with type " + type);
        return nullptr;
    }
}