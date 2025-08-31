# include <iostream>
// We'll do some linked list excercises.
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }

    ~Node() = default;
};

class List {
    private:
    Node* head;
    public:
    List() : head(nullptr) {}

    Node* getHead() {
        return head;
    }

    int front() {
        return head->data;
    }
    int back() {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp->data;
    }

    void pushFront(int numerito) {
        Node* nuevoNode = new Node(numerito);
        nuevoNode->next = head;
        head = nuevoNode;
    }

    void pushBack(int numerito) {
        Node* nodo = new Node(numerito);
        if (!head) { head = nodo; return; }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nodo;
        nodo->next = NULL;
    }

    void popFront() {
        if (!head) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void popBack() {
        Node *temp = head;
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; return; }
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    int operator[](int pos) {
        Node* temp = head;
        int i = 0;
        while (i++ < pos) {
            temp = temp->next;
        }
        return temp->data;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        Node* temp = head;
        int i = 0;
        while (temp != NULL) {
            i++;
            temp = temp->next;
        }
        return i;
    }

    void clear() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void sort() {
        if (!head || !head->next) return;
        while (isOdered() == false) {
            Node* t = head;
            int contador = 0;
            while ( t != NULL && t->next != NULL ) {
                if (t->data > t->next->data) {
                    swamp(contador);
                }
                t = t->next;
                contador++;
            }
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void insert (int pos, int num) {
        Node * nodo = new Node(num);
        Node* temp = head;
        int i = 0;
        while (i++  < pos -1) {
            temp = temp->next;
        }
        nodo->next = temp->next;
        temp->next = nodo;
    }

    friend ostream& operator<<(ostream& os, const List& l) {
        Node* temp = l.head;
        while (temp != NULL) {
            os << temp->data << " " << endl;
            temp = temp->next;
        }
        return os;
    }

    void swamp(int i) {
        int si = size();
        if (i > si -2) {
            return;
            cout << "Error: No se coloco bien las constantes"<<endl;
        }

        if ( i == 0) {
            Node* t1 = head;
            Node* t2 = head->next;
            Node* t3 = head->next->next;
            t2->next = t1;
            t1->next = t3;
            head = t2;
        }
        else {
            Node* t1 = head;
            int var = 1;
            while (var++ < i) {
                t1 = t1->next;
            }
            Node* t2 = t1->next;
            Node* t3 = t2->next;
            t2->next = t3->next;
            t3->next = t2;
            t1->next = t3;
        }
    }

    bool isOdered() {
        if (!head || !head->next) return true;
        Node* t = head;
        while (t->next) {
            if (t->data > t->next->data) return false;
            t = t->next;
        }
        return true;
    }

    ~List() = default;

    };

    bool f() {
        return true;
    }

int main () {
        List l1;
        l1.pushFront(30);
        l1.pushBack(50);
        l1.pushFront(20);
        l1.pushFront(10);
        l1.pushBack(40);

        cout << "-------------" << endl;

        cout << l1;
        l1.sort();
        cout << "Order: ---" << endl;
        cout << l1.isOdered() << endl;
        cout << "Tamaño de lista: " << l1.size() << endl;

        cout << "El valor en la posicion 2:" << endl;
        cout << l1[2] << endl;




        l1.reverse();
        cout << "Reverse: ---" << endl;
        cout << l1;


}