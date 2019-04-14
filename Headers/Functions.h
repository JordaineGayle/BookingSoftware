#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include "DATAManipulation.h"
void Welcome(){
    system("color f2");
    printf("\t\tWelcome to Artist Management");
    nl(2);
}


void AddUser(){

    User newuser;

    char utype;

    printf("\nAdd A System User\n");

    newuser.Id = UserDataCount()+1;

    fflush(stdin);
    printf("Enter First Name: ");
    gets(newuser.FirstName);

    fflush(stdin);
    printf("\nEnter Last Name: ");
    gets(newuser.LastName);

    fflush(stdin);
    printf("\nEnter System Username: ");
    gets(newuser.Username);

    fflush(stdin);
    printf("\nEnter System Password: ");
    gets(newuser.Password);

    fflush(stdin);
    printf("\nEnter Address: ");
    gets(newuser.Address);

    fflush(stdin);
    printf("\nSelect User Type (M - Manager, C - Clerk): ");
    scanf("%c", &utype);


    if(utype == 'M' || utype == 'm'){
        newuser.UserType = Manager;
    }else{
        newuser.UserType = Clerk;
    }

    time_t now;
	time(&now);
	ctime(&now);

    strcpy(newuser.DateJoined,ctime(&now));

    int result = CreateUser(newuser, UserFileName, "ab+");

    if(result == 1){
            fflush(stdin);
        printf("\n#ERROR# -> The Free Version Only Allows 3 Users, [Upgrade Membership Plan]\n");
    }else if(result == 2){
        fflush(stdin);
        printf("\n#ERROR# -> Duplicate Data Detected [Already Exist]\n");
    }else if(result == 3){
        fflush(stdin);
        printf("\nRecord Added Successfully!\n");
    }else{
        fflush(stdin);
        printf("\nAn Error Has Occurred\n");
    }

    AddUser();
}

void DeleteUser(){

    int selection;

    printf("\nDelete A user\n\n");

    printf("\tId\tUsername\tFirstname\tLastname\tUserType\tAddress\t\tDateJoined\n\n");

    const int totalUsers = UserDataCount();

    User * ptr = ListOfUser();

    for(int x = 0; x < totalUsers; x++){

        fflush(stdin);
        printf("\t%-2d\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\n\n",
               (ptr+x)->Id, (ptr+x)->Username, (ptr+x)->FirstName,
               (ptr+x)->LastName, (ptr+x)->UserType == Manager ? "Manager" : "Clerk",
                (ptr+x)->Address, (ptr+x)->DateJoined);

    }

    printf("Select Id Of User To Delete: ");
    scanf("%d", &selection);


    int exist = UserExist(selection);

    if(exist >- 1){

        const int newArrayLength = UserDataCount()-1;

        int oldArrayLength = UserDataCount();

        printf("\nNew Array: %d\nOld Array: %d\nExist: %d\n",newArrayLength,oldArrayLength,exist);

        User newUserList[newArrayLength];

        int newId = 1;
        int k = 0;
        //User *ptr2 = ListOfUser();
        for(int x = 0; x < oldArrayLength; x++){

                printf("\n\nValue of x: %d\n\n",x);

                if(exist != x){
                    //(ptr2+x)->Id = newId;
                    User ob;
                    ob = *(ListOfUser()+x);
                    ob.Id = newId;
                    newUserList[k] = ob;
                    newId++;
                    k++;
                }

        }

        printf("\n\nNew List\n\n");

        printf("\tId\tUsername\tFirstname\tLastname\tUserType\tAddress\t\tDateJoined\n\n");

        for(int x = 0; x < newArrayLength; x++){

        fflush(stdin);
        printf("\t%-2d\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\n\n",
               newUserList[x].Id, newUserList[x].Username, newUserList[x].FirstName,
               newUserList[x].LastName, newUserList[x].UserType == Manager ? "Manager" : "Clerk",
                newUserList[x].Address, newUserList[x].DateJoined);

        }

        FILE * newFile = fopen(UserFileName, "wb+");
        //fseek(newFile, 0)
        if(fwrite(newUserList,sizeof(User), newArrayLength, newFile)){
            printf("\nNew User Successfully Deleted!\n");
        }else{
           printf("\n#ERROR# -> Failed To Delete User [Internal Error]\n");
        }

        fclose(newFile);



    }else{
        printf("\n#ERROR# -> User you are trying to delete doesn't exist! [False]\n");
    }

    DeleteUser();
}


void MenuA(int userType){
    printf("\n\n\t\tPlease Select What An Add Option Below\n\n");
    char selection;
    if(userType == Manager){
        printf(" a). Add User\n c). Add Artiste\n c). Add Booking\n\n");

        fflush(stdin);
        printf("Select  Option: ");
        scanf("%c", &selection);

        if(selection == 'a' || selection == 'A'){
            AddUser();
        }

        while( selection == 'b' || selection == 'B' ){

        }



        if(selection == 'c' || selection == 'C'){

        }
    }else{
        printf(" a). Add Booking\n\n");
    }
}

void MenuB(int userType){
    printf("\n\n\t\tPlease Select What An Add Option Below\n\n");
    if(userType == Manager){
        printf(" a). Update User\n c). Update Artiste\n c). Update Booking\n\n");
    }else{
        printf(" a). Update Booking\n\n");
    }
}

void MenuDelete(int userType){

    printf("\n\n\t\tPlease Select What An Add Option Below\n\n");

    if(userType == Manager){

        char selection;

        printf(" a). Delete User\n c). Delete Artiste\n c). Delete Booking\n\n");

        fflush(stdin);
        printf("Select  Option: ");
        scanf("%c", &selection);

        if(selection == 'a' || selection == 'A'){
            DeleteUser();
        }

        while( selection == 'b' || selection == 'B' ){

        }



        if(selection == 'c' || selection == 'C'){

        }
    }
}

void MenuSearch(int userType){
    printf("\n\n\t\tPlease Select What An Add Option Below\n\n");
    if(userType == Manager){
        st();
        printf("\n\t\tDisplay Options\n\n");
        printf(" a). All Users\n b). All Artiste\n c). All Booking\n d). All Foundations\n e). All Reports\n\n");
        st();
        printf("\n\t\tSearch Options\n\n");
        printf(" a). QueryUserById\n b). QueryUserByName\n c). QueryUserByEmail\n d). QueryUserByType\n");
        printf(" e). QueryArtisteById\n f). QueryUserByName\n g). QueryArtisteByStageName\n h). QueryArtisteByGenre\n");
        printf(" i). QueryBookingById\n j). QueryBookingByArtisteId\n k). QueryBookingByEmployeeId\n l). QueryArtisteByType\n");
        printf(" m). QueryByBookingNumber\n n). QueryArtisteByFoundationId\n");
    }else{
        st();
        printf("\n\t\tDisplay Options\n\n");
        printf("a). All Booking\n b). All Artiste\n c). All Reports\n\n");
        st();
        printf("\n\t\tSearch Options\n\n");
        printf(" a). QueryBookingById\n b). QueryBookingByArtisteId\n c). QueryBookingByEmployeeId\n d). QueryArtisteByType\n");
        printf(" e). QueryByBookingNumber\n");
    }
}

void MenuReport(){

    printf("\n\n\t\tPlease Select What An Add Option Below\n\n");

    printf(" a). Artiste Report\n b). Foundation Report");

}





int Login(){

    char tempUsername[25];
    char tempPassword[25];
    char pass;
    char userType;
    int index = 0;


    nlm(2);

    printf("\t\tLogin Area\n\n");

    fflush(stdin);
    printf("\t\t\tUsername: ");
    gets(tempUsername);

    fflush(stdin);
    printf("\n\t\t\tPassword: ");

    memset(tempPassword,0,sizeof tempPassword);

    while( (pass = _getch()) != '\n'){
        if(pass == 13){
            index+=1;
            tempPassword[index] = '\0';
            printf("\n");
            break;
        }else if(pass == 9 || pass == 32){

        }else if(pass == 8){
            fflush(stdin);
            index-=1;
            tempPassword[index] = ' ';
            printf("\b \b");
            if(index <= -1){
                system("cls");
                Welcome();
                printf("\t\t\tPassword: ");
                index=0;
            }
        }else{
            tempPassword[index] = pass;
            fflush(stdin);
            _putch('*');
            index++;
        }
    }

    fflush(stdin);
    printf("\n\t\t\tUserType (M or C): ");
    scanf("%c",&userType);

    nlm(2);

    int indexed = LinearUserSearch(tempUsername, tempPassword, userType);

    if(indexed > -1 && indexed < 3){
        return indexed;
    }

    return -1;

}

void Menu(int userType){

    heading("Menu");
    char menuSelection;

    if(userType == Manager){
        printf("\n\n a). Add\n b). Update\n c). Delete\n d). Search\n e). Generate Report");
    }else{
        printf("\n\n a). Add\n b). Update\n c). Search\n d). Generate Report");
    }


    fflush(stdin);
    printf("\n\nSelect Option: ");
    scanf("%c",&menuSelection);

    if(menuSelection == 'a' || menuSelection == 'A'){

        MenuA(userType);

    }else if(menuSelection == 'b' || menuSelection == 'B'){

        MenuB(userType);

    }else if(menuSelection == 'c' || menuSelection == 'C'){

        if(userType == Manager){

            MenuDelete(userType);

        }else{

            MenuSearch(userType);
        }

    }else if(menuSelection == 'd' || menuSelection == 'D'){

        if(userType == Manager){

            MenuSearch(userType);

        }else{

            MenuReport(userType);
        }
    }else if( (menuSelection == 'e' || menuSelection == 'E') && userType==Manager){

        MenuReport();

    }
    else{
        printf("\n\n#ERROR# -> Invalid Menu Option\n");
        Menu(userType);
    }

    Menu(userType);
}

void LoginHandler(){
    int loginStatus = Login();

    int errorCount = 3;

    while(loginStatus <= -1 && errorCount > 0){
        printf("#Login Error# | Attempts Left: %d\n",errorCount);
        loginStatus = Login();
        errorCount--;
    }

    if(loginStatus > -1){
        User user = *(ListOfUser()+loginStatus);
        printf("Welcome, %s %s", user.FirstName, user.LastName);
        Menu(user.UserType);
    }else{
        printf("Login Failed Please Try Again Later....");
        exit(1);
    }
}




#endif // FUNCTIONS_H_INCLUDED
