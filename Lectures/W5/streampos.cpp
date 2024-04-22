#include <iostream>
#include <fstream>

using namespace std;

int main () {
    streampos begin, end;
    ifstream myfile ("example.txt", ios::binary);
    begin = myfile.tellg();
    myfile.seekg (0, ios::end);

    end = myfile.tellg();
    myfile.close();
    cout << "size is: " << (end-begin) << " bytes.\n";
}

// q: What does seekg do?
// a: It moves the file pointer to the specified position.
// q: Can you explain the parameters?
// a: The first parameter is the offset from the specified position, and the second parameter is the position to move to.
// q: How does offset work, and what are the possible values for position?
// a: The offset can be positive or negative, and the position can be ios::beg, ios::cur, or ios::end.
// q: What does ios::beg mean?
// a: It means the beginning of the file.
// q: What does ios::cur mean?
// a: It means the current position of the file pointer.
// q: What does ios::end mean?
// a: It means the end of the file.
// q: How to change the current position of the file pointer?
// a: You can use the seekg method.
// q: So use seekg to move the file pointer to the middle of the file.
// a: myfile.seekg (0, ios::end);   
// q: But this moves the file pointer to the end of the file. How to move it to the middle?
// a: myfile.seekg (0, ios::end); myfile.seekg (0, ios::beg); myfile.seekg (0, ios::cur);
// q: What does tellg do?
// a: It returns the current position of the file pointer.