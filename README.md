# CS225 Final Project FA22: Reddit Community Connections


## [Presentation Video](https://www.youtube.com/watch?v=U_kN8syVgV8](https://www.youtube.com/watch?v=yPSVZlV5hLI)

## Data

We used the [Reddit Hyperlink Network](https://snap.stanford.edu/data/soc-RedditHyperlinks.html) data set. The data set that we used is [this](https://snap.stanford.edu/data/soc-redditHyperlinks-body.tsv).

## Repo Stucture

The [`/src`](https://github.com/allenZhang0/CS225-FINAL-PROJECT-FA22/tree/main/src) folder contains the code that we used to make our graph along with the algorithms that we used. 

The [`/tests`](https://github.com/allenZhang0/CS225-FINAL-PROJECT-FA22/tree/main/tests) folder contains the datasets that we used to test along with the `tests.cpp` and `catch.hpp` which are the files that we used to test our files. We also store image representations of our test cases in this folder.

The [`/lib`](https://github.com/allenZhang0/CS225-FINAL-PROJECT-FA22/tree/main/lib) folder contains the `trimmed.tsv` which is the zip file for our dataset, to use this project the user must unzip the file and make sure that it is in the correct directly for our `main.cpp` to work. This folder also contains the output file `SCC_output.csv` of the Kosaraju's algorithm which stores all the strongly connected compenents with more than (>) 1 subreddit.

The [`/docs`](https://github.com/allenZhang0/CS225-FINAL-PROJECT-FA22/tree/main/docs) folder contains the `results.md`, `team_contract.txt`, and `project_proposal.txt`. 


## Setup

To run our repository on your own machine, one must first have the environment for UIUC CS225 setup, if you do not have it set up, follow the instructions from [This Guide](https://courses.engr.illinois.edu/cs225/fa2022/resources/own-machine/).

### Execution
Before trying to run our main, the user must unzip the file `.../CS225-FINAL-PROJECT-FA22/lib/soc-redditHyperlinks-body.tsv.zip`. Make sure that the file is inside the the [`/lib`](https://github.com/allenZhang0/CS225-FINAL-PROJECT-FA22/tree/main/lib) folder, and not in a folder inside the [`/lib`](https://github.com/allenZhang0/CS225-FINAL-PROJECT-FA22/tree/main/lib) folder, the file must directly be inide the [`/lib`](https://github.com/allenZhang0/CS225-FINAL-PROJECT-FA22/tree/main/lib) folder.

To run out code make sure that you are in `.../CS225-FINAL-PROJECT-FA22` folder, and the type in `make` in the command prompt compile and execute the code.

## Code Functionality and Runtimes
To be implemented lol...

## Testing
To run our test cases is similar to running our main. Make sure that you are in `.../CS225-FINAL-PROJECT-FA22` folder, and the type in `make tests` in the command prompt to compile and execute the code.

## Team:

### In order of least to most work

Phillip X.
Brian K.
Allen Z. 
Siddant Y.

### Mentor:

Gabriella X.
