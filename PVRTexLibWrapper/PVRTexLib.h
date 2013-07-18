/*
 *  PVRTexLib.h
 *  PVRTexLib
 *
 *  Created by Dean Ellis on 04/07/2013.
 *  Copyright (c) 2013 Dean Ellis. All rights reserved.
 *
 */

#ifndef PVRTexLib_
#define PVRTexLib_

/* The classes below are exported */
#pragma GCC visibility push(default)

extern "C" {
    void* __cdecl CompressTexture(unsigned char* data, int height, int width, int mipLevels, bool preMultiplied, bool fourbppCompression, int** dataSizes);
}

#pragma GCC visibility pop
#endif


