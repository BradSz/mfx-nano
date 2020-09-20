#pragma once

#include "signal/IEffect.h"

class Fuzz : public IEffect
{
public:
    Fuzz() = default;
    ~Fuzz() override = default;

    void Execute(const FDSampleBuffer &input, FDSampleBuffer *output) override;
};