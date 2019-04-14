#include <stdio.h>
#include <stdlib.h>
#include "Headers/Functions.h"

int main()
{
    //printf("Random: %ld",ran(10000000,10000000000));

    Welcome();

    if(file_exists(UserFileName) == 0){

    printf("\n\n**********************************************************************\n\n");

        for(int x = 0; x < AccountsCount(); x++){
			printf("AccountId: %d - ReferenceId: %d - AccountNumber: %ld - AccountBalance: %.2f - AccountType: %s\n\n",
				(AccountsList() + x)->Id, (AccountsList() + x)->RefId, (AccountsList() + x)->AccountInfo.AccountNum, (AccountsList() + x)->AccountInfo.AccountBalance,
				(AccountsList() + x)->AccountInfo.AccountType == FoundationAccount ? "Foundation" : "Artiste");
        }

    printf("\n\n**********************************************************************\n\n");


        for(int x = 0; x < FoundationCount(); x++){
			printf("FoundationId: %d - NameOfFoundation: %s - YearFounded: %d - Address: %s - NoEmployees: %d - Charity: %s\n\n",
				(FoundationList()+x)->Id, (FoundationList() + x)->NameOfFoundation,
				(FoundationList() + x)->YearFounded, (FoundationList() + x)->Address,
				(FoundationList() + x)->NumberOfEmployees, (FoundationList() + x)->MajorityCurCharity);
        }


	printf("\n\n**********************************************************************\n\n");


		for (int x = 0; x < ArtisteCount(); x++) {
			printf("AzrtisteId: %d - StageName: %s - Firstname: %s - LastName: %s - Telephone#: %s - Address: %s - Email: %s - Genre: %s - FoundationId: %d - YearlyEarnings: %.2f\n\n",
				 (ArtisteList()+x)->Id, (ArtisteList() + x)->StageName, (ArtisteList() + x)->FirstName,
				(ArtisteList() + x)->LastName, (ArtisteList() + x)->TelephoneNumber, (ArtisteList() + x)->PhysicalAddress,
				(ArtisteList() + x)->Email, (ArtisteList() + x)->Genre, (ArtisteList() + x)->FoundationId, (ArtisteList() + x)->YearlyEarnings);
		}


    printf("\n\n**********************************************************************\n\n");

        for(int x = 0; x < UserDataCount(); x++){
            printf("UserName: %s - Password: %s - FullName: %s %s - Type: %d -  Date: %s - ID: %d\n\n",(ListOfUser()+x)->Username,(ListOfUser()+x)->Password, (ListOfUser()+x)->FirstName, (ListOfUser()+x)->LastName,(ListOfUser()+x)->UserType,(ListOfUser()+x)->DateJoined, (ListOfUser()+x)->Id);
        }

        LoginHandler();

    }else{

        printf("\n\n  First Time Usage require (Manager Role): [*Please Create A Manager Role To Continue*]\n");

        AddUser(1);

        system("cls");

        Welcome();

        LoginHandler();
    }

    return 0;
}
