# greedy choice property

notice that if you have some cut (S, V-S), a minimum spanning tree
must have at least one edge crossing that cut, otherwise the graph
will be disconnected.

let's say we have a minimum spanning tree T\* which does not contain
the minimum edge E={u,v} which crosses this cut. if we remove some
edge E' from the crossing edges which is in T\* that is along the
unique path (since T\* is a tree) from u to v, notice that since
there was previously only one unique path from u to v, u has no
connection to v. however if we now take edge E={u,v}, we get a new
graph where u and v are connected, lets call this T':

weight(T') = weight(T\*) - weight(E') + weight(E)

notice T' is a spanning tree, because it has n-1 edges and n vertices
and it also is a connected graph, since we rejoined that path that joins
u and v, therefore all the parts that u' was connected to  via a path u'
to v', are now achieveable via the path u' to u, u to v and v to v'.

this means T' is a spanning tree, but also notice that since E is the
crossing edge with minimum weight:

weight(E) <= weight(E')

therefore:

weight(T') = weight(T\*) - weight(E') + weight(E)
weight(T') <= weight(T\*) - wegiht(E') + weight(E')
weight(T') <= weight(T\*)

therefore since T\* was a MST, and the weight of T' is less than or equal
to T\*, T' is also an MST.

this concludes the proof (via cut and paste technique)
