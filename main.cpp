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

    Node* getHead() { return head; }

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
    friend ostream& operator<<(ostream& os, const List& l) {
        Node* temp = l.head;
        while (temp != NULL) {
            os << temp->data << " " << endl;
            temp = temp->next;
        }
        return os;
    }
    List solucion(int k){
        List l1;
        List l2;
        Node* temporal = head;
        while (temporal != NULL) {
            if(temporal->data < k){
                  l1.pushBack(temporal->data);
            }
            else{
                l2.pushBack(temporal->data);
            }
            temporal = temporal->next;
        }
        List l3;
        Node* temporal2 = l1.getHead();
        Node* temporal3 = l2.getHead();
        while(temporal2 != NULL){
            l3.pushBack(temporal2->data);
            temporal2 = temporal2->next;
        }
        while(temporal3 != NULL){
            l3.pushBack(temporal3->data);
            temporal3 = temporal3->next;
        }
        return l3;
    }
};

/* sol tarea
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

    void clear() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
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

    ~List() = default;

};

bool f() {
    return true;
}
*/

int main () {
/* Tarea del profesor para subir a canvas
    List l1;
    cout << 5/2;
    l1.pushFront(30);
    l1.pushBack(50);
    l1.pushFront(20);
    l1.pushFront(10);
    l1.pushBack(40);

    cout << "-------------"<<endl;


    cout << l1;
    l1.sort();
    cout << l1.isOdered()<<endl;
    l1.reverse();
    cout << l1;
*/
    List milista;
    int k = 3;
    milista.pushBack(1);
    milista.pushBack(4);
    milista.pushBack(3);
    milista.pushBack(2);
    milista.pushBack(5);
    milista.pushBack(2);
    cout << milista << endl;
    cout << "-----" << endl;
    cout << milista.solucion(k) << endl;

}