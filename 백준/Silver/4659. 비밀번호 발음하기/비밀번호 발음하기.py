from collections import deque

def checkingm(s):
    return s in 'aeiou'

def moeum(ss):
    answer = False
    for i in ss:
        if checkingm(i):
            answer = True
    return answer

def three(ss):
    if len(ss) < 3 :
        return True
    for i in range(len(ss)-2):
        first = checkingm(ss[i])
        second = checkingm(ss[i+1])
        third = checkingm(ss[i+2])
        if first == second == third:
            return False
    return True

def two(ss):
    for i in range(len(ss)):
        if ss[i] != 'e' and ss[i] != 'o':
            if(i+1 < len(ss)):
                if ss[i] == ss[i+1]:
                    return False
    return True            
    

while 1:
    ss = input()
    if ss == "end":
        exit(0)
    if moeum(ss) is False:
        print(f"<{ss}> is not acceptable.")
        continue

    if three(ss) is False:
        print(f"<{ss}> is not acceptable.")
        continue 

    if two(ss) is False:
        print(f"<{ss}> is not acceptable.")
        continue 
    print(f"<{ss}> is acceptable.")

    

    

