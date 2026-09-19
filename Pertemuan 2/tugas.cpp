#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void insertFirst(int n) {
    node *newNode = new node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(int n) {
    node *newNode = new node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "List Kosong!" << endl;
        return;
    }
    node *newNode = new node;
    newNode->value = n;
    newNode->next = NULL;
    node *p = head;

    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << " tidak ditemukan!" << endl;
        delete newNode;
    } else {
        newNode->next = p->next;
        p->next = newNode;

        if (p == tail) {
            tail = newNode;
        }
    }
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    node *temp = head;
    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }
    delete temp;
}

void deleteLast() {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    node *p = head;

    while (p->next != tail) {
        p = p->next;
    }

    delete tail;
    tail = p;
    tail->next = NULL;
}

void deleteMiddle(int value) {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    
    if (head->value == value) {
        deleteFirst();
        return;
    }
    node *p = head;

    while (p->next != NULL && p->next->value != value) {
        p = p->next;
    }

    if (p->next == NULL) {
        cout << "Node dengan nilai " << value << " tidak ditemukan" << endl;
    } else {
        node *temp = p->next;
        p->next = temp->next;

        if (temp == tail) {
            tail = p;
        }

        delete temp;
    }
}

void display() {
    node *temp = head;
    cout << "Isi Linked List: ";
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int pilihan;
    int nilai;
    int check;
    do {
        cout << endl;
        cout << "===== MENU SINGLE LINKED LIST =====" << endl;
        cout << "1. Tambah di awal" << endl;
        cout << "2. Tambah di akhir" << endl;
        cout << "3. Tambah setelah nilai tertentu" << endl;
        cout << "4. Hapus berdasarkan nilai" << endl;
        cout << "5. Tampilkan Linked List" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertFirst(nilai);
                display();
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertLast(nilai);
                display();
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> check;
                insertAfter(nilai, check);
                display();
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                deleteMiddle(nilai);
                display();
                break;
            case 5:
                display();
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak tersedia!" << endl;
        }
    } while (pilihan != 0);
    return 0;
}