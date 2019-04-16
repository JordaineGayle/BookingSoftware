#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED
#include <string.h>
#include "Variables.h"

int file_exists(char * filename)
{
    FILE * file;
    file = fopen(filename, "rb");
    if (!file) //I'm sure, you meant for READING =)
    {
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0;
}

void CreateLog(char *description){

    ActivityLog log;

    log.UserId = LoggedInUser;

    log.Description = description;

    time_t mytime;

    mytime = time(NULL);

    log.Date = ctime(&mytime);

    AddLog(log,ActivityFileName, "ab+");

}

int DateCompare(Date d1, Date d2){
    if (d1.year < d2.year)
       return -1;

    else if (d1.year > d2.year)
       return 1;

    if (d1.year == d2.year)
    {
         if (d1.month<d2.month)
              return -1;
         else if (d1.month>d2.month)
              return 1;
         else if (d1.day<d2.day)
              return -1;
         else if(d1.day>d2.day)
              return 1;
         else
              return 0;
    }

    return -1;
}

long randAccNum(long mini, long maxx) {

	time_t now;

	srand(time(&now));

	Sleep(10 + rand() % 1000 - 1);

	return (long)abs((mini*rand() % maxx) + rand() % 100) - 1;
}

int currentYear(){

	int year;

	time_t now;

	time(&now);

	struct tm *local = localtime(&now);

	year = local->tm_year + 1900;

	return year;
}

Date currentDate(){

    Date d;

	time_t now;

	time(&now);

    struct tm *local = localtime(&now);

	d.day = local->tm_mday;
	d.month = local->tm_mon + 1;
	d.year = local->tm_year + 1900;

    return d;
}

/****************************************************/

int UserDataCount(){

    FILE * file;

    int fileCount = 0;

    if(file_exists(UserFileName)==0){
        file = fopen(UserFileName, "rb+");

    if(file == NULL){

        perror("File failed to open");

    }else{

        User uObject;

        while(!feof(file)){
            fread(&uObject, sizeof(uObject), 1, file);
            fileCount++;
        }

    }

    fclose(file);
    if(fileCount <= 0){
        fileCount = -1;
        return fileCount;
    }

    return fileCount-1;
    }else{
        return 0;
    }


}

User * ListOfUser(){

    FILE * usr = NULL;

    usr = fopen(UserFileName, "rb+");

    const int res = UserDataCount();

    User users[res+3];

    User * userPtr = &users[0];

    while(!feof(usr)){

        fread(users, sizeof(User), res, usr);

    }

    fclose(usr);

    return userPtr;

}

int LinearUserSearch(char *username, char *password, char uType){

    UserType userType;

    if(uType == 'M' || uType == 'm'){
        userType = Manager;
    }else{
        userType = Clerk;
    }

    const int counted = UserDataCount();

    User * ptr = ListOfUser();

    for(int usr = 0; usr <  counted; usr++){

        if( (strcmp((ptr+usr)->Username, username)==0) && (strcmp((ptr+usr)->Password, password)==0) && (ptr+usr)->UserType == userType){
            return usr;
        }
    }

    return -1;

}

int UserExist(int Id){
    const int counted = UserDataCount();

    User * ptr = ListOfUser();

    for(int usr = 0; usr <  counted; usr++){

        if( (ptr+usr)->Id == Id ){
            return usr;
        }
    }

    return -1;
}


int UserExistByUsername(char *name){

    const int counted = UserDataCount();

    if(counted > -1){
        User * ptr = ListOfUser();

        for(int usr = 0; usr <  counted; usr++){

        if( strcmpi((ptr+usr)->Username,name) == 0 ){
            return usr;
            }
        }
    }

    return -1;
}


User * QueryUserByUsername(char * username){
    ListPos = 0;
    if (file_exists(UserFileName) == 0) {

		const int counted = UserDataCount();

		int foundCounter = 0;



		if(counted <= 0){
			return NULL;
		}else{
			User * ptr = ListOfUser();
            int index[counted+1000];
			if (ptr == NULL) {
				return NULL;
			}

			for (int x = 0; x < counted; x++) {

				if ( strcmpi((ptr+x)->Username, username) == 0){
                    index[foundCounter] = x;
					foundCounter++;
				}
			}

			if(foundCounter > 0){
                User matchList[foundCounter];

                User * listPtr = &matchList[0];
                //Booking * ptr2 = BookingList();
                for(int x = 0; x < foundCounter; x++){
                     User u = *(ptr+index[x]);
                     matchList[x] = u;
                }

                if(listPtr != NULL){
                    ListPos = foundCounter;
                    return listPtr;
                }else{
                    return NULL;
                }
			}else{
                return NULL;
			}
		}
	}

	return NULL;
}


/****************************************************/


/***********************Artiste****************************/


int ArtisteCount(){

    FILE * file;

    int fileCount = 0;

    if(file_exists(ArtisteFileName)==0){
        file = fopen(ArtisteFileName, "rb+");

    if(file == NULL){

        perror("File failed to open");

    }else{

        Artiste obj;

        while(!feof(file)){
            fread(&obj, sizeof(obj), 1, file);
            fileCount++;
        }

    }

    fclose(file);
    if(fileCount <= 0){
        fileCount = -1;
        return fileCount;
    }

    return fileCount-1;
    }else{
        return 0;
    }
}

Artiste * ArtisteList(){

    if(file_exists(ArtisteFileName) == 0){

        FILE * ar;

        ar = fopen(ArtisteFileName, "rb+");

        const int res = ArtisteCount();

        Artiste artiste[res+100];

        Artiste * ptr = &artiste[0];

        while(!feof(ar)){

            fread(artiste, sizeof(Artiste), res, ar);

        }

        fclose(ar);

        return ptr;
    }else{
        return NULL;
    }


}

int ArtisteExist(char * stageName){

    if(file_exists(ArtisteFileName) == 0){

        const int counted = ArtisteCount();

        if(counted <= 0){
            return -1;
        }else{
            Artiste * ptr = ArtisteList();

            if (ptr == NULL) {
                return -1;
            }

            for(int x = 0; x <  counted; x++){

                if( strcmpi(stageName, (ptr+x)->StageName) == 0 ){
                    return x;
                }
            }
        }
    }

    return -1;
}

int ArtisteExistById(int Id){

    if(file_exists(ArtisteFileName) == 0){

        const int counted = ArtisteCount();

        if(counted <= 0){
            return -1;
        }else{
            Artiste * ptr = ArtisteList();

            if (ptr == NULL) {
                return -1;
            }

            for(int x = 0; x <  counted; x++){

                if( (ptr+x)->Id == Id ){
                    return x;
                }
            }
        }
    }

    return -1;
}


/***********************Artiste****************************/


/***********************Foundation****************************/

int FoundationCount() {

	FILE * file;

	int fileCount = 0;

	if (file_exists(FoundationFileName) == 0) {
		file = fopen(FoundationFileName, "rb+");

		if (file == NULL) {

			perror("File failed to open");

		}
		else {

			Foundation obj;

			while (!feof(file)) {
				fread(&obj, sizeof(obj), 1, file);
				fileCount++;
			}

		}

		fclose(file);
		if (fileCount <= 0) {
			fileCount = -1;
			return fileCount;
		}

		return fileCount - 1;
	}
	else {
		return 0;
	}
}

Foundation * FoundationList() {

	if (file_exists(FoundationFileName) == 0) {

		FILE * fd;

		fd = fopen(FoundationFileName, "rb+");

		const int res = FoundationCount();

		Foundation foundation[res + 100];

		Foundation * ptr = &foundation[0];

		while (!feof(fd)) {

			fread(foundation, sizeof(Foundation), res, fd);
		}

		fclose(fd);

		return ptr;
	}
	else {
		return NULL;
	}


}

int FoundationExist(char * foundationName) {

	if (file_exists(FoundationFileName) == 0) {

		const int counted = FoundationCount();

		if(counted <= 0){
            return -1;
		}else{
            Foundation * ptr = FoundationList();

            if (ptr == NULL) {
                return -1;
            }

            for (int x = 0; x < counted; x++) {

                if (strcmpi(foundationName, (ptr + x)->NameOfFoundation) == 0) {
                    return x;
                }
            }
		}
	}

	return -1;
}

int FoundationExistById(int Id) {

	if (file_exists(FoundationFileName) == 0) {

		const int counted = FoundationCount();

		if(counted <= 0){
            return -1;
		}else{
            Foundation * ptr = FoundationList();

            if (ptr == NULL) {
                return -1;
            }

            for (int x = 0; x < counted; x++) {

                if ( (ptr+x)->Id == Id ) {
                    return x;
                }
            }
		}
	}

	return -1;
}

int FoundationExistByYearFounded(int year) {

	if (file_exists(FoundationFileName) == 0) {

		const int counted = FoundationCount();

		if(counted <= 0){
            return -1;
		}else{
            Foundation * ptr = FoundationList();

            if (ptr == NULL) {
                return -1;
            }

            for (int x = 0; x < counted; x++) {

                if ( (ptr+x)->YearFounded ==year ) {
                    return x;
                }
            }
		}
	}

	return -1;
}

Foundation * delFoundation(int Id){

        const int counted = FoundationCount();

        Foundation fd[counted - 1];
        Foundation *newFoundation = &fd[0];

        int y = 0;
        int id = 1;

        Foundation * ptr = FoundationList();
		for (int x = 0; x < counted; x++) {

                if( (ptr+x)->Id != Id){
                    Foundation f;
                    f = *(ptr+x);
                    f.Id = id;
                    fd[y] = f;
                    y++;
                    id++;
                }
		}



		return newFoundation;
}


Foundation * QueryFoundationByYearFound(int year){
    ListPos = 0;
    if (file_exists(FoundationFileName) == 0) {

		const int counted = FoundationCount();

		int foundCounter = 0;



		if(counted <= 0){
			return NULL;
		}else{
			Foundation * ptr = FoundationList();
            int index[counted+1000];
			if (ptr == NULL) {
				return NULL;
			}

			for (int x = 0; x < counted; x++) {

				if ( (ptr+x)->YearFounded == year){
                    index[foundCounter] = x;
					foundCounter++;
				}
			}

			if(foundCounter > 0){
                Foundation matchList[foundCounter];

                Foundation * listPtr = &matchList[0];

                for(int x = 0; x < foundCounter; x++){
                     Foundation obj = *(ptr+index[x]);
                     matchList[x] = obj;
                }

                if(listPtr != NULL){
                    ListPos = foundCounter;
                    return listPtr;
                }else{
                    return NULL;
                }
			}else{
                return NULL;
			}
		}
	}

	return NULL;
}


/***********************Foundation****************************/


/***********************Accounts****************************/


int AccountsCount() {

	FILE * file;

	int fileCount = 0;

	if (file_exists(AccountsFileName) == 0) {
		file = fopen(AccountsFileName, "rb+");

		if (file == NULL) {

			perror("File failed to open");

		}
		else {

			Accounts obj;

			while (!feof(file)) {
				fread(&obj, sizeof(obj), 1, file);
				fileCount++;
			}

		}

		fclose(file);
		if (fileCount <= 0) {
			fileCount = -1;
			return fileCount;
		}

		return fileCount - 1;
	}
	else {
		return 0;
	}
}

Accounts * AccountsList() {

	if (file_exists(AccountsFileName) == 0) {

		FILE * acc;

		acc = fopen(AccountsFileName, "rb+");

		const int res = AccountsCount();

		Accounts accounts[res + 100];

		Accounts * ptr = &accounts[0];

		while (!feof(acc)) {

			fread(accounts, sizeof(Accounts), res, acc);
		}

		fclose(acc);

		return ptr;
	}
	else {
		return NULL;
	}
}

int AccountExist(int accNum) {

	if (file_exists(AccountsFileName) == 0) {

		const int counted = AccountsCount();

		if(counted <= 0){
			return -1;
		}else{
			Accounts * ptr = AccountsList();

			if (ptr == NULL) {
				return -1;
			}

			for (int x = 0; x < counted; x++) {

				if ( (ptr+x)->AccountInfo.AccountNum == accNum ) {
					return x;
				}
			}
		}
	}

	return -1;
}

int AccountExistByRef(int refId, AccountTypes accType) {

	if (file_exists(AccountsFileName) == 0) {

		const int counted = AccountsCount();

		if(counted <= 0){
			return -1;
		}else{
			Accounts * ptr = AccountsList();

			if (ptr == NULL) {
				return -1;
			}

			for (int x = 0; x < counted; x++) {

				if ( (ptr+x)->RefId == refId && (ptr+x)->AccountInfo.AccountType == accType ) {
					return x;
				}
			}
		}
	}

	return -1;
}

Accounts * delAccount(int refId){

        const int counted = AccountsCount();

        //printf("\n\nTotal Accounts: %d\n\n",counted);

        Accounts ac[counted-2];
        Accounts *newAccount = &ac[0];
        int y = 0;
        int id = 1;

        Accounts * ptr = AccountsList();
		for (int x = 0; x < counted; x++) {

                if( (ptr+x)->RefId != refId){
                    Accounts a;
                    a = *(ptr+x);
                    a.Id = id;

                    if((ptr+x)->RefId <= 1){
                        a.RefId = 1;
                    }else{
                        a.RefId-=1;
                    }

                    ac[y] = a;
                    y++;
                    id++;
                }
		}



		return newAccount;
}

/***********************Accounts****************************/


/***********************Booking****************************/

int BookingCount(){

	FILE * file;

	int fileCount = 0;

	if (file_exists(BookingFileName) == 0) {
		file = fopen(BookingFileName, "rb+");

		if (file == NULL) {

			perror("File failed to open");

		}
		else {

			Booking obj;

			while (!feof(file)) {
				fread(&obj, sizeof(obj), 1, file);
				fileCount++;
			}

		}

		fclose(file);
		if (fileCount <= 0) {
			fileCount = -1;
			return fileCount;
		}

		return fileCount - 1;
	}
	else {
		return 0;
	}
}

Booking * BookingList(){

		if (file_exists(BookingFileName) == 0) {

		FILE * bk;

		bk = fopen(BookingFileName, "rb+");

		const int res = BookingCount();

		Booking booking[res +1000];

		Booking * ptr = &booking[0];

		while (!feof(bk)) {

			fread(booking, sizeof(Booking), res, bk);
		}

		fclose(bk);

		return ptr;
	}
	else {
		return NULL;
	}
}

int BookingExist(int artisteId, Date date){

	if (file_exists(BookingFileName) == 0) {

		const int counted = BookingCount();

		if(counted <= 0){
			return -1;
		}else{
			Booking * ptr = BookingList();

			if (ptr == NULL) {
				return -1;
			}

			for (int x = 0; x < counted; x++) {

				if ( ((ptr+x)->ArtisteId == artisteId) &&  ((ptr+x)->DateBooked.day == date.day && (ptr+x)->DateBooked.month == date.month && (ptr+x)->DateBooked.year == date.year) ) {
					return x;
				}
			}
		}
	}

	return -1;
}

int BookingExistByBookingNumber(int bookingNum){

	if (file_exists(BookingFileName) == 0) {

		const int counted = BookingCount();

		if(counted <= 0){
			return -1;
		}else{
			Booking * ptr = BookingList();

			if (ptr == NULL) {
				return -1;
			}

			for (int x = 0; x < counted; x++) {

				if ( (ptr+x)->BookingNumber == bookingNum ) {
					return x;
				}
			}
		}
	}

	return -1;
}

int BookingExistById(int Id){

	if (file_exists(BookingFileName) == 0) {

		const int counted = BookingCount();

		if(counted <= 0){
			return -1;
		}else{
			Booking * ptr = BookingList();

			if (ptr == NULL) {
				return -1;
			}

			for (int x = 0; x < counted; x++) {

				if ( (ptr+x)->Id == Id) {
					return x;
				}
			}
		}
	}

	return -1;
}

Booking * QueryBookingByDate(Date date){
    ListPos = 0;
    if (file_exists(BookingFileName) == 0) {

		const int counted = BookingCount();

		int foundCounter = 0;



		if(counted <= 0){
			return NULL;
		}else{
			Booking * ptr = BookingList();
            int index[counted+1000];
			if (ptr == NULL) {
				return NULL;
			}

			for (int x = 0; x < counted; x++) {

				if ((ptr+x)->DateBooked.day == date.day && (ptr+x)->DateBooked.month == date.month && (ptr+x)->DateBooked.year == date.year) {
                    index[foundCounter] = x;
					foundCounter++;
				}
			}

			if(foundCounter > 0){
                Booking matchList[foundCounter];

                Booking * listPtr = &matchList[0];
                //Booking * ptr2 = BookingList();
                for(int x = 0; x < foundCounter; x++){
                     Booking b = *(ptr+index[x]);
                     matchList[x] = b;
                }

                if(listPtr != NULL){
                    ListPos = foundCounter;
                    return listPtr;
                }else{
                    return NULL;
                }
			}else{
                return NULL;
			}
		}
	}

	return NULL;
}

Booking * QueryBookingByArtisteId(int Id){
    ListPos = 0;
    if (file_exists(BookingFileName) == 0) {

		const int counted = BookingCount();

		int foundCounter = 0;



		if(counted <= 0){
			return NULL;
		}else{
			Booking * ptr = BookingList();
            int index[counted+1000];
			if (ptr == NULL) {
				return NULL;
			}

			for (int x = 0; x < counted; x++) {

				if ( (ptr+x)->ArtisteId == Id){
                    index[foundCounter] = x;
					foundCounter++;
				}
			}

			if(foundCounter > 0){
                Booking matchList[foundCounter];

                Booking * listPtr = &matchList[0];
                //Booking * ptr2 = BookingList();
                for(int x = 0; x < foundCounter; x++){
                     Booking b = *(ptr+index[x]);
                     matchList[x] = b;
                }

                if(listPtr != NULL){
                    ListPos = foundCounter;
                    return listPtr;
                }else{
                    return NULL;
                }
			}else{
                return NULL;
			}
		}
	}

	return NULL;
}


Booking * QueryBookingByPromoterName(char * promoterName){
    ListPos = 0;
    if (file_exists(BookingFileName) == 0) {

		const int counted = BookingCount();

		int foundCounter = 0;



		if(counted <= 0){
			return NULL;
		}else{
			Booking * ptr = BookingList();
            int index[counted+1000];
			if (ptr == NULL) {
				return NULL;
			}

			for (int x = 0; x < counted; x++) {

				if ( strcmpi((ptr+x)->PromoterName, promoterName) == 0){
                    index[foundCounter] = x;
					foundCounter++;
				}
			}

			if(foundCounter > 0){
                Booking matchList[foundCounter];

                Booking * listPtr = &matchList[0];
                //Booking * ptr2 = BookingList();
                for(int x = 0; x < foundCounter; x++){
                     Booking b = *(ptr+index[x]);
                     matchList[x] = b;
                }

                if(listPtr != NULL){
                    ListPos = foundCounter;
                    return listPtr;
                }else{
                    return NULL;
                }
			}else{
                return NULL;
			}
		}
	}

	return NULL;
}

Booking * QueryBookingEmployeeId(int Id){
    ListPos = 0;
    if (file_exists(BookingFileName) == 0) {

		const int counted = BookingCount();

		int foundCounter = 0;



		if(counted <= 0){
			return NULL;
		}else{
			Booking * ptr = BookingList();
            int index[counted+8000];
			if (ptr == NULL) {
				return NULL;
			}

			for (int x = 0; x < counted; x++) {

				if ( (ptr+x)->EmployeeId == Id){
                    index[foundCounter] = x;
					foundCounter++;
				}
			}

			if(foundCounter > 0){
                Booking matchList[foundCounter];

                Booking * listPtr = &matchList[0];

                for(int x = 0; x < foundCounter; x++){
                     Booking b = *(ptr+index[x]);
                     matchList[x] = b;
                }

                if(listPtr != NULL){
                    ListPos = foundCounter;
                    return listPtr;
                }else{
                    return NULL;
                }
			}else{
                return NULL;
			}
		}
	}

	return NULL;
}
int BookingCountPerYear(int ArtisteId){

	if(file_exists(BookingFileName) == 0){

        int bookingcount = BookingCount();

        int counter = 0;

        if(bookingcount <= 0){
            return counter;
        }else{

            Booking * ptr = BookingList();

            for(int x = 0; x < bookingcount; x++){

                if((ptr+x)->ArtisteId == ArtisteId && (ptr+x)->DateBooked.year == currentYear()){
                    counter++;
                }

            }

            return counter;
        }
	}

	return -1;

}

int BookingCountPerArtiste(int ArtisteId){

	if(file_exists(BookingFileName) == 0){

        int bookingcount = BookingCount();

        int counter = 0;

        if(bookingcount <= 0){
            return counter;
        }else{

            Booking * ptr = BookingList();

            for(int x = 0; x < bookingcount; x++){

                if((ptr+x)->ArtisteId == ArtisteId){
                    counter++;
                }

            }

            return counter;
        }
	}

	return -1;

}

/***********************Booing****************************/







/**************************Dedicated Function**************************/

void ArtisteYearlyReport(){



}

/****************************Dedicated Function**********************/




















void exitProgram(){
    printf("Please Wait");
    int  counter = 12;
    while(counter > 0){
        printf(".");
        Sleep(200);
        if(counter == 1){
            Beep(800,1000);
        }

        counter--;

    }
    printf("\nThanks For Using  Good Bye!");
    exit(1);
}




void nl(int amount){
    for(int x = 0; x < amount; x++){
        printf("\n");
    }
}

void tb(int amount){
    for(int x = 0; x < amount; x++){
        printf("\t");
    }
}

void nlm(int val){
    nl(val);
    printf("****************************************************");
    nl(val);
}

void st(){
    printf("****************************************************");
}

void heading(char *heading){
    nlm(2);
    tb(3);
    printf("%s", heading);
}





#endif // HELPERS_H_INCLUDED
