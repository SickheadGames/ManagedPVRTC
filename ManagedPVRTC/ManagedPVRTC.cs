using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace ManagedPVRTC
{
    public static class ManagedPVRTC
    {
        [DllImport("PVRTexLibC", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CompressTexture(byte[] data, int height, int width, int mipLevels, bool preMultiplied, bool pvrtc4bppCompression, ref IntPtr dataSizes);
    }
}
