def checkCard(number):
    sum_array = 0

    for i in range(len(number) - 2, -1, -2):
        double = int(number[i]) * 2
        if double > 9:
            sum_array += double // 10 + double % 10
        else:
            sum_array += double

    for i in range(len(number) - 1, -1, -2):
        sum_array += int(number[i])

    return sum_array % 10 == 0

def main():

    number = input("Number: ").strip()
    if number.isdigit():
        if checkCard(number):
            if len(number) == 15 and (number[:2] == "34" or number[:2] == "37"):
                print("AMEX")
            elif len(number) == 16 and number[:2] in ["51", "52", "53", "54", "55"]:
                print("MASTERCARD")
            elif (len(number) == 13 or len(number) == 16) and number[0] == "4":
                print("VISA")
            else:
                print("INVALID")
        else:
            print("INVALID")
    else:
        print("INVALID")  # Se o input não for um número


main()