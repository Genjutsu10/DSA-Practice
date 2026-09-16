

class myStack {
	private:
	int top; // I was not able to use int n, int array, and int top in functions(isEmpty, push and pop).
	int capacity;
	int *arr;
	
	public:
	myStack(int n) {
		
		capacity = n;
		top = -1;
		arr = new int[capacity];
		
	}
	
	bool isEmpty() {
		return top == -1 ;
	}
	
	bool isFull() {
		return top == capacity - 1;
	}
	
	void push(int x) {
		
		if (top < capacity - 1) {
			top = top + 1;
			arr[top] = x;
		}
	}
	
	void pop() {
		
		if (top != -1) {
			top = top - 1;
		}
	}
	
	int peek() {
		if (top != -1) {
			return arr[top];
			
		} return - 1;
	}
	
};
