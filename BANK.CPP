#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "conio.h"
#include <bits/stdc++.h>
using namespace std;
class account
{
 int acno;
 char username[20];
 int deposit;
 char type[3];

 public:
   void create_account();
   void show_account();
   void f_deposit(int);
   void draw(int);
   int return_acno();
   int return_deposit();
   char* return_type();
   char* return_username();
};

void account::create_account()
 {
  cout<<endl<<"--------------------------------"<<endl;
  cout<<"ENTER DETAILS:" <<endl;
  cout<<"--------------------------------"<<endl;
  cout<<"\nEnter the account number:"<<endl;
  cin>>acno;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  cout<<"Enter the name of the account holder: "<<endl;
  cin.getline(username,500);
  cout<<"Enter the type of the account: "<<endl;
  cin.getline(type,500);
  cout<<"Enter the initial amout of deposit: " <<endl;
  cin>>deposit;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  cout<<"\n\nYOUR ACCOUNT HAS BEEN CREATED"<<"\n";
  cout<<"--------------------------------"<<endl<<endl;
 }

void account::show_account()
{

 cout<<"\n Account Number: "<<acno;
 cout<<"\n Name of the Account Holder: ";
 cout<<username;
 cout<<"\n Type of Account: "<<type;
 cout<<"\n Balance Account: "<<deposit;
 cout<<"\n\n--------------------------------\n\n";
}

void account::f_deposit(int y)
 {
    deposit=deposit+y;
 }
void account::draw(int y)
 {
    deposit=deposit-y;
 }
int account::return_acno()
 {
    return acno;
 }
int account::return_deposit()
 {
    return deposit;
 }
char* account::return_type()
 {
    return type;
 }

 char* account::return_username()
 {
    return username;
 }



void Intro()
 {
   cout<<"-------------------------------------------------------------"<<endl;
   cout<<endl;
   cout<<"                    WELCOME TO E-BANKING"<<endl<<endl;
   cout<< "----------------------------> <------------------------------"<<endl;
   cout<<endl;
 }

//create a new file

void create()
{
 int i,n;
 account a;
 ofstream fout;
 cout<<"How many records you want?"<<endl;
 cin>>n;
 fout.open("bank.txt",ios::out|ios::binary);

 for(i=0;i<n;i++)
 {
  a.create_account();
  fout.write((char*)&a,sizeof(a));
 }
fout.close();
}

//read file

void display()
{
 account a;
 ifstream fin;
 fin.open("bank.txt",ios::in|ios::binary);
 fin.seekg(0);
 while(fin.read((char*)&a,sizeof(a)))
 {
  a.show_account();
 }
fin.close();
}
void copy(char user[20])
{remove("user.txt");
 fstream f,t;
 account a;
 f.open("bank.txt",ios::in|ios::binary);
 t.open("user.txt",ios::out|ios::binary);
 f.seekg(0,ios::beg);
 while(f.read((char*)&a,sizeof(a)))
 {if (strcmp(user,a.return_username())==0)
   {t.write((char*)&a,sizeof(a));}
 }
f.close();
t.close();
}
void user_display(char user[20])
{copy(user);
 account a;
 ifstream fin;
 fin.open("user.txt",ios::in|ios::binary);
 while(fin.read((char*)&a,sizeof(a)))
 {
  a.show_account();
 }
fin.close();
}

//search based on account type
void search_type()
{
 account a;
 char choice_type[3],flag=0;
 std::ifstream fin;
 fin.open("bank.txt",ios::in|ios::binary);
 cout<<"Enter account type of your choice: "<<endl;
 cin>>choice_type;
 while(fin.read((char*)&a,sizeof(a)))
 {
  if(strcmp(a.return_type(),choice_type)==0)
   {
    a.show_account();
    flag=1;
   }
 }
 fin.close();
 if (flag==0)
 {
  cout<<"Sorry! Account not found! Please check again!"<<endl;
 }
 }

 void user_search_type(char user[20])
{copy(user);
 account a;
 char choice_type[3],flag=0;
 std::ifstream fin;
 fin.open("user.txt",ios::in|ios::binary);
 cout<<"Enter account type of your choice: "<<endl;
 cin>>choice_type;
 while(fin.read((char*)&a,sizeof(a)))
 {
  if(strcmp(a.return_type(),choice_type)==0)
   {
    a.show_account();
    flag=1;
   }
 }
 fin.close();
 if (flag==0)
 {
  cout<<"Sorry! Account not found! Please check again!"<<endl;
 }
 }
//search based on account number

void open_choice()
{
 account a;
 int choice_acno,flag=0;
 std::ifstream fin;
 fin.open("bank.txt",ios::in|ios::binary);
 cout<<"Enter account number of your choice: "<<endl;
 cin>>choice_acno;
 while(fin.read((char*)&a,sizeof(a)))
 {
  if(a.return_acno()==choice_acno)
   {
    a.show_account();
    flag=1;
   }
 }
 fin.close();
 if (flag==0)
 {
  cout<<"Sorry! Account not found! Please check again!"<<endl;
 }
 }

 void user_open_choice(char user[20])
{copy(user);
 account a;
 int choice_acno,flag=0;
 std::ifstream fin;
 fin.open("user.txt",ios::in|ios::binary);
 cout<<"Enter account number of your choice: "<<endl;
 cin>>choice_acno;
 while(fin.read((char*)&a,sizeof(a)))
 {
  if(a.return_acno()==choice_acno)
   {
    a.show_account();
    flag=1;
   }
 }
 fin.close();
 if (flag==0)
 {
  cout<<"Sorry! Account not found! Please check again!"<<endl;
 }
 }
//to append by adding new records

void append()
{
 int i,n;
 account a;
 std::ofstream fout;
 cout<<"How many accounts you want to add?"<<endl;
 cin>>n;
 fout.open("bank.txt",ios_base::app|ios::binary);

 for(i=0;i<n;i++)
 {
  a.create_account();
  fout.write((char*)&a,sizeof(a));
 }
fout.close();
}

void deposit(char user[20])
{copy(user);
 account a ;
 int accnum;
 int depamount;
 int flag=0;
 std::fstream f,t,temp;
 f.open("bank.txt",ios::out|ios::in|ios::binary);
 t.open("user.txt",ios::in|ios::binary);
 temp.open("temp.txt",ios::out|ios::binary);
 t.seekg(0);
 cout<<"Enter account number: "<<endl;
 cin>>accnum;
 while(t.read((char*)&a,sizeof(a)))
  {
    if(accnum==a.return_acno())
     {flag=1;
      cout<<"Enter the amount to be deposited: "<<endl;
      cin>>depamount;
      a.f_deposit(depamount);
      a.show_account(); 
      temp.write((char*)&a,sizeof(a));
     }

     else
     {
     	temp.write((char *)&a,sizeof(a));
     }
    
  }
 
   if (flag==0)

   {  cout<<"ERROR! ACCOUNT NOT FOUND."<<endl;}

f.close();
t.close();
temp.close();
remove("temp.txt");
rename("temp.txt","bank.txt");
}

void withdraw(char user[20])
{
 copy(user);
 account a;
 int accnum;
 int wamount;
 int flag=0;
 fstream f,t,temp;
 f.open("bank.txt",ios::in|ios::out|ios::binary);
 t.open("user.txt",ios::in|ios::binary);
 temp.open("temp.txt",ios::out|ios::binary);
 t.seekg(0);
 cout<<"Enter the Account Number: "<<endl;
 cin>>accnum;
 while(t.read((char*)&a,sizeof(a)))
 {
  if(accnum==a.return_acno())
   {flag=1;
    cout<<"Enter the amount to be withdrawn: "<<endl;
    cin>>wamount;
    if(strcmp(a.return_type(),"s")==0)
     {
      cout<<"Sorry! Cannot withdraw from savings amount."<<endl;
     }
    else if((a.return_deposit()-wamount)<10)
    {cout<<"Sorry! Enough money not available in your account."<<endl;}
    else
    {
     a.draw(wamount);
     temp.write((char*)&a,sizeof(a));

     flag=1;
     a.show_account();
    }
   }
  else
  	{temp.write((char *)&a,sizeof(a));}
  }
if (flag==0)
 cout<<"Error! Account not found!"<<endl;
f.close();
t.close();
temp.close();
remove("bank.txt");
rename("temp.txt","bank.txt");
}

float calculate(int P,int T)
{
 float tot=P*pow(1.15,T-1);
 return tot;
}

void loan(char user[20])
{copy(user);
 account a;
 char choice;
 int accnum,lamount,years,l=0;
 fstream f,t,t1;
 f.open("bank.txt",ios::out|ios::in|ios::binary);
 t.open("user.txt",ios::in|ios::binary);
 t1.open("temp.txt",ios::out|ios::binary);
 t.seekg(0);
 cout<<"Enter your Account Number: "<<endl;
 cin>>accnum;
 while(t.read((char*)&a,sizeof(a)))
 {  if(accnum==a.return_acno())
 	{
 	l=1;
    cout<<"Enter the amount you want a loan: "<<endl;
    cin>>lamount;
    cout<<"\n Enter tentative number of years after which you will be able to pay back the loan: "<<endl;
    cin>>years;
    cout<<"\n The interest rate is 15% compounded annually."<<endl;
    cout<<"\n Amount to be paid after the said time: "<<calculate(lamount,years);
    cout<<"\n Do you agree to this?(Y/N) \n";
    cin>>choice;
      if(choice=='Y'||choice=='y')
       {
			a.f_deposit(lamount);
			t1.write((char*)&a,sizeof(a));
			cout<<"The money has been deposited to your account.\n";
       }
      else
       {
			cout<<"You have entered \"No\".";
       }
  }
  else
  {
  	t1.write((char*)&a,sizeof(a));
  }
  
 }
if(l==0) cout<<"Error! Account not found \n";
f.close();
t.close();
t1.close();
remove("bank.txt");
rename("temp.txt","bank.txt");
}

 void Delete()
{
 ifstream f1("bank.txt",ios::binary);
 ofstream f2("temp.txt",ios::binary);
 account acc;
 int accnos, flag=0;
 f1.seekg(0);
 cout<<"Enter the account number of the account to be deleted:\n";
 cin>>accnos;
 while(  f1.read((char*)&acc,sizeof(acc)))
  {

   if(acc.return_acno()!=accnos)
   f2.write((char*)&acc,sizeof(acc));
   else 
   flag=1;
  }
  if(flag==0)
  cout<<"Account does not exist \n";
  else
  cout<<"Account with Account number "<<accnos<<" has been deleted \n";
 f1.close();
 f2.close();
 remove("bank.txt");
 rename("temp.txt","bank.txt");
}

int main()
{
 clrscr();
 Intro();
 create();
 int ch;
 int login;
 char choice;
 char user[20];

 do
 {
  cout<<"-----------------------------------------------------";
  cout<<"\n                LOGIN: \n\nPRESS: \n1 => user \n2 => banker\n\nEnter Mode:\n";
  cin>> login;
  cout<<"-----------------------------------------------------\n";
  if(login==1)
  { cout<<"ENTER USERNAME:\n";
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.getline(user,500);
 
    do
    {   
  copy(user);
  cout<<"------------------------------------------------------\n";
  cout<<"\n                      MENU: \n\n";
  cout<<"Enter 1-To search based on type in the bank."<<"\n";
  cout<<"Enter 2-To display the details of your account."<<"\n";
  cout<<"Enter 3-To search based on account number."<<"\n";
  cout<<"Enter 4-To append an account by adding new records."<<"\n";
  cout<<"Enter 5-To deposit amount in your account."<<"\n";
  cout<<"Enter 6-To withdraw amount from your account."<<"\n";
  cout<<"Enter 7-To take a loan from the bank."<<"\n\n";
  cout<<"Enter Choice: ";
  cin>>ch;
  cout<<"-------------------------------------------------------\n\n";
  switch(ch)
  {
   case 1:user_search_type(user);
	  break;
   case 2:user_display(user);
	  break;
   case 3:user_open_choice(user);
	  break;
   case 4:append();
	  break;
   case 5:deposit(user);
	  break;
   case 6:withdraw(user);
	  break;
   case 7:loan(user);
	  break;
   default: cout<<"\nSorry! Please enter correct choice.\n";
  }
 cout<<"\nDo you want to continue?(Y/N)"<<"\n";
 cin>>choice;
 }while(choice=='y'||choice=='Y');
 }
 else if(login==2)
 {cout<<"ENTER PASSWORD: ";
 int p;
 cin>>p;
 if(p==123)
 {
  do
  {
  cout<<"------------------------------------------------------------";
  cout<<"\n\n                 MENU: \n\n";
  cout<<"Enter 1-To search based on type in the bank."<<"\n";
  cout<<"Enter 2-To display the details of account."<<"\n";
  cout<<"Enter 3-To search based on account number."<<"\n";
  cout<<"Enter 4-To append an account by adding new records."<<"\n";
  cout<<"Enter 5-To delete the account based on account number."<<"\n";

  cout<<"Enter Choice:\n";
  cin>>ch;

  cout<<"\n\n------------------------------------------------------------\n\n";
  switch(ch)
  {
   case 1:search_type();
	  break;
   case 2:display();
	  break;
   case 3:open_choice();
	  break;
   case 4:append();
	  break;
   case 5:Delete();
          break;
   default: cout<<"\nSorry! Please enter correct choice.\n";
  }
 cout<<"\nDo you want to continue?(Y/N):  "<<"\n";
 cin>>choice;
 }while(choice=='y'||choice=='Y');
 }
 else
 {cout<<"\nwrong password \n";}
 }
 cout<<"\nDo you want to return to login menu?(Y/N):  "<<"\n";
 cin>>choice;
 }while(choice=='y'||choice=='Y');
cout<<"\n\n                     ******THANK YOU!******\n\n";
getch();
}