#include <iostream>
#include <string>

using namespace std;

void passFailCalc (float mt1, float mt2, float fin)
{   
    float mtAverage = (mt1 + mt2) / 2;
    double totalAverage = (mt1 + mt2 + fin) / 3;

    if ( mtAverage < 30 )
    {
        cout << "You failed, MT average under 30!" << endl;
    }
    else if ( totalAverage < 40)
    {
        cout << "You failed, total average under 40!" << endl;
    }
    else 
    {
        cout << "You passed!" << endl;
    }
    cout << "Total Average: " << totalAverage << endl; 
}

int main()
{   
    float mt1, mt2, fin;
    cout << "Enter your mt1: ";
    cin >> mt1;
    cout << "Enter your mt2: ";
    cin >> mt2;
    cout << "Enter your final: ";
    cin >> fin;
    passFailCalc(mt1, mt2, fin);
}