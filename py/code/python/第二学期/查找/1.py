class sequence_list:
    def __init__(self):
        self.sequence_list = []
        self.length = 0
    
    #创建顺序表
    def create_sequence(self):
        print("请输入数据后按回车确认，若想结束输入请按#")
        element = input("请输入元素：")
        while element != "#":
            self.sequence_list.append(int(element))
            element = input("请输入元素：")
        self.length = len(self.sequence_list)

    # 遍历顺序表
    def traverse_element(self):
        for i in range(self.length):
            print("第", i+1, "个元素的值为", self.sequence_list[i])

    # 查找元素值函数，用列表自带的index方法实现
    def find_element(self):
        key = int(input('请输入你要查找的元素值：'))
        if key in self.sequence_list:
            ipos = self.sequence_list.index(key)
            print('查找成功！值为',key,'的元素，位于当前顺序表的第',ipos+1,'个位置。')
        else:
            print('查找失败！当前顺序表中不存在值为',key,'的元素')
    
     # 顺序查找方法，在此补充代码
    def SequenceSearch(self, key):
        for i in range(len(self.sequence_list)):
            if self.sequence_list[i] == key:
                return i+1

    # 改进的顺序查找方法，“哨兵”，在此补充代码
    #def SequenceSearch1(self, key):
    
def test_search():
    sl = sequence_list()
    sl.create_sequence()
    sl.traverse_element()
    data = input("请输入你要查找的值：")
    index = sl.SequenceSearch(int(data))
    # index = sl.SequenceSearch1(int(data))
    if index != -1:
        print("你输入的值在第", index + 1, "个位置")
    else:
        print("你输入的值不存在")


if __name__ == "__main__":
    test_search()
