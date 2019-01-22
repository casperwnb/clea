#include <stdio.h>
#include <math.h>

// 使用二分法, 逐步逼近
double mysqrt(double num) {
    double low = 1, high = num;
    double mid = low + (high-low)/2;
    double e = 1e-6;
    while(1) {
        double v = mid * mid;
        if(v - num > e) {
            high = mid;
        } else if(num - v > e) {
            low = mid;
        } else {
            return mid;
        }
        mid = low + (high-low)/2;
    }
    return 0;
}

int main() {
    double d = 2;
    printf("%f\n", mysqrt(d));
    printf("%f\n", sqrt(d));
    return 0;
}
