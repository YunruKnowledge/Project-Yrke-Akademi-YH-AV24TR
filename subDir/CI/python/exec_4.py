import math

temp:str =""
while not temp.isnumeric():
  temp = input("Enter some text.\nInput: ")
temp = int(temp)
  
temp2 = 1
for i in range(1, temp+1):
  temp2 = temp2 * i

if temp > 0 :
  print(temp2)
  print(math.factorial(temp))

