import pandas as pd

rainbow = pd.read_csv("rainbow.csv")
pas= rainbow.to_dict()["Password"]
sha_1 = rainbow.to_dict()["SHA-1"]
sha_256 = rainbow.to_dict()["SHA-256"]
md5 = rainbow.to_dict()["MD5"]

inp = input("Enter the hash: ")

output_idx = 0
for key, val in sha_1.items():
    if val == inp:
        output_idx = key
        break

for key, val in sha_256.items():
    if val == inp:
        output_idx = key
        break

for key, val in md5.items():
    if val == inp:
        output_idx = key
        break

print(f"Output = {pas[output_idx]}")