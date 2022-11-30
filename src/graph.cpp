#include "graph.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>

Graph::Graph(std::string filename){
    std::ifstream File;
    File.open(filename);
    std::string line;
    while(getline(File, line)){
        line.erase(std::remove(line.begin(), line.end(),' '),line.end());
        std::vector<std::string> parts;
        int startpos = 0;
        int endpos = 0;
        for(size_t i = 0; i < line.length(); i++){
            if(line[i] == '\t'){
                endpos = i;
                parts.push_back(line.substr(startpos, endpos-startpos));
                startpos = endpos+1;
            }
        }
        parts.push_back(line.substr(startpos, line.length()-startpos));
        //std::cout << line.substr(startpos, line.length()-startpos) << std::endl;
        //std::cout << parts[0] << " -> " << parts[1] << std::endl;
        nodes.insert(parts[0]);
        nodes.insert(parts[1]);

        auto it = graph_.find(parts[0]);
        if(it == graph_.end()){
            std::vector<std::pair<std::string,int>> adj;
            adj.push_back({parts[1],1});
            //std::cout << "adj" << adj[0].first << std::endl;
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
    /*for(std::map<std::string, std::vector<std::pair<std::string,int>>>::const_iterator it = graph_.begin(); it != graph_.end(); it++){
        std::cout << "Node: " << std::endl;
        std::cout << it->first << std::endl;
        std::cout << "Connects: " << std::endl;
        for(size_t a = 0; a < it->second.size(); a++){
            std::cout << it->second[a].first << " || Weight: " << it->second[a].second << std::endl; 
        }
    }*/
    /*
    std::cout << "GRAPH SIZE =====" << graph_.size() << std::endl;
    std::cout << "TRANsPOSE SIZE ======" << transpose_.size() << std::endl;
    */

}

std::string Graph::MostVisited(){
    std::map<std::string, bool> visited;
    for(std::map<std::string, std::vector<std::pair<std::string,int>>>::const_iterator it = graph_.begin(); it != graph_.end(); it++){
        visited.insert({it->first, false});
    }
    for(std::map<std::string, bool>::const_iterator it = visited.begin(); it != visited.end(); it++){
        if(it->second == false){
            BFS(visited, it->first);
        }
    }
    
    //std::cout << "Total: " << total << std::endl;

    std::string most_visited;
    int max = -1;

    for(std::unordered_map<std::string, int>::const_iterator it = links_.begin(); it != links_.end(); it++){
        if(it->second > max){
            most_visited = it->first;
            max = it->second;
        }
    }
    return most_visited;
}


void Graph::BFS(std::map<std::string, bool>& visited, std::string start){
    std::queue<std::string> q;
    q.push(start);
    int f = 0;
    while(!q.empty()){
        std::string curr_subreddit = q.front();
        q.pop();
        if(!visited[curr_subreddit]){
            //f++;
            visited[curr_subreddit] = true;
            for(size_t i = 0; i < graph_[curr_subreddit].size(); i++){
                q.push(graph_[curr_subreddit][i].first);
                auto findnum = links_.find(graph_[curr_subreddit][i].first);
                if(findnum == links_.end()){
                    links_.insert({graph_[curr_subreddit][i].first, 0});
                }
                links_[graph_[curr_subreddit][i].first] += graph_[curr_subreddit][i].second;
                f += graph_[curr_subreddit][i].second;
            }
        }
    }
    //std::cout << "Count: " << f << std::endl;
    total += f;
    //std::cout << uniques.size();
}

std::map<std::string, std::vector<std::pair<std::string,int>>> Graph::getGraph() {
    return graph_;
}
int Graph::shortPathLength(std::string origin, std::string dest){
    //std::cout << "+++++++DJMAN++++++++" << std::endl;
    std::map<std::string, int> dist = Djikstras(origin);
    return dist[dest];
}
std::map<std::string, int> Graph::Djikstras(std::string origin){
    std::map<std::string, int> distance;
    for(std::map<std::string, std::vector<std::pair<std::string,int>>>::const_iterator it = graph_.begin(); it != graph_.end(); it++){
        distance.insert({it->first, INT_MAX});
    }
    std::priority_queue<std::pair<std::string,int>, std::vector<std::pair<std::string,int>>, std::greater<std::pair<std::string,int>>> djman;
    djman.push(std::make_pair(origin, 0));
    distance[origin] = 0;
    while(!djman.empty()){
        std::string incoming = djman.top().first;
        //std::cout << "Node" << std::endl;
        //std::cout << incoming << std::endl;
        djman.pop();
        //std::cout << "Adjacency" << std::endl;
        for(size_t i = 0; i < graph_[incoming].size(); i++){
            std::string manipulate = graph_[incoming][i].first;
            //std::cout << manipulate << std::endl;
            int weight = 1;
            if(distance[manipulate] > distance[incoming] + weight){
                distance[manipulate] = distance[incoming] + weight;
                djman.push(std::make_pair(manipulate, distance[manipulate]));
            }
        }
    }
    return distance;
}



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
void Graph::getSCCs() {
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
            std::cout << std::endl;
        }
    }
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

