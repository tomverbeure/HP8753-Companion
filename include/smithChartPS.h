/*
 * Copyright (c) 2022 Michael G. Katzmann
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#ifndef SMITHPS_H_
#define SMITHPS_H_
#include <glib-2.0/glib.h>

const char *smithPS = "\
% 18 December 1990 \n \
% Marshall Jose WA3VPZ \n \
% JHU - Applied Physics Laboratory, Laurel, MD \n \
 \
/setGcolor  { 0.3 0.6 0.6 setrgbcolor } def \
/setGcolor  { 0.8 0.3 0.3 setrgbcolor } def \
/setZcolor { 0.2 0.2 0.5 setrgbcolor } def \
/setZcolor { 0.8 0.3 0.3 setrgbcolor } def \
/setLegendCcolor { 0 0 0 setrgbcolor } def \
 \
/isDisplay {  \
  currentpagedevice /Name known { \
    currentpagedevice /Name get dup (display) eq exch (x11alpha) eq or \
  }{  \
    false \
  } ifelse \
} def \
 \
isDisplay { \
    /GrAlpha    4 def \
    /TxAlpha    4 def \
 \
    currentdevice \
    mark /TextAlphaBits TxAlpha /GraphicsAlphaBits GrAlpha 6 -1 roll \
    putdeviceprops pop \
} if \
 \
4.25 72 mul 5.9 72 mul translate  \
  \
/Helvfont {/Helvetica findfont 5 scalefont setfont} def Helvfont  \
/Symfont {/Symbol findfont 5 scalefont setfont} def  \
  \
[(0) (0.1) (0.2) (0.3) (0.4) (0.5) (0.6) (0.7) (0.8) (0.9) \
 (1.0) (1.2) (1.4) (1.6) (1.8) (2.0) (3.0) (4.0) (5.0) \
 (10) (20) (50)] /Labels exch def \
[0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.2 1.4 \
 1.6 1.8 2.0 3.0 4.0 5.0 10 20 50] /Lvalues exch def \
[ 0  0.2   0.5   1     2     5    10    20    50 ] /ZRegions exch def \
   [ 0.01  0.02  0.05  0.1   0.2   1     2    10 ] /ZMinordiv exch def \
   [ 5     5     2     2     5     5     5    5  ] /ZMajordiv exch def \
[ 0  1     2     4    10    20    50 ] /YRegions exch def \
   [ 0.1  0.2  0.5     1     5    30 ] /YMinordiv exch def \
   [ 5     5     2     6     2     1 ] /YMajordiv exch def \
/minorinc 0 def \
/majorinc 0 def \
 \
/Unitradius 3.25 72 mul def	\
/Coeffradius 3.375 72 mul def \
/Waveradius  3.625 72 mul def \
 \n \
/RXtoUV { \n \
  /xtmp exch def   /rtmp exch def \n \
  rtmp rtmp mul xtmp xtmp mul add rtmp 2 mul add 1 add /dtmp exch def \n \
  rtmp rtmp mul xtmp xtmp mul add 1 sub dtmp div \n \
  xtmp 2 mul dtmp div \n \
} def \n \
 \n \
/AngR { \n \
  /xa exch def   /ra exch def \n \
  ra xa RXtoUV \n \
  exch ra ra 1 add div sub atan \n \
} def \n \
 \n \
/AngX { \n \
  /xa exch def   /ra exch def \n \
  ra xa RXtoUV \n \
  1 xa div sub exch 1 sub atan \n \
} def \n \
 \n \
/Doarc { \n \
  5 -1 roll Unitradius mul \n \
  5 -1 roll Unitradius mul \n \
  5 -1 roll Unitradius mul \n \
  5 -2 roll \n \
  arc stroke \n \
} def \n \
 \n \
/DrawRarc { \n \
  /xx2 exch def  /xx1 exch def  /rr exch def \n \
 \n \
  rr dup 1 add div /u0 exch def \n \
  /v0 0 def \n \
  1 rr 1 add div /radius exch def \n \
 \n \
  rr xx1 AngR /theta1 exch def \n \
  rr xx2 AngR /theta2 exch def \n \
  u0 v0 radius theta1 theta2 Doarc \n \
} def \n \
 \n \
/DrawXarc { \n \
  /rr2 exch def  /rr1 exch def  /xx exch def \n \
 \n \
  /u0 1 def \n \
  1 xx div /v0 exch def \n \
  1 xx div abs /radius exch def \n \
 \n \
  rr1 xx AngX /theta1 exch def \n \
  rr2 xx AngX /theta2 exch def \n \
  u0 v0 radius theta1 theta2 Doarc \n \
} def \n \
 \n \
/Doblock { \
  /rtics 0 def \
  r1 minorinc add minorinc r2 minorinc 2 div add { \
    /r exch def \
    rtics 1 add dup /rtics exch def \
    majorinc mod 0 eq {0.5 setlinewidth} {0 setlinewidth} ifelse \
    r x2 x1 DrawRarc \
    r x1 neg x2 neg DrawRarc \
  } for \
 \
  /xtics 0 def \
  x1 minorinc add minorinc x2 minorinc 2 div add { \
    /x exch def \
    xtics 1 add dup /xtics exch def \
    majorinc mod 0 eq {0.5 setlinewidth} {0 setlinewidth} ifelse \
    x r1 r2 DrawXarc \
    x neg r2 r1 DrawXarc \
  } for \
} def \
 \
/Doimmittance { \
  /Majordiv exch def  /Minordiv exch def  /Regions exch def \
  0 1 Minordiv length 1 sub {/index exch def \
 \
    Minordiv index get /minorinc exch def \
    Majordiv index get /majorinc exch def \
 \
    0 /r1 exch def \
    Regions index 1 add get /r2 exch def \
    Regions index get /x1 exch def \
    Regions index 1 add get /x2 exch def \
    Doblock \
 \
    Regions index get /r1 exch def \
    Regions index 1 add get /r2 exch def \
    0 /x1 exch def \
    Regions index get /x2 exch def \
    index 7 eq {majorinc 3 def} if \
    Doblock \
  } for \
 \
  0.5 setlinewidth \
  Unitradius neg 0 moveto Unitradius 0 lineto stroke \
  0 0 Unitradius 0 360 arc stroke \
  50 10000 0  DrawRarc \
  50 0 -10000 DrawRarc \
  50 0 10000  DrawXarc \
  -50 10000 0 DrawXarc \
  newpath 0 0 2 0 360 arc \
  currentgray 1 setgray fill setgray 0 setlinewidth \
  0 0 2 0 360 arc stroke \
  0 0 0.25 0 360 arc stroke \
 \
} def \
 \
/Dorightstring { \
  /lab exch def  /yl exch def  /xl exch def \
  lab stringwidth pop /wid exch def \
  newpath  xl yl moveto \
	   wid neg 0 rlineto \
           0 5 rlineto \
           wid 0 rlineto \
           0 -5 rlineto \
  closepath currentgray 1 setgray fill \
  xl yl moveto wid neg 1 rmoveto setgray lab show \
} def \
 \
/Doleftstring { \
  /lab exch def  /yl exch def  /xl exch def \
  lab stringwidth pop /wid exch def \
  newpath  xl yl moveto \
           wid 0 rlineto \
           0 5 rlineto \
           wid neg 0 rlineto \
           0 -5 rlineto \
  closepath currentgray 1 setgray fill \
  xl yl 1 add moveto setgray lab show \
} def \
 \
/DoLabels { \
  1 1 Lvalues length 1 sub { dup \
    Labels exch get /label exch def \
    Lvalues exch get /x exch def \
    0 x RXtoUV exch atan \
    gsave rotate Unitradius 1 sub 1 label Dorightstring grestore \
    0 x neg RXtoUV exch atan 180 add \
    gsave rotate Unitradius 1 sub neg 1 label Doleftstring grestore \
    x 0 RXtoUV pop Unitradius mul neg \
    gsave 90 rotate 1 add 2 exch label Doleftstring grestore \
  } for \
 \
  2 2 10 { dup \
    Labels exch get /label exch def \
    Lvalues exch get /x exch def \
    x 1 RXtoUV Unitradius mul exch Unitradius mul exch \
    gsave translate x 1 AngX 180 add rotate \
          1 1 label Doleftstring grestore \
    x -1 RXtoUV Unitradius mul exch Unitradius mul exch \
    gsave translate x -1 AngX rotate \
          -1 1 label Dorightstring grestore \
    1 x RXtoUV Unitradius mul exch Unitradius mul exch \
    gsave translate 1 x AngR rotate \
          -1 1 label Dorightstring grestore \
    1 x neg RXtoUV Unitradius mul exch Unitradius mul exch \
    gsave translate 1 x neg AngR 180 add rotate \
          1 1 label Doleftstring grestore \
  } for \
 \
} def \
 \
/DoRX { \
  ZRegions ZMinordiv ZMajordiv Doimmittance  DoLabels \
} def \
 \
/DoGB { \
  gsave \
    currentdash  \
    180 rotate \
    YRegions YMinordiv YMajordiv Doimmittance DoLabels \
    setdash \
  grestore \
} def \
 \
/Doperp { \
  gsave rotate 0 translate -90 rotate \
  dup stringwidth pop 2 div neg 0 moveto show grestore \
} def \
 \
/FindTCrad {/th exch def \
  th sin Unitradius mul Coeffradius div \
  dup dup mul neg 1 add sqrt div 1 atan \
  180 th sub exch sub sin Coeffradius mul th sin div \
} def \
 \
/Docoeffcircle { \
  0 setlinewidth 0 setgray \
  0 0 Coeffradius 0 360 arc stroke \
  gsave \
  0 2 178 { pop \
    Coeffradius neg 0 moveto -2 0 rlineto stroke \
    Coeffradius 0 moveto 2 0 rlineto stroke \
    2 rotate \
  } for \
  grestore \
  /str 20 string def \
  20 10 170 { dup dup \
    str cvs exch Coeffradius 3 add exch Doperp \
    neg dup str cvs exch Coeffradius 3 add exch Doperp \
  } for \
  (180) Coeffradius 3 add 180 Doperp \
  Symfont (\\261) Coeffradius 3 add 181.5 Doperp Helvfont \
 \
  gsave Unitradius neg 0 translate \
  90 -1 1 {/thet exch def \
    thet FindTCrad /TCrad exch def \
    gsave thet rotate TCrad 0 moveto -3 0 rlineto stroke \
    thet 10 ge thet 5 mod 0 eq and { \
      TCrad 2 sub -4 moveto thet str cvs \
      dup stringwidth pop neg 0 rmoveto show \
    } if \
    grestore \
    gsave 180 thet sub rotate TCrad neg 0 moveto 3 0 rlineto stroke \
    thet 10 ge thet 5 mod 0 eq and { \
      TCrad neg 1 add -4 moveto thet neg str cvs show \
    } if \
    grestore \
  } for \
  grestore \
  0.5 setlinewidth 0 0 Coeffradius Waveradius add 2 div 0 360 arc stroke \
  0 setlinewidth Coeffradius 3 sub 0 moveto 3 0 rlineto stroke \
} def \
 \
/Dowavecircle { \
  /str 20 string def \
  0 setlinewidth 0 setgray \
  0 0 Waveradius 0 360 arc stroke \
  /lstep 180 125 div def \
  1 1 250 {/ix exch def \
    gsave ix lstep mul rotate \
    Waveradius 2 add neg 0 moveto 4 0 rlineto stroke grestore \
    ix 5 mod 0 eq ix 16 gt and { \
      ix 250 eq {0} {ix} ifelse \
      500 div str cvs dup \
      gsave ix lstep mul rotate Waveradius 7 sub neg 0 translate 90 rotate \
      dup stringwidth pop 2 div neg 0 moveto show grestore \
      gsave ix lstep mul neg rotate Waveradius 3 add neg 0 translate 90 rotate \
      dup stringwidth pop 2 div neg 0 moveto show grestore \
    } if \
  } for \
  0.5 setlinewidth \
  0 0 Waveradius dup Coeffradius sub 2 div add 0 360 arc stroke \
  0 setlinewidth \
} def \
 \
/pi 3.141592654 def \
/findhalfangle { \
  stringwidth pop 2 div 2 xrad mul pi mul div 360 mul \
} def \
/outsideplacechar { \
  /char exch def  /halfangle char findhalfangle def \
  gsave \
    halfangle neg rotate rad 0 translate -90 rotate \
    char stringwidth pop 2 div neg 0 moveto char show \
  grestore \
  halfangle 2 mul neg rotate \
} def \
 \
/outsidecircletext { \
  /rad exch def  /centerangle exch def \
  /ptsize exch def  /str exch def \
  /xrad rad ptsize 4 div add def \
  gsave \
    centerangle str findhalfangle add rotate \
    str {/charcode exch def ( ) dup 0 charcode put outsideplacechar } forall \
  grestore \
} def \
 \
/Docircletext { \
  (ANGLE OF TRANSMISSION COEFFICIENT IN DEGREES) \
  5 0 Coeffradius 7 sub outsidecircletext \
  (ANGLE OF REFLECTION COEFFICIENT IN DEGREES) \
  5 0 Coeffradius 3 add outsidecircletext \
  (\\320> WAVELENGTHS TOWARD GENERATOR \\320>) \
  5 166 Waveradius 3 add outsidecircletext \
  (<\\320 WAVELENGTHS TOWARD LOAD <\\320) \
  5 -166.5 Waveradius 7 sub outsidecircletext \
  /a1 164 def  /u1 a1 cos def  /v1 a1 sin def \
  /a2 108 def  /u2 a2 cos def  /v2 a2 sin def \
  /r Unitradius 0.940 mul def \
  newpath \
    u1 r mul 1 sub v1 r mul 1 sub moveto \
    u1 5 mul v1 5 mul rlineto \
    0 0 r 5 add a1 a2 arcn \
    u2 5 mul neg u2 5 mul neg rlineto \
    0 0 r 1 sub a2 a1 arc \
  closepath currentrgbcolor 1 setgray fill setrgbcolor \
  (INDUCTIVE REACTANCE COMPONENT \\(+jX/Zo\\), \\ \
OR CAPACITIVE SUSCEPTANCE \\(+jB/Yo\\)) \
  5 136 r outsidecircletext \
  gsave 1 -1 scale \
  newpath \
    u1 r mul 1 sub v1 r mul 1 sub moveto \
    u1 5 mul v1 5 mul rlineto \
    0 0 r 5 add a1 a2 arcn \
    u2 5 mul neg u2 5 mul neg rlineto \
    0 0 r 1 sub a2 a1 arc \
  closepath currentrgbcolor 1 setgray fill setrgbcolor \
  grestore \
  (CAPACITIVE REACTANCE COMPONENT \\(-jX/Zo\\), \\ \
OR INDUCTIVE SUSCEPTANCE \\(-jB/Yo\\)) \
  5 -136 r outsidecircletext \
  /u1 Unitradius 0.800 mul neg def \
  (RESISTANCE COMPONENT \\(R/Zo\\), OR CONDUCTANCE COMPONENT \\(G/Yo\\)) \
  dup stringwidth pop /u2 exch u1 add def \
  newpath \
    u1 -15 moveto \
    u1 -10  lineto \
    u2 -10  lineto \
    u2 -15 lineto \
  closepath currentrgbcolor 1 setgray fill setrgbcolor \
  u1 1 add -14 moveto show \
} def \
 \
/Swrlabels [1.1 1.2 1.4 1.6 1.8 2 2.5 3 4 5 10 20 40 100] def \
/Swrbreaks [1.05 1.2 3 4 5 10 20 40 100] def \
/Swrdivs   [0.05 0.1 0.2 0.5 1 2 10 60] def \
 \
/Dbslabels [1 2 3 4 5 6 8 10 15 20 30 40] def \
/Dbsbreaks [0.5 6 20 30 40] def \
/Dbsdivs   [0.5 1 2 5] def \
 \
/Attlabels [1 2 3 4 5 7 10 15] def \
/Attbreaks [0.2 5 10 15] def \
/Attdivs  [0.2 0.5 1] def \
 \
/Swllabels [1.1 1.2 1.3 1.4 1.6 1.8 2 3 4 5 10 20] def \
/Swlbreaks [1.02 1.2 1.4 2 3 5 10 20 50] def \
/Swldivs   [0.02 0.05 0.1 0.2 0.5 1 5 30] def \
 \
/Rldblabels [0 1 2 3 4 5 6 7 8 9 10 12 14 20 30] def \
/Rldbbreaks [0.2 6 10 20 30] def \
/Rldbdivs   [0.2 0.5 1 2] def \
 \
/Rcplabels [0.01 0.05 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1] def \
/Rcpbreaks [0.005 .01 0.1 0.5 1] def \
/Rcpdivs   [0.005 0.01 0.02 0.05] def \
 \
/Rfllabels [0.1 0.2 0.4 0.6 0.8 1 1.5 2 3 4 5 6 10 15] def \
/Rflbreaks [0.02 0.1 0.2 2 4 6 10 15] def \
/Rfldivs   [0.02 0.05 0.1 0.2 0.5 1 5] def \
 \
/Swplabels [1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 2 2.5 3 4 5 10] def \
/Swpbreaks [1.02 1.5 2 3 4 5 10] def \
/Swpdivs   [0.02 0.05 0.1 0.2 0.5 1] def \
 \
/Rclabels [0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1] def \
/Rcbreaks [0 1] def \
/Rcdivs   [0.02] def \
 \
/Tcplabels [0.99 0.95 0.9 0.8 0.7 0.6 0.5 0.4 0.3 0.2 0.1 0] def \
/Tcpbreaks [0.05 5 0.9 0.99 0.995] def \
/Tcpdivs   [0.05 0.02 0.01 0.005] def \
 \
/Tclabels [1 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 2] def \
/Tcbreaks [1 2] def \
/Tcdivs   [0.02] def \
 \
/swr-rho {dup 1 sub exch 1 add div} def \
/dbs-rho {20 div 10 exch exp swr-rho} def \
/att-rho {-10 div 10 exch exp} def \
/swl-rho {dup 1 sub exch 1 add div sqrt} def \
/rldb-rho {-20 div 10 exch exp} def	\
/rcp-rho {0 exch dup 0 ge {exch} if pop sqrt} def \
/tcp-rho {1 sub neg rcp-rho} def \
/rfl-rho {-10 div 10 exch exp tcp-rho} def \
/swp-rho {dup mul swr-rho} def \
/tc-rho {1 sub} def \
\
/Donomoline {\
  /name exch def     /direction exch def  /lineside exch def\
  /qty-rho exch def  /divs exch def       /breaks exch def\
  /labels exch def\
\
  /fullscale Unitradius direction mul def\
  /tic 2 lineside mul def\
  0 0 moveto 0 2 rlineto stroke\
  fullscale 0 moveto 0 tic rlineto stroke\
\
  0 1 divs length 1 sub {/ix exch def\
    breaks ix get divs ix get breaks ix 1 add get {\
      qty-rho cvx exec fullscale mul 0 moveto 0 tic rlineto stroke\
    } for\
  } for\
\
  0 1 labels length 1 sub {\
    labels exch get dup qty-rho cvx exec fullscale mul 0 moveto\
    0 lineside 0 gt {3} {-7} ifelse rmoveto\
    str cvs dup stringwidth pop 2 div neg 0 rmoveto show\
  } for\
\
  fullscale 0 moveto 0.05 fullscale mul 0 rlineto stroke\
  gsave\
    fullscale 1.05 mul 0 translate 45 direction mul rotate\
    0 0 moveto 0.22 fullscale mul 0 lineto stroke\
    lineside 0 gt {3} {-3} ifelse direction mul\
    lineside 0 gt {1} {-5} ifelse moveto\
    direction 0 lt {name stringwidth pop neg 0 rmoveto} if\
    name show\
  grestore\
} def\
\
/Donomograph { \
  0 setlinewidth \
  0 setgray \
  /str 20 string def \
  gsave \
    0 -4.0 72 mul translate \
    0 0 moveto (RADIALLY SCALED PARAMETERS) dup \
      stringwidth pop 2 div neg 0 rmoveto show \
    0.1 Unitradius mul -10 moveto (TOWARD LOAD \\320\\>) show \
    0.9 Unitradius mul -10 moveto (\\<\\320 TOWARD GENERATOR) \
      dup stringwidth pop neg 0 rmoveto show \
 \
    0 -0.25 72 mul translate \
    0 0 moveto 0 -.5 72 mul lineto stroke \
    Unitradius neg 10 moveto 0 0.65 Unitradius mul rlineto stroke \
    Unitradius 10 moveto 0 0.65 Unitradius mul rlineto stroke \
 \
    Unitradius neg 0 moveto Unitradius 0 lineto stroke \
    Swrlabels Swrbreaks Swrdivs (swr-rho) 1 -1 (SWR) Donomoline \
      -4 3 moveto (1) show \
      Symfont Unitradius 3 add neg 3 moveto (\\245) show Helvfont \
    Dbslabels Dbsbreaks Dbsdivs (dbs-rho) -1 -1 (dBS) Donomoline \
      -4 -7 moveto (1) show \
      Symfont Unitradius 2 add neg -7 moveto (\\245) show Helvfont \
    Attlabels Attbreaks Attdivs (att-rho) 1 1 (ATTEN. [dB]) Donomoline \
    Swllabels Swlbreaks Swldivs (swl-rho) -1 1 (S.W. LOSS COEFF) Donomoline \
      1 -7 moveto (1) show \
      Symfont Unitradius 2 sub -7 moveto (\\245) show Helvfont \
 \
    0 -0.25 72 mul translate \
    Unitradius neg 0 moveto Unitradius 0 lineto stroke \
    Rldblabels Rldbbreaks Rldbdivs (rldb-rho) 1 -1 (RTN. LOSS [dB]) Donomoline \
      Symfont -4 3 moveto (\\245) show Helvfont \
    Rcplabels Rcpbreaks Rcpdivs (rcp-rho) -1 -1 (RFL. COEFF, P) Donomoline \
      -4 -7 moveto (0) show \
    Rfllabels Rflbreaks Rfldivs (rfl-rho) 1 1 (RFL. LOSS [dB]) Donomoline \
      Symfont Unitradius 1 sub 3 moveto (\\245) show Helvfont \
      1 3 moveto (0) show \
    Swplabels Swpbreaks Swpdivs (swp-rho) -1 1 (S.W. PEAK \\(CONST. P\\)) \
      Donomoline \
      1 -7 moveto (0) show \
      Symfont Unitradius 1 sub -7 moveto (\\245) show Helvfont \
 \
    0 -0.25 72 mul translate \
    Unitradius neg 0 moveto Unitradius 0 lineto stroke \
    Rclabels Rcbreaks Rcdivs () 1 -1 (RFL. COEFF, E or I) Donomoline \
    -4 3 moveto (0) show \
    Tcplabels Tcpbreaks Tcpdivs (tcp-rho) 1 1 (TRANSM. COEFF, P) Donomoline \
    1 3 moveto (1) show \
    newpath 0 0 moveto -2 -3 lineto 2 -3 lineto 2 -3 lineto closepath fill \
    0 -8 moveto (CENTER) dup stringwidth pop 2 div neg 0 rmoveto show \
 \
    0 -0.25 72 mul translate \
    Unitradius neg 0 moveto Unitradius 0 lineto stroke \
    Tclabels Tcbreaks Tcdivs (tc-rho) 1 1 (TRANSM. COEFF, E or I) Donomoline \
    Unitradius neg 0 translate \
    0 2 98 { \
      dup Unitradius mul 0.01 mul dup 0 moveto 0 2 rlineto stroke \
      exch dup 10 mod 0 eq \
        {exch 3 moveto .01 mul str cvs dup \
         stringwidth pop 2 div neg 0 rmoveto show} \
        {pop pop} \
      ifelse \
    } for \
    newpath 0 0 moveto -2 -3 lineto 2 -3 lineto closepath fill \
    0 -8 moveto (ORIGIN) dup stringwidth pop 2 div neg 0 rmoveto show \
 \
  grestore \
} def \
 \
/Dodots { \
  /znaught exch def  /pointarray exch def \
  pointarray length 3 mod 0 eq { \
    0 3 pointarray length 3 sub { /ix exch def \
      pointarray ix get znaught div \
      pointarray ix 1 add get znaught div \
      RXtoUV Unitradius mul exch Unitradius mul exch 2 copy moveto \
      2 copy 3 0 360 arc currentgray 0 setgray fill setgray \
      moveto 4 -3 rmoveto \
      currentfont \
        /Helvetica-Bold findfont 8 scalefont setfont \
        pointarray ix 2 add get show \
      setfont \
    } for \
  } if \
} def \
 \
/norm { Unitradius mul } def \
/traceUV { \
  /bCurve exch def \
  /pointarray exch def \
  gsave \
  0.25 setlinewidth \
  1 setlinejoin \
  1 setlinecap \
  bCurve { \
    pointarray length dup 8 gt exch 2 sub 6 mod 0 eq and { \
      pointarray 0 get norm pointarray 1 get norm moveto \
      2 6 pointarray length 1 sub { \
        /ix exch def \
        0 1 5 { ix add pointarray exch get norm } for \
        curveto \
      } for \
      stroke \
    } if \
  }{ \
    pointarray length dup 4 gt exch 2 mod 0 eq and { \
      pointarray 0 get norm pointarray 1 get norm moveto \
      2 2 pointarray length 1 sub { \
        /ix exch def \
        pointarray ix get norm \
        pointarray ix 1 add get norm \
        lineto \
      } for \
      stroke \
    } if \
  } ifelse \
  grestore \
} def \
\
/markerSymbol { \
  10 dict begin \
  /up exch def \
  /delta exch def \
  /label exch def \
  /im exch def \
  /re exch def \
  gsave \
    Unitradius Unitradius scale \
    /arrowLength 0.04 def \
    0.002 setlinewidth \
    newpath re im moveto \
    arrowLength 4 div neg \
    arrowLength up not {neg} if rlineto \
    arrowLength 2 div 0 rlineto currentpoint closepath stroke \
    re im arrowLength up { 1.25 mul add }{ 2 mul sub } ifelse moveto \
    /Helvetica findfont arrowLength scalefont setfont \
	label dup stringwidth pop 2 div neg 0 rmoveto show \
    delta {/Symbol findfont arrowLength scalefont setfont (D) show } if \
  grestore \
  end \
} def \
/in { 72.0 mul } def \
/toString { 15 string cvs } def \
 \
/mkrXleft 0.5 in def \
/mkrXoffsetRight 0.80 in def \
/mkrYtop 10.3 in def \
\
/mkrLineNo 0 def \
/mkrFontSize 7 def \
\
/prevLeftOrRight -1 def \
\
/formatSmithOrPolarSymbols [ [(V) /degree] [(dB) /degree] [(U) (U)] [/Omega /Omega] [(S) (S)]] def \
/sweepSymbols [ (Hz) (Hz) (Hz) (Hz) (dBm) (s) ] def \
\
/rightJustifyShow { \
  dup \
  stringwidth pop neg 0 rmoveto \
  show \
} def \
 \
/mkrYadvance { \
  /mkrLineNo exch mkrLineNo add def \
  mkrYtop mkrFontSize mkrLineNo 1.2 mul mul sub \
} def \
\
/markerText { \
  gsave \
    currentrgbcolor initgraphics setrgbcolor \
    /sweepType exch def \
    /sStimulusPrefix exch def \
    /sStimulusValue exch def \
    /mkrType exch def \
    /sPrefix2 exch def \
    /sValue2 exch def \
    /sPrefix1 exch def \
    /sValue1 exch def \
    /leftOrRight exch def \
    /mkrNo exch def \
\
    prevLeftOrRight leftOrRight ne { /mkrLineNo 0 def /prevLeftOrRight leftOrRight def } if \
\
    /mkrY 0 mkrYadvance def \
    /mkrX mkrXleft leftOrRight 6.5 in mul add def \
    mkrX mkrY moveto \
    /Helvetica-Bold findfont mkrFontSize scalefont setfont \
    mkrNo 1 add toString show (:) show \
    /Helvetica findfont mkrFontSize scalefont setfont \
\
    mkrX mkrXoffsetRight add mkrY moveto \
    sValue1 rightJustifyShow 0.02 in 0 rmoveto sPrefix1 show \
      formatSmithOrPolarSymbols mkrType get 0 get dup type \
      /nametype eq { /fs currentfont def /Symbol findfont mkrFontSize scalefont setfont glyphshow fs setfont }{ show } ifelse \
    /mkrY 1 mkrYadvance def \
\
    mkrX mkrXoffsetRight add mkrY moveto \
    sValue2 rightJustifyShow 0.02 in 0 rmoveto sPrefix2 show \
      formatSmithOrPolarSymbols mkrType get 1 get dup type \
      /nametype eq { /fs currentfont def /Symbol findfont mkrFontSize scalefont setfont glyphshow fs setfont }{ show } ifelse \
    /mkrY 1 mkrYadvance def \
\
    mkrX mkrXoffsetRight add mkrY moveto \
    sStimulusValue rightJustifyShow 0.02 in 0 rmoveto sStimulusPrefix show \
      sweepSymbols sweepType get show \
    /mkrY 1 mkrYadvance def \
\
  grestore \
  /mkrLineNo mkrLineNo 0.5 add def \
} def \
\
/markerDeltaText { \
  /mkrLineNo mkrLineNo 0.2 sub def \
  gsave \
  initgraphics \
    /deltaMarker exch def \
\
    /mkrY 0 mkrYadvance def \
    /mkrX mkrXleft leftOrRight 6.5 in mul add def \
    mkrX mkrY moveto \
\
    /Symbol findfont mkrFontSize scalefont setfont /Delta glyphshow \
    /Helvetica findfont mkrFontSize scalefont setfont \
    ( ref = ) show deltaMarker 4 lt {deltaMarker 1 add toString show} \
      { /Symbol findfont mkrFontSize scalefont setfont /Delta glyphshow } ifelse \
\
  grestore \
  /mkrLineNo mkrLineNo 1.3 add def \
} def \
\
/showDate { \
  gsave \
    20 dict begin \
    /date exch def \
    initgraphics \
    clippath pathbbox 3 -1 roll sub /height exch def \
    exch sub /width exch def \
    width 0.5 in sub height 0.3 in sub moveto \
\
    0 setgray \
    /Helvetica-Oblique findfont 10 scalefont setfont \
    date rightJustifyShow \
    end \
  grestore \
} def \
\
/showTitle { \
  gsave \
    20 dict begin \
    /title exch def \
    initgraphics \
    clippath pathbbox 3 -1 roll sub /height exch def \
    exch sub /width exch def \
    0.5 in height 0.3 in sub moveto \
\
    0 setgray \
    /Helvetica-Bold findfont 15 scalefont setfont \
    title show \
    end \
  grestore \
} def \
\
/stimulusXpos 0.9 in def \
/stimulusYpos 2.6 in def \
/stimulusTextFontSize 8 def \
/sweepTypeLabel [(Linear Frequency) (Log Frequency) (List Frequency) (CW Time) (Power)] def \
/CWtimeSweep 3 def \
\
/stimulusTextLine { \
  channel 0 eq { \
      X Y moveto \
      exch rightJustifyShow \
      X offset add 0.2 in add Y moveto rightJustifyShow \
  } { \
      X 6.7 in add Y moveto \
      exch show \
      X 6.5 in add Y moveto rightJustifyShow \
  } ifelse \
  /Y Y stimulusTextFontSize 1.5 mul sub def \
} def \
 \
/stimulusText { \
    gsave \
    25 dict begin \
    /bCoupled exch def \
    /channel exch def \
    /sweepType exch def \
    /sCenter exch def \
    /sStop exch def \
    /sStart exch def \
\
    currentrgbcolor initgraphics setrgbcolor \
    /Helvetica findfont stimulusTextFontSize scalefont setfont \
\
    bCoupled { 0 setgray } if \
	sStart stringwidth pop dup \
    sStop stringwidth pop dup \
    sCenter stringwidth pop dup \
    3 -1 roll gt { 2 -1 roll pop } { pop } ifelse \
    dup 3 -1 roll gt { 2 -1 roll pop } { pop } ifelse /offset exch def \
\
    /Y stimulusYpos def \
    /X stimulusXpos def \
\
    /Helvetica-Oblique findfont stimulusTextFontSize scalefont setfont \
    channel 0 eq { \
      X 0.2 in add Y moveto \
      sweepTypeLabel sweepType get show \
    }{ \
      X 6.5 in add Y moveto \
      sweepTypeLabel sweepType get rightJustifyShow \
    } ifelse \
    /Y Y stimulusTextFontSize 1.75 mul sub def \
\
    /Helvetica findfont stimulusTextFontSize scalefont setfont \
    (Start) sStart stimulusTextLine \
    sweepType CWtimeSweep lt { \
       (Center) sCenter stimulusTextLine \
       (Stop) sStop stimulusTextLine \
     } { \
       (Stop) sStop stimulusTextLine \
       /Y Y stimulusTextFontSize 0.75 mul sub def \
       channel 0 eq { \
         () sCenter (  C.W. Frequency) \
       } { \
         () (C.W. Frequency  ) sCenter \
       } ifelse \
       Concatenate stimulusTextLine \
     } ifelse \
\
\
    end \
  grestore \
\
} def \
\
/bandwidthXleft 2.5 in def \
/bandwidthXoffsetRight 0.40 in def \
/bandwidthYtop 10.3 in def \
\
/bandwidthFontSize 7 def \
\
/bandwidthText { \
    gsave \
    25 dict begin \
    /channel exch def \
    /sQ exch def \
    /sCenterUnits exch def \
    /sCenter exch def \
    /sWidthUnits exch def \
    /sWidth exch def \
\
    currentrgbcolor initgraphics setrgbcolor \
\
    /Y bandwidthYtop def \
    /X bandwidthXleft def \
    channel 0 ne { /X X 3.0 in add def } if \
\
    /Helvetica-Bold findfont bandwidthFontSize scalefont setfont \
    /boldFont currentfont def \
    X Y moveto (Width:) rightJustifyShow \
    /Helvetica findfont bandwidthFontSize scalefont setfont \
    /regularFont currentfont def \
    X bandwidthXoffsetRight add Y moveto sWidth rightJustifyShow \
    bandwidthFontSize 2 div 0 rmoveto sWidthUnits show \
    /Y Y mkrFontSize 1.2 mul sub def \
\
    boldFont setfont X Y moveto (Center:) rightJustifyShow \
    regularFont setfont \
    X bandwidthXoffsetRight add Y moveto sCenter rightJustifyShow \
    bandwidthFontSize 2 div 0 rmoveto sCenterUnits show \
    /Y Y mkrFontSize 1.2 mul sub def \
\
    boldFont setfont X Y moveto (Q:) rightJustifyShow \
    regularFont setfont \
    X bandwidthXoffsetRight add Y moveto sQ rightJustifyShow \
\
    end \
  grestore \
} def \
\
/statusXleft 0.5 in def \
/statusYtop 10.5 in def \
\
/statusFontSize 10 def \
/statusText { \
    gsave \
    25 dict begin \
    /channel exch def \
    /sIFBW exch def \
    /sMeasurement exch def \
\
    currentrgbcolor initgraphics setrgbcolor \
\
    /Helvetica-Bold findfont statusFontSize scalefont setfont \
    statusXleft channel 0 ne {4 in add } if statusYtop moveto sMeasurement show \
    /Helvetica findfont statusFontSize 3 mul 4 div scalefont setfont \
    0.3 in 0 rmoveto (IF bandwidth: )show sIFBW show (Hz) show \
    end \
  grestore \
} def \
\
/legendNotYetDrawn true def \
/drawGrid { \
  /RXnotGB exch def \
  RXnotGB { \
	setZcolor \
	DoRX \
  } { \
	setGcolor \
	DoGB \
  } ifelse \
  legendNotYetDrawn { \
    setLegendCcolor \
    Docoeffcircle \
    Dowavecircle \
    setZcolor \
    Docircletext \
    Donomograph \
    /legendNotYetDrawn false def \
  } if \
} def \
";
#endif
