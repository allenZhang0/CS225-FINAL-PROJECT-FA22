#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include <limits.h>


#include "catch.hpp"


#include "../src/graph.h"
#include <map>

bool compareMap(std::map<std::string, std::vector<std::pair<std::string,int>>> m1, std::map<std::string, std::vector<std::pair<std::string,int>>> m2) {
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

TEST_CASE("Perfect Input", "[case-1]") {
    Graph g("../CS225-FINAL-PROJECT-FA22/tests/PLS - Sheet1.tsv");
    std::map<std::string, std::vector<std::pair<std::string,int>>> ans; 
    std::vector<std::pair<std::string,int>> n1;
    n1.push_back({"NODE2",3});
    n1.push_back({"NODE16",1});
    ans.insert({"NODE1", n1});

    std::vector<std::pair<std::string,int>> n2;
    n2.push_back({"NODE4",2});
    n2.push_back({"NODE12",1});
    ans.insert({"NODE2", n2});

    std::vector<std::pair<std::string,int>> n3;
    n3.push_back({"NODE10",1});
    n3.push_back({"NODE20",1});
    ans.insert({"NODE3", n3});

    std::vector<std::pair<std::string,int>> n4;
    n4.push_back({"NODE8",1});
    ans.insert({"NODE4", n4});
    
    std::map<std::string, std::vector<std::pair<std::string,int>>> map = g.getGraph();
    /*for(std::map<std::string, std::vector<std::pair<std::string,int>>>::const_iterator it = map.begin(); it != map.end(); it++){
        std::cout << "Node: " << std::endl;
        std::cout << it->first << std::endl;
        std::cout << "Connects: " << std::endl;
        for(size_t a = 0; a < it->second.size(); a++){
            std::cout << it->second[a].first << " || Weight: " << it->second[a].second << std::endl; 
        }
    }
    std::cout << "====================================" << std::endl;
    for(std::map<std::string, std::vector<std::pair<std::string,int>>>::const_iterator it = ans.begin(); it != ans.end(); it++){
        std::cout << "Node: " << std::endl;
        std::cout << it->first << std::endl;
        std::cout << "Connects: " << std::endl;
        for(size_t a = 0; a < it->second.size(); a++){
            std::cout << it->second[a].first << " || Weight: " << it->second[a].second << std::endl; 
        }
    }*/
    REQUIRE(compareMap(map, ans));
}
TEST_CASE("With extra spaces", "[case-2]") {
    Graph g("../CS225-FINAL-PROJECT-FA22/tests/PLS - Sheet1 copy.tsv");
    
    //std::cout << "++++++++++++++++"<< std::endl;
    //std::cout << "++++++++++++++++"<< std::endl;

    std::map<std::string, std::vector<std::pair<std::string,int>>> ans; 
    std::vector<std::pair<std::string,int>> n1;
    n1.push_back({"NODE2",3});
    n1.push_back({"NODE16",1});
    ans.insert({"NODE1", n1});

    std::vector<std::pair<std::string,int>> n2;
    n2.push_back({"NODE4",2});
    n2.push_back({"NODE12",1});
    ans.insert({"NODE2", n2});

    std::vector<std::pair<std::string,int>> n3;
    n3.push_back({"NODE10",1});
    n3.push_back({"NODE20",1});
    ans.insert({"NODE3", n3});

    std::vector<std::pair<std::string,int>> n4;
    n4.push_back({"NODE8",1});
    ans.insert({"NODE4", n4});
    
    std::map<std::string, std::vector<std::pair<std::string,int>>> map = g.getGraph();
    /*for(std::map<std::string, std::vector<std::pair<std::string,int>>>::const_iterator it = map.begin(); it != map.end(); it++){
        std::cout << "Node: " << std::endl;
        std::cout << it->first << std::endl;
        std::cout << "Connects: " << std::endl;
        for(size_t a = 0; a < it->second.size(); a++){
            std::cout << it->second[a].first << " || Weight: " << it->second[a].second << std::endl; 
        }
    }
    std::cout << "====================================" << std::endl;
    for(std::map<std::string, std::vector<std::pair<std::string,int>>>::const_iterator it = ans.begin(); it != ans.end(); it++){
        std::cout << "Node: " << std::endl;
        std::cout << it->first << std::endl;
        std::cout << "Connects: " << std::endl;
        for(size_t a = 0; a < it->second.size(); a++){
            std::cout << it->second[a].first << " || Weight: " << it->second[a].second << std::endl; 
        }
    }*/
    REQUIRE(compareMap(map, ans));
}

TEST_CASE("most_visited_subreddit", "[case3]") {
    Graph g("../CS225-FINAL-PROJECT-FA22/tests/PLS - Sheet1.tsv");
    REQUIRE(g.MostVisited() == "NODE2");
}

TEST_CASE("ShortTestPath - Simple", "[case4]") {
    Graph g("../CS225-FINAL-PROJECT-FA22/tests/SHORTEST_PATH1_-_Sheet1.tsv");
    REQUIRE(g.shortPathLength("NODE1", "NODE8") == 2);
}

TEST_CASE("ShortTestPath - Same Node", "[case5]") {
    Graph g("../CS225-FINAL-PROJECT-FA22/tests/SHORTEST_PATH1_-_Sheet1.tsv");
    REQUIRE(g.shortPathLength("NODE1", "NODE1") == 0);
}

TEST_CASE("ShortTestPath - No Connection, Works With Direction", "[case6]") {
    Graph g("../CS225-FINAL-PROJECT-FA22/tests/SHORTEST_PATH1_-_Sheet1.tsv");
    REQUIRE(g.shortPathLength("NODE2", "NODE9") == INT_MAX);
}

TEST_CASE("ShortTestPath - HARD", "[case7]") {
    Graph g("../CS225-FINAL-PROJECT-FA22/tests/HARD_MANY_EDGES_-_Sheet1.tsv");
    REQUIRE(g.shortPathLength("NODE8", "NODE5") == 3);
}

TEST_CASE("ShortTestPath - Hard Disconnected", "[case8]") {
    Graph g("../CS225-FINAL-PROJECT-FA22/tests/HARD_DISCONNECTED_-_Sheet1.tsv");
    REQUIRE(g.shortPathLength("NODE11", "NODE20") == INT_MAX);
}






