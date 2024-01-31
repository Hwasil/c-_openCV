* Grayscale : 화소 당 1byte 사용해 화소 밝기 표시
* Color : 화소 당 3byte 사용해 BGR 성분 저장

flip(src, dst, 1) : 입력 영상 좌우로 뒤집기 (input, output, 대칭 방향 3가지)
1 : y축 대칭, 0 : 상하 대칭, -1 : 좌우 & 상하대칭
