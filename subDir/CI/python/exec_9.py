import json

f = open("./public/data.json", "r")
message = json.load(f)
f.close()

print("{:<32} | {:<8} | {:^6} | {:<}\n{}".format("Signal", "Type", "Length", "Description", "-"*96))
for i in message["signals"]:
    print("{:<32} | {:<8} | {:>6} | {:<}".format(i["name"], i["type"], i["length"],i["comment"]))
    