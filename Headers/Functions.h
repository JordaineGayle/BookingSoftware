#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include "DATAManipulation.h"

void Welcome(){
    system("color f2");
    printf("\t\tWelcome to Artiste Management Jamaica");
    nl(2);
}


void AddUser(int firstTime){

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

    while(firstTime == 1 && (utype != 'm' || utype != 'M') ){

        fflush(stdin);
        printf("\n#ERROR# -> First Time Users Are Required To Be Manager [UserError]\n");
        printf("\nSelect User Type (M - Manager, C - Clerk): ");
        scanf("%c", &utype);

        if(utype == 'M' || utype == 'm'){
            break;
        }

    }


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

    //AddUser();
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


void AddArtiste() {

	Artiste artiste;

	Foundation foundation;

	Accounts aAccount;

	Accounts fAccount;

	printf("\n Add An Artiste\n\n");

	aAccount.Id = AccountsCount() + 1;
	fAccount.Id = aAccount.Id+1;

	foundation.Id = FoundationCount() + 1;

	artiste.Id = ArtisteCount() + 1;

	printf("*********************************************\n");

	printf(" Artiste Info\n\n");

	fflush(stdin);
	printf(" Enter Artiste's Stage Name: ");
	gets(artiste.StageName);

	while (ArtisteExist(artiste.StageName) > -1) {
        fflush(stdin);
		printf("\n#ERROR# -> Artiste Name Already Taken [StageName Error]\n");
		printf(" Enter Artiste's Stage Name: ");
		gets(artiste.StageName);
	}

    fflush(stdin);
	printf("\n Enter Artiste's Firstname: ");
	gets(artiste.FirstName);

	fflush(stdin);
	printf("\n Enter Artiste's Lastname: ");
	gets(artiste.LastName);

	fflush(stdin);
	printf("\n Enter Artiste's Telephone#: ");
	gets(artiste.TelephoneNumber);

	fflush(stdin);
	printf("\n Enter Artiste's PhysicalAddress: ");
	gets(artiste.PhysicalAddress);

	fflush(stdin);
	printf("\n Enter Artiste's Email: ");
	gets(artiste.Email);

	fflush(stdin);
	printf("\n Enter Artiste's Genre: ");
	gets(artiste.Genre);

	fflush(stdin);
	printf("\n Enter Artiste's Account Balance: ");
	scanf("%f",&aAccount.AccountInfo.AccountBalance);

	fflush(stdin);
	printf("\n Enter Artiste's Yearly Earnings: ");
    scanf("%f",&artiste.YearlyEarnings);

    fflush(stdin);
	printf("\n\n*********************************************\n");

	printf(" Foundation Info\n\n");

	fflush(stdin);
	printf(" Enter Foundation Name: ");
	gets(foundation.NameOfFoundation);

	while (FoundationExist(foundation.NameOfFoundation) > -1) {
		fflush(stdin);
		printf("\n#ERROR# -> Foundation Azlready Exist [FoundationName Error]\n");
		printf(" Enter Foundation Name: ");
		gets(foundation.NameOfFoundation);
	}

	fflush(stdin);
	printf("\n Enter Foundation Address: ");
	gets(foundation.Address);

	fflush(stdin);
	printf("\n Enter Foundation Year Founded: ");
	scanf("%d",&foundation.YearFounded);

	fflush(stdin);
	printf("\n Enter Foundation Employee Total: ");
	scanf("%d",&foundation.NumberOfEmployees);

	fflush(stdin);
	printf("\n Enter Foundation Major Charity(Current) : ");
	gets(foundation.MajorityCurCharity);

	fflush(stdin);
	printf(" \nEnter Foundation's Account Balance: ");
    scanf("%f",&fAccount.AccountInfo.AccountBalance);

	int fRes = CreateFoundation(foundation, FoundationFileName, "ab+");
	if (fRes < 0) {
		printf("\n#ERROR# -> Failed To Create Foundation [Internal Error]\n");
		AddArtiste();
	}
	else {

		artiste.FoundationId = fRes;

		int aRes = CreateArtiste(artiste, ArtisteFileName, "ab+");

		if (aRes < 0) {
			printf("\n#ERROR# -> Failed To Create Artiste [Internal Error]\n");
			AddArtiste();
		}
		else {

			int foundationAccNum = randAccNum(10000000, 1000000000);
			Sleep(200);
			int artisteAccNum = randAccNum(10000000, 100000000);

			while (AccountExist(foundationAccNum) > -1) {
				foundationAccNum = randAccNum(10000000, 1000000000);
			}

			while (AccountExist(artisteAccNum) > -1) {
				artisteAccNum = randAccNum(10000000, 100000000);
			}

			fAccount.RefId = fRes;
			fAccount.AccountInfo.AccountNum = foundationAccNum;
			fAccount.AccountInfo.AccountType = FoundationAccount;

			aAccount.RefId = aRes;
			aAccount.AccountInfo.AccountNum = artisteAccNum;
			aAccount.AccountInfo.AccountType = ArtisteAccount;

			int success = CreateAccount(aAccount,AccountsFileName,"ab+");
			Sleep(200);
			int success1 = CreateAccount(fAccount,AccountsFileName,"ab+");

			if (success == 3 && success1 == 3) {
				printf("\nAccount Created Successfully!\n");
			}
			else {
				printf("\n#ERROR# -> An Unexpected Error Has Occured [Internal System Error]\n");
			}

			AddArtiste();

		}


	}

}

void DeleteArtiste() {

    const int totalArtiste = ArtisteCount();

    if(totalArtiste <= 0){
        printf("\n#ERROR# -> Sorry No Artiste Created To Delete [No Artiste Created]\n");
        MenuDelete(Manager);
        //getch();
    }else{

        char selection[40];

	printf("\nDelete A Artiste\n\n");

	printf("\tId\tStage Name\tFirstname\tLastName\tGenre\tYearly Earnings\t\tFoundation\n\n");

	Artiste * ptr = ArtisteList();

	for (int x = 0; x < totalArtiste; x++) {
		fflush(stdin);
		printf("\t%-2d\t%-8s\t%-8s\t%-8s\t%-8s\t%-8.2f\t%-8s\n\n",
			(ptr+x)->Id, (ptr+x)->StageName, (ptr+x)->FirstName,(ptr+x)->LastName,(ptr+x)->Genre, (ptr+x)->YearlyEarnings, (FoundationList()+x)->NameOfFoundation);
	}

	fflush(stdin);
	printf("Select StageName Of Artiste To Delete: ");
	gets(selection);

	int exist = ArtisteExist(selection);

	if (exist > -1) {

		int oldArrayLength = ArtisteCount();

		const int newArrayLength = oldArrayLength - 1;

		Artiste newArtisteList[newArrayLength];

		Foundation newFoundationList[newArrayLength];

		Accounts newAccountList[AccountsCount() - 2];

		int newId = 1;
		int newIndex = 0;
		int newAccLength = 0;

		for (int x = 0; x < oldArrayLength; x++) {

			if (exist != x) {

				Artiste ar;

				ar = *(ArtisteList()+x);

				ar.Id = newId;

				ar.FoundationId = newId;

				newArtisteList[newIndex] = ar;

				newId++;
				newIndex++;
			}

		}

		for(int x = 0; x < newArrayLength; x++){
            newFoundationList[x] = *(delFoundation( (ArtisteList()+exist)->Id) + x);
		}

		for (int x = 0; x < (AccountsCount() - 2); x++) {
			newAccountList[x] = *(delAccount((ArtisteList())->Id) + x);
			newAccLength++;
		}


		for (int x = 0; x < newArrayLength; x++) {
			fflush(stdin);
			printf("\n\n\t%-2d\t%-8s\t%-8s\t%-8s\t%-8s\t%-8.2f\t%-8s\n\n",
				newArtisteList[x].Id, newArtisteList[x].StageName, newArtisteList[x].FirstName, newArtisteList[x].LastName,
				 newArtisteList[x].Genre, newArtisteList[x].YearlyEarnings, newFoundationList[x].NameOfFoundation);
		}

		FILE * file;

		file = fopen(ArtisteFileName,"wb+");

		fwrite(newArtisteList, sizeof(Artiste), newArrayLength, file);

		fclose(file);
        Sleep(200);
		FILE * file1;

		file1 = fopen(FoundationFileName, "wb+");

		fwrite(newFoundationList, sizeof(Foundation), newArrayLength, file1);

		fclose(file1);
        Sleep(200);
		FILE * file2;

		file2 = fopen(AccountsFileName, "wb+");

		fwrite(newAccountList, sizeof(Accounts), newAccLength, file2);

		fclose(file2);




	}
	else {
		printf("\n#ERROR# -> Failed To Delete Artiste [Doesn't Exist]\n");
	}

	DeleteArtiste();
    }
}

void UpdateArtiste() {

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
            AddUser(0);
        }

        while( selection == 'b' || selection == 'B' ){
			AddArtiste();
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

        printf(" a). Delete User\n b). Delete Artiste\n c). Delete Booking\n\n");

        fflush(stdin);
        printf("Select  Option: ");
        scanf("%c", &selection);

        if(selection == 'a' || selection == 'A'){
            DeleteUser();
        }else if( selection == 'b' || selection == 'B' ){
			DeleteArtiste();
        }else if(selection == 'c' || selection == 'C'){

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
        Menu(user.UserType);
    }else{
        printf("Login Failed Please Try Again Later....");
        exit(1);
    }
}




#endif // FUNCTIONS_H_INCLUDED
