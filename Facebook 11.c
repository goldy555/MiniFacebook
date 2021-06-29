#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/// LOGINID: admin
/// PASSWORD: admin111
/// Please save the code in an empty file in case of no input error

typedef struct // Structure to save the date of birth...
{
    int date;
    int month;
    int year;
} db;

typedef struct data//structure to save personal info..
{
    char *name, *nickname, *familyname, *gender, *caller;
    int age;
    db birth;
} data;

FILE *fp;
data newuser() {
    data info;
    char New[500];
    int p = 0;
    printf("\n******************************");
    printf("Enter the new info\n");
    printf("\nEnter user's ID : ");
    scanf("%s", New);
    info.name = (char *) malloc(sizeof(char) * strlen(New + 1));//letting user dynamically enter the datas
    strcpy(info.name, New);
    printf("Enter the User's family name : ");
    scanf("%s", New);
    info.familyname = (char *) malloc(sizeof(char) * strlen(New) + 1);
    strcpy(info.familyname, New);
    printf("Enter the nickname : ");
    scanf("%s", New);
    info.nickname = (char *) malloc(sizeof(char) * strlen(New) + 1);
    strcpy(info.nickname, New);

    do{
            p==0;
    printf("Enter User's age : ");
    scanf("%d", &info.age);
    if(info.age<12 || info.age>=100)
    {

        printf("The age is not correct, delete it from file and reenter the correct data  :\n");
        p=1;

    }
if(p==1){
    printf("enter right info");
}
    }
    while (p=0);
    printf("Enter the gender : ");
    scanf("%s", New);
    info.gender = (char *) malloc(sizeof(char) * strlen(New) + 1);
    strcpy(info.gender, New);
    do {
        int p = 0;
        printf("Enter the date of birth\n(dd\nmm\nyyyy\n) : ");
        scanf("%d%d%d", &info.birth.date, &info.birth.month, &info.birth.year);
        if (info.birth.date <= 0 || info.birth.date > 31) {
            printf("Incorrect date\n");
            p = 1;
        }
        if (info.birth.month <= 0 || info.birth.month > 12) {
            printf("Incorrect month\n");
            p = 1;
        }
        if (info.birth.year > 2019) {
            printf("Incorrect year\n");
            p = 1;
        }
        if (p == 1)
            printf("\nDelete the wrong info from file and Re enter the info with correct datas ...\n");
    }
    while (p == 1);
    printf("\nEnter the caller : ");
    scanf("%s", New);
    info.caller = (char *) malloc(sizeof(char) * strlen(New) + 1);
    strcpy(info.caller, New);
    return info;
}

void add(data info) {

    FILE *fp = fopen("minifacebook.txt", "a");//File to store data, a(append) in case file doesn't exist;

    fprintf(fp, "%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%s\n", info.name, info.familyname, info.nickname, info.age,
            info.gender, info.birth.date, info.birth.month, info.birth.year, info.caller);
    //fprintf to print info in file
    fclose(fp);// to close the file
}


void printUser(data userData) {
    printf("%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%s\n", userData.name, userData.familyname, userData.nickname,
           userData.age, userData.gender, userData.birth.date, userData.birth.month, userData.birth.year,
           userData.caller);
}

void show(char *type, char* param) {
    // type == "all", type == "name", type == "family name"
    int totalLines = 0;

    FILE *file = fopen("./minifacebook.txt", "r");

    char chr;

    while ((chr = getc(file)) != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
            totalLines++;
    }

    rewind(file);

    int lineLength = 2048;
    char field[lineLength];
    data userData;

    for (int i = 0; i < totalLines; i++) {
        fscanf(file, "%s", field);
        userData.name = (char *) malloc(sizeof(char) * lineLength);
        strcpy(userData.name, field);

        fscanf(file, "%s", field);
        userData.familyname = (char *) malloc(sizeof(char) * lineLength);
        strcpy(userData.familyname, field);

        fscanf(file, "%s", field);
        userData.nickname = (char *) malloc(sizeof(char) * lineLength);
        strcpy(userData.nickname, field);

        fscanf(file, "%d", &userData.age);

        fscanf(file, "%s", field);
        userData.gender = (char *) malloc(sizeof(char) * lineLength);
        strcpy(userData.gender, field);
        fscanf(file, "%d", &userData.birth.date);
        fscanf(file, "%d", &userData.birth.month);
        fscanf(file, "%d", &userData.birth.year);

        fscanf(file, "%s", field);
        userData.caller = (char *) malloc(sizeof(char) * lineLength);
        strcpy(userData.caller, field);

        if (strcmp(type, "all") == 0) {
            printUser(userData);
        } else if (strcmp(type, "name") == 0 && strcmp(userData.name, param) == 0) {
            printUser(userData);
        } else if (strcmp(type, "familyname") == 0 && strcmp(userData.familyname, param) == 0) {
            printUser(userData);
        }
    }

    fclose(file);
}
data InFile(){//this function returns the data in file of users one by one.
	char str[1000];
	data info;


	if(fp==NULL)
	fp=fopen("minifacebook.txt","r");

	fscanf(fp,"%s",str);//scan the first string into str
	info.name = (char*)malloc(sizeof(char)*strlen(str)+1);// str+1 ..+1 for terminating character
	strcpy(info.name,str);//copy the str to info.name

	fscanf(fp,"%s",str);
	info.familyname = (char*)malloc(sizeof(char)*strlen(str)+1);
	strcpy(info.familyname,str);

	fscanf(fp,"%s",str);
	info.nickname = (char*)malloc(sizeof(char)*strlen(str)+1);
	strcpy(info.nickname,str);

	fscanf(fp,"%d",&info.age);

	fscanf(fp,"%s",str);
	info.gender = (char*)malloc(sizeof(char)*strlen(str)+1);
	strcpy(info.gender,str);
	fscanf(fp,"%d",&info.birth.date);
	fscanf(fp,"%d",&info.birth.month);
	fscanf(fp,"%d",&info.birth.year);

	fscanf(fp,"%s",str);
	info.caller = (char*)malloc(sizeof(char)*strlen(str)+1);
	strcpy(info.caller,str);
return info;//return data of user in structure.
}
int users()
{
	FILE *fp;
	int n=0;
	char some[1000];
	fp = fopen("minifacebook.txt","r");//open files in read mode
	while(1)
	{
		if(fscanf(fp,"%s",some)!=EOF)//read the file until the end of file
		{
			++n;// keeps counting the number of user in the file
		}
		else
		break;

	}
	n=n/9;//there are 9 elements in structure so n is divided by 9;
	fclose(fp);
	return n;
}

void modify()
{
	char text[50];
	data info;
	int i=0,memlen=0, c=0;
	memlen = users();
	data *mod = (data*)malloc(sizeof(data) * memlen);//dynamically creating a array of the size of number of users in file
	fp=fopen("minifacebook.txt","r");

	while(i<memlen)//loop until the number of users in file
	{
			info = InFile();//info stores the structure return from the function InFile()
			mod[i]=info;//store info in index
			i++;

	}
	fclose(fp);//close file
	printf("Enter the name of the person: ");
	scanf("%s",text);// data from users...
	for(i=0;i<memlen;i++)
	{
		if(strcmp(mod[i].name,text)==0)//search condition
		{
			mod[i] = newuser();
			fp = fopen("minifacebook.txt","w");//open in write mode because this overwrites the data in the file..
			for(i=0;i<memlen;i++)
			{
				fprintf(fp,"%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%s\n",mod[i].name,mod[i].familyname,mod[i].nickname,mod[i].age,mod[i].gender,mod[i].birth.date,mod[i].birth.month,mod[i].birth.year,mod[i].caller);

			}
			fclose(fp);
			printf("The data has been modified");
			c=1;
			break;
           }
		}
	if (c==0)
	printf("there was no such user in database ");
fclose(fp);

}



void Eliminate()
{
	char name[50];
	fp = fopen("minifacebook.txt","r");
	int memlen,i=0,k,v=0;
	memlen = users();//stores number of users in file.....
	data elim;
	data *info = (data*)malloc(sizeof(data) * memlen);//dynamicly make array of structure of size of number of users in file
	while(i<memlen)
	{
			elim = InFile();
			info[i]=elim;
			i++;

	}
	fclose(fp);
	printf("\tDelete the data...");
	printf("Enter the name : ");
	scanf("%s",name);
	for(i=0;i<memlen;i++)
	{
		if(strcmp(info[i].name,name)==0)//find the name in the array which user has entered...
		{
			for(k=i;k<memlen;k++)//decrease size of array
			info[k]=info[k+1];
			memlen--;
			fp = fopen("minifacebook.txt","w");
			for(i=0;i<memlen;i++)
			{
				//store new data in the file...
				fprintf(fp,"%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%s\n",info[i].name,info[i].familyname,info[i].nickname,info[i].age,info[i].gender,info[i].birth.date,info[i].birth.month,info[i].birth.year,info[i].caller);
			}
			fclose(fp);
			printf("Data elimination Successful");
			v=1;
			break;
		}
	}
	if(v==0)
	printf("No data found......");

}


bool Acess(char LoginID[], char password[])//to check login info..
{
    char code[] = "admin111", ID[] = "admin";
    if (!strcmp(ID, LoginID) == 0 && strcmp(code, password) == 0) {
        return true;//sucessful login
    } else {

        return false;//In case of incorrect username or password...
    }

}


void main_menu() // Main Menu function
{
    printf("*******************************\n");
    printf("Menu\n 1.Add new users\n 2.List of all users\n 3.List User by name\n 4.List User by Family Name\n 5.Modify User's Data\n 6.Delete the User from Database\n 7.Exit the program");
    printf("\n*******************************");
}


void main() {

    char LoginID[20];
    char password[8];//storing password
    int pick, i, in;
    data call;

    printf("Enter your LoginID : ");
    scanf("%s", LoginID);

    printf("Enter your 8 character password : ");
    scanf("%s",password);
    /* accept password */



/**********************/

    printf("\n\nPress any key to continue");

    int Enter = Acess(LoginID, password);//calling access fucntion to check username and password

    if (Enter) {
        printf("\n\nLogged IN\n");

        do {
            main_menu();//display menu in screen

            printf("\nEnter the choice: ");
            scanf("%d", &pick);

            switch (pick) {
                case 1: {
                    call = newuser();// call structure function to add info of user
                    add(call); //add user info into file
                    printf("the user have been added to database....");
                    break;

                }
                case 2: {
                    show("all", NULL);
                    break;
                }
                case 3: {
                    char name[1024];

                printf("Enter the User's Name:");
                    scanf("%s", name);
                    show("name", name);
                    break;
                }
                case 4: {
                    char familyname[1024];
                    printf("Enter the User's Family Name:");
                    scanf("%s", familyname);
                    show("familyname", familyname);
                    break;
                }
                case 5: {
                    modify();
                    break;
                }

              case 6:  {

              Eliminate();// delete the data from file
              break;

              }
              case 7: {

              printf("Exiting the program\n");//exit the program
              break;
              }

                default: {
                    printf("Wrong Choice!! Enter Again ");
                    break;
                }
            }

        }
        while (pick <= 6|| pick > 7);

    } else {
        printf("\nIncorrect username or password");
    }
}

