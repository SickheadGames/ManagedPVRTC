using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace ManagedPVRTC
{
    public enum PixelFormat : ulong
    {
        PVRTCI_2bpp_RGB,
        PVRTCI_2bpp_RGBA,
        PVRTCI_4bpp_RGB,
        PVRTCI_4bpp_RGBA,
        PVRTCII_2bpp,
        PVRTCII_4bpp,
        ETC1,
        DXT1,
        DXT2,
        DXT3,
        DXT4,
        DXT5,

        //These formats are identical to some DXT formats.
        BC1 = DXT1,
        BC2 = DXT3,
        BC3 = DXT5,

        //These are currently unsupported:
        BC4,
        BC5,
        BC6,
        BC7,

        //These are supported
        UYVY,
        YUY2,
        BW1bpp,
        SharedExponentR9G9B9E5,
        RGBG8888,
        GRGB8888,
        ETC2_RGB,
        ETC2_RGBA,
        ETC2_RGB_A1,
        EAC_R11,
        EAC_RG11,

        RGB565 = 0x5060561626772,
        RGBA4444 = 0x404040461626772,
        RGBA8888 = 0x808080861626772,
    };

    public static class ManagedPVRTC
    {
        [DllImport("pvrtc", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CompressTexture(byte[] data, int height, int width, int mipLevels, bool preMultiplied, bool pvrtc4bppCompression, ref IntPtr dataSizes);

        [DllImport("pvrtc", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr Transcode(byte[] data, int height, int width, PixelFormat sourceFormat, PixelFormat destinationFormat, int mipLevels, bool preMultiplied, ref IntPtr destinationDataSizes);
    }
}
