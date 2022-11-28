#include "graph.h"
#include <string>
#include <iostream>
int main(){
    //graph construction
    //trim("/workspaces/CS 225/CS225/CS225-FINAL-PROJECT-FA22/lib/soc-redditHyperlinks-body.tsv");
    Graph g("/workspaces/CS225/CS225-FINAL-PROJECT-FA22/tests/PLS - Sheet1.tsv");
    std::string mv = g.MostVisited();
    std::cout << mv << std::endl;
    return 0;
}