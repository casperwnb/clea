#include <stdio.h>

// 时间复杂度O(N^3), 空间复杂度O(1)
int maxsubarrayv1(int *data, int size) {
    int maxresult=data[0], tmpsum=0;
    int startidx, endidx;
    for(int i=0; i<size; ++i) {
        for(int j=i; j<size; ++j) {
            tmpsum = 0;

            // 计算i与j之间数据和
            for(int k=i; k<=j; ++k) {
                tmpsum += data[k];
            }

            if(maxresult < tmpsum) {
                maxresult = tmpsum;
                startidx = i;
                endidx = j;
            }
        }
    }
    printf("startidx: %d, endidx: %d\n", startidx, endidx);
    return maxresult;
}

// 时间复杂度O(N^2), 空间复杂度O(1)
int maxsubarrayv2(int *data, int size) {
    int maxresult=data[0], tmpsum=0;
    int startidx, endidx;
    for(int i=0; i<size; ++i) {
        tmpsum = 0;
        for(int j=i; j<size; ++j) {
            // 计算i到j之间的和, 并且记录当前的最大值
            tmpsum += data[j];
            if(maxresult < tmpsum) {
                maxresult = tmpsum;
                startidx = i;
                endidx = j;
            }
        }
    }
    printf("startidx: %d, endidx: %d\n", startidx, endidx);
    return maxresult;
}

// 时间复杂度O(NlgN)
// 使用递归: 最大值可能出现的情况分三种, 左边, 中间(左边+右边的和), 右边
// 该方法对全部是负数的情况不满足
int maxsubarrayv3(int *data, int left, int right) {
    int maxleftsum, maxrightsum;
    int maxleftbordersum, maxrightbordersum;
    int leftbordersum, rightbordersum;
    int center, i, maxsum=data[0];

    if(left == right) {
        return data[left]>0 ? data[left] : 0;
    }

    center = left + (right-left)/2;
    maxleftsum = maxsubarrayv3(data, left, center);
    maxrightsum = maxsubarrayv3(data, center+1, right);

    maxleftbordersum = 0;
    leftbordersum = 0;
    for(i=center; i>=left; --i) {
        leftbordersum += data[i];
        if(leftbordersum > maxleftbordersum) {
            maxleftbordersum = leftbordersum;
        }
    }

    maxrightbordersum = rightbordersum = 0;
    for(i=center+1; i<=right; ++i) {
        rightbordersum += data[i];
        if(rightbordersum > maxrightbordersum) {
            maxrightbordersum = rightbordersum;
        }
    }
    maxsum = maxleftsum > maxrightsum ? maxleftsum : maxrightsum;
    maxsum = maxsum > maxleftbordersum + maxrightbordersum ? maxsum : maxleftbordersum + maxrightbordersum;
    return maxsum;
}

// 时间复杂度O(N), 空间复杂度O(1)
int maxsubarrayv4(int *data, int size) {
    #ifdef FLAG
    // flag的作用: 当数组中的数据全部为负数时, 防止结果的最大值变为0
    int maxresult=data[0], tmpsum=0, flag=1;
    for(int i=0; i<size; ++i) {
        flag = 1;
        tmpsum += data[i];
        if(tmpsum < 0) {
            tmpsum = 0;
            flag = 0;
        }
        if(flag && maxresult < tmpsum) {
            maxresult = tmpsum;
        }
        if(flag == 0) { // 依次比较一次即可
            if(maxresult < data[i]) {
                maxresult = data[i];
            }
        }
    }
    return maxresult;
    #else
    int maxresult=data[0], tmpsum = 0;
    for(int i=0; i<size; ++i) {
        tmpsum += data[i];
        // 当tmpsum大于零时才进行大小的判断
        if(tmpsum > 0 && maxresult < tmpsum) {
            maxresult = tmpsum;
        } else {
            tmpsum = 0;
            maxresult = maxresult > data[i] ? maxresult : data[i];
        }
    }
    return maxresult;
    #endif
}

int main() {
    int data[] = {-20, 3, -2, 7, -9, -10, -11};
    int size = sizeof(data) / sizeof(data[0]);
    int r1 = maxsubarrayv1(data, size);
    int r2 = maxsubarrayv2(data, size);
    int r3 = maxsubarrayv3(data, 0, size-1);
    int r4 = maxsubarrayv4(data, size);
    printf("r1: %d, r2: %d, r3: %d, r4: %d\n", r1, r2, r3, r4);
    return 0;
}
