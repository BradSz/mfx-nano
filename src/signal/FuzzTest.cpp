#include <boost/test/unit_test.hpp>

#include "signal/Fuzz.h"

struct FuzzTest
{
    FDSampleBuffer a{2000};
    FDSampleBuffer b{2000};
};

BOOST_FIXTURE_TEST_CASE(InputOutput, FuzzTest)
{
    Fuzz f;
    f.Execute(a, &b);
}
