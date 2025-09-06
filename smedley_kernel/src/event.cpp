#include "event.hpp"
#include "eventregistry.hpp"
#include "events/console.hpp"
#include "events/dailyupdate.hpp"
#include "events/westernize.hpp"

#define DECLARE_REGISTRY(Ev) \
    smedley::EventRegistry<Ev>::Handlers smedley::EventRegistry<Ev>::_handlers = smedley::EventRegistry<Ev>::Handlers{};

using namespace smedley::events;

DECLARE_REGISTRY(ConsoleCmdManagerInitEvent);
DECLARE_REGISTRY(DailyUpdateEvent);
DECLARE_REGISTRY(WesternizeEvent);

namespace smedley
{

    void Event::Cancel()
    {
        _is_cancelled = _cancelable;
    }

}