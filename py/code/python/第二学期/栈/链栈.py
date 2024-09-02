class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.top = Node(None)

    def push(self, data):
        node = Node(data)
        node.next = self.top.next
        self.top.next = node

    def is_empty(self):
        return None is self.top.next

    def pop(self):
        if self.is_empty():
            return False
        node = self.top.next
        self.top.next = node.next
        return node.next.data

    def peek(self):
        return self.top.next.data


if __name__ == '__main__':
    stack = Stack()
    stack.push(2)
    stack.push(3)
    stack.push(3)
    print(stack.pop())
    print(stack.pop())
    print(stack.pop())