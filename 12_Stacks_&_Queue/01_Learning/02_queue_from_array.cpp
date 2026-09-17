class myQueue {
	
	private:
	int start;
	int end;
	int current_size;
	int capacity;
	int *arr;
	
	public:
	
	myQueue(int n) {
		
		start = -1;
		end = -1;
		
		capacity = n;
		
		current_size = 0;
		
		arr = new int[capacity];
		
	}
	
	bool isEmpty() {
		
		return start == -1 && end == -1;
		
	}
	
	bool isFull() {
		
		return current_size == capacity;
	}
	
	void enqueue(int x) {
		if (current_size < capacity) {
			if (current_size == 0) {
				start = 0, end = 0;
			}
			else {
				end = (end + 1)%capacity;
			}
			
			arr[end] = x;
			current_size++;
		}
		
	}
	
	void dequeue() {
		
		if (current_size > 0) {
			if (current_size == 1) {
				start = -1, end = -1;
			}
			else {
				start = (start + 1)%capacity;
			}
			current_size --;
		}
		
	}
	
	int getFront() {
		if (current_size != 0) {
			return arr[start];
		}return -1;
	}
	
	int getRear() {
		if (current_size != 0) {
			return arr[end];
		}return -1;
	}
};
