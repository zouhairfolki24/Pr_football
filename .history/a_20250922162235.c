#include <stdio.h>

char * full_name(char fullName[]){
    return fullName;
}

int main() {
    char * fullName = full_name("Zouhair Folki");

    printf("%s", fullName);

    return 0;
}