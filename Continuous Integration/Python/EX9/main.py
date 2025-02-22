import json

with open("data.json", "r") as f:
    data = json.load(f)
    
name_longest = max(data["signals"], key=lambda x: len(x["name"]))["name"]
type_longest = max(data["signals"], key=lambda x: len(x["type"]))["type"]
length_longest = max(data["signals"], key=lambda x: len(str(x["length"])))["length"]
comment_longest = max(data["signals"], key=lambda x: len(x["comment"]))["comment"]

name_count = len(name_longest)
type_count = len(type_longest)
length_count = len(str(length_longest))  
comment_count = len(comment_longest)
    
# print("{:<30} | {:<10} | {:<5} | {}".format("Name", "Type", "Length", "Comment"))
print(f"{'Signal':<{name_count}} | {'Type':<{type_count}} | {'Length':<{length_count + len('length')}} | {'Description':<{comment_count}}")
print((name_count + type_count + length_count + comment_count + 30) * "-")
for item in data["signals"]:
    # print("{:<30} | {:<10} |  {:<5} | {}".format(item["name"], item["type"], item["length"], item["comment"]))
    print(f"{item['name']:<{name_count}} | {item['type']:<{type_count}} | {item['length']:<{length_count + (len('length'))}} | {item['comment']:<{comment_count}}")