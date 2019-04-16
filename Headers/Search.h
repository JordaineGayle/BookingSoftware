#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include "Helpers.h"

void SearchUserById(){

    int amtOf = UserDataCount();

    if(amtOf > 0){

        int selection;

        printf("\n\n * -1 Exit Program* \n");
        printf(" * -2 Previous Menu* \n");
        printf(" * -3 Main Menu* \n\n");

        fflush(stdin);
        printf("\n\n Enter User Id: ");
        scanf("%d", &selection);

        if(selection == -1){
            exitProgram();
        }else if(selection == -2){
            MenuSearch(globalUser);
        }else if(selection == -3){
            Menu(globalUser);
        }

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
        }
        SearchUserById();
    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }

}

void SearchUserByUsername(){

    int amtOf = UserDataCount();

    if(amtOf > 0){

        char selection[100];

        printf("\n\n * -1 Exit Program* \n");
        printf(" * -2 Previous Menu* \n");
        printf(" * -3 Main Menu* \n\n");

        fflush(stdin);
        printf("\n\n Enter User-name on File: ");
        gets(selection);
        if(strcmpi(selection,"-1") == 0){
            exitProgram();
        }else if(strcmpi(selection,"-2") == 0){
            MenuSearch(globalUser);
        }else if(strcmpi(selection,"-3") == 0){
            Menu(globalUser);
        }


        printf("\nSearching User File Please Wait");
            int c = 10;
            while(c > 0){
                printf(".");
                Sleep(100);
                c--;
            }
            nl(1);

        User * ptr = QueryUserByUsername(selection);

        if(ptr != NULL){
            st();st();
            printf("\n\n\tId\tUserName\tFullName\t\tType\t\tDateJoined\n\n");

            for(int x = 0; x < ListPos; x++){
            printf("\t%-2d\t%s\t\t%s %s\t\t%s\t\t%s\n\n",
                   (ptr+x)->Id,(ptr+x)->Username,(ptr+x)->FirstName, (ptr+x)->LastName,(ptr+x)->UserType == Manager ? "Manager" : "Clerk",(ptr+x)->DateJoined);
            }
            ListPos = 0;
            st();st();
        }else if(ptr == NULL){
            printf("\n\n\t\t*Sorry No Booking Found*\n\n");
        }
        SearchUserByUsername();

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}

void SearchArtisteById(){

    int amtOf = ArtisteCount();

    if(amtOf > 0){

        int selection;

        printf("\n\n * -1 Exit Program* \n");
        printf(" * -2 Previous Menu* \n");
        printf(" * -3 Main Menu* \n\n");

        fflush(stdin);
        printf("\n\n Artiste Id: ");
        scanf("%d", &selection);
        if(selection == -1){
            exitProgram();
        }else if(selection == -2){
            MenuSearch(globalUser);
        }else if(selection == -3){
            Menu(globalUser);
        }


        printf("\nSearching Artiste File Please Wait");
            int c = 10;
            while(c > 0){
                printf(".");
                Sleep(100);
                c--;
            }
            nl(1);
        int exist = ArtisteExistById(selection);

        if(exist > -1){

            Artiste obj = *(ArtisteList()+exist);
            st();st();
            printf("\n\n\tId\tA.StageName\tA.Firstname\tA.Lastname\tA.Cell#\t\tA.Genre\n\n");
            printf("\t%-2d\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\n\n", obj.Id, obj.StageName, obj.FirstName, obj.LastName, obj.TelephoneNumber, obj.Genre );
            st();st();
        }else if(exist <= -1){
            printf("\n\n\t\t*Sorry No Artiste Found*\n\n");
        }
        SearchArtisteById();

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}

void SearchArtisteByStageName(){

    int amtOf = ArtisteCount();

    if(amtOf > 0){

        char selection[100];

        printf("\n\n * -1 Exit Program* \n");
        printf(" * -2 Previous Menu* \n");
        printf(" * -3 Main Menu* \n\n");

        fflush(stdin);
        printf("\n\n Artiste Username: ");
        gets(selection);
        if(strcmpi(selection,"-1") == 0){
            exitProgram();
        }else if(strcmpi(selection,"-2") == 0){
            MenuSearch(globalUser);
        }else if(strcmpi(selection,"-3") == 0){
            Menu(globalUser);
        }


        printf("\nSearching Artiste File Please Wait");
            int c = 10;
            while(c > 0){
                printf(".");
                Sleep(100);
                c--;
            }
            nl(1);
        int exist = ArtisteExist(selection);

        if(exist > -1){

            Artiste obj = *(ArtisteList()+exist);
            st();st();
            printf("\n\n\tId\tA.StageName\tA.Firstname\tA.Lastname\tA.Cell#\t\tA.Genre\n\n");
            printf("\t%-2d\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\n\n", obj.Id, obj.StageName, obj.FirstName, obj.LastName, obj.TelephoneNumber, obj.Genre );
            st();st();
        }else if(exist <= -1){
            printf("\n\n\t\t*Sorry No Artiste Found*\n\n");
        }
        SearchArtisteByStageName();

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}

void SearchFoundationById(){

    int amtOf = FoundationCount();

    if(amtOf > 0){

        int selection;

        printf("\n\n * -1 Exit Program* \n");
        printf(" * -2 Previous Menu* \n");
        printf(" * -3 Main Menu* \n\n");

        fflush(stdin);
        printf("\n\n Foundation Id: ");
        scanf("%d", &selection);
        if(selection == -1){
            exitProgram();
        }else if(selection == -2){
            MenuSearch(globalUser);
        }else if(selection == -3){
            Menu(globalUser);
        }


        printf("\nSearching Artiste File Please Wait");
            int c = 10;
            while(c > 0){
                printf(".");
                Sleep(100);
                c--;
            }
            nl(1);
        int exist = FoundationExistById(selection);

        if(exist > -1){

            Foundation obj = *(FoundationList()+exist);
            st();st();
            printf("\n\n\tId\tFoundation\tYear Founded\tAddress\t\tNo. Employees\tCharity Group\n\n");
            printf("\t%-2d\t%-8s\t%-8d\t%-8s\t%-8d\t%-8s\n\n",obj.Id, obj.NameOfFoundation, obj.YearFounded, obj.Address, obj.NumberOfEmployees, obj.MajorityCurCharity );
            st();st();
        }else if(exist <= -1){
            printf("\n\n\t\t*Sorry No Foundation Found*\n\n");
        }
        SearchFoundationById();

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}

void SearchFoundationByDateFounded(){

    int amtOf = FoundationCount();

    if(amtOf > 0){

        int selection;

        printf("\n\n * -1 Exit Program* \n");
        printf(" * -2 Previous Menu* \n");
        printf(" * -3 Main Menu* \n\n");

        fflush(stdin);
        printf("\n\n Enter Year Foundation Founded: ");
        scanf("%d", &selection);

        if(selection == -1){
            exitProgram();
        }else if(selection == -2){
            MenuSearch(globalUser);
        }else if(selection == -3){
            Menu(globalUser);
        }


        printf("\nSearching Foundation File Please Wait");
            int c = 10;
            while(c > 0){
                printf(".");
                Sleep(100);
                c--;
            }
            nl(1);

        Foundation * ptr = QueryFoundationByYearFound(selection);

        if(ptr != NULL){
            st();st();
            printf("\n\n\tId\tFoundation\tYear Founded\tAddress\t\tNo. Employees\tCharity Group\n\n");
            for(int x = 0; x < ListPos; x++){
                printf("\t%-2d\t%-8s\t%-8d\t%-8s\t%-8d\t%-8s\n\n",
                    (ptr+x)->Id, (ptr+x)->NameOfFoundation, (ptr+x)->YearFounded, (ptr+x)->Address, (ptr+x)->NumberOfEmployees, (ptr+x)->MajorityCurCharity );
            }
            ListPos = 0;
            st();st();
        }else if(ptr == NULL){
            printf("\n\n\t\t*Sorry No Booking Found*\n\n");
        }
        SearchFoundationByDateFounded();

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }

}



void SearchBookingByBookingNumber(){

    int amtOf = BookingCount();

    if(amtOf > 0){

        int selection;

        printf("\n\n * -1 Exit Program* \n");
        printf(" * -2 Previous Menu* \n");
        printf(" * -3 Main Menu* \n\n");

        fflush(stdin);
        printf("\n\n Enter Booking Number: ");
        scanf("%d", &selection);

        if(selection == -1){
            exitProgram();
        }else if(selection == -2){
            MenuSearch(globalUser);
        }else if(selection == -3){
            Menu(globalUser);
        }

        printf("\nSearching Booking File Please Wait");
            int c = 10;
            while(c > 0){
                printf(".");
                Sleep(100);
                c--;
            }
            nl(1);
        int exist = BookingExistByBookingNumber(selection);

        if(exist > -1){

            Booking obj = *(BookingList()+exist);
            st();st();
            printf("\n\n\t\tId\tArtiste\t\tBookingNum\tBookingDate\tCreatedBy\tLocation\tPromoter\tLocalRate\tForeignRate\tVoluntaryService\n\n");

                int c = ArtisteExistById(obj.ArtisteId);
                char * stageName = (ArtisteList()+c)->StageName;

                int k = UserExist( obj.EmployeeId );
                char * userE = (ListOfUser()+k)->Username;

                printf("\t\t%-2d\t%-8s\t%-8d\t%d/%d/%d\t%-8s\t%-8s\t%-8s\t%-8.2f\t%-8.2f\t%-8c\n\n",
                 obj.Id, stageName,
                  obj.BookingNumber,
                    obj.DateBooked.day,obj.DateBooked.month,obj.DateBooked.year,
                    userE,
                    obj.Location,obj.PromoterName, obj.Rate.local, obj.Rate.overseas,
                    obj.IsVoluntary == one ? 'Y' : 'N'
                 );
            st();st();
        }else if(exist <= -1){
            printf("\n\n\t\t*Sorry No Records Found*\n\n");
        }
        SearchBookingByBookingNumber();
    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}


void SearchBookingByArtisteId(){

    int amtOf = BookingCount();

    if(amtOf > 0){

        int selection;

        printf("\n\n * -1 Exit Program* \n");
        printf(" * -2 Previous Menu* \n");
        printf(" * -3 Main Menu* \n\n");

        fflush(stdin);
        printf("\n\n Enter ArtisteId Associated With Booking: ");
        scanf("%d", &selection);

        if(selection == -1){
            exitProgram();
        }else if(selection == -2){
            MenuSearch(globalUser);
        }else if(selection == -3){
            Menu(globalUser);
        }


        printf("\nSearching Booking File Please Wait");
            int c = 10;
            while(c > 0){
                printf(".");
                Sleep(100);
                c--;
            }
            nl(1);

        Booking * ptr = QueryBookingByArtisteId(selection);

        if(ptr != NULL){
            st();st();
            printf("\n\n\t\tId\tArtiste\t\tBookingNum\tBookingDate\tCreatedBy\tLocation\tPromoter\tLocalRate\tForeignRate\tVoluntaryService\n\n");
            for(int x = 0; x < ListPos; x++){
                int c = ArtisteExistById((ptr+x)->ArtisteId);
                char * stageName = (ArtisteList()+c)->StageName;

                int k = UserExist( (ptr+x)->EmployeeId );
                char * userE = (ListOfUser()+k)->Username;

                printf("\t\t%-2d\t%-8s\t%-8d\t%d/%d/%d\t%-8s\t%-8s\t%-8s\t%-8.2f\t%-8.2f\t%-8c\n\n",
                 (ptr+x)->Id, stageName,
                  (ptr+x)->BookingNumber,
                    (ptr+x)->DateBooked.day,(ptr+x)->DateBooked.month,(ptr+x)->DateBooked.year,
                    userE,
                    (ptr+x)->Location,(ptr+x)->PromoterName, (ptr+x)->Rate.local, (ptr+x)->Rate.overseas,
                    (ptr+x)->IsVoluntary == one ? 'Y' : 'N'
                 );
            }
            ListPos = 0;
            st();st();
        }else if(ptr == NULL){
            printf("\n\n\t\t*Sorry No Booking Found*\n\n");
        }
        SearchBookingByArtisteId();

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }

}

void SearchBookingByDate(){
    int amtOf = BookingCount();

    if(amtOf > 0){

        Date d;

        printf("\n\n * -1 Exit Program* \n");
        printf(" * -2 Previous Menu* \n");
        printf(" * -3 Main Menu* \n\n");

        fflush(stdin);
        printf("\n\n Enter Booking Date (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &d.day,&d.month,&d.year);
        if(d.day == -1 || d.month == -1 || d.year == -1){
            exitProgram();
        }else if(d.day == -2  || d.month == -2 || d.year == -2){
            MenuSearch(globalUser);
        }else if(d.day == -3  || d.month == -3 || d.year == -3){
            Menu(globalUser);
        }


        printf("\nSearching Booking File Please Wait");
            int c = 10;
            while(c > 0){
                printf(".");
                Sleep(100);
                c--;
            }
            nl(1);

        Booking * ptr = QueryBookingByDate(d);

        if(ptr != NULL){
            st();st();
            printf("\n\n\t\tId\tArtiste\t\tBookingNum\tBookingDate\tCreatedBy\tLocation\tPromoter\tLocalRate\tForeignRate\tVoluntaryService\n\n");
            for(int x = 0; x < ListPos; x++){
                int c = ArtisteExistById((ptr+x)->ArtisteId);
                char * stageName = (ArtisteList()+c)->StageName;

                int k = UserExist( (ptr+x)->EmployeeId );
                char * userE = (ListOfUser()+k)->Username;

                printf("\t\t%-2d\t%-8s\t%-8d\t%d/%d/%d\t%-8s\t%-8s\t%-8s\t%-8.2f\t%-8.2f\t%-8c\n\n",
                 (ptr+x)->Id, stageName,
                  (ptr+x)->BookingNumber,
                    (ptr+x)->DateBooked.day,(ptr+x)->DateBooked.month,(ptr+x)->DateBooked.year,
                    userE,
                    (ptr+x)->Location,(ptr+x)->PromoterName, (ptr+x)->Rate.local, (ptr+x)->Rate.overseas,
                    (ptr+x)->IsVoluntary == one ? 'Y' : 'N'
                 );
            }
            ListPos = 0;
            st();st();
        }else if(ptr == NULL){
            printf("\n\n\t\t*Sorry No Booking Found*\n\n");
        }
        SearchBookingByDate();

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }

}

void SearchBookingByPromoterName(){

    int amtOf = BookingCount();

    if(amtOf > 0){

        char selection[100];

        printf("\n\n * -1 Exit Program* \n");
        printf(" * -2 Previous Menu* \n");
        printf(" * -3 Main Menu* \n\n");

        fflush(stdin);
        printf("\n\n Enter Promoter Name On Booking: ");
        gets(selection);
        if(strcmpi(selection,"-1") == 0){
            exitProgram();
        }else if(strcmpi(selection,"-2") == 0){
            MenuSearch(globalUser);
        }else if(strcmpi(selection,"-3") == 0){
            Menu(globalUser);
        }


        printf("\nSearching Booking File Please Wait");
            int c = 10;
            while(c > 0){
                printf(".");
                Sleep(100);
                c--;
            }
            nl(1);

        Booking * ptr = QueryBookingByPromoterName(selection);

        if(ptr != NULL){
            st();st();
            printf("\n\n\t\tId\tArtiste\t\tBookingNum\tBookingDate\tCreatedBy\tLocation\tPromoter\tLocalRate\tForeignRate\tVoluntaryService\n\n");
            for(int x = 0; x < ListPos; x++){
                int c = ArtisteExistById((ptr+x)->ArtisteId);
                char * stageName = (ArtisteList()+c)->StageName;

                int k = UserExist( (ptr+x)->EmployeeId );
                char * userE = (ListOfUser()+k)->Username;

                printf("\t\t%-2d\t%-8s\t%-8d\t%d/%d/%d\t%-8s\t%-8s\t%-8s\t%-8.2f\t%-8.2f\t%-8c\n\n",
                 (ptr+x)->Id, stageName,
                  (ptr+x)->BookingNumber,
                    (ptr+x)->DateBooked.day,(ptr+x)->DateBooked.month,(ptr+x)->DateBooked.year,
                    userE,
                    (ptr+x)->Location,(ptr+x)->PromoterName, (ptr+x)->Rate.local, (ptr+x)->Rate.overseas,
                    (ptr+x)->IsVoluntary == one ? 'Y' : 'N'
                 );
            }
            ListPos = 0;
            st();st();
        }else if(ptr == NULL){
            printf("\n\n\t\t*Sorry No Booking Found*\n\n");
        }
        SearchBookingByPromoterName();

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }

}

void SearchBookingByEmployeeId(){

    int amtOf = BookingCount();

    if(amtOf > 0){

        int selection;

        printf("\n\n * -1 Exit Program* \n");
        printf(" * -2 Previous Menu* \n");
        printf(" * -3 Main Menu* \n\n");

        fflush(stdin);
        printf("\n\n Enter Employee Id On Booking: ");
        scanf("%d", &selection);

        if(selection == -1){
            exitProgram();
        }else if(selection == -2){
            MenuSearch(globalUser);
        }else if(selection == -3){
            Menu(globalUser);
        }


        printf("\nSearching Booking File Please Wait");
            int c = 10;
            while(c > 0){
                printf(".");
                Sleep(100);
                c--;
            }
            nl(1);

        Booking * ptr = QueryBookingEmployeeId(selection);

        if(ptr != NULL){
            st();st();
            printf("\n\n\t\tId\tArtiste\t\tBookingNum\tBookingDate\tCreatedBy\tLocation\tPromoter\tLocalRate\tForeignRate\tVoluntaryService\n\n");
            for(int x = 0; x < ListPos; x++){
                int c = ArtisteExistById((ptr+x)->ArtisteId);
                char * stageName = (ArtisteList()+c)->StageName;

                int k = UserExist( (ptr+x)->EmployeeId );
                char * userE = (ListOfUser()+k)->Username;

                printf("\t\t%-2d\t%-8s\t%-8d\t%d/%d/%d\t%-8s\t%-8s\t%-8s\t%-8.2f\t%-8.2f\t%-8c\n\n",
                 (ptr+x)->Id, stageName,
                  (ptr+x)->BookingNumber,
                    (ptr+x)->DateBooked.day,(ptr+x)->DateBooked.month,(ptr+x)->DateBooked.year,
                    userE,
                    (ptr+x)->Location,(ptr+x)->PromoterName, (ptr+x)->Rate.local, (ptr+x)->Rate.overseas,
                    (ptr+x)->IsVoluntary == one ? 'Y' : 'N'
                 );
            }
            ListPos = 0;
            st();st();
        }else if(ptr == NULL){
            printf("\n\n\t\t*Sorry No Booking Found*\n\n");
        }
        SearchBookingByEmployeeId();

    }else{
        printf("\n\nNo Records Returned For This Request\n\n");
    }
}


#endif // SEARCH_H_INCLUDED
