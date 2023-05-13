#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;

    // Constructor del nodo
    Node(int value);
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
            // Si la lista está vacía, el nuevo nodo será el primero
            head = newNode;
        }
        else
        {
            // Si la lista no está vacía, buscar el último nodo y enlazarlo al nuevo nodo
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
                return true; // El elemento fue encontrado
            }
            current = current->next;
        }
        return false; // El elemento no fue encontrado
    }

    // Método para eliminar un elemento de la lista
    void remove(int value)
    {
        if (head == NULL)
        {
            return; // La lista está vacía, no hay nada que eliminar
        }

        if (head->data == value)
        {
            // El elemento a eliminar es el primero de la lista
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
            // El elemento a eliminar se encuentra en el medio de la lista
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
    // Crear una lista enlazada
    LinkedList MiLista;

    // Insertar elementos
    MiLista.insert(5);
    MiLista.insert(10);
    MiLista.insert(3);

    // Imprimir la lista
    MiLista.print(); // Output: 5 10 3

    // Buscar elementos
    cout << MiLista.search(10) << endl; // Output: 1 (true)
    cout << MiLista.search(7) << endl;  // Output: 0 (false)

    // Eliminar elementos
    MiLista.remove(10);
    return 0;
}