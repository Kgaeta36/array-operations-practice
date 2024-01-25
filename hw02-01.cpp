#include <iostream>
using namespace std;
/**
Title: Hw02-1.cpp
Abstract: This program will let the user conduct three operations to an array;
delete the max, append a number, and reverse the array. Author: KImberly Gaeta
Email: Kgaeta@csumb.edu
Date: 02/03/2023
Estimate: 4 hours
  **/

void printArray(int a[]);
void deleteMax(int a[]);
void appendNum(int a[]);
void reverseArray(int a[]);
const int MAX = 10;
int main() {
  int bruh[MAX] = {10, 20, 30, 40, 50, 15, 25, 35, 45, 55};
  int choice;
  char cont;
  cout << "Array Values: ";
  printArray(bruh);
  cout << "This is a list of operations\n"
       << "\t1. Delete the max\n"
       << "\t2. Append a number\n"
       << "\t3. Reverse array\n";
  do {
    cout << "\nEnter your option: ";
    cin >> choice;
    if (choice == 1) {
      deleteMax(bruh);
    } else if (choice == 2) {
      appendNum(bruh);
    } else if (choice == 3) {
      reverseArray(bruh);
    }
    cout << "Continue? (Y/N) : ";
    cin >> cont;
  } while (cont == 'Y');
}
// works! <3
void printArray(int a[]) { // Works!
  for (int i = 0; i < MAX; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
// finding highest works! take out & shift.
// Works B)
void deleteMax(int a[]) {
  int high = 0;
  for (int i = 0; i < MAX; i++) {
    if (a[i] > high) {
      high = a[i];
    }
  }
  for (int i = 0; i < MAX; i++) {
    if (a[i] == high) {
      for (int k = i; k < MAX; k++) {
        a[k] = a[k + 1];
      }
      break;
    }
  }
  cout << "New Array Values: ";
  printArray(a);
}
// adding works, full message dont :(
// WORKS!!!!!
void appendNum(int a[]) {
  int check = 0, append;
  if (a[MAX - 1] != check) {
    cout << "Array is full and can't append anymore.\n"
         << "Array Values: ";
    printArray(a);
  } else {
    for (int i = 0; i < MAX; i++) {
      if (a[i] == check) {
        cout << "Enter the number to append: ";
        cin >> append;
        a[i] = append;
        cout << "New Array Values: ";
        printArray(a);
        break;
      }
    }
  }
}
// filled index works, now switch
//Works >:(
void reverseArray(int a[]) {
  int filledCount = -1, swapping = 0, temp1 = 0, temp2 = 0;
  for (int i = 0; i < MAX; i++) {
    if (a[i] != 0) {
      filledCount++;
    }
  }
  //(testing) cout << filledCount << " " << a[filledCount];
 while (filledCount > swapping){
    temp1 = a[filledCount];
    temp2 = a[swapping];
    a[swapping] = temp1;
    a[filledCount] = temp2;
   swapping++;
   filledCount--;
   }

  cout << "\nNew Array Values: ";
  printArray(a);
}