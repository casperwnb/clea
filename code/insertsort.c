#include <stdio.h>
#include <stdbool.h>

void printarray(int *data, int n) {
    for(int i=0; i<n; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void insertsortv1(int *data, int n) {
    for(int i=1; i<n; ++i) {
        int j = i - 1;
        int v = data[i];

        // 使用while循环来查找有序部分的正确位置
        while(data[j] > v && j >= 0) {
            data[j+1] = data[j];
            --j;
        }
        data[j+1] = v;
    }
}

void insertsortv2(int *data, int n) {
    for(int i=1; i<n; ++i) {
        int j = i - 1;
        int v = data[i];

       // 使用for循环来查找有序部分的正确位置
        for(; j>=0; --j) {
            if(data[j] > v) {
                data[j+1] = data[j];
            } else {
                break;
            }
        }
        data[j+1] = v;
    }
}

int main() {
    int data[] = {3, 5, 4, 1, 2, 6, 7};
    int n = sizeof(data)/sizeof(data[0]);
    insertsortv1(data, n);
    printarray(data, n);
    return 0;
}


/*
Python版本的插入排序
def insertsort(data):
    size = len(data)

    for i in range(1, size):
        tmp = data[i]
        jj = 1
        for j in range(i-1, -1, -1):
            if data[j] > tmp:
                data[j+1] = data[j]
            else:
                jj = j
                break
        data[jj+1] = tmp

def insertsortv2(data):
    size = len(data)
    for i in range(1, size):
        j = i - 1
        tmp = data[i]
        while data[j] > tmp and j>=0:
            data[j+1] = data[j]
            j -= 1
        data[j+1] = tmp

def insertsortv3(data):
    size = len(data)

    for i in range(1, size):
        for j in range(i, 0, -1):
            # 将需要插入的数据放到数组的末尾, 然后通过交换来得到正确的位置
            if data[j-1] > data[j]:
                data[j-1], data[j] = data[j], data[j-1]
 */
