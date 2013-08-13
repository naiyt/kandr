/* Excerces 3-1

   Our binary search makes two tests inside the loop, when one would
   suffice (at the price of more tests outside). Write a version
   with only one test inside the loop and measure the difference in
   runtime. */

// In terms of testing runtimes, I ran them both with arrays of
// 1,000,000 elements, and searched them each 1,000,000 times.
// The original finished in .29 seconds and the revised
// finished in .27 seconds. Negligble difference, so the one with
// better readabilty would likely win in this situation.

#include <stdio.h>
#include <time.h>
#define MAXARRAYLEN 1000000 

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
    mid = (low+high)/2;
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
    }

    clock_t begin, end;
    
    begin = clock();
    for(i = 0; i < 1000000; i++) {
        kandrbinsearch(MAXARRAYLEN+1, arrayTest, MAXARRAYLEN);
    }
    end = clock();
    double timeFirst = (double)(end - begin) / CLOCKS_PER_SEC;

    begin = clock();
    for(i = 0; i < 1000000; i++) {
       myBinSearch(MAXARRAYLEN+1, arrayTest, MAXARRAYLEN);
    }
    end = clock();
    double timeSecond = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Original: %f\nRevised test: %f\n", timeFirst, timeSecond);

    return 0;
}
