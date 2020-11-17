n = int(input())
words = []
for i in range(n):
    s = input()
    words.append(s[::-1])
words.sort()

for w in words:
    print(w[::-1])
