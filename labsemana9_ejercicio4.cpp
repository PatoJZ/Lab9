#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;

    Node(int value): data(value), next(NULL) {}
};
class LinkedList
{
private:
    Node* head;

public:
    // Constructor de la lista enlazada
    LinkedList() : head(NULL) {}

    // Destructor de la lista enlazada
    ~LinkedList()
    {
        // Liberar la memoria de todos los nodos al destruir la lista
        Node* current = head;
        while (current != NULL)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Método para insertar un elemento al final de la lista
    void insert(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {

            Node* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Método para buscar un elemento en la lista
    bool search(int value)
    {
        Node* current = head;
        while (current != NULL)
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Método para eliminar un elemento de la lista
    void remove(int value)
    {
        if (head == NULL)
        {
            return;
        }

        if (head->data == value)
        {

            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next != NULL)
        {

            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Método para imprimir los elementos de la lista
    void print()
    {
        Node* current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{

    LinkedList MiLista;

    // Insertar elementos
    MiLista.insert(5);
    MiLista.insert(10);
    MiLista.insert(3);

    // Imprimir la lista
    cout << "Lista: ";
    MiLista.print();

    // Buscar elementos
    cout << "Buscar 10: " << (MiLista.search(10) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscar 8: " << (MiLista.search(8) ? "Encontrado" : "No encontrado") << endl;


    // Eliminar elementos
    MiLista.remove(10);
    cout << "Elemento 10 removido" << endl;

    cout << "Lista Actualizada: ";
    MiLista.print();
    
    return 0;
}