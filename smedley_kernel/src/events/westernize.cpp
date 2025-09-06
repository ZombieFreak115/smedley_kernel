#include "eventregistry.hpp"
#include "memory.hpp"
#include "events/westernize.hpp"


namespace smedley::v2 {
    class CCountry;
}

using namespace smedley;


void WesternizeEventHook(v2::CCountry* country)
{
    smedley::EventRegistry<events::WesternizeEvent>::Notify(events::WesternizeEvent(country));
}


namespace smedley::events
{
    void __declspec(naked) WesternizeEvent::HookTrampoline()
    {
        __asm {
            // no need to do anything before the call as it is at the start of the func

            call WesternizeEventHook

            // patched instructions

            push ebp
            mov ebp, esp
            mov eax, fs:0x0

            jmp hook_ret_addr
        }
    }

    WesternizeEvent::WesternizeEvent(v2::CCountry* country) : Event(false)
    {
        _country = country;
    }
    v2::CCountry* WesternizeEvent::GetCountry() {
        return _country;
    }
    void WesternizeEvent::InstallHook()
    {
        hook_ret_addr = memory::Map::base_addr + hook_addr + 5;
        memory::Hook(memory::Map::base_addr + hook_addr, HookTrampoline, 9, nullptr);
    }

}