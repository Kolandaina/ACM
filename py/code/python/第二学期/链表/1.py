class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            last_node = self.head
            while last_node.next:
                last_node = last_node.next
            last_node.next = new_node

    def delete(self, data):
        if self.head is None:
            return
        if self.head.data == data:
            self.head = self.head.next
            return
        current_node = self.head
        while current_node.next:
            if current_node.next.data == data:
                current_node.next = current_node.next.next
                return
            current_node = current_node.next

    def search(self, data):
        current_node = self.head
        while current_node:
            if current_node.data == data:
                return True
            current_node = current_node.next
        return False

    def traverse(self):
        current_node = self.head
        while current_node:
            print(current_node.data, end=' ')
            current_node = current_node.next


if __name__ == '__main__':
    # 创建一个新的链表
    linked_list = LinkedList()

    # 插入节点
    linked_list.insert(3)
    linked_list.insert(4)
    linked_list.insert(5)

    # 遍历链表
    linked_list.traverse()  # 输出: 3 4 5

    # 查找节点
    print(linked_list.search(4))  # 输出: True
    print(linked_list.search(6))  # 输出: False

    # 删除节点
    linked_list.delete(4)
    linked_list.traverse()  # 输出: 3 5
