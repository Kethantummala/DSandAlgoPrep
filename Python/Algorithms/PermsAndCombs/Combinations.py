s=input("Enter a string to get all its combinations:")

s="abcd"

for count in range(1,len(s)):
    for j in range(len(s)-(count-1)):
        add_s=""
        if((j+count)>len(s)):
            add_s=s[0]
        print("count:",count,s[j:j+count]+add_s)
