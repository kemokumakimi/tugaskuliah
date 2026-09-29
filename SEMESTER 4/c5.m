clear all;
fs = 10000; t=0:1/fs:0.5;
v1 = 0.5 * cos  (2 * pi * 440 * t);
v2 = 0.5 * cos (2 * pi * 880 * t);
v = v1 + v2;
sound(v1, fs);
subplot (2,2,1);
plot(t,v1);
axis([0 00.1 -1 1]);
title("Nada 1");

sound(v2, fs);
subplot (2,2,2);
plot(t,v2);
axis([0 00.1 -1 1]);
title("Nada 2");

sound(v2, fs);
subplot (2,2,3);
plot(t,v);
title("Penggabungan Nada");
axis([0 00.1 -1 1]);
xlabel('Time (sec)');
ylabel('v(t)');
