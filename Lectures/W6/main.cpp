#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct student {
  string name;
  int mt1;
  int mt2;
  int final;
  double weightedAverage;
};

void printStudent(student st);

int main() {
  int n;

  cout << "Enter the number of students: ";
  string mystr;
  getline(cin, mystr);
  stringstream(mystr) >> n;

  student *students = new student[n];

  for (int i = 0; i < n; i++) {
    cout << "Enter the name of student " << i + 1 << ": ";
    getline(cin, students[i].name);
    cout << "Enter the first midterm grade: ";
    getline(cin, mystr);
    stringstream(mystr) >> students[i].mt1;
    cout << "Enter the second midterm grade: ";
    getline(cin, mystr);
    stringstream(mystr) >> students[i].mt2;
    cout << "Enter the final grade: ";
    getline(cin, mystr);
    stringstream(mystr) >> students[i].final;
  }

  student *studentP;
  for  (int j=0; j < n; j++) {
    studentP = &students[j];
    studentP->weightedAverage = (studentP->mt1 + studentP->mt2) * 0.3 + (studentP->final) * 0.4;   
  }

  for  (int j=0; j < n; j++) {
    printStudent(students[j]);
  }

  student *maxGradeStudentP;
  float maxGrade = 0;
  for  (int j=0; j < n; j++) {
    if (students[j].weightedAverage > maxGrade)
    {
      maxGradeStudentP = &students[j];
    }
  }

  cout << "Student with the max grade: " << endl;
  cout << "Name: " << maxGradeStudentP->name << " Weighted Grade: " << maxGradeStudentP->weightedAverage << endl;
  delete[] students;
  return 0;
}

void printStudent(student st) {
  cout << st.name << " " << st.mt1 << " " << st.mt2 << " " << st.final << " " << st.weightedAverage << endl;
}