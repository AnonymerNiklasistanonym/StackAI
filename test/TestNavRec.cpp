#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <vector>
#include <tuple>

#include "NavRec.h"


TEST_CASE( "NavRec", "[NavRec]" ) {
    std::vector<std::tuple<std::string, nav_ptr, nav_ptr, float>> valuesToTest {
        {
            "find connection same position but size 0",
            std::make_shared<NavRec>(Pos2D { 0, 0 }, Pos2D { 0, 0 }),
            std::make_shared<NavRec>(Pos2D { 0, 0 }, Pos2D { 0, 0 }),
            -1
        }, {
            "find connection same position",
            std::make_shared<NavRec>(Pos2D { 0, 0 }, Pos2D { 1, 1 }),
            std::make_shared<NavRec>(Pos2D { 0, 0 }, Pos2D { 1, 1 }),
            // Somehow this is also -1
            -1
        }
    };
    for (const auto& [name, from, to, expectedOutput] : valuesToTest)
    {
        SECTION("NavRec distance check > " + name)
        {
            NavRecConnection navRevConnection { from, to };
            CHECK(expectedOutput == Approx(navRevConnection.distance).epsilon(1e-12));
            BENCHMARK("NavRec distance check > " + name + " (benchmark)") {
                NavRecConnection navRevConnection { from, to };
                return navRevConnection;
            };
        }
    }
}
