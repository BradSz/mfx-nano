#include "signal/Fuzz.h"

void Fuzz::Execute(const FDSampleBuffer &input, FDSampleBuffer *output)
{
    std::copy(input.Data(), input.Data() + input.Size(), output->Data());
}