#include "functions.h" // Assume this header includes Trie and TrieNode class definitions
using namespace std;

int main() {

  cout << endl << endl << endl << endl;

  Trie trie;
  int choice;
  string word;

  do {

    cout << endl << endl;

    cout << "\nTrie Operations Menu:\n";
    cout << "1. Insert a word\n";
    cout << "2. Search for a word\n";
    cout << "3. Search by prefix\n";
    cout << "4. Delete a word\n";
    cout << "5. Display all words\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";

    cin >> choice;

    cout << endl << endl;

    switch (choice) {
    case 1: {
      cout << "Enter a word to insert: ";
      cin >> word;
      trie.insert(word);
      cout << "\"" << word << "\" inserted into the Trie.\n";
      break;
    }

    case 2: {
      cout << "Enter a word to search: ";
      cin >> word;
      if (trie.search(word)) {
        cout << "\"" << word << "\" found in the Trie.\n";
      } else {
        cout << "\"" << word << "\" not found in the Trie.\n";
      }
      break;
    }

    case 3: {
      cout << "Enter a prefix to search: ";
      cin >> word;
      if (trie.startsWith(word)) {
        cout << "There are words in the Trie that start with \"" << word
             << "\".\n";
      } else {
        cout << "No words found with the prefix \"" << word << "\".\n";
      }
      break;
    }

    case 4: {
      cout << "Enter a word to delete: ";
      cin >> word;
      if (trie.deleteWord(word)) {
        cout << "\"" << word << "\" deleted from the Trie.\n";
      } else {
        cout << "\"" << word << "\" not found in the Trie.\n";
      }
      break;
    }

    case 5: {
      cout << "Words in the Trie:\n";
      trie.displayTrie();
      cout << endl;
      break;
    }

    case 0: {
      cout << "Exiting...\n";
      break;
    }

    default: {
      cout << "Invalid choice. Please try again.\n";
    }
    }
    cout << endl << endl;
  } while (choice != 0);
  cout << endl << endl << endl << endl;
  return 0;
}