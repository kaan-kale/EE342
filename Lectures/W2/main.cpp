#include <iostream>
#include <string>

using namespace std;

int getPopulation1 (void)
{
    int pop1;
    cout << "Enter population of the village 1: ";
    cin >> pop1;
    return pop1; 

}

int getPopulation2 (void)
{   
    int pop2;
    cout << "Enter population of the village 2: ";
    cin >> pop2;
    return pop2;
}

int main()
{   
    int pop1, pop2;
    pop1 = getPopulation1();
    pop2 = getPopulation2();



    if (pop2 > pop1)
    {
        cout << "Population of the second village is higher!!!";
        return 1;
    }

    int incr1, incr2;
    cout << "Enter population increment of the village 1: ";
    cin >> incr1;
    cout << "Enter population increment of the village 2: ";
    cin >> incr2;

    if (incr1 >= incr2)
    {
        cout << "Village 2 cannot catch the village 1";
        return 2;
    }


    int i = 0;
    while (pop1 > pop2)
    {
        pop1 += incr1;
        pop2 += incr2;
        ++i;
    }

    cout << i << " years have passed!";
    return 0;
}