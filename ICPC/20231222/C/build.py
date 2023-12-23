import random

#生成10^18以内的整数

def gen():
    return random.randint(0, 10 ** 18)

n = 10 ** 5
print(n)
for i in range(n):
    print(gen(), gen())

