def sum_func(*args):
    n = len(args)
    m = 0
    for i in range(n):
        m += args[i]
    return m
