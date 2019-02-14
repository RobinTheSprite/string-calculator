//
// Created by Mark on 2/13/2019.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "strcalc_test.h"
#include "strcalc.h"

TEST_CASE("Corner Cases")
{
    REQUIRE(strcalc("") == 0);
}

//gtmeier@alaska.edu
//gtmeier on git

TEST_CASE("Single Numbers")
{
    REQUIRE(strcalc("1") == 1);
    REQUIRE(strcalc("7") == 7);
    REQUIRE(strcalc("999") == 999);
    REQUIRE(strcalc("2000") == 0);
}




