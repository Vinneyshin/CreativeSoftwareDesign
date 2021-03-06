#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

bool is_sum_of_three_triangle_number(vector<int>& triangle_numbers, int number);

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    
    if(T < 3 || T > 1000) return -1;

    int* numbers = new int[T];
    
    vector<int> triangle_numbers;
    set<int> sum_of_three_triangle_numbers;

    for (int i = 1; (i*(i+1))/2 < 1000; ++i)
    {
        triangle_numbers.push_back((i*(i+1))/2);
    }

    for (int i = 0; i < triangle_numbers.size(); i++)
    {
        for (int j = 0; j < triangle_numbers.size(); j++)
        {
            for (int k = 0; k < triangle_numbers.size(); k++)
            {
                sum_of_three_triangle_numbers.insert(triangle_numbers[i] + triangle_numbers[j] + triangle_numbers[k]);
            }   
        }
    }

    for (int i = 0; i < T; i++) cin >> numbers[i];

    for (int i = 0; i < T; i++)
        cout << (sum_of_three_triangle_numbers.find(numbers[i]) != sum_of_three_triangle_numbers.end() ? "1" : "0") << endl;
    
    return 0;
}


/*
triangle numbers
1
3
6
10
15
21
28
36
45
55
66
78
91
105
120
136
153
171
190
210
231
253
276
300
325
351
378
406
435
465
496
528
561
595
630
666
703
741
780
820
861
903
946
990

ofstream out("out.txt");
cout.rdbuf(out.rdbuf());

for (int i = 1; (i*(i+1))/2 < 1000; ++i)
{
    cout << (i*(i+1))/2 << endl;
}

*/

/*
1 = 
2 = 
3 = 1 + 1 + 1
4 = 
5 = 1 + 1 + 3
6 = 
7 = 1 + 3 + 3
8 = 1 + 1 + 6
9 = 3 + 3 + 3
10 = 1 + 3 + 6
11 = 
12 = 1 + 1 + 10
13 = 1 + 6 + 6
14 = 1 + 3 + 10
15 = 3 + 6 + 6
16 = 3 + 3 + 10
17 = 1 + 1 + 15
18 = 6 + 6 + 6
19 = 1 + 3 + 15
20 = 
21 = 1 + 10 + 10
22 = 1 + 6 + 15
23 = 1 + 1 + 21
24 = 3 + 6 + 15
25 = 1 + 3 + 21
26 = 1 + 10 + 15
27 = 3 + 3 + 21
28 = 1 + 6 + 21
29 = 
30 = 1 + 1 + 28
31 = 1 + 15 + 15
32 = 1 + 3 + 28
33 = 3 + 15 + 15
34 = 3 + 3 + 28
35 = 1 + 6 + 28
36 = 6 + 15 + 15
37 = 1 + 15 + 21
38 = 1 + 1 + 36
39 = 1 + 10 + 28
40 = 1 + 3 + 36
41 = 3 + 10 + 28
42 = 3 + 3 + 36
43 = 1 + 6 + 36
44 = 1 + 15 + 28
45 = 3 + 6 + 36
46 = 3 + 15 + 28
47 = 1 + 1 + 45
48 = 6 + 6 + 36
49 = 1 + 3 + 45
50 = 1 + 21 + 28
51 = 3 + 3 + 45
52 = 1 + 6 + 45
53 = 10 + 15 + 28
54 = 3 + 6 + 45
55 = 6 + 21 + 28
56 = 1 + 10 + 45
57 = 1 + 1 + 55
58 = 1 + 21 + 36
59 = 1 + 3 + 55
60 = 3 + 21 + 36
61 = 1 + 15 + 45
62 = 1 + 6 + 55
63 = 3 + 15 + 45
64 = 3 + 6 + 55
65 = 1 + 28 + 36
66 = 1 + 10 + 55
67 = 1 + 21 + 45
68 = 1 + 1 + 66
69 = 3 + 21 + 45
70 = 1 + 3 + 66
71 = 1 + 15 + 55
72 = 3 + 3 + 66
73 = 1 + 6 + 66
74 = 1 + 28 + 45
75 = 3 + 6 + 66
76 = 3 + 28 + 45
77 = 1 + 10 + 66
78 = 6 + 6 + 66
79 = 3 + 10 + 66
80 = 1 + 1 + 78
81 = 15 + 21 + 45
82 = 1 + 3 + 78
83 = 10 + 28 + 45
84 = 1 + 28 + 55
85 = 1 + 6 + 78
86 = 3 + 28 + 55
87 = 3 + 6 + 78
88 = 1 + 21 + 66
89 = 1 + 10 + 78
90 = 3 + 21 + 66
91 = 1 + 45 + 45
92 = 1 + 36 + 55
93 = 1 + 1 + 91
94 = 1 + 15 + 78
95 = 1 + 3 + 91
96 = 3 + 15 + 78
97 = 3 + 3 + 91
98 = 1 + 6 + 91
99 = 6 + 15 + 78
100 = 1 + 21 + 78
101 = 1 + 45 + 55
102 = 1 + 10 + 91
103 = 1 + 36 + 66
104 = 3 + 10 + 91
105 = 3 + 36 + 66
106 = 6 + 45 + 55
107 = 1 + 1 + 105
108 = 6 + 36 + 66
109 = 1 + 3 + 105
110 = 10 + 45 + 55
111 = 1 + 55 + 55
112 = 1 + 6 + 105
113 = 1 + 21 + 91
114 = 3 + 6 + 105
115 = 1 + 36 + 78
116 = 1 + 10 + 105
117 = 3 + 36 + 78
118 = 3 + 10 + 105
119 = 28 + 36 + 55
120 = 1 + 28 + 91
121 = 1 + 15 + 105
122 = 1 + 1 + 120
123 = 3 + 15 + 105
124 = 1 + 3 + 120
125 = 6 + 28 + 91
126 = 3 + 3 + 120
127 = 1 + 6 + 120
128 = 1 + 36 + 91
129 = 3 + 6 + 120
130 = 3 + 36 + 91
131 = 1 + 10 + 120
132 = 6 + 6 + 120
133 = 1 + 66 + 66
134 = 1 + 28 + 105
135 = 3 + 66 + 66
136 = 1 + 15 + 120
137 = 1 + 45 + 91
138 = 1 + 1 + 136
139 = 3 + 45 + 91
140 = 1 + 3 + 136
141 = 6 + 15 + 120
142 = 1 + 21 + 120
143 = 1 + 6 + 136
144 = 3 + 21 + 120
145 = 1 + 66 + 78
146 = 10 + 45 + 91
147 = 1 + 10 + 136
148 = 6 + 6 + 136
149 = 1 + 28 + 120
150 = 6 + 66 + 78
151 = 1 + 45 + 105
152 = 1 + 15 + 136
153 = 3 + 45 + 105
154 = 3 + 15 + 136
155 = 1 + 1 + 153
156 = 6 + 45 + 105
157 = 1 + 3 + 153
158 = 1 + 21 + 136
159 = 3 + 3 + 153
160 = 1 + 6 + 153
161 = 1 + 55 + 105
162 = 3 + 6 + 153
163 = 3 + 55 + 105
164 = 1 + 10 + 153
165 = 1 + 28 + 136
166 = 1 + 45 + 120
167 = 3 + 28 + 136
168 = 3 + 45 + 120
169 = 1 + 15 + 153
170 = 1 + 78 + 91
171 = 3 + 15 + 153
172 = 1 + 66 + 105
173 = 1 + 1 + 171
174 = 3 + 66 + 105
175 = 1 + 3 + 171
176 = 1 + 55 + 120
177 = 3 + 3 + 171
178 = 1 + 6 + 171
179 = 10 + 78 + 91
180 = 3 + 6 + 171
181 = 6 + 55 + 120
182 = 1 + 10 + 171
183 = 1 + 91 + 91
184 = 1 + 78 + 105
185 = 3 + 91 + 91
186 = 3 + 78 + 105
187 = 1 + 15 + 171
188 = 6 + 91 + 91
189 = 3 + 15 + 171
190 = 1 + 36 + 153
191 = 10 + 10 + 171
192 = 1 + 1 + 190
193 = 1 + 21 + 171
194 = 1 + 3 + 190
195 = 3 + 21 + 171
196 = 3 + 3 + 190
197 = 1 + 6 + 190
198 = 6 + 21 + 171
199 = 1 + 45 + 153
200 = 1 + 28 + 171
201 = 1 + 10 + 190
202 = 3 + 28 + 171
203 = 1 + 66 + 136
204 = 6 + 45 + 153
205 = 3 + 66 + 136
206 = 1 + 15 + 190
207 = 15 + 21 + 171
208 = 1 + 36 + 171
209 = 1 + 55 + 153
210 = 3 + 36 + 171
211 = 1 + 105 + 105
212 = 1 + 1 + 210
213 = 3 + 105 + 105
214 = 1 + 3 + 210
215 = 1 + 78 + 136
216 = 3 + 3 + 210
217 = 1 + 6 + 210
218 = 10 + 55 + 153
219 = 1 + 28 + 190
220 = 1 + 66 + 153
221 = 1 + 10 + 210
222 = 3 + 66 + 153
223 = 3 + 10 + 210
224 = 6 + 28 + 190
225 = 6 + 66 + 153
226 = 1 + 15 + 210
227 = 1 + 36 + 190
228 = 1 + 91 + 136
229 = 3 + 36 + 190
230 = 3 + 91 + 136
231 = 6 + 15 + 210
232 = 1 + 21 + 210
233 = 1 + 1 + 231
234 = 3 + 21 + 210
235 = 1 + 3 + 231
236 = 1 + 45 + 190
237 = 3 + 3 + 231
238 = 1 + 6 + 231
239 = 1 + 28 + 210
240 = 3 + 6 + 231
241 = 1 + 120 + 120
242 = 1 + 10 + 231
243 = 3 + 120 + 120
244 = 3 + 10 + 231
245 = 1 + 91 + 153
246 = 1 + 55 + 190
247 = 1 + 15 + 231
248 = 3 + 55 + 190
249 = 3 + 15 + 231
250 = 1 + 78 + 171
251 = 6 + 55 + 190
252 = 3 + 78 + 171
253 = 1 + 21 + 231
254 = 10 + 91 + 153
255 = 1 + 1 + 253
256 = 1 + 45 + 210
257 = 1 + 3 + 253
258 = 3 + 45 + 210
259 = 1 + 105 + 153
260 = 1 + 6 + 253
261 = 3 + 105 + 153
262 = 3 + 6 + 253
263 = 1 + 91 + 171
264 = 1 + 10 + 253
265 = 3 + 91 + 171
266 = 1 + 55 + 210
267 = 15 + 21 + 231
268 = 1 + 36 + 231
269 = 1 + 15 + 253
270 = 3 + 36 + 231
271 = 3 + 15 + 253
272 = 10 + 91 + 171
273 = 1 + 136 + 136
274 = 1 + 120 + 153
275 = 1 + 21 + 253
276 = 3 + 120 + 153
277 = 1 + 45 + 231
278 = 1 + 1 + 276
279 = 3 + 45 + 231
280 = 1 + 3 + 276
281 = 36 + 55 + 190
282 = 1 + 28 + 253
283 = 1 + 6 + 276
284 = 3 + 28 + 253
285 = 3 + 6 + 276
286 = 10 + 45 + 231
287 = 1 + 10 + 276
288 = 6 + 6 + 276
289 = 1 + 78 + 210
290 = 1 + 36 + 253
291 = 3 + 78 + 210
292 = 1 + 15 + 276
293 = 21 + 136 + 136
294 = 3 + 15 + 276
295 = 6 + 36 + 253
296 = 1 + 105 + 190
297 = 6 + 15 + 276
298 = 1 + 21 + 276
299 = 1 + 45 + 253
300 = 3 + 21 + 276
301 = 3 + 45 + 253
302 = 1 + 1 + 300
303 = 6 + 21 + 276
304 = 1 + 3 + 300
305 = 1 + 28 + 276
306 = 3 + 3 + 300
307 = 1 + 6 + 300
308 = 1 + 136 + 171
309 = 1 + 55 + 253
310 = 1 + 78 + 231
311 = 1 + 10 + 300
312 = 3 + 78 + 231
313 = 1 + 36 + 276
314 = 6 + 55 + 253
315 = 3 + 36 + 276
316 = 1 + 15 + 300
317 = 10 + 136 + 171
318 = 3 + 15 + 300
319 = 10 + 78 + 231
320 = 1 + 66 + 253
321 = 6 + 15 + 300
322 = 1 + 21 + 300
323 = 1 + 91 + 231
324 = 3 + 21 + 300
325 = 1 + 153 + 171
326 = 28 + 45 + 253
327 = 1 + 1 + 325
328 = 6 + 91 + 231
329 = 1 + 3 + 325
330 = 6 + 153 + 171
331 = 1 + 120 + 210
332 = 1 + 6 + 325
333 = 3 + 120 + 210
334 = 3 + 6 + 325
335 = 28 + 136 + 171
336 = 1 + 10 + 325
337 = 1 + 36 + 300
338 = 3 + 10 + 325
339 = 3 + 36 + 300
340 = 10 + 120 + 210
341 = 1 + 15 + 325
342 = 6 + 36 + 300
343 = 1 + 66 + 276
344 = 1 + 153 + 190
345 = 1 + 91 + 253
346 = 1 + 45 + 300
347 = 1 + 21 + 325
348 = 3 + 45 + 300
349 = 3 + 21 + 325
350 = 6 + 91 + 253
351 = 6 + 45 + 300
352 = 1 + 120 + 231
353 = 1 + 1 + 351
354 = 1 + 28 + 325
355 = 1 + 3 + 351
356 = 1 + 55 + 300
357 = 3 + 3 + 351
358 = 1 + 6 + 351
359 = 1 + 105 + 253
360 = 3 + 6 + 351
361 = 3 + 105 + 253
362 = 1 + 10 + 351
363 = 6 + 6 + 351
364 = 1 + 153 + 210
365 = 10 + 55 + 300
366 = 3 + 153 + 210
367 = 1 + 15 + 351
368 = 1 + 91 + 276
369 = 3 + 15 + 351
370 = 3 + 91 + 276
371 = 1 + 45 + 325
372 = 6 + 15 + 351
373 = 1 + 21 + 351
374 = 1 + 120 + 253
375 = 3 + 21 + 351
376 = 3 + 120 + 253
377 = 10 + 91 + 276
378 = 6 + 21 + 351
379 = 1 + 78 + 300
380 = 1 + 1 + 378
381 = 1 + 55 + 325
382 = 1 + 3 + 378
383 = 3 + 55 + 325
384 = 3 + 3 + 378
385 = 1 + 6 + 378
386 = 6 + 55 + 325
387 = 3 + 6 + 378
388 = 1 + 36 + 351
389 = 1 + 10 + 378
390 = 1 + 136 + 253
391 = 3 + 10 + 378
392 = 1 + 66 + 325
393 = 6 + 36 + 351
394 = 1 + 15 + 378
395 = 6 + 136 + 253
396 = 3 + 15 + 378
397 = 1 + 45 + 351
398 = 10 + 10 + 378
399 = 3 + 45 + 351
400 = 1 + 21 + 378
401 = 1 + 190 + 210
402 = 3 + 21 + 378
403 = 1 + 171 + 231
404 = 1 + 78 + 325
405 = 3 + 171 + 231
406 = 1 + 105 + 300
407 = 1 + 28 + 378
408 = 1 + 1 + 406
409 = 3 + 28 + 378
410 = 1 + 3 + 406
411 = 6 + 105 + 300
412 = 3 + 3 + 406
413 = 1 + 6 + 406
414 = 15 + 21 + 378
415 = 1 + 36 + 378
416 = 10 + 28 + 378
417 = 1 + 10 + 406
418 = 1 + 66 + 351
419 = 3 + 10 + 406
420 = 3 + 66 + 351
421 = 1 + 120 + 300
422 = 1 + 15 + 406
423 = 3 + 120 + 300
424 = 1 + 45 + 378
425 = 1 + 171 + 253
426 = 3 + 45 + 378
427 = 3 + 171 + 253
428 = 1 + 21 + 406
429 = 6 + 45 + 378
430 = 1 + 78 + 351
431 = 1 + 105 + 325
432 = 3 + 78 + 351
433 = 3 + 105 + 325
434 = 1 + 55 + 378
435 = 1 + 28 + 406
436 = 3 + 55 + 378
437 = 1 + 1 + 435
438 = 15 + 45 + 378
439 = 1 + 3 + 435
440 = 6 + 28 + 406
441 = 3 + 3 + 435
442 = 1 + 6 + 435
443 = 1 + 36 + 406
444 = 1 + 190 + 253
445 = 1 + 66 + 378
446 = 1 + 10 + 435
447 = 3 + 66 + 378
448 = 1 + 171 + 276
449 = 6 + 190 + 253
450 = 3 + 171 + 276
451 = 1 + 15 + 435
452 = 1 + 45 + 406
453 = 3 + 15 + 435
454 = 1 + 153 + 300
455 = 10 + 10 + 435
456 = 3 + 153 + 300
457 = 1 + 21 + 435
458 = 15 + 190 + 253
459 = 3 + 21 + 435
460 = 10 + 15 + 435
461 = 10 + 45 + 406
462 = 1 + 55 + 406
463 = 1 + 231 + 231
464 = 1 + 28 + 435
465 = 3 + 231 + 231
466 = 3 + 28 + 435
467 = 1 + 1 + 465
468 = 6 + 231 + 231
469 = 1 + 3 + 465
470 = 1 + 91 + 378
471 = 3 + 3 + 465
472 = 1 + 6 + 465
473 = 1 + 66 + 406
474 = 3 + 6 + 465
475 = 3 + 66 + 406
476 = 1 + 10 + 465
477 = 6 + 6 + 465
478 = 3 + 10 + 465
479 = 1 + 153 + 325
480 = 36 + 66 + 378
481 = 1 + 15 + 465
482 = 10 + 66 + 406
483 = 3 + 15 + 465
484 = 1 + 105 + 378
485 = 1 + 78 + 406
486 = 3 + 105 + 378
487 = 1 + 21 + 465
488 = 1 + 136 + 351
489 = 3 + 21 + 465
490 = 3 + 136 + 351
491 = 1 + 55 + 435
492 = 6 + 21 + 465
493 = 3 + 55 + 435
494 = 1 + 28 + 465
495 = 15 + 15 + 465
496 = 3 + 28 + 465
497 = 1 + 171 + 325
498 = 1 + 1 + 496
499 = 1 + 120 + 378
500 = 1 + 3 + 496
501 = 3 + 120 + 378
502 = 1 + 36 + 465
503 = 1 + 6 + 496
504 = 3 + 36 + 465
505 = 1 + 153 + 351
506 = 10 + 171 + 325
507 = 1 + 10 + 496
508 = 1 + 231 + 276
509 = 3 + 10 + 496
510 = 3 + 231 + 276
511 = 1 + 45 + 465
512 = 1 + 15 + 496
513 = 3 + 45 + 465
514 = 1 + 78 + 435
515 = 1 + 136 + 378
516 = 1 + 190 + 325
517 = 3 + 136 + 378
518 = 1 + 21 + 496
519 = 6 + 78 + 435
520 = 3 + 21 + 496
521 = 1 + 55 + 465
522 = 15 + 231 + 276
523 = 1 + 171 + 351
524 = 10 + 136 + 378
525 = 1 + 28 + 496
526 = 6 + 55 + 465
527 = 1 + 91 + 435
528 = 6 + 171 + 351
529 = 3 + 91 + 435
530 = 1 + 1 + 528
531 = 21 + 45 + 465
532 = 1 + 3 + 528
533 = 1 + 36 + 496
534 = 3 + 3 + 528
535 = 1 + 6 + 528
536 = 1 + 210 + 325
537 = 3 + 6 + 528
538 = 3 + 210 + 325
539 = 1 + 10 + 528
540 = 6 + 6 + 528
541 = 1 + 105 + 435
542 = 1 + 45 + 496
543 = 1 + 136 + 406
544 = 1 + 15 + 528
545 = 3 + 136 + 406
546 = 3 + 15 + 528
547 = 6 + 45 + 496
548 = 6 + 136 + 406
549 = 6 + 15 + 528
550 = 1 + 21 + 528
551 = 10 + 45 + 496
552 = 1 + 55 + 496
553 = 1 + 276 + 276
554 = 1 + 253 + 300
555 = 3 + 276 + 276
556 = 1 + 120 + 435
557 = 1 + 28 + 528
558 = 3 + 120 + 435
559 = 3 + 28 + 528
560 = 1 + 153 + 406
561 = 6 + 120 + 435
562 = 1 + 210 + 351
563 = 1 + 1 + 561
564 = 3 + 210 + 351
565 = 1 + 3 + 561
566 = 10 + 28 + 528
567 = 3 + 3 + 561
568 = 1 + 6 + 561
569 = 1 + 190 + 378
570 = 3 + 6 + 561
571 = 1 + 105 + 465
572 = 1 + 10 + 561
573 = 3 + 105 + 465
574 = 1 + 45 + 528
575 = 1 + 78 + 496
576 = 3 + 45 + 528
577 = 1 + 15 + 561
578 = 1 + 171 + 406
579 = 1 + 253 + 325
580 = 3 + 171 + 406
581 = 3 + 253 + 325
582 = 6 + 15 + 561
583 = 1 + 21 + 561
584 = 1 + 55 + 528
585 = 3 + 21 + 561
586 = 1 + 120 + 465
587 = 10 + 171 + 406
588 = 1 + 91 + 496
589 = 1 + 153 + 435
590 = 1 + 28 + 561
591 = 3 + 153 + 435
592 = 3 + 28 + 561
593 = 6 + 91 + 496
594 = 6 + 153 + 435
595 = 1 + 66 + 528
596 = 28 + 190 + 378
597 = 1 + 1 + 595
598 = 1 + 36 + 561
599 = 1 + 3 + 595
600 = 3 + 36 + 561
601 = 1 + 300 + 300
602 = 1 + 6 + 595
603 = 3 + 300 + 300
604 = 3 + 6 + 595
605 = 1 + 253 + 351
606 = 1 + 10 + 595
607 = 1 + 45 + 561
608 = 3 + 10 + 595
609 = 3 + 45 + 561
610 = 1 + 231 + 378
611 = 1 + 15 + 595
612 = 3 + 231 + 378
613 = 3 + 15 + 595
614 = 10 + 253 + 351
615 = 6 + 231 + 378
616 = 6 + 15 + 595
617 = 1 + 21 + 595
618 = 21 + 36 + 561
619 = 1 + 153 + 465
620 = 1 + 91 + 528
621 = 3 + 153 + 465
622 = 3 + 91 + 528
623 = 36 + 91 + 496
624 = 1 + 28 + 595
625 = 6 + 91 + 528
626 = 1 + 190 + 435
627 = 21 + 45 + 561
628 = 1 + 66 + 561
629 = 6 + 28 + 595
630 = 3 + 66 + 561
631 = 6 + 190 + 435
632 = 1 + 1 + 630
633 = 1 + 136 + 496
634 = 1 + 3 + 630
635 = 3 + 136 + 496
636 = 3 + 3 + 630
637 = 1 + 6 + 630
638 = 1 + 231 + 406
639 = 3 + 6 + 630
640 = 1 + 78 + 561
641 = 1 + 10 + 630
642 = 3 + 78 + 561
643 = 3 + 10 + 630
644 = 21 + 28 + 595
645 = 6 + 78 + 561
646 = 1 + 15 + 630
647 = 10 + 231 + 406
648 = 3 + 15 + 630
649 = 1 + 120 + 528
650 = 1 + 153 + 496
651 = 1 + 55 + 595
652 = 1 + 21 + 630
653 = 1 + 91 + 561
654 = 3 + 21 + 630
655 = 1 + 276 + 378
656 = 1 + 190 + 465
657 = 3 + 276 + 378
658 = 3 + 190 + 465
659 = 1 + 28 + 630
660 = 1 + 253 + 406
661 = 3 + 28 + 630
662 = 1 + 66 + 595
663 = 15 + 120 + 528
664 = 3 + 66 + 595
665 = 1 + 136 + 528
666 = 15 + 21 + 630
667 = 1 + 36 + 630
668 = 1 + 1 + 666
669 = 3 + 36 + 630
670 = 1 + 3 + 666
671 = 10 + 66 + 595
672 = 3 + 3 + 666
673 = 1 + 6 + 666
674 = 1 + 78 + 595
675 = 3 + 6 + 666
676 = 1 + 45 + 630
677 = 1 + 10 + 666
678 = 3 + 45 + 630
679 = 1 + 300 + 378
680 = 21 + 253 + 406
681 = 3 + 300 + 378
682 = 1 + 15 + 666
683 = 1 + 276 + 406
684 = 3 + 15 + 666
685 = 3 + 276 + 406
686 = 1 + 55 + 630
687 = 1 + 91 + 595
688 = 1 + 21 + 666
689 = 1 + 253 + 435
690 = 3 + 21 + 666
691 = 3 + 253 + 435
692 = 6 + 91 + 595
693 = 6 + 21 + 666
694 = 6 + 253 + 435
695 = 1 + 28 + 666
696 = 10 + 91 + 595
697 = 1 + 66 + 630
698 = 1 + 136 + 561
699 = 3 + 66 + 630
700 = 1 + 171 + 528
701 = 1 + 105 + 595
702 = 3 + 171 + 528
703 = 1 + 36 + 666
704 = 1 + 325 + 378
705 = 1 + 1 + 703
706 = 3 + 325 + 378
707 = 1 + 3 + 703
708 = 6 + 36 + 666
709 = 1 + 78 + 630
710 = 1 + 6 + 703
711 = 3 + 78 + 630
712 = 1 + 45 + 666
713 = 10 + 325 + 378
714 = 1 + 10 + 703
715 = 1 + 153 + 561
716 = 1 + 120 + 595
717 = 3 + 153 + 561
718 = 3 + 120 + 595
719 = 1 + 15 + 703
720 = 6 + 153 + 561
721 = 3 + 15 + 703
722 = 1 + 55 + 666
723 = 10 + 10 + 703
724 = 3 + 55 + 666
725 = 1 + 21 + 703
726 = 15 + 45 + 666
727 = 3 + 21 + 703
728 = 1 + 231 + 496
729 = 15 + 153 + 561
730 = 1 + 351 + 378
731 = 10 + 55 + 666
732 = 1 + 28 + 703
733 = 1 + 66 + 666
734 = 3 + 28 + 703
735 = 3 + 66 + 666
736 = 1 + 105 + 630
737 = 6 + 28 + 703
738 = 3 + 105 + 630
739 = 1 + 210 + 528
740 = 1 + 36 + 703
741 = 3 + 210 + 528
742 = 1 + 276 + 465
743 = 1 + 1 + 741
744 = 3 + 276 + 465
745 = 1 + 3 + 741
746 = 15 + 28 + 703
747 = 3 + 3 + 741
748 = 1 + 6 + 741
749 = 1 + 45 + 703
750 = 1 + 253 + 496
751 = 1 + 120 + 630
752 = 1 + 10 + 741
753 = 3 + 120 + 630
754 = 3 + 10 + 741
755 = 6 + 253 + 496
756 = 6 + 120 + 630
757 = 1 + 15 + 741
758 = 1 + 91 + 666
759 = 1 + 55 + 703
760 = 1 + 231 + 528
761 = 1 + 325 + 435
762 = 3 + 231 + 528
763 = 1 + 21 + 741
764 = 6 + 55 + 703
765 = 3 + 21 + 741
766 = 1 + 300 + 465
767 = 1 + 136 + 630
768 = 3 + 300 + 465
769 = 3 + 136 + 630
770 = 1 + 28 + 741
771 = 6 + 300 + 465
772 = 1 + 105 + 666
773 = 1 + 276 + 496
774 = 3 + 105 + 666
775 = 3 + 276 + 496
776 = 10 + 136 + 630
777 = 6 + 105 + 666
778 = 1 + 36 + 741
779 = 10 + 28 + 741
780 = 3 + 36 + 741
781 = 10 + 105 + 666
782 = 1 + 1 + 780
783 = 6 + 36 + 741
784 = 1 + 3 + 780
785 = 1 + 378 + 406
786 = 1 + 190 + 595
787 = 1 + 6 + 780
788 = 3 + 190 + 595
789 = 3 + 6 + 780
790 = 6 + 378 + 406
791 = 1 + 10 + 780
792 = 6 + 6 + 780
793 = 1 + 231 + 561
794 = 10 + 378 + 406
795 = 1 + 91 + 703
796 = 1 + 15 + 780
797 = 1 + 55 + 741
798 = 3 + 15 + 780
799 = 3 + 55 + 741
800 = 6 + 91 + 703
801 = 6 + 15 + 780
802 = 1 + 21 + 780
803 = 1 + 136 + 666
804 = 3 + 21 + 780
805 = 1 + 276 + 528
806 = 1 + 210 + 595
807 = 3 + 276 + 528
808 = 1 + 66 + 741
809 = 1 + 28 + 780
810 = 3 + 66 + 741
811 = 3 + 28 + 780
812 = 10 + 136 + 666
813 = 1 + 406 + 406
814 = 1 + 378 + 435
815 = 1 + 253 + 561
816 = 3 + 378 + 435
817 = 1 + 36 + 780
818 = 6 + 406 + 406
819 = 3 + 36 + 780
820 = 1 + 78 + 741
821 = 1 + 190 + 630
822 = 1 + 1 + 820
823 = 3 + 190 + 630
824 = 1 + 3 + 820
825 = 6 + 78 + 741
826 = 1 + 45 + 780
827 = 1 + 6 + 820
828 = 3 + 45 + 780
829 = 1 + 300 + 528
830 = 10 + 190 + 630
831 = 1 + 10 + 820
832 = 6 + 6 + 820
833 = 1 + 91 + 741
834 = 6 + 300 + 528
835 = 3 + 91 + 741
836 = 1 + 15 + 820
837 = 21 + 36 + 780
838 = 1 + 171 + 666
839 = 45 + 91 + 703
840 = 1 + 136 + 703
841 = 1 + 210 + 630
842 = 1 + 21 + 820
843 = 3 + 210 + 630
844 = 1 + 378 + 465
845 = 6 + 136 + 703
846 = 3 + 378 + 465
847 = 1 + 66 + 780
848 = 1 + 351 + 496
849 = 1 + 28 + 820
850 = 3 + 351 + 496
851 = 3 + 28 + 820
852 = 6 + 66 + 780
853 = 6 + 351 + 496
854 = 1 + 325 + 528
855 = 15 + 210 + 630
856 = 3 + 325 + 528
857 = 1 + 36 + 820
858 = 10 + 28 + 820
859 = 1 + 78 + 780
860 = 21 + 136 + 703
861 = 3 + 78 + 780
862 = 1 + 120 + 741
863 = 1 + 1 + 861
864 = 3 + 120 + 741
865 = 1 + 3 + 861
866 = 1 + 45 + 820
867 = 3 + 3 + 861
868 = 1 + 6 + 861
869 = 21 + 28 + 820
870 = 3 + 6 + 861
871 = 1 + 435 + 435
872 = 1 + 10 + 861
873 = 3 + 435 + 435
874 = 3 + 10 + 861
875 = 1 + 171 + 703
876 = 1 + 55 + 820
877 = 1 + 15 + 861
878 = 1 + 136 + 741
879 = 3 + 15 + 861
880 = 1 + 351 + 528
881 = 6 + 55 + 820
882 = 3 + 351 + 528
883 = 1 + 21 + 861
884 = 1 + 253 + 630
885 = 3 + 21 + 861
886 = 1 + 105 + 780
887 = 1 + 66 + 820
888 = 3 + 105 + 780
889 = 3 + 66 + 820
890 = 1 + 28 + 861
891 = 6 + 105 + 780
892 = 3 + 28 + 861
893 = 10 + 253 + 630
894 = 1 + 190 + 703
895 = 1 + 153 + 741
896 = 1 + 300 + 595
897 = 3 + 153 + 741
898 = 1 + 36 + 861
899 = 1 + 78 + 820
900 = 3 + 36 + 861
901 = 1 + 120 + 780
902 = 28 + 171 + 703
903 = 1 + 406 + 496
904 = 6 + 78 + 820
905 = 1 + 1 + 903
906 = 6 + 120 + 780
907 = 1 + 3 + 903
908 = 6 + 406 + 496
909 = 3 + 3 + 903
910 = 1 + 6 + 903
911 = 28 + 253 + 630
912 = 1 + 91 + 820
913 = 1 + 171 + 741
914 = 1 + 10 + 903
915 = 3 + 171 + 741
916 = 3 + 10 + 903
917 = 1 + 55 + 861
918 = 6 + 171 + 741
919 = 1 + 15 + 903
920 = 1 + 253 + 666
921 = 1 + 325 + 595
922 = 3 + 253 + 666
923 = 3 + 325 + 595
924 = 6 + 15 + 903
925 = 1 + 21 + 903
926 = 1 + 105 + 820
927 = 3 + 21 + 903
928 = 1 + 66 + 861
929 = 10 + 253 + 666
930 = 3 + 66 + 861
931 = 1 + 300 + 630
932 = 1 + 28 + 903
933 = 3 + 300 + 630
934 = 1 + 153 + 780
935 = 1 + 231 + 703
936 = 3 + 153 + 780
937 = 3 + 231 + 703
938 = 36 + 406 + 496
939 = 6 + 153 + 780
940 = 1 + 36 + 903
941 = 1 + 120 + 820
942 = 3 + 36 + 903
943 = 1 + 276 + 666
944 = 10 + 231 + 703
945 = 3 + 276 + 666
946 = 6 + 120 + 820
947 = 1 + 351 + 595
948 = 1 + 1 + 946
949 = 1 + 45 + 903
950 = 1 + 3 + 946
951 = 3 + 45 + 903
952 = 1 + 171 + 780
953 = 1 + 6 + 946
954 = 3 + 171 + 780
955 = 3 + 6 + 946
956 = 1 + 325 + 630
957 = 1 + 10 + 946
958 = 3 + 325 + 630
959 = 1 + 55 + 903
960 = 21 + 36 + 903
961 = 3 + 55 + 903
962 = 1 + 15 + 946
963 = 15 + 45 + 903
964 = 1 + 435 + 528
965 = 10 + 325 + 630
966 = 3 + 435 + 528
967 = 1 + 105 + 861
968 = 1 + 21 + 946
969 = 3 + 105 + 861
970 = 1 + 66 + 903
971 = 1 + 190 + 780
972 = 3 + 66 + 903
973 = 1 + 231 + 741
974 = 1 + 153 + 820
975 = 1 + 28 + 946
976 = 3 + 153 + 820
977 = 3 + 28 + 946
978 = 6 + 231 + 741
979 = 6 + 153 + 820
980 = 1 + 276 + 703
981 = 15 + 105 + 861
982 = 1 + 78 + 903
983 = 1 + 36 + 946
984 = 3 + 78 + 903
985 = 3 + 36 + 946
986 = 28 + 55 + 903
987 = 6 + 78 + 903
988 = 6 + 36 + 946
989 = 10 + 276 + 703
990 = 21 + 66 + 903
991 = 1 + 210 + 780
992 = 1 + 1 + 990
993 = 1 + 496 + 496
994 = 1 + 3 + 990
995 = 1 + 91 + 903
996 = 3 + 3 + 990
997 = 1 + 6 + 990
998 = 1 + 136 + 861
999 = 3 + 6 + 990
1000 = 3 + 136 + 861

map<int, string> m1;


for (int i = 0; i < triangleNums.size(); i++)
    {
    for (int j = 0; j < triangleNums.size(); j++)
    {
        for (int k = 0; k < triangleNums.size(); k++)
        {
            int key = triangleNums[i] + triangleNums[j] + triangleNums[k];
            string firstNum = to_string(triangleNums[i]);
            string secondNum = to_string(triangleNums[j]);
            string thirdNum = to_string(triangleNums[k]);
        
            string value = to_string(key) + " = " + firstNum + " + " + secondNum + " + " + thirdNum + "\n";
            
            m1.insert(pair<int, string>(key, value));
        }
    }
}

for(int n = 1; n < 1001; n++) {
    bool istrue = false;
    for(map<int,string>::iterator it = m1.begin(); it != m1.end(); it++) {    
        if(n == it->first)
        {
            cout << it->second;
            istrue = true;
        }
    }
    if(!istrue) {
        cout << n << " = " << endl;
    }
}
*/