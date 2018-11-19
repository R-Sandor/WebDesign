# I am importing the time function so that I measure how long
# it takes to fire 6 rounds.
import time
import GUI
import Round1
import Round2
# I may end up trying to come up with a way to summon the program
# into this one so that I can have a much easier to understand code

# Defines the main function.
def main():
    
# I use fire to be a starting variable for the loop 
# 6 shots need to fired, thus I set index equal 0 
    print ('')
    print ('ROUND 3 - Dastardly Dan')
    print ('---------------------------------------------------------')
    print ('Good luck Dastardly Dan is fast and dangerous.')
    print ('Your using your good pistol so you will have chance.')
    print ('---------------------------------------------------------')
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
            

            if end_time > 2:
                print("Dastardly Dan gunned you down but you won't be forgoten. Thanks for playing!")
                
            else:
                print('You won took out the most infamous person around! Thank you!')
    
       
        
    else:
        print("He drew faster and shot you as you strugled to draw.")

        
main()

