#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* Athira Jasmine S - 1706064630
Nabila Ayu A - 1706019803 */

struct node {

char nameRegist [100], username[15], pass[15], HP[15], eMail[100];
struct node *ptr;
}*front,*front1,*rear,*temp;


char mov[20][250]={"A Star is Born\t Studio 1", "First Man\t\t Studio 2", "Venom\t\t Studio 3", "Small Foot\t\t Studio 4"};
char name[32][100]={'\0'};
char number [32][2]={'\0'};
int num[32]={0};
int movno;
int i=0;
int money, totmoney=0;
char nameregist [100], username1[15], pass1[15], username2[15], pass2[15], hp[15], email[100];

void menu();
void signup();
void login();
void interface();
void addmoney();
void checkmoney();
void nowshowing();
void namenumber(int amount, char numstr[100]);
void buyticket ();
int readnumber (int movno);
void readname (int movno);
void status ();
void statusbuy (int );
int exitchoice();
void inserT();
void display();
void userInsert();
void passInsert();
void confirm(int data);

FILE *fptr;
char tempt[255],usr[255],pss[255];
int opt, count=0;

void main()
{
    int i;
    front = rear = NULL;
	printf("\n\n");

	printf("\n\n\t\t\t\t---------------WELCOME TO ONLINE MARGO CINEMA !---------------------");

	printf("\n\n\n");
	system("pause");

    // membuka txt username buat ditaruh di linked list
    fptr = fopen("username.txt","r");
   	while(fgets(tempt, sizeof(tempt), fptr))
	{
	    for(i=0;i<strlen(tempt)-1;i++)
        {
            usr[i] = tempt[i];
        }
        userInsert();
        tempt[0] = '\0';
        usr[0] = '\0';
    }
    fclose(fptr);

    // membuka txt password buat ditaruh di linked list
    fptr = fopen("pass.txt","r");
   	while(fgets(tempt, sizeof(tempt), fptr))
	{
	    for(i=0;i<strlen(tempt)-1;i++)
        {
            pss[i] = tempt[i];
        }
        passInsert();
        tempt[0] = '\0';
        pss[0] = '\0';
        count++;
    }
    fclose(fptr);

	menu();
}

void menu()
{
	int choice;

	system("cls");
	printf("\n\n\t\t\t\t*~*~*~*~*~*~* WELCOME TO ONLINE MARGO CINEMA *~*~*~*~*~*~*\n\n");
	printf("\n\n\n");
	printf("\n\t\t\t\t1) Sign Up");
	printf("\n\t\t\t\t2) Login");
	printf("\n\t\t\t\t3) Help");
	printf("\n\t\t\t\t4) Exit ");

	printf("\n\n\t\t\t\tYour pick : ");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			signup();
		break;

		case 2:
			login();
			interface();
		break;

		case 3:
			printf("\n\nThis program's main function is to help you book tickets to watch movies in Margo Cinema.\nTo operate this program, you may follow these steps:");
			printf("\n\n1) Choose '1' to regist your account. Just fill the identity that the program ask");
			printf("\n2) Enter the username and the password for your account. Remember your username and password for you account");
			printf("\n3) Then, choose '2' to log in. Enter your username and password that you have previously registered");
			printf("\n4) If you entered correctly, you will login to the system. If not, repeat to enter again");

			printf("\n\n");
			system("pause");
			menu();
		break;

		case 4:
			exitchoice();
		break;

		default:
			printf("\n\t\t\t\tPlease choose between [1], [2], [3], or [4]!");
			printf("\n\n");
			system("pause");
			menu();
	}
}

void interface()
{
	int choice, i;

	system("cls");
	printf("\n\n\t\t\t---------------Welcome To Margo Cinema Ticket Booking System---------------");
	printf("\n\n\n");

	printf("\n\t\t\t\t[1] Add Money\n\t\t\t\t[2] Check Money\n\t\t\t\t[3] Now Showing\n\t\t\t\t[4] Buy Ticket\n\t\t\t\t[5] Seat Availability\n\t\t\t\t[6] Help\n\t\t\t\t[7] Logout and Exit");
	printf("\n\n\t\t\t\tYour choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			addmoney();
			interface();
		break;

		case 2:
			checkmoney();
			interface();
		break;

		case 3:
			nowshowing();
			interface();
		break;

		case 4:
			buyticket();
			interface();
		break;

		case 5:
			status();
			interface();

		break;


		case 6:
			printf("\n\nThis menu consist of 8 menu with the explanation:");
			printf("\n'1' is used to add the money for your account to buy the ticket. You can add based on you want");
			printf("\n'2' is used to check your current money");
			printf("\n'3' is used to see the list of movies currently playing.");
			printf("\n'4' is used to buy the ticket for the movie you want to see. You may input the code of the movie.\n    Then, enter the amount of tickets you want to buy. Choose the seat number and fill the name in.\n    Finally, your ticket has been booked!");
			printf("\n'5' is used to check the status of the available seat for each movies.");
			printf("\n'6' is used to give the explanation for each choice of menu.");
			printf("\n'7' is used to log out and exit the menu.");


			printf("\n\n");
			system("pause");
			interface();
		break;

		case 7:
			exitchoice();
		break;

		default:
			printf("\t\t\t\tPlease choose between [1] until [7]!");
			printf("\n\n");
			system("pause");
			interface();
	}
}

void addmoney()
{
	system("cls");
	printf("\n\n\n");

	printf("\t\t\t\tYour current money: Rp. %d", totmoney);
	printf("\n\n\t\t\t\tHow much money do you want to add?: Rp. ");
	scanf("%d", &money);

	totmoney+=money;

	printf("\n\n\t\t\t\t>>>>Your current money: Rp. %d", totmoney);
	printf("\n\n");
	system("pause");
}

void checkmoney()
{
	system("cls");
	printf("\n\n\n");

	printf("\t\t\t\t>>>>Your current money: Rp. %d", totmoney);
	printf("\n\n");
	system("pause");
}

void nowshowing()
{
	system("cls");
	printf("\n\n\n");

	printf("\n\n\t\t\t\t NOW SHOWING:");
	printf("\n\n\t\t\t\t[Code] Movie\t\t    Studio");
	printf("\n\n\t\t\t\t[1] %s\n\t\t\t\t[2] %s\n\t\t\t\t[3] %s\n\t\t\t\t[4] %s", mov[0], mov[1], mov[2], mov[3]);
	printf("\n\n");
	system("pause");
	interface();
}

void buyticket()
{
	int i=0, a, choice,movno;
	char numstr[100];

	system("cls");
	printf("\n\n\n");

	printf("\t\t\t\tNow Showing Movies:");
	printf("\n\n\t\t\t\t[Code] Movies\t\t    studio");
	printf("\n\n\t\t\t\t[1] %s\n\t\t\t\t[2] %s\n\t\t\t\t[3] %s\n\t\t\t\t[4] %s", mov[0], mov[1], mov[2], mov[3]);
	printf("\n\n\t\t\t\tPrice @Rp.100000");
	printf("\n\n");

	printf("\t\t\t\tYour choice: ");
	scanf("%d", &movno);

	if(movno<1 || movno>4)
	{
		printf("\n\n\t\t\t\tPlease choose between [1] until [4]!");
		printf("\n\n");
		buyticket();
	}

	printf("\t\t\t\tYour Ticket Code: %d ********** %s", movno, mov[movno-1]);
	statusbuy(movno);

	FILE *f1, *fopen();
	char str1[80]="32", str2[4], str3[4];
	int seat1, amount=0;

	switch(movno)
	{
		case 1:
			f1= fopen("mov1.txt", "r+");
			fgets(str1,80,f1);
			fclose(f1);
		break;

		case 2:
			f1= fopen("mov2.txt", "r+");
			fgets(str1,80,f1);
			fclose(f1);
		break;

		case 3:
			f1= fopen("mov3.txt", "r+");
			fgets(str1,80,f1);
			fclose(f1);
		break;

		case 4:
			f1= fopen("mov4.txt", "r+");
			fgets(str1,80,f1);
			fclose(f1);
		break;

	}

	seat1= atoi(str1);

	if(seat1<=0)
	{
		printf("\t\t\t\tThe seats are full");
	}

	else
	{
		Loopamo:
		printf("\n\t\t\t\tAvailable Seats: %d", seat1);
		printf("\n\n\t\t\t\tHow many ticket do you want to buy?: ");
		scanf("%d", &amount);
		printf("\n");

		a=100000*amount;

		if(totmoney<a)
		{
			Loopnoten:
			printf("\n\t\t\t\t>>>>>Your current money: Rp. %d", totmoney);
			printf("\n\n\t\t\t\tYour current money is not enough");
			printf("\n\t\t\t\t[1] Reduce the amount of ticket\n\t\t\t\t[2] Go to 'Add Money' Menu");
			printf("\n\n\t\t\t\tYour choice: ");
			scanf("%d", &choice);

			switch(choice)
			{
				case 1:
					goto Loopamo;
				break;

				case 2:
					printf("\n\n");
					system("pause");
					addmoney();
					interface();
				break;

				default:
					printf("\t\t\t\tPlease choose between [1] or [2]!");
					printf("\n\n");
					system("pause");

					goto Loopnoten;
			}
		}

		seat1-=amount;
		itoa(movno, numstr, 10);
		namenumber(amount, numstr);

		printf("\t\t\t\tThe total price is Rp. %d", a);

		totmoney-=a;
		printf("\n\n\t\t\t\t>>>>>Your current money: Rp. %d", totmoney);

		itoa(seat1, str1, 10);

		switch(movno)
		{
			case 1:
				f1= fopen("mov1.txt", "w");
				fputs(str1,f1);
				fclose(f1);
			break;

			case 2:
				f1= fopen("mov2.txt", "w");
				fputs(str1,f1);
				fclose(f1);
			break;

			case 3:
				f1= fopen("mov3.txt", "w");
				fputs(str1,f1);
				fclose(f1);
			break;

			case 4:
				f1= fopen("mov4.txt", "w");
				fputs(str1,f1);
				fclose(f1);
			break;

		}
	}
	printf("\n\n");
	system("pause");
}

void statusbuy(int movno)
{
	printf("\t\t\t\tYour Ticket Code: %d ********** %s", movno, mov[movno-1]);
	system("cls");
	printf("\n\n\n");

	int i, j, index=0;
	j=readnumber(movno);
	readname(movno);

	char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};

	for(i=0; i<j; i++)
	{
		strcpy(tempname[num[i]], name[i]);
	}

	printf("\t\t\t\t\t\t\tSCREEN\n\n");
	for(i=0; i<8; i++)
	{
		printf("\t\t\t\t");
		for(j=0; j<4; j++)
		{
			printf("%d.%s\t", index+1, tempname[index+1]);
			index++;
		}
		printf("\n");
	}
}

void status()
{
	system("cls");
	printf("\n\n\n");

	int i, j, movno, index=0;

	printf("\t\t\t\tEnter the code of the movie: ");
	scanf("%d", &movno);

	j=readnumber(movno);
	readname(movno);

	printf("\t\t\t\tMovie with the code %d: %s", movno, mov[movno-1]);
	printf("\n\n");

	char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};

	for(i=0; i<j; i++)
	{
		strcpy(tempname[num[i]], name[i]);
	}

	printf("\t\t\t\t\t\t\tSCREEN\n\n");
	for(i=0; i<8; i++)
	{
		printf("\t\t\t\t");
		for (j=0; j<4; j++)
		{
			printf("%d.%s\t", index+1, tempname[index+1]);
			index++;
		}
		printf("\n");
	}

	printf("\n\n");
	system("pause");
}

int readnumber(int movno)
{
	char tempstr[100], tempstr2[12]= "number";

	FILE *a, *b;

	char numstr[100];

	int i=0, j=0, k;

	itoa(movno, numstr, 10);
	strcat(numstr,".txt");
	strcat(tempstr2,numstr);

	a=fopen(tempstr2, "a+");
		while(!feof(a))
		{
			number[i][j]=fgetc(a);

			if(number[i][j] == ' ')
			{
				j=0;
				i++;
			}

			else
			{
				j++;
			}
		}
			k=i;

			for(i=0; i<k; i++)
			{
				num[i]= atoi(number[i]);
			}

			fclose(a);

			return k;
}

void readname(int movno)
{
	char tempstr1[12]="name";

	FILE *b;

	char numstr[100];

	int i=0, j=0, k=0;

	itoa(movno, numstr, 10);
	strcat(numstr, ".txt");
	strcat(tempstr1, numstr);

	b=fopen(tempstr1, "a+");
		while(!feof(b))
		{
			name[i][j]= fgetc(b);

			if(name[i][j] == ' ')
			{
				j=0;
				i++;
			}

			else
			{
				j++;
			}
		}

		name[i][j]='\0';
		k=i;
		fclose(b);
}

void namenumber(int amount, char numstr[100])
{
	char tempstr[100], tempstr1[12]="name", tempstr2[12]="number";
	int number;

	FILE *a, *b;
	int i=0;

	strcat(numstr, ".txt");
	strcat(tempstr1, numstr);
	strcat(tempstr2, numstr);

	a=fopen(tempstr1, "a");
	b=fopen(tempstr2, "a");

	for(i=0; i<amount; i++)
	{
		printf("\t\t\t\tEnter the details for ticket no. %d\n", i+1);
		printf("\t\t\t\tInput the seat number: ");
		scanf("%d", &number);
		printf("\t\t\t\tInput the name of person: ");
		scanf("%s", name[number-1]);
		printf("\n\n");

		itoa(number, tempstr, 10);
		fprintf(a, "%s ", name[number-1]);
		fprintf(b, "%s ", tempstr);
	}

	fclose(a);
	fclose(b);
}

void signup()
{
	int c=' ';
	char pass3[15];
	system("cls");
	printf("\n\n\n");
	printf("\t\t\t\tAccount Registration");
	printf("\n\n\n\t\t\t\tInput your name\t\t\t: ");
	scanf("  %60[^\n]", &nameregist);
	printf("\t\t\t\tInput your phone number\t\t: ");
	scanf(" %s", &hp);
	printf("\t\t\t\tInput your e-mail address\t: ");
	scanf(" %s", &email);

	printf("\n\t\t\t\tInput your username (max 15 character using alphabet and number): ");
	scanf("%s", &username1);

	Looppass:
	printf("\t\t\t\tInput your password (max 15 character using alphabet and number): ");

	while(i<15)
	{
	    pass1[i]=getch();
	    c=pass1[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pass1[i]='\0';
	i=0;

	printf("\t\t\t\t\t\t\tConfirm your password (max 15 character using alphabet and number): ");

	while(i<15)
	{
	    pass3[i]=getch();
	    c=pass3[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pass3[i]='\0';
	i=0;

	if (strcmp(pass1, pass3) != 0)
	{
		printf("\n\n\t\t\t\tYour confirmed password is wrong!");
		printf("\n\n");
		system("pause");
		printf("\n");
		goto Looppass;
	}

	printf("\n\n\t\t\t\tYour account is successfully registered! Your detail account are: ");
	printf("\n\t\t\t\tName\t\t\t: %s", nameregist);
	printf("\n\t\t\t\tPhone Number\t\t: %s", hp);
	printf("\n\t\t\t\tE-mail Address\t\t: %s", email);
	printf("\n\n\t\t\t\tYour Username\t\t: ");
	printf("%s", username1);

	// masukin username dan pass yang baru
    inserT();

    // memindahkan semua data dari linked list ke txt
    fptr = fopen("username.txt","w+");
    front1 = front;
        while(front1 != NULL)
        {
            fprintf(fptr,"%s",front1->username);
            front1 = front1->ptr;
        }
    fclose(fptr);

    // memindahkan semua data dari linked list ke txt
    fptr = fopen("pass.txt","w+");
    front1 = front;
        while(front1 != NULL)
        {
            fprintf(fptr,"%s",front1->pass);
            front1 = front1->ptr;
        }
    fclose(fptr);

	printf("\n\n");
	system("pause");
	menu();
}

void login()
{
	int i=0, choice1;
	char c=' ';
	system("cls");
	display();
	printf("\n\n\n");
	printf("\t\t\t\tChoose your username: ");
	scanf("%d", &opt);
	confirm(opt-1); // setelah milih username, buat menyesuaikan password dgn pilihan user
	//printf("%s\n", pass1);
	printf("\t\t\t\tEnter your password: ");

	while(i<15)
	{
	    pass2[i]=getch();
	    c=pass2[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pass2[i]='\0';
	i=0;

	if (strcmp(pass1, pass2) == 0)
	{
		printf("\n\n\t\t\t\tLogin is Successful!");
		printf("\n\t\t\t\tWelcome!");
		printf("\n\n");
		system("pause");
	}

	else
	{
		printf("\n\n\t\t\t\tYour passwords are wrong!");
		printf("\n\t\t\t\t[1] Sign Up\n\t\t\t\t[2] Repeat to Enter");
		printf("\n\t\t\t\tYour choice: ");
		scanf("%d", &choice1);

		switch(choice1)
		{
			case 1:
				signup();
			break;

			case 2:
				login();
			break;
		}
	}
}

// masukkan data baru lewat sign up
void inserT()
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        strcpy(rear->username,username1);
        strcpy(rear->pass,pass1);
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        strcpy(temp->username,username1);
        strcpy(temp->pass,pass1);
        temp->ptr = NULL;

        rear = temp;
    }
}

// masukin data dari txt ke linked list
void userInsert()
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        strcpy(rear->username,usr);
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        strcpy(temp->username,usr);
        temp->ptr = NULL;

        rear = temp;
    }
}

void passInsert()
{
    int counting1=0;
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("List is empty\n");
        return;
    }

	while (counting1 != count)
   		{
	    front1 = front1->ptr;
        counting1++;
		}
        strcpy(front1->pass,pss);
}

void confirm(int data)
{
	int counting1=0;
	front1 = front;

	while (counting1 != data)
   		{
	    front1 = front1->ptr;
        counting1++;
		}
    strcpy(username1,front1->username);
    strcpy(pass1,front1->pass);
}

void display()
{
	int i=1;
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("List is empty\n");
        return;
    }
    while (front1 != NULL)
    {
        printf("\t\t\t\t%d\t%s\n", i, front1->username);
        front1 = front1->ptr;
        i++;
    }
}

int exitchoice()
{
	printf("\n\t\t\t\tYou have been logged out.");
	printf("\n\t\t\t\tThank you for using this system!");
	printf("\n\t\t\t\tSee you at the movie!");

	printf("\n\n");
	system("pause");
	return 0;
}
