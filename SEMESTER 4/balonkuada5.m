clear all;
fs = 8000;

t = 0:1/fs:0.5;

c = sin(2*pi*261.63*t); % C
d = sin(2*pi*293.66*t); % D
e = sin(2*pi*329.63*t); % E
f = sin(2*pi*349.23*t); % F
g = sin(2*pi*392.00*t); % G
a = sin(2*pi*440.00*t); % A
b = sin(2*pi*493.88*t); % B
nol = zeros(size(t1));

% Melodi lagu Balonku dengan 5 balon
nada1 = [c c g g a a g nol f f e e d d c nol];
nada2 = [g g f f e e d g g f f e e d nol];
nada3 = [g g f f e e d c c g g a a g nol];
nada4 = [f f e e d d c nol g g f f e e d nol];
nada5 = [c c g g a a g nol f f e e d d c nol];

% Gabungkan melodi untuk membuat lagu Balonku dengan 5 balon
balonku = [nada1 nada2 nada3 nada4 nada5];
sound(balonku, fs);

% Simpan lagu Balonku dengan 5 balon dalam file audio
filename = 'Balonku_5_Balon.wav';
audiowrite(filename, balonku, fs);

