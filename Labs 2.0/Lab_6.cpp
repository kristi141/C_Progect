#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    string data;
    vector<Node*> children;
    int capacity;

    Node(const string& data, int capacity) : data(data), capacity(capacity) {}

    ~Node() {
        for (Node* child : children) {
            delete child;
        }
    }
};

class Tree {
private:
    Node* root;
    int initialCapacity;

    void printTree(Node* node, int level, int child_num) {
        if (!node){
          return;  
        } 

        for (int i = 0; i < level; i++) 
            cout << "    ";

        if (level > 0){
            cout << "|-- " << child_num << ". ";
        }

        cout << node->data << endl;

        for (int i = 0; i < node->children.size(); i++) {
            printTree(node->children[i], level + 1, i + 1);
        }
    }

    Node* findAvailableParent(Node* node) {
        if (node->children.size() < node->capacity) {
            return node;
        }
        
        for (Node* child : node->children) {
            Node* available = findAvailableParent(child);
            if (available) {
                return available;
            }
        }
        return nullptr;
    }

public:
    Tree(int initialCapacity) : root(nullptr), initialCapacity(initialCapacity) {}

    ~Tree() {
        delete root;
    }

    void addNode(const string& data) {
        if (!root) {
            root = new Node(data, initialCapacity);
            return;
        }

        Node* parent = findAvailableParent(root);
        if (parent) {
            parent->children.push_back(new Node(data, initialCapacity));
        } else {
            root->children.push_back(new Node(data, initialCapacity));
        }
    }

    void printTree() {
        if (!root) {
            cout << "Дерево пустое!" << endl;
            return;
        }
        cout << "Структура дерева:" << endl;
        cout << "1. " << root->data << endl;  // Корень всегда 1
        for (int i = 0; i < root->children.size(); i++) {
            printTree(root->children[i], 1, i + 1);
        }
    }
};

int main() {
    int initialCapacity;
    cout << "Введите начальную емкость узлов: ";
    cin >> initialCapacity;

    Tree tree(initialCapacity);

    int option;
    string data;

    do {
        cout << "\nМеню:\n"
             << "1. Добавить вершину\n"
             << "2. Вывести дерево\n"
             << "3. Выход\n"
             << "Выберите опцию: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Введите данные для узла: ";
                cin >> data;
                tree.addNode(data);
                break;
            case 2:
                tree.printTree();
                break;
            case 3:
                cout << "Выход..." << endl;
                break;
            default:
                cout << "Ошибка: неверная опция!" << endl;
        }
    } while (option != 3);

    return 0;
}