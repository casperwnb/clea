#include <stdio.h>
#include <stdbool.h>

/*
 * 思路:
 * 不要想着直接定位到转折点, 定位转折点之后, 在使用普通二分查找, 其时间复杂度为O(n)
 * 不定位转折点, 只需要知道转折点在中间点的哪一侧即可. 因为不含转折点的一侧一定是单调递增的.
 * 如果data[left] <= data[mid], 则data[mid]一定不在转折点左侧, 即left~mid的整个部分都是递增的.
 * 如果data[left] > data[mid], 则data[mid]一定在转折点的左侧, 即mid~right这个部分是递增的
 */

/*
 * 当有重复元素时, 不一定是第一个位置
 */
int bsearchlooparray(int *data, int n, int v) {
    if (n <= 0) return -1;
    int left=0, right=n-1, mid;
    while(left <= right) {
        mid = left + (right-left)/2;
        if (data[mid] == v) return mid;

        if(data[left] <= data[mid]) {
            if(data[left] <= v && v < data[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if(data[mid] < v && v <= data[right]) {
                left = mid + 1;
            } else {
                right = mid + 1;
            }
        }
    }
    return -1;
}

int bsearchlooparraydup(int *data, int left, int right, int v, int *loc) {
    if(left > right) return false;
    int mid = left + (right-left)/2;
    if(v == data[mid]) {
        *loc = mid;
        return true;
    }

    // data[left], data[mid], data[right]
    // 1 3 5
    if(data[mid] > data[left] && data[mid] < data[right]) { // 普通二分
        if(v < data[mid]) {
            return bsearchlooparraydup(data, left, mid-1, v, loc);
        } else {
            return bsearchlooparraydup(data, mid+1, right, v, loc);
        }
    } else if(data[mid] < data[left] && data[mid] < data[right]) { // 5 1 3, 转折在左侧
        if(v > data[mid] && v <= data[right]) {
            return bsearchlooparraydup(data, mid+1, right, v, loc);
        } else {
            return bsearchlooparraydup(data, left, mid-1, v, loc);
        }
    } else if(data[mid]>data[left] && data[mid] > data[right]) { // 3 5 1, 转折在右侧
        if(v < data[mid] && v >= data[left]) {
            return bsearchlooparraydup(data, left, mid-1, v, loc);
        } else {
            return bsearchlooparraydup(data, mid+1, right, v, loc);
        }
    } else { // 3 3 3, 左中右都相等的情况
        return bsearchlooparraydup(data, left, mid-1, v, loc) ||
        bsearchlooparraydup(data, mid+1, right, v, loc);
    }
}

int main() {
    int data[] = {4, 5, 6, 7, 7, 8, 1, 2, 3, 3, 3, 3};
    int n = sizeof(data)/sizeof(data[0]);
    int v = 7;
    int idx = bsearchlooparray(data, n, v);
    printf("%d\n", idx);

    int i;
    bsearchlooparraydup(data, 0, n, v, &i);
    printf("%d\n", i);
    return 0;
}
