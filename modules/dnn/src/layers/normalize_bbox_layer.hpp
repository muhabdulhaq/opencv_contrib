/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                           License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2013, OpenCV Foundation, all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#ifndef __OPENCV_DNN_LAYERS_NORMALIZEBBOX_LAYER_HPP__
#define __OPENCV_DNN_LAYERS_NORMALIZEBBOX_LAYER_HPP__
#include "../precomp.hpp"

namespace cv
{
namespace dnn
{
class NormalizeBBoxLayer : public Layer
{
    Mat _buffer;

    Mat _sumChannelMultiplier;
    Mat _sumSpatialMultiplier;

    Blob _scale;

    float _eps;
    bool _across_spatial;
    bool _channel_shared;

    size_t _num;
    size_t _channels;
    size_t _rows;
    size_t _cols;

    size_t _channelSize;
    size_t _imageSize;

    static const size_t _numAxes = 4;
    static const std::string _layerName;

public:
    NormalizeBBoxLayer(LayerParams &params);
    void allocate(const std::vector<Blob*> &inputs, std::vector<Blob> &outputs);
    void forward(std::vector<Blob*> &inputs, std::vector<Blob> &outputs);

    void checkInputs(const std::vector<Blob*> &inputs);

    template<typename T>
    T getParameter(const LayerParams &params,
                   const std::string &parameterName,
                   const size_t &idx = 0,
                   const bool required = true,
                   const T& defaultValue = T());

    bool getParameterDict(const LayerParams &params,
                          const std::string &parameterName,
                          DictValue& result);
};
}
}
#endif
