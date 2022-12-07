## Leading Question 
Just like how a country has many cities and many roads and one may wonder how to reach each city just once from a single starting point, our leading question is a morphing of this problem using the world of reddit data where reddit.com itself is a mirror to a country and its many subreddits are its cities. We want to analyze which subreddits are the most popular in terms of most incoming hyperlinks from other cities, i.e. the city with most incoming roads must be very popular.

Further subquestions can be related to how can we traverse the reddit landscape in a way that we can reach every possible subreddit or we can reach the most subreddits via hyperlinks to other ones. Or we could analyze which communities of subreddits are the most closely knit with each subreddit posting hyperlinks to the other back and forth. The possibilities are only bounded by our time limitation and imagination. We will stick to analyzing which subreddits are most popular and which clusters (categories) of subreddits are the face of reddit activity. 
Algorithms we plan to use:
Kosaraju's algorithm / Tarjan's strongly connected component algorithm to find strongly connected components which represent the most tightly knit communities.
BFS to traverse each node and populate a dictionary of subreddits and their incoming and outgoing hyperlinks. (This data can further be used in PageRank Algorithm to compute the importance of each node and then rank them in the end?)
Dijkstra's to compute shortest path from one subreddit to another. 
## Dataset Acquisition
Reddit subreddits mutual hyperlink dataset from Stanford's SNAP dataset. 
(https://snap.stanford.edu/data/soc-RedditHyperlinks.html)
## Data Format

We've acquired this dataset from Stanford's SNAP database, the input format is a TSV file that has the following fields:

    Source subreddit
    
    Target subreddit
    
    Post_ID_timestamp
    
    Link Sentiment
    
    Properties
    
Realistically, we only need the source and target subreddits because we are purely analyzing the importance of subreddits, how to get to each subreddit via shortest path, and also which communities of subreddits are the most tightly knit. 

## Data Correction
In a paragraph or two, you should describe how will you parse the input data and what checks are you doing to ensure the input data is error-free. At minimum this should dicuss how you will check for missing entries and how will you correct such instances when you find them. Depending on the dataset, it is also reasonable to check for values that are not physically possible or values which are statistical outliers. Note: These are just suggestions -- you may have many other ideas for how to find and correct problems in your dataset

Since the input is a TSV file, we can just parse using split by tab on each line of the file and we will only take in the input and target subreddits, all other fields will be disregarded. For missing entries, we can detect them in place and we will just throw away this line of information because if it's missing a source or target subreddit, then it's useless for our analysis. These 'dead' or 'isolated' subreddits add nothing to our analysis. 


## Data Storage

We are planning to store the graph inside an adjacency list because we are assuming that most subreddits will not have outoging links to all other subreddits, therefore an adjacency matrix would take up too much memory for storing a bunch of no connections. This list will store the number of incoming links from and outgoing links to each unique subreddit. This will take up O(V+E) space. 

## Algorithm 
Function inputs:
We need to first parse the input for source and target subreddits and then insert the correct information into the adjacency list. This will be the base input for all of our graph algorithms.

##### Kosaraju's:
Input will be the graph itself via adjancency list. 

Output will be the vector of vectors of strongly connected communities.

Function runtime: Since we are using an adjancency list, Kosaraju runs two traversals and will finish in O(V+E) time. 
We will use a vector of vectors to store the names of nodes of strongly connected components. This will take O(V^2)

#### BFS: 
Input: this will be performed on the graph via adjacency list. 

Output: this will be a pure traversal, and will populate a dictionary, but it will not return anything. 

Runtime: This will be limited by the number of nodes which is V, therefore the runtime is O(V)

We will use a queue to store the nodes of the BFS traversal. This will use up O(V) space. 
We then are planning on storing a dictionary which will hold the subreddit and then a pair of the toal incoming and outgoing links in order to compute which ones are the most 'important'. This will take O(V+E) space.

#### Dijkstra's:
Input: this will be performed on graph via adjancency list. 

Output: this will populate the p and d vectors and then we can access the shortest path by indexing the path vector. 

Runtime: This will run in O(Vlog(V) + E).

We will use 2 more vectors to store the cost and predecessor for Dijkstra's.

## Timeline

Week 1: During the first week, we will be primarily focusing on finishing the implementation/creation of our graph.
Week 2: We will implement BFS/dijkstra's algorithm and finish testing both algorithms on our finalized graph.
Week 3: In addition to the 2 mentioned prior, we will now implement Kosaraju's algorithm and finalize with tests.
Week 4: Finalize project and make revisions to implementation if necessary.
