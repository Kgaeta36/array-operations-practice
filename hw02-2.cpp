#include <fstream>
#include <iostream>
using namespace std;
/**
Title: Hw02-2.cpp
Abstract: This program will determine the average of quiz scores of all students
in a coursde.
Author: Kimberly Gaeta
Email: Kgaeta@csumb.edu
Date: 2/05/2023
Estimate: 4 hours
  **/
const int MAX = 30;

struct Student {
  string name;
  int id;
  double quiz1;
  double quiz2;
  double quiz3;
  double quiz4;
  double quiz5;
  double average;
};
struct Course {
  Student roster[MAX];
};
void printLine();
void getInfo(Student roster[], ifstream &fin, int &x);
void testprint(Student roster[], int x);
void getAverage (Student roster[], int x);
int main() {
  string filename;
  ifstream fin;
  int studentCount = 0;
  Course c1;
  cout << "Enter an input file: ";
  cin >> filename;
  fin.open(filename);
  // check for fail
  if (fin.fail()) {
    cerr << "Couldn't open file\n";
    return 0;
    }
  //  start printing out
  printLine();
  cout << "Course Report: Quiz Average\n";
  printLine();
  getInfo(c1.roster, fin, studentCount);
  getAverage(c1.roster, studentCount);
  testprint(c1.roster, studentCount);
  printLine();

}
void printLine() {
  for (int i = 0; i < 50; i++) {
    cout << "-";
  }
  cout << "\n";
}
// prints all quiz scores not average rn
void testprint(Student roster[], int x) {
  for (int i = 0; i < x; i++) {
    cout << roster[i].name << " (" << roster[i].id << ") : " 
      << roster[i].average << "\n";
  }
}

void getInfo(Student roster[], ifstream &fin, int &studentCount) {
  string nameInput;
  int idInput;
  double q1, q2, q3, q4, q5;
  for (int i = 0; i < MAX; i++) {
    fin >> nameInput;
   // cerr << nameInput << " " << i << "\n";
    if (nameInput == "STOP") {
     break;
    } else {
     roster[i].name = nameInput;
      fin >> idInput >> q1 >> q2 >> q3 >> q4 >> q5;
      roster[i].id = idInput;
      roster[i].quiz1 = q1;
      roster[i].quiz2 = q2;
      roster[i].quiz3 = q3;
      roster[i].quiz4 = q4;
      roster[i].quiz5 = q5;
      studentCount++;
    }
  }
}
void getAverage (Student roster[], int studentCount){
  double average;
  for (int i = 0; i < studentCount; i++){
    average = (roster[i].quiz1 + roster[i].quiz2 + roster[i].quiz3 +
      roster[i].quiz4 + roster[i].quiz5)/5;
    roster[i].average = average;
  }
}