stack = []
n = int(input())

for _ in range(n):
    op = input()
    if op[0:4] == 'push':
        x = op.split(' ')
        stack.append(x[1])
    elif len(stack) == 0:
        print('error')
    else:
        print(stack[-1])
        if op == 'pop': 
            stack.pop()