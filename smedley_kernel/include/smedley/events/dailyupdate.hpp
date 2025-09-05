#pragma once
#include "../event.hpp"

namespace smedley::events
{

    /**
    When the daily update is executed, this event is notified
     */
    class DailyUpdateEvent : public Event
    {
    public:
        DailyUpdateEvent();
        /// @brief returns the console command manager being initalized
        /// @brief installs the hook needed to trigger the event
        static void InstallHook();
    };

}