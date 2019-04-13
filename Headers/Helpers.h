#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED
#include <string.h>

int LinearUserSearch(User *ptr, char *username, char *password, char uType){

    UserType userType;

    if(uType == 'M' || uType == 'm'){
        userType = Manager;
    }else{
        userType = Clerk;
    }

    for(int usr = 0; usr < 3; usr++){

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
    amount <= -1 ? 1 : amount;
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
