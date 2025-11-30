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

const float_t DEFAULT_SIGNAL_AMPLITUDE = 1.0f;
const float_t DEFAULT_PI_CONST = 3.14159265f;

SIGNAL_ build_blank_wave(const float_t t, const float_t sample_rate)
{
    const size_t signal_size = sample_rate * t;
    float_t *ptr = calloc(signal_size, sizeof(float_t));
    if (!ptr)
    {
        const SIGNAL_ trouble = {
            NULL,
            0,
            1
        };
        return trouble;
    }
    const SIGNAL_ clear_wave = {
        ptr,
        signal_size,
        0
    };
    return clear_wave;
}

SIGNAL_ build_sin_wave(float_t s_amplitude, const float_t s_phase,
const float_t s_frequency, const float_t s_sample_rate, const float_t t)
{
    if (s_amplitude == 0)
    {
        s_amplitude = DEFAULT_SIGNAL_AMPLITUDE;
    }

    const float_t s_radian_frequency = 2.0f * DEFAULT_PI_CONST * s_frequency;
    const int64_t s_samples_count = (int64_t)(s_sample_rate * t);
    const float_t delta_phase = s_radian_frequency / s_sample_rate;

    float_t *ptr = malloc(s_samples_count * sizeof(float_t));
    float_t current_phase = s_phase;

    for (size_t i = 0; i < s_samples_count; i++)
    {
        ptr[i] = s_amplitude * cosf(current_phase);
        current_phase += delta_phase;
        if (current_phase > DEFAULT_PI_CONST)
        {
            current_phase -= 2.0f * DEFAULT_PI_CONST;
        } else if ( current_phase <= -DEFAULT_PI_CONST)
        {
            current_phase += 2.0f * DEFAULT_PI_CONST;
        }
    }

    const SIGNAL_ sin_wave = {
        ptr,
        s_samples_count,
        0
    };
    return sin_wave;
}
