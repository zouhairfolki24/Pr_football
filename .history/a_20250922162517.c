#include <stdio.h>

char * full_name(char fullName[]){
    return fullName;
}

int main() {
    char fullName1[20] = "Zouhair Folki";
    char fullName2[20] = "Younes Bougam";

    char * fullName1 = full_name(fullName1);
    char * fullName2 = full_name(fullName2);

    printf("%s", fullName);
    printf("%s", fullName2);

    return 0;
}