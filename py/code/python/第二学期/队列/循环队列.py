class CircularQueue:
    def __init__(self, maxsize):
        self.maxsize = maxsize
        self.queue = [None] * maxsize
        self.front = 0
        self.rear = 0
    
    def is_empty(self):
        return self.front == self.rear and not self.queue[self.front]
    
    def is_full(self):
        return self.front == self.rear and self.queue[self.front]
   
    def enqueue(self, value):
        if not self.is_full():
            self.queue[self.rear] = value
            self.rear = (self.rear + 1) % self.maxsize
        else:
            print("Queue is full.")
    
    def dequeue(self):
        if not self.is_empty():
            value = self.queue[self.front]
            self.queue[self.front] = None
            self.front = (self.front + 1) % self.maxsize
            return value
        else:
            print("Queue is empty.")
