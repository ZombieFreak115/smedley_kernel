#pragma once
#include "../event.hpp"

namespace smedley::v2 {
    class CCountry;
    class CCountryTag;
}

namespace smedley::events
{

    /**
    When one country spheres another, this event is notified.
    This event is also notified during save load (as it appears the game calls it on every sphere pair on save load). Should probably be changed later
     */
    class AddToSphereEvent : public Event
    {
        v2::CCountry* _source;
        v2::CCountryTag* _target;
        static void  HookTrampoline();
        static constexpr uintptr_t hook_addr = 0x00133e59;
        inline static uintptr_t hook_ret_addr = NULL;
    public:
        AddToSphereEvent(v2::CCountry* source, v2::CCountryTag* target);

        /// @brief returns country which sphered the target
        v2::CCountry* GetSource();


        /// @brief returns country tag which got sphered
        v2::CCountryTag* GetTarget();

        /// @brief installs the hook needed to trigger the event
        static void InstallHook();
    };

}