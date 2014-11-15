// This is the main DLL file.

#include "stdafx.h"

#include "PVRTexLibWrapper.h"
#include <PVRTexture.h>
#include <PVRTextureUtilities.h>

using namespace pvrtexture;

CPVRTexture* pvrTexture = NULL;

extern void __cdecl CreateTexture(unsigned char* data, const uint32& u32Width, const uint32& u32Height, const uint32& u32Depth, const PixelType ptFormat, bool preMultiplied, const EPVRTVariableType eChannelType, const EPVRTColourSpace eColourspace)
{
    DestroyTexture();

    PVRTextureHeaderV3 pvrHeader;
    pvrHeader.u32Version = PVRTEX_CURR_IDENT;
    pvrHeader.u32Flags = preMultiplied ? PVRTEX3_PREMULTIPLIED : 0;
    pvrHeader.u64PixelFormat = ptFormat.PixelTypeID;
    pvrHeader.u32ColourSpace = eColourspace;
    pvrHeader.u32ChannelType = eChannelType;
    pvrHeader.u32Width = u32Width;
    pvrHeader.u32Height = u32Height;
    pvrHeader.u32Depth = u32Depth;
    pvrHeader.u32NumSurfaces = 1;
    pvrHeader.u32NumFaces = 1;
    pvrHeader.u32MIPMapCount = 1;
    pvrHeader.u32MetaDataSize = 0;
    pvrTexture = new CPVRTexture(pvrHeader, data);
}

extern void __cdecl DestroyTexture()
{
    if (pvrTexture != NULL)
    {
        delete pvrTexture;
        pvrTexture = NULL;
    }
}

extern bool __cdecl Resize(const uint32& u32NewWidth, const uint32& u32NewHeight, const uint32& u32NewDepth, const EResizeMode eResizeMode)
{
    if (pvrTexture == NULL)
        return false;
    return pvrtexture::Resize(*pvrTexture, u32NewWidth, u32NewHeight, u32NewDepth, eResizeMode);
}

extern bool __cdecl GenerateMIPMaps(const EResizeMode eFilterMode, const uint32 uiMIPMapsToDo)
{
    if (pvrTexture == NULL)
        return false;
    return pvrtexture::GenerateMIPMaps(*pvrTexture, eFilterMode, uiMIPMapsToDo);
}

extern bool __cdecl Transcode(const PixelType ptFormat, const EPVRTVariableType eChannelType, const EPVRTColourSpace eColourspace, const ECompressorQuality eQuality, const bool bDoDither)
{
    if (pvrTexture == NULL)
        return false;
    return pvrtexture::Transcode(*pvrTexture, ptFormat, eChannelType, eColourspace, eQuality, bDoDither);
}

extern const uint32 __cdecl GetTextureDataSize(int32 iMIPLevel)
{
    if (pvrTexture == NULL)
        return 0;
    return pvrTexture->getDataSize(iMIPLevel);
}

extern void __cdecl GetTextureData(unsigned char* data, uint32 dataSize, uint32 uiMIPLevel)
{
    if (pvrTexture == NULL)
        return;
    memcpy(data, pvrTexture->getDataPtr(uiMIPLevel), dataSize);
}