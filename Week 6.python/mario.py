while True:
    try:
        height = int(input("Height: "))
        if height >= 1 and height <= 8:
            break
    except ValueError:
        continue

for i in range(height):
    for space in range(height - i - 1):
        print(" ", end="")
    for hash in range(i + 1):
        print("#", end="")

    print("  ", end="")

    for hash in range(i+1):
        print("#", end="")
    print("")