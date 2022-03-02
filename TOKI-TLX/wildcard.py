word = input()
position = word.find('*')
letak = int()

if(position == 0):
    if(len(word) == 1):
        letak = 0
    else:
        letak = 1
elif(position == len(word)-1):
    letak = 2
else:
    letak = 3

word = word.replace('*', '')
n = int(input())

for i in range(n):
    m = input()
    sear = m.find(word)
    if(letak == 0):
        print(m)
    elif(letak == 1 and sear == len(m)-len(word)):
        print(m)
    elif(letak == 2 and sear == 0):
        print(m)
    elif(letak == 3 and sear > 0 and sear < len(m)-len(word)):
        print(m)