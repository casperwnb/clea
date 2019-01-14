#include <stdio.h>
#include <stdbool.h>

 // 每冒泡一次, 将最大的值放入到最后边
 // 冒泡排序可以进一步优化的地方就是, 当某次冒泡过程没有出现
 // 数据交换时, 就可以直接返回结果了
void bubblesort(int *data, int n) {
    bool flag = true; // 初始为true, 表示数组已经排好序了
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n-i-1; ++j) {
            if(data[j] > data[j+1]) {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
                flag = false; // 有数据交换, 则表示未排好序
            }
        }
        if(flag) {
            break;
        }
    }
}

void printarray(int *data, int n) {
    for(int i=0; i<n; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {3, 5, 4, 1, 2, 6};
    int n = sizeof(data)/sizeof(data[0]);
    bubblesort(data, n);
    printarray(data, n);
    return 0;
}

/*
python版本冒泡排序:
# 冒泡排序
def bubblesort(data):
    size = len(data)
    for i in range(size):
        flag = True
        for j in range(size-i-1):
            if data[j] > data[j+1]:
                data[j], data[j+1] = data[j+1], data[j]
                flag = False
        if flag:
            break
 */

