class Student:
    def __init__(self):
        self.list_name = []
        self.list_total_score = []
        self.list_id = []
        self.length = 0

    def create_seq_list(self):
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
        print("请输入学生学号，姓名和总分，当输入学生学号为0是结束录入")

        while True:
            a = int(input("请输入学生学号："))
            if a == 0:
                break
            b, c = input("请输入学生名字和总分：").split()
            self.list_id.append(a)
            self.list_name.append(b)
            self.list_total_score.append(c)
            self.length += 1

    def display(self):
        if self.length == 0:
            print("学生系统暂未录入学生信息")
        else:
            for i in range(self.length):
                print(f"{self.list_id[i]}   {self.list_name[i]}   {self.list_total_score[i]}")

    def inquire(self):
        a = input("请输入学生学号:")
        if a in self.list_id:
            n = self.list_id.index(a)
            print(f"{self.list_id[n]}   {self.list_name[n]}   {self.list_total_score[n]}")
        else:
            print("学生系统中暂未录入此人信息")

    def revise(self):
        a = int(input("请输入学生学号："))
        if a in self.list_id:
            b, c = input("请输入要修改学生的姓名和总分：")
            n = self.list_id.index(a)
            self.list_name[n] = b
            self.list_total_score[n] = c
        else:
            print("学生系统中暂未录入此人信息")

    def insert(self):
        ipos = int(input("请输入要插入的位置:"))
        a = input("请输入学生学号:")
        b = input("请输入学生姓名：")
        c = input("请输入学生总分：")
        self.list_id.insert(ipos-1, a)
        self.list_name.insert(ipos-1, b)
        self.list_total_score.insert(ipos-1, c)
        self.length += 1

    def delete(self):
        a = input("请输入要删除学生学号:")
        if a in self.list_id:
            n = self.list_id.index(a)
            self.list_id.remove(a)
            del self.list_total_score[n]
            del self.list_name[n]
            self.length -= 1
        else:
            print("学生系统中暂未录入此人信息")

    def show(self):
        if self.length == 0:
            print("学生系统暂未录入学生信息")
            return None
        list_name = self.list_name.copy()
        list_total_score = self.list_total_score.copy()
        list_id = self.list_id.copy()
        for i in range(0, self.length):
            for j in range(0, self.length - 1 - i):
                if list_total_score[j] < list_total_score[j + 1]:
                    list_total_score[j], list_total_score[j + 1] = list_total_score[j + 1], list_total_score[j]
                    list_name[j], list_name[j + 1] = list_name[j + 1], list_name[j]
                    list_id[j], list_id[j+1] = list_id[j+1], list_id[j]
        for i in range(self.length):
            print(f"{list_id[i]}   {list_name[i]}   {list_total_score[i]}")

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
    student = Student()
    student.create_seq_list()
