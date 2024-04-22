#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct product {
  int weight;
  double price;
};

struct movies_t {
  string title;
  int year;
} mine, yours;

void printmovie(movies_t movie);

int main() {
  product apple;
  product banana, melon;

  apple.weight = 100;
  apple.price = 0.99;
  cout << apple.weight << endl;

  string mystr;
  mine.title = "2001 A Space Odyssey";
  mine.year = 1968;

  cout << "Enter title: ";
  getline(cin, yours.title);
  cout << "Enter year: ";
  getline(cin, mystr);
  stringstream(mystr) >> yours.year;

  cout << "My favorite movie is:\n ";
  printmovie(mine);
  cout << "And yours is:\n ";
  printmovie(yours);
  return 0;
}

void printmovie(movies_t movie) {
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}