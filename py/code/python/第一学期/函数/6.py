def count_digit(mun, dit):
    mun = str(mun)
    m = 0
    n = len(mun)
    for i in range(n):
        if mun[i] == str(dit):
            m += 1
    return m
