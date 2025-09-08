#pragma once

#include "../clausewitz/persistent.hpp"
#include "../std/vector.hpp"
#include "../v2/selectable.hpp"

namespace smedley::v2
{

    class CUniqueUnitNameInternal : public clausewitz::CPersistent
    {
    protected:
        uint32_t _uk_0x8;
        uint32_t _uk_0xc;
        uint32_t _uk_0x10;
        uint32_t _uk_0x14;
        short count;
    };

    static_assert(sizeof(CUniqueUnitNameInternal) == 0x1c);

    class CUniqueUnitName : public clausewitz::CPersistent
    {
    protected:
        sstd::vector<CUniqueUnitNameInternal> _names;
    };

    static_assert(sizeof(CUniqueUnitName) == 0x18);


    class CSubUnitDefinition
    {
    };

    class CSubUnit
    {
    };
    class CUnit : clausewitz::CList<CSubUnit*>, CSelectable, clausewitz::CReferenceObject
    {
    };

}