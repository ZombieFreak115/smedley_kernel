#include "event.hpp"
#include "eventregistry.hpp"
#include "events/console.hpp"
#include "events/dailyupdate.hpp"

#define DECLARE_REGISTRY(Ev) \
    smedley::EventRegistry<Ev>::Handlers smedley::EventRegistry<Ev>::_handlers = smedley::EventRegistry<Ev>::Handlers{};

using namespace smedley::events;

DECLARE_REGISTRY(ConsoleCmdManagerInitEvent);
DECLARE_REGISTRY(DailyUpdateEvent);

namespace smedley
{

    void Event::Cancel()
    {
        _is_cancelled = _cancelable;
    }

}