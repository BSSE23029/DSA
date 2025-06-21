#include "MyArray.h"

using namespace std;

int main() {

  cout << "Enter the data type:\n1- for int\n2- for double\n3- for float\n4- "
          "for string\n0- Exit\n";
  cout << "\nEnter choice:";
  int dataType;
  cin >> dataType;

  cout << endl;

  switch (dataType) {
  case 1: {

    MyArray<int> Iarray;
    Iarray.menu();
    break;
  }
  case 2: {

    MyArray<double> Darray;
    Darray.menu();
    break;
  }
  case 3: {

    MyArray<float> Farray;
    Farray.menu();
    break;
  }
  case 4: {

    MyArray<string> Sarray;
    Sarray.menu();
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

  // MyArray<int> array(5);
  // array.insertAtIndex(10, 0);
  // array.insertAtIndex(5, 1);
  // array.insertAtIndex(1, 2);
  // array.insertAtIndex(7, 3);
  // array.insertAtIndex(9, 4);

  // array.removeAtIndex(2);

  // array.menuDisplay();

  return 0;
}
