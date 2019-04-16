#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include "Helpers.h"

void SearchUserById(){

    int amtOf = UserDataCount();

    if(amtOf >= 0){

        int selection;

        fflush(stdin);
        printf("\n\n Enter User Id: ");
        scanf("%d", &selection);
        printf("\nSearching Userfile Please Wait");
            int c = 10;
            while(c > 0){
                printf(".");
                Sleep(100);
                c--;
            }
            nl(1);
        int exist = UserExist(selection);

        if(exist > -1){

            User obj = *(ListOfUser()+exist);
            st();st();
            printf("\n\n\tId\tUserName\tFullName\t\tType\t\tDateJoined\n\n");
            printf("\t%-2d\t%s\t\t%s %s\t\t%s\t\t%s\n\n", obj.Id,obj.Username,obj.FirstName, obj.LastName,obj.UserType == Manager ? "Manager" : "Clerk",obj.DateJoined);
            st();st();
        }else if(exist <= -1){
            printf("\n\n\t\t*Sorry No User Found By That Id*\n\n");
            SearchUserById();
        }

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }

}

/*printf("\nSearching Please Wait");
            int c = 10;
            while(c > 0){
                printf(".");
                Sleep(100);
                c--;
            }
            nl(1);*/
void SearchUserByUsername(char * uname){

    int amtOf = UserDataCount();

    if(amtOf >= 0){

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}

void SearchArtisteById(int Id){

    int amtOf = ArtisteCount();

    if(amtOf >= 0){

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}

void SearchArtisteByStageName(char * uname){

    int amtOf = ArtisteCount();

    if(amtOf >= 0){

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}

void SearchFoundationById(char * fname){

    int amtOf = FoundationCount();

    if(amtOf >= 0){

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}

void SearchFoundationByDateFounded(char * fname){

    int amtOf = FoundationCount();

    if(amtOf >= 0){

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}



void SearchBookingByBookingNumber(int Id){

    int amtOf = BookingCount();

    if(amtOf >= 0){

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}


void SearchBookingByArtisteId(char * fname){

    int amtOf = BookingCount();

    if(amtOf >= 0){

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}



void SearchBookingByPromoterName(int Id){

    int amtOf = BookingCount();

    if(amtOf >= 0){

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}

void SearchBookingByEmployeeId(char * uname){

    int amtOf = BookingCount();

    if(amtOf >= 0){

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}


#endif // SEARCH_H_INCLUDED
