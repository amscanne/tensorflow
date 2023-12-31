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

#ifndef TENSORFLOW_COMPILER_XLA_SERVICE_GPU_FUSION_PIPELINE_H_
#define TENSORFLOW_COMPILER_XLA_SERVICE_GPU_FUSION_PIPELINE_H_

#include "tensorflow/compiler/xla/service/gpu/gpu_device_info.h"
#include "tensorflow/compiler/xla/service/hlo_cost_analysis.h"
#include "tensorflow/compiler/xla/service/hlo_pass_pipeline.h"
#include "tensorflow/compiler/xla/stream_executor/device_description.h"
#include "tensorflow/compiler/xla/xla.pb.h"

namespace xla {
namespace gpu {

// Function wrapper around the (non-horizontal) XLA GPU fusion pipeline.
HloPassPipeline FusionPipeline(
    const DebugOptions& debug_options,
    HloCostAnalysis::ShapeSizeFunction shape_size_bytes_function,
    const GpuDeviceInfo& gpu_device_info,
    const se::CudaComputeCapability& compute_capability);

// Function wrapper around the horizontal XLA GPU fusion pipeline.
HloPassPipeline HorizontalFusionPipeline(const GpuDeviceInfo& gpu_device_info);

}  // namespace gpu
}  // namespace xla

#endif  // TENSORFLOW_COMPILER_XLA_SERVICE_GPU_FUSION_PIPELINE_H_
