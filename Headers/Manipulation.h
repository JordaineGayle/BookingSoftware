#ifndef MANIPULATION_H_INCLUDED
#define MANIPULATION_H_INCLUDED
#include "DATAManipulation.h"
#include "Display.h"
#include "Functions.h"

void Menu(int);

void MenuA(int);

void MenuB(int);

void MenuReport();

void MenuSearch();

void MenuDelete(int);

void AddUser(int firstTime){

    User newuser;

    char utype;

    printf("\n\n *Add A System User*\n\n");

    printf(" * -1 Exit Program* \n");
    printf(" * -2 Prevoius Menu* \n");
    printf(" * -3 Main Menu* \n\n");

    newuser.Id = UserDataCount()+1;

    fflush(stdin);
    printf("Enter First Name: ");
    gets(newuser.FirstName);
    if(strcmpi(newuser.FirstName,"-1") == 0){
        exitProgram();
    }else if(strcmpi(newuser.FirstName,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(newuser.FirstName,"-3") == 0){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\nEnter Last Name: ");
    gets(newuser.LastName);
    if(strcmpi(newuser.LastName,"-1") == 0){
        exitProgram();
    }else if(strcmpi(newuser.LastName,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(newuser.LastName,"-3") == 0){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\nEnter System Username: ");
    gets(newuser.Username);
    if(strcmpi(newuser.Username,"-1") == 0){
        exitProgram();
    }else if(strcmpi(newuser.Username,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(newuser.Username,"-3") == 0){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\nEnter System Password: ");
    gets(newuser.Password);
    if(strcmpi(newuser.Password,"-1") == 0){
        exitProgram();
    }else if(strcmpi(newuser.Password,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(newuser.Password,"-3") == 0){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\nEnter Address: ");
    gets(newuser.Address);
    if(strcmpi(newuser.Address,"-1") == 0){
        exitProgram();
    }else if(strcmpi(newuser.Address,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(newuser.Address,"-3") == 0){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\nSelect User Type (M - Manager, C - Clerk): ");
    scanf("%c", &utype);
    if(utype=='1'){
        exitProgram();
    }else if(utype=='2'){
        MenuA(globalUser);
    }else if(utype=='3'){
        Menu(globalUser);
    }


    while(firstTime == 1 && (utype != 'm' || utype != 'M') ){

        fflush(stdin);
        printf("\n#ERROR# -> First Time Users Are Required To Be Manager [UserError]\n");
        printf("\nSelect User Type (M - Manager, C - Clerk): ");
        scanf("%c", &utype);
        if(utype=='1'){
        exitProgram();
    }else if(utype=='2'){
        MenuA(globalUser);
    }else if(utype=='3'){
        Menu(globalUser);
    }

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

    AddUser(0);
}

void DeleteUser(){

    int selection;

    printf("\nDelete A user\n\n");

    printf(" * -1 Exit Program* \n");
    printf(" * -2 Prevoius Menu* \n");
    printf(" * -3 Main Menu* \n\n");

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
    if(selection == -1){
        exitProgram();
    }else if(selection == -2){
        MenuDelete(globalUser);
    }else if(selection == -3){
        Menu(globalUser);
    }


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

	printf("\n *Add An Artiste*\n\n");

	printf(" * -1 Exit Program * \n");
    printf(" * -2 Prevoius Menu * \n");
    printf(" * -3 Main Menu * \n\n");

	aAccount.Id = AccountsCount() + 1;
	fAccount.Id = aAccount.Id+1;

	foundation.Id = FoundationCount() + 1;

	artiste.Id = ArtisteCount() + 1;

	printf("*********************************************\n");

	printf(" *Artiste Info*\n\n");

	fflush(stdin);
	printf(" Enter Artiste's Stage Name: ");
	gets(artiste.StageName);
	if(strcmpi(artiste.StageName,"-1") == 0){
        exitProgram();
    }else if(strcmpi(artiste.StageName,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(artiste.StageName,"-3") == 0){
        Menu(globalUser);
    }

	while (ArtisteExist(artiste.StageName) > -1) {
        fflush(stdin);
		printf("\n#ERROR# -> Artiste Name Already Taken [StageName Error]\n");
		printf(" Enter Artiste's Stage Name: ");
		gets(artiste.StageName);
		if(strcmpi(artiste.StageName,"-1") == 0){
        exitProgram();
    }else if(strcmpi(artiste.StageName,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(artiste.StageName,"-3") == 0){
        Menu(globalUser);
    }
	}

    fflush(stdin);
	printf("\n Enter Artiste's Firstname: ");
	gets(artiste.FirstName);
	if(strcmpi(artiste.FirstName,"-1") == 0){
        exitProgram();
    }else if(strcmpi(artiste.FirstName,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(artiste.FirstName,"-3") == 0){
        Menu(globalUser);
    }

	fflush(stdin);
	printf("\n Enter Artiste's Lastname: ");
	gets(artiste.LastName);
	if(strcmpi(artiste.LastName,"-1") == 0){
        exitProgram();
    }else if(strcmpi(artiste.LastName,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(artiste.LastName,"-3") == 0){
        Menu(globalUser);
    }

	fflush(stdin);
	printf("\n Enter Artiste's Telephone#: "); //remeber to add back the quote
	gets(artiste.TelephoneNumber);
	if(strcmpi(artiste.TelephoneNumber,"-1") == 0){
        exitProgram();
    }else if(strcmpi(artiste.TelephoneNumber,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(artiste.TelephoneNumber,"-3") == 0){
        Menu(globalUser);
    }

	fflush(stdin);
	printf("\n Enter Artiste's PhysicalAddress: ");
	gets(artiste.PhysicalAddress);
	if(strcmpi(artiste.PhysicalAddress,"-1") == 0){
        exitProgram();
    }else if(strcmpi(artiste.PhysicalAddress,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(artiste.PhysicalAddress,"-3") == 0){
        Menu(globalUser);
    }

	fflush(stdin);
	printf("\n Enter Artiste's Email: ");
	gets(artiste.Email);
	if(strcmpi(artiste.Email,"-1") == 0){
        exitProgram();
    }else if(strcmpi(artiste.Email,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(artiste.Email,"-3") == 0){
        Menu(globalUser);
    }

	fflush(stdin);
	printf("\n Enter Artiste's Genre: ");
	gets(artiste.Genre);
	if(strcmpi(artiste.Genre,"-1") == 0){
        exitProgram();
    }else if(strcmpi(artiste.Genre,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(artiste.Genre,"-3") == 0){
        Menu(globalUser);
    }

	fflush(stdin);
	printf("\n Enter Artiste's Account Balance: ");
	scanf("%f",&aAccount.AccountInfo.AccountBalance);
	if(aAccount.AccountInfo.AccountBalance == -1){
        exitProgram();
    }else if(aAccount.AccountInfo.AccountBalance == -2){
        MenuA(globalUser);
    }else if(aAccount.AccountInfo.AccountBalance == -3){
        Menu(globalUser);
    }

	fflush(stdin);
	printf("\n Enter Artiste's Yearly Earnings: ");
    scanf("%f",&artiste.YearlyEarnings);
    if(artiste.YearlyEarnings == -1){
        exitProgram();
    }else if(artiste.YearlyEarnings == -2){
        MenuA(globalUser);
    }else if(artiste.YearlyEarnings == -3){
        Menu(globalUser);
    }

    fflush(stdin);
	printf("\n\n*********************************************\n");

	printf(" Foundation Info\n\n");

	fflush(stdin);
	printf(" Enter Foundation Name: ");
	gets(foundation.NameOfFoundation);
	if(strcmpi(foundation.NameOfFoundation,"-1") == 0){
        exitProgram();
    }else if(strcmpi(foundation.NameOfFoundation,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(foundation.NameOfFoundation,"-3") == 0){
        Menu(globalUser);
    }

	while (FoundationExist(foundation.NameOfFoundation) > -1) {
		fflush(stdin);
		printf("\n#ERROR# -> Foundation Azlready Exist [FoundationName Error]\n");
		printf(" Enter Foundation Name: ");
		gets(foundation.NameOfFoundation);
		if(strcmpi(foundation.NameOfFoundation,"-1") == 0){
        exitProgram();
    }else if(strcmpi(foundation.NameOfFoundation,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(foundation.NameOfFoundation,"-3") == 0){
        Menu(globalUser);
    }
	}

	fflush(stdin);
	printf("\n Enter Foundation Address: ");
	gets(foundation.Address);
	if(strcmpi(foundation.Address,"-1") == 0){
        exitProgram();
    }else if(strcmpi(foundation.Address,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(foundation.Address,"-3") == 0){
        Menu(globalUser);
    }

	fflush(stdin);
	printf("\n Enter Foundation Year Founded: ");
	scanf("%d",&foundation.YearFounded);
	if(foundation.YearFounded == -1){
        exitProgram();
    }else if(foundation.YearFounded == -2){
        MenuA(globalUser);
    }else if(foundation.YearFounded == -3){
        Menu(globalUser);
    }

	fflush(stdin);
	printf("\n Enter Foundation Employee Total: ");
	scanf("%d",&foundation.NumberOfEmployees);
	if(foundation.NumberOfEmployees == -1){
        exitProgram();
    }else if(foundation.NumberOfEmployees == -2){
        MenuA(globalUser);
    }else if(foundation.NumberOfEmployees == -3){
        Menu(globalUser);
    }

	fflush(stdin);
	printf("\n Enter Foundation Major Charity(Current) : ");
	gets(foundation.MajorityCurCharity);
	if(strcmpi(foundation.MajorityCurCharity,"-1") == 0){
        exitProgram();
    }else if(strcmpi(foundation.MajorityCurCharity,"-2") == 0){
        MenuA(globalUser);
    }else if(strcmpi(foundation.MajorityCurCharity,"-3") == 0){
        Menu(globalUser);
    }

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

		}


	}

	AddArtiste();

}

void DeleteArtiste() {

    const int totalArtiste = ArtisteCount();

    if(totalArtiste <= 0){
        printf("\n#ERROR# -> Sorry No Artiste Created To Delete [No Artiste Created]\n");
        DeleteArtiste();
    }else{

    char selection[40];

	printf("\nDelete A Artiste\n\n");

	printf(" * -1 Exit Program* \n");
    printf(" * -2 Prevoius Menu* \n");
    printf(" * -3 Main Menu* \n\n");

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
    if(strcmpi(selection,"-1") == 0){
        exitProgram();
    }else if(strcmpi(selection,"-2") == 0){
        MenuDelete(globalUser);
    }else if(strcmpi(selection,"-3") == 0){
        Menu(globalUser);
    }

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


void AddBooking(){

	Booking booking;

    DisplayArtiste();

    if(globalUser == Manager){
        printf(" * -1 Exit Program * \n");
        printf(" * -2 Prevoius Menu * \n");
        printf(" * -3 Main Menu * \n\n");
    }else{
        printf(" * -1 Exit Program * \n");
        printf(" * -2 Prevoius Menu * \n\n");
    }


    char voluntaryService;

    fflush(stdin);
    printf(" Enter ArtisteId: ");
    scanf("%d",&booking.ArtisteId);
    if(booking.ArtisteId == -1){
        exitProgram();
    }else if(booking.ArtisteId == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(booking.ArtisteId == -3){
        Menu(globalUser);
    }

    while(ArtisteExistById(booking.ArtisteId) <= -1){
        fflush(stdin);
        printf("\n#ERROR# -> Artiste Doesn't Exist [ArtisteId Error]\n\n");
        printf(" Enter ArtisteId: ");
        scanf("%d",&booking.ArtisteId);
        if(booking.ArtisteId==-1){
        exitProgram();
    }else if(booking.ArtisteId==-2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(booking.ArtisteId==-3){
        Menu(globalUser);
    }
    }

    fflush(stdin);
    printf("\n Enter Booking Date: ");
    scanf("%d/%d/%d", &booking.DateBooked.day,&booking.DateBooked.month,&booking.DateBooked.year);
    if(booking.DateBooked.day == -1 || booking.DateBooked.month == -1 || booking.DateBooked.year == -1){
        exitProgram();
    }else if(booking.DateBooked.day == -2 || booking.DateBooked.month == -2 || booking.DateBooked.year == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(booking.DateBooked.day == -3 || booking.DateBooked.month == -3 || booking.DateBooked.year == -3){
        Menu(globalUser);
    }

    while(DateCompare(booking.DateBooked, currentDate()) != 1){
        fflush(stdin);
        printf("\n#ERROR# -> Date Must Be Grater Than Today [Date Less]\n");
        printf("\n Enter A Valid Booking Date: ");
        scanf("%d/%d/%d", &booking.DateBooked.day,&booking.DateBooked.month,&booking.DateBooked.year);
        if(booking.DateBooked.day == -1 || booking.DateBooked.month == -1 || booking.DateBooked.year == -1){
        exitProgram();
    }else if(booking.DateBooked.day == -2 || booking.DateBooked.month == -2 || booking.DateBooked.year == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(booking.DateBooked.day == -3 || booking.DateBooked.month == -3 || booking.DateBooked.year == -3){
        Menu(globalUser);
    }
    }

    while(BookingExist(booking.ArtisteId, booking.DateBooked) >= 0){
        fflush(stdin);
        printf("\n#ERROR# -> Date Already Booked By You [ArtisteId Error]\n\n");
        printf("\n Enter A Valid Booking Date: ");
        scanf("%d/%d/%d",&booking.DateBooked.day,&booking.DateBooked.month,&booking.DateBooked.year);
        if(booking.DateBooked.day == -1 || booking.DateBooked.month == -1 || booking.DateBooked.year == -1){
        exitProgram();
    }else if(booking.DateBooked.day == -2 || booking.DateBooked.month == -2 || booking.DateBooked.year == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(booking.DateBooked.day == -3 || booking.DateBooked.month == -3 || booking.DateBooked.year == -3){
        Menu(globalUser);
    }
    }

    while(BookingCountPerYear(booking.ArtisteId) >= 15){
        fflush(stdin);
        printf("\n#ERROR# -> This Artiste Already Reached His Yearly Quota [Max Booking Per Year]\n");
        printf("\n Enter A Valid Booking Date: ");
        scanf("%d/%d/%d", &booking.DateBooked.day,&booking.DateBooked.month,&booking.DateBooked.year);
        if(booking.DateBooked.day == -1 || booking.DateBooked.month == -1 || booking.DateBooked.year == -1){
        exitProgram();
    }else if(booking.DateBooked.day == -2 || booking.DateBooked.month == -2 || booking.DateBooked.year == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(booking.DateBooked.day == -3 || booking.DateBooked.month == -3 || booking.DateBooked.year == -3){
        Menu(globalUser);
    }
    }


    fflush(stdin);
    printf("\n Enter Booking Type: (O-Overseas | L-Local): ");
    scanf("%c",&booking.Type);
    if(booking.Type=='1'){
        exitProgram();
    }else if(booking.Type=='2'){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(booking.Type=='3'){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\n Booking Location: ");
    gets(booking.Location);
    if(strcmpi(booking.Location,"-1") == 0){
        exitProgram();
    }else if(strcmpi(booking.Location,"-2") == 0){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(strcmpi(booking.Location,"-3") == 0){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\n Guide: ");
    gets(booking.Guide);
    if(strcmpi(booking.Guide,"-1") == 0){
        exitProgram();
    }else if(strcmpi(booking.Guide,"-2") == 0){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(strcmpi(booking.Guide,"-3") == 0){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\n Promoter Name: ");
    gets(booking.PromoterName);
    if(strcmpi(booking.PromoterName,"-1") == 0){
        exitProgram();
    }else if(strcmpi(booking.PromoterName,"-2") == 0){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(strcmpi(booking.PromoterName,"-3") == 0){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\n Local Rate: ");
    scanf("%f",&booking.Rate.local);
    if(booking.Rate.local == -1){
        exitProgram();
    }else if(booking.Rate.local == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(booking.Rate.local == -3){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\n International Rate: ");
    scanf("%f",&booking.Rate.overseas);
    if(booking.Rate.overseas == -1){
        exitProgram();
    }else if(booking.Rate.overseas == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(booking.Rate.overseas == -3){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\n Voluntary Service (Y/N): ");
    scanf("%c",&voluntaryService);
    if(voluntaryService == '1'){
        exitProgram();
    }else if(voluntaryService == '2'){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(voluntaryService == '3'){
        Menu(globalUser);
    }

    if(voluntaryService == 'y' || voluntaryService == 'Y'){
        booking.IsVoluntary = one; //true
    }else{
        booking.IsVoluntary = zero; //false
    }

    if(booking.Type == 'O' || booking.Type == 'o'){

        fflush(stdin);
        printf("\n Hotel Name: ");
        gets(booking.Info.HotelInfo);
        if(strcmpi(booking.Info.HotelInfo,"-1") == 0){
        exitProgram();
    }else if(strcmpi(booking.Info.HotelInfo,"-2") == 0){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(strcmpi(booking.Info.HotelInfo,"-3") == 0){
        Menu(globalUser);
    }

        fflush(stdin);
        printf("\n Cost of Hotel: ");
        scanf("%f",&booking.Info.HotelCharge);
        if(booking.Info.HotelCharge==-1){
        exitProgram();
    }else if(booking.Info.HotelCharge==-2){
        if(globalUser == Manager){
            if(globalUser == Manager){
                    MenuDelete(globalUser);
            }else{
                Menu(globalUser);
            }
        }

    }else if(booking.Info.HotelCharge==-3){
        Menu(globalUser);
    }

        fflush(stdin);
        printf("\n Flight Origin State/Country - Destination State/Country: ");
        gets(booking.Info.FlightInfo);
        if(strcmpi(booking.Info.FlightInfo,"-1") == 0){
        exitProgram();
    }else if(strcmpi(booking.Info.FlightInfo,"-2") == 0){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(strcmpi(booking.Info.FlightInfo,"-3") == 0){
        Menu(globalUser);
    }

        fflush(stdin);
        printf("\n Plane Fare: ");
        scanf("%f",&booking.Info.PlaneFare);
        if(booking.Info.PlaneFare==-1){
        exitProgram();
    }else if(booking.Info.PlaneFare==-2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(booking.Info.PlaneFare==-3){
        Menu(globalUser);
    }

        fflush(stdin);
        printf("\n Number Of People: ");
        scanf("%d",&booking.Info.NumberOfPersons);
        if(booking.Info.NumberOfPersons==-1){
        exitProgram();
    }else if(booking.Info.NumberOfPersons==-2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(booking.Info.NumberOfPersons==-3){
        Menu(globalUser);
    }
    }

    booking.Id = BookingCount()+1;

    booking.BookingNumber = randAccNum(90000,100000);

    while(BookingExistByBookingNumber(booking.BookingNumber) >= 0){
        booking.BookingNumber = randAccNum(90000,100000);
    }

    booking.EmployeeId = LoggedInUser;

    if(CreateBooking(booking, BookingFileName, "ab+") > -1){
        printf("\nBooking Added Successfully\n");
    }else{
        printf("\nFailed To Add Booking\n");
    }

    AddBooking();


}

void DeleteBooking(){

    DisplayBookings();

    printf(" * -1 Exit Program* \n");
    printf(" * -2 Prevoius Menu* \n");
    printf(" * -3 Main Menu* \n\n");

    int selection;

    printf("\n Select Booking Id To Delete: ");
    scanf("%d",&selection);
    if(selection == -1){
        exitProgram();
    }else if(selection == -2){
        MenuDelete(globalUser);
    }else if(selection == -3){
        Menu(globalUser);
    }


    int exist = BookingExistById(selection);

    if(exist <= -1){
        printf("\n#ERROR# -> Booking Doesn't Exist [Enter Valid Id]\n");
        DeleteBooking();
    }else{
        int oldArrayLength = BookingCount();

        int newArrayLength = oldArrayLength-1;

        Booking newBookingList[newArrayLength];

        int newIndex = 0;

        int newId = 1;

        Booking * ptr = BookingList();

        for(int x = 0; x < oldArrayLength; x++){

            if(exist!=x){

                Booking obj = *(ptr+x);

                obj.Id = newId;

                newBookingList[newIndex] = obj;

                newIndex++;
                newId++;
            }

        }

        printf("\t*Local Bookings*\n\n\t\tId\tArtiste\t\tBookingNum\tBookingDate\tCreatedBy\tLocation\tPromoter\tLocalRate\tForeignRate\tVoluntaryService\n\n");

        for(int x = 0; x < newArrayLength; x++){

                int c = ArtisteExistById(newBookingList[x].ArtisteId);
                char * stageName = (ArtisteList()+c)->StageName;

                int k = UserExist( newBookingList[x].EmployeeId );
                char * userE = (ListOfUser()+k)->Username;

                printf("\t\t%-2d\t%-8s\t%-8d\t%d/%d/%d\t%-8s\t%-8s\t%-8s\t%-8.2f\t%-8.2f\t%-8c\n\n",
                 newBookingList[x].Id, stageName,
                  newBookingList[x].BookingNumber,
                    newBookingList[x].DateBooked.day,newBookingList[x].DateBooked.month,newBookingList[x].DateBooked.year,
                    userE,
                    newBookingList[x].Location,newBookingList[x].PromoterName, newBookingList[x].Rate.local, newBookingList[x].Rate.overseas,
                    newBookingList[x].IsVoluntary == one ? 'Y' : 'N'
                 );

        }

        Sleep(200);

        FILE *file;

        file = fopen(BookingFileName,"wb+");

        if(fwrite(newBookingList,sizeof(Booking), newArrayLength, file)){
            fclose(file);
            printf("\nFile Record Successfully\n");
        }else{
            fclose(file);
            printf("\n#ERROR# -> Failed To Delete Record [Internal Error]\n");
        }

    }
}


void UpdateUser(){

    int selection;

    DisplayUsers();


    printf(" * -1 Exit Program* \n");
    printf(" * -2 Prevoius Menu* \n");
    printf(" * -3 Main Menu* \n\n");

    printf(" Select User Id To Update: ");

    scanf("%d", &selection);
    if(selection==-1){
            exitProgram();
        }else if(selection==-2){
            MenuA(globalUser);
        }else if(selection==-3){
            Menu(globalUser);
        }

    int exist = UserExist(selection);

    if(exist > -1){

        int totalUsers = UserDataCount();

        char utype;

        User userArry[totalUsers];

        User * ptr = ListOfUser();

        for(int x = 0; x < totalUsers; x++){
            userArry[x] = *(ptr+x);
        }

        fflush(stdin);
        printf("Enter First Name: ");
        gets(userArry[exist].FirstName);
        if(strcmpi(userArry[exist].FirstName,"-1") == 0){
            exitProgram();
        }else if(strcmpi(userArry[exist].FirstName,"-2") == 0){
            MenuA(globalUser);
        }else if(strcmpi(userArry[exist].FirstName,"-3") == 0){
            Menu(globalUser);
        }

        fflush(stdin);
        printf("\nEnter Last Name: ");
        gets(userArry[exist].LastName);
        if(strcmpi(userArry[exist].LastName,"-1") == 0){
            exitProgram();
        }else if(strcmpi(userArry[exist].LastName,"-2") == 0){
            MenuA(globalUser);
        }else if(strcmpi(userArry[exist].LastName,"-3") == 0){
            Menu(globalUser);
        }

        fflush(stdin);
        printf("\nEnter System Username: ");
        gets(userArry[exist].Username);
        if(strcmpi(userArry[exist].Username,"-1") == 0){
            exitProgram();
        }else if(strcmpi(userArry[exist].Username,"-2") == 0){
            MenuA(globalUser);
        }else if(strcmpi(userArry[exist].Username,"-3") == 0){
            Menu(globalUser);
        }

        fflush(stdin);
        printf("\nEnter System Password: ");
        gets(userArry[exist].Password);
        if(strcmpi(userArry[exist].Password,"-1") == 0){
            exitProgram();
        }else if(strcmpi(userArry[exist].Password,"-2") == 0){
            MenuA(globalUser);
        }else if(strcmpi(userArry[exist].Password,"-3") == 0){
            Menu(globalUser);
        }

        fflush(stdin);
        printf("\nEnter Address: ");
        gets(userArry[exist].Address);
        if(strcmpi(userArry[exist].Address,"-1") == 0){
            exitProgram();
        }else if(strcmpi(userArry[exist].Address,"-2") == 0){
            MenuA(globalUser);
        }else if(strcmpi(userArry[exist].Address,"-3") == 0){
            Menu(globalUser);
        }

        fflush(stdin);
        printf("\nSelect User Type (M - Manager, C - Clerk): ");
        scanf("%c", &utype);
        if(utype=='1'){
            exitProgram();
        }else if(utype=='2'){
            MenuA(globalUser);
        }else if(utype=='3'){
            Menu(globalUser);
        }

        if(utype == 'M' || utype == 'm'){
            userArry[exist].UserType = Manager;
        }else{
            userArry[exist].UserType = Clerk;
        }

        FILE * fFile = fopen(UserFileName, "wb+");

        if(fwrite(userArry, sizeof(User), totalUsers, fFile)){
            fclose(fFile);
            printf("\nUser Record Successfully Updated!\n");
        }else{
            fclose(fFile);
            printf("\n#ERROR# -> Failed To Update User Record [Internal Error]\n");
        }

    }else{
        printf("\n#ERROR# -> Error User Doesn't Exist [Out Of Bound Index]\n");
        UpdateUser();
    }
}

void UpdateBooking() {

    int selection;

    DisplayBookings();

    if(globalUser == Manager){
        printf(" * -1 Exit Program * \n");
        printf(" * -2 Prevoius Menu * \n");
        printf(" * -3 Main Menu * \n\n");
    }else{
        printf(" * -1 Exit Program * \n");
        printf(" * -2 Prevoius Menu * \n\n");
    }

    printf(" Select Booking Id To Update: ");

    scanf("%d", &selection);
    if(selection == -1){
        exitProgram();
    }else if(selection == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }

    }else if(selection == -3){
        Menu(globalUser);
    }


    int exist = BookingExistById(selection);

    if(exist > -1){

        DisplayArtiste();

        char voluntaryService;

        int totalBooking = BookingCount();

        Booking bookingArry[totalBooking];

        Booking * ptr = BookingList();

        for(int x = 0; x < totalBooking; x++){
            bookingArry[x] = *(ptr+x);
        }



            fflush(stdin);
    printf(" Enter ArtisteId: ");
    scanf("%d",&bookingArry[exist].ArtisteId);
    if(bookingArry[exist].ArtisteId == -1){
        exitProgram();
    }else if(bookingArry[exist].ArtisteId == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(bookingArry[exist].ArtisteId == -3){
        Menu(globalUser);
    }

    while(ArtisteExistById(bookingArry[exist].ArtisteId) <= -1){
        fflush(stdin);
        printf("\n#ERROR# -> Artiste Doesn't Exist [ArtisteId Error]\n\n");
        printf(" Enter ArtisteId: ");
        scanf("%d",&bookingArry[exist].ArtisteId);
        if(bookingArry[exist].ArtisteId == -1){
        exitProgram();
    }else if(bookingArry[exist].ArtisteId == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(bookingArry[exist].ArtisteId == -3){
        Menu(globalUser);
    }
    }

    fflush(stdin);
    printf("\n Enter Booking Date: ");
    scanf("%d/%d/%d", &bookingArry[exist].DateBooked.day,&bookingArry[exist].DateBooked.month,&bookingArry[exist].DateBooked.year);
    if(bookingArry[exist].DateBooked.day == -1 || bookingArry[exist].DateBooked.month == -1 || bookingArry[exist].DateBooked.year == -1){
        exitProgram();
    }else if(bookingArry[exist].DateBooked.day == -2 || bookingArry[exist].DateBooked.month == -2 || bookingArry[exist].DateBooked.year == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(bookingArry[exist].DateBooked.day == -3 || bookingArry[exist].DateBooked.month == -3 || bookingArry[exist].DateBooked.year == -3){
        Menu(globalUser);
    }

    while(DateCompare(bookingArry[exist].DateBooked, currentDate()) != 1){
        fflush(stdin);
        printf("\n#ERROR# -> Date Must Be Grater Than Today [Date Less]\n");
        printf("\n Enter A Valid Booking Date: ");
        scanf("%d/%d/%d", &bookingArry[exist].DateBooked.day,&bookingArry[exist].DateBooked.month,&bookingArry[exist].DateBooked.year);
        if(bookingArry[exist].DateBooked.day == -1 || bookingArry[exist].DateBooked.month == -1 || bookingArry[exist].DateBooked.year == -1){
        exitProgram();
    }else if(bookingArry[exist].DateBooked.day == -2 || bookingArry[exist].DateBooked.month == -2 || bookingArry[exist].DateBooked.year == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(bookingArry[exist].DateBooked.day == -3 || bookingArry[exist].DateBooked.month == -3 || bookingArry[exist].DateBooked.year == -3){
        Menu(globalUser);
    }
    }

    while(BookingExist(bookingArry[exist].ArtisteId, bookingArry[exist].DateBooked) >= 0){
        fflush(stdin);
        printf("\n#ERROR# -> Date Already Booked By You [ArtisteId Error]\n\n");
        printf("\n Enter A Valid Booking Date: ");
        scanf("%d/%d/%d",&bookingArry[exist].DateBooked.day,&bookingArry[exist].DateBooked.month,&bookingArry[exist].DateBooked.year);
        if(bookingArry[exist].DateBooked.day == -1 || bookingArry[exist].DateBooked.month == -1 || bookingArry[exist].DateBooked.year == -1){
        exitProgram();
    }else if(bookingArry[exist].DateBooked.day == -2 || bookingArry[exist].DateBooked.month == -2 || bookingArry[exist].DateBooked.year == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(bookingArry[exist].DateBooked.day == -3 || bookingArry[exist].DateBooked.month == -3 || bookingArry[exist].DateBooked.year == -3){
        Menu(globalUser);
    }
    }

    while(BookingCountPerYear(bookingArry[exist].ArtisteId) >= 15){
        fflush(stdin);
        printf("\n#ERROR# -> This Artiste Already Reached His Yearly Quota [Max Booking Per Year]\n");
        printf("\n Enter A Valid Booking Date: ");
        scanf("%d/%d/%d", &bookingArry[exist].DateBooked.day,&bookingArry[exist].DateBooked.month,&bookingArry[exist].DateBooked.year);
        if(bookingArry[exist].DateBooked.day == -1 || bookingArry[exist].DateBooked.month == -1 || bookingArry[exist].DateBooked.year == -1){
        exitProgram();
    }else if(bookingArry[exist].DateBooked.day == -2 || bookingArry[exist].DateBooked.month == -2 || bookingArry[exist].DateBooked.year == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(bookingArry[exist].DateBooked.day == -3 || bookingArry[exist].DateBooked.month == -3 || bookingArry[exist].DateBooked.year == -3){
        Menu(globalUser);
    }
    }


    fflush(stdin);
    printf("\n Enter Booking Type: (O-Overseas | L-Local): ");
    scanf("%c",&bookingArry[exist].Type);
    if(bookingArry[exist].Type=='1'){
        exitProgram();
    }else if(bookingArry[exist].Type=='2'){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(bookingArry[exist].Type=='3'){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\n Booking Location: ");
    gets(bookingArry[exist].Location);
    if(strcmpi(bookingArry[exist].Location,"-1") == 0){
        exitProgram();
    }else if(strcmpi(bookingArry[exist].Location,"-2") == 0){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(strcmpi(bookingArry[exist].Location,"-3") == 0){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\n Guide: ");
    gets(bookingArry[exist].Guide);
    if(strcmpi(bookingArry[exist].Guide,"-1") == 0){
        exitProgram();
    }else if(strcmpi(bookingArry[exist].Guide,"-2") == 0){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(strcmpi(bookingArry[exist].Guide,"-3") == 0){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\n Promoter Name: ");
    gets(bookingArry[exist].PromoterName);
    if(strcmpi(bookingArry[exist].PromoterName,"-1") == 0){
        exitProgram();
    }else if(strcmpi(bookingArry[exist].PromoterName,"-2") == 0){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(strcmpi(bookingArry[exist].PromoterName,"-3") == 0){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\n Local Rate: ");
    scanf("%f",&bookingArry[exist].Rate.local);
    if(bookingArry[exist].Rate.local == -1){
        exitProgram();
    }else if(bookingArry[exist].Rate.local == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(bookingArry[exist].Rate.local == -3){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\n International Rate: ");
    scanf("%f",&bookingArry[exist].Rate.overseas);
    if(bookingArry[exist].Rate.overseas == -1){
        exitProgram();
    }else if(bookingArry[exist].Rate.overseas == -2){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(bookingArry[exist].Rate.overseas == -3){
        Menu(globalUser);
    }

    fflush(stdin);
    printf("\n Voluntary Service (Y/N): ");
    scanf("%c",&voluntaryService);
    if(voluntaryService == '1'){
        exitProgram();
    }else if(voluntaryService == '2'){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(voluntaryService == '3'){
        Menu(globalUser);
    }

    if(voluntaryService == 'y' || voluntaryService == 'Y'){
        bookingArry[exist].IsVoluntary = one; //true
    }else{
        bookingArry[exist].IsVoluntary = zero; //false
    }

    if(bookingArry[exist].Type == 'O' || bookingArry[exist].Type == 'o'){

        fflush(stdin);
        printf("\n Hotel Name: ");
        gets(bookingArry[exist].Info.HotelInfo);
        if(strcmpi(bookingArry[exist].Info.HotelInfo,"-1") == 0){
        exitProgram();
    }else if(strcmpi(bookingArry[exist].Info.HotelInfo,"-2") == 0){
        if(globalUser == Manager){
            MenuDelete(globalUser);
        }else{
            Menu(globalUser);
        }
    }else if(strcmpi(bookingArry[exist].Info.HotelInfo,"-3") == 0){
        Menu(globalUser);
    }

        fflush(stdin);
        printf("\n Cost of Hotel: ");
        scanf("%f",&bookingArry[exist].Info.HotelCharge);
        if(bookingArry[exist].Info.HotelCharge==-1){
            exitProgram();
        }else if(bookingArry[exist].Info.HotelCharge==-2){
            if(globalUser == Manager){
                if(globalUser == Manager){
                        MenuDelete(globalUser);
                }else{
                    Menu(globalUser);
                }
            }
            }else if(bookingArry[exist].Info.HotelCharge==-3){
                Menu(globalUser);
            }

        fflush(stdin);
        printf("\n Flight Origin State/Country - Destination State/Country: ");
        gets(bookingArry[exist].Info.FlightInfo);
        if(strcmpi(bookingArry[exist].Info.FlightInfo,"-1") == 0){
            exitProgram();
        }else if(strcmpi(bookingArry[exist].Info.FlightInfo,"-2") == 0){
            if(globalUser == Manager){
                MenuDelete(globalUser);
            }else{
                Menu(globalUser);
            }
        }else if(strcmpi(bookingArry[exist].Info.FlightInfo,"-3") == 0){
            Menu(globalUser);
        }

        fflush(stdin);
        printf("\n Plane Fare: ");
        scanf("%f",&bookingArry[exist].Info.PlaneFare);
        if(bookingArry[exist].Info.PlaneFare==-1){
            exitProgram();
        }else if(bookingArry[exist].Info.PlaneFare==-2){
            if(globalUser == Manager){
                MenuDelete(globalUser);
            }else{
                Menu(globalUser);
            }
        }else if(bookingArry[exist].Info.PlaneFare==-3){
            Menu(globalUser);
        }

        fflush(stdin);
        printf("\n Number Of People: ");
        scanf("%d",&bookingArry[exist].Info.NumberOfPersons);
        if(bookingArry[exist].Info.NumberOfPersons==-1){
            exitProgram();
        }else if(bookingArry[exist].Info.NumberOfPersons==-2){
            if(globalUser == Manager){
                MenuDelete(globalUser);
            }else{
                Menu(globalUser);
            }
        }else if(bookingArry[exist].Info.NumberOfPersons==-3){
            Menu(globalUser);
        }
    }

        //bookingArry[exist].EmployeeId = LoggedInUser;

        FILE * fFile = fopen(BookingFileName, "wb+");

        if(fwrite(bookingArry, sizeof(Booking), totalBooking, fFile)){
            fclose(fFile);
            printf("\nBooking Record Successfully Updated!\n");
        }else{
            fclose(fFile);
            printf("\n#ERROR# -> Failed To Update Booking Record [Internal Error]\n");
        }

    }else{
        printf("\n#ERROR# -> Error Booking Doesn't Exist [Out Of Bound Index]\n");
        UpdateBooking();
    }
}

void UpdateFoundation(){

    int selection;

    DisplayFoundation();

    printf(" Select Foundation Id To Update: ");

    scanf("%d", &selection);

    int exist = FoundationExistById(selection);

    if(exist > -1){

        int totalFoundations = FoundationCount();

        Foundation foundationArry[totalFoundations];

        int totalAccounts = AccountsCount();

        Accounts accountArry[totalAccounts];


        Foundation * ptr = FoundationList();

        for(int x = 0; x < totalFoundations; x++){
            foundationArry[x] = *(ptr+x);
        }

        Accounts * aPtr = AccountsList();

        for(int x = 0; x < totalAccounts; x++){
            accountArry[x] = *(aPtr+x);
        }

        fflush(stdin);
        printf(" Enter Foundation Name: ");
        gets(foundationArry[exist].NameOfFoundation);

        while (FoundationExist(foundationArry[exist].NameOfFoundation) > -1) {
            fflush(stdin);
            printf("\n#ERROR# -> Foundation Already Exist [FoundationName Error]\n");
            printf(" Enter Foundation Name: ");
            gets(foundationArry[exist].NameOfFoundation);
        }

        fflush(stdin);
        printf("\n Enter Foundation Address: ");
        gets(foundationArry[exist].Address);

        fflush(stdin);
        printf("\n Enter Foundation Year Founded: ");
        scanf("%d",&foundationArry[exist].YearFounded);

        fflush(stdin);
        printf("\n Enter Foundation Employee Total: ");
        scanf("%d",&foundationArry[exist].NumberOfEmployees);

        fflush(stdin);
        printf("\n Enter Foundation Major Charity(Current) : ");
        gets(foundationArry[exist].MajorityCurCharity);

        int accExist = AccountExistByRef(foundationArry[exist].Id, FoundationAccount);

        fflush(stdin);
        printf(" \nEnter Foundation's Account Balance: ");
        scanf("%f",&accountArry[accExist].AccountInfo.AccountBalance);


        FILE * fFile = fopen(FoundationFileName, "wb+");

        fwrite(foundationArry, sizeof(Foundation), totalFoundations, fFile);

        fclose(fFile);

        Sleep(300);

        FILE * aFile = fopen(AccountsFileName,"wb+");

        if(fwrite(accountArry, sizeof(Accounts), totalAccounts, aFile)){
            fclose(aFile);
            printf("\nFoundation Record Successfully Updated!\n");
        }else{
            fclose(aFile);
            printf("\n#ERROR# -> Failed To Update Foundation Record [Internal Error]\n");
        }

    }else{
        printf("\n#ERROR# -> Error Foundation Doesn't Exist [Out Of Bound Index]\n");
        UpdateFoundation();
    }
}

void UpdateArtiste() {

    int selection;

    DisplayArtiste();

    printf(" Select Artiste Id To Update: ");

    scanf("%d", &selection);

    int exist = ArtisteExistById(selection);

    if(exist > -1){

        int totalArtiste = ArtisteCount();

        Artiste artisteArry[totalArtiste];

        int totalAccounts = AccountsCount();

        Accounts accountArry[totalAccounts];


        Artiste * ptr = ArtisteList();

        for(int x = 0; x < totalArtiste; x++){
            artisteArry[x] = *(ptr+x);
        }

        Accounts * aPtr = AccountsList();

        for(int x = 0; x < totalAccounts; x++){
            accountArry[x] = *(aPtr+x);
        }

        fflush(stdin);
        printf(" Enter Artiste's Stage Name: ");
        gets(artisteArry[exist].StageName);

        while (ArtisteExist(artisteArry[exist].StageName) > -1) {
            fflush(stdin);
            printf("\n#ERROR# -> Artiste Name Already Taken [StageName Error]\n");
            printf(" Enter Artiste's Stage Name: ");
            gets(artisteArry[exist].StageName);
        }

        fflush(stdin);
        printf("\n Enter Artiste's Firstname: ");
        gets(artisteArry[exist].FirstName);

        fflush(stdin);
        printf("\n Enter Artiste's Lastname: ");
        gets(artisteArry[exist].LastName);

        fflush(stdin);
        printf("\n Enter Artiste's Telephone#: "); //remeber to add back the quote
        gets(artisteArry[exist].TelephoneNumber);

        fflush(stdin);
        printf("\n Enter Artiste's PhysicalAddress: ");
        gets(artisteArry[exist].PhysicalAddress);

        fflush(stdin);
        printf("\n Enter Artiste's Email: ");
        gets(artisteArry[exist].Email);

        fflush(stdin);
        printf("\n Enter Artiste's Genre: ");
        gets(artisteArry[exist].Genre);

        int accExist = AccountExistByRef(artisteArry[exist].Id, ArtisteAccount);

        fflush(stdin);
        printf("\n Enter Artiste's Account Balance: ");
        scanf("%f",&accountArry[accExist].AccountInfo.AccountBalance);

        fflush(stdin);
        printf("\n Enter Artiste's Yearly Earnings: ");
        scanf("%f",&artisteArry[exist].YearlyEarnings);


        FILE * fFile = fopen(ArtisteFileName, "wb+");

        fwrite(artisteArry, sizeof(Artiste), totalArtiste, fFile);

        fclose(fFile);

        Sleep(300);

        FILE * aFile = fopen(AccountsFileName,"wb+");

        if(fwrite(accountArry, sizeof(Accounts), totalAccounts, aFile)){
            fclose(aFile);
            printf("\nArtiste Record Successfully Updated!\n");
        }else{
            fclose(aFile);
            printf("\n#ERROR# -> Failed To Update Artiste Record [Internal Error]\n");
        }

    }else{
        printf("\n#ERROR# -> Error Artiste Doesn't Exist [Out Of Bound Index]\n");
        UpdateArtiste();
    }

}

void updateMenu(){

    char selection;

    printf("\n *Please Select A Option From Below*\n\n");

    fflush(stdin);
    printf(" a). Artiste Information\n b). Foundation\n c). Booking\n\n");

    fflush(stdin);
    printf(" Enter Option: ");
    scanf("%c",&selection);

    if(selection == 'a' || selection == 'A'){
        UpdateArtiste();
    }else if(selection == 'b' || selection == 'B'){
        UpdateFoundation();
    }else if(selection == 'c' || selection == 'C'){
        UpdateBooking();
    }else{
        updateMenu();
    }

}
#endif // MANIPULATION_H_INCLUDED
