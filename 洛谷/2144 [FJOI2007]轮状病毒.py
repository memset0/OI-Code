def locate(x):
    a = [1, 3]
    for i in range(2, x):
        a.append(a[-1] + a[-2])
    # print(a)
    return a[x - 1]

def solve(x):
    t = locate(x)
    if x % 2 == 1:
        return t ** 2
    else:
        return t ** 2 - 4

for i in range(1, 101):
    print('ans[%d] = "%d";' % (i, solve(i)))
