#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printarray(int *data, int n) {
    for(int i=0; i<n; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void countsort(int *data, int n) {
    int maxv = data[0];
    for(int i=1; i<n; ++i) {
        if(maxv < data[i]) {
            maxv = data[i];
        }
    }

    // 初始化计数数据
    int *c = (int*)malloc(sizeof(int) * (maxv+1));
    for(int i=0; i<=maxv; ++i) {
        c[i] = 0;
    }

    for(int i=0; i<n; ++i) {
        ++c[data[i]];
    }

    // 累加
    for(int i=1; i<=maxv; ++i) {
        c[i] += c[i-1];
    }

    int *r = (int*)malloc(sizeof(int)*n);
    // 为了让该排序算法是稳定的排序, 就需要从数组的后面往前遍历
    for(int i=n-1; i>=0; --i) {
        int idx = c[data[i]] - 1;
        r[idx] = data[i];
        --c[data[i]];
    }
    
    for(int i=0; i<n; ++i) {
        data[i] = r[i];
    }
    free(r);
    free(c);
}


int main() {
    int data[] = {3, 3, 2, 5, 7, 6, 7, 3, 1, 9, 4, 20};
    int n = sizeof(data)/sizeof(data[0]);

    countsort(data, n);
    printarray(data, n);
    
    return 0;
}
