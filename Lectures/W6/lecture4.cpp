#include <iostream>
#include <sstream>
#include <string>

using namespace std;

typedef char C;
typedef unsigned int WORD;
typedef char *pChar;
typedef char field[50];

struct movies_t {
  string title;
  int year;
};

typedef struct movies_t movies;

// using C = char;
// using WORD = unsigned int;
// using pChar = char *;
// using field = char [50];

union mytypes_t {
  char c;
  int i;
  float f;
} mytypes;

// Create an enum
enum colors_t { black, blue, green, cyan=100, red, purple, yellow, white };

enum months_t { january=1, february, march, april,
                may, june, july, august,
                september, october, november, december} y2k;

int main() {
  C mychar;
  WORD myword;
  pChar mystring;
  field name;

  // Use that enum
  colors_t mycolor;
  mycolor = white;

  if (mycolor == green) mycolor = red;

  cout << mycolor << endl;  

  months_t amonth;
  amonth = november;
  cout << amonth << endl;
  return 0;
}