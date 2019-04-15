#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include "Helpers.h"


void DisplayUsers(){

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

        printf("\n\n\t*Overseas Bookings*\n\n\t\tId\tArtiste\t\tBookingNum\tBookingDate\tCreatedBy\tLocation\tPromoter\tLocalRate\tForeignRate\tVoluntaryService\tHotelName\tHotelCharge\tPlaneFare\n\n");
        for(int x = 0; x < totalBookings; x++){

            if( (ptr+x)->Type == 'O' || (ptr+x)->Type == 'o' ){

                int c = ArtisteExistById((ptr+x)->ArtisteId);
                char * stageName = (ArtisteList()+c)->StageName;

                int k = UserExist( (ptr+x)->EmployeeId );
                char * userE = (ListOfUser()+k)->Username;

                printf("\t\t%-2d\t%-8s\t%-8d\t%d/%d/%d\t%-8s\t%-8s\t%-8s\t%-8.2f\t%-8.2f\t%-8c\t%15s\t\t%.2f\t\t%.2f\n\n",
                 (ptr+x)->Id, stageName,
                  (ptr+x)->BookingNumber,
                    (ptr+x)->DateBooked.day,(ptr+x)->DateBooked.month,(ptr+x)->DateBooked.year,
                    userE,
                    (ptr+x)->Location,(ptr+x)->PromoterName, (ptr+x)->Rate.local, (ptr+x)->Rate.overseas,
                    (ptr+x)->IsVoluntary == one ? 'Y' : 'N',
                       (ptr+x)->Info.HotelInfo,
                       (ptr+x)->Info.HotelCharge,
                       (ptr+x)->Info.PlaneFare
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

}

#endif // DISPLAY_H_INCLUDED
