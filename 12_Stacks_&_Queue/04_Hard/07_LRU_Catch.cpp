//! ================================== Optimal code ==================================

#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:

    // Doubly Linked List ka node
    // Har node me key aur value store hogi
    class Node {
    public:
        int key;
        int value;

        Node* next;
        Node* prev;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };

    // Dummy nodes
    // head ke baad wala = Most Recently Used
    // tail ke pehle wala = Least Recently Used
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int capacity;

    // key -> us key ka node
    // Isse node ko O(1) me find kar sakte hai
    unordered_map<int, Node*> mp;


    LRUCache(int capacity) {

        this->capacity = capacity;

        // Initially list empty hai
        head->next = tail;
        tail->prev = head;
    }


    // New node ko head ke just baad add karenge
    // Matlab node Most Recently Used ban jayega
    void addNode(Node* newNode) {

        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }


    // Kisi existing node ko linked list se remove karna
    void deleteNode(Node* delNode) {

        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }


    int get(int key) {

        // Agar key hash map me present hai
        if(mp.find(key) != mp.end()) {

            Node* resNode = mp[key];

            int ans = resNode->value;

            // Access hone ke baad ye key
            // Most Recently Used ban jayegi
            mp.erase(key);

            deleteNode(resNode);

            addNode(resNode);

            mp[key] = head->next;

            return ans;
        }

        // Key nahi mili
        return -1;
    }


    void put(int key, int value) {

        // Agar key already exist karti hai
        if(mp.find(key) != mp.end()) {

            Node* existingNode = mp[key];

            // Purana node remove karenge
            mp.erase(key);
            deleteNode(existingNode);
        }


        // Agar cache full hai
        if(mp.size() == capacity) {

            // Tail ke just pehle wala
            // Least Recently Used node hai
            Node* lru = tail->prev;

            mp.erase(lru->key);

            deleteNode(lru);
        }


        // New node ko front par add karenge
        // Ye Most Recently Used ban jayega
        addNode(new Node(key, value));

        mp[key] = head->next;
    }
};