#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
快速排序的思路:
1. 选一个值当做分界值
2. 让小于该值的位于左边, 大于该值的位于右边
3. 最后让该分界值位于中间正确的位置, 然后依次处理左边和右边的部分
*/
int partition(int *data, int start, int end) {
    int i=start, j=end, povit = data[start];
    while(i != j) {
        while(j > i && data[j] >= povit) --j;
        while(j > i && data[i] <= povit) ++i;

        if(i < j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
    data[start] = data[i];
    data[i] = povit;
    return i;
}

// 第二种分区的方法, 不太好理解
// 思路是: 有点儿类似选择排序, 通过游标i把A[p...r-1]分成两部分,
// A[p...i-1]的元素都是小于
// pivot的, 暂且叫做"已处理区间", A[i...r-1]是"未处理区间".
// 每次都从未处理区间的取一个元素A[j]
// 与pivot对比, 如果小于pivot, 则将其加入到已处理区间的尾部, 即A[i]的位置.
int partitionv2(int *A, int p, int r) {
    int povit = A[r];
    int i = p;
    for(int j=p; j<=r-1; j++) {
        if(A[j] < povit) {
            if (i != j) {
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
            ++i;
        }
    }
    A[r] = A[i];
    A[i] = povit;
    return i;
}

void myqsort(int *data, int start, int end) {
    if(start >= end) return;

    int i = partitionv2(data, start, end);
    myqsort(data, start, i-1);
    myqsort(data, i+1, end);
}

void myquicksort(int *data, int n) {
    myqsort(data, 0, n-1);
}

void printarray(int *data, int n) {
    for(int i=0; i<n; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 100};
    int n = sizeof(data)/sizeof(data[0]);
    myquicksort(data, n);
    printarray(data, n);
    return 0;
}

/*
Python版本快速排序
def myqsort(data):
    if len(data) <= 1: return data

    povit = data[0]
    left = [d for d in data[1:] if d<=povit]
    right = [d for d in data[1:] if d > povit]
    return myqsort(left) + [povit] + myqsort(right)

data = [1, 3, 5, 7, 2, 4, 6, 8]
data = myqsort(data)
print(data)
*/
