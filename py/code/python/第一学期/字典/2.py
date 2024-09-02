dic = {'admin': '123456',
       'administrator': '12345678',
       'root': 'password'
       }
n = 3
while n:
    yh = input()
    mm = input()
    if yh in dic:
        if dic[yh] == mm:
            print("登录成功")
            break
        else:
            print("登录失败")
    else:
        print("登录失败")
    n -= 1
