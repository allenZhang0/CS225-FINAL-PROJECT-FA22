## Leading Question:
After fully implementing Dijkstra’s, Kosaraju’s, and BFS with an adjacency list into our finalized project, teamSOCK was able to accomplish the following task of analyzing which subreddits are most popular in terms of most incoming hyperlinks from other subreddits. 

In total, the game which we have created allows users to choose from three options: “1. Most Visited,” “2. Shortest Path Between Two Subreddits,” and “3. Strongly Connected Components.” Clicking option 1, our BFS algorithm will traverse our adjacency list until a subreddit with the most incoming hyperlinks is found. If option 2 is selected, Dijkstra's Algorithm will be able to successfully relay the shortest number of “clicks” necessary to navigate from one subreddit to another. And as an additional feature, option 3 outputs a llist of all subreddits in their corresponding “strongly connected” groups/communities. This feature was made possible by our Kosaraju implementation.

Having tested our project multiple times, our group was able to verify previous assumptions as well as make some interesting discoveries. To start, we were able to confirm askReddit as the “Most Visited” subreddit with the most incoming hyperlinks. This was quite unsurprising due to it being the 3rd most active subreddit worldwide. What did surprise our group the most was the many bizarre connections that could be made from one link to another. Even the most bizarre origin to destination subreddit combinations did not exceed 5 edges.


## Dijkstras: 

Dijkstra’s Algorithm was necessary in the completion of our project due to our desire to relay the minimum distance between two subreddits. As for inputs, we have an “origin” subreddit and a “destination” subreddit. Using a map data structure, we store each possible vertex and its distance to the origin. Next, we implemented a priority queue to store the correct order in which we want to access the element. And with each iteration, we were able to minimize the possible distances between the subreddits until we reached a finite minimum. Our algorithm has a runtime of O(S + Hlog(S)) with S representing subreddits and H representing hyperlinks. We created several test case suites to test for the accuracy of our algorithm.

## BFS: 

Breadth first search was used as a helper function in our project to populate the links (private variable) map which stores the subreddit as a string and the number of subreddits that point to it as an integer. This data is later accessed in our most visited function where we iterate through the map to find the most visited subreddit. The runtime for the BFS function is O(S + H) due to the fact that we use an adjacency linked list representation for our graph. We created several test case suites to test for the accuracy of our algorithm.


## Kosaraju:

Our Kosaraju’s Algorithm prints out a list of the strongly connected subReddits by taking in our graph representation running an initial DFS traversal to populate the stack, and finally run a DFS traversal for each subReddit that hasn’t been visited on the transpose of the graph representation. The initial DFS traversal is performed by fillOrder on graph_. To find each SCC the DFS function was performed on transpose_ until it runs out of connected nonvisited subReddits. At the end, we ran a set of comprehensive test cases which matched the solutions that we calculated by hand. Our algorithm also has a runtime of O(S + H) with S representing subreddits and H representing hyperlinks.
