//focus on just explaining not writing code as it is already written in the file. 

/*
//ordered map with ologn insertion and search

#include <iostream>
using namespace std;

struct Node {
    int key, value;
    Node* left;
    Node* right;

    Node(int k, int v) {
        key = k;
        value = v;
        left = right = nullptr;
    }
};

class OrderedMap {
    Node* root = nullptr;

public:

    Node* insert(Node* node, int key, int value) {
        if (!node) return new Node(key, value);

        if (key < node->key)
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);
        else
            node->value = value; // update

        return node;
    }

    void insert(int key, int value) {
        root = insert(root, key, value);
    }

    int get(Node* node, int key) {
        if (!node) return -1;

        if (key == node->key) return node->value;
        else if (key < node->key) return get(node->left, key);
        else return get(node->right, key);
    }

    int get(int key) {
        return get(root, key);
    }
};

int main() {
    OrderedMap mp;

    mp.insert(2, 20);
    mp.insert(12, 120); // collision possible (2 % 10 == 12 % 10)

    cout << mp.get(2) << endl;
    cout << mp.get(12) << endl;
}


*/

#include <iostream>
#include <vector>
using namespace std;

class UnorderedMap {
    static const int SIZE = 10;
    vector<pair<int,int>> table[SIZE];

    int hash(int key) {
        return key % SIZE;
    }

public:

    void insert(int key, int value) {
        int idx = hash(key);

        for (auto &p : table[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }

        table[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = hash(key);

        for (auto &p : table[idx]) {
            if (p.first == key)
                return p.second;
        }

        return -1;
    }
};

int main() {
    UnorderedMap mp;

    mp.insert(2, 20);
    mp.insert(12, 120); // collision possible (2 % 10 == 12 % 10)

    cout << mp.get(2) << endl;
    cout << mp.get(12) << endl;
}