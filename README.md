# BytE-Bank


## Abstract

A user-friendly E-banking application program. It dives into working of e-banking and data management systems. The application provides user with abilities to create, view, withdraw/deposit money and even take loans. The application provides login and systems at both the administrative and end-user level.

---

## About The Project

This project helps us to understand the working and management of a bank. The bank gives the user a choice to login to the bank as either an user (customer) or a banker (management) . If chosen to access the bank as a user, the bank allows the user to create an account. The project also helps the user to deposit or withdraw a certain amount of money from his/her own account. The user is also given the choice of taking a loan from the bank with a fixed rate of interest according to the money desired to borrow. If chosen to enter as a banker, the banker has access to all the existing accounts in the bank. The banker can also delete or create an account as requested by the user.

---

## Gathering Data
 The program starts with the bank asking to update the bank database. The bank holds the information regarding the account number, account holder, type of account, intial amount of deposit. The program flashes with an account created message as soon as it is done.

---

## User Login

As a user you can only access your accounts and you should not be allowed to see or modify another person's acount. The program asks for the username and shows only your accounts. All the modification in accounts are realtime updation in the database.

The user has been given the following options:
  - To search based on type in the bank.
  - To display the details of your account.
  - To search based on account number.
  - To append an account by adding new records.
  - To deposit amount in your account.
  - To withdraw amount from your account.
  - To take a loan from the bank. 
 

---

## Banker Login

The banker should be able to view all the accounts detail for administrative and book keeping purposes but should not be allowed to modify the account. The banker should not be allowed to withdraw/deposit money to any user's account. The banker login is protected with a password.

The banker has been given the following options:
- To search based on type in the bank.
- To display the details of account.
- To search based on account number.
- To append an account by adding new records.
- To delete the account based on account number.



---

## Local Installation:

Download the zip folder 
(Link: https://github.com/AnushaNathRoy/Youtube-Study-Buddy/tree/main/Youtube-Study-Buddy%20App)
Run on terminal:
```sh
g++ BANK.CPP -o bank;
./bank;
```

---
