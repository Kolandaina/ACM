def can_hit_ball(l, x):
    if 0 <= x <= l:
        return "存在支点"
    else:
        return "不存在支点"

# 测试例子
l = 5
x, y = 3, 4
print(can_hit_ball(l, x))  # 输出：存在支点

x, y = 6, 2
print(can_hit_ball(l, x))  # 输出：不存在支点
