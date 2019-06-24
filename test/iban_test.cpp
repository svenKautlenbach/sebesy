#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <stdexcept>

#include "iban.h"

using namespace sebesy;

namespace
{
    TEST(Iban, ctorThrowsInvalidArgumentErrorOnInvalidIban)
    {
        ASSERT_THROW(Iban("ABC"), std::invalid_argument);
    }

}
