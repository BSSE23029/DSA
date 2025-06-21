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
}

// Partition function used by quicksort
template <typename T> int partition(T *array, int left, int right) {

  // Take the last element as the pivot
  T pivot = array[right];

  // Initialize i as the index of the smaller element
  int i = left - 1;

  // Iterate through the array from left to right
  for (int j = left; j < right; ++j) {

    // If the current element is smaller than or equal to the pivot
    if (array[j] <= pivot) {

      // Increment i (index of smaller element)
      i++;

      // Swap the smaller element with the current element
      swap(array[i], array[j]);
    }
  }

  // Place the pivot element at its correct position
  swap(array[i + 1], array[right]);

  // Return the index of the pivot element
  return i + 1;
}

// Quick sort algorithm
template <typename T> void quick_Sort(T *array, int left, int right) {
  // Base case: if the subarray has one or zero elements, it's already sorted
  if (left < right) {

    // Find the pivot index
    int pivotIndex = partition(array, left, right);

    // Recursively sort the subarrays on the left and right of the pivot
    quick_Sort(array, left, pivotIndex - 1);
    quick_Sort(array, pivotIndex + 1, right);
  }
}

// Now integrate this into MyArray's quickSort method:
template <typename T> void MyArray<T>::quickSort(char axis) {

  // Get the number of dimensions in the array
  int dimensions = getDimensions();

  if (dimensions == 1) {
    // For 1D array, use custom quickSort
    quick_Sort(arr1D, 0, d0 - 1);
  } else if (dimensions == 2) {
    if (axis == 'x' || axis == 'X') {
      // Sort along rows
      for (int i = 0; i < d1; ++i) {
        // Apply quick sort to each row individually
        quick_Sort(arr2D[i], 0, d0 - 1);
      }
    } else if (axis == 'y' || axis == 'Y') {
      // Sort along columns (manual column sorting)
      for (int j = 0; j < d0; ++j) {
        // Extract column

        // Create a temporary array to hold the current column
        T *tempColumn = new T[d1];

        // Copy the current column to the temporary array
        for (int i = 0; i < d1; ++i) {
          tempColumn[i] = arr2D[i][j];
        }

        // Use custom quickSort on tempcolumn
        quick_Sort(tempColumn, 0, d1 - 1);

        // Replace the original column with the sorted temporary column
        for (int i = 0; i < d1; ++i) {
          arr2D[i][j] = tempColumn[i];
        }

        // Clean up the temporary array
        delete[] tempColumn;
      }
    }
  } else if (dimensions == 3) {
    if (axis == 'x' || axis == 'X') {
      // Sort along x (rows in each 2D plane)
      for (int i = 0; i < d1; ++i) {
        for (int j = 0; j < d2; ++j) {
          // Apply quick sort to each 2D slice individually
          quick_Sort(arr3D[i][j], 0, d0 - 1);
        }
      }
    } else if (axis == 'y' || axis == 'Y') {
      // Sort along y (columns in each 2D plane(depth))
      for (int k = 0; k < d2; ++k) // depth
      {
        for (int j = 0; j < d0; ++j) // columns
        {
          // Create a temporary array to hold the current column
          T *tempColumn = new T[d1];

          // Copy the current column to the temporary array
          for (int i = 0; i < d1; ++i) // rows
          {
            tempColumn[i] = arr3D[j][i][k];
          }

          // Apply quick sort to the temporary column
          quick_Sort(tempColumn, 0, d1 - 1);

          // Replace the original column with the sorted temporary column
          for (int i = 0; i < d1; ++i) {
            arr3D[j][i][k] = tempColumn[i];
          }
          // Clean up the temporary array
          delete[] tempColumn;
        }
      }
    } else if (axis == 'z' || axis == 'Z') {
      // Sort along z (layers in each 2D slice)
      for (int i = 0; i < d1; ++i) // rows
      {
        for (int j = 0; j < d0; ++j) // columns
        {

          // Create a temporary array to hold the current layer
          T *tempLayer = new T[d2];

          // Copy the current layer to the temporary array
          for (int k = 0; k < d2; ++k) {
            tempLayer[k] = arr3D[j][i][k];
          }

          // Apply quick sort to the temporary layer
          quick_Sort(tempLayer, 0, d2 - 1);

          // Replace the original layer with the sorted temporary layer
          for (int k = 0; k < d2; ++k) {
            arr3D[j][i][k] = tempLayer[k];
          }
          // Clean up the temporary array
          delete[] tempLayer;
        }
      }
    }
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
void MyArray<T>::setElement(T value, int index0, int index1, int index2) {

  if (d2 != 0) {
    if (index0 >= 0 && index0 <= d0 && index1 >= 0 && index1 <= d1 &&
        index2 >= 0 && index2 <= d2) {
      // itterating after boundchecking
      arr3D[index0][index1][index2] = value;
    } else {
      cout << "Indices out of bounds." << endl;
    }
  } else if (d1 != 0) {
    if (index0 >= 0 && index0 <= d0 && index1 >= 0 && index1 <= d1) {
      // cout << "\n 2d case \n";

      // itterating after boundchecking
      arr2D[index0][index1] = value;

      // cout << "\n at index " << index0 << index1 << endl;
    } else {
      cout << "Indices out of bounds." << endl;
    }
  } else if (d0 != 0) {
    if (index0 >= 0 && index0 <= d0) {
      // cout << "\n 1d case \n";

      // itterating after boundchecking
      arr1D[index0] = value;
    } else {
      cout << "Index out of bounds." << endl;
    }
  } else {
    cout << "Error: Invalid dimensions" << endl;
  }
}

template <typename T>
T MyArray<T>::getElement(int index0, int index1, int index2) const {
  if (d2 != 0) {
    if (index0 >= 0 && index0 < d0 && index1 >= 0 && index1 < d1 &&
        index2 >= 0 && index2 < d2) {
      // itterating after boundchecking
      return arr3D[index0][index1][index2];
    } else {
      cout << "Indices out of bounds." << endl;
      return T{};
    }
  } else if (d1 != 0) {
    if (index0 >= 0 && index0 < d0 && index1 >= 0 && index1 < d1) {
      // itterating after boundchecking
      return arr2D[index0][index1];
    } else {
      cout << "Indices out of bounds." << endl;
      return T{};
    }
  } else if (d0 != 0) {
    if (index0 >= 0 && index0 < d0) {
      // itterating after boundchecking
      return arr1D[index0];
    } else {
      cout << "Index out of bounds." << endl;
      return T{};
    }
  } else {
    cout << "Error: Invalid dimensions" << endl;
    return T{};
  }
}

template <typename T> void MyArray<T>::display() const {
  cout << endl << endl;
  if (d2 > 0) {
    for (int i = 0; i < d2; ++i) {
      for (int j = 0; j < d1; ++j) {
        for (int k = 0; k < d0; ++k) {
          cout << "Index"
               << "[" << k << "]"
               << "[" << j << "]"
               << "[" << i << "]: " << setw(5) << arr3D[k][j][i]
               << endl; // setw() -> set width
        }
        cout << endl;
      }
      cout << endl;
    }
  } else if (d1 > 0) {
    for (int i = 0; i < d1; ++i) {
      for (int j = 0; j < d0; ++j) {
        cout << "Index"
             << "[" << j << "]"
             << "[" << i << "]: " << setw(5) << arr2D[j][i]
             << endl; // setw() -> set width
      }
      cout << endl;
    }
  } else {
    for (int i = 0; i < d0; ++i) {
      cout << "Index"
           << "[" << i << "]: " << setw(5) << arr1D[i]
           << endl; // setw() -> set width
    }
    cout << endl;
  }
  cout << endl << endl;
}

template <typename T> MyArray<T> *MyArray<T>::create(int d0, int d1, int d2) {
  return new MyArray(
      d0, d1, d2); // returns new memory allocation throughout the progran
}

// This function calculates something called a "cofactor"
template <typename T> T MyArray<T>::getCofactor(int row, int col) {

  // First, we need to create a smaller matrix called a "minor"
  MyArray<T> *minor = getMinor(row, col);

  // Now, we calculate the cofactor using the minor
  // We first calculate the determinant of the minor matrix.
  // This gives us the value of the cofactor itself.
  // We then multiply this determinant by either 1 or -1, depending on whether
  // the sum of the row and column indices is even or odd.
  T cofactor = (*minor->getDeterminant()) * ((row + col) % 2 == 0 ? 1 : -1);
  delete minor;
  return cofactor;
}

// This function creates adjoint matrix for 2D matrix
template <typename T> MyArray<T> *MyArray<T>::getAdjoint() {
  // First, we create a new empty matrix to store the adjoint
  MyArray<T> *adjoint = new MyArray(d0, d1);

  // Now, we fill in the adjoint matrix with cofactors
  for (int i = 0; i < d0; ++i) {
    for (int j = 0; j < d1; ++j) {

      // We put the cofactor in the right spot in the adjoint matrix
      adjoint->setElement(getCofactor(j, i), i, j);
    }
  }
  return adjoint;
}

// This function tries to find its inverse
template <typename T> MyArray<T> *MyArray<T>::getInverse() {
  // First, we check if our grid is defined to be flipped
  if (d2 > 0) {
    cout << "Inverse is not defined for this array." << endl;
    return nullptr;
  }

  MyArray<T> *inverse;

  if (d1 > 0) {

    if (d1 != d0) {
      cout << "Matrix is not square." << endl;
      return nullptr;
    }

    // If the determinant is zero, we can't find the inverse
    T determinant = *this->getDeterminant();
    if (determinant == 0) {
      cout << "Matrix is singular and does not have an inverse." << endl;
      return nullptr;
    }

    // Now we create the adjoint matrix
    MyArray<T> *adjoint = this->getAdjoint();

    // And create a new empty matrix for the inverse
    inverse = new MyArray(d0, d1);

    // Finally, we fill in the inverse matrix using the adjoint and determinant
    for (int i = 0; i < d0; ++i) {
      for (int j = 0; j < d1; ++j) {
        inverse->setElement(adjoint->getElement(i, j) / determinant, i, j);
      }
    }

    delete adjoint;
  }

  // if 1D
  else if (d0 > 0) {
    // flip the array
    inverse = new MyArray(d0);

    for (int i = 0; i < d0; ++i) {
      inverse->setElement(this->getElement(i), d0 - 1 - i);
    }
  }

  return inverse;
}

template <typename T> MyArray<T> *MyArray<T>::transpose(MyArray<T> *matrix) {
  MyArray<T> *transposed = new MyArray(matrix->d1, matrix->d0);
  for (int i = 0; i < matrix->d0; ++i) {
    for (int j = 0; j < matrix->d1; ++j) {
      transposed->setElement(matrix->getElement(i, j), j, i);
    }
  }
  return transposed;
}

template <typename T> T *MyArray<T>::getDeterminant() {
  // Determinant is only defined for 2D square matrices
  if (d2 > 0 || d0 == 0) {
    cout << "Determinant is not defined for this array." << endl;
    return nullptr;
  }

  if (d1 != d0) {
    cout << "Matrix is not square." << endl;
    return nullptr;
  }

  T *result = new T;

  // For tiny grids, we can calculate the determinant easily
  if (d0 == 1) {
    *result = arr2D[0][0];
  } else if (d0 == 2) {
    *result = arr2D[0][0] * arr2D[1][1] - arr2D[0][1] * arr2D[1][0];
  } else if (d0 == 3) {
    *result =
        arr2D[0][0] * (arr2D[1][1] * arr2D[2][2] - arr2D[1][2] * arr2D[2][1]) -
        arr2D[0][1] * (arr2D[1][0] * arr2D[2][2] - arr2D[1][2] * arr2D[2][0]) +
        arr2D[0][2] * (arr2D[1][0] * arr2D[2][1] - arr2D[1][1] * arr2D[2][0]);
  } else {
    // Implement determinant calculation for larger matrices

    // This is a simplified version using "Laplace expansion"
    int sign = 1;
    T sum = 0;
    for (int i = 0; i < d0; ++i) {
      MyArray<T> *minor = getMinor(0, i);
      sum += sign * arr2D[0][i] * (*minor->getDeterminant());
      delete minor;
      sign *= -1;
    }
    *result = sum;
  }

  return result;
}

// This function makes a smaller grid by removing one row and column
template <typename T> MyArray<T> *MyArray<T>::getMinor(int row, int col) {

  // We create a brand new empty grid, but smaller
  MyArray<T> *minor = new MyArray(d0 - 1, d1 - 1);

  // Then we fill it up with numbers from our old grid, skipping the removed row
  // and column

  // Start with a counter for rows in our new small grid
  int r = 0;

  // Loop through each row of our big grid
  for (int i = 0; i < d0; ++i) {

    // Skip the row we want to remove from our minor
    if (i == row)
      continue;

    // Reset column counter for each kept row
    int c = 0;

    // Loop through each column of our big grid
    for (int j = 0; j < d1; ++j) {

      // Skip the column we want to remove from our minor

      if (j == col)
        continue;
      // Copy the cell value from our big grid to our small grid
      // We use r for rows and c for columns in our small grid
      minor->setElement(arr2D[i][j], r, c++);
    }
    // Move to the next row in our small grid
    r++;
  }
  return minor;
}

// Assignment-2

template <typename T> MyArray<T> *MyArray<T>::sum(const MyArray &other) {
  if (d2 != 0) { // 3D Array
    if (d0 != other.d0 || d1 != other.d1 || d2 != other.d2) {
      cout << "Dimension mismatch for sum operation." << endl;
      return nullptr;
    }

    MyArray *result = new MyArray(d0, d1, d2);
    for (int i = 0; i < d0; ++i) {
      for (int j = 0; j < d1; ++j) {
        for (int k = 0; k < d2; ++k) {
          // summing the indexes and saving into a new matrix
          result->setElement(
              this->getElement(i, j, k) + other.getElement(i, j, k), i, j, k);
        }
      }
    }
    return result;
  } else if (d1 != 0) { // 2D Array
    if (d0 != other.d0 || d1 != other.d1) {
      cout << "Dimension mismatch for sum operation." << endl;
      return nullptr;
    }

    MyArray *result = new MyArray(d0, d1);
    for (int i = 0; i < d0; ++i) {
      for (int j = 0; j < d1; ++j) {
        // summing the indexes and saving into a new matrix
        result->setElement(this->getElement(i, j) + other.getElement(i, j), i,
                           j);
      }
    }
    return result;
  }

  else if (d0 != 0) { // 1D Array
    if (d0 != other.d0) {
      cout << "Dimension mismatch for sum operation." << endl;
      return nullptr;
    }

    MyArray *result = new MyArray(d0);
    for (int i = 0; i < d0; ++i) {
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

template <typename T> MyArray<T> *MyArray<T>::getTranspose() {
  if (d2 != 0) { // 3D Array
    MyArray *result = MyArray<T>::create(d2, d1, d0);
    for (int i = 0; i < d0; ++i) {
      for (int j = 0; j < d1; ++j) {
        for (int k = 0; k < d2; ++k) {
          // Interchange the elements
          result->setElement(getElement(i, j, k), k, j, i);
        }
      }
    }
    return result;
  }

  else if (d1 != 0) { // 2D Array
    MyArray *result = MyArray<T>::create(d1, d0);
    for (int i = 0; i < d0; ++i) {
      for (int j = 0; j < d1; ++j) {
        // Interchange the rows and columns
        result->setElement(getElement(i, j), j, i);
      }
    }
    return result;
  }

  else if (d0 != 0) { // 1D Array
    MyArray *result = MyArray<T>::create(d0);
    for (int i = 0; i < d0; ++i) {
      result->setElement(getElement(d0 - i - 1), i); // reverse the array
    }
    return result;
  }

  else {
    cout << "Invalid dimensions for transpose." << endl;
    return nullptr;
  }
}

template <typename T> T MyArray<T>::sumElements() const {
  T total = T(); // Initialize to default value
  if (d2 != 0) { // 3D Array
    for (int i = 0; i < d0; ++i) {
      for (int j = 0; j < d1; ++j) {
        for (int k = 0; k < d2; ++k) {
          total += getElement(i, j, k);
        }
      }
    }
  } else if (d1 != 0) { // 2D Array
    for (int i = 0; i < d0; ++i) {
      for (int j = 0; j < d1; ++j) {
        total += getElement(i, j);
      }
    }
  } else if (d0 != 0) { // 1D Array
    for (int i = 0; i < d0; ++i) {
      total += getElement(i);
    }
  }

  else {
    cout << "Invalid dimensions for sum operation." << endl;
    total = 0;
  }
  return total;
}

template <typename T>
MyArray<T> *MyArray<T>::multiply(const MyArray &other) const {

  if (d2 != 0) { // 3D Array
    if (d0 != other.d0 || d1 != other.d1 || d2 != other.d2) {
      cout << "Dimension mismatch for matrix multiplication." << endl;
      return nullptr;
    }

    MyArray *result = MyArray<T>::create(d0, d1, d2);
    for (int i = 0; i < d2; ++i) {
      for (int j = 0; j < d1; ++j) {
        for (int k = 0; k < d0; ++k) {
          T element = this->getElement(k, j, i) * other.getElement(k, j, i);
          // Set the element of the result array to the sum
          result->setElement(element, i, j, k);
        }
      }
    }
    
      return result;
  }

  else if (d1 != 0) { // 2D Array
    if (d1 != other.d0) {
      cout << "Dimension mismatch for matrix multiplication." << endl;
      return nullptr;
    }

    MyArray *result = MyArray<T>::create(d0, other.d1);

    // Loop over each element of the result array
    for (int i = 0; i < d0; ++i) {
      for (int j = 0; j < other.d1; ++j) {
        // Initialize the sum to zero
        T sum = T();

        // Loop over each element of the first array
        for (int k = 0; k < d1; ++k) {
          // Multiply the element of the first array by the element of the
          // second array
          sum += getElement(i, k) * other.getElement(k, j);
        }

        // Set the element of the result array to the sum
        result->setElement(sum, i, j);
      }
    }

    // Return the result array
    return result;
  }

  else { // 1D Array
    if (d0 != other.d0) {
      cout << "Dimension mismatch for matrix multiplication." << endl;
      return nullptr;
    }

    MyArray *result = MyArray<T>::create(d0);
    for (int i = 0; i < d0; ++i) {
      T sum = T();
      for (int k = 0; k < d0; ++k) {
        sum += getElement(k) * other.getElement(k);
      }
      result->setElement(sum, 0);
    }
    return result;
  }
  return nullptr;
}

// Main function to test sorting
void dummy() {
  MyArray<int> *array = MyArray<int>::create(3, 2, 2);
  // 3 columns, 2 rows, 2 layers
  array->setElement(1, 0, 0, 0);
  array->setElement(2, 1, 0, 0);
  array->setElement(3, 2, 0, 0);

  array->setElement(4, 0, 1, 0);
  array->setElement(5, 1, 1, 0);
  array->setElement(6, 2, 1, 0);

  array->setElement(7, 0, 0, 1);
  array->setElement(8, 1, 0, 1);
  array->setElement(9, 2, 0, 1);

  array->setElement(10, 0, 1, 1);
  array->setElement(11, 1, 1, 1);
  array->setElement(12, 2, 1, 1);

  cout << "\n3D array:\n" << endl;
  array->display();

  cout << "Element from column 0, row 0, layer 0: "
       << array->getElement(0, 0, 0) << endl;
  cout << "Element from column 2, row 1, layer 1: "
       << array->getElement(2, 1, 1) << endl;

  // array->getRow2D(1);
  // array->getRow3D(0, 0);

  // int* arr = array->getRow3D(1, 0); //row , layer
  // cout << "row 1, layer 0:  [ " << arr[0] << " " << arr[1] << " " << arr[2]
  // << " ]" << endl << endl;

  array->getDeterminant();
  array->getInverse();
  array->quickSort('y');

  array->sum(*array);
  array->getTranspose();
  array->sumElements();
  array->multiply(*array);

  delete array;
}