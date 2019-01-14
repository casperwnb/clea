#include <stdio.h>

// 正常情况下的查找代码
int normalfind(char *data, int n, char key) {
    if (data == NULL || n <= 0) {
        return -1;
    }
    int i = 0;
    // 这段代码比下一段代码多了一个i<n的比较, 当数据量很大的时候累计的时间就很明显了
    while(i < n) {  
        if(data[i] == key) {
            return i;
        }
        ++i;
    }
    return -1;
}

// 利用哨兵来进行线性查找
int guardfind(char *data, int n, char key) {
    if(data == NULL || n <= 0) {
        return -1;
    }

    if(data[n-1] == key)
        return n-1;

    char tmp = data[n-1];
    data[n-1] = key;
    int i = 0;
    while(data[i] != key) {
        ++i;
    }
    data[n-1] = tmp;
    if (i == n-1)
        return -1;
    return i;
}

int main() {
    char a[] = {4, 2, 3, 5, 9, 6};
    int n = sizeof(a)/sizeof(a[0]);
    int l = normalfind(a, n, 10);
    printf("%d\n", l);
    return 0;
}
