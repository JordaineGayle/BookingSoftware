#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED
#include <string.h>
#include "DATAManipulation.h"

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

void nl(int amount){
    amount <= -1 ? 1 : amount;
    for(int x = 0; x < amount; x++){
        printf("\n");
    }
}

void tb(int amount){
    amount <= 0 ? 1 : amount;
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
