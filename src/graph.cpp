#include "graph.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>

Graph::Graph(std::string filename){
    //Code for data parsing 
    std::ifstream File;
    File.open(filename);
    std::string line;
    while(getline(File, line)){
        line.erase(std::remove(line.begin(), line.end(),' '),line.end()); // get rid of spaces
        std::vector<std::string> parts;
        int startpos = 0;
        int endpos = 0;
        for(size_t i = 0; i < line.length(); i++){
            if(line[i] == '\t'){ // tab delimited so search for character
                endpos = i;
                parts.push_back(line.substr(startpos, endpos-startpos));
                startpos = endpos+1;
            }
        }
        parts.push_back(line.substr(startpos, line.length()-startpos));
        
        nodes.insert(parts[0]);
        nodes.insert(parts[1]);
        //for population of the normal graph
        auto it = graph_.find(parts[0]);
        if(it == graph_.end()){
            std::vector<std::pair<std::string,int>> adj;
            adj.push_back({parts[1],1});
            graph_.insert({parts[0], adj});
        }else{
            bool found = false;
            for(size_t l = 0; l < it->second.size(); l++){
                if(it->second[l].first == parts[1]){
                    found = true;
                    it->second[l].second++;
                }
            }if(!found){
                std::pair<std::string, int> b = {parts[1],1};
                it->second.push_back(b);
            }
        }
        //for population of the transpose graph for kosarajus
        auto it2 = transpose_.find(parts[1]);
        if (it2 == transpose_.end()) { // if not found, make a new entry
            std::vector<std::pair<std::string,int>> adj;
            adj.push_back({parts[0], 1});
            transpose_.insert({parts[1], adj});
        } else { // if found, then check if the node is already pushed into the vector
            bool found = false;
            for(size_t l = 0; l < it2->second.size(); l++){
                if(it2->second[l].first == parts[0]){
                    found = true;
                    it2->second[l].second++;
                }
            }if(!found){
                std::pair<std::string, int> b = {parts[0],1};
                it2->second.push_back(b);
            }
        }
        
    }
    File.close();
    std::string useless = MostVisited();
    useless = useless + "+";
}

std::string Graph::MostVisited(){
    //populate visited map
    std::map<std::string, bool> visited;
    for(std::map<std::string, std::vector<std::pair<std::string,int>>>::const_iterator it = graph_.begin(); it != graph_.end(); it++){
        visited.insert({it->first, false});
    }
    //ensure that all nodes are visited even isolated ones
    for(std::map<std::string, bool>::const_iterator it = visited.begin(); it != visited.end(); it++){
        if(it->second == false){
            BFS(visited, it->first); // BFS Lmao
        }
    }
    //Find the subreddit with most incoming links with BFS
    std::string most_visited;
    int max = -1;
    for(std::map<std::string, int>::iterator it = links_.begin(); it != links_.end(); it++){
        if(it->second > max){
            most_visited = it->first;
            max = it->second;
        }
    }
    //Will always be the same string
    return most_visited;
}


void Graph::BFS(std::map<std::string, bool>& visited, std::string start){
    //basic bfs
    std::queue<std::string> q;
    q.push(start);
    int f = 0; // testing variable for total verticies
    while(!q.empty()){
        std::string curr_subreddit = q.front();
        q.pop();
        if(!visited[curr_subreddit]){
            visited[curr_subreddit] = true;
            for(size_t i = 0; i < graph_[curr_subreddit].size(); i++){
                q.push(graph_[curr_subreddit][i].first);
                auto findnum = links_.find(graph_[curr_subreddit][i].first);
                if(findnum == links_.end()){
                    links_.insert({graph_[curr_subreddit][i].first, 0});
                }
                links_[graph_[curr_subreddit][i].first] += graph_[curr_subreddit][i].second;
                f += graph_[curr_subreddit][i].second; // weights represent # of connections
            }
        }
    }
    total += f; // Dummy variable possible uses for own implementation
}

std::map<std::string, std::vector<std::pair<std::string,int>>> Graph::getGraph() {
    //WOOOO Getters
    return graph_;
}
int Graph::shortPathLength(std::string origin, std::string dest){
    //Given orign and destination will find the shortest path linking the two
    //if INT_MAX should return -1 + print no connection 
    std::map<std::string, int> dist = Djikstras(origin);
    return dist[dest];
}
std::map<std::string, int> Graph::Djikstras(std::string origin){
    //Map population
    std::map<std::string, int> distance;
    for(std::map<std::string, std::vector<std::pair<std::string,int>>>::const_iterator it = graph_.begin(); it != graph_.end(); it++){
        distance.insert({it->first, INT_MAX});
    }
    //priority q
    std::priority_queue<std::pair<std::string,int>, std::vector<std::pair<std::string,int>>, std::greater<std::pair<std::string,int>>> djman;
    djman.push(std::make_pair(origin, 0));
    distance[origin] = 0;
    while(!djman.empty()){
        std::string incoming = djman.top().first;
        djman.pop();
        for(size_t i = 0; i < graph_[incoming].size(); i++){
            std::string manipulate = graph_[incoming][i].first;
            int weight = 1;
            if(distance[manipulate] > distance[incoming] + weight){
                distance[manipulate] = distance[incoming] + weight;
                djman.push(std::make_pair(manipulate, distance[manipulate]));
            }
            //djman
        }
    }
    return distance;
}



void Graph::DFS(std::string start, std::map<std::string, bool> &visited) {
    visited[start] = true; 
    std::cout << start << " ";
    tempres.push_back(start);
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
/*
std::map<std::string, std::vector<std::pair<std::string,int>>> Graph::getTranspose() {
    std::map<std::string, std::vector<std::pair<std::string,int>>> t; 
    std::map<std::string, std::vector<std::pair<std::string,int>>>::iterator i; 
    for (i = graph_.begin(); i != graph_.end(); i++) {
        std::vector<std::pair<std::string, int>>::iterator it; 
        for (it = i->second.begin(); it != i->second.end(); it++) {
            t[it->first].push_back({i->first, 0});
        }
    }
    return t; 
}
*/
std::vector<std::vector<std::string>> Graph::getSCCs() {
    std::stack<std::string> st;
    std::map<std::string, bool> visitedG;
    std::map<std::string, bool> visitedT;
    for(std::set<std::string>::const_iterator it = nodes.begin(); it != nodes.end(); it++){
        visitedG.insert({*it, false});
        visitedT.insert({*it, false});
    }
    for (std::map<std::string, bool>::iterator it = visitedG.begin(); it != visitedG.end(); it++) {
        if (it->second == false) {
            fillOrder(it->first, visitedG, st);
        }
    }
    while (!st.empty()) {
        std::string top = st.top(); 
        st.pop(); 

        if (visitedT[top] == false) {
            DFS(top, visitedT);
            SCCs.push_back(tempres);
            tempres.clear();
            std::cout << std::endl;
        }
    }
    return SCCs;
}

void Graph::graphPrinter() {
    for (auto it = graph_.begin(); it != graph_.end(); it++) {
        std::cout << it->first << " connects to ";
        for (auto i = it->second.begin(); i != it->second.end(); i++) {
            std::cout << i->first << " "; 
        }
        std::cout << std::endl;
    }
}

std::map<std::string, int> Graph::getLinks(){
    return links_;
}


