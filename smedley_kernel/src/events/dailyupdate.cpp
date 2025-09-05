#include "eventregistry.hpp"
#include "memory.hpp"
#include "events/dailyupdate.hpp"





namespace smedley::events
{

    constexpr uintptr_t hook_addr = 0x00108590;
    uintptr_t hook_ret_addr = NULL;
    void DailyUpdateEventHook()
    {
        smedley::EventRegistry<events::DailyUpdateEvent>::Notify(events::DailyUpdateEvent());
    }

    void __declspec(naked) HookTrampoline()
    {
        __asm {
            call DailyUpdateEventHook

            // patched instructions
            push ebp
            mov ebp, esp
            and esp, 0xfffffff8

            jmp hook_ret_addr
        }
    }




   DailyUpdateEvent::DailyUpdateEvent() : Event(false)
    {
    }

    void DailyUpdateEvent::InstallHook()
    {
        hook_ret_addr = memory::Map::base_addr + hook_addr + 5; 
        memory::Hook(memory::Map::base_addr + hook_addr, HookTrampoline, 6, nullptr);
    }

}