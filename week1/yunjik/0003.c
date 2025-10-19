#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct member {
    int age;
    char name[101];
};

struct member mem[100000];		//전역으로 해서 오버플로우 막기??

int main() {
    int num;
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++) {
        scanf("%d %s", &mem[i].age, &mem[i].name);
    }

    for (int i = 0; i < num - 1; i++) {             //버블정렬을 통해 정렬함 이때 나이가 같으면 그대로 두기 때문에 들어온 순 대로도 정렬가능
        for (int j = 0; j < num - i - 1; j++) {
            if (mem[j].age > mem[j + 1].age) {
                struct member temp = mem[j];
                mem[j] = mem[j + 1];
                mem[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < num; i++) {
        printf("\n%d %s\n", mem[i].age, mem[i].name);
    }

    return 0;
}