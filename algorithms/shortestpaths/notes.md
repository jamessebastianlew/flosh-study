# dijkstras

at any point, extend the shortest path you have so far.

# bellman fords

the longest potential path goes through n nodes, which means
it takes n-1 edges. therefore if you go through every edge and
try to improve the distance each time, and you do this n-1 times,
you will find the minimum path.

if after n-1 runs you can still update the distances to new
minimums, then you have a negative weight cycle.

# floyd warshalls

consider taking intermediate node 'k'. if you take this node
check all the potential paths going from i through k to the
next edge. if you do this for all k then you know you will
have considered path i -> k1 -> k2 -> k3 .. -> j.
