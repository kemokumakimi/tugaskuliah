clear all;
f = 500;
fs =16000;
t = 1/fs:1/fs:0.5;
y = 2*sin(2*pi*f*t);
sound(y,fs);
plot(t,y);
axis([0 0.1 -1 1]);
title('Sinyal Sinus (f=800 hz), sampling 16000hz');
