#include "functions.h"

using namespace std;

int main() {

  cout << "Enter the data type:\n1- for int\n2- for double\n3- for float\n4- "
          "for string\n0- Exit\n";
  cout << "\nEnter choice:";
  int dataType;
  cin >> dataType;

  int dimentions;

  do {

    cout << "\nEnter the desired dimentions of Array\n 1 for 1D\n 2 for "
            "2D\n 0 for Exit\nEnter your choice:";
    cin >> dimentions;

    cout << endl;

    if (dimentions == 1) {

      switch (dataType) {
      case 1: {

        MyArray<int> Iarray(true);
        Iarray.menu1D();
        break;
      }
      case 2: {

        MyArray<double> Darray(true);
        Darray.menu1D();
        break;
      }
      case 3: {

        MyArray<float> Farray(true);
        Farray.menu1D();
        break;
      }
      case 4: {

        MyArray<string> Sarray(true);
        Sarray.menu1D();
        break;
      }

      case 0: {
        cout << "Exiting...." << endl;
        return 0;
      }

      default:
        cout << "Invalid data type" << endl;
        return 1;
      }
    }

    else if (dimentions == 2) {

      switch (dataType) {
      case 1: {

        MyArray<int> Iarray;
        Iarray.menu2D();
        break;
      }
      case 2: {

        MyArray<double> Darray;
        Darray.menu2D();
        break;
      }
      case 3: {

        MyArray<float> Farray;
        Farray.menu2D();
        break;
      }
      case 4: {

        MyArray<string> Sarray;
        Sarray.menu2D();
        break;
      }

      case 0: {
        cout << "Exiting...." << endl;
        return 0;
      }

      default:
        cout << "Invalid data type" << endl;
        return 1;
      }

    }

    else {
      cout << "Invalid dimentions" << endl;
    }
  } while (dimentions == 1 || dimentions == 0);

  return 0;
}
