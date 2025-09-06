#pragma once
#include "../event.hpp"

namespace smedley::v2 {
    class CCountry;
}

namespace smedley::events
{

    /**
    When the monthly update is executed for a country, this event is notified
     */
    class MonthlyUpdateEvent : public Event
    {
        v2::CCountry* _country;
        static void  HookTrampoline();
        static constexpr uintptr_t hook_addr = 0x0010c2a6;
        inline static uintptr_t hook_ret_addr = NULL;
    public:
        MonthlyUpdateEvent(v2::CCountry* country);
        // @brief returns the country being updated
        v2::CCountry* GetCountry();


        /// @brief installs the hook needed to trigger the event
        static void InstallHook();
    };
}
