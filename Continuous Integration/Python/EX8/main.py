# 1. Create a new string by concatenating string a and string b
string_a = "This is"
string_b = " the way!"
new_string = string_a + " " + string_b
print(new_string)


# 2. Create a lower case version of the following string (Hint: take a look at the string documentation for str.lower())
input_string = "This Is The String"
lowercase_string = input_string.lower()
print(lowercase_string)


# 3. Create an upper case version of the following string
input_string = "This Is The String"
uppercase_string = input_string.upper()
print(uppercase_string)


# 4. Does the string start with an 'S'?
string = "Begin at once"
if string == "S":
    result = True
else:
    result = False

print(result)


# 5. Does the string end with a '.'?
string = "The end."
if string[-1] == ".":
    result = True
else:
    result = False
print(result)


# 6. Find the index of the first instance of 'and' (Hint: see str.find())
string = '"Tell me and I forget. Teach me and I remember. Involve me and I learn." -Benjamin Franklin'
index = string.find("and")
print("Index:", index)
print("Content:", string[index : index + 3])


# 7. Split the string at each comma into several strings in a list (Hint: str.split())
string = "apples,bananas,cherries,dates"
fruit_list = string.split(",")
for fruit in fruit_list:
    print("Fruit:", fruit)


# 8. Print out the number of items in the list
number_list = [45, 65, 2, 4, 10, 94, 23, 54, 2, 54]
list_length = len(number_list)
print(list_length)


# 9. Print out the number of characters in the string
quote = '"Whoever is happy will make others happy too." -Anne Frank'
quote_length = len(quote)
print(quote_length)


# 10 Print out the values using string formatting
side_a = 2
side_b = 6
area = side_a * side_b
print("The area of a rectangle with sides {} and {} is {}".format(side_a, side_b, area))


# 11 Print out the number of apples and oranges in a string using string formatting
basket = {"apples": 10, "oranges": 2}
summary = basket["apples"] + basket["oranges"]
print(summary)


# 12. Print out the quote inserting the strings in its respective places using string formatting.
name = "Sir Lancelot of Camelot"
quest = "To seek the Holy Grail"
favorite_colour = "Blue"

quote = """
Bridgekeeper: What is your name?
Lancelot: My name is {}.
Bridgekeeper: What is your quest?
Lancelot: {}.
Bridgekeeper: What is your favourite colour?
Lancelot: {}.
Bridgekeeper: Right. Off you go.
"""
print(quote.format(name, quest, favorite_colour))


# 13. Do the same thing as last exercise but ask for user input for the answers
name = input("Please enter your name: ")
quest = input("Please enter your quest: ")
favorite_colour = input("Please enter your favorite color: ")

quote = """
Bridgekeeper: What is your name?
Lancelot: My name is {}.
Bridgekeeper: What is your quest?
Lancelot: {}.
Bridgekeeper: What is your favorite colour?
Lancelot: {}.
Bridgekeeper: Right. Off you go.
"""
print(quote.format(name, quest, favorite_colour))


# 14. Take a number between 0 and 9999 as an input from the user, write a
#      program which writes the number of digits in the number.

number = int(input("Enter a number between 0 and 9999: "))
count = 0
for dig in str(number):
    count += 1
print("Number of digit is ", count)


# 15. Add error handling for entering an index which is not in the list by
#      printing out 'Invalid index'
fruits = ["apples", "bananas", "cherries", "dates"]
index = int(input("Enter fruit index: "))
if index < 0 or index >= len(fruits):
    print("Invalid Index!")
else:
    print("You chose {}".format(fruits[index]))


# 16. Add error handling for entering an index which is not in the list or not an integer
fruits = ["apples", "bananas", "cherries", "dates"]
index = int(input("Enter fruit index: "))
if index < 0 or index >= len(fruits):
    print("Invalid Index!")
else:
    print("You chose {}".format(fruits[index]))


# # 17. Let the user choose a number, print out the numbers from 1 to that chosen number.
number = int(input("Enter number: "))
count = 0
while count != number:
    print(count)
    count += 1


# # 18. Print out the item and the number of items in basket on separate lines using a for-loop
basket = {"apples": 10, "oranges": 2}
for fruit in basket.keys():
    print("There are {} {} in the basket".format(basket[fruit], fruit))


# # 19. Sum the values in the list. Verify the value using sum().
number_list = [34, 23, 5, 61, 12, 14, 4]
sum_of_list = 0
for index in range(len(number_list)):
    sum_of_list += number_list[index]
print("The sum is:", sum_of_list)
print("The sum should be:", sum(number_list))


# # 20. Use a while loop to write a program where the user can enter numbers and add
#       each of them to a list. If the user enters a non-integer then print out the
#       sum of the list and exit.
number_list = []
x = "45"
while x.strip().isdigit():
    x = input("Enter a number, or if you want to exit enter something else: ")
    if x.strip().isdigit():
        number_list.append(int(x))
    else:
        pass


result = 0
for index in range(len(number_list)):
    result += number_list[index]

print(result)
print("The sum of the numbers is:", sum(number_list))


# # 21. Add a function print_small_values() to the previous exercise which finds
#       all values less than 10 and prints them out.


def print_small_values(numbers):
    small_number = []
    for i in range(len(numbers)):
        if int(numbers[i]) < 10:
            small_number.append(int(numbers[i]))
        else:
            pass
    print(small_number)


print("The sum of the numbers is:", sum(number_list))
print_small_values(number_list)


# # 22. Add a store_values() function to the previous exercise which stores each
#       value in a file called "values.txt" with one number per line. Then call
#       store_values at the end of the program.
def store_values(numbers):
    with open("values.txt", "w") as f:
        for i in range(len(numbers)):
            f.write(str(numbers[i]) + "\n")


store_values(number_list)


# # 23. Add a load_values() function to the previous exercise which loads the values
#       and returns the list. At the start of the program initialize number_list using this function.
def load_values():
    read_numbers = []
    with open("values.txt", "r") as f:
        lines = f.readlines()
    read_numbers = [int(line.strip()) for line in lines]
    return read_numbers


number_list = load_values()
print(number_list)


# # 24 a) Use a while loop to create a menu system where a user can either add items, remove items, list items or quit.

# Example usage:

# $ python3 menu.py

# List handler menu. Actions: add, remove, show, quit
# > add
# Item: apples
# Item "apples" added
# > show
# apples
# > remove
# Item: apples
# Item "apples" removed
# > show
# > quit
# <exit>

def display_menu():
    menu = "MENU"
    print(20 * "-")
    print(menu.center(20))
    print(20 * "-")
    print("--> add")
    print("--> show")
    print("--> remove")
    print("--> quit")
    print(20 * "-")

def write_to_file(item_list):
    with open("items.txt", "w") as f:
        for i in range(len(item_list)):
            f.write(str(item_list[i]) + "\n")
        
def read_from_file():
    with open("items.txt", "r") as f:
        lines = f.readlines()
    show_items = [line for line in lines]
    print([line.removesuffix('\n') for line in lines])
        
item_list = []
while True:
    display_menu()
    _input = input("Enter command: ")
    if _input == "add":
        _input = input("Enter item you want to input: ")
        item_list.append(_input)
        write_to_file(item_list)
    elif _input == "show":
        read_from_file()
    elif _input == "remove":
        _input = input("Enter item you want to remove: ")
        if _input in item_list:
            item_list.remove(_input)
            write_to_file(item_list)
        else:
            print("Item {} not found in the list".format(_input))
    elif _input == "quit":
        break
    else:
        print("Wrong input! Try again")
    
    
# 24 b) Load list from a file on startup and store all changes to the file
