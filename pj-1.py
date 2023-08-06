def task(string):
    val=len(string)
    space=int(val)
    rev=string[::-1]
    reval=2

    for i in range(0,val):
        if i < val//2:
            print(' '*(i)+string[i]+' '*(space-2)+rev[i])
            space-=2
        elif i == val//2:
            print(' '*i+string[i])
        elif i > val//2:
            print(' '*(i-reval)+rev[i]+' '*(space)+string[i])
            reval+=2
            space+=2

    choice = input("Do you wish to try again (y/n):")
    if choice == 'y':
        start()
    else:
        exit()    

def start():
    string=input("Enter a string of odd length:")
    if len(string)%2 !=1:
        print("Invalid string length restarting the program")
        print('---- X --- X --- X ----')
        start()
    else:
         task(string)        

start()


