; This script calculates n1 Cartesian coordinates (fs_x, fs_y) of
; of the x-ray tube focal spot toggle positions, as well as the n1
; tube rotation angles (fs_a) that make up a circular arc trajectory
; to model some of the commercial DBT systems geometries.
; In our benchtop the angular swivel arm motion, used in DBT machines,
; is realized via synchronous motion of the orthogonal x- and y- linear
; stages, with a rotary table on top, on which the x-ray tube is mounted.
; It is a more complicated setup then needed, but we had to work
; with what was already installed in the laboratory.
; Such pre-computed motion path is then loaded into a programmable
; multi-axis controller (PMAC) Delta Tau Turbo Clipper, that sends the jog
; commands to the microstepping drives of the linear and rotary stages.
; Output of this script is fs_x (mm), fs_y (mm), and fs_a (degrees),
; where the origin of coordinate sytem (x= 0, y= 0) is set up
; with respect (with some offsets for convenience) to x- and y-
; translational stages "home" postions.
;
; Three clinical DBT systems trajectories can be computed: Siemens
; Mammomat, GE Essential, Hologic Selenia. Their corresponding
; parameters are listed below:
;
;           Siemens   GE   Hologic
; 
; R, mm      655     660    700
; n_prj      25       9     15
; arc, deg.  46      25     15

pi=    3.14159265359
xc=   -990.0               ; COR== detector plane (wrt table home position), mm
yc=    0.0
r=     700                 ; circle's radius, mm (655  660 700)

n1=    15                  ; number of projection angles (25  9  15)
n2=    2                   ; add two table 'ramp' intervals
n_prj= n1+n2

arc=   15.0                ; full arc, deg. (46  25  15)
arc=   arc+2.0*arc/(n1-1)  ; full arc + two 'ramp' intervals
d_arc= arc/(n_prj-1)       ; delta angle

x= fltarr(n_prj)           ; x-coordinates
y= fltarr(n_prj)           ; y-coordinates

for i=1,n_prj do begin
   
   x(i-1)= xc+r*cos((arc/2.0-(i-1)*d_arc)/180.0*pi)
   y(i-1)= yc-r*sin((arc/2.0-(i-1)*d_arc)/180.0*pi)
   
   ;----- x, y, angle
   
   fs_x= round(y(i-1)*1000.0)
   fs_y= round(x(i-1)*1000.0)
   fs_a= round(atan((y(i-1)-yc)/(x(i-1)-xc))*180.0/pi*12500.0)
   print,i,fs_x,fs_y,fs_a  ;,(arc/2.0-(i-1)*d_arc),atan((y(i-1)-yc)/(x(i-1)-xc))*180.0/pi
   
endfor

end



;; set_plot,'ps'
;; device,filename='real_arc_vs_commanded.eps',/encapsulated,/bold,/pre_xsize,/pre_ysize

;; ;window,0,xsiz=800,ysiz=800
;; cgplot,y,x,psym=cgsymcat(16),color='red',/isotropic,xrange=[-150.0,150.0],yrange=[-625,0.0],$
;; /xstyle,/ystyle,thick=3,charsize=1,charthick=3.0,xthick=3,ythick=3

;; ;-----open file with measured FS positions and overplot the real arc

;; openr,1,'fs_posn.txt'
;; xy= fltarr(2,9)
;; readf,1,xy
;; close,1

;; xy(1,*)= -(920.0+xy(1,*))
;; xc= xy(0,*)
;; yc= xy(1,*)

;; cgoplot,xc,yc,psym=cgsymcat(16),color='blue'

;; device,/close
;; set_plot,'x'
