#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<ctype.h>
#include<iomanip.h>
#include<stdio.h>
#include<math.h>

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
  cout<<"\n Enter the account number:";
  cin>>acno;
  cout<<"Enter the name of the account holder: ";
  gets(username);
  cout<<"Enter the type of the account (C/S/FD): ";
  gets(type);
  cout<<"Enter the initial amout of deposit: ";
  cin>>deposit;
  cout<<"YOUR ACCOUNT HAS BEEN CREATED."<<"\n";
 }

void account::show_account()
{
 cout<<"\n Account Number: "<<acno;
 cout<<"\n Name of the Account Holder: ";
 cout<<username;
 cout<<"\n Type of Account: "<<type;
 cout<<"\n Balance Account: "<<deposit;
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
   cout<<"WELCOME TO _ BANK"<<endl;
 }

//create a new file

void create()
{
 int i,n;
 account a;
 ofstream fout;
 cout<<"How many records you want?";
 cin>>n;
 fout.open("bank.dat",ios::out|ios::binary);

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
 fin.open("bank.dat",ios::in|ios::binary);
 fin.seekg(0);
 while(fin.read((char*)&a,sizeof(a)))
 {
  a.show_account();
 }
fin.close();
}
void copy(char user[20])
{fstream f,t;
 account a;
 f.open("bank.dat",ios::in|ios::binary);
 t.open("user.dat",ios::out|ios::binary);
 f.seekg(0);
 while(f.read((char*)&a,sizeof(a)))
 {if (strcmpi(user,a.return_username())==0)
   {t.write((char*)&a,sizeof(a));}
 }
f.close();
t.close();
}
void user_display(char user[20])
{copy(user);
 account a;
 ifstream fin;
 fin.open("user.dat",ios::in|ios::binary);
 fin.seekg(0);
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
 ifstream fin;
 fin.open("bank.dat",ios::in|ios::binary);
 cout<<"Enter account type of your choice: ";
 cin>>choice_type;
 while(fin.read((char*)&a,sizeof(a)))
 {
  if(strcmpi(a.return_type(),choice_type)==0)
   {
    a.show_account();
    flag=1;
   }
 }
 fin.close();
 if (flag==0)
 {
  cout<<"Sorry! Account not found! Please check again!";
 }
 }

 void user_search_type(char user[20])
{copy(user);
 account a;
 char choice_type[3],flag=0;
 ifstream fin;
 fin.open("user.dat",ios::in|ios::binary);
 cout<<"Enter account type of your choice: ";
 cin>>choice_type;
 while(fin.read((char*)&a,sizeof(a)))
 {
  if(strcmpi(a.return_type(),choice_type)==0)
   {
    a.show_account();
    flag=1;
   }
 }
 fin.close();
 if (flag==0)
 {
  cout<<"Sorry! Account not found! Please check again!";
 }
 }
//search based on account number

void open_choice()
{
 account a;
 int choice_acno,flag=0;
 ifstream fin;
 fin.open("bank.dat",ios::in|ios::binary);
 cout<<"Enter account number of your choice: ";
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
  cout<<"Sorry! Account not found! Please check again!";
 }
 }

 void user_open_choice(char user[20])
{copy(user);
 account a;
 int choice_acno,flag=0;
 ifstream fin;
 fin.open("user.dat",ios::in|ios::binary);
 cout<<"Enter account number of your choice: ";
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
  cout<<"Sorry! Account not found! Please check again!";
 }
 }
//to append by adding new records

void append()
{
 int i,n;
 account a;
 ofstream fout;
 cout<<"How many accounts you want to add?";
 cin>>n;
 fout. open("bank.dat",ios::ate|ios::binary);

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
 fstream f,t;
 f.open("bank.dat",ios::out|ios::in|ios::binary);
 t.open("user.dat",ios::in|ios::binary);
 f.seekg(0);
 cout<<"Enter account number: ";
 cin>>accnum;
 while(t.read((char*)&a,sizeof(a)))
  {
    if(accnum==a.return_acno())
     {flag=1;
       f.seekg(0);
    while (f.read((char*)&a,sizeof(a)))
    {if(accnum==a.return_acno())
    {
      cout<<"Enter the amount to be deposited: ";
      cin>>depamount;
      a.f_deposit(depamount);
      f.seekp(f.tellg()-sizeof(a));
      f.write((char*)&a,sizeof(a));
       a.show_account();
     }
  }
  }
  }
   if (flag==0)

   {  cout<<"ERROR! ACCOUNT NOT FOUND.";}

f.close();
}

void withdraw(char user[20])
{
 copy(user);
 account a;
 int accnum;
 int wamount;
 int flag=0;
 fstream f,t;
 f.open("bank.dat",ios::out|ios::in|ios::binary);
 t.open("user.dat",ios::in|ios::binary);
 t.seekg(0);
 cout<<"Enter the Account Number: ";
 cin>>accnum;
 while(t.read((char*)&a,sizeof(a)))
 {
  if(accnum==a.return_acno())
   {flag=1;
    f.seekg(0);
    while (f.read((char*)&a,sizeof(a)))
    {if(accnum==a.return_acno())
    {
    cout<<"Enter the amount to be withdrawn: ";
    cin>>wamount;
    if(strcmpi(a.return_type(),"s")==0)
     {
      cout<<"Sorry! Cannot withdraw from savings amount.";
     }
    else if((a.return_deposit()-wamount)<10)
    {cout<<"Sorry! Enough money not available in your account.";}
  else
    {
     a.draw(wamount);
     f.seekp(f.tellg()-sizeof(a));
     f.write((char*)&a,sizeof(a));
     flag=1;
     a.show_account();
    }
   }
  }
  }
  }
if (flag==0)
 cout<<"Error! Account not found!";
f.close();
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
 int accnum,lamount,years;
 fstream f,t;
 f.open("bank.dat",ios::out|ios::in|ios::binary);
 t.open("user.dat",ios::in|ios::binary);
 t.seekg(0);
 cout<<"Enter your Account Number: ";
 cin>>accnum;
 while(t.read((char*)&a,sizeof(a)))
 {  if(accnum==a.return_acno())

   { f.seekg(0);
     while (f.read((char*)&a,sizeof(a)))
    { if(accnum==a.return_acno())
       {f.seekp(f.tellg()-sizeof(a));
    cout<<"Enter the amount you want a loan: ";
    cin>>lamount;
    cout<<"\n Enter tentative number of years after which you will be able to pay back the loan: ";
    cin>>years;
    cout<<"\n The interest rate is 15% compounded annually.";
    cout<<"\n Amount to be paid after the said time: "<<calculate(lamount,years);
    cout<<"\n Do you agree to this?(Y\N)";
    cin>>choice;
      if(choice=='Y'||choice=='y')
       {
	a.f_deposit(lamount);
	f.write((char*)&a,sizeof(a));
	cout<<"The money has been deposited to your account.";
       }
      else
       {
	cout<<"Error! Account not found!";
       }
  }
 }
 }

 }
f.close();
}

 void Delete()
{
 ifstream f1("bank.dat",ios::binary);
 ofstream f2("temp.dat",ios::binary);
 account acc;
 int accnos, flag=0;
 f1.seekg(0);
 cout<<"Enter the account number of the account to be deleted:";
 cin>>accnos;
 while(  f1.read((char*)&acc,sizeof(acc)))
  {

   if(acc.return_acno()!=accnos)
   f2.write((char*)&acc,sizeof(acc));
   else 
   flag=1;
  }
  if(flag==0)
  cout<<"Account does not exist";
  else
  cout<<"Account with Account number "<<accnos<<" has been deleted";
 f1.close();
 f2.close();
 remove("bank.dat");
 rename("temp.dat","bank.dat");
}

void main()
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
  cout<<"LOGIN: 1.user 2.banker\n";
  cin>> login;
  if(login==1)
  { cout<<"ENTER USERNAME:";
    gets(user);
    copy(user);
    do
    {
  cout<<"\n MENU: ";
  cout<<"Enter 1-To search based on type in the bank."<<"\n";
  cout<<"Enter 2-To display the details of your account."<<"\n";
  cout<<"Enter 3-To search based on account number."<<"\n";
  cout<<"Enter 4-To append an account by adding new records."<<"\n";
  cout<<"Enter 5-To deposit amount in your account."<<"\n";
  cout<<"Enter 6-To withdraw amount from your account."<<"\n";
  cout<<"Enter 7-To take a loan from the bank."<<"\n";
  cout<<"Enter Choice: ";
  cin>>ch;
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
   default: cout<<"Sorry! Please enter correct choice.";
  }
 cout<<"\n Do you want to continue?(Y/N)"<<"\n";
 cin>>choice;
 }while(choice=='y'||choice=='Y');
 }
 else if(login==2)
 {cout<<"ENTER PASSWORD:";
 int p;
 cin>>p;
 if(p==123)
 {
  do
  {cout<<"\n MENU: ";
  cout<<"Enter 1-To search based on type in the bank."<<"\n";
  cout<<"Enter 2-To display the details of your account."<<"\n";
  cout<<"Enter 3-To search based on account number."<<"\n";
  cout<<"Enter 4-To append an account by adding new records."<<"\n";
  cout<<"Enter 5-To delete the account based on account number."<<"\n";

  cout<<"Enter Choice: ";
  cin>>ch;
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
   default: cout<<"Sorry! Please enter correct choice.";
  }
 cout<<"\n Do you want to continue?(Y/N)"<<"\n";
 cin>>choice;
 }while(choice=='y'||choice=='Y');
 }
 else
 {cout<<"wrong password \n";}
 }
 cout<<"\n Do you want to return to login menu?(Y/N)"<<"\n";
 cin>>choice;
 }while(choice=='y'||choice=='Y');
cout<<"******THANK YOU!******";
getch();
}









