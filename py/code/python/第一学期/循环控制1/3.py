n = int(input())
guo = 100 * 1.001 ** n
if n <= 3:
    print("{:.5f},{:.5f}".format(guo, 100*1.002**n))
elif 3 < n <= 5:
    print("{:.5f},{:.5f}".format(guo, 100*1.002**3*0.999**(n-3)))
elif n % 5 == 0:
    print("{:.5f},{:.5f}".format(guo, 100*1.002**(3*n//5)*0.999**(2*n//5)))
elif n % 5 > 3:
    print("{:.5f},{:.5f}".format(guo, 100*1.02**(3*n//5+1)*0.999**(2*n//5+1)))
elif n % 5 == 3:
    print("{:.5f},{:.5f}".format(guo, 100*1.02**(3*n//5+1)*0.999**(2*n//5)))
elif n % 5 < 3:
    print("{:.5f},{:.5f}".format(guo, 100*1.02**(3*n//5+n % 5)*0.999**(2*n//5)))
