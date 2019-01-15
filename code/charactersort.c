#include <stdio.h>

void charactersort(char *data, int n) {
    int i=0, j=n-1;
    while(i != j) {
        while(i < j && 'a'<=data[i] && data[i]<='z') ++i;
        while(i < j && 'A'<=data[j] && data[j]<='Z') --j;
        if(i < j) {
            char t = data[i];
            data[i] = data[j];
            data[j] = t;
        }
    }
}

void printarray(char *data, int n) {
    for(int i=0; i<n; ++i) {
        printf("%c ", data[i]);
    }
    printf("\n");
}

int main() {
    char data[] = {'D', 'a', 'F', 'B', 'c', 'A', 'z', 'S'};
    int n = sizeof(data)/sizeof(data[0]);
    charactersort(data, n);
    printarray(data, n);
    return 0;
}
