#include "functions.h"

template <typename T>
MyArray<T>::MyArray(int d0, int d1, int d2) : d0(d0), d1(d1), d2(d2) {

  // If this is a 3D array, allocate memory for it
  if (d2 != 0) {
    // Set the other two pointers to nullptr
    arr1D = nullptr;
    arr2D = nullptr;

    // Allocate the memory for the 3D array
    arr3D = new T **[d0];

    // Loop over the first dimension
    for (int i = 0; i < d0; i++) {

      // Allocate memory for the second dimension
      arr3D[i] = new T *[d1];

      // Loop over the second dimension
      for (int j = 0; j < d1; j++) {

        // Allocate memory for the third dimension
        arr3D[i][j] = new T[d2];

        // Print a message to check that the memory is being allocated
        // cout << "declared " << i << j << endl;
      }
    }
  }

  // If this is a 2D array, allocate memory for it
  else if (d1 != 0) {
    // Set the other two pointers to nullptr
    arr1D = nullptr;
    arr3D = nullptr;

    // Allocate memory for the 2D array
    arr2D = new T *[d0];

    // Loop over the first dimension
    for (int i = 0; i < d0; i++) {

      // Allocate memory for the second dimension
      arr2D[i] = new T[d1];

      // Print a message to check that the memory is being allocated
      // cout << "declared " << d0 << d1 << endl;
    }
  }

  // If this is a 1D array, allocate memory for it
  else if (d0 != 0) {
    // Set the other two pointers to nullptr
    arr2D = nullptr;
    arr3D = nullptr;

    // Allocate memory for the 1D array
    arr1D = new T[d0];

    // Print a message to check that the memory is being allocated
    // cout << "declared " << d0 << endl;
  }

  // If the dimensions are invalid, print an error message
  else {
    cout << "Error: Invalid dimensions" << endl;
    return;
  }
}

template <typename T> MyArray<T>::~MyArray() {

  // If this is a 3D array, free the memory
  if (d2 != 0) {

    // Loop over the first dimension
    for (int i = 0; i < d0; i++) {

      // Loop over the second dimension
      for (int j = 0; j < d1; j++) {

        // Free the memory for the third dimension
        delete[] arr3D[i][j];
      }

      // Free the memory for the second dimension
      delete[] arr3D[i];
    }

    // Free the memory for the first dimension
    delete[] arr3D;
  }

  // If this is a 2D array, free the memory
  else if (d1 != 0) {

    
    // If this is a 2D array, free the memory
    // Loop over the first dimension
    for (int i = 0; i < d0; i++) {

      // Free the memory for the second dimension
      delete[] arr2D[i];
    }

    // Free the memory for the first dimension
    delete[] arr2D;
  }

  // If this is a 1D array, free the memory
  else if (d0 != 0) {

    // Free the memory for the first dimension
    delete[] arr1D;
  }

  // If the array doesn't exist, nothing is needed but for saftey
  else {
    arr1D = nullptr;
    arr2D = nullptr;
    arr3D = nullptr;
    delete [] arr1D;
    delete [] arr2D;
    delete [] arr3D;
  }
}

template <typename T> MyArray<T>::MyArray(const MyArray &other) {

  // Copy the dimensions from the other array
  d0 = other.d0;
  d1 = other.d1;
  d2 = other.d2;

  // If this is a 3D array, copy the elements from the other array
  if (d2) {

    // Loop over the first dimension
    for (int i = 0; i < d0; i++) {

      // Loop over the second dimension
      for (int j = 0; j < d1; j++) {

        // Loop over the third dimension
        for (int k = 0; k < d2; k++) {

          // Copy the element from the other array to this array
          arr3D[i][j][k] = other.arr3D[i][j][k];
        }
      }
    }
  }

  // If this is a 2D array, copy the elements from the other array
  else if (d1) {

    // Loop over the first dimension
    for (int i = 0; i < d0; i++) {

      // Loop over the second dimension
      for (int j = 0; j < d1; j++) {

        // Copy the element from the other array to this array
        arr2D[i][j] = other.arr2D[i][j];
      }
    }
  }

  // If this is a 1D array, copy the elements from the other array
  else if (d0) {

    // Loop over the first dimension
    for (int i = 0; i < d0; i++) {

      // Copy the element from the other array to this array
      arr1D[i] = other.arr1D[i];
    }
  }

  // If the dimensions are invalid, print an error message and return
  else {
    cout << "Error: Invalid dimensions" << endl;
    return;
  }
}

template <typename T> int MyArray<T>::getDimensions() const {
  return (d2 > 0) ? 3 : (d1 > 0) ? 2 : 1;
}

template <typename T>
void MyArray<T>::setElement(double value, int index0, int index1, int index2) {

  if (d2 != 0) {
    if (index0 >= 0 && index0 <= d0 && index1 >= 0 && index1 <= d1 &&
        index2 >= 0 && index2 <= d2) 
        {
            // itterating after boundchecking
      arr3D[index0][index1][index2] = value;
    } 
    else 
    {
      cout << "Indices out of bounds." << endl;
    }
  } 
  else if (d1 != 0) 
  {
    if (index0 >= 0 && index0 <= d0 && index1 >= 0 && index1 <= d1) 
    {
      // cout << "\n 2d case \n";

      // itterating after boundchecking
      arr2D[index0][index1] = value;

      // cout << "\n at index " << index0 << index1 << endl;
    } 
    else 
    {
      cout << "Indices out of bounds." << endl;
    }
  } 
  else if (d0 != 0) 
  {
    if (index0 >= 0 && index0 <= d0) 
    {
      // cout << "\n 1d case \n";

      // itterating after boundchecking
      arr1D[index0] = value;
    } 
    else 
    {
      cout << "Index out of bounds." << endl;
    }
  } 
  else 
  {
    cout << "Error: Invalid dimensions" << endl;
  }
}

template <typename T>
T MyArray<T>::getElement(int index0, int index1, int index2) const {
  if (d2 != 0) {
    if (index0 >= 0 && index0 < d0 && index1 >= 0 && index1 < d1 &&
        index2 >= 0 && index2 < d2) 
        {
            // itterating after boundchecking 
      return arr3D[index0][index1][index2];
    } 
    else 
    {
      cout << "Indices out of bounds." << endl;
      return T{};
    }
  } 
  else if (d1 != 0) 
  {
    if (index0 >= 0 && index0 < d0 && index1 >= 0 && index1 < d1) 
    {
        // itterating after boundchecking
      return arr2D[index0][index1];
    } 
    else 
    {
      cout << "Indices out of bounds." << endl;
      return T{};
    }
  } 
  else if (d0 != 0) 
  {
    if (index0 >= 0 && index0 < d0) 
    {
        // itterating after boundchecking
      return arr1D[index0];
    } 
    else 
    {
      cout << "Index out of bounds." << endl;
      return T{};
    }
  }
  else 
  {
    cout << "Error: Invalid dimensions" << endl;
    return T{};
  }
}

template <typename T> void MyArray<T>::display() const {
  cout << endl << endl;
  if (d2 > 0) 
  {
    for (int i = 0; i < d0; ++i) 
    {
      for (int j = 0; j < d1; ++j) 
      {
        for (int k = 0; k < d2; ++k) 
        {
          cout << setw(5) << arr3D[i][j][k] << " "; // setw() -> set width
        }
        cout << endl;
      }
      cout << endl;
    }
  } 
  else if (d1 > 0) 
  {
    for (int i = 0; i < d0; ++i) 
    {
      for (int j = 0; j < d1; ++j) 
      {
        cout << setw(5) << arr2D[i][j] << " ";
      }
      cout << endl;
    }
  } 
  else 
  {
    for (int i = 0; i < d0; ++i) 
    {
      cout << setw(5) << arr1D[i] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;
}

template <typename T> MyArray<T> *MyArray<T>::sum(const MyArray &other) {
  if (d2 != 0) 
  { // 3D Array
    if (d0 != other.d0 || d1 != other.d1 || d2 != other.d2) 
    {
      cout << "Dimension mismatch for sum operation." <<  endl;
      return nullptr;
    }

    MyArray *result = new MyArray(d0, d1, d2);
    for (int i = 0; i < d0; ++i) 
    {
      for (int j = 0; j < d1; ++j) 
      {
        for (int k = 0; k < d2; ++k) 
        {
            // summing the indexes and saving into a new matrix
          result->setElement(
              this->getElement(i, j, k) + other.getElement(i, j, k), i, j, k);
        }
      }
    }
    return result;
  }
  else if (d1 != 0) 
  { // 2D Array
    if (d0 != other.d0 || d1 != other.d1) 
    {
      cout << "Dimension mismatch for sum operation." << endl;
      return nullptr;
    }

    MyArray *result = new MyArray(d0, d1);
    for (int i = 0; i < d0; ++i) 
    {
      for (int j = 0; j < d1; ++j) 
      {
        // summing the indexes and saving into a new matrix
        result->setElement(this->getElement(i, j) + other.getElement(i, j), i,
                           j);
      }
    }
    return result;
  }

  else if (d0 != 0) 
  { // 1D Array
    if (d0 != other.d0) 
    {
      cout << "Dimension mismatch for sum operation." << endl;
      return nullptr;
    }

    MyArray *result = new MyArray(d0);
    for (int i = 0; i < d0; ++i) 
    {
        // summing the indexes and saving into a new matrix
      result->setElement(this->getElement(i) + other.getElement(i), i);
    }
    return result;
  }

  else {
    cout << "Invalid dimensions for sum operation." << endl;
    return nullptr;
  }
}

template <typename T> T MyArray<T>::sumElements() const {
  T total = T(); // Initialize to default value
  if (d2 != 0) 
  { // 3D Array
    for (int i = 0; i < d0; ++i) 
    {
      for (int j = 0; j < d1; ++j) 
      {
        for (int k = 0; k < d2; ++k) 
        {
          total += getElement(i, j, k);
        }
      }
    }
  } else if (d1 != 0) 
  { // 2D Array
    for (int i = 0; i < d0; ++i) 
    {
      for (int j = 0; j < d1; ++j) 
      {
        total += getElement(i, j);
      }
    }
  } 
  else if (d0 != 0) { // 1D Array
    for (int i = 0; i < d0; ++i) 
    {
      total += getElement(i);
    }
  }

  else 
  {
    cout << "Invalid dimensions for sum operation." <<  endl;
    total = 0;
  }
  return total;
}

template <typename T>
MyArray<T> *MyArray<T>::multiply(const MyArray &other) const {

  if (d2 != 0) 
  { // 3D Array
    if (d0 != other.d0 || d1 != other.d2 || d2 != other.d1) 
    {
      cout << "Dimension mismatch for matrix multiplication." << endl;
      return nullptr;
    }

    MyArray *result = MyArray<T>::create(d0, d1, other.d2);
    for (int i = 0; i < d0; ++i) 
    {
      for (int j = 0; j < other.d2; ++j) 
      {
        for (int k = 0; k < d2; ++k) 
        {
          // Sum over the d1 dimension
          T sum = T();
          for (int l = 0; l < d1; ++l) 
          {
            sum += getElement(i, l, k) * other.getElement(l, k, j);
          }
          // Set the element of the result array to the sum
          result->setElement(sum, i, j, k);
        }
      }
    }
  }

  else if (d1 != 0) 
  { // 2D Array
    if (d1 != other.d0) 
    {
      cout << "Dimension mismatch for matrix multiplication." << endl;
      return nullptr;
    }

    MyArray *result = MyArray<T>::create(d0, other.d1);

    // Loop over each element of the result array
    for (int i = 0; i < d0; ++i) 
    {
      for (int j = 0; j < other.d1; ++j) 
      {
        // Initialize the sum to zero
        T sum = T();

        // Loop over each element of the first array
        for (int k = 0; k < d1; ++k) 
        {
          // Multiply the element of the first array by the element of the second array
          sum += getElement(i, k) * other.getElement(k, j);
        }

        // Set the element of the result array to the sum
        result->setElement(sum, i, j);
      }
    }

    // Return the result array
    return result;
  }

  else 
  { // 1D Array
    if (d0 != other.d0) 
    {
      cout << "Dimension mismatch for matrix multiplication." << endl;
      return nullptr;
    }

    MyArray *result = MyArray<T>::create(d0);
    for (int i = 0; i < d0; ++i) 
    {
      T sum = T();
      for (int k = 0; k < d0; ++k) 
      {
        sum += getElement(k) * other.getElement(k);
      }
      result->setElement(sum, 0);
    }
    return result;
  }
  return nullptr;
}

template <typename T> MyArray<T> *MyArray<T>::getTranspose() {
  if (d2 != 0) 
  { // 3D Array
    MyArray *result = MyArray<T>::create(d2, d1, d0);
    for (int i = 0; i < d0; ++i) 
    {
      for (int j = 0; j < d1; ++j) 
      {
        for (int k = 0; k < d2; ++k) 
        {
          // Interchange the elements 
          result->setElement(getElement(i, j, k), k, j, i); 
        }
      }
    }
    return result;
  }

  else if (d1 != 0) 
  { // 2D Array
    MyArray *result = MyArray<T>::create(d1, d0);
    for (int i = 0; i < d0; ++i) 
    {
      for (int j = 0; j < d1; ++j) 
      {
        // Interchange the rows and columns
        result->setElement(getElement(i, j), j, i);
      }
    }
    return result;
  }

  else if (d0 != 0) 
  { // 1D Array
    MyArray *result = MyArray<T>::create(d0);
    for (int i = 0; i < d0; ++i) 
    {
      result->setElement(getElement(d0 - i - 1), i); // reverse the array
    }
    return result;
  }

  else 
  {
    cout << "Invalid dimensions for transpose." << endl;
    return nullptr;
  }
}

template <typename T> MyArray<T> *MyArray<T>::create(int d0, int d1, int d2) {
  return new MyArray(d0, d1, d2); // returns new memory allocation throughout the progran
}

 // for the templates
void temp(){
  MyArray<int> *array = MyArray<int>::create(3);

  array->setElement(10, 0);
  array->getElement( 1);
  array->display();
  array->multiply(*array);
  array->sum(*array);
  array->sumElements();
  array->getTranspose();
  array->getDimensions();
  array->display();

  delete[] array;


};