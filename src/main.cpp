#include "graph.h"
#include <string>
#include <iostream>

int main(){
    //graph construction
    Graph g("/workspaces/CS225/CS225-FINAL-PROJECT-FA22/soc-redditHyperlinks-body.tsv");
    //hehehehhehe BFS bitches
    std::string mv = g.MostVisited();
    std::cout << mv << std::endl;
    return 0;
}