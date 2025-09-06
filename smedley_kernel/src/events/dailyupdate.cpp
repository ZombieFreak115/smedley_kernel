#include "eventregistry.hpp"
#include "memory.hpp"
#include "events/dailyupdate.hpp"


using namespace smedley;

void DailyUpdateEventHook()
{
    smedley::EventRegistry<events::DailyUpdateEvent>::Notify(events::DailyUpdateEvent());
}

//static void __declspec(naked) HookTrampoline()
//{
//    __asm {
//        call DailyUpdateEventHook
//
//        //patched instructions
//        push ebp
//        mov ebp, esp
//        and esp, 0xfffffff8
//
//        jmp hook_ret_addr
//    }
//}



namespace smedley::events
{

    void __declspec(naked) DailyUpdateEvent::HookTrampoline()
    {
        __asm {
            call DailyUpdateEventHook

            //patched instructions
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