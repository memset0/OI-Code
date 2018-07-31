# file = open("T36196.txt", "w+")
n = int(input())
ans = 1
for i in range(1, n + 1):
    ans *= i
print ans
