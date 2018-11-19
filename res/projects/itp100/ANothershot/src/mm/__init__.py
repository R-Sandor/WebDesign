# I am importing the time function so that I measure how long
# it takes to fire 6 rounds.
import time


# Defines the main function.
def main():
    
# I use fire to be a starting variable for the loop 
# 6 shots need to fired, thus I set index equal 0 
    print ('ROUND1 - DIRTY JOE')
    print ('----------------------------------------------------')
    print ('You must fire all 6 shots by hitting the right keys')
    print ('or you will draw your second pistol and probably die')
    print ('-----------------------------------------------------')
    print ('')
    draw = input('Hit the key D to Draw ')
    if draw.lower() == 'd':
        start_time=time.time()
        fire = 'f'
        if fire == 'f':
            index = 0
            while index < 6:

            # While the index is less than 6 the fire is used as a way to justify that
            # the right key is entered and when it is entered it adds one to the index
                fire = input('Press Q to Fire ')
                if fire == 'q':
                    index += 1
                fire = input ('Press W to Fire ')
                if fire == 'w':
                    index += 1
                fire = input ('Press E to Fire ')
                if fire == 'e':
                    index += 1
                fire = input ('Press R to Fire ')
                if fire == 'r':
                    index += 1
                fire = input ('Press T to Fire ')
                if fire == 't':
                    index += 1
                fire = input ('Press Y to Fire ')
                if fire == 'y':
                    index += 1
                end_time = time.time() - start_time
            

            if end_time > 16:
                print("Dirty Joe shot you but you didn't die. \n"
                      "You gotta be faster to kill Wondering Lee Roy")
                
            else:
                print('You Won, Ready for round two')
    
       
        
    else:
        print("Shot the gun out right of your hand because you didn't hit the right key")

        
main()
