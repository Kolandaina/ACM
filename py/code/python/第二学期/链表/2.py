class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data, position):
        if position < 0:
            print("Invalid position")
            return

        new_node = Node(data)

        if position == 0:
            new_node.next = self.head
            self.head = new_node
            return

        current = self.head
        current_position = 0

        while current_position < position - 1:
            current = current.next
            current_position += 1
            if current is None:
                break

        if current is None:
            print("Invalid position")
            return

        new_node.next = current.next
        current.next = new_node

    def display(self):
        current = self.head

        while current:
            print(current.data, end=" ")
            current = current.next

        print()


if __name__ == "__main__":
    # Create a linked list
    linked_list = LinkedList()

    # Insert elements
    linked_list.insert(1, 0)
    linked_list.insert(2, 0)
    linked_list.insert(3, 1)

    # Display the linked list
    linked_list.display()
