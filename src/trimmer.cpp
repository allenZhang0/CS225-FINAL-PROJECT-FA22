#include "trimmer.h"

void trim(std::string filename) {
    std::ifstream in;
    std::ofstream out;
    in.open(filename);
    out.open("/workspaces/CS 225/CS225/CS225-FINAL-PROJECT-FA22/lib/trimmed.tsv");
    std::string line;
    int coin; 
    while (getline(in, line)) {
        coin = rand() % 4;
        if (coin == 1) {
            out << line << std::endl;
        }
    }
    in.close();
    out.close();
}