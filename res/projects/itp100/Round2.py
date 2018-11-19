# I am importing the time function so that I measure how long
# it takes to fire 6 rounds.
import time


# I may end up trying to come up with a way to summon the program
# into this one so that I can have a much easier to understand code

# Defines the main function.
def main():
    
# I use fire to be a starting variable for the loop 
# 6 shots need to fired, thus I set index equal 0 
    print ('ROUND 2 - WONDERING LEE ROY')
    print ('----------------------------------------------------')
    print ('You know the drill fire all 6 shots by hitting the right keys')
    print ('or you will draw your second pistol and probably die.')
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
                fire = input('Press 1 to Fire ')
                if fire == '1':
                    index += 1
                fire = input ('Press 6 to Fire ')
                if fire == '6':
                    index += 1
                fire = input ("Press h to Fire ")
                if fire == 'h':
                    index += 1
                fire = input ('Press m to Fire ')
                if fire == 'm':
                    index += 1
                fire = input ('Press ? to Fire ')
                if fire == '?':
                    index += 1
                fire = input ('Press z to Fire ')
                if fire == 'z':
                    index += 1
                end_time = time.time() - start_time
            

            if end_time > 8:
                print("Wondering Lee Roy Motorally Wounded you but you didn't die. \n"
                      "He said he never seen anyone so bold \n"
                      "so you join his gang to stop a common enemy Dasterdly Dan!")
                
            else:
                print('You won the showdown!! The town made you sharif but you promised to kill \n'
                      'Dasterdly Dan.')
    
       
        
    else:
        print("Your opponet laughs and spares you because you can't draw your gun and you made him laugh. \n"
              "So he asks for you to join his gang and you do.")

        
main()
