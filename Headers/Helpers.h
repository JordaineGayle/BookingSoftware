#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED
#include <string.h>
#include "Variables.h"
#include "Structures.h"

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

long randAccNum(long mini, long maxx) {

	time_t now;

	srand(time(&now));



	Sleep(10 + rand() % 1000 - 1);

	return (long)abs((mini*rand() % maxx) + rand() % 100) - 1;
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

        Artiste artiste[res+3];

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

    return -1;
}




/***********************Artiste****************************/





/***********************Booking****************************/


/***********************Booing****************************/



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

		Foundation foundation[res + 3];

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

	return -1;
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

		Accounts accounts[res + 3];

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

	return -1;
}

/***********************Accounts****************************/



































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
