#include <smedley/plugin.hpp>
#include <smedley/eventregistry.hpp>
#include <smedley/events/dailyupdate.hpp>
#include <smedley/events/westernize.hpp>
#include <smedley/v2/gamestate.hpp>
#include <smedley/v2/db/culture.hpp>

namespace dailyupdate_example
{
    using namespace smedley;

    class Plugin : public smedley::Plugin
    {
    public:
        Plugin() : smedley::Plugin()
        {
        }

        void OnLoad() override
        {
            logger().Info("Loading daily update example");

            AddEventHandler<smedley::events::DailyUpdateEvent>("on_daily_update_init", std::bind(&Plugin::OnDailyUpdate, this, std::placeholders::_1));
            AddEventHandler<smedley::events::WesternizeEvent>("on_westernize_update_init", std::bind(&Plugin::OnWesternize, this, std::placeholders::_1));
        }

        void OnDailyUpdate(events::DailyUpdateEvent& e)
        {
            /*for (auto country : v2::CCurrentGameState::instance()->countries()) {
                bool civ = country->Civilized();
                if (!civ) {
                    country->Westernize();
                }
                
                country->SetResearchPoints(smedley::clausewitz::CFixedPoint{100000});
            }*/
        }
        void OnWesternize(events::WesternizeEvent& e)
        {
            v2::CCountry* country = e.GetCountry();

            country->SetResearchPoints(smedley::clausewitz::CFixedPoint{ 1000000 });
            
        }
    };

}

PLUGIN_API smedley::Plugin* CreatePlugin()
{
    return static_cast<smedley::Plugin*>(new dailyupdate_example::Plugin{});
}