#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include "Manipulation.h"

void Welcome(){
    system("color f2");
    printf("\t\tWelcome to Artiste Management Jamaica");
    nl(2);
}


void MenuA(int userType){
    printf("\n\n\t\tPlease Select What An Add Option Below\n\n");
    char selection;
    if(userType == Manager){
        printf(" a). Add User\n b). Add Artiste\n c). Add Booking\n\n");

        fflush(stdin);
        printf("Select  Option: ");
        scanf("%c", &selection);

        if(selection == 'a' || selection == 'A'){
            AddUser(0);
        }

        while( selection == 'b' || selection == 'B' ){
			AddArtiste();
        }

        if(selection == 'c' || selection == 'C'){
            AddBooking();
        }
    }else{
        //printf(" a). Add Booking\n\n");
        AddBooking();
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

        printf(" a). Delete User\n b). Delete Artiste\n c). Delete Booking\n\n");

        fflush(stdin);
        printf("Select  Option: ");
        scanf("%c", &selection);

        if(selection == 'a' || selection == 'A'){
            DeleteUser();
        }else if( selection == 'b' || selection == 'B' ){
			DeleteArtiste();
        }else if(selection == 'c' || selection == 'C'){
            DeleteBooking();
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
        globalUser = user.UserType;
        LoggedInUser = user.Id;
        Menu(user.UserType);
    }else{
        printf("Login Failed Please Try Again Later....");
        exit(1);
    }
}




#endif // FUNCTIONS_H_INCLUDED
