//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// Monomial Definition
//typedef struct monomial
//{
//    /* data */
//    float coef;
//    int A;
//    int B;
//    int C;
//};
//
//typedef struct list
//{
//    /* data */
//    struct node* head;
//    struct node* tail;
//    int n;
//};
//
//// Node definition
//typedef struct node
//{
//    /* data */
//    struct monomial value;
//    struct node* next;
//};
//
//// Create a new node
//struct node* new_node(struct monomial value)
//{
//    struct node* new_node = (struct node*)malloc(sizeof(struct node));
//    new_node->value = value;
//    new_node->next = 0;
//    return new_node;
//}
//
//// Delete a target node
//int list_delete(struct list* A, struct node* target)
//{
//    struct node* p = A->head;
//    struct node* q = 0;
//    while (p)
//    {
//        if (p == target)
//        {
//            if (q)
//            {
//                q->next = p->next;
//            }
//            else
//            {
//                A->head = p->next;
//            }
//            if (!p->next)
//            {
//                A->tail = q;
//            }
//            free(p);
//            A->n--;
//            return 0;
//        }
//        q = p;
//        p = p->next;
//    }
//    return -1;
//}
//
//// Finalize
//void finalize(struct list* list)
//{
//    struct node* current = list->head;
//    while (current != 0)
//    {
//        struct node* next = current->next;
//        free(current);
//        current = next;
//    }
//    free(list);
//}
//
//// Initialize
//struct list* initialize()
//{
//    struct list* list = (struct list*)malloc(sizeof(struct list));
//    list->head = 0;
//    list->tail = 0;
//    list->n = 0;
//    return list;
//}
//
//int list_insert(struct list* A, struct monomial nvalue)
//{
//    struct node* newN = new_node(nvalue);
//    if (!A->head)
//    {
//        A->head = newN;
//        A->tail = newN;
//    }
//    else
//    {
//        A->tail->next = newN;
//        A->tail = newN;
//    }
//    A->n++;
//    return 0;
//}
//
//// Develop a function to evaluate an operation between polynomials
//// Add two polynomials
//// Operation is P3 = P1 + kP2
//void add(struct list* P1, struct list* P2, struct list* P3, float k)
//{
//    // Go through P1 and P2 and add them to P3
//    struct node* current1 = P1->head;
//    while (current1 != 0)
//    {
//        struct node* current2 = P2->head;
//        while (current2 != 0)
//        {
//            if (current1->value.A == current2->value.A && current1->value.B == current2->value.B && current1->value.C == current2->value.C)
//            {
//                struct monomial newMonomial;
//                newMonomial.coef = current1->value.coef + current2->value.coef;
//                newMonomial.A = current1->value.A;
//                newMonomial.B = current1->value.B;
//                newMonomial.C = current1->value.C;
//                list_insert(P3, newMonomial);
//            }
//        }
//        current1 = current1->next;
//    }
//}
//
//// Test in main
//int main()
//{
//    struct list* P1 = initialize();
//    struct list* P2 = initialize();
//    struct list* P3 = initialize();
//    struct monomial new_node;
//    new_node.coef = 1;
//    new_node.A = 1;
//    new_node.B = 0;
//    new_node.C = 0;
//    list_insert(P1, new_node);
//    new_node.coef = 2;
//    new_node.A = 0;
//    new_node.B = 1;
//    new_node.C = 0;
//    list_insert(P1, new_node);
//    new_node.coef = 3;
//    new_node.A = 0;
//    new_node.B = 0;
//    new_node.C = 1;
//    list_insert(P1, new_node);
//    new_node.coef = 1;
//    new_node.A = 1;
//    new_node.B = 0;
//    new_node.C = 0;
//    list_insert(P2, new_node);
//    new_node.coef = 2;
//    new_node.A = 0;
//    new_node.B = 1;
//    new_node.C = 0;
//    list_insert(P2, new_node);
//    new_node.coef = 3;
//    new_node.A = 0;
//    new_node.B = 0;
//    new_node.C = 1;
//    list_insert(P2, new_node);
//    add(P1, P2, P3, 1);
//    struct node* current = P3->head;
//    while (current != 0)
//    {
//        printf("%f*x^%d*y^%d*z^%d\n", current->value.coef, current->value.A, current->value.B, current->value.C);
//        current = current->next;
//    }
//    finalize(P1);
//    finalize(P2);
//    finalize(P3);
//    return 0;
//}

#include<iostream>
using namespace std;

class LinkedList;
class Node
{
    friend class LinkedList;

private:
    int data;
    Node* next;
};

class LinkedList {

private:
    Node* head;
public:
    LinkedList(); // Default constructor
    ~LinkedList(); // Destructor
    bool insertAtStart(int val);
    void display();
    int countNodes();
    bool removeKthNode(int k, int& val);
    void combine(LinkedList& list1, LinkedList& list2);
    void shuffleMerge(LinkedList& list1, LinkedList& list2);
    bool removeLastNode(int& val);
    bool removeSecondLastNode(int& val);
    Node* remove(int x) {
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL) {
            if (temp->data == x) {
                if (prev == NULL) {
                    head = temp->next;
                    return temp;
                }
                prev->next = temp->next;
                return temp;
            }
            prev = temp;
            temp = temp->next;
        }
        return NULL;
    }
    // 5 10 3 2 8
    void sort() {
        for (Node* temp = head; temp != NULL; temp = temp->next) {
            Node* min = temp;
            for (Node* temp2 = temp->next; temp2 != NULL; temp2 = temp2->next) {
                if (min->data > temp2->data)
                {
                    min = temp2;
                }
            }
            Node* remo = remove(min->data);
            Node* temp3 = head;
            while (temp3->next != NULL) {
                temp3 = temp3->next;
            }
            temp3->next = remo;
            remo->next = NULL;
        }
    }

};


LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList() {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

bool LinkedList::insertAtStart(int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->next = head;
    head = temp;
    return true;
}

void LinkedList::display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int LinkedList::countNodes() {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


bool LinkedList::removeKthNode(int k, int& val) {
    Node* temp = head;
    Node* prev = NULL;
    int count = 0;
    while (temp != NULL) {
        if (count == k) {
            val = temp->data;
            if (temp == head) {
                head = head->next;
            }
            else {
                prev->next = temp->next;
            }
            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
    return false;
}

void LinkedList::combine(LinkedList& list1, LinkedList& list2) {
    Node* temp1 = list1.head;
    Node* temp2 = list2.head;
    Node* prev = NULL;

    if (temp1) {
        head = temp1;
        while (temp1) {
            prev = temp1;
            temp1 = temp1->next;
        }
        if (temp2) {
            prev->next = temp2;
        }
        list1.head = NULL;
        list2.head = NULL;
    }
    else {
        head = temp2;
        list2.head = NULL;
        return;
    }

}

void LinkedList::shuffleMerge(LinkedList& list1, LinkedList& list2) {
    Node* temp1 = list1.head;
    Node* temp2 = list2.head;

    head = temp1;
    temp1 = temp1->next;
    while (temp1 && temp2) {
        head->next = temp2;
        temp2 = temp2->next;
        head = head->next;
        head->next = temp1;
        temp1 = temp1->next;
        head = head->next;
    }
    head->next = temp2;
    head = list1.head;
    list1.head = NULL;
    list2.head = NULL;
}

bool LinkedList::removeLastNode(int& val) {
    int nodeCount = countNodes();
    return removeKthNode(nodeCount - 1, val);
}

bool LinkedList::removeSecondLastNode(int& val) {
    int nodeCount = countNodes();
    return removeKthNode(nodeCount - 2, val);
}

class CDLLD;
class DNode
{
    friend class CDLLD;

public:
    int data;
    DNode* next;
    DNode* prev;
};
class CDLLD
{ // Circular Doubly Linked List with a Dummy header node
public:
    DNode head; // Dummy header node

    CDLLD();  // Default constructor
    ~CDLLD(); // Destructor
    bool insertAtStart(int val);
    bool insertAtEnd(int val);
    void display();
    int countNodes();
    void shuffleMerge(CDLLD& list1, CDLLD& list2) {

        DNode* ptr1 = list1.head.next;
        DNode* ptr2 = list2.head.next;
        DNode* ptr3 = ptr1->next;
        DNode* ptr4 = ptr2->next;
        while (ptr3 != &list1.head && ptr4 != &list2.head)
        {

            ptr1->next = ptr2;
            ptr2->prev = ptr1;
            ptr2->next = ptr3;
            ptr3->prev = ptr2;
            ptr2 = ptr4;
            ptr1 = ptr3;
            ptr3 = ptr3->next;
            ptr4 = ptr4->next;
        }
        ptr2->next = &head;
        head.prev = ptr2;
        head.next = list1.head.next;

        list1.head.next = &list1.head;
        list1.head.prev = &list1.head;
        list2.head.next = &list2.head;
        list2.head.prev = &list2.head;
        return;

        DNode* list1Head = list1.head.next;
        DNode* list2Head = list2.head.next;
        DNode* list1Tail = list1.head.prev;
        DNode* list2Tail = list2.head.prev;

        head.next = list1Head;
        list1Head->prev = &head;
        head.prev = list2Tail;
        list2Tail->next = &head;


        list1Head = list1Head->next;
        DNode *temp = head.next;
        while (list1Head != &list1.head && list2Head != &list2.head) {
            temp->next = list2Head;
            list2Head->prev = temp;
            list2Head = list2Head->next;
            temp = temp->next;
            temp->next = list1Head;
            list1Head->prev = temp;
            list1Head = list1Head->next;
            temp = temp->next;
        }
        temp->next = list2Head;
        list2Head->prev = temp;

        list1.head.next = &list1.head;
        list1.head.prev = &list1.head;

        list2.head.next = &list2.head;
        list2.head.prev = &list2.head;
    }
};

CDLLD::CDLLD()
{
    head.next = &head;
    head.prev = &head;
}

CDLLD::~CDLLD()
{
    DNode* temp;
    while (head.next != &head) {
        temp = head.next;
        head.next = temp->next;
        temp->next->prev = &head;
        delete temp;
    }
}

bool CDLLD::insertAtStart(int val) {
    DNode* temp = new DNode();
    temp->data = val;
    temp->next = head.next;
    temp->prev = &head;
    head.next->prev = temp;
    head.next = temp;
    return true;
}

bool CDLLD::insertAtEnd(int val) {
    DNode* temp = new DNode();
    temp->data = val;
    temp->next = &head;
    temp->prev = head.prev;
    head.prev->next = temp;
    head.prev = temp;
    return true;
}

void CDLLD::display() {
    DNode* temp = head.next;
    while (temp != &head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int CDLLD::countNodes() {
    DNode* temp = head.next;
    int count = 0;
    while (temp != &head) {
        count++;
        temp = temp->next;
    }
    return count;
}


void combine(CDLLD& list1, CDLLD& list2, CDLLD& list3) {
    //Start of List 1
    DNode* list1head = list1.head.next;
    //End of list1
    DNode* list1tail = list1.head.prev;
    //Start of list2
    DNode* list2head = list2.head.next;
    //End of list2
    DNode* list2tail = list2.head.prev;

    list1tail->next = list2head;
    list2head->prev = list1tail;

    list2tail->next = &list3.head;

    list3.head.next = list1head;
    list3.head.prev = list2tail;

    list1.head.next = &list1.head;
    list1.head.prev = &list1.head;

    list2.head.next = &list2.head;
    list2.head.prev = &list2.head;
}



int main()
{
    //Create a Circular Doubly Linked List with a Dummy header node
    CDLLD list1;
    list1.insertAtStart(3);
    list1.insertAtStart(4);
    list1.display();
    //Create a Circular Doubly Linked List with a Dummy header node
    CDLLD list2;
    list2.insertAtStart(5);
    list2.insertAtStart(8);
    list2.display();
    //Create a Circular Doubly Linked List with a Dummy header node
    CDLLD list3;

    //Combine the two lists
    //combine(list1, list2, list3);
    //Display the combined list

    list3.shuffleMerge(list1, list2);
    list3.display();

    return 0;
}