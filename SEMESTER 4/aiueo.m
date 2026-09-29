clear all;
fs = 8000;
a = 10;
y = audioread('aiueo.wav');
suara = audioplayer(y,fs);
xn = a * y;
suara2 = audioplayer(xn,fs);
play(suara2);
figure,plot(xn);
