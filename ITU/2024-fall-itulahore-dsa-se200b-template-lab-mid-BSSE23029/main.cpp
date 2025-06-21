#include "functions.h"


int main() {

    Student s1("ali", 3);
    Student s2("ali", 3);
    Student s3("ali", 3);

    //s1.display();

    Node n(s1);

    //n.display();

    //Node *newNode = new Node(s1);

    Queue q;

    q.enqueue(s1);

    //q.display();
    // q.enqueue(s2);
    // q.enqueue(s3);

    // q.display();
    

    //cout << "Mid Exam!";
    
    return 0;
}
