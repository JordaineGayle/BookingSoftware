#include <stdio.h>
#include <stdlib.h>
#include "Headers/Functions.h"
int main()
{
    Welcome();

    /*for(int x = 0; x < 3; x++){
        printf("UserName: %s - Password: %s - FullName: %s %s\n\n",(ListOfUsers()+x)->Username,(ListOfUsers()+x)->Password, (ListOfUsers()+x)->FirstName, (ListOfUsers()+x)->LastName);
    }*/

    LoginHandler(); //complete



    //printf("Hello world!\n");
    return 0;
}
