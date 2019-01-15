#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 该分区函数采用的是从大到小的排序方式实现的
int partition(int *data, int start, int end) {
    int povit = data[start];
    int i=start, j=end, tmp;
    while(i != j) {
        while(i < j && data[j] <= povit) --j;
        while(i < j && data[i] >= povit) ++i;

        if(i < j) {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
    data[start] = data[i];
    data[i] = povit;
    return i;
}

int findkth(int *data, int n, int k) {
    if (k <= 0 || k > n) {
        return -1;
    }
    
    int i = partition(data, 0, n-1);
    while(i != k-1) {
        if (i < k) {
            i = partition(data, i+1, n-1);
        } else {
            i = partition(data, 0, i-1);
        }
    }
    return data[i];
}

void printarray(int *data, int n) {
    for(int i=0; i<n; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 100, -2};
    int n = sizeof(data)/sizeof(data[0]);
    int v = findkth(data, n, n);
    printf("%d\n", v);
    return 0;
}
