/*
 * =================================================================
 *
 *       Filename:  smart_mtp_2p2_gamma.h
 *
 *    Description:  Smart dimming algorithm implementation
 *
 *        Author: jb09.kim
 *        Company:  Samsung Electronics
 *
 * ================================================================
 */
/*
<one line to give the program's name and a brief idea of what it does.>
Copyright (C) 2014, Samsung Electronics. All rights reserved.

*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
*/

#ifndef _SMART_MTP_2P2_GAMMA_H_
#define _SMART_MTP_2P2_GAMMA_H_

/*
*		index : 0 ~ 255
*		((index/255)^2.2)*16384
*/
int candela_coeff_2p2[] = {
0,
0,
0,
1,
2,
3,
4,
6,
8,
10,
13,
16,
20,
23,
28,
32,
37,
42,
48,
54,
61,
67,
75,
82,
90,
99,
108,
117,
127,
137,
148,
159,
170,
182,
195,
207,
221,
234,
249,
263,
278,
294,
310,
326,
343,
361,
379,
397,
416,
435,
455,
475,
496,
517,
539,
561,
584,
607,
630,
654,
679,
704,
730,
756,
783,
810,
838,
866,
894,
924,
953,
984,
1014,
1046,
1077,
1110,
1142,
1176,
1210,
1244,
1279,
1314,
1350,
1387,
1424,
1461,
1499,
1538,
1577,
1617,
1657,
1698,
1739,
1781,
1824,
1866,
1910,
1954,
1999,
2044,
2089,
2136,
2182,
2230,
2278,
2326,
2375,
2425,
2475,
2526,
2577,
2629,
2681,
2734,
2788,
2842,
2896,
2951,
3007,
3064,
3121,
3178,
3236,
3295,
3354,
3414,
3474,
3535,
3597,
3659,
3721,
3785,
3849,
3913,
3978,
4044,
4110,
4177,
4244,
4312,
4380,
4450,
4519,
4590,
4660,
4732,
4804,
4877,
4950,
5024,
5098,
5173,
5249,
5325,
5402,
5480,
5558,
5637,
5716,
5796,
5876,
5957,
6039,
6121,
6204,
6288,
6372,
6457,
6542,
6628,
6715,
6802,
6890,
6978,
7067,
7157,
7247,
7338,
7429,
7522,
7614,
7708,
7802,
7896,
7992,
8087,
8184,
8281,
8379,
8477,
8576,
8676,
8776,
8877,
8978,
9080,
9183,
9287,
9391,
9495,
9601,
9707,
9813,
9920,
10028,
10137,
10246,
10355,
10466,
10577,
10688,
10801,
10914,
11027,
11141,
11256,
11372,
11488,
11605,
11722,
11840,
11959,
12078,
12198,
12319,
12440,
12562,
12685,
12808,
12932,
13057,
13182,
13308,
13434,
13561,
13689,
13818,
13947,
14077,
14207,
14338,
14470,
14602,
14736,
14869,
15004,
15139,
15274,
15411,
15548,
15686,
15824,
15963,
16103,
16243,
16384,
};

/*
*		index : 0 ~ 255
*		((index/255)^2.15)*16384
*/
int candela_coeff_2p15[] = {
0 ,
0 ,
0 ,
1 ,
2 ,
3 ,
5 ,
7 ,
10 ,
12 ,
16 ,
19 ,
23 ,
27 ,
32 ,
37 ,
43 ,
49 ,
55 ,
62 ,
69 ,
76 ,
84 ,
93 ,
102 ,
111 ,
121 ,
131 ,
142 ,
153 ,
165 ,
177 ,
189 ,
202 ,
215 ,
229 ,
243 ,
258 ,
273 ,
289 ,
305 ,
322 ,
339 ,
357 ,
375 ,
393 ,
412 ,
432 ,
452 ,
472 ,
493 ,
515 ,
537 ,
559 ,
582 ,
606 ,
629 ,
654 ,
679 ,
704 ,
730 ,
757 ,
783 ,
811 ,
839 ,
867 ,
896 ,
926 ,
956 ,
986 ,
1017 ,
1048 ,
1080 ,
1113 ,
1146 ,
1180 ,
1214 ,
1248 ,
1283 ,
1319 ,
1355 ,
1392 ,
1429 ,
1467 ,
1505 ,
1544 ,
1583 ,
1623 ,
1663 ,
1704 ,
1746 ,
1788 ,
1830 ,
1873 ,
1917 ,
1961 ,
2006 ,
2051 ,
2096 ,
2143 ,
2190 ,
2237 ,
2285 ,
2333 ,
2382 ,
2432 ,
2482 ,
2532 ,
2584 ,
2635 ,
2688 ,
2740 ,
2794 ,
2848 ,
2902 ,
2957 ,
3013 ,
3069 ,
3125 ,
3183 ,
3240 ,
3299 ,
3358 ,
3417 ,
3477 ,
3538 ,
3599 ,
3660 ,
3723 ,
3786 ,
3849 ,
3913 ,
3977 ,
4042 ,
4108 ,
4174 ,
4241 ,
4308 ,
4376 ,
4445 ,
4514 ,
4583 ,
4653 ,
4724 ,
4796 ,
4867 ,
4940 ,
5013 ,
5087 ,
5161 ,
5235 ,
5311 ,
5387 ,
5463 ,
5540 ,
5618 ,
5696 ,
5775 ,
5854 ,
5934 ,
6015 ,
6096 ,
6178 ,
6260 ,
6343 ,
6426 ,
6510 ,
6595 ,
6680 ,
6766 ,
6852 ,
6939 ,
7027 ,
7115 ,
7203 ,
7293 ,
7383 ,
7473 ,
7564 ,
7656 ,
7748 ,
7841 ,
7934 ,
8028 ,
8123 ,
8218 ,
8314 ,
8410 ,
8507 ,
8605 ,
8703 ,
8802 ,
8901 ,
9001 ,
9102 ,
9203 ,
9305 ,
9407 ,
9510 ,
9614 ,
9718 ,
9823 ,
9928 ,
10034 ,
10141 ,
10248 ,
10356 ,
10464 ,
10573 ,
10683 ,
10793 ,
10903 ,
11015 ,
11127 ,
11240 ,
11353 ,
11467 ,
11581 ,
11696 ,
11812 ,
11928 ,
12045 ,
12162 ,
12280 ,
12399 ,
12518 ,
12638 ,
12759 ,
12880 ,
13002 ,
13124 ,
13247 ,
13371 ,
13495 ,
13620 ,
13745 ,
13871 ,
13998 ,
14125 ,
14253 ,
14382 ,
14511 ,
14641 ,
14771 ,
14902 ,
15034 ,
15166 ,
15299 ,
15432 ,
15566 ,
15701 ,
15836 ,
15972 ,
16109 ,
16246 ,
16384 ,
};

/*
*		index : 0 ~ 255
*		((index/255)^2.1)*16384
*/
int candela_coeff_2p1[] = {
0 ,
0 ,
1 ,
1 ,
3 ,
4 ,
6 ,
9 ,
11 ,
15 ,
18 ,
22 ,
27 ,
32 ,
37 ,
43 ,
49 ,
56 ,
63 ,
70 ,
78 ,
87 ,
95 ,
105 ,
115 ,
125 ,
136 ,
147 ,
158 ,
170 ,
183 ,
196 ,
210 ,
224 ,
238 ,
253 ,
268 ,
284 ,
301 ,
318 ,
335 ,
353 ,
371 ,
390 ,
409 ,
429 ,
449 ,
470 ,
491 ,
513 ,
535 ,
558 ,
581 ,
605 ,
629 ,
654 ,
679 ,
705 ,
731 ,
758 ,
785 ,
813 ,
841 ,
870 ,
899 ,
929 ,
959 ,
990 ,
1021 ,
1053 ,
1085 ,
1118 ,
1151 ,
1185 ,
1219 ,
1254 ,
1289 ,
1325 ,
1362 ,
1399 ,
1436 ,
1474 ,
1512 ,
1551 ,
1591 ,
1631 ,
1672 ,
1713 ,
1754 ,
1796 ,
1839 ,
1882 ,
1926 ,
1970 ,
2015 ,
2060 ,
2106 ,
2152 ,
2199 ,
2247 ,
2294 ,
2343 ,
2392 ,
2441 ,
2491 ,
2542 ,
2593 ,
2645 ,
2697 ,
2750 ,
2803 ,
2857 ,
2911 ,
2966 ,
3021 ,
3077 ,
3134 ,
3191 ,
3248 ,
3306 ,
3365 ,
3424 ,
3484 ,
3544 ,
3605 ,
3666 ,
3728 ,
3790 ,
3853 ,
3917 ,
3981 ,
4045 ,
4110 ,
4176 ,
4242 ,
4309 ,
4376 ,
4444 ,
4513 ,
4582 ,
4651 ,
4721 ,
4792 ,
4863 ,
4935 ,
5007 ,
5080 ,
5153 ,
5227 ,
5301 ,
5376 ,
5452 ,
5528 ,
5605 ,
5682 ,
5759 ,
5838 ,
5917 ,
5996 ,
6076 ,
6157 ,
6238 ,
6319 ,
6401 ,
6484 ,
6568 ,
6651 ,
6736 ,
6821 ,
6906 ,
6992 ,
7079 ,
7166 ,
7254 ,
7342 ,
7431 ,
7521 ,
7611 ,
7701 ,
7793 ,
7884 ,
7976 ,
8069 ,
8163 ,
8257 ,
8351 ,
8446 ,
8542 ,
8638 ,
8735 ,
8832 ,
8930 ,
9029 ,
9128 ,
9227 ,
9327 ,
9428 ,
9529 ,
9631 ,
9734 ,
9837 ,
9940 ,
10044 ,
10149 ,
10254 ,
10360 ,
10467 ,
10574 ,
10681 ,
10789 ,
10898 ,
11007 ,
11117 ,
11227 ,
11338 ,
11450 ,
11562 ,
11675 ,
11788 ,
11902 ,
12016 ,
12131 ,
12247 ,
12363 ,
12480 ,
12597 ,
12715 ,
12833 ,
12952 ,
13072 ,
13192 ,
13313 ,
13434 ,
13556 ,
13679 ,
13802 ,
13925 ,
14049 ,
14174 ,
14300 ,
14425 ,
14552 ,
14679 ,
14807 ,
14935 ,
15064 ,
15193 ,
15323 ,
15454 ,
15585 ,
15717 ,
15849 ,
15982 ,
16115 ,
16249 ,
16384 ,
};

/*
*		index : 0 ~ 255
*		300 is max CANDELA
*		(300*((index/255)^2.2))*16384
*/

int curve_2p2[] = {
0 ,
25 ,
115 ,
280 ,
528 ,
862 ,
1287 ,
1807 ,
2424 ,
3141 ,
3960 ,
4884 ,
5915 ,
7054 ,
8303 ,
9663 ,
11138 ,
12727 ,
14432 ,
16255 ,
18197 ,
20259 ,
22442 ,
24748 ,
27177 ,
29730 ,
32410 ,
35215 ,
38149 ,
41210 ,
44402 ,
47723 ,
51175 ,
54760 ,
58477 ,
62328 ,
66313 ,
70433 ,
74689 ,
79081 ,
83611 ,
88279 ,
93085 ,
98031 ,
103116 ,
108343 ,
113710 ,
119219 ,
124871 ,
130666 ,
136605 ,
142687 ,
148915 ,
155288 ,
161807 ,
168473 ,
175285 ,
182245 ,
189353 ,
196610 ,
204016 ,
211571 ,
219277 ,
227133 ,
235140 ,
243299 ,
251610 ,
260073 ,
268690 ,
277459 ,
286383 ,
295461 ,
304693 ,
314081 ,
323624 ,
333324 ,
343180 ,
353192 ,
363362 ,
373690 ,
384175 ,
394819 ,
405622 ,
416585 ,
427707 ,
438988 ,
450431 ,
462034 ,
473798 ,
485724 ,
497812 ,
510061 ,
522474 ,
535049 ,
547788 ,
560691 ,
573757 ,
586988 ,
600384 ,
613944 ,
627670 ,
641562 ,
655619 ,
669844 ,
684234 ,
698792 ,
713517 ,
728410 ,
743470 ,
758699 ,
774097 ,
789663 ,
805399 ,
821304 ,
837379 ,
853624 ,
870040 ,
886626 ,
903383 ,
920311 ,
937411 ,
954683 ,
972127 ,
989744 ,
1007533 ,
1025495 ,
1043630 ,
1061939 ,
1080422 ,
1099079 ,
1117910 ,
1136916 ,
1156097 ,
1175452 ,
1194984 ,
1214691 ,
1234574 ,
1254633 ,
1274869 ,
1295281 ,
1315870 ,
1336637 ,
1357581 ,
1378703 ,
1400003 ,
1421481 ,
1443138 ,
1464973 ,
1486987 ,
1509181 ,
1531554 ,
1554106 ,
1576839 ,
1599752 ,
1622845 ,
1646119 ,
1669574 ,
1693210 ,
1717027 ,
1741026 ,
1765206 ,
1789569 ,
1814114 ,
1838841 ,
1863751 ,
1888844 ,
1914120 ,
1939580 ,
1965223 ,
1991050 ,
2017061 ,
2043257 ,
2069636 ,
2096201 ,
2122950 ,
2149885 ,
2177005 ,
2204310 ,
2231801 ,
2259478 ,
2287341 ,
2315391 ,
2343627 ,
2372050 ,
2400660 ,
2429457 ,
2458442 ,
2487614 ,
2516974 ,
2546522 ,
2576258 ,
2606183 ,
2636296 ,
2666598 ,
2697089 ,
2727769 ,
2758639 ,
2789698 ,
2820947 ,
2852386 ,
2884015 ,
2915834 ,
2947844 ,
2980045 ,
3012436 ,
3045019 ,
3077793 ,
3110758 ,
3143915 ,
3177264 ,
3210805 ,
3244538 ,
3278464 ,
3312582 ,
3346893 ,
3381396 ,
3416093 ,
3450984 ,
3486067 ,
3521345 ,
3556816 ,
3592481 ,
3628340 ,
3664394 ,
3700642 ,
3737085 ,
3773723 ,
3810556 ,
3847584 ,
3884808 ,
3922227 ,
3959842 ,
3997652 ,
4035659 ,
4073862 ,
4112262 ,
4150858 ,
4189651 ,
4228641 ,
4267827 ,
4307212 ,
4346793 ,
4386572 ,
4426549 ,
4466724 ,
4507096 ,
4547668 ,
4588437 ,
4629405 ,
4670572 ,
4711937 ,
4753502 ,
4795266 ,
4837229 ,
4879391 ,
4921754 ,
};

/*
*		index : 0 ~ 255
*		300 is max CANDELA
*		(300*((index/255)^2.15))*16384
*/

int curve_2p15[] = {
0 ,
33 ,
146 ,
349 ,
648 ,
1048 ,
1551 ,
2160 ,
2878 ,
3708 ,
4650 ,
5708 ,
6882 ,
8174 ,
9586 ,
11119 ,
12774 ,
14553 ,
16456 ,
18484 ,
20639 ,
22922 ,
25333 ,
27874 ,
30545 ,
33347 ,
36280 ,
39347 ,
42547 ,
45881 ,
49350 ,
52955 ,
56696 ,
60574 ,
64589 ,
68743 ,
73035 ,
77466 ,
82038 ,
86750 ,
91603 ,
96597 ,
101734 ,
107013 ,
112435 ,
118001 ,
123711 ,
129566 ,
135565 ,
141710 ,
148001 ,
154439 ,
161023 ,
167754 ,
174633 ,
181660 ,
188836 ,
196160 ,
203634 ,
211257 ,
219031 ,
226955 ,
235029 ,
243255 ,
251633 ,
260162 ,
268843 ,
277677 ,
286665 ,
295805 ,
305099 ,
314547 ,
324149 ,
333906 ,
343818 ,
353884 ,
364107 ,
374485 ,
385020 ,
395711 ,
406559 ,
417564 ,
428726 ,
440046 ,
451523 ,
463159 ,
474954 ,
486907 ,
499020 ,
511291 ,
523722 ,
536314 ,
549065 ,
561976 ,
575049 ,
588282 ,
601676 ,
615232 ,
628950 ,
642829 ,
656871 ,
671075 ,
685441 ,
699971 ,
714663 ,
729519 ,
744539 ,
759722 ,
775070 ,
790582 ,
806258 ,
822099 ,
838105 ,
854276 ,
870613 ,
887115 ,
903784 ,
920618 ,
937618 ,
954785 ,
972119 ,
989620 ,
1007287 ,
1025123 ,
1043125 ,
1061296 ,
1079634 ,
1098140 ,
1116815 ,
1135658 ,
1154670 ,
1173851 ,
1193201 ,
1212721 ,
1232410 ,
1252268 ,
1272297 ,
1292495 ,
1312864 ,
1333404 ,
1354114 ,
1374994 ,
1396046 ,
1417269 ,
1438663 ,
1460229 ,
1481967 ,
1503876 ,
1525958 ,
1548211 ,
1570638 ,
1593236 ,
1616008 ,
1638953 ,
1662070 ,
1685361 ,
1708825 ,
1732463 ,
1756275 ,
1780261 ,
1804421 ,
1828755 ,
1853263 ,
1877946 ,
1902804 ,
1927837 ,
1953045 ,
1978428 ,
2003986 ,
2029720 ,
2055630 ,
2081716 ,
2107977 ,
2134415 ,
2161029 ,
2187820 ,
2214787 ,
2241931 ,
2269252 ,
2296751 ,
2324426 ,
2352279 ,
2380309 ,
2408517 ,
2436902 ,
2465466 ,
2494208 ,
2523128 ,
2552226 ,
2581503 ,
2610959 ,
2640593 ,
2670407 ,
2700400 ,
2730571 ,
2760923 ,
2791453 ,
2822164 ,
2853054 ,
2884124 ,
2915374 ,
2946805 ,
2978415 ,
3010206 ,
3042178 ,
3074331 ,
3106664 ,
3139179 ,
3171874 ,
3204751 ,
3237809 ,
3271049 ,
3304471 ,
3338074 ,
3371859 ,
3405826 ,
3439976 ,
3474307 ,
3508821 ,
3543518 ,
3578397 ,
3613460 ,
3648705 ,
3684133 ,
3719744 ,
3755539 ,
3791516 ,
3827678 ,
3864023 ,
3900552 ,
3937265 ,
3974162 ,
4011243 ,
4048508 ,
4085958 ,
4123592 ,
4161411 ,
4199415 ,
4237603 ,
4275976 ,
4314535 ,
4353278 ,
4392207 ,
4431322 ,
4470622 ,
4510107 ,
4549779 ,
4589636 ,
4629679 ,
4669909 ,
4710324 ,
4750926 ,
4791715 ,
4832690 ,
4873852 ,
4915200 ,
};

/*
*		index : 0 ~ 255
*		300 is max CANDELA
*		(300*((index/255)^2.1))*16384
*/

int curve_2p1[] = {
0 ,
43 ,
186 ,
436 ,
798 ,
1275 ,
1870 ,
2585 ,
3422 ,
4382 ,
5468 ,
6679 ,
8018 ,
9486 ,
11083 ,
12811 ,
14671 ,
16663 ,
18788 ,
21047 ,
23441 ,
25970 ,
28635 ,
31437 ,
34376 ,
37453 ,
40668 ,
44022 ,
47516 ,
51150 ,
54924 ,
58839 ,
62896 ,
67094 ,
71435 ,
75919 ,
80546 ,
85316 ,
90230 ,
95289 ,
100492 ,
105841 ,
111335 ,
116974 ,
122760 ,
128692 ,
134772 ,
140998 ,
147371 ,
153893 ,
160562 ,
167380 ,
174347 ,
181462 ,
188727 ,
196141 ,
203705 ,
211419 ,
219283 ,
227298 ,
235464 ,
243781 ,
252249 ,
260869 ,
269640 ,
278564 ,
287640 ,
296868 ,
306250 ,
315784 ,
325471 ,
335312 ,
345307 ,
355455 ,
365758 ,
376214 ,
386826 ,
397592 ,
408513 ,
419589 ,
430820 ,
442207 ,
453749 ,
465448 ,
477302 ,
489313 ,
501480 ,
513804 ,
526284 ,
538922 ,
551717 ,
564669 ,
577778 ,
591046 ,
604471 ,
618054 ,
631795 ,
645695 ,
659753 ,
673970 ,
688346 ,
702881 ,
717575 ,
732428 ,
747441 ,
762613 ,
777945 ,
793438 ,
809090 ,
824902 ,
840875 ,
857008 ,
873302 ,
889757 ,
906373 ,
923150 ,
940088 ,
957188 ,
974449 ,
991872 ,
1009456 ,
1027203 ,
1045111 ,
1063182 ,
1081415 ,
1099810 ,
1118369 ,
1137089 ,
1155973 ,
1175020 ,
1194230 ,
1213603 ,
1233139 ,
1252839 ,
1272702 ,
1292730 ,
1312921 ,
1333276 ,
1353795 ,
1374478 ,
1395326 ,
1416338 ,
1437515 ,
1458856 ,
1480362 ,
1502034 ,
1523870 ,
1545871 ,
1568037 ,
1590369 ,
1612867 ,
1635530 ,
1658358 ,
1681353 ,
1704513 ,
1727839 ,
1751332 ,
1774991 ,
1798816 ,
1822807 ,
1846965 ,
1871290 ,
1895782 ,
1920440 ,
1945266 ,
1970258 ,
1995418 ,
2020744 ,
2046239 ,
2071900 ,
2097730 ,
2123727 ,
2149892 ,
2176224 ,
2202725 ,
2229393 ,
2256230 ,
2283235 ,
2310409 ,
2337751 ,
2365261 ,
2392940 ,
2420788 ,
2448804 ,
2476990 ,
2505344 ,
2533868 ,
2562561 ,
2591423 ,
2620454 ,
2649655 ,
2679026 ,
2708566 ,
2738276 ,
2768155 ,
2798205 ,
2828424 ,
2858814 ,
2889374 ,
2920104 ,
2951004 ,
2982075 ,
3013316 ,
3044728 ,
3076310 ,
3108064 ,
3139988 ,
3172083 ,
3204349 ,
3236786 ,
3269395 ,
3302174 ,
3335125 ,
3368247 ,
3401541 ,
3435007 ,
3468644 ,
3502453 ,
3536433 ,
3570586 ,
3604910 ,
3639407 ,
3674075 ,
3708916 ,
3743929 ,
3779115 ,
3814473 ,
3850003 ,
3885706 ,
3921582 ,
3957631 ,
3993852 ,
4030246 ,
4066813 ,
4103554 ,
4140467 ,
4177554 ,
4214813 ,
4252246 ,
4289853 ,
4327633 ,
4365587 ,
4403714 ,
4442015 ,
4480489 ,
4519138 ,
4557960 ,
4596957 ,
4636127 ,
4675472 ,
4714991 ,
4754684 ,
4794551 ,
4834593 ,
4874809 ,
4915200 ,
};

int s6e63m0_candela_coeff[] = {
0 ,
0 ,
0 ,
0 ,
0 ,
0 ,
0 ,
0 ,
0 ,
0 ,
0 ,
0 ,
1 ,
1 ,
1 ,
2 ,
2 ,
3 ,
4 ,
5 ,
6 ,
8 ,
11 ,
13 ,
16 ,
20 ,
24 ,
29 ,
35 ,
41 ,
49 ,
58 ,
67 ,
78 ,
89 ,
103 ,
118 ,
135 ,
153 ,
173 ,
199 ,
223 ,
238 ,
252 ,
272 ,
291 ,
308 ,
326 ,
340 ,
360 ,
382 ,
402 ,
419 ,
443 ,
467 ,
494 ,
516 ,
538 ,
568 ,
592 ,
615 ,
640 ,
670 ,
693 ,
718 ,
748 ,
780 ,
812 ,
836 ,
869 ,
901 ,
929 ,
961 ,
991 ,
1025 ,
1063 ,
1096 ,
1130 ,
1164 ,
1199 ,
1235 ,
1274 ,
1316 ,
1350 ,
1394 ,
1435 ,
1473 ,
1515 ,
1553 ,
1596 ,
1640 ,
1680 ,
1720 ,
1761 ,
1806 ,
1854 ,
1902 ,
1944 ,
1992 ,
2042 ,
2087 ,
2141 ,
2188 ,
2236 ,
2291 ,
2339 ,
2388 ,
2437 ,
2488 ,
2538 ,
2590 ,
2645 ,
2699 ,
2759 ,
2815 ,
2867 ,
2924 ,
2982 ,
3036 ,
3095 ,
3158 ,
3220 ,
3283 ,
3341 ,
3403 ,
3468 ,
3534 ,
3592 ,
3659 ,
3722 ,
3785 ,
3857 ,
3922 ,
3987 ,
4053 ,
4120 ,
4188 ,
4260 ,
4329 ,
4405 ,
4478 ,
4551 ,
4625 ,
4695 ,
4769 ,
4844 ,
4916 ,
4989 ,
5062 ,
5135 ,
5206 ,
5282 ,
5366 ,
5445 ,
5522 ,
5604 ,
5686 ,
5764 ,
5844 ,
5923 ,
6004 ,
6085 ,
6167 ,
6249 ,
6332 ,
6419 ,
6505 ,
6593 ,
6680 ,
6764 ,
6854 ,
6943 ,
7030 ,
7113 ,
7196 ,
7284 ,
7379 ,
7472 ,
7566 ,
7660 ,
7752 ,
7847 ,
7943 ,
8036 ,
8130 ,
8224 ,
8319 ,
8416 ,
8514 ,
8618 ,
8719 ,
8815 ,
8916 ,
9019 ,
9117 ,
9216 ,
9316 ,
9421 ,
9530 ,
9637 ,
9742 ,
9853 ,
9962 ,
10066 ,
10173 ,
10284 ,
10391 ,
10500 ,
10610 ,
10721 ,
10831 ,
10937 ,
11050 ,
11161 ,
11268 ,
11375 ,
11495 ,
11610 ,
11724 ,
11840 ,
11956 ,
12073 ,
12183 ,
12300 ,
12420 ,
12540 ,
12665 ,
12786 ,
12907 ,
13028 ,
13149 ,
13271 ,
13394 ,
13521 ,
13644 ,
13770 ,
13894 ,
14021 ,
14147 ,
14271 ,
14395 ,
14527 ,
14661 ,
14795 ,
14930 ,
15066 ,
15199 ,
15331 ,
15465 ,
15596 ,
15727 ,
15859 ,
15991 ,
16124 ,
16258 ,
16384 ,
};

int s6e63m0_curve_2p2[] = {
0 ,
1 ,
3 ,
7 ,
12 ,
20 ,
30 ,
43 ,
57 ,
74 ,
94 ,
116 ,
181 ,
261 ,
357 ,
470 ,
638 ,
873 ,
1149 ,
1505 ,
1948 ,
2462 ,
3187 ,
4014 ,
4947 ,
5998 ,
7322 ,
8790 ,
10406 ,
12406 ,
14785 ,
17393 ,
20233 ,
23309 ,
26624 ,
30843 ,
35530 ,
40580 ,
45998 ,
51943 ,
59567 ,
66992 ,
71281 ,
75715 ,
81627 ,
87360 ,
92307 ,
97789 ,
101994 ,
107916 ,
114544 ,
120609 ,
125563 ,
132753 ,
139989 ,
148171 ,
154830 ,
161459 ,
170491 ,
177474 ,
184610 ,
191900 ,
200851 ,
208025 ,
215268 ,
224525 ,
233995 ,
243502 ,
250903 ,
260832 ,
270407 ,
278624 ,
288448 ,
297172 ,
307582 ,
318888 ,
328847 ,
338973 ,
349266 ,
359728 ,
370358 ,
382346 ,
394839 ,
405107 ,
418139 ,
430542 ,
442024 ,
454514 ,
466020 ,
478816 ,
491918 ,
503929 ,
516097 ,
528425 ,
541772 ,
556091 ,
570614 ,
583274 ,
597584 ,
612685 ,
626209 ,
642334 ,
656324 ,
670784 ,
687212 ,
701724 ,
716402 ,
731246 ,
746256 ,
761433 ,
776925 ,
793649 ,
809625 ,
827588 ,
844406 ,
860145 ,
877239 ,
894489 ,
910729 ,
928472 ,
947330 ,
966066 ,
985002 ,
1002167 ,
1020903 ,
1040415 ,
1060129 ,
1077595 ,
1097643 ,
1116505 ,
1135562 ,
1157162 ,
1176573 ,
1196160 ,
1215924 ,
1235865 ,
1256295 ,
1278087 ,
1298760 ,
1321576 ,
1343524 ,
1365222 ,
1387352 ,
1408362 ,
1430792 ,
1453323 ,
1474871 ,
1496592 ,
1518486 ,
1540554 ,
1561718 ,
1584466 ,
1609667 ,
1633642 ,
1656693 ,
1681320 ,
1705704 ,
1729303 ,
1753078 ,
1777031 ,
1801161 ,
1825469 ,
1849954 ,
1874618 ,
1899643 ,
1925558 ,
1951427 ,
1977817 ,
2003972 ,
2029340 ,
2056321 ,
2083012 ,
2108920 ,
2133761 ,
2158798 ,
2185215 ,
2213663 ,
2241712 ,
2269787 ,
2298149 ,
2325479 ,
2354122 ,
2383050 ,
2410925 ,
2438977 ,
2467207 ,
2495613 ,
2524928 ,
2554282 ,
2585355 ,
2615560 ,
2644608 ,
2674730 ,
2705583 ,
2735171 ,
2764934 ,
2794872 ,
2826365 ,
2859063 ,
2891124 ,
2922619 ,
2955919 ,
2988470 ,
3019761 ,
3052021 ,
3085226 ,
3117156 ,
3150042 ,
3183115 ,
3216377 ,
3249187 ,
3281038 ,
3314853 ,
3348429 ,
3380335 ,
3412468 ,
3448603 ,
3482883 ,
3517348 ,
3551998 ,
3586833 ,
3621854 ,
3654959 ,
3690035 ,
3725943 ,
3761880 ,
3799549 ,
3835852 ,
3871969 ,
3908271 ,
3944757 ,
3981429 ,
4018286 ,
4056410 ,
4093256 ,
4130995 ,
4168337 ,
4206323 ,
4244164 ,
4281201 ,
4318413 ,
4358189 ,
4398275 ,
4438561 ,
4479048 ,
4519735 ,
4559566 ,
4599306 ,
4639620 ,
4678786 ,
4718131 ,
4757656 ,
4797361 ,
4837246 ,
4877311 ,
4915200 ,
};
#endif /* START_MTP_2P2_GAMMA_H */