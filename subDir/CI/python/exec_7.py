
import re


def find_number(_input:str, _verbal:bool = False):
  if _verbal:
    print("Input: \"{}\"".format(_input))
    print("(1 to 3 digits max.)")
  
  temp = []
  for token in _input.split():
      try:
          number = int(token)
          if (len(token) <= 3 and len(token) >= 1):
            temp.append(number)
          
      except ValueError:
          # print(token, "is something else")
          pass
  if _verbal:    
    print("Output: {}".format(temp))
  return temp


def verify_IPADRESS_V4(_input:str, _verbal:bool = False):
  if _verbal:
    print("Input: \"{}\"".format(_input))
    print("(XXX.XXX.XXX.XXX)")
  
  temp = []
  for token in _input.split("."):
      try:
          number = int(token)
          if (len(token) <= 3 and len(token) >= 1 and number <= 255 and number >= 0):
            temp.append(number)
          
      except ValueError:
          # print(token, "is something else")
          pass
  if _verbal:
    print("Output: {}".format(temp))
  return len(temp) == 4


def STRING_UNDERSCORE(_input:str, _verbal:bool = False):
  if _verbal:
    print("Input: \"{}\"".format(_input))
    print("(\"TEMP_TEXT\" ⇆ \"TEMP TEXT\")")

  temp:str = ""
  if _input.find("_") == -1:
    temp = _input.replace(" ", "_")
  else: 
    temp = _input.replace("_", " ")
        
  if _verbal:
    print("Output: {}".format(temp))
  return temp


def DATE_FORMAT_US_TO_SWE(_input:str, _verbal:bool = False):
  if _verbal:
    print("Input: \"{}\"".format(_input))
    print("(YYYY-MM-DD -> DD/MM/YYYY)")

  temp = []
  iterator = 0
  for token in _input.split("-"):
      try:
          number = int(token)
          iterator += 1
          if iterator == 1 and len(token) == 4:
            temp.append(number)
          elif iterator == 2 and len(token) == 2:
            temp.append(number)
          elif iterator == 3 and len(token) == 2:
            temp.append(number)
          else:
            break
          
      except ValueError:
          # print(token, "is something else")
          pass
        
  if _verbal:
    print("Output: {}".format(temp))
  return "{:02}/{:02}/{}".format(temp[2], temp[1], temp[0])


def AEEAAAEEAEE(_input:str, _verbal:bool = False):
  if _verbal:
    print("Input: \"{}\"".format(_input))
    print("(EXAMPLE TEXT APP -> EXAMPLE, APP)")

  temp = []
  for token in _input.split():
    if (token.casefold()[0] == 'e' or token.casefold()[0] == 'a'):
      temp.append(token)
          
        
  if _verbal:
    print("Output: {}".format(temp))
  return temp


user_input = "Current Level: 123 db, 72 db, 6 db, 1234 db"
print(find_number(user_input))

print(verify_IPADRESS_V4("192.168.1.69"))
print(verify_IPADRESS_V4("192.168.1.692"))

print(STRING_UNDERSCORE("String_yo_fumo"))
print(STRING_UNDERSCORE("Fumo no string yo"))

print(DATE_FORMAT_US_TO_SWE("2024-02-31"))

print(AEEAAAEEAEE("Test ex app poor pap Embart"))