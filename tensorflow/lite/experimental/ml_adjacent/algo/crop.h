/* Copyright 2023 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef TENSORFLOW_LITE_EXPERIMENTAL_ML_ADJACENT_ALGO_CROP_H_
#define TENSORFLOW_LITE_EXPERIMENTAL_ML_ADJACENT_ALGO_CROP_H_
#include "tensorflow/lite/experimental/ml_adjacent/lib.h"

namespace ml_adj {
namespace crop {

// Center Crop
//
// Inputs: [img: any, frac: scalar<double>]
// Ouputs: [img: any]
//
// Crop the given image from center, scaling height and width dimensions by
// decimal input. Let `offs = floor((d - d * frac) / 2)` where `d` is a given
// dimension and `frac` is the second decimal scalar input to this Algo. The
// bounding box for each dimension `d` then covers `[offs, d - offs)`. Mimics
// semantic of `tf.image.central_crop`.
//
// https://www.tensorflow.org/api_docs/python/tf/image/central_crop

const algo::Algo* Impl_CenterCrop();

}  // namespace crop
}  // namespace ml_adj

#endif  // TENSORFLOW_LITE_EXPERIMENTAL_ML_ADJACENT_ALGO_CROP_H_
