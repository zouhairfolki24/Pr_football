#include <stdio.h>

int position_minimum(int integers[], int size_integers) {

    int pos_min = 0;

    for (int i = 1; i < size_integers; i++) {
        if (integers[i] < integers[pos_min]) {
            pos_min = i;
        }
    }

    return pos_min;
}

int main() {
    
    int integers[] = {42, 17, 63};
    int size_integers = sizeof(integers) / sizeof(integers[0]);
    int pos_min, value_temp;

    while (size_integers > 1) { // size_integers = 2
        
        pos_min = position_minimum(integers, size_integers); // ({42, 63, 17})
        
        value_temp = integers[size_integers - 1];
        integers[size_integers - 1] = integers[pos_min];
        integers[pos_min] = value_temp;
    
        size_integers -= 1;

    }

    size_integers = sizeof(integers) / sizeof(integers[0]);

    for (int i = size_integers - 1; i >= 0; i--) {

        printf("%d, ", integers[i]);

    }

    return 0;
}