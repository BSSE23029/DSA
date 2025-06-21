#include "functions.h"
#include <iostream>

using namespace std;

// Resource(string firstName,  string lastName,  string date_of_birth,  string
// CNIC,  string phoneNumber,  string address) {
//     this->firstName = firstName;
//     this->lastName = lastName;
//     this->date_of_birth = date_of_birth;
//     this->CNIC = CNIC;
//     this->phoneNumber = phoneNumber;
//     this->address = address;
//   }

int main() {
  cout << endl << endl;
  // Graph graph;
  int choice;

  Resource p1("hamid", "raza", "24", "35", "1234", "street");
  Resource p2("ahmad", "raza", "24", "35", "1234", "street");
  Resource p3("ali", "raza", "24", "35", "1234", "street");

  //   cout << "2. Get data of the root\n";
  //   cout << "3. Get a child of a node\n";
  //   cout << "4. Get tree height\n";
  //   cout << "5. Get degree of tree\n";
  //   cout << "6. Search for a node\n";
  //   cout << "7. Update a node value\n";
  //   cout << "8. Get size of the tree\n";
  //   cout << "0. Exit\n";
  //   cout << "----------------\n";
  //   cout << "Enter your choice: ";

  Tree t(p1);

  t.insert(p2);
  t.insert(p3);

  while (choice != 0) {
    cout << "\n----- Menu -----\n";
    cout << "1. Insert Resource\n";
    cout << "2. Make Vanact\n";
    cout << "3. Apply Leave\n";
    cout << "4. Has child applied leave\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      t.insert(p2);
      t.insert(p3);
      // t.display();
      break;
    }
    case 2: {
      t.makeVacant(p2);
      t.updatePeriod(p2, 1000);

      break;
    }
    case 3: {
      t.applyLeave(p2);
      break;
    }
    case 4: {
    //   if (t.hasChildAppliedLeave(p1) == true) {
    //     cout << "Yes";
    //   } else {
    //     cout << "NO";
    //   }

      break;
    }
    case 0: {
      // Exit
      cout << "Exiting...\n";
      break;
    }
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  }

  cout << endl << endl;
  return 0;
}
