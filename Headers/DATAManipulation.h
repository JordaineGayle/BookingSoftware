#ifndef DATAMANIPULATION_H_INCLUDED
#define DATAMANIPULATION_H_INCLUDED
#define MAX_ARTISTE 20
#define MAX 20
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <windows.h>
#include <string.h>
#include "Helpers.h"

/**************************************************************************/


int CreateUser(User user, char *path, char *mode){

    FILE * usr;

    if(file_exists(path) == 0){

        int currentUsers = UserDataCount();

        if(currentUsers >= 3){

            return 1;

        }else{
            User * ptr = ListOfUser();

            for(int x = 0; x < currentUsers; x++){
                if( (ptr+x)->UserType == user.UserType && (strcmp((ptr+x)->Username, user.Username) == 0)){
                    return 2;
                }
            }

            usr = fopen(path,mode);

            fseek(usr, user.Id, SEEK_SET);
            fwrite(&user, sizeof(user),1,usr);

            fclose(usr);

            return 3;
        }

    }else{

        FILE * fp;

        fp = fopen(path,mode);

        fseek(fp, user.Id, SEEK_SET);
        fwrite(&user, sizeof(user),1,fp);

        fclose(fp);

        return 3;
    }

}


int CreateBooking(Booking booking, char *path, char *mode){

    Sleep(100);

    FILE * fp;

    fp = fopen(path,mode);

    fseek(fp, booking.Id, SEEK_SET);

    if(fwrite(&booking, sizeof(booking),1,fp)){
        fclose(fp);
        return 3;
    }

    fclose(fp);

    return -1;
}


int CreateArtiste(Artiste artiste, char *path, char *mode){

    if(file_exists(path) == 0){

        int totalRecords = ArtisteCount();

        if(totalRecords >= 20){

            return -1; //maximum amount of artiste

        }else{

            int artisteExist = ArtisteExist(artiste.StageName);

            if(artisteExist >- 1){
                return -2;
            }else{

                FILE * fp;

                fp = fopen(path,mode);

                fseek(fp, artiste.Id, SEEK_SET);

                fwrite(&artiste, sizeof(artiste),1,fp);

                fclose(fp);

                return artiste.Id;
            }
        }

    }else{

        FILE * fp;

        fp = fopen(path,mode);

        fseek(fp, artiste.Id, SEEK_SET);

        fwrite(&artiste, sizeof(artiste),1,fp);

        fclose(fp);

        return artiste.Id;
    }

}

int CreateFoundation(Foundation found, char *path, char *mode){

	if (file_exists(path) == 0) {

		int foundationExist = FoundationExist(found.NameOfFoundation);

		if (foundationExist > -1) {

			int foundationId = (FoundationList() + foundationExist)->Id;

			return foundationId;
		}
		else {

			FILE * fp;

			fp = fopen(path, mode);

			fseek(fp, found.Id, SEEK_SET);

			fwrite(&found, sizeof(found), 1, fp);

			fclose(fp);

			return found.Id;
		}
	}
	else {

		FILE * fp;

		fp = fopen(path, mode);

		fseek(fp, found.Id, SEEK_SET);

		fwrite(&found, sizeof(found), 1, fp);

		fclose(fp);

		return found.Id;
	}


}

int CreateAccount(Accounts account, char *path, char *mode){

	if (file_exists(path) == 0) {

		int accountExist = AccountExist(account.AccountInfo.AccountNum);

		if (accountExist > -1) {

			return 2; //already There
		}
		else {

			FILE * fp;

			fp = fopen(path, mode);

			fseek(fp, account.Id, SEEK_SET);

			fwrite(&account, sizeof(account), 1, fp);

			fclose(fp);

			return 3;
		}
	}
	else {

		FILE * fp;

		fp = fopen(path, mode);

		fseek(fp, account.Id, SEEK_SET);

		fwrite(&account, sizeof(account), 1, fp);

		fclose(fp);

		return 3;


	}
}


char * ArtisteRep(ArtisteReport report, char *path, char *mode){

    FILE * aReport = NULL;

    aReport = fopen(path,mode);

    fprintf(aReport,"Id\tArtisteId\tYearly Earnings\n%d\t%d\t%.2f\t%s\n****************************************************************\n\n",report.Id,report.ArtisteId,report.YearlyEarnings,report.Date);

    fclose(aReport);

    return "Record Created Successfully!";

}

char * FoundationRep(FoundationReport report, char *path, char *mode){
    //file pointer
    FILE * fReport = NULL;

    //opening the file
    fReport = fopen(path,mode);

    fprintf(fReport,"Id\tFoundationId\tMajor Charity\tYearly Earnings\n%d\t%d\t%s\t%.2f\t%s\n****************************************************************\n\n",report.Id,report.FoundationId,report.CurrentMajorCharity,report.Revenue,report.Date);

    fclose(fReport);

    return "Record Created Successfully!";
}

char * GeneralRep(GeneralReport report, char *path, char *mode){
    //file pointer
    FILE *gReport = NULL;

    //opening the file
    gReport = fopen(path,mode);

    fprintf(gReport,"Id\tArtisteId\tYearly Earnings\n%d\t%d\t%.2f\t%s\n",report.ArtisteReport.Id,report.ArtisteReport.ArtisteId,report.ArtisteReport.YearlyEarnings,report.ArtisteReport.Date);

    fprintf(gReport,"Id\tFoundationId\tMajor Charity\tYearly Earnings\n%d\t%d\t%s\t%.2f\t%s\n****************************************************************\n\n",report.FoundationReport.Id,report.FoundationReport.FoundationId,report.FoundationReport.CurrentMajorCharity,report.FoundationReport.Revenue,report.FoundationReport.Date);

    fclose(gReport);



    return "Record Created Successfully!";

}

void AddLog(ActivityLog log,char *path, char *mode){
    //file pointer
    FILE * logs = NULL;

    //opening the file
    logs = fopen(path,mode);

    //writing ActivityLog data from a ActivityLog structure to the file
    fprintf(logs,"UserId: %d\nDescription: %s\nDate: %s\n*****************************************\n\n",log.UserId,log.Description,log.Date);


    //closing back the user file
    fclose(logs);
}

/**************************************************************************/



#endif // DATAMANIPULATION_H_INCLUDED
