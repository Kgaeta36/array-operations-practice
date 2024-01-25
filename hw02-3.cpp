#include <iostream>
#include <fstream>
using namespace std;
/**
Title : Hw02-3.cpp
Abstract : This program will find a customer's information from a bank data.
Author: Kimberly Gaeta
Email: Kgaeta@csumb.edu
Date: 2/06/2023
Estimate: 4 hours
  **/
const int MAX = 30;
struct Person{
  string name;
  int id;
  double balance;
};
struct Bank{
  Person account[MAX];
};
void printLine();
void getInfo(Person account[], ifstream &fin, int &accountCount);
void findAccount (Person account[], string findName, int accountCount);
void printAccount (Person account[], int x);
int main() {
  ifstream fin;
  string filename;
  string findName;
  int accountCount = 0;
  char cont;
  Bank b1;
  cout << "Enter an input file: ";
    cin >> filename;
  fin.open(filename);
  if (fin.fail()){
    cerr << "Couldn't open file.";
      return 0;
  }
  getInfo (b1.account, fin, accountCount);
  do {
    printLine();
    cout << "Record Finder - Enter a customer name : ";
    cin >> findName;
    printLine();
    // main functions
    
  // printAccount (b1.account, accountCount);
   findAccount (b1.account, findName, accountCount);
    printLine();
    
    
    cout << "\nDo you want to continue? (y/n) ";
    cin >> cont;
    cout << "\n";
  } while (cont == 'y');
  cout << "BYE!";
}
void printLine() {
  for (int i = 0; i < 50; i++) {
    cout << "-";
  }
  cout << "\n";
}
void getInfo(Person account[], ifstream &fin, int &accountCount){
  string nameInput;
  int idInput;
  double balanceInput;
  for (int i = 0; i < MAX; i++){
    fin >> nameInput;
    if (nameInput == "STOP"){
      break;
    } else {
      account[i].name = nameInput;
      fin >> idInput >> balanceInput;
      account[i].id = idInput;
      account[i].balance = balanceInput;
      accountCount++;
    }
  }
}
// For testing!!
void printAccount (Person account[], int x){
  for (int i = 0; i < x; i++){
    cout << account[i].name << " " << account[i].id << " " << account[i].balance << "\n";
  }
}

void findAccount (Person account[], string findName, int accountCount){
  bool found = false;
  for (int i = 0; i < accountCount; i++){
    //cerr << i << " " << account[i].name << "\n";
    if (findName == account[i].name){
     cout << "Name: " << account[i].name << "\nAccount: " 
       << account[i].id << "\nBalance: " << account[i].balance 
       << "\n\n"; 
      found = true;
    }
  }
  if (found == false){
    cout << "Fail. " << findName << " Doesn't exist.";
    cout << "\n";
  }
 
}
//cant find the peeps???? everything else works :)