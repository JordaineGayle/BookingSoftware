#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include "Helpers.h"


void DisplayUsers(){

    printf("\n\n\t\t\t\t\t*All Users In System*\n\n\n");

    printf("\tId\tUserName\tFullName\t\tType\t\tDateJoined\n\n");
    int userTotal = UserDataCount();

    User *ptr = ListOfUser();

    for(int x = 0; x < userTotal; x++){
            printf("\t%-2d\t%s\t\t%s %s\t\t%s\t\t%s\n\n",
                   (ptr+x)->Id,(ptr+x)->Username,(ptr+x)->FirstName, (ptr+x)->LastName,(ptr+x)->UserType == Manager ? "Manager" : "Clerk",(ptr+x)->DateJoined);
        }
}

void DisplayBookings(){

    printf("\n\n\t\t\t\t\t*All Bookings In System*\n\n\n");

    if(file_exists(BookingFileName) == 0){

        int totalBookings = BookingCount();

        Booking *ptr = BookingList();

        printf("\t*Local Bookings*\n\n\t\tId\tArtiste\t\tBookingNum\tBookingDate\tCreatedBy\tLocation\tPromoter\tLocalRate\tForeignRate\tVoluntaryService\n\n");

        for(int x = 0; x < totalBookings; x++){

            if( (ptr+x)->Type == 'l' || (ptr+x)->Type == 'L' ){

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

        }

        printf("\t*Overseas Bookings*\n\n\t\tId\tArtiste\t\tBookingNum\tBookingDate\tCreatedBy\tLocation\tPromoter\tLocalRate\tForeignRate\tVoluntaryService\n\n");

        for(int x = 0; x < totalBookings; x++){

            if( (ptr+x)->Type == 'O' || (ptr+x)->Type == 'o' ){

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

        }

    }else{
        printf("\n\t\t\t\t*No Bookings Available*\n");
    }
}

void DisplayArtiste(){

    printf("\n\n\t\t\t\t\t*All Artiste In System*\n\n\n");

    printf("\tId\tA.StageName\tA.Firstname\tA.Lastname\tA.Cell#\t\tA.Genre\n\n");
    int artisteTotal = ArtisteCount();

    Artiste *ptr = ArtisteList();

    for(int x = 0; x < artisteTotal; x++){
        printf("\t%-2d\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\n\n",
               (ptr+x)->Id, (ptr+x)->StageName, (ptr+x)->FirstName, (ptr+x)->LastName, (ptr+x)->TelephoneNumber, (ptr+x)->Genre );
    }
}

void DisplayFoundation(){
    printf("\n\n\t\t\t\t\t*All Foundation In System*\n\n\n");

    printf("\tId\tFoundation\tYear Founded\tAddress\t\tNo. Employees\tCharity Group\n\n");
    int foundationTotal = FoundationCount();

    Foundation *ptr = FoundationList();

    for(int x = 0; x < foundationTotal; x++){
        printf("\t%-2d\t%-8s\t%-8d\t%-8s\t%-8d\t%-8s\n\n",
               (ptr+x)->Id, (ptr+x)->NameOfFoundation, (ptr+x)->YearFounded, (ptr+x)->Address, (ptr+x)->NumberOfEmployees, (ptr+x)->MajorityCurCharity );
    }
}

#endif // DISPLAY_H_INCLUDED
