#include <iostream>
#include <new>

using namespace std;

template <class SomeType>
void printarray ( SomeType arg[], int length)
{
  for  (int n=0; n<length; ++n)
  {
    cout << arg[n] << ' ';
  }
  cout << '\n';
}

int main ()
{   
    int numProducts;

    cout << "Number of products: ";
    cin >> numProducts;

    int *quantity;
    double *price;
    quantity = new (nothrow) int[numProducts];
    price = new (nothrow) double[numProducts];

    int n;

    if (quantity == nullptr || price == nullptr)
    {
        cout << "Error: memory could not be allocated";
        return 1;
    }
    else  
    {
        for (n=0; n<numProducts; n++)
        {
        cout << "Enter the quantity of Product " << n+1 << ": ";
        cin >> quantity[n];

        cout << "Enter the price of Product " << n+1 << ": ";
        cin >> price[n];
        }
        cout << "Quantity:" << endl;
        printarray(quantity, numProducts);

        cout << "Price:" << endl;
        printarray(price, numProducts);

        delete[] quantity;
        delete[] price;
    }
    return 0;
}