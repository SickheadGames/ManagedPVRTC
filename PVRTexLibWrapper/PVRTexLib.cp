/*
 *  PVRTexLib.cp
 *  PVRTexLib
 *
 *  Created by Dean Ellis on 04/07/2013.
 *  Copyright (c) 2013 Dean Ellis. All rights reserved.
 *
 */

#include <iostream>
#include "PVRTexLib.h"
#include "PVRTexLibPriv.h"
#include <PVRTexture.h>
#include <PVRTextureUtilities.h>

extern void* __cdecl CompressTexture(unsigned char* data, int height, int width, int mipLevels, bool preMultiplied, bool fourbppCompression, int** dataSizes)
{
    PVRTextureHeaderV3 pvrHeader;
    
    pvrHeader.u32Version = PVRTEX_CURR_IDENT;
    pvrHeader.u32Flags = preMultiplied ? PVRTEX3_PREMULTIPLIED : 0;
    pvrHeader.u64PixelFormat = pvrtexture::PVRStandard8PixelType.PixelTypeID;
    pvrHeader.u32ColourSpace = ePVRTCSpacelRGB;
    pvrHeader.u32ChannelType = ePVRTVarTypeUnsignedByteNorm;
    pvrHeader.u32Height = height;
    pvrHeader.u32Width = width;
    pvrHeader.u32Depth = 1;
    pvrHeader.u32NumSurfaces = 1;
    pvrHeader.u32NumFaces = 1;
    pvrHeader.u32MIPMapCount = 1;
    pvrHeader.u32MetaDataSize = 0;
    
    pvrtexture::CPVRTexture sTexture( pvrHeader, data );
    
    if (mipLevels > 1)
        GenerateMIPMaps(sTexture, pvrtexture::eResizeLinear, mipLevels);
    
    auto bpp =  fourbppCompression ? ePVRTPF_PVRTCI_4bpp_RGBA : ePVRTPF_PVRTCI_2bpp_RGBA;
    
    pvrtexture::PixelType pixType(bpp);
    Transcode(sTexture,
              pixType,
              ePVRTVarTypeUnsignedByteNorm,
              ePVRTCSpacelRGB );
    
    *dataSizes = new int[mipLevels];
    
    for(int x = 0; x < mipLevels; x++)
        (*dataSizes)[x] = sTexture.getDataSize(x);
    
    int totalDataSize = sTexture.getDataSize();
    auto returnData = new unsigned char[totalDataSize];
    
    memcpy(returnData, sTexture.getDataPtr(), totalDataSize);
    
    return returnData;
}
