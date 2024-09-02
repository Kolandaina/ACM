def isflower(n):
    x = n // 100
    y = (n-x*100) // 10
    z = n-x*100-y*10
    if n == x ** 3 + y ** 3 + z ** 3:
        return True
    else:
        return False
