#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define max 100000
struct point {			//점위치 받을 구조체
	int x;
	int y;
};
	
int main(void) {											
	struct point p[max];
	int num;
	scanf("%d", &num);	//점 몇개할지 입력
	for (int f=0;f < num;f++) {
		scanf("%d %d", &p[f].x, &p[f].y);
	}	

	for (int i = 0;i < num - 1;i++) {
		for (int j = 0;j < num - i - 1;j++) {
			if (p[j].x > p[j + 1].x|| (p[j].x==p[j+1].x&&p[j].y>p[j+1].y) ) {	//x값을 정렬시키면서 x값이 같을때 y값도 비교해서 정렬한다

				struct point temp = p[j];		//struct point temp는 구조체 값 잠시 저장할 임시임(int temp의 구조체 버전)
				p[j] = p[j + 1];
				p[j + 1] = temp;

			}
		}
	}

	for (int ii = 0;ii < num;ii++) {
		printf("\n%d %d", p[ii].x, p[ii].y);
	}
	
	return 0;
}