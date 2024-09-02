# 定义链表节点类
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# 定义链表类
class LinkedList:
    def __init__(self):
        self.head = None

    # 创建链表
    def create(self, data):
        for val in data:
            node = ListNode(val)
            if not self.head:
                self.head = node
            else:
                cur = self.head
                while cur.next:
                    cur = cur.next
                cur.next = node

    # 打印链表
    def print(self):
        cur = self.head
        while cur:
            print(cur.val, end=' ')
            cur = cur.next
        print()

    # 插入链表
    def insert(self, index, val):
        if index < 0 or index > self.length():
            print("插入位置不合法")
            return False
        node = ListNode(val)
        if index == 0:
            node.next = self.head
            self.head = node
        else:
            cur = self.head
            for i in range(index - 1):
                cur = cur.next
            node.next = cur.next
            cur.next = node

    # 删除链表
    def delete(self, val):
        if not self.head:
            return False
        if self.head.val == val:
            self.head = self.head.next
            return True
        cur = self.head
        while cur.next:
            if cur.next.val == val:
                cur.next = cur.next.next
                return True
            cur = cur.next
        return False

    # 计算链表长度
    def length(self):
        cur = self.head
        count = 0
        while cur:
            count += 1
            cur = cur.next
        return count

    # 销毁链表
    def destroy(self):
        self.head = None


if __name__ == "__main__":
    # 创建链表
    llist = LinkedList()
    llist.create([1, 2, 3, 4, 5])

    # 打印链表
    llist.print()  # 1 2 3 4 5

    # 插入链表
    llist.insert(3, 6)

    # 删除链表
    llist.print()
    llist.delete(3)

    # 打印链表
    llist.print()  # 1 2 4 6 5

