#pragma once

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
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
    Returns the length of the shortest path
    @param std::string orign -> origin of path
    @param std::string destination -> end of path 
    */
    int shortPathLength(std::string origin, std::string dest);
    /*
    Djikstra's algorithm, acts as a helper function to find distance between origin and destination
    @param std::string origin is the subreddit to which you want to find the ditance from
    */
    std::map<std::string, int> Djikstras(std::string origin);
    /*
    Getter for the graph;
    */
    std::map<std::string, std::vector<std::pair<std::string,int>>> getGraph();
    /*
    Standard DFS 
    */
    void DFS(std::string start, std::map<std::string, bool> &visited);
    
    /*
    */
    void fillOrder(std::string start, std::map<std::string, bool> &visited, std::stack<std::string> &s);
    
    /*
    Kosaraju's Algorith to find the strongly connected components in the graph;
    */
    std::vector<std::vector<std::string>> getSCCs();
    
    /*
    NOT USED
    */
    std::map<std::string, std::vector<std::pair<std::string,int>>> getTranspose(); 
    
    /*
    Print a graph 
    */
    void graphPrinter();

    /*
    Getter for links for utlity;
    */
   std::map<std::string, int> getLinks();

private:
    // first string is the node name
    // vector will contain a string of all connections that the node has. 
    std::map<std::string, std::vector<std::pair<std::string, int>>> graph_;
    
    // contains the name of a node, and the amount of connections it has. 
    std::map<std::string, int> links_;
    
    //Just testing for number of links
    int total = 0;

    //set for easiness
    std::set<std::string> nodes;

    //map of transponse graph
    std::map<std::string, std::vector<std::pair<std::string, int>>> transpose_;

    //Used to store Strongly connected components separtely
    std::vector<std::string> tempres;

    //ALL strongly connected components 
    std::vector<std::vector<std::string>> SCCs;
};