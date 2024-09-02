s = input()
words = [ss for ss in s.split()]
lt = [len(word) for word in words]
maxlen = max(lt)
maxword = words[lt.index(maxlen)]
print("最长单词是{}，长度是{}。".format(maxword, maxlen))
