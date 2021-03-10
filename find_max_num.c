/***
 2021/03/10 swhors@naver.com
 
 아래 코드는 주어진 수열의 조합으로 최대 값을 찾는 코드입니다.
 예로 [1,3,5] 주어진 경우에, 531을 반환하는 것입니다.
 
 아래 코드는 수정 중에 있습니다.
 ***/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _DBG 0
#undef _DBG

int *boglebogle(int *a, int len) {
    for (int i = 0;i < len; i++) {
        int comp0 = (a[i]>=10?a[i]/10:a[i]);
        int leave0 = a[i] % 10;
        for (int b = i+1;b < len; b++) {
            int comp1 = (a[b]>=10?a[b]/10:a[b]);
            int leave1 = a[b] % 10;
            if (comp0 < comp1) {
                int tmp = a[i];
                a[i] = a[b];
                a[b] = tmp;
            } else if (comp0 == comp1) {
                if (leave0 < leave1) {
                    int tmp = a[i];
                    a[i] = a[b];
                    a[b] = tmp;
                }
            }
        }
    }

    return a;
}

char *find_max_num(int *a, int len) {
    /* 1. 앞자리의 수가 큰 순으로 정렬 */
    int *sorted = boglebogle(a, len);

#if defined _DBG

    /* 2. 데이터 확인 */
    for(int i = 0;i < len;i++)
    {
        printf("%d, ", sorted[i]);
    }
    printf("\n");
#endif


    /* 3. 수 들을 JOIN */
    char *num = (char*)malloc(10);
    sprintf(num, "%d", sorted[0]);
    for (int i = 1;i< len;i++) {
        char tmp[10];
        sprintf(tmp, "%d", sorted[i]);

        strcat(num, tmp);
    }

#if defined _DBG
    /* 4. 데이터 확인 */
    printf("sorted %s\n", num);
#endif

    /* 5. 반환 */
    return &num[0];
}

int main() {
    int data[4] = {1,2,3,4};
    int data_len = 4;
    printf("result = %s\n",
           find_max_num((int*)&data[0], data_len));

    int data1[7] = {8,2,13,4,11,10,22};
    int data_len1 = 7;
    printf("result = %s\n",
           find_max_num((int*)&data1[0], data_len1));
}
