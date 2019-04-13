#include <stdio.h>
#include <stdlib.h>
#include "Headers/Functions.h"
int main()
{
    Welcome();

    UserType u = Manager;
    //AddUser();
    User o = {1,"jg","Jordaine","Gayle","1234pass",u,"Riverside Dr","e"};
    printf("\n%s\n",CreateUser(o,UserFileName,"ab+"));

    int si;

printf("\nResult%d\n",UserDataCount());
    //int x = LinearUserSearch(ListOfUsers(),"bobby", "life",'m');
    //printf("\nResult%d\n",x);
    for(int x = 0; x < UserDataCount(); x++){
        printf("UserName: %s - Password: %s - FullName: %s %s - Type: %d\n\n",(ListOfUsers()+x)->Username,(ListOfUsers()+x)->Password, (ListOfUsers()+x)->FirstName, (ListOfUsers()+x)->LastName,(ListOfUsers()+x)->UserType);
    }

    LoginHandler(); //complete

    //printf("Hello world!\n");
    return 0;
}
