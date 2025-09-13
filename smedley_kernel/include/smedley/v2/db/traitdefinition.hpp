#pragma once

#include "../../std/string.hpp"
#include "../../std/vector.hpp"
#include "../country.hpp"
#include <cstring>
#include <string>

namespace smedley::v2
{

    class CTraitDefinitionArray
    {
        CTraitDefinition* _traitDefinitions[10];
    };

    static_assert(sizeof(CTraitDefinitionArray) == 0x28);

}