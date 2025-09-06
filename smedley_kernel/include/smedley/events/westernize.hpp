#pragma once
#include "../event.hpp"

namespace smedley::v2 {
    class CCountry;
}



namespace smedley::events
{

    /**
    When a country westernizes, this event is notified
     */
    class WesternizeEvent : public Event
    {
        v2::CCountry* _country;
        static void  HookTrampoline();
        static constexpr uintptr_t hook_addr = 0x00142370;
        inline static uintptr_t hook_ret_addr = NULL;
    public:
        WesternizeEvent(v2::CCountry* country);

        /// @brief returns the westernizing country
        v2::CCountry* GetCountry();

        /// @brief installs the hook needed to trigger the event
        static void InstallHook();
    };

}