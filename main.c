#include <stdio.h>
#include <stdlib.h>
#include "Headers/Functions.h"
int main()
{
    Welcome();

    UserType u = Manager;
    //AddUser();
    User o = {1,"jg","Jordaine","Gayle","1234pass",u,"Riverside Dr","e"};
    printf("\n%d\n",CreateUser(o,UserFileName,"ab+"));

    printf("\nResult%d\n",UserDataCount());
    //int x = LinearUserSearch(ListOfUsers(),"bobby", "life",'m');
    //printf("\nResult%d\n",x);
    for(int x = 0; x < UserDataCount(); x++){
        printf("UserName: %s - Password: %s - FullName: %s %s - Type: %d -  Date: %s - ID: %d\n\n",(ListOfUser()+x)->Username,(ListOfUser()+x)->Password, (ListOfUser()+x)->FirstName, (ListOfUser()+x)->LastName,(ListOfUser()+x)->UserType,(ListOfUser()+x)->DateJoined, (ListOfUser()+x)->Id);
    }

    LoginHandler(); //complete

    //printf("Hello world!\n");
    return 0;
}
