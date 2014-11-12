// PVRTexLibC.h

#pragma once

#include <PVRTGlobal.h>

extern "C" {
    __declspec(dllexport) void* __cdecl CompressTexture(unsigned char* data, int height, int width, int mipLevels, bool preMultiplied, bool fourbppCompression, int** dataSizes);

    __declspec(dllexport) void* __cdecl Transcode(unsigned char* data, int height, int width, PVRTuint64 sourceFormat, PVRTuint64 destinationFormat, int mipLevels, bool preMultiplied, int** destinationDataSizes);
}
