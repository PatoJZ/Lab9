#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) : data(value), left(NULL), right(NULL) {} // Se inicializa en nulo
};

class BinaryTree
{
private:
    Node* root;

    // Método privado
    Node* insertRecursive(Node* currentNode, int value)
    {
        if (currentNode == NULL)
        {
            return new Node(value);
        }

        if (value < currentNode->data)
        {
            currentNode->left = insertRecursive(currentNode->left, value);
        }
        else if (value > currentNode->data)
        {
            currentNode->right = insertRecursive(currentNode->right, value);
        }

        return currentNode;
    }

    // Método 
    bool searchRecursive(Node* currentNode, int value) 
    {
        if (currentNode == NULL)
        {
            return false;
        }

        if (value == currentNode->data)
        {
            return true;
        }
        else if (value < currentNode->data)
        {
            return searchRecursive(currentNode->left, value);
        }
        else
        {
            return searchRecursive(currentNode->right, value);
        }
    }

    // Método para imprimir
    void printInOrderRecursive(Node* currentNode) 
    {
        if (currentNode == NULL)
        {
            return;
        }

        printInOrderRecursive(currentNode->left);
        cout << currentNode->data << " ";
        printInOrderRecursive(currentNode->right);
    }

public:
    // Constructor
    BinaryTree() : root(NULL) {}

    // Insertar un valor en el árbol
    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    // Buscar un valor en el árbol
    bool search(int value) 
    {
        return searchRecursive(root, value);
    }

    // Imprimir el árbol en orden
    void printInOrder() 
    {
        printInOrderRecursive(root);
        cout << endl;
    }
};

int main()
{
    // Crear un árbol binario
    BinaryTree tree;

    // Insertar elementos en el árbol
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);

    // Imprimir el árbol en orden
    cout << "Arbol en orden: ";
    tree.printInOrder();

    // Buscar elementos en el árbol
    cout << "Buscar 4: " << (tree.search(4) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscar 6: " << (tree.search(6) ? "Encontrado" : "No encontrado") << endl;

    return 0;
}
