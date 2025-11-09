# Question

1. Dijkstra’s algorithm fails on negative weights due to its strategy where, if a node’s shortest path is already found, it assumes that that is permanent and cannot be changed. A negative edge, however, can create a shorter path after the vertex has been visited, but by then it is too late, as the algorithm has already assumed the path to be completed.
