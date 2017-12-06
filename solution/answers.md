## Homework 6 Answers

### Problem 1

See the following completed code files:

1.  [bin_heap.h](bin_heap.h)

Below is a demo of the binary heap / min-priority queue:
```
$ g++ -o bin_heap bin_heap.cpp
$ ./bin_heap 
Input items and their keys (separated by whitespace) to insert into the min-heap. If an item is alread in the heap, the key will be updated.
Hitting 'Enter' with no input stops building the heap and iteratively pops the minimum key value until it is empty.

(Item, Key): e 2
Heap:
e (2) 

(Item, Key): r 3
Heap:
e (2) 
r (3) 

(Item, Key): i 1
Heap:
i (1) 
r (3) e (2) 

(Item, Key): k 4
Heap:
i (1) 
r (3) e (2) 
k (4) 

(Item, Key): k 0
Heap:
k (0) 
i (1) e (2) 
r (3) 

(Item, Key): k 1
Heap:
k (1) 
i (1) e (2) 
r (3) 

(Item, Key): k 2
Heap:
i (1) 
k (2) e (2) 
r (3) 

(Item, Key): 

Popping items until empty...
Pop min: i
Heap:
k (2) 
r (3) e (2) 

Pop min: k
Heap:
e (2) 
r (3) 

Pop min: e
Heap:
r (3) 

Pop min: r
Heap:
(heap empty)

```


### Problem 2

See the following completed code files:

1.  [routes.cpp](routes.cpp)

Below is a demo of the program finding the shortest paths between cities:
```
$ g++ -o routes routes.cpp
$ ./routes
Route from New_York_NY to Los_Angeles_CA: New_York_NY -> Harrisburg -> Pittsburgh_PA -> Columbus_OH -> Dayton_OH -> Indianapolis_IN -> St_Louis_MO -> Oklahoma_City_OK -> Albuquerque_NM -> Flagstaff_AZ -> Los_Angeles_CA (2819.3 miles)

Route from New_York_NY to Miami_FL: New_York_NY -> Philadelphia_PA -> Baltimore_MD -> Richmond_VA -> Florence_SC -> Savannah_GA -> Jacksonville_FL -> Daytona_Beach_FL -> Miami_FL (1324.4 miles)

Route from New_York_NY to Seattle_WA: New_York_NY -> Scranton_PA -> Cleveland_OH -> Toledo_OH -> Chicago_IL -> Madison_WI -> Albert_Lea_MN -> Sioux_Falls_SD -> Billings_MT -> Butte_MT -> Seattle_WA (2928.6 miles)

Route from New_York_NY to San_Francisco_CA: New_York_NY -> Scranton_PA -> Cleveland_OH -> Toledo_OH -> Chicago_IL -> Davenport_IA -> Des_Moines_IA -> Omaha_NB -> Cheyenne_WY -> Salt_Lake_City_UT -> Sacramento_CA -> San_Francisco_CA (3006.9 miles)

Route from New_York_NY to Boston_MA: New_York_NY -> Providence_RI -> Boston_MA (231.3 miles)

```
