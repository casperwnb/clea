#include <stdio.h>

// 查找第一个值等于给定值的元素, 好理解的版本
// 当data[mid] != v时, 与普通的二分查找一样,
// 当data[mid] == v时, 此时就需要进行判断,
// 当mid == 0时, 此时就是第一个元素了, 可以直接返回
// 当data[mid-1] != v时, 说明当前mid的值就是第一个出现的值, 直接返回
// 当data[mid-1] == v时, 说明此时的mid一定不是第一个出现的值, 即将
// 查找范围变为low~mid-1之间, 再进行二分查找.
int bfirstsearch(int *data, int n, int v) {
    int low=0, high=n-1, mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        if(data[mid] > v) {
            high = mid - 1;
        } else if(data[mid] < v) {
            low = mid + 1;
        } else {
            if(mid == 0 || data[mid-1] != v) return mid;
            else high = mid - 1;
        }
    }
    return -1;
}

// 理解:
// 当有多个重复的数据时, 第一次找到的mid不一定是第一个, 但0~mid之间一定是存在该数据的
// 此时将查找空间缩小为low~mid-1, 分两种情况:
// 1. low~mid-1之间没有需要查找的值, 此时随着查找的进行, low的值会逐步增加直到==high+1
// 而此时的low恰好就是数组中第一次出现的值
// 2. low~mid-1之间有查找的数据, 此时high=high-1, 如果有多个, 则会随着查找的进行会演变
// 为情形1
int bfirstsearchhard(int *data, int n, int v) {
    int low=0, high=n-1, mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        printf("mid=%d\n", mid);
        if(data[mid] < v) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // low一定是小于n的, 所以可以不用判断
    if(data[low] == v) return low;
    else return -1;
}

int main() {
    int data[] = {1, 3, 4, 5, 6, 6, 6, 7, 8};
    int n = sizeof(data)/sizeof(data[0]);
    int idx = bfirstsearchhard(data, n, 6);
    printf("%d\n", idx);
    return 0;
}
