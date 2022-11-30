
#include "graph.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>

void Graph::DFS(std::string start, std::map<std::string, bool> &visited) {
    visited[start] = true; 
    std::cout << start << " ";
    std::vector<std::pair<std::string, int>>::iterator it; 
    for (it = transpose_[start].begin(); it != transpose_[start].end(); it++) {
        if (!visited[it->first]) {
            DFS(it->first, visited);
        }
    }
}
void Graph::fillOrder(std::string start, std::map<std::string, bool> &visited, std::stack<std::string> &s) {
    visited[start] = true;
    std::vector<std::pair<std::string, int>>::iterator it; 
    for (it = graph_[start].begin(); it != graph_[start].end(); it++) {
        if (!visited[it->first]) {
            fillOrder(it->first, visited, s);
        }
    }
    s.push(start);
}

void Graph::getSCCs() {
    std::stack<std::string> st;
    std::map<std::string, bool> visitedG;
    std::map<std::string, bool> visitedT;
    for(std::set<std::string>::const_iterator it = nodes.begin(); it != nodes.end(); it++){
        visitedG.insert({*it, false});
        visitedT.insert({*it, false});
    }
    
    for(std::map<std::string, std::vector<std::pair<std::string,int>>>::const_iterator it = graph_.begin(); it != graph_.end(); it++){
        if (visitedG[it->first] == false) {
            fillOrder(it->first, visitedG, st);
        }
    }
    while (!st.empty()) {
        std::string top = st.top(); 
        st.pop(); 

        if (visitedT[top] == false) {
            DFS(top, visitedT);
            std::cout << std::endl;
        }
    }

}


