#pragma once
#include "../event.hpp"

namespace smedley::events
{

    /**
    When the daily update is executed, this event is notified
     */
    class DailyUpdateEvent : public Event
    {
        static constexpr uintptr_t hook_addr = 0x00108590;
        inline static uintptr_t hook_ret_addr = NULL;
        static void HookTrampoline();
        
    public:
        DailyUpdateEvent();
        /// @brief installs the hook needed to trigger the event
        static void InstallHook();

    };

}