#include "graph.h"
#include <string>
#include <iostream>
int main(){
    //graph construction
    /*
    Used the line of code below to trim our data set otherwise we wouldn't be able to upload our file to github
    */
    //trim("/workspaces/CS 225/CS225/CS225-FINAL-PROJECT-FA22/lib/soc-redditHyperlinks-body.tsv");
    //Graph g("../CS225-FINAL-PROJECT-FA22/tests/PLS - Sheet1.tsv");
    //Graph g("../CS225-FINAL-PROJECT-FA22/tests/KOSARAJU's SIMPLE TEST - Sheet1.tsv");
    //Graph g("./CS225-FINAL-PROJECT-FA22/lib/trimmed.tsv");
    //Graph g("/workspaces/CS 225/CS225/CS225-FINAL-PROJECT-FA22/lib/trimmed.tsv");
    Graph g("/workspaces/CS 225/CS225/CS225-FINAL-PROJECT-FA22/tests/KOSARAJU's SIMPLE TEST - Sheet1.tsv");
    /*
    std::string mv = g.MostVisited();
    std::cout << "Most Visited Node: " << mv << std::endl;
    int l = g.shortPathLength("NODE1", "NODE4");
    std::cout << "Shorttest path length == " << l << std::endl;
    */
    g.getSCCs();
    //g.graphPrinter();
    return 0;
}