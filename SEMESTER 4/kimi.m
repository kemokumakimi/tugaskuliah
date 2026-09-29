gambar=imread('sailboat.jpg');
gray=rgb2gray(gambar);
g1 = [0 -1 0;-1 4 -1;0 -1 0];
highPass = conv2(double(gray),g1);; imshow(gray);66
figure, imshow(uint8(highPass))
