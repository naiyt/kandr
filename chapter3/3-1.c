/* Excerces 3-1

   Our binary search makes two tests inside the loop, when one would
   suffice (at the price of more tests outside). Write a version
   with only one test inside the loop and measure the difference in
   runtime. */

#include <stdio.h>
#include <time.h>
#define MAXARRAYLEN 10 

// The method from the book, to test runtime
int kandrbinsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low+high)/2;
        if(x < v[mid]) {
            high = mid + 1;
        }
        else if (x > v[mid]) {
            low = mid + 1;
        }
        else
            return mid;
    }
    return -1;
}

int myBinSearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0; 
    high = n - 1;

    // Test in the loop declaration whether we're at the right
    // location
    while(low <= high && x != v[mid]) {
        mid = (low+high)/2;
        if(x < v[mid])
            high = mid + 1;
        else
            low = mid + 1;
    }
    return (x == v[mid]) ? mid : -1;
}


main() {
    int arrayTest[MAXARRAYLEN];
    int i;
    for(i = 0; i < MAXARRAYLEN; ++i) {
        arrayTest[i] = i;
        printf("%d - %d\n", arrayTest[i], i);
    }
    printf("Hi");

    clock_t begin, end;
    
    begin = clock();
    for(i = 0; i < 500; i++) {
        printf("First: %d", i);
        kandrbinsearch(-1, arrayTest, MAXARRAYLEN);
    }
    end = clock();
    double timeFirst = (double)(end - begin) / CLOCKS_PER_SEC;

    begin = clock();
    for(i = 0; i < 500; i++) {
        printf("Second: %d", i);
       myBinSearch(-1, arrayTest, MAXARRAYLEN);
    }
    end = clock();
    double timeSecond = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Original: %f\nRevised test: %f\n", timeFirst, timeSecond);

    return 0;
}
