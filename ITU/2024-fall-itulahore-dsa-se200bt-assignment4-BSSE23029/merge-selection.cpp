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

// Insertion Sort for 1D array
    template <typename T> void MyArray<T>::insertionSort1D(T*& array) {
        int n = d0; // Assuming d0 represents the size of the 1D array
        for (int i = 0; i < n; i++) {
            T key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }

    // Insertion Sort for 2D array
    template <typename T> void MyArray<T>::insertionSort2D() {
        for (int i = 0; i < d1; i++) {
            insertionSort1D(arr2D[i]);
        }
    }

    
    // Insertion Sort for 3D array
    template <typename T> void MyArray<T>::insertionSort3D() {
        for (int i = 0; i < d2; i++) {
            for (int j = 0; j < d1; j++) {
                insertionSort1D(arr3D[i][j]);
            }
    }}

   // Selection Sort for 1D array
    template <typename T> void MyArray<T>::selectionSort1D(T*& array) {
          int n = d0;
        for (int i = 0; i < n - 1; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (array[j] < array[min])
                    min = j;
            }
            T temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }

    // Selection Sort for 2D array
    template <typename T> void MyArray<T>::selectionSort2D() {
        for (int i = 0; i < d1; i++) {
            selectionSort1D(arr2D[i]);
        }
    }

    // Selection Sort for 3D array
    template <typename T> void MyArray<T>::selectionSort3D() {
        for (int i = 0; i < d2; i++) {
            for (int j = 0; j < d1; j++){
                selectionSort1D(arr3D[i][j]);}
        }
    }

    template <typename T> void MyArray<T>::merge(T*& array, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        T* L = new T[n1];
        T* R = new T[n2];

        for (int i = 0; i < n1; i++)
            L[i] = array[left + i];
        for (int i = 0; i < n2; i++)
            R[i] = array[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                array[k] = L[i];
                i++;
            } else {
                array[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            array[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }

    template <typename T> void MyArray<T>::mergeSortRecursion(T*& array, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortRecursion(array, left, mid);
            mergeSortRecursion(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }

    

    // Merge Sort for 1D array
    template <typename T> void MyArray<T>::mergeSort1D(T*& array) {
        mergeSortRecursion(array, 0, d0 - 1);
    }

    

    // Merge Sort for 2D array
    template <typename T> void MyArray<T>::mergeSort2D() {
        for (int i = 0; i < d1; i++) {
            mergeSort1D(arr2D[i]);
        }
    }


    

    // Merge Sort for 3D array
    template <typename T> void MyArray<T>::mergeSort3D() {
        for (int i = 0; i < d2; i++) {
            for (int j = 0; j < d1; j++) {
                mergeSort1D(arr3D[i][j]);
            }
        }
    }

    // Get row function for 3D array
    template <typename T> T* MyArray<T>::getRow3D(int row, int layer) {
        if (row >= 0 && row < d1 && layer >= 0 && layer < d2) {
            return arr3D[layer][row];
        }
        return nullptr; // or throw an exception
    }

    // Get row function for 2D array
    template <typename T> T* MyArray<T>::getRow2D(int row) {
        if (row >= 0 && row < d1) {
            return arr2D[row];
        }
        return nullptr; // or throw an exception
    }

    // Set Element function
    template <typename T> void MyArray<T>::setElement(T value, int index1, int index2, int index3) {
        if (index3 != -1) {
            arr3D[index3][index2][index1] = value;
        } else if (index2 != -1) {
            arr2D[index2][index1] = value;
        } else {
            arr1D[index1] = value;
        }
    }

    // Get Element function
    template <typename T> T MyArray<T>::getElement(int index1, int index2, int index3) {
        if (index3 != -1) {
            return arr3D[index3][index2][index1];
        } else if (index2 != -1) {
            return arr2D[index2][index1];
        } else {
            return arr1D[index1];
        }
    }




// Assignment - 2
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
        cout << "\nColumn"<<i<<"\n";
      for (int j = 0; j < d1; ++j) 
      {
        cout << "\nRow"<<j<<"\n";
        for (int k = 0; k < d2; ++k) 
        {
            cout << "\nLayer"<<k<<"\n";
          cout << setw(5) << arr3D[i][j][k] << " "; // setw() -> set width
        }
        cout << endl<< endl<< endl;
      }
      cout << endl<< endl<< endl<< endl<< endl<< endl<< endl;
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

  array->insertionSort3D();
  array->selectionSort3D();
  array->mergeSort3D();

  array->getRow3D(0, 0);
  array->getRow3D(0, 0);

  delete[] array;


};