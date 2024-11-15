while True:
    try:
        a, b = map(int, input().split())
        print(a + b)
    except EOFError:
        break

"""
import sys

for line in sys.stdin:
    x = line.split()
    print(int(x[0]) + int(x[1]))
"""

"""
import sys

for line in sys.stdin:
    a, b = map(int, line.split())
    print(a + b)
"""