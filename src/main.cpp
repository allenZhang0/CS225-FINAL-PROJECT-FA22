#include "graph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include <stdlib.h>

int main(){
    //graph construction
    /*
    Used the line of code below to trim our data set otherwise we wouldn't be able to upload our file to github
    */
    //trim("/workspaces/CS 225/CS225/CS225-FINAL-PROJECT-FA22/lib/soc-redditHyperlinks-body.tsv");
    std::cout << "\033[91m" <<"WELCOME TO CS225 FINAL PROJECT BY teamSOCK !!!" << std::endl;
    std::cout << "OUR PROJECT USES THE DATASET FROM https://snap.stanford.edu/data/soc-RedditHyperlinks.html \nTO ANALYZE CERTAIN CHARACTERISTICS" << std::endl;
    std::cout << "WE IMPLEMENTED BFS TO FIND THE MOST VISITED SUBREDDIT" << std::endl;
    std::cout << "DJIKSTRA'S ALGORITHM TO FIND THE SHORTEST PATH BETWEEN TWO SUBREDDITS" << std::endl;
    std::cout << "AND KOSARAJU'S ALGORITHM TO FIND THE SUBREDDITS THAT ARE THE MOST STRONGLY CONNECTED" << std::endl;
    Graph g("../CS225-FINAL-PROJECT-FA22/lib/trimmed.tsv");
    std::map<std::string, std::vector<std::pair<std::string,int>>> graph = g.getGraph();
    bool runner = true;
    do{
        std::cout << "\033[32m" <<"TYPE 1 FOR MOST VISITED" << std::endl;
        std::cout << "TYPE 2 FOR SHORTEST PATH BETWEEN TWO SUBREDDITS" << std::endl;
        std::cout << "TYPE 3 FOR STRONGLY CONNECTED COMPONENTS" << std::endl;
        int algochoice = 0;
        std::vector<int> workaround = {1,2,3};
        std::vector<int>::iterator it;
        do{
            std::cin >> algochoice;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            it = std::find(workaround.begin(), workaround.end(), algochoice);
            if(it == workaround.end()){
                std::cerr << "\033[31m" << "Enter a valid choice" << std::endl;
            }
        }while(it == workaround.end());
        if(algochoice == 1){
            std::string mostvisted = g.MostVisited();
            std::cout << "\033[36m" << "THE MOST VISITED SUBREDDIT IS: " << mostvisted <<std::endl; 
        }else if(algochoice == 2){
            std::string origin = "godeater";
            std::cout << "\033[34m" << "ENTER A START SUBREDDIT" << std::endl;
            std::map<std::string, std::vector<std::pair<std::string,int>>>::const_iterator mit;
            do{
                std::cin >> origin;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    origin = "godeater";
                }
                mit = graph.find(origin);
                if(mit == graph.end()){
                    std::cerr << "\033[31m" << "Enter a valid subreddit / Subreddit not present in dataset" << std::endl;
                }
            }while(mit == graph.end());
            std::string dest = "godeater";
            std::cout << "\033[34m" << "ENTER A END SUBREDDIT" << std::endl;
            std::map<std::string, std::vector<std::pair<std::string,int>>>::const_iterator diss;
            do{
                std::cin >> dest;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                diss = graph.find(dest);
                if(diss == graph.end()){
                    std::cerr << "\033[31m" << "Enter a valid subreddit / Subreddit not present in dataset" << std::endl;
                }
            }while(diss == graph.end());
            int shortpath = g.shortPathLength(origin, dest);
            std::cout << "\033[33m" << "THE SHORTEST PATH BETWEEN " << origin << " AND " << dest << " IS: " << shortpath << std::endl;
        }else if(algochoice == 3){
            std::cout << "\033[93m" << "THE STRONGLY CONNECTED COMPONENTS ARE: " << std::endl;
            std::vector<std::vector<std::string>> sccs = g.getSCCs();
            for(size_t i = 0; i < sccs.size(); i++){
                for(size_t j = 0; j < sccs[i].size(); j++){
                    std::cout << "\033[93m" << sccs[i][j] << " ";
                }
                std::cout << std::endl;
            } 
        }
        std::string yesorno;
        std::cout << "\033[95m" << "WOULD YOU LIKE TO CONTINUE (y or n)" << std::endl;
        std::vector<std::string> wa = {"y","n"};
        std::vector<std::string>::iterator cit;
        do{
            std::cin >> yesorno;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cit = std::find(wa.begin(), wa.end(), yesorno);
            if(cit == wa.end()){
                std::cerr << "\033[31m" << "Enter a valid choice" << std::endl;
            }
        }while(cit == wa.end());
        if(yesorno == "n"){
            runner = false;
        }
        std::cout << "\033[0m" << std::endl;
    }while(runner);
    //Graph g("../CS225-FINAL-PROJECT-FA22/tests/PLS - Sheet1.tsv");
    //Graph g("../CS225-FINAL-PROJECT-FA22/tests/KOSARAJU's SIMPLE TEST - Sheet1.tsv");
    //Graph g("./CS225-FINAL-PROJECT-FA22/lib/trimmed.tsv");
    //Graph g("/workspaces/CS 225/CS225/CS225-FINAL-PROJECT-FA22/lib/trimmed.tsv");
    return 0;
}