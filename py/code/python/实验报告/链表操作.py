class Node:
    def __init__(self, id, name, score):
        self.id = id
        self.name = name
        self.score = score
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def create_student(self):
        self.helper()
        element = int(input())
        while True:
            if element == 0:
                print("已退出学生管理系统，欢迎下次使用")
                break
            elif element == 1:
                self.record()
            elif element == 2:
                self.display()
            elif element == 3:
                self.inquire()
            elif element == 4:
                self.revise()
            elif element == 5:
                self.insert()
            elif element == 6:
                self.delete()
            elif element == 7:
                self.show()
            self.helper()
            element = int(input())

    def record(self):
        a = input("请输入学生学号：")
        b = input("请输入学生姓名：")
        c = input("请输入学生总分：")
        new_node = Node(a, b, c)
        if self.head is None:
            self.head = new_node
        else:
            current_node = self.head
            while current_node.next is not None:
                current_node = current_node.next
            current_node.next = new_node

    def display(self):
        current_node = self.head
        while current_node is not None:
            print("id: %s, name: %s, score: %s" % (current_node.id, current_node.name, current_node.score))
            current_node = current_node.next

    def inquire(self):
        a = input("请输入学生学号：")
        current_node = self.head
        while current_node is not None:
            if current_node.id == a:
                print("id: %s, name: %s, score: %s" % (current_node.id, current_node.name, current_node.score))
                break
            current_node = current_node.next

    def revise(self):
        a = input("请输入学生学号：")
        b = input("请输入学生姓名：")
        c = input("请输入学生总分：")
        current_node = self.head
        while current_node is not None:
            if current_node.id == a:
                current_node.name = b
                current_node.score = c
                break
            current_node = current_node.next

    def insert(self):
        ipos = int(input("请输入要插入的位置:"))
        a = input("请输入学生学号:")
        b = input("请输入学生姓名：")
        c = input("请输入学生总分：")
        node = Node(a, b, c)
        if ipos == 0:
            node.next = self.head
            self.head = node
        else:
            curnode = self.head
            for i in range(ipos - 1):
                curnode = curnode.next
                if curnode is None:
                    break
            if curnode is not None:
                node.next = curnode.next
                curnode.next = node

    def delete(self):
        a = input("请输入学生学号：")
        if self.head is None:
            return
        if self.head.id == a:
            self.head = self.head.next
            return
        current_node = self.head
        while current_node.next is not None:
            if current_node.next.id == a:
                current_node.next = current_node.next.next
                return
            current_node = current_node.next

    def show(self):
        if self.head is None:
            return
        node_list = []
        current_node = self.head
        while current_node is not None:
            node_list.append(current_node)
            current_node = current_node.next
        node_list.sort(key=lambda x: x.score, reverse=True)
        for node in node_list:
            print("id: %s, name: %s, score: %s" % (node.id, node.name, node.score))

    @classmethod
    def helper(cls):
        print("|***********欢迎进入学生管理系统**********|")
        print("|             1.录入学生信息             |")
        print("|             2.显示学生信息             |")
        print("|             3.查询学生信息             |")
        print("|             4.修改学生信息             |")
        print("|             5.添加学生信息             |")
        print("|             6.删除学生信息             |")
        print("|             7.按总分排名次             |")
        print("|             0.退出                    |")
        print("|**************************************|")
        print("请输入您所选的选项(0--7):")


if __name__ == "__main__":
    students = LinkedList()
    students.create_student()
