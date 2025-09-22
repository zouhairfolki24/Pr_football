#include <stdio.h>

char * full_name(char fullName[]){
    return fullName;
}

int main() {
    char * fullName = full_name("Zouhair Folki");
    char * fullName2 = full_name("Younes Bougam");

    printf("%s", fullName);
    printf("%s", fullName);

    return 0;
}