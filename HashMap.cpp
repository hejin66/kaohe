#include <iostream>
#include <cassert>
#include <vector>

class HashMap {
public:
    HashMap(int capacity = 10) {
        buckets.resize(capacity, nullptr);
        count = 0;
    }

    void put(int key, int value) {
        int idx = hash(key);
        Node* cur = buckets[idx];
        while (cur != nullptr) {
            if (cur->key == key) {
                cur->value = value;
                return;
            }
            cur = cur->next;
        }
        Node* node = new Node(key, value);
        node->next = buckets[idx];
        buckets[idx] = node;
        count++;
    }

    int get(int key) {
        int idx = hash(key);
        Node* cur = buckets[idx];
        while (cur != nullptr) {
            if (cur->key == key) {
                return cur->value;
            }
            cur = cur->next;
        }
        return -1;
    }

    bool containsKey(int key) {
        int idx = hash(key);
        Node* cur = buckets[idx];
        while (cur != nullptr) {
            if (cur->key == key) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    int hash(int key) {
        return key % buckets.size();
    }

    std::vector<Node*> buckets;
    int count;
};

int main() {
    HashMap m;
    m.put(5, 50);
    m.put(15, 150);
    m.put(7, 70);

    assert(m.get(5) == 50);
    assert(m.get(15) == 150);
    assert(m.get(7) == 70);
    assert(m.get(100) == -1);

    assert(m.containsKey(5) == true);
    assert(m.containsKey(100) == false);

    m.put(5, 500);
    assert(m.get(5) == 500);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
