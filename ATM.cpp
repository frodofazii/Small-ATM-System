#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include<string>
void display();
void gotoxy(int,int);
void time();
void help();
void createaccount();
void readingFromTranscationTextFile();
void insertIdIntoIdFile();
void insertPinCodeIntoIdFile();
void insertnameIntonameFile();
void insertemailIntonameFile();
void insertbalanceIntoIdFile();
void updatetranscationTextFile();
void readingFromIdTextFile();
void countingFromIdTextFile();
void readingFromPinCodeTextFile();
void countingFromPinCodeTextFile();
void proceed();
void cashwithdraw();
void loadAlldata();
void balanceinquiry();
void cashdeposit();
void fundtransfer();
////////////
int pinCodecounter=0; ///Global Variables
int	idCounter=0;
int pinCodes[100];
int id[100];

int amounts[100];
int indexSaver;
//////////

using namespace std;

int main()
{
	char ch;
	do{
display();
cin>>ch;
switch(ch)
{
case 'h':
case 'H':	
gotoxy(0,21);
help();
break;
case 'C':
case 'c':
gotoxy(30,15);
createaccount();
break;
case 'P':
case 'p':
gotoxy(30,14);	
proceed();
break;
}
}while(ch!='E'&& ch!='e');

system("pause");

}
void loadAlldata()
{
	 countingFromIdTextFile();
	  countingFromPinCodeTextFile();

 readingFromIdTextFile();
 readingFromPinCodeTextFile();
 readingFromTranscationTextFile();
}
void display()
{
		char ch;
system("cls");
system("title ATM Project");
system("color 1f");	
gotoxy(0,2);
cout<<"ADMIN"<<endl;
time();
gotoxy(0,3);
cout<<"________________________________________________________________________________";
gotoxy(28,11);
cout<<"WELCOME TO MY ATM MACHINE"<<endl;
gotoxy(30,14);
cout<<"P:Press to proceed"<<endl;
gotoxy(30,15);
cout<<"C:Press to create Account"<<endl;
gotoxy(0,20);
cout<<"________________________________________________________________________________";
gotoxy(0,21);
cout<<"H:Press for More Information"<<endl;

cout<<"E:Press Exit"<<endl;


}
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
  
}
void time()
{
   time_t now = time(0);
   
   char* dt = ctime(&now);
	gotoxy(55,2);
   cout<<dt<<endl;
}
void help()
{
	char ch;
	system("cls");
	cout<<"Inorder to Use Our ATM service sure That"<<endl; 
	cout<<"You Might have Already Opened Account"<<endl;
	cout<<"\n";
	cout<<"ATM SERVICE"<<endl;
	cout<<endl;
	cout<<"Cash WithDrawel: Use this service to withdraw amount (40,000/-per day)"<<endl;
	cout<<endl;
	cout<<"Fast Cash: This enables to withdraw your preferred amounts with touch"<<endl;
	cout<<endl;
	cout<<"Balance Enquiry: To cheak the current balance in your account"<<endl;
	cout<<"\n";
	cout<<"Mini statment: keep Track of Transction in your account"<<endl;
	cout<<"\n";
	cout<<"Fund Transfer: Transfer amount intastly your loved ones"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	cout<<"For More Information"<<endl;
	cout<<"Call this NO. 034-6652-9363"<<endl;
	cout<<"              033-6457-7688"<<endl;
	cout<<"              033-6481-2445"<<endl;
	cout<<"\n";
	cout<<"\n";
	cout<<"R:For Return to Mian Menu"<<endl;
	system("pause");	
	}
////////////////////////////////////////////////////
void createaccount()
{
	system("cls");
insertnameIntonameFile();
insertemailIntonameFile();
insertIdIntoIdFile();
insertPinCodeIntoIdFile();
insertbalanceIntoIdFile();
cout<<"Your Account Succesfully Created"<<endl;
	system("pause");
}
void insertnameIntonameFile()
{
	char name[20];
	cout<<"Enter the Name:"<<endl;
	cin>>name;
	cout<<"\n";
		FILE *ptr;
        ptr=fopen("name.txt","a");
	    fprintf(ptr,"%s    \n",name);
	    
		fclose(ptr);
}

void insertIdIntoIdFile()
{	
	int id;
	cout<<"Enter the ID for 1st time:"<<endl;
	cin>>id;
	cout<<"\n";
		FILE *ptr;
        ptr=fopen("id.txt","a");
	    fprintf(ptr,"%d    \n",id);
		fclose(ptr);
}

void insertPinCodeIntoIdFile()
{
	int pinCode;
	cout<<"Enter the PIN CODE of our Desire for 1st Time:"<<endl;
	cin>>pinCode;
	cout<<"\n";
	FILE *ptr;
        ptr=fopen("pinCodes.txt","a");
	    fprintf(ptr,"%d    \n",pinCode);
		fclose(ptr);

}
void insertemailIntonameFile()
{
	char mail[20];
	cout<<"Enter the Correct Email:"<<endl;
	cin>>mail;
	cout<<"\n";
		FILE *ptr;
        ptr=fopen("Email.txt","a");
	    fprintf(ptr,"%s    \n",mail);
	    
		fclose(ptr);
}
void insertbalanceIntoIdFile()
{	
	int balance;
	cout<<"Enter the Initial Balance:"<<endl;
	cin>>balance;
	cout<<"\n";
		FILE *ptr;
        ptr=fopen("initial_balance.txt","a");
	    fprintf(ptr,"%d    \n",balance);
		fclose(ptr);
}
/////////////
//////////////
void proceed()
{
	system("cls");
	char ch;
countingFromPinCodeTextFile();
readingFromPinCodeTextFile();
countingFromIdTextFile();
readingFromIdTextFile();
readingFromTranscationTextFile();
int userId,pncode;
gotoxy(28,12);
cout<<"Enter Your Login Id: ";
cin>>userId;
cout<<"\n";
gotoxy(28,14);
cout<<"Enter the PinCode: ";
cin>>pncode;
//char ch;
//char str[10];
//int i=0;
//while(ch=cin.get()!=13)
//{
	//cout<<"*";
	//str[i]=ch;
	//i++;
//}//
int count=0;

for(int i=0;i<pinCodecounter;i++)
{

if(id[i]==userId)
{
	continue;
	indexSaver=i;
}
count++;
}
if(count==pinCodecounter)
{
	cout<<"Wrong Password"<<endl;
}else
{
	cout<<"Congrtulation You Login";
	system("cls");
	gotoxy(0,2);
	cout<<"C:CASH WITHDRAW"<<endl;
	gotoxy(64,2);
	cout<<"B:BALANCE INQUIRY"<<endl;
	gotoxy(0,15);
	cout<<"D:CASH DEPOSIT"<<endl;
	gotoxy(64,15);
	cout<<"F:FUND TRANSFER"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 'c':
		case 'C':
			cashwithdraw();
			break;
		case 'B':
		case 'b':
		balanceinquiry();
		break;
		case 'D':
		case 'd':
		cashdeposit();
		break;
		case 'F':
		case 'f':
		fundtransfer();
		break;
	}
	}
	
	system("pause");
}
void readingFromIdTextFile()
{
	char const* const filename="id.txt";
  FILE *file=fopen("id.txt","r");
  char line[100];
  int i=0;
  while(fgets(line,sizeof(line),file))
  {
  	
id[i]=atoi(line);
  	i++;
  }
  fclose(file);
  
}
void countingFromIdTextFile()
{
	char const* const filename="id.txt";
  FILE *file=fopen("id.txt","r");
  char line[100];
  while(fgets(line,sizeof(line),file))
  {
  	
  	idCounter++;
  	
  }
 // printf("Current Save ID's %d\n",idCounter);
  fclose(file);
  
}

void readingFromPinCodeTextFile()
{
	char const* const filename="pinCodes.txt";
  FILE *file=fopen("pinCodes.txt","r");
  char line[100];
  int i=0;
  while(fgets(line,sizeof(line),file))
  {
	pinCodes[i]=atoi(line);
  i++;
  }
  fclose(file);
  
  
}
void readingFromTranscationTextFile()
{
	char const* const filename="initial_balance.txt";
  FILE *file=fopen("initial_balance.txt","r");
  char line[100];
  int i=0;
  while(fgets(line,sizeof(line),file))
  {
	amounts[i]=atoi(line);
  i++;
  }
  fclose(file);
  
  
}
void countingFromPinCodeTextFile()
{

	char const* const filename="pinCodes.txt";
  FILE *file=fopen("pinCodes.txt","r");
  char line[100];
  while(fgets(line,sizeof(line),file))
  {
  pinCodecounter++;
  
  }
  
  printf("Current save Data %d\n",pinCodecounter);
  fclose(file);
  
}
void cashwithdraw()
{
	system("cls");
	int rs;
	gotoxy(28,11);
	printf(" Your Cuurent Balance is   = %d\n",amounts[indexSaver]);
	cout<<"Enter the Amount in Rupees "<<endl;
	cin>>rs;
	if(amounts[indexSaver]>rs)
	{
	
	amounts[indexSaver]=amounts[indexSaver]-rs;
printf("\nYour New Balance is    %d  =",amounts[indexSaver]);
}
	else
	printf("Trancscation Failed");
	
	//system("cls");
	updatetranscationTextFile();
	gotoxy(28,11);
	cout<<"Thanks For Using our Service"<<endl;
	
}
void updatetranscationTextFile()
{
	FILE *ptr;
        ptr=fopen("initial_balance.txt","w");
	    for(int i=0;i<idCounter;i++)
	    {
		
		fprintf(ptr,"%d    \n",amounts[i]);
	}
		fclose(ptr);	
}
void balanceinquiry()
{
	system("cls");
	char ch;
	gotoxy(25,12);
cout<<"If You Want to Cheak Balance Then click (Y)";
	cin>>ch;
	if(ch=='Y'||ch=='y')
	{
	printf("Your Balance is    :  %d",amounts[indexSaver]);
	
	}
}
void cashdeposit()
{
	system("cls");
	int rs;
	gotoxy(22,12);
	cout<<"Enter the Amount U want to add in Your Account: ";
	cin>>rs;
	system("cls");
	gotoxy(28,12);
	amounts[indexSaver]=amounts[indexSaver]+rs;
	updatetranscationTextFile();
	cout<<"Cash Deposit Successfully"<<endl;
	cout<"\n";
	cout<<"\n";
}
void fundtransfer()
{
	system("cls");
	int rs,s;
	gotoxy(22,12);
	cout<<"Enter the Amount You want to Transfer ";
	cin>>rs;
	if(amounts[indexSaver]>rs)
	{
	
	gotoxy(22,13);
	cout<<"Enter the Account Nbr you want share ";
	cin>>s;
	int counter=0;
	int idIndexSaver;
for(int k=0;k<idCounter;k++)
{
if(id[k]==s)
{
	idIndexSaver=k;
	continue;
}
counter++;
}
if(counter==idCounter)
{
cout<<"No ID Exists";
}	else
{

	gotoxy(28,12);
	amounts[indexSaver]=amounts[indexSaver]-rs;
	
	amounts[idIndexSaver]=amounts[idIndexSaver]+rs;
	system("cls");

	
updatetranscationTextFile();
	cout<<"Your Fund Transfer Successfully";
getch();
}
}else
{
	cout<<"You have no so much money";
	
}
}
