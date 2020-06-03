# proof

notice that the reason this works is that every time you do
an update query, something nice happens, which is, you may
merge multiple values greater than 'x' into one value 'x'.
in other words, the number of unique values may decrease.

in other words, if we have a-i unique values in the subtree
of some node, then when we do our minimum query, we will
either end up changing:

A. nothing in all our children if 'x' is greater than the max, 
this will not change the number of unique values.
B. or we will end up change exactly one of our children, which
also will not change the number of unique values in the subtree.
C. we will change more than one of our children, which will decrease
the number of unique values.

whats good is we can do A and B in quick time if we store the max
and second max in each node, however, C will require us recursively
changing the children.

the good thing is every time we recursively change our children, we
decrease the number of unique values of our range by at least 1.

now see that if we recurse, we will change the number of unique
elements in our range for that subtree, and then perhaps we could
recurse down our children and decrease theirs. so what we need to
know to find out how many times this process might happen is, for
each node, what is the sum of the unique values that we could have
accumulated throughout the queries.

at the beginning the sum of all the unique values for each range
(note overlapping ranges would count as well because our recurse
could also go to children). we would have nlogn sum max at the
beginning (if all elements were unique) and for each query, we can
only increase the number of unique elements if we are changing
values on the edge. for example:
5 5 -> 2 5, will decrease the number of unique elements.
if we do this we will change the number of unique elements for
all its parents too.

so each query gets at most +log n unique elements.

so in total, the sum of the number of uniuq elements we could
possible have had the entire time is at most n log n + q log n.

if we decrease the number of unique elements by one each time
we do our extra recurse, then the most we could subtract is
n log n + q log n, because otherwise we would have less than or
equal to zero unique values??? which would be impossible.

we can leverage this idea by only ever updating the nodes
down the segment tree if we are guaranteed to merge more than
one node, meaning the number of unique values must decrease.

