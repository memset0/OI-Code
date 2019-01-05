n = int(raw_input())
ans = 0
t = 1
for i in range(1, n + 1):
    t = t * i
    ans = ans + t
print ans
