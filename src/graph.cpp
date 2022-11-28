#include "graph.h"
#include <fstream>
#include <iostream>
#include <queue>

Graph::Graph(std::string filename){
    std::ifstream File;
    File.open(filename);
    std::string line;
    while(getline(File, line)){
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
        //std::cout << parts[0] << " -> " << parts[1] << std::endl; 
        auto it = graph_.find(parts[0]);
        if(it == graph_.end()){
            std::vector<std::string> adj;
            adj.push_back(parts[1]);
            graph_.insert({parts[0], adj});
        }else{
            it->second.push_back(parts[1]);
        }
    }
    File.close();
    for(std::map<std::string, std::vector<std::string>>::const_iterator it = graph_.begin(); it != graph_.end(); it++){
        std::cout << "Node: " << std::endl;
        std::cout << it->first << std::endl;
        std::cout << "Connects: " << std::endl;
        for(size_t a = 0; a < it->second.size(); a++){
            std::cout << it->second[a] << std::endl; 
        }
    }
}

std::string Graph::MostVisited(){
    std::map<std::string, bool> visited;
    for(std::map<std::string, std::vector<std::string>>::const_iterator it = graph_.begin(); it != graph_.end(); it++){
        visited.insert({it->first, false});
    }
    for(std::map<std::string, bool>::const_iterator it = visited.begin(); it != visited.end(); it++){
        if(it->second == false){
            BFS(visited, it->first);
        }
    }
    std::cout << "Total: " << total << std::endl;

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
                q.push(graph_[curr_subreddit][i]);
            }
            links_.insert({curr_subreddit, 1});
        }else{
            links_[curr_subreddit]++;
        }
        f++;
    }
    std::cout << "Count: " << f << std::endl;
    total += f;
}

std::map<std::string, std::vector<std::string>> Graph::getGraph() {
    return graph_;
}
