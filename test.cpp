int x;
// int x


for (int i = 1; i < 31; i = i + 2) {			// 홀수값
	GaussianBlur(src, dst, Size(i, i), 0, 0);	// 가우시안 스무딩
	imshow("Gaussian filter", dst);
	waitKey(1000);
} 
