#include "parse_test.h"
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
    return true; 
}

TEST_CASE("trailing_spaces", "[case-1]") {
    Graph g("/workspaces/CS 225/CS225/CS225-FINAL-PROJECT-FA22/tests/trailing_spaces.tsv");
    std::map<std::string, std::vector<std::string>> ans; 
    std::vector<std::string> n1;
    n1.push_back("NODE2");
    n1.push_back("NODE6");
    n1.push_back("NODE14");
    n1.push_back("NODE16");
    ans.insert({"NODE1", n1});

    std::vector<std::string> n2;
    n2.push_back("NODE4");
    n2.push_back("NODE12");
    n2.push_back("NODE18");
    ans.insert({"NODE2", n2});

    std::vector<std::string> n3;
    n3.push_back("NODE10");
    n3.push_back("NODE20");
    ans.insert({"NODE3", n3});

    std::vector<std::string> n4;
    n4.push_back("NODE8");
    ans.insert({"NODE4", n4});

    std::map<std::string, std::vector<std::string>> map = g.getGraph();
    REQUIRE(compareMap(map, ans));
}