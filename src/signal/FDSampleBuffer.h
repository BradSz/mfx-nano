#pragma once

#include <vector>

class FDSampleBuffer final
{
public:
    using Sample = float;

    FDSampleBuffer(size_t size) : samples_(size) {}

    inline const Sample *Data() const { return samples_.data(); }
    inline Sample *Data() { return samples_.data(); }
    inline size_t Size() const { return samples_.size(); }

    FDSampleBuffer(FDSampleBuffer &&) = default;
    FDSampleBuffer(const FDSampleBuffer &) = delete;
    FDSampleBuffer &operator=(FDSampleBuffer &&) = default;
    FDSampleBuffer &operator=(const FDSampleBuffer &) = delete;

private:
    std::vector<Sample> samples_;
};