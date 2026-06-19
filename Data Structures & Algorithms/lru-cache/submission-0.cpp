#include <unordered_map>
using namespace std;
class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;   
    Node* tail;   
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        Node* node = mp[key];
        deleteNode(node);
        addNode(node);
        return node->value;
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* existing = mp[key];
            existing->value = value;
            deleteNode(existing);
            addNode(existing);
            return;
        }
        if (mp.size() == capacity) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
            delete lru;
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};