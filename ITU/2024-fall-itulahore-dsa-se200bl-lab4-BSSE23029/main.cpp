#include "functions.h"

// Main menu function
void menu() {
  int choice;

  // Loop until the user chooses to exit
  do {
    // Display menu options
    cout << "1. Input 3D array" << endl;
    cout << "2. Count sort 3D array" << endl;
    cout << "3. Radix sort 3D array" << endl;
    cout << "0. Exit" << endl;

    // Read user input
    cin >> choice;

    // Switch based on user choice
    switch (choice) {
    case 1: {
      // Create a 4x4 integer array
      MyArray<int> *array = MyArray<int>::create(2, 2, 2);

      // Prompt user to enter elements of 2D array
      cout << "Enter elements of 3D array: " << endl;
      
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 2; ++k){
          int a;
          cout << "Index[" << i << "]"
               << "[" << j << "]" << "[" << k << "]: ";
          cin >> a;
          array->setElement(a, i, j, k);
        }
      }}

      // Display original array
      cout << "\n------------------------------Original------------------------"
              "-----------\n";
      array->display();

      // Clean up memory
      delete array;
      break;
    }

    case 2: {
      // Create a 3x3 integer array
      MyArray<int> *array = MyArray<int>::create(2, 2, 2);

      // Prompt user to enter elements of 2D array
      cout << "Enter elements of 3D array: " << endl;
      
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 2; ++k){
          int a;
          cout << "Index[" << i << "]"
               << "[" << j << "]" << "[" << k << "]: ";
          cin >> a;
          array->setElement(a, i, j, k);
        }
      }}

      // Display original array
      cout << "\n------------------------------Original------------------------"
              "-----------\n";
      array->display();

      // Calculate inverse and display result
      array->countSort3D();

      cout << "\n------------------------------Result--------------------------"
              "---------\n";
      array->display();

      // Clean up memory
      delete array;
      break;
    }

    case 3: {
      // Create a 1D integer array
      MyArray<int> *array = MyArray<int>::create(2, 2, 2);

      cout << "Enter elements of 3D array: " << endl;
      
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 2; ++k){
          int a;
          cout << "Index[" << i << "]"
               << "[" << j << "]" << "[" << k << "]: ";
          cin >> a;
          array->setElement(a, i, j, k);
        }
      }}

      // Display original array
      cout << "\n------------------------------Original------------------------"
              "-----------\n";
      array->display();

      // Perform quick sort along x-axis
      array->radixSort3D();

      // Display sorted array
      cout << "\n------------------------------Result--------------------------"
              "---------\n";
      array->display();

      // Clean up memory
      delete array;
      break;
    }

    case 0: {
      // Exit message
      cout << "\n\nExiting......" << endl;
    }
    }

  } while (choice != 0);
}

// void countSort(int *arr, int n, int exp) {
//     int output[n];         // Output array
//     int count[10] = {}; // Count array  = 0

//     // Store count of occurrences in count[]
//     for (int i = 0; i < n; i++)
//       count[(arr[i] / exp) % 10]++;

//     // Change count[i] so that count[i] now contains actual position of this
//     // digit in output array
//     for (int i = 1; i < 10; i++)
//       count[i] += count[i - 1];

//     // Build the output array
//     for (int i = n - 1; i >= 0; i--) {
//       output[count[(arr[i] / exp) % 10] - 1] = arr[i];
//       count[(arr[i] / exp) % 10]--;
//     }

//     // Copy the output array to arr[], so that arr[] now contains sorted numbers
//     // according to current digit
//     for (int i = 0; i < n; i++)
//       arr[i] = output[i];
//   }

//   void radixSort1D(int *&array) {

//     int max = array[0];

//     for (int i = 1; i < 3; i++) {

//       if (array[i] > max) {

//         max = array[i];
//       }
//     }

//     for (int exp = 1; max / exp > 0; exp *= 10) {
//       countSort(array, 3, exp);
//     }
//   }



int main() {





  menu();


  // MyArray<int> array(3, 2, 2); // 3 columns, 2 rows, 2 layers

  //   array.setElement(22, 0, 0, 0);
  //   array.setElement(14, 1, 0, 0);
  //   array.setElement(57, 2, 0, 0);

  //   array.setElement(39, 0, 1, 0);
  //   array.setElement(423, 1, 1, 0);
  //   array.setElement(103, 2, 1, 0);

  //   array.setElement(55, 0, 0, 1);
  //   array.setElement(867, 1, 0, 1);
  //   array.setElement(22, 2, 0, 1);

  //   array.setElement(631, 0, 1, 1);
  //   array.setElement(70, 1, 1, 1);
  //   array.setElement(534, 2, 1, 1);

  //   array.radixSort3D();

  //   array.display();
 

  return 0;
}