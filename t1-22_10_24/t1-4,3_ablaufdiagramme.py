

# n = int(input("Natürliche Zahl größer gleich 1: "))

# print()

# x = 0
# print("+", end="")
# while x != n:
#     print("-", end="")
#     x += 1
# print("+", end="")

# y = 0
# while y != n:
#     print("")

#     print("|", end="")
#     z = 0
#     while z != n:
#         print(" ", end="")
#         z += 1
#     print("|", end="")
#     y += 1
# print("")

# x = 0
# print("+", end="")
# while x != n:
#     print("-", end="")
#     x += 1
# print("+", end="")


n = int(input("Natürliche Zahl größer gleich 1: "))
zweiterDurchlauf = False


for i in range(2):
    x = 0
    print("+", end="")
    while x != n:
        print("-", end="")
        x += 1
    print("+", end="")

    if not zweiterDurchlauf:
        y = 0
        while y != n:
            print()

            print("|", end="")
            z = 0
            while z != n:
                print(" ", end="")
                z += 1
            print("|", end="")
            y += 1
        print("")
        zweiterDurchlauf = True