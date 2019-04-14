#include <stdio.h>
#include <stdlib.h>
#include "Headers/Functions.h"
int main()
{
    Welcome();

    //UserType u = Manager;
    printf("\nUserdata count: %d\n",UserDataCount());
    //AddUser();
    //DeleteUser();
    for(int x = 0; x < UserDataCount(); x++){
        printf("UserName: %s - Password: %s - FullName: %s %s - Type: %d -  Date: %s - ID: %d\n\n",(ListOfUser()+x)->Username,(ListOfUser()+x)->Password, (ListOfUser()+x)->FirstName, (ListOfUser()+x)->LastName,(ListOfUser()+x)->UserType,(ListOfUser()+x)->DateJoined, (ListOfUser()+x)->Id);
    }

    LoginHandler(); //complete

    //printf("Hello world!\n");
    return 0;
}
