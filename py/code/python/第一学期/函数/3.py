def isprime(m):
    if m == 1:
        return False
    for i in range(2, m):
        if m % i == 0:
            return False
    return True


def reversenumber(m):
    m = str(m)
    a = m[::-1]
    a = int(a)
    return a
