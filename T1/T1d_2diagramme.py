from re import I


n = int(input("Natürliche Zahl größer gleich 1: "))
i = 1
while i <= n:
    j = i
    while j > 0:
        print("*", end="")
        j -= 1
    print()
    i += 1 