#include <stdio.h>
#include <stdlib.h>
#include "Headers/Functions.h"

int main()
{
    Welcome();

    if(file_exists(UserFileName) == 0){

        LoginHandler();

    }else{

        printf("\n\n  First Time Usage require (Manager Role): [*Please Create A Manager Role To Continue*]\n");

        AddUser(1);

        system("cls");

        Welcome();

        LoginHandler();
    }

    return 0;
}
