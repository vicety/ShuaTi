strori = input()
strano = input()
lori = {}
case = {}
for i in range(26):
    lori[strori[i]] = strano[i]
string = input()
ans = ''
for i in range(len(string)):
    if string[i].isdigit():
        ans+=string[i]
    else:
        low = string[i].lower()
        ans+=lori[low].upper() if string[i].isupper() else lori[low]
print(ans)