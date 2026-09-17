class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// ignore above bullshit...

class myStack {
    
  private:
    int lenght;
    Node* top;

  public:
    myStack() {
    top = nullptr;
    lenght = 0;
    
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        lenght++;
        temp->data = x;
    }

    void pop() {
        
        if( top == nullptr) return ;
        Node* tem = top;
        top = tem->next;
        delete tem;
        lenght--;
        
    }

    int peek() {
        if( top == nullptr) return -1;
        return top->data;
    }

    int size() {
        return lenght;
    }
};