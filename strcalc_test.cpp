//
// Created by Mark on 2/13/2019.
//
#include "catch.hpp"
#include "strcalc_test.h"
#include "strcalc.h"

TEST_CASE("\"No Output\" Cases")
{
    REQUIRE(strcalc("") == 0);
    REQUIRE(strcalc("/") == 0);
    REQUIRE(strcalc("/[/") == 0);
    REQUIRE(strcalc("//[]") == 0);
    REQUIRE(strcalc("//[") == 0);
}

TEST_CASE("Single Numbers")
{
    REQUIRE(strcalc("1") == 1);
    REQUIRE(strcalc("7") == 7);
    REQUIRE(strcalc("999") == 999);
    REQUIRE(strcalc("2000") == 0);
}

TEST_CASE("Standard Delimiters")
{
    REQUIRE(strcalc("3,6") == 9);
}

TEST_CASE("Custom Delimiters")
{
    REQUIRE(strcalc("//$300") == 300);
    REQUIRE(strcalc("/#350") == 0);
    REQUIRE(strcalc("//[@@]350") == 350);
    REQUIRE(strcalc("//[#%&]400") == 400);
}


