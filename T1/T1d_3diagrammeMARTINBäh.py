
n = int(input("Natürliche Zahl größer gleich 1: "))
strichzeile = 0
pluszeile = 0
# erste pluszeile
for j in [0,1]:
    print("+", end="")
    i = 1 
    while i <= n:
        print("-", end="")
        i += 1
    print("+")

    pluszeile += 1

    if pluszeile != 2:
        while strichzeile != n:
            print("|", end="")
            i= 1
            while i <= n:
                print(" ", end="")
                i += 1
                
                
            print("|")
            strichzeile += 1


    