## Homework 6 Answers

### Problem 1

See the following completed code files:

*   [bin_heap.h](bin_heap.h)

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

*   [routes.cpp](routes.cpp)

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

### Problem 3

See the following completed code files:

*   [huffman.cpp](huffman.cpp)

Below is a demo of the program using Huffman encoding with 8, 9, and 256 levels:
```
$ g++ -o huffman huffman.cpp
$ ./huffman 8
   CODE   
----------
0 (f=23446): 1001
1 (f=43053): 101
2 (f=88645): 11
3 (f=89827): 0
4 (f=11536): 10001
5 (f=1130): 100001
6 (f=186): 1000001
7 (f=6): 0000001

Code efficiency: 555864 vs 773487 (0.718647)

$ ./huffman 9
   CODE   
----------
0 (f=19730): 1010
1 (f=33765): 110
2 (f=61512): 01
3 (f=96397): 11
4 (f=41889): 00
5 (f=3695): 10010
6 (f=691): 100010
7 (f=144): 1000010
8 (f=6): 0000010

Code efficiency: 603482 vs 1.03132e+06 (0.585157)

$ ./huffman 256
   CODE   
----------
0 (f=736): 110111111
1 (f=196): 0100101100
10 (f=346): 0001001111
100 (f=2912): 1111111
101 (f=2901): 1101111
102 (f=2950): 000000
103 (f=2961): 100000
104 (f=2908): 1011111
105 (f=3067): 000100
106 (f=3052): 011000
107 (f=3126): 001100
108 (f=3116): 010100
109 (f=3217): 100010
11 (f=351): 1001001111
110 (f=3251): 110010
111 (f=3205): 000010
112 (f=3298): 011010
113 (f=3333): 100110
114 (f=3294): 101010
115 (f=3304): 000110
116 (f=3118): 110100
117 (f=3302): 111010
118 (f=3236): 010010
119 (f=3195): 011100
12 (f=287): 1010001101
120 (f=3041): 101000
121 (f=3077): 100100
122 (f=2965): 010000
123 (f=2902): 0011111
124 (f=2779): 0110111
125 (f=2777): 1010111
126 (f=2745): 0010111
127 (f=2575): 1110011
128 (f=2561): 1010011
129 (f=2451): 0000011
13 (f=199): 1010001010
130 (f=2452): 1000011
131 (f=2303): 1001101
132 (f=2143): 1111001
133 (f=2182): 0010101
134 (f=2034): 0011001
135 (f=1979): 1110001
136 (f=1908): 1111110
137 (f=1817): 0101110
138 (f=1709): 0010110
139 (f=1589): 0111100
14 (f=199): 0010001010
140 (f=1443): 00111111
141 (f=1340): 10000111
142 (f=1289): 00001011
143 (f=1146): 00101101
144 (f=1092): 11100101
145 (f=1055): 10111001
146 (f=977): 11010001
147 (f=913): 11101110
148 (f=797): 10101100
149 (f=746): 10110000
15 (f=221): 0000011110
150 (f=739): 00110000
151 (f=641): 100100011
152 (f=570): 110001101
153 (f=483): 010100001
154 (f=482): 110000001
155 (f=416): 110001010
156 (f=384): 101111000
157 (f=386): 000101100
158 (f=346): 1101100111
159 (f=314): 1000100011
16 (f=249): 0100001001
160 (f=265): 1001100101
161 (f=236): 0010000001
162 (f=240): 1010000001
163 (f=210): 0001010110
164 (f=182): 00010111111
165 (f=183): 10010111111
166 (f=169): 00101100111
167 (f=165): 11010101011
168 (f=131): 10001100101
169 (f=130): 00001100101
17 (f=242): 0110100001
170 (f=126): 01100001001
171 (f=123): 01110100001
172 (f=98): 01100101100
173 (f=114): 01000011110
174 (f=99): 11100101100
175 (f=86): 110101100111
176 (f=94): 10010001000
177 (f=82): 101010101011
178 (f=73): 110010001101
179 (f=66): 000010001101
18 (f=319): 0010101011
180 (f=76): 100000100011
181 (f=68): 100010001101
182 (f=77): 010000100011
183 (f=61): 011110100001
184 (f=64): 111100001001
185 (f=59): 011000011110
186 (f=47): 001010001000
187 (f=54): 101001010110
188 (f=42): 0010101100111
189 (f=41): 1001010101011
19 (f=383): 001111000
190 (f=37): 0000000100011
191 (f=48): 011010001000
192 (f=45): 000010001000
193 (f=29): 1111001010110
194 (f=39): 1110000100011
195 (f=32): 1111110100001
196 (f=31): 0111110100001
197 (f=30): 0111000011110
198 (f=39): 0110000100011
199 (f=28): 0011001010110
2 (f=560): 101100101
20 (f=429): 101010110
200 (f=24): 1101010001000
201 (f=25): 0001001010110
202 (f=28): 1011001010110
203 (f=18): 01010010001101
204 (f=25): 1111010001000
205 (f=18): 11010010001101
206 (f=24): 0101010001000
207 (f=21): 01010101100111
208 (f=16): 00011100001001
209 (f=17): 10010010001101
21 (f=492): 000001001
210 (f=23): 0100010001000
211 (f=15): 01111000011110
212 (f=17): 00010010001101
213 (f=19): 11000000100011
214 (f=11): 111010101100111
215 (f=10): 000001010101011
216 (f=12): 00111010001000
217 (f=11): 01100010001000
218 (f=14): 00111001010110
219 (f=14): 11001001010110
22 (f=666): 001100111
220 (f=12): 11100010001000
221 (f=3): 0010111010001000
222 (f=3): 1101001001010110
223 (f=15): 11111000011110
224 (f=8): 011011100001001
225 (f=5): 0011010101100111
226 (f=9): 001000000100011
227 (f=4): 1101011100001001
228 (f=9): 101000000100011
229 (f=10): 010001010101011
23 (f=869): 11010110
230 (f=5): 1100001010101011
231 (f=7): 010111001010110
232 (f=10): 110001010101011
233 (f=4): 0010011100001001
234 (f=4): 0101011100001001
235 (f=6): 110111010001000
236 (f=4): 1110111001010110
237 (f=5): 1011010101100111
238 (f=4): 1010011100001001
239 (f=3): 1010111010001000
24 (f=985): 00110001
240 (f=4): 0111011100001001
241 (f=1): 011001011100001001
243 (f=3): 0101001001010110
244 (f=4): 1110011100001001
245 (f=5): 0100001010101011
246 (f=1): 00110111001010110
247 (f=2): 10110111001010110
248 (f=2): 10001011100001001
249 (f=4): 0110011100001001
25 (f=927): 10011110
250 (f=1): 001001011100001001
251 (f=1): 111001011100001001
252 (f=2): 00001011100001001
253 (f=1): 101001011100001001
254 (f=4): 1111011100001001
255 (f=6): 001001001010110
26 (f=991): 10110001
27 (f=1164): 01101101
28 (f=1226): 11111101
29 (f=1181): 11101101
3 (f=716): 101001111
30 (f=1096): 01110101
31 (f=932): 01011110
32 (f=897): 11001110
33 (f=840): 11001010
34 (f=762): 11001000
35 (f=761): 01001000
36 (f=750): 00001000
37 (f=769): 11111000
38 (f=824): 01001010
39 (f=813): 00001010
4 (f=961): 00100001
40 (f=897): 01001110
41 (f=934): 11011110
42 (f=913): 01101110
43 (f=975): 01010001
44 (f=956): 00000001
45 (f=1001): 10001001
46 (f=1006): 00101001
47 (f=1036): 00111001
48 (f=1084): 10100101
49 (f=1133): 00001101
5 (f=1017): 10101001
50 (f=1069): 00100101
51 (f=1127): 11110101
52 (f=1163): 10101101
53 (f=1216): 01111101
54 (f=1263): 10100011
55 (f=1283): 00110011
56 (f=1302): 00101011
57 (f=1312): 01101011
58 (f=1312): 11101011
59 (f=1288): 10110011
6 (f=662): 110101011
60 (f=1332): 01111011
61 (f=1392): 11100111
62 (f=1291): 10001011
63 (f=1326): 10011011
64 (f=1337): 00000111
65 (f=1318): 00011011
66 (f=1435): 00101111
67 (f=1336): 11111011
68 (f=1488): 1110000
69 (f=1415): 11001111
7 (f=466): 100011110
70 (f=1438): 10101111
71 (f=1528): 0111000
72 (f=1613): 1111100
73 (f=1586): 1101100
74 (f=1728): 0110110
75 (f=1752): 1110110
76 (f=1771): 0001110
77 (f=1888): 0111110
78 (f=1927): 1000001
79 (f=1942): 1100001
8 (f=382): 110001000
80 (f=1947): 0010001
81 (f=2029): 1101001
82 (f=2082): 1011001
83 (f=2012): 1001001
84 (f=2193): 1010101
85 (f=2146): 0000101
86 (f=2151): 1000101
87 (f=2211): 0110101
88 (f=2349): 0011101
89 (f=2357): 1011101
9 (f=368): 1010111111
90 (f=2371): 0111101
91 (f=2536): 1100011
92 (f=2538): 0010011
93 (f=2647): 1011011
94 (f=2591): 1001011
95 (f=2652): 0111011
96 (f=2700): 1000111
97 (f=2712): 0100111
98 (f=2817): 0001111
99 (f=2795): 1110111

Code efficiency: 1.85527e+06 vs 2.06263e+06 (0.899469)
```

As you can see, Huffman encoding (somewhat unfairly) improves the efficiency
more when 9 levels are allowed, compared to 8 levels, because encoding 9 levels
in the basic equal-length scheme requires 4 bits but leaves 7 of the possible
4-bit codes unutilized. The variable length encoding scheme used by Huffman
encoding does not suffer from this inefficiency. Greater compression efficiency
can also be gained with fewer allowed brightness levels (e.g., 8 versus 256)
because the frequent brightness levels used in the original image tend to
cluster near each other and result in even higher concentration of occurrences
when these neighboring levels are combined and encoded with shorter codewords.

### Problem 4
**Extra credit**

See the following completed code files:

*   [set_cover.cpp](set_cover.cpp)

Below is a demo of the program on the school set cover problem from the textbook,
as well as the egonet graph (with only the large connected component included):

```
$ g++ -o set_cover set_cover.cpp
$ ./set_cover ../solution/school_set_cover_graph.txt 1
Testing ./set_cover ...


Nodes:
A, B, C, D, E, F, G, H, I, J, K

Edges:
A: B, D, H, I, K
B: A, C, D
C: B, D
D: A, B, C
E: A, F, G
F: E, G
G: E, F
H: A, I, J, K
I: A, H, J, K
J: H, I, K
K: A, H, I, J

Covering vertices from greedy algorithm: A E B H (4)

Covering vertices from random algorithm: G H A E C (5)

Covering vertices from optimal algorithm: B E H (3)

$ ./set_cover egonet_graph_noempty.txt 0
Testing ./set_cover ...


Covering vertices from greedy algorithm: 58 3 42 205 189 209 212 121 137 16 203 13 17 82 130 24 32 49 53 56 126 140 (22)

Covering vertices from random algorithm: 46 90 9 170 124 129 231 62 188 53 205 11 148 190 106 166 192 209 207 72 98 110 56 69 197 57 61 86 203 144 186 27 80 179 117 224 114 64 233 87 42 52 83 189 84 150 49 172 43 130 136 105 139 177 176 15 213 222 31 183 196 73 157 30 85 113 174 229 16 112 1 120 178 41 167 161 216 111 126 (79)
Graph too large, not attempting optimal search...
```
