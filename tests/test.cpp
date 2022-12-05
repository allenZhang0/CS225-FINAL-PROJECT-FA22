#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

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

TEST_CASE("ShortTestPath", "[case4]") {
    Graph g("../CS225-FINAL-PROJECT-FA22/tests/PLS - Sheet1.tsv");
    REQUIRE(g.MostVisited() == "NODE2");
}

/*TEST_CASE("Kosaraju Test 1", "[case 5]") {
    Graph g("../CS225-FINAL-PROJECT-FA22/tests/KOSARAJU's SIMPLE TEST - Sheet1 (1).tsv");
    std::vector<std::vector<std::string>> ans;

    std::vector<std::string> r1;
    r1.push_back("NODE3");
    ans.push_back(r1);

    std::vector<std::string> r2;
    r2.push_back("NODE4");
    ans.push_back(r2);

    std::vector<std::string> r3;
    r3.push_back("NODE2");
    ans.push_back(r3);

    std::vector<std::string> r4;
    r4.push_back("NODE1");
    ans.push_back(r3);

    std::vector<std::string> r5;
    r5.push_back("NODE0");
    ans.push_back(r5);
    
    std::vector<std::vector<std::string>> comp = g.getSCCs();
    REQUIRE(comp.size() == ans.size());
    for(size_t i = 0; i < ans.size(); i++){
        REQUIRE(comp[i].size() == ans[i].size());
        for(size_t j = 0; j < ans[i].size(); j++){
            REQUIRE(comp[i][j] == ans[i][j]);
        }
    }
}

TEST_CASE("Kosaraju Test 2", "[case6]") {
    Graph g("../CS225-FINAL-PROJECT-FA22/tests/KOSARAJU's SIMPLE TEST - Sheet1.tsv");
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> r1;
    r1.push_back("NODE0");
    r1.push_back("NODE1");
    r1.push_back("NODE2");
    ans.push_back(r1);
    std::vector<std::string> r2;
    r2.push_back("NODE3");
    ans.push_back(r2);
    std::vector<std::string> r3;
    r3.push_back("NODE4");
    ans.push_back(r3);
    std::vector<std::vector<std::string>> comp = g.getSCCs();
    REQUIRE(comp.size() == ans.size());
    for(size_t i = 0; i < ans.size(); i++){
        REQUIRE(comp[i].size() == ans[i].size());
        for(size_t j = 0; j < ans[i].size(); j++){
            REQUIRE(comp[i][j] == ans[i][j]);
        }
    }
}*/