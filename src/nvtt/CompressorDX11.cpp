// Copyright (c) 2009-2011 Ignacio Castano <castano@gmail.com>
// Copyright (c) 2007-2009 NVIDIA Corporation -- Ignacio Castano <icastano@nvidia.com>
// 
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#include "CompressorDX11.h"

#include "nvtt.h"
#include "CompressionOptions.h"

#include "bc6h/zoh.h"
#include "bc6h/utils.h"

//#include "bc7/avpcl.h"
//#include "bc7/utils.h"

using namespace nv;
using namespace nvtt;


void CompressorBC6::compressBlock(Tile & tile, AlphaMode alphaMode, const CompressionOptions::Private & compressionOptions, void * output)
{
    NV_UNUSED(alphaMode); // ZOH does not support alpha.

    if (compressionOptions.pixelType == PixelType_UnsignedFloat ||
        compressionOptions.pixelType == PixelType_UnsignedNorm ||
        compressionOptions.pixelType == PixelType_UnsignedInt)
    {
        Utils::FORMAT = UNSIGNED_F16; // @@ Do not use globals.
    }
    else
    {
        Utils::FORMAT = SIGNED_F16;
    }

    ZOH::compress(tile, (char *)output);
}


void CompressorBC7::compressBlock(Tile & tile, AlphaMode alphaMode, const CompressionOptions::Private & compressionOptions, void * output)
{
    // @@ TODO
}
