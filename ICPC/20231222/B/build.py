import random

# 生成随机数
def random_num():
    return random.randint(-1000, 999)

# 生成坐标点
def random_point():
    return str(random_num()) + " " + str(random_num())

print(random_point()+" "+random_point())