#include <stdio.h>
#include <limits.h>

typedef unsigned int bitset_t;

int main(){
    bitset_t pole[52] = {};
    int k = 0;

    int i = k/32;        //gives the corresponding index in the array A
    int pos = k%32;      //gives the corresponding bit position in A[i]

    unsigned int flag = 1;   // flag = 0000.....00001

    flag = flag << pos;      // flag = 0000...010...000   (shifted k positions)

    pole[i] = pole[i] | flag;      // Set the bit at the k-th position in A[i]

    for(int j = 0; j < 10; j++){
        printf("Prvek[%d]: %d\n", j, pole[j]);
    }
}