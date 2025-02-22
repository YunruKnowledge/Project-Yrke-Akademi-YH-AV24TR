number = int(input("Input a number grater than 0: "))

if number > 0:
    factorial = 1
    while number != 0:
        factorial *= number
        number -= 1
    else:
        print("Your number in factorial is: {}".format(factorial))
else:
    print("number must be grater than 0!")