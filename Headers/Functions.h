#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include "Manipulation.h"
#include "Search.h"

void Welcome(){
    system("color f2");
    printf("\t\tWelcome to Artiste Management Jamaica");
    nl(2);
}

void MenuDisplay(int userType){

    char selection;

    if(userType == Manager){
        st();st();
        printf("\n\t\tDisplay Options\n\n");
        printf(" a). All Users\n b). All Artiste\n c). All Booking\n d). All Foundations\n e). All Reports\n f). Main Menu\n g). Exit\n\n");

    }else{
        st();st();
        printf("\n\t\tDisplay Options\n\n");
        printf("a). All Booking\n b). All Artiste\n c). All Reports\n d). Main Menu\n e). Exit\n\n");
    }

    fflush(stdin);
    printf(" \nSelect a option from above: ");
    scanf("%c", &selection);
    st();st();
    nl(2);
    if(selection == 'a' || selection == 'A'){
       if(userType == Manager){
            DisplayUsers();
            MenuDisplay(globalUser);
       }else{
            DisplayBookings();
            MenuDisplay(globalUser);
       }
    }else if(selection == 'b' || selection == 'B'){
        DisplayArtiste();
        MenuDisplay(globalUser);
    }else if(selection == 'c' || selection == 'C'){
        if(userType==Manager){
            DisplayBookings();
            MenuDisplay(globalUser);
        }else{
            DisplaySavedReports();
        }
    }else if(selection == 'd' || selection == 'D'){
        if(userType==Manager){
            DisplayFoundation();
            MenuDisplay(globalUser);
        }else{
            Menu(userType);
        }
    }else if(selection == 'e' || selection == 'E'){
        if(userType==Manager){
            DisplaySavedReports();
            MenuDisplay(globalUser);
        }else{
            exitProgram();
        }
    }else if( (selection == 'f' || selection == 'F') && userType == Manager){
        Menu(userType);
    }else if( (selection == 'G' || selection == 'g') && userType == Manager){
        exitProgram();
    }else{
		    printf("#\nERROR# -> Please select a valid option [Option Error]\n\n");
            MenuDisplay(globalUser);
    }

}

void MenuA(int userType){
    st();st();
    printf("\n\n\t\t\t\t*Please Select an Option Below*\n\n");
    char selection;
    if(userType == Manager){
        printf(" a). Add User\n b). Add Artiste\n c). Add Booking\n d). Main Menu\n e). Exit Software\n\n");

        fflush(stdin);
        printf("Select  Option: ");
        scanf("%c", &selection);

        if(selection == 'a' || selection == 'A'){
            AddUser(0);
        }else if( selection == 'b' || selection == 'B' ){
			AddArtiste();
        }else if(selection == 'c' || selection == 'C'){
            AddBooking();
        }else if(selection == 'd' || selection == 'D'){
            Menu(globalUser);
		}else if(selection == 'e' || selection == 'e'){
            exitProgram();
		}else{
		    printf("#\nERROR# -> Please select a valid option [Option Error]\n\n");
            MenuA(globalUser);
		}
    }else{
        AddBooking();
    }
}

void MenuB(int userType){
    st();st();
    printf("\n\n\t\t\t\t*Please Select an Option Below*\n\n");
    char selection;
    if(userType == Manager){
        printf(" a). Update User\n b). Update Artiste\n c). Main Menu\n d). Exit Software\n\n");

        fflush(stdin);
        printf(" Select  Option: ");
        scanf("%c", &selection);

        if(selection == 'a' || selection == 'A'){
            UpdateUser();
        }else if( selection == 'b' || selection == 'B' ){
			updateMenu();
        }else if(selection == 'C' || selection == 'c'){
            Menu(globalUser);
        }else if(selection == 'D' || selection == 'd'){
            exitProgram();
        }else{
		    printf("#\nERROR# -> Please select a valid option [Option Error]\n\n");
            MenuB(globalUser);
		}
    }else{
        UpdateBooking();
    }
}

void MenuDelete(int userType){

    st();st();
    printf("\n\n\t\t\t\t*Please Select an Option Below*\n\n");

    if(userType == Manager){

        char selection;

        printf(" a). Delete User\n b). Delete Artiste\n c). Delete Booking\n d). Main Menu\n e). Exit Software\n\n");

        fflush(stdin);
        printf("Select  Option: ");
        scanf("%c", &selection);

        if(selection == 'a' || selection == 'A'){
            DeleteUser();
        }else if( selection == 'b' || selection == 'B' ){
			DeleteArtiste();
        }else if(selection == 'c' || selection == 'C'){
            DeleteBooking();
		}else if(selection == 'd' || selection == 'D'){
            Menu(globalUser);
		}else if(selection == 'e' || selection == 'e'){
            exitProgram();
		}else{
		    printf("#\nERROR# -> Please select a valid option [Option Error]\n\n");
            MenuDelete(globalUser);
		}

    }
}

void MenuSearch(int userType){

    char selection;
    nl(2);
    st();st();
    printf("\n\n\t\t\t\t*Please Select an Option Below*\n\n");

    if(userType == Manager){

        st();st();
        printf("\n\n a). QueryUserById\n b). QueryUserByUser-name\n c). QueryArtisteById\n d). QueryArtisteStageName\n");
        printf(" e). QueryFoundationById\n f). QueryFoundationByDateFounded\n g). QueryBookingByBookingNumber\n h). QueryBookingByArtisteId\n");
        printf(" i). QueryBookingByDate\n j). QueryBookingByPromoterName\n k). QueryBookingByEmployeeId\n\n");
    }else{
        st();st();
        printf("\n\n a). QueryArtisteById\n b). QueryArtisteStageName\n");
        printf(" c). QueryBookingByBookingNumber\n d). QueryBookingByArtisteId\n");
        printf(" e). QueryBookingByDate\n f). QueryBookingByPromoterName\n g.) QueryBookingByEmployeeId\n\n");
    }

    printf("\n\n * 1 Exit Program * \n");
    printf(" * 2 Main Menu * \n");

    fflush(stdin);
    printf("\n Enter Query Option: ");
    scanf("%c",&selection);



        if(selection == '1'){
            exitProgram();
        }else if(selection == '2'){
            Menu(globalUser);
        }

    if(selection == 'a' || selection == 'A'){

        if(userType==Manager){
            SearchUserById();

        }else{
            SearchArtisteById();
        }

    }else if(selection == 'b' || selection == 'B'){

        if(userType==Manager){
            SearchUserByUsername();
        }else{
            SearchArtisteByStageName();
        }

    }else if(selection == 'c' || selection == 'C'){

        if(userType==Manager){
            SearchArtisteById();

        }else{
            SearchBookingByBookingNumber();
        }

    }else if(selection == 'd' || selection == 'D'){

        if(userType==Manager){
            SearchArtisteByStageName();
        }else{
            SearchBookingByArtisteId();
        }

    }else if(selection == 'e' || selection == 'E'){

        if(userType==Manager){
            SearchFoundationById();

        }else{
            SearchBookingByDate();
        }

    }else if(selection == 'f' || selection == 'F'){

        if(userType==Manager){
            SearchFoundationByDateFounded();
        }else{
            SearchBookingByPromoterName();
        }

    }else if(selection == 'g' || selection == 'G'){

        if(userType==Manager){
            SearchBookingByBookingNumber();
        }else{
            SearchBookingByEmployeeId();
        }

    }else if( (selection == 'h' || selection == 'H') && userType == Manager){

        SearchBookingByArtisteId();

    }else if( (selection == 'i' || selection == 'I')  && userType == Manager){

        SearchBookingByDate();

    }else if( (selection == 'j' || selection == 'J')  && userType == Manager){

        SearchBookingByPromoterName();

    }else if( (selection == 'k' || selection == 'K')  && userType == Manager){

        SearchBookingByEmployeeId();

    }else{
        printf("\n#ERROR# -> Please select a valid option [Option Error]\n\n");
    }

    MenuSearch(userType);
}

void MenuReport(){

    st();st();
    printf("\n\n\t\t\t\t*Please Select a Option Below*\n\n");

    printf(" a). Artiste Yearly Earning Report\n b). Generate Invoice\n c). Main Menu\n d). Exit");

    char selection;
    fflush(stdin);
    printf("\n Enter Option: ");
    scanf("%c", &selection);

    st();st();
    nl(2);

    if(selection == 'a' || selection == 'A'){
        ArtisteYearlyReport();
    }else if(selection == 'b' || selection == 'B'){
        GenerateInvoice();
    }else if(selection == 'C' || selection == 'c'){
        Menu(globalUser);
    }else if(selection == 'D' || selection == 'd'){
        exitProgram();
    }else{
        printf("\n\n#ERROR# -> Invalid Option Selected\n\n");
    }

    MenuReport();

}

int Login(){

    char tempUsername[100];
    char tempPassword[100];
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


void Menu(int userType){

    heading("Menu");
    char menuSelection;

    if(userType == Manager){
        printf("\n\n a). Add\n b). Update\n c). Delete\n d). Search\n e). Generate Report\n f). View/Display Records");
    }else{
        printf("\n\n a). Add\n b). Update\n c). Search\n d). Generate Report\n e). View/Display Records");
    }

    printf("\n\n\t*************************\n");
    printf("\t*\t\t\t*\n");
    printf("\t* 0). To Exit Program\t*\n");
    printf("\t* 1). To Re-Login\t*\n");
    printf("\t*\t\t\t*");
    printf("\n\t*************************");

    fflush(stdin);
    printf("\n\n Select Option: ");
    scanf("%c",&menuSelection);


    if(menuSelection == '0'){
        exitProgram();
    }else if(menuSelection == '1'){
        system("cls");
        Welcome();
        LoginHandler();
    }

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

            MenuReport();
        }
    }else if( (menuSelection == 'e' || menuSelection == 'E')){

        if(userType == Manager){
            MenuReport();
        }else{
            MenuDisplay(userType);
        }
    }else if( (menuSelection == 'f' || menuSelection == 'F')  && userType==Manager){
        MenuDisplay(userType);
    }
    else{
        printf("\n\n#ERROR# -> Invalid Menu Option\n");
        Menu(userType);
    }
}

#endif // FUNCTIONS_H_INCLUDED
