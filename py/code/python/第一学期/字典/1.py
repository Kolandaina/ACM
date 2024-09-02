digit = list(input())
word = {}
for i in digit:
    if i in word:
        word[i] += 1
    else:
        word[i] = 1
print(word)
