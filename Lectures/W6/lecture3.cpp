#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct movies_t {
  string title;
  int year;
} films[3];

void printmovie(movies_t movie);

struct friends_t {
  string name;
  string email;
  movies_t favorite_movie;
} charlie, maria;

int main() {
  string mystr;
  int n;

  for (n = 0; n < 3; n++) {
    cout << "Enter title: ";
    getline(cin, films[n].title);
    cout << "Enter year: ";
    getline(cin, mystr);
    stringstream(mystr) >> films[n].year;
  }

  cout << "\nYou have entered these movies:\n";
  for (n = 0; n < 3; n++) {
    printmovie(films[n]);
  }

  movies_t amovice;
  movies_t *pmovie;

  pmovie = &amovice;
  pmovie->title = "2001 A Space Odyssey";
  pmovie->year = 1968;

  printmovie(amovice);

  friends_t *pfriends = &charlie;

  charlie.name = "Charlie";
  maria.favorite_movie.title = "Amelie";
  charlie.favorite_movie.year = 2001;
  pfriends->favorite_movie.year = 2000;

  cout << charlie.favorite_movie.year << endl;
  return 0;
}

void printmovie(movies_t movie) {
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}