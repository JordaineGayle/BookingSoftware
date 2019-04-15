#ifndef MANIPULATION_H_INCLUDED
#define MANIPULATION_H_INCLUDED
#include "DATAManipulation.h"
#include "Display.h"
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
	printf("\n Enter Artiste's Telephone#: "); //remeber to add back the quote
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
        //MenuDelete(Manager);
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


void AddBooking(){

	Booking booking;

    DisplayArtiste();

    char voluntaryService;

    fflush(stdin);
    printf(" Enter ArtisteId: ");
    scanf("%d",&booking.ArtisteId);

    while(ArtisteExistById(booking.ArtisteId) <= -1){
        fflush(stdin);
        printf("\n#ERROR# -> Artiste Doesn't Exist [ArtisteId Error]\n\n");
        printf(" Enter ArtisteId: ");
        scanf("%d",&booking.ArtisteId);
    }

    fflush(stdin);
    printf("\n Enter Booking Date: ");
    scanf("%d/%d/%d", &booking.DateBooked.day,&booking.DateBooked.month,&booking.DateBooked.year);

    while(DateCompare(booking.DateBooked, currentDate()) != 1){
        fflush(stdin);
        printf("\n#ERROR# -> Date Must Be Grater Than Today [Date Less]\n");
        printf("\n Enter A Valid Booking Date: ");
        scanf("%d/%d/%d", &booking.DateBooked.day,&booking.DateBooked.month,&booking.DateBooked.year);
    }

    while(BookingExist(booking.ArtisteId, booking.DateBooked) >= 0){
        fflush(stdin);
        printf("\n#ERROR# -> Date Already Booked By You [ArtisteId Error]\n\n");
        printf("\n Enter A Valid Booking Date: ");
        scanf("%d/%d/%d",&booking.DateBooked.day,&booking.DateBooked.month,&booking.DateBooked.year);
    }

    while(BookingCountPerYear(booking.ArtisteId) >= 15){
        fflush(stdin);
        printf("\n#ERROR# -> This Artiste Already Reached His Yearly Quota [Max Booking Per Year]\n");
        printf("\n Enter A Valid Booking Date: ");
        scanf("%d/%d/%d", &booking.DateBooked.day,&booking.DateBooked.month,&booking.DateBooked.year);
    }


    fflush(stdin);
    printf("\n Enter Booking Type: (O-Overseas | L-Local): ");
    scanf("%c",&booking.Type);

    fflush(stdin);
    printf("\n Booking Location: ");
    gets(booking.Location);

    fflush(stdin);
    printf("\n Guide: ");
    gets(booking.Guide);

    fflush(stdin);
    printf("\n Promoter Name: ");
    gets(booking.PromoterName);

    fflush(stdin);
    printf("\n Local Rate: ");
    scanf("%f",&booking.Rate.local);

    fflush(stdin);
    printf("\n International Rate: ");
    scanf("%f",&booking.Rate.overseas);

    fflush(stdin);
    printf("\n Voluntary Service (Y/N): ");
    scanf("%c",&voluntaryService);

    if(voluntaryService == 'y' || voluntaryService == 'Y'){
        booking.IsVoluntary = one; //true
    }else{
        booking.IsVoluntary = zero; //false
    }

    if(booking.Type == 'O' || booking.Type == 'o'){

        fflush(stdin);
        printf("\n Hotel Name: ");
        gets(booking.Info.HotelInfo);

        fflush(stdin);
        printf("\n Cost of Hotel: ");
        scanf("%f",&booking.Info.HotelCharge);

        fflush(stdin);
        printf("\n Flight Origin State/Country - Destination State/Country: ");
        gets(booking.Info.FlightInfo);

        fflush(stdin);
        printf("\n Plane Fare: ");
        scanf("%f",&booking.Info.PlaneFare);

        fflush(stdin);
        printf("\n Number Of People: ");
        scanf("%d",&booking.Info.NumberOfPersons);
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

    //AddBooking();


}

void DeleteBooking(){

    DisplayBookings();

    int selection;

    printf("\nSelect Booking Id To Delete: ");
    scanf("%d",&selection);

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

void UpdateBooking() {
}

#endif // MANIPULATION_H_INCLUDED
