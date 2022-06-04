s=input("Enter a string to get all its permutations:")

s="abcdef"

def perm(s,selected_substr):
    if(len(s)==0):
        print(selected_substr)
    for i in range(len(s)):
        new_s=s[0:i]+s[i+1:]
        perm(new_s,selected_substr+s[i])

perm(s,"")