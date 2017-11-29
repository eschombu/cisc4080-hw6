# [CISC 4080: Algorithms](http://www.dsm.fordham.edu/~eschomburg/algorithms/)

## Homework 6 (check back for updates)
**Problems 1 & 2 due Wednesday, November 22**
**Problems 3 & 4 due Wednesday, November 29**
        
1.  The following files contain an implementation, and some testing
    code, of a binary heap for use as a min-priority queue. You
    must complete the implementation of the class in the header
    file (`bin_heap.h`), which you will use in follow-up
    questions. If you compile the `bin_heap.cpp` file
    run the resulting executable, it will allow you to test the
    heap by manually entering new elements (as value and key pairs)
    and observing the resulting heap as it repeatedly pops its min-
    key values.

    *   [`bin_heap.h`](bin_heap.h)
    *   [`bin_heap.cpp`](bin_heap.cpp)

1.  The following files contain C++ code and a text file with
    interstate highway route distances between cities across the
    United States. Use the priority queue (heap) you built in
    the previous part to implement Dijkstra's algorithm for finding
    the shortest routes between cities.

    The `Graph` class defined in `graph.h` is
    very similar to that found in HW5, but slightly modified to
    incorporate edges with non-integer lengths. You should not need
    to modify it. Your task is to complete the implementations of
    `Dijkstra()` and `get_path()` in [`routes.cpp`](routes.cpp) to obtain
    the path distances sought in `test_shortest_paths()`, which runs when
    the compiled code is executed from the command line.

    The `test_shortest_paths()` function should print
    paths and path distances between:

    *   New York to Los Angeles
    *   New York to Miami
    *   New York to Seattle
    *   New York to San Francisco
    *   New York to Bostong

    As in any problem you are trying to solve, it may help in your
    code development to create a smaller graph for testing purposes.
    Feel free to do that in this case on your own, creating a smaller
    city graph file from the one provided and having the program use
    your modified version until you have your program working.

    *   [`graph.h`](graph.h)
    *   [`routes.cpp`](routes.cpp)
    *   [`city_connections.txt`](city_connections.txt)

1.  Once again use your binary heap min-prority queue, this to
    compress the image displayed below. The top/left image uses 16-bit
    grayscale (i.e., 65536 luminance/brightness levels) and is 429x600 pixels.
    The bottom/right image has the same dimensions, but uses only 4 bits
    per pixel (16 luminance levels). However, it can be further compressed by
    using Huffman encoding by considering the pixel values as "letters" in an
    "alphabet" of the allowed luminance levels. For example, an 8-bit
    brightness scale has 256 "letters".

    ![kayak_gray.png](kayak_gray.png) | ![kayak_reduced.png](kayak_reduced.png)

    Complete/answer the following tasks/questions:
    *   Complete the code in [`huffman.cpp`](huffman.cpp) to
        reduce/compress the image data. This file uses classes and
        functions defined in [`huffman.h`](huffman.h) and
        [`image.h`](image.h), which you probably want to look at for
        reference, but should not need to modify. Note that the image file is
        not actually encoded in a standard image file format, it is
        instead a text file containing a 429x600 matrix of pixel
        brightnesses (grayscale levels) for you to work with in C++
        without having to install additional tools on your computer.
        
        *  [`huffman.cpp`](huffman.cpp)
        *  [`huffman.h`](huffman.h)
        *  [`image.h`](image.h)
        *  [`kayak_mat.dat`](kayak_mat.dat)

    *   **Why does the compression factor (the ratio of the number of bits used
        to encode the image with and without Huffman encoding) typically
        improve as the number of grayscale levels are reduced? But why is
        it worse for 8 levels compared to 9 levels?**

    The brightness levels in the image matrix provided here are decimals
    between 0 and 1, but I don't actually care what their scale is. The
    `reduce_img_mat()` function can change them to integers if you like.
    (For example, values {0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875} or
    {0, 1, 2, 3, 4, 5, 6, 7} in the 3-bit case are both fine.)


1.  ***Extra credit:***
    The greedy algorithm to solve the set cover problem presented in the text
    and lecture was shown to find a "near optimal" solution; i.e., not the
    smallest covering set, but only larger than the optimal solution by a
    factor of ln(|*V*|). Here, we will compare the greedy algorithm to one in
    which covering sets are randomly selected (to see how much better we can do
    by at least attempting to find a better solution with simple greedy
    approach), as well as implement an algorithm that finds the optimal
    solution. Finding the optimal solution will, however, prove intractable for
    large graphs, so you we will not attempt this for the large `egonet` graph.

    Suppose we would like to use a social network to launch some sort of
    advertising campaign, but we would like to limit the number of users we
    directly target with ads. Furthermore, suppose we believe that if one user
    gets exposed to the ad, they are highly likely to share it with all of
    their first-degree connections on the network. So we decide we would like
    to target the smallest set of individuals whose direct connections will
    cover the entire network.

    We will use the same `egonet` graph from the last homework assignment. You
    may have noticed, however, that a handful of users had 0 connections. Here
    is a "reduced" version of the graph with those "empty" users removed:
    [`egonet_graph_noempty.txt`](egonet_graph_noempty.txt).

    *   Implement a greedy algorithm to select a subset of users in the egonet
        graph that will cover the entire graph with their first-degree
        connections.
    *   Implement an algorithm that randomly (rather than greedily) grows a
        subset of users that cover the graph, and compare the size of the one
        found in this way on the egonet graph to the size of the covering
        subset found with your greedy algorithm.
    *   Specify an algorithm that will find the optimal solution, and estimate
        its efficiency (e.g., approximately how many candidate subsets of users will test for set cover before one is found?) in big-*O* notation as a
        function of the number of vertices/users. (Note that it will not test
        *all* possible sets of users since we already know a limit on the size
        of the optimal covering subset.)
    *   Implement your algorithm above and test it by finding an optimal
        solution to the school-placement problem from the text/lecture (chapter
        5). You will need to create a text file with the relevant graph
        (specified by an adjacency list) to load with the `read_adjacency_file()`
        function.

    Complete the above tasks by using/completing the following code files:
    *   [`set_cover.h`](set_cover.h)
    *   [`set_cover.cpp`](set_cover.cpp)


# 

If you are running Windows and do not already know how to compile and execute C++
programs on your machine, these instructions should be helpful:
https://cs.calvin.edu/courses/cs/112/resources/installingEclipse/cygwin/.

You should utilize resources online, such as http://www.cplusplus.com/reference/
if you aren't familiar with some of the C++ classes and data structures
used here.

Email your code, answers, and the path distance matrix output file to
me (![eschomburg STRUDEL fordham.edu](email.png)) by midnight on the due date,
and please email me for questions and clarifications before then.
