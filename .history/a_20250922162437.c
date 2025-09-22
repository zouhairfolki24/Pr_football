#include <stdio.h>

char * full_name(char fullName[]){
    return fullName;
}

int main() {
    char fullName1[20];
    char fullName2[20]

    char * fullName = full_name("Zouhair Folki");
    char * fullName2 = full_name("Younes Bougam");

    printf("%s", fullName);
    printf("%s", fullName2);

    return 0;
}