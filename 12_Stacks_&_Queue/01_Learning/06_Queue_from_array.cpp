class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class myQueue {
        
  private:
    
    int length;
    Node* end;
    Node* start;
    

  public:
    myQueue() {
        end = nullptr;
        start = nullptr;
        length = 0;
    }

    bool isEmpty() {
        return start == nullptr;
    }

    void enqueue(int x) {
        
        Node* temp = new Node(x);
            
        if( start == nullptr ){
            start = temp;
            end = temp;
        }
        else{
            end->next = temp;
            end = temp ;
        }
        length++;
        
    }

    void dequeue() {
        
        Node*temp=start;

        start=start->next;
        delete(temp);
        
        length--;
    }
    

    int getFront() {
        
        if( start == nullptr){
            return -1;
        }
        
        return start->data;
        
    }

    int size() {
        return length;
    }
};
