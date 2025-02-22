def search(string: str):
    r_numbers = string.split(" ")
    numbers = []
    for item in r_numbers:
        if item.strip().isdigit():
            counter = 0
            for digit in item:
                counter += 1
            if counter <= 3:
                numbers.append(item)
    return numbers


def valid_part(string: str):
    status = False
    n = len(string)

    if n > 3:
        pass
    else:
        for i in range(n):
            if string[i].isdigit():
                status = True

    if status == True:
        x = int(string)
        if 0 <= x <= 255:
            status = True
        else:
            status = False

    return status


def validate_ip_v4(ip: str):
    status = True

    if ip is None:
        status = False
    else:
        parts = ip.split(".")
        count = 0

        for i in range(len(ip)):
            if ip[i] == ".":
                count += 1

        if count != 3:
            status = False
        else:
            for part in parts:
                if not valid_part(part):
                    status = False
                else:
                    status = True

    return status


def change(string: str):
    result = ""
    for ch in string:
        if ch == " ":
            result += "_"
        elif ch == "_":
            result += " "
        else:
            result += ch
    return result


def validate_date(date: str):
    """
    Enter a date in yyyy-mm-dd format
    """

    days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    c_date = date.split("-")

    check = False
    for c_check in c_date:
        if c_check.strip().isdigit():
            check = True

    good_date = False
    if check:
        for item in range(len(c_date)):
            c_date[item] = int(c_date[item])

        if (c_date[0] % 400 == 0) and (c_date[0] % 100 == 0):
            days[1] = 29

        if c_date[0] > 0 and c_date[1] > 0 and c_date[1] < 12:
            if c_date[-1] < days[c_date[1]] and c_date[-1] > 0:
                good_date = True

    return_date = ""
    if good_date:
        for item in range(len(c_date)):
            return_date += str(c_date[item])
            if item != len(c_date) - 1:
                return_date += "-"

    return return_date


def find_all_words(string: str):
    """
    Find all words starting with 'a' or 'e'
    """
    
    list_of_words = string.split(' ')
    return_list_of_words = []
    
    for word in list_of_words:
        if word[0].lower() == 'a' or word[0].lower() == 'e':
            return_list_of_words.append(word)
            
    return return_list_of_words
            


string = "Hello Elon My World 10 20 300 4000 All ello anna"
print(search(string))

ip = "125.512.100.10"
print("Valid" if validate_ip_v4(ip) else "Not valid")

print(change(string))

date = "2025-2-19"
print("Date before validation: ", date)
print("Date after Validation: ", validate_date(date))

print(find_all_words(string))