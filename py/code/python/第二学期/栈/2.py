import re

class Calculator:
    def __init__(self):
        self.num_stack = []
        self.op_stack = []
    
    @staticmethod
    def calculate(n1, n2, operator):
        '''
        :param n1: float
        :param n2: float
        :param operator: + - * /
        :return: float
        '''
        result = 0
        if operator == "+":
            result = n1 + n2
        elif operator == "-":
            result = n1 - n2
        elif operator == "*":
            result = n1 * n2
        elif operator == "/":
            result = n1 / n2
        return result
    
    @staticmethod
    def is_operator(e):
        '''
        :param e: str
        :return: bool
        '''
        opers = ['+', '-', '*', '/', '(', ')']
        return True if e in opers else False
    
    @staticmethod
    def decision(tail_op, now_op):
        '''
        :param tail_op: 运算符栈的最后一个运算符
        :param now_op: 从算式列表取出的当前运算符
        :return: 1 代表弹栈运算,0 代表弹运算符栈最后一个元素， -1 表示入栈
        '''
        # 定义4种运算符级别
        rate1 = ['+', '-']
        rate2 = ['*', '/']
        rate3 = ['(']
        rate4 = [')']

        if tail_op in rate1:
            if now_op in rate2 or now_op in rate3:
                # 说明连续两个运算优先级不一样，需要入栈
                return -1
            else:
                return 1

        elif tail_op in rate2:
            if now_op in rate3:
                return -1
            else:
                return 1

        elif tail_op in rate3:
            if now_op in rate4:
                return 0   # ( 遇上 ) 需要弹出 (，丢掉 )
            else:
                return -1  # 只要栈顶元素为(，当前元素不是)都应入栈。
        else:  # 栈顶运算符和当前运算符优先级相同
            return -1
    
    def final_calc(self, formula_list):
        self.num_stack = []       # 数字栈
        self.op_stack = []        # 运算符栈
        for e in formula_list:
            operator = self.is_operator(e)
            if not operator:
                # 压入数字栈
                # 字符串转换为符点数
                self.num_stack.append(float(e))
            else:
                # 如果是运算符
                while True:
                    # 如果运算符栈等于0无条件入栈
                    if len(self.op_stack) == 0:
                        self.op_stack.append(e)
                        break

                    # decision 函数做决策
                    tag = self.decision(self.op_stack[-1], e)
                    if tag == -1:
                        # 如果是-1压入运算符栈进入下一次循环
                        self.op_stack.append(e)
                        break
                    elif tag == 0:
                        # 如果是0弹出运算符栈内最后一个(, 丢掉当前)，进入下一次循环
                        self.op_stack.pop()
                        break
                    elif tag == 1:
                        # 如果是1弹出运算符栈内最后两个元素，弹出数字栈最后两位元素。
                        op = self.op_stack.pop()
                        num2 = self.num_stack.pop()
                        num1 = self.num_stack.pop()
                        # 执行计算
                        # 计算之后压入数字栈
                        self.num_stack.append(self.calculate(num1, num2, op))
        # 处理大循环结束后 数字栈和运算符栈中可能还有元素 的情况
        while len(self.op_stack) != 0:
            op = self.op_stack.pop()
            num2 = self.num_stack.pop()
            num1 = self.num_stack.pop()
            self.num_stack.append(self.calculate(num1, num2, op))

        return self.num_stack, self.op_stack
    
    @staticmethod
    def formula_format(formula):
        # 去掉算式中的空格
        formula = re.sub(' ', '', formula)
        # 以 '横杠数字' 分割， 其中正则表达式：(\-\d+\.?\d*) 括号内：
        # \- 表示匹配横杠开头； 
        # \d+ 表示匹配数字1次或多次；
        # \.?表示匹配小数点0次或1次；
        # \d*表示匹配数字1次或多次。
        formula_list = [i for i in re.split('(\-\d+\.?\d*)', formula) if i]

        # 最终的算式列表
        final_formula = []
        for item in formula_list:
            # 第一个是以横杠开头的数字（包括小数）final_formula。
            # 即第一个是负数，横杠就不是减号
            if len(final_formula) == 0 and re.search('^\-\d+\.?\d*$', item):
                final_formula.append(item)
                continue

            if len(final_formula) > 0:
                # 如果final_formal最后一个元素是运算符['+', '-', '*', '/', '(']
                # 则横杠数字不是负数
                if re.search('[\+\-\*\/\(]$', final_formula[-1]):
                    final_formula.append(item)
                    continue
            # 按照运算符分割开
            item_split = [i for i in re.split('([\+\-\*\/\(\)])', item) if i]
            final_formula += item_split
        return final_formula
    
if __name__ == '__main__':
    calculator = Calculator()
    formula = input('请输入：\n')
    formula_list = Calculator.formula_format(formula)
    result, _ = calculator.final_calc(formula_list)
    print("计算结果：\n", result[0])
