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

TEST_CASE("Comma Delimiters")
{
    REQUIRE(strcalc("3,6") == 9);
    REQUIRE(strcalc("10,12") == 22);
    REQUIRE(strcalc("1001,100")==100);
    REQUIRE(strcalc("1001,1001")==0);
}

TEST_CASE("Newline Delimiters")
{
    REQUIRE(strcalc("5\n6")==11);
    REQUIRE(strcalc("1001\n1")==1);
    REQUIRE(strcalc("1001\n1001")==0);
}

TEST_CASE("Custom Delimiters")
{
    REQUIRE(strcalc("//$300") == 300);
    REQUIRE(strcalc("/#350") == 0);
    REQUIRE(strcalc("//[@@]350") == 350);
    REQUIRE(strcalc("//[#%&]400") == 400);
}

TEST_CASE("3 Numbers , or newline delimited")
{
    REQUIRE(strcalc("1,2,3")==6);
    REQUIRE(strcalc("1\n2\n3")==6);
    REQUIRE(strcalc("1,2\n3")==6);
    REQUIRE(strcalc("1001,1,2")==3);
    REQUIRE(strcalc("1001,1001,1001")==0);
}

TEST_CASE("Negative Number Throws Exception")
{
    REQUIRE_THROWS_AS(strcalc("-1"), const char*);
    REQUIRE_THROWS_AS(strcalc("1,-1"), const char*);
    REQUIRE_THROWS_AS(strcalc("1001,1,-1"), const char*);
    REQUIRE_THROWS_AS(strcalc("1001\n1\n-1"), const char*);
    REQUIRE_THROWS_AS(strcalc("1001,1\n-1"), const char*);
}

