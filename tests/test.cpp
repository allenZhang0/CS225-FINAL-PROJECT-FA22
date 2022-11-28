#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include "catch.hpp"


#include "/workspaces/CS225/CS225-FINAL-PROJECT-FA22/src/graph.h"
#include <map>

bool compareMap(std::map<std::string, std::vector<std::string>> m1, std::map<std::string, std::vector<std::string>> m2) {
    if (m1.size() != m2.size()) {
        return false;
    }
    for (auto it = m1.begin(); it != m1.end(); it++) {
        std::string key = it->first;
        if(m1[key].size() != m2[key].size()) {
            return false; 
        } else {
            for (unsigned i = 0; i < m1[key].size(); i++) {
                if(std::find(m2[key].begin(), m2[key].end(), m1[key][i]) == m2[key].end()) {
                    return false;
                }
            }
        }
    }
    return true; 
}

TEST_CASE("trailing_spaces", "[case-1]") {
    Graph g("/workspaces/CS225/CS225-FINAL-PROJECT-FA22/tests/PLS - Sheet1.tsv");
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
    for(std::map<std::string, std::vector<std::string>>::const_iterator it = g.graph_.begin(); it != g.graph_.end(); it++){
        std::cout << "Node: " << std::endl;
        std::cout << it->first << std::endl;
        std::cout << "Connects: " << std::endl;
        for(size_t a = 0; a < it->second.size(); a++){
            std::cout << it->second[a] << std::endl; 
        }
    }
    std::cout << "====================================" << std::endl;
    for(std::map<std::string, std::vector<std::string>>::const_iterator it = ans.begin(); it != ans.end(); it++){
        std::cout << "Node: " << std::endl;
        std::cout << it->first << std::endl;
        std::cout << "Connects: " << std::endl;
        for(size_t a = 0; a < it->second.size(); a++){
            std::cout << it->second[a] << std::endl; 
        }
    }
    REQUIRE(compareMap(map, ans));
}