#pragma once

#include <vector>
#include <string>
#include <map>
#include <unordered_map>

class Graph{
public:
    /*
    Constructor 
    @param filename, required to construct graph using the given files. 
    */
    Graph(std::string filename);
    //There are disconnected components lol so need this
    std::string MostVisited();
    /*
    BFS algorithm:
    Will population a dictionary that tells how many other nodes point to this specific node.
    */
    void BFS(std::map<std::string, bool>& visited, std::string start);

    /*
    */
    void Djikstras();


private:
    // first string is the node name
    // vector will contain a string of all connections that the node has. 
    std::map<std::string, std::vector<std::string>> graph_;
    // contains the name of a node, and the amount of connections it has. 
    std::unordered_map<std::string, int> links_;
    //Just testing for number of links
    int total = 0;
};