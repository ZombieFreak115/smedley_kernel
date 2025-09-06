#include "hooks.hpp"
#include "events/console.hpp"
#include "events/dailyupdate.hpp"
#include "events/westernize.hpp"

namespace smedley
{

    void InstallHooks()
    {
        using namespace events;

        // event hooks
        ConsoleCmdManagerInitEvent::InstallHook();
        DailyUpdateEvent::InstallHook();
        WesternizeEvent::InstallHook();
    }

}