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
Image size: 429x601 (257829 pixels)
   CODE   
----------
0 (f=19730): 1010
1 (f=33765): 110
2 (f=61512): 01
3 (f=96397): 11
4 (f=41889): 00
5 (f=3695): 10010
6 (f=691): 100010
7 (f=150): 000010
Frequency sum: 257829

Basic bits: 3
Code efficiency: 603332 vs 773487 (0.780016)

$ ./huffman 9
Image size: 429x601 (257829 pixels)
   CODE   
----------
0 (f=15844): 0110
1 (f=28268): 010
2 (f=45498): 00
3 (f=78712): 11
4 (f=71874): 01
5 (f=15192): 11110
6 (f=1851): 101110
7 (f=471): 1001110
8 (f=119): 0001110
Frequency sum: 257829

Basic bits: 4
Code efficiency: 631544 vs 1.03132e+06 (0.612367)

$ ./huffman 256Image size: 429x601 (257829 pixels)
   CODE   
----------
0 (f=736): 00010000
1 (f=196): 0111111000
10 (f=345): 0010010111
100 (f=2835): 0001111
101 (f=2874): 0011111
102 (f=2887): 0111111
103 (f=2946): 000000
104 (f=2949): 100000
105 (f=2977): 110000
106 (f=3024): 101000
107 (f=3064): 000100
108 (f=3151): 001100
109 (f=3117): 010100
11 (f=348): 1010010111
110 (f=3213): 100010
111 (f=3193): 111100
112 (f=3281): 101010
113 (f=3288): 011010
114 (f=3311): 100110
115 (f=3255): 110010
116 (f=3235): 010010
117 (f=3198): 000010
118 (f=3291): 111010
119 (f=3170): 101100
12 (f=298): 0000000011
120 (f=3119): 110100
121 (f=3028): 011000
122 (f=3072): 100100
123 (f=2876): 1011111
124 (f=2865): 1101111
125 (f=2746): 1100111
126 (f=2725): 0100111
127 (f=2706): 1000111
128 (f=2581): 0001011
129 (f=2486): 1000011
13 (f=196): 1111111000
130 (f=2488): 0100011
131 (f=2322): 0101101
132 (f=2272): 0001101
133 (f=2156): 1000101
134 (f=2109): 1011001
135 (f=2016): 1001001
136 (f=1951): 0010001
137 (f=1863): 0111110
138 (f=1773): 1110110
139 (f=1650): 1000110
14 (f=207): 1000010110
140 (f=1495): 0001000
141 (f=1414): 01001111
142 (f=1314): 11101011
143 (f=1225): 10000011
144 (f=1097): 11010101
145 (f=1074): 11111001
146 (f=1024): 11101001
147 (f=952): 00000001
148 (f=870): 01010110
149 (f=752): 11001000
15 (f=209): 1010010110
150 (f=746): 01010000
151 (f=695): 110010111
152 (f=606): 100000011
153 (f=553): 010110101
154 (f=461): 011011110
155 (f=453): 110010110
156 (f=379): 100111000
157 (f=416): 100010110
158 (f=370): 010010000
159 (f=326): 0011011011
16 (f=252): 1001110001
160 (f=283): 1110110101
161 (f=263): 1010011001
162 (f=243): 1101000001
163 (f=208): 0010010110
164 (f=205): 1111011100
165 (f=177): 10101110111
166 (f=176): 00101110111
167 (f=175): 11011011011
168 (f=161): 11010110011
169 (f=128): 10010011001
17 (f=240): 1111011110
170 (f=122): 00001110001
171 (f=122): 10101000001
172 (f=116): 10111011110
173 (f=90): 101101110111
174 (f=120): 00101000001
175 (f=101): 10111011100
176 (f=77): 011000000011
177 (f=81): 101010110011
178 (f=92): 011101110111
179 (f=72): 110110110101
18 (f=316): 0010110011
180 (f=63): 110001110001
181 (f=84): 001011011011
182 (f=63): 000010011001
183 (f=74): 101000000011
184 (f=65): 000110110101
185 (f=63): 100010011001
186 (f=51): 000000010110
187 (f=51): 100000010110
188 (f=45): 1001101110111
189 (f=43): 0001101110111
19 (f=373): 110010000
190 (f=39): 0111000000011
191 (f=42): 0101011011011
192 (f=49): 100111011100
193 (f=40): 1001010110011
194 (f=35): 0001000000011
195 (f=35): 1010110110101
196 (f=28): 0000111011110
197 (f=34): 0100110110101
198 (f=27): 1110000010110
199 (f=39): 1111000000011
2 (f=530): 110011001
20 (f=401): 011011100
200 (f=26): 1010000010110
201 (f=25): 1000111011100
202 (f=23): 10111101110111
203 (f=30): 0010001110001
204 (f=17): 01100110110101
205 (f=26): 0010000010110
206 (f=19): 11001000000011
207 (f=24): 01111101110111
208 (f=19): 00001010110011
209 (f=13): 00110000010110
21 (f=506): 101110001
210 (f=24): 11111101110111
211 (f=17): 00010110110101
212 (f=14): 01000111011110
213 (f=17): 11100110110101
214 (f=17): 10010110110101
215 (f=12): 00000111011100
216 (f=9): 001001000000011
217 (f=14): 00100111011110
218 (f=11): 100111101110111
219 (f=13): 10110000010110
22 (f=650): 110110011
220 (f=15): 01100111011110
221 (f=11): 011101011011011
222 (f=2): 00011010001110001
223 (f=6): 010000111011100
224 (f=14): 11000111011110
225 (f=7): 010100111011110
226 (f=5): 0010001010110011
227 (f=8): 111100111011110
228 (f=6): 1111101011011011
229 (f=8): 101010001110001
23 (f=879): 11010110
230 (f=11): 000111101110111
231 (f=4): 1011100111011110
232 (f=7): 110100111011110
233 (f=10): 001101011011011
234 (f=3): 0110000111011100
235 (f=5): 1101101011011011
236 (f=5): 1010001010110011
237 (f=5): 1101001000000011
238 (f=4): 1011010001110001
239 (f=4): 1111010001110001
24 (f=994): 11010001
240 (f=3): 1110000111011100
241 (f=4): 0111010001110001
242 (f=1): 000111101011011011
243 (f=1): 00011100111011110
244 (f=2): 10101001000000011
245 (f=4): 1001010001110001
246 (f=5): 0101101011011011
247 (f=1): 110011010001110001
248 (f=3): 10111101011011011
249 (f=1): 010011100111011110
25 (f=895): 11001110
250 (f=4): 0001010001110001
251 (f=1): 010011010001110001
252 (f=2): 00101001000000011
253 (f=1): 100111101011011011
254 (f=1): 110011100111011110
255 (f=10): 110001010110011
26 (f=1006): 11110001
27 (f=1133): 11110101
28 (f=1197): 01111101
29 (f=1180): 00011101
3 (f=696): 001110111
30 (f=1102): 00110101
31 (f=956): 10000001
32 (f=902): 00101110
33 (f=824): 11001010
34 (f=763): 01111000
35 (f=748): 11010000
36 (f=755): 10111000
37 (f=749): 01001000
38 (f=818): 01001010
39 (f=804): 01011100
4 (f=964): 11000001
40 (f=889): 01001110
41 (f=908): 10101110
42 (f=930): 01011110
43 (f=944): 11111110
44 (f=935): 01111110
45 (f=1029): 00011001
46 (f=966): 01010001
47 (f=1054): 00111001
48 (f=1061): 01111001
49 (f=1117): 01110101
5 (f=1019): 01101001
50 (f=1060): 10111001
51 (f=1088): 01010101
52 (f=1190): 10011101
53 (f=1203): 11111101
54 (f=1239): 01100011
55 (f=1269): 01010011
56 (f=1291): 11110011
57 (f=1347): 01111011
58 (f=1262): 11100011
59 (f=1281): 11010011
6 (f=671): 111011011
60 (f=1296): 01101011
61 (f=1431): 11001111
62 (f=1283): 00110011
63 (f=1329): 01011011
64 (f=1290): 01110011
65 (f=1352): 11111011
66 (f=1413): 11110111
67 (f=1361): 00010111
68 (f=1408): 10110111
69 (f=1461): 01111111
7 (f=478): 001000001
70 (f=1388): 00110111
71 (f=1467): 11111111
72 (f=1626): 0001010
73 (f=1568): 0011100
74 (f=1645): 0000110
75 (f=1782): 0001110
76 (f=1756): 0110110
77 (f=1855): 1101110
78 (f=1933): 1100001
79 (f=1858): 0011110
8 (f=382): 011111000
80 (f=1932): 0100001
81 (f=2012): 0001001
82 (f=2040): 0101001
83 (f=1996): 0110001
84 (f=2163): 1100101
85 (f=2148): 0000101
86 (f=2160): 0100101
87 (f=2163): 0010101
88 (f=2290): 1001101
89 (f=2333): 1101101
9 (f=375): 000111000
90 (f=2370): 1011101
91 (f=2392): 0111101
92 (f=2604): 0101011
93 (f=2532): 0010011
94 (f=2592): 1001011
95 (f=2622): 0011011
96 (f=2699): 0000111
97 (f=2681): 0111011
98 (f=2766): 1010111
99 (f=2855): 0101111
Frequency sum: 257829

Basic bits: 8
Code efficiency: 1.8567e+06 vs 2.06263e+06 (0.900163)
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

Covering vertices from random algorithm: B I E (3)

Covering vertices from optimal algorithm: B E H (3)

$ ./set_cover egonet_graph_noempty.txt 0
Testing ./set_cover ...


Covering vertices from greedy algorithm: 58 3 42 205 189 209 212 121 137 16 203 13 17 82 130 24 32 49 53 56 126 140 (22)

Covering vertices from random algorithm: 100 34 41 35 67 111 202 27 66 143 172 13 144 150 192 64 130 25 74 136 50 53 77 200 149 63 70 28 173 196 152 32 135 238 217 49 55 103 (38)
Graph too large, not attempting optimal search...
```
