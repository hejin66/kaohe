#include <iostream>
#include <cassert>

class BSTMap {
public:
    BSTMap() : root(nullptr) {}

    void put(int key, int value) {
        root = putHelper(root, key, value);
    }

    int get(int key) {
        Node* n = getHelper(root, key);
        return (n == nullptr) ? -1 : n->value;
    }

    bool containsKey(int key) {
        return getHelper(root, key) != nullptr;
    }

private:
    struct Node {
        int key;
        int value;
        Node *left, *right;
        Node(int k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* putHelper(Node* node, int key, int value) {
        if (node == nullptr) {
            return new Node(key, value);
        }
        if (key < node->key) {
            node->left = putHelper(node->left, key, value);
        } else if (key > node->key) {
            node->right = putHelper(node->right, key, value);
        } else {
            node->value = value;
        }
        return node;
    }

    Node* getHelper(Node* node, int key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (key < node->key) {
            return getHelper(node->left, key);
        } else if (key > node->key) {
            return getHelper(node->right, key);
        } else {
            return node;
        }
    }

    Node* root;
};

int main() {
    BSTMap m;
    m.put(5, 50);
    m.put(3, 30);
    m.put(7, 70);
    m.put(1, 10);
    m.put(9, 90);

    assert(m.get(5) == 50);
    assert(m.get(3) == 30);
    assert(m.get(7) == 70);
    assert(m.get(1) == 10);
    assert(m.get(9) == 90);
    assert(m.get(100) == -1);

    assert(m.containsKey(5) == true);
    assert(m.containsKey(100) == false);

    m.put(5, 500);
    assert(m.get(5) == 500);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
