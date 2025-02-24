# 1. Create a new string by concatenating string a and string b
string_a = "This is"
string_b = " the way!"
new_string = string_a + string_b
print(new_string)


# 2. Create a lower case version of the following string (Hint: take a look at the string documentation for str.lower())
input_string = 'This Is The String'
lowercase_string = input_string.lower()
print(lowercase_string)


# 3. Create an upper case version of the following string
input_string = 'This Is The String'
uppercase_string = input_string.upper()
print(uppercase_string)


# 4. Does the string start with an 'S'?
string = 'Begin at once'
result = string == string.capitalize()
print(result)


# 5. Does the string end with a '.'?
string = 'The end.'
result = string.endswith(".")
print(result)


# 6. Find the index of the first instance of 'and' (Hint: see str.find())
string = '"Tell me and I forget. Teach me and I remember. Involve me and I learn." -Benjamin Franklin'
index = string.find("and")
print('Index:', index)
print('Content:', string[index:index+3])


# 7. Split the string at each comma into several strings in a list (Hint: str.split())
string = 'apples,bananas,cherries,dates'
fruit_list = string.split(",")
for fruit in fruit_list:
    print('Fruit:', fruit)


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
print('The area of a rectangle with sides {} and {} is {}'.format(side_a, side_b, area))

 

# 11 Print out the number of apples and oranges in a string using string formatting
basket = { 'apples': 10, 'oranges': 2 }
summary = "There are {} apples and {} oranges.".format(basket['apples'], basket['oranges'])
print(summary)


# 12. Print out the quote inserting the strings in its respective places using string formatting.
name = 'Sir Lancelot of Camelot'
quest = 'To seek the Holy Grail'
favourite_colour = 'Blue'

quote = '''
Bridgekeeper: What is your name?
Lancelot: My name is {}.
Bridgekeeper: What is your quest?
Lancelot: {}.
Bridgekeeper: What is your favourite colour?
Lancelot: {}.
Bridgekeeper: Right. Off you go.
'''
print(quote.format(name,quest,favourite_colour))


# 13. Do the same thing as last exercise but ask for user input for the answers
name = input("Enter a name:")
quest = input("Enter a quest:")
favourite_colour = input("Enter a color:")

quote = '''
Bridgekeeper: What is your name?
Lancelot: My name is {}.
Bridgekeeper: What is your quest?
Lancelot: {}.
Bridgekeeper: What is your favourite colour?
Lancelot: {}.
Bridgekeeper: Right. Off you go.
'''
print(quote.format(name,quest,favourite_colour))

 

# 14. Take a number between 0 and 9999 as an input from the user, write a
#     program which writes the number of digits in the number.
number = int(input('Enter a number between 0 and 9999: '))
print(len(str(number)))

 

# 15. Add error handling for entering an index which is not in the list by
#     printing out 'Invalid index'
fruits = ['apples', 'bananas', 'cherries', 'dates']
index = int(input('Enter fruit index: '))
if index <= 3:
  print('You chose {}'.format(fruits[index]))
else:
  print("Invalid index")

 

# 16. Add error handling for entering an index which is not in the list or not an integer
fruits = ['apples', 'bananas', 'cherries', 'dates']
try:
  index = int(input('Enter fruit index: '))
  if index >= 0 and index <= 3:
    print('You chose {}'.format(fruits[index]))
  else: 
    ValueError
except ValueError:
  print(ValueError)  

 

# 17. Let the user choose a number, print out the numbers from 1 to that chosen number.
number = int(input('Enter number: '))
for i in range(1, number):
  print(i)

 

# 18. Print out the item and the number of items in basket on separate lines using a for-loop
basket = { 'apples': 10, 'oranges': 2 }
for v in basket:
  print(v)

 

# 19. Sum the values in the list. Verify the value using sum().
number_list = [34, 23, 5, 61, 12, 14, 4]
sum_of_list = 0
for v in number_list:
  sum_of_list += v
print('The sum is:', sum_of_list)
print('The sum should be:', sum(number_list))

 

# 20. Use a while loop to write a program where the user can enter numbers and add
#     each of them to a list. If the user enters a non-integer then print out the
#     sum of the list and exit.
number_list = []
temp:str = "1"
while temp.isnumeric():
  temp = input("Enter some text.\nInput: ")
  number_list.append(int(temp))

print('The sum of the numbers is:', sum(number_list))

 

# 21. Add a function print_small_values() to the previous exercise which finds
#     all values less than 10 and prints them out.

number_list = []
while temp.isnumeric():
  temp = input("Enter some text.\nInput: ")
  number_list.append(int(temp))
  
def print_small_values(_list:list):
  for v in _list:
    if v < 10:
      print(v)

print('The sum of the numbers is:', sum(number_list))
print_small_values(number_list)

 

# 22. Add a store_values() function to the previous exercise which stores each
#     value in a file called "values.txt" with one number per line. Then call
#     store_values at the end of the program.
def store_values(_list:list):
  f = open("./public/values.temp", "w")
  for v in _list:
    f.write(v)
  f.close() 

# 23. Add a load_values() function to the previous exercise which loads the values
#     and returns the list. At the start of the program initialize number_list using this function.
def load_value(_path:str):
  temp = []
  f = open("./public/"+_path, "r")
  data = f.readline
  while data != "":
    temp.append(data)
    data = f.readline
  f.close()
  return temp

# 24 a) Use a while loop to create a menu system where a user can either add items, remove items, list items or quit.
actions = ["add", "remove", "show", "quit"]
items = []

user_input:str = ""
while user_input != actions[3]:
  user_input = input("Menu: {}, {}, {}, {}".format(actions[0],actions[1],actions[2],actions[3]))
  
  if user_input == actions[0]:
    user_input = input("Item: ")
    items.append(user_input)
  elif user_input == actions[1]:
    user_input = input("Item: ")
    items.remove(user_input)
  elif user_input == actions[2]:
    print(items)
user_input:str = ""
    
# Example usage:
# 
# $ python3 menu.py
# 
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

# 24 b) Load list from a file on startup and store all changes to the file

store_values(number_list)
