from typing import Counter


s = input("Enter String: ")
c = Counter(s)
print("Character Frequency: ")
for i in c:
    print(f"{i}, {c[i]}")
