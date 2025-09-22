#include <stdio.h>

char * get_full_name(char fullName[]){
    return fullName;
}

int main() {
    char fullName1[20] = "Zouhair Folki";
    char fullName2[20] = "Younes Bougam";

    char * pfullName1 = get_full_name(fullName1);
    char * fullName2 = get_full_name(fullName2);

    printf("%s", fullName);
    printf("%s", fullName2);

    return 0;
}