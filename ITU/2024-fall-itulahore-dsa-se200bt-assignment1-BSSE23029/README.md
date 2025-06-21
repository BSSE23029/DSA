[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Tk5_elYl)
# Fall2024-SE200T-DSA-Assignment1

Please follow the steps given in the document 


Implement the following ArrayList class with the given attributes and methods:

# Class Attributes:
    data
    size
    capacity
# Class Methods:
    insertAtIndex:
    Inserts an element at a specific index in the array. If the index is out of bounds, display an error message. Resize the array if necessary.

    removeAtIndex:
    Removes an element from a specific index in the array. If the index is out of bounds, display an error message. Adjust the array size accordingly.

    sortArray:
    Sorts the array in ascending order.

    display:
    Displays the current elements of the array.

    uniqueElements:
    This function will ensure that any repeated element in the array would be removed. 

    menu:
    Displays options:

  # Menu should be like this
  Enter 1 to insert at a given index
  Enter 2 to remove from a given index
  Enter 3 to sort the array
  Enter 4 to display the array
  Enter 5 to remove duplicates
  Enter 0 to Exit
  
  # Example Usage:
  
  Insert At Index:
  
  Input: Enter element to insert: 4
  Input: Enter index to insert at: 2
  Output: Array [10, 5, 4, 1, 7, 9, 0, 2]
  Remove At Index:
  
  Input: Enter index to remove from: 2
  Output: Array [10, 5, 1, 7, 9, 0, 2]
  Sort Array:
  
  Output: Array [0, 1, 2, 5, 7, 9, 10]
