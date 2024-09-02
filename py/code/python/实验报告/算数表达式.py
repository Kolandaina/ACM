import re  # 引入re库


class Stack:  # 创建一个Stack类，
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def is_empty(self):
        return len(self.items) == 0

    def peek(self):
        return self.items[-1]

    def size(self):
        return len(self.items)


class Calculator:
    def __init__(self, str):
        self.str = str

    def change_houzhui(self):  # 去掉括号和将运算符号后移得到后缀表达式
        result = []
        stack = Stack()
        for i in self.str:
            if self.is_operator(i):
                result.append(float(i))
            else:
                if stack.is_empty():
                    stack.push(i)
                elif i in '*/(':
                    stack.push(i)
                elif i == ')':
                    t = stack.pop()
                    while t != '(':
                        result.append(t)
                        t = stack.pop()
                elif i in '+-' and stack.peek() in '*/':
                    if stack.items.count('(') == 0:
                        while not stack.is_empty():
                            result.append(stack.pop())
                    else:
                        t = stack.pop()
                        while t != '(':
                            result.append(t)
                            t = stack.pop()
                        stack.push('(')
                    stack.push(i)
                else:
                    stack.push(i)
        while not stack.is_empty():
            result.append(stack.pop())
        self.str = result

    def calac_houzhui(self):  # 将得到后缀表达式进行入栈和运算得到答案
        num = Stack()
        base_opt = ['+', '-', '*', '/']
        for j in self.str:
            if self.is_operator(j):
                num.push(float(j))
            if j in base_opt:
                num2 = num.pop()
                num1 = num.pop()
                if j == "+":
                    num.push(num1 + num2)
                elif j == "-":
                    num.push(num1 - num2)
                elif j == "*":
                    num.push(num1 * num2)
                else:
                    num.push(num1 / num2)
        return num.pop()

    @staticmethod
    def is_operator(e):
        opers = ['+', '-', '*', '/', '(', ')']
        if e in opers:
            return False
        return True


def formula_format(str):  # 通过re库和正则表达式将输入的算数表达式进行分割并返回一个列表
    str = re.sub(' ', '', str)
    str_list = [i for i in re.split('(\-\d+\.?\d*)', str) if i]
    str = []
    for i in str_list:
        if len(str) == 0 and re.search('^\-\d+\.?\d*$', i):
            str.append(i)
            continue
        if len(str) > 0:
            if re.search('[\+\-\*\/\(]$', str[-1]):
                str.append(i)
                continue
        item_split = [i for i in re.split('([\+\-\*\/\(\)])', i) if i]
        str += item_split
    return str


if __name__ == '__main__':
    str = input()
    str_list = formula_format(str)
    ss = Calculator(str_list)
    ss.change_houzhui()
    print(ss.calac_houzhui())
