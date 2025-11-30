/*
Copyright 2025 Nazarenko Mykyta

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "dsp.h"

SIGNAL_ build_blank_wave(const float_t t, const int32_t frequency)
{
    const size_t signal_size = (float_t)frequency * t;
    float_t *ptr = calloc(signal_size, sizeof(float_t));
    const SIGNAL_ clear_wave = {
        ptr,
        signal_size
    };
    return clear_wave;
}


