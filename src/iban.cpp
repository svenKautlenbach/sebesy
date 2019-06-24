#include "iban.h"

#include <stdexcept>

namespace sebesy
{
    Iban::Iban(std::string number)
    {
        throw std::invalid_argument("Bad IBAN number(" + number + ")");
    }
}