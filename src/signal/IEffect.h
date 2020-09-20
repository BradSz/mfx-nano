#pragma once

#include "signal/FDSampleBuffer.h"

class IEffect
{
public:
    virtual ~IEffect() = default;

    /// @brief Processes this set of samples, applying an effect (eg, distortion)
    ///
    /// @param input frequency-domain input samples to apply effect to
    /// @param output frequency-domain output samples after effect was applied
    virtual void Execute(const FDSampleBuffer &input, FDSampleBuffer *output) = 0;
};