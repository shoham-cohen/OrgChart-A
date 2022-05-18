#include "OrgChart.hpp"
#include <iostream>
#include "doctest.h"

using namespace ariel;

TEST_CASE("Good case"){
    OrgChart chart;
    CHECK_NOTHROW(chart.add_root("CEO"));
    CHECK_NOTHROW(chart.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(chart.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(chart.add_sub("CEO", "COO"));
    CHECK_NOTHROW(chart.add_sub("CTO", "PM"));
    
    vector<string> reverse = {"PM", "CTO", "CFO", "COO", "CEO"};
    vector<string> people = {"CEO", "CTO", "CFO", "COO", "PM"};
    vector<string> preorder = {"NEW CEO", "CTO", "PM", "CFO", "COO"};


    auto iterator = chart.begin_reverse_order();
    for (size_t i = 0; i < reverse.size(); iterator++, i++){
        CHECK_EQ((*iterator), reverse[i]);
    }
    
    iterator = chart.begin_level_order();
    for (size_t i = 0; i < reverse.size(); iterator++, i++){
        CHECK_EQ((*iterator), people[i]);
    }

    CHECK_NOTHROW(chart.add_root("NEW CEO"));
    iterator = chart.begin_preorder();
    for (size_t i = 0; i < reverse.size(); iterator++, i++){
        CHECK_EQ((*iterator), reverse[i]);
    }
}

TEST_CASE("bad case"){
    OrgChart chart;
    chart.add_root("CEO");
    CHECK_THROWS(chart.add_sub("NOT EXIST", "CTO"));
    chart.add_root("NEW CEO");
    CHECK_NE(chart.root.name, "CEO");
    CHECK_THROWS(chart.add_sub("CEO", "CTO"));

}