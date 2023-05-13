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

    // Método privado para insertar un valor en el árbol recursivamente
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

    // Método privado para buscar un valor en el árbol recursivamente
    bool searchRecursive(Node* currentNode, int value) const
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

    // Método privado para imprimir el árbol en orden recursivamente
    void printInOrderRecursive(Node* currentNode) const
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

    // Método público para insertar un valor en el árbol
    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    // Método público para buscar un valor en el árbol
    bool search(int value) const
    {
        return searchRecursive(root, value);
    }

    // Método público para imprimir el árbol en orden
    void printInOrder() const
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
    cout << "Árbol en orden: ";
    tree.printInOrder();

    // Buscar elementos en el árbol
    cout << "Buscar 4: " << (tree.search(4) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscar 6: " << (tree.search(6) ? "Encontrado" : "No encontrado") << endl;

    return 0;
}
