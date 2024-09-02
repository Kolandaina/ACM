class Stack:
    def __init__(self):
        self.max_stack_size = 20
        self.stack = [None for i in range(self.max_stack_size)]
        self.top = -1
    # 判断栈空
    def is_empty(self):
        return self.top == -1
    # 判断栈满
    def is_full(self):
        return self.top == self.max_stack_size - 1
    # 进栈
    def push_stack(self, x):
        if self.is_full():
            print("Push stack")
        else:
            self.top += 1
            self.stack[self.top] = x
    # 出栈
    def pop_stack(self):
        if self.is_empty():
            print("Pop stack")
        else:
            ipos = self.stack[self.top]
            self.top -= 1
            return ipos
    # 取出栈顶元素
    def get_top_stack(self):
        if self.is_empty():
            print("栈空")
        return self.stack[self.top]
    # 输入
    def create_stack_by_input(self):
        element = input("Please enter:")
        while element != '#':
            self.push_stack(int(element))
            element = input("输入:")
    # 遍历
    def traverse_stack(self):
        if self.is_empty():
            print("Empty stack")
        else:
            for i in range(self.top + 1):
                print(self.stack[i], end=" ")
    # 出栈
    def pop_stack_all(self):
        while not self.is_empty():
            print(self.pop_stack(), end=" ")

def decimal_to_k(number, k):
    stack = Stack()
    while number >= k:
        stack.push_stack(number % k)
        number //= k
    stack.push_stack(number)
    result = ''
    while not stack.is_empty():
        result += str(stack.pop_stack())
    return int(result)


if __name__ == '__main__':
    m = int(input('请输入十进制数m:'))
    n = int(input('请输入k进制数的k:'))
    print(decimal_to_k(m, n))
