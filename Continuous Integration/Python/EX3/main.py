count = 0
string = str(input("Input a string: "))
for i in range(0, len(string)):
    if string[i].isupper():
        count += 1

print("there are {} uppercase letters in your string".format(count))