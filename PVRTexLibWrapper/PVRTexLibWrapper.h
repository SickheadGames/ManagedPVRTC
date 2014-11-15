// PVRTexLibC.h

#pragma once

#include <PVRTGlobal.h>
#include <PVRTextureDefines.h>
#include <PVRTextureFormat.h>

using namespace pvrtexture;

extern "C" {
    __declspec(dllexport) void __cdecl CreateTexture(unsigned char* data, const uint32& u32Width, const uint32& u32Height, const uint32& u32Depth, const PixelType ptFormat, bool preMultiplied, const EPVRTVariableType eChannelType, const EPVRTColourSpace eColourspace);

    __declspec(dllexport) void __cdecl DestroyTexture();

    __declspec(dllexport) bool __cdecl Resize(const uint32& u32NewWidth, const uint32& u32NewHeight, const uint32& u32NewDepth, const EResizeMode eResizeMode);

    __declspec(dllexport) bool __cdecl GenerateMIPMaps(const EResizeMode eFilterMode, const uint32 uiMIPMapsToDo = PVRTEX_ALLMIPLEVELS);

    __declspec(dllexport) bool __cdecl Transcode(const PixelType ptFormat, const EPVRTVariableType eChannelType, const EPVRTColourSpace eColourspace, const ECompressorQuality eQuality = ePVRTCNormal, const bool bDoDither = false);

    __declspec(dllexport) const uint32 __cdecl GetTextureDataSize(int32 iMIPLevel = PVRTEX_ALLMIPLEVELS);

    __declspec(dllexport) void __cdecl GetTextureData(unsigned char* data, uint32 dataSize, uint32 uiMIPLevel = 0);
}
