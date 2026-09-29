clear all;
fs = 8000;

t1 = 0:1/fs:0.70;
t3 = 0:1/fs:0.25;

c1 = sin(2*pi*130.8*t3);
c2 = sin(2*pi*262*t3);
c3 = sin(2*pi*523.3*t3);
d1 = sin(2*pi*294*t3);
e1 = sin(2*pi*330*t3);
f1 = sin(2*pi*349.2*t3);
g1 = sin(2*pi*392.0*t3);
b = sin (2*pi*493.9*t3);

nol = zeros(size(t1));

nada1 = [c1,e1,c1,e1,f1,g1,g1,nol,b,c2,b,c2,b,g1,nol,nol];
nada2 = [c1,e1,c1,e1,f1,g1,g1,nol,b,c2,b,c2,b,g1,nol];
nada3 = [c1,nol,e1,nol,g1,nol,f1,f1,g1,f1,e1,c1,f1,e1,c1,nol];
nada4 = [c1,nol,e1,nol,g1,nol,f1,f1,g1,f1,e1,c1,f1,e1,c1];
Gundulpacul = [nada1,nada2,nada3,nada4];
sound(Gundulpacul,fs);
filename='Gundulpacul.wav';
audiowrite(filename,Gundulpacul,fs);
