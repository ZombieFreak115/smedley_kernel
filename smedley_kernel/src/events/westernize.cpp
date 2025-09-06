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
            // save context
            push eax
            push fs

            // use free register to push the "this" country ptr as variable to func
            mov ecx, [ebp+0x8]
            push ecx

            call WesternizeEventHook
            // restore context
            pop ecx
            pop fs
            pop eax

            // patched instructions
            cmp DWORD PTR ds : 0x125eadc, 0x0

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
        memory::Hook(memory::Map::base_addr + hook_addr, HookTrampoline, 7, nullptr);
    }

}