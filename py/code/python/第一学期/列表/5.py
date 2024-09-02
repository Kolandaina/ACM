from random import*
mylist = []
for i in range(20):
    x = randint(1000, 5000)
    mylist.append(x)
mylist.sort(reverse=True)
count = 0
for x in mylist:
    if x % 2 == 0:
        count += 1
        print(x, end=" ")
        if count % 3 == 0:
            print()
