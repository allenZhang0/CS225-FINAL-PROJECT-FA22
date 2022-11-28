#include "test_helper.h"
#include <catch2/catch_test_macros.hpp>

bool compareMap(std::map<std::string, std::vector<std::string>> m1, std::map<std::string, std::vector<std::string>> m2) {
    if (m1.size() != m2.size()) {
        return false;
    }
    for (auto it = m1.begin(); it != m1.end(); it++) {
        std::string key = it->first;
        REQUIRE(m1[key].size() != m2[key].size());
        for (unsigned i = 0; i < m1[key].size(); i++) {
            REQUIRE(m1[key][i] == m2[key][i]);
        }
    }
}