#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

/*
unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}*/

/*
TEST_CASE( "Factorials benchmarks", "[factorial]" ) {
    BENCHMARK("Factorial 20") {
        return Factorial(20);
    };
    BENCHMARK("Factorial 2000") {
        return Factorial(2000);
    };
    BENCHMARK("Factorial 20000000") {
        return Factorial(20000000);
    };
}*/
