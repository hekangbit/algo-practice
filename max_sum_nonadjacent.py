
arr = [1, 2, 4, 1, 7, 8, 3]

def dp_opt(arr):
    opt = []
    for i in range(len(arr)):
        opt.append(0)

    opt[0] = arr[0]
    opt[1] = max(arr[0], arr[1])

    for i in range(2, len(arr)):
        a = opt[i - 2] + arr[i]
        b = opt[i - 1]
        opt[i] = max(a, b)

    return opt[len(arr) - 1]


res = dp_opt(arr)
print(res)