# I am importing the time function so that I measure how long
# it takes to fire 6 rounds.
import time
# I may end up trying to come up with a way to summon the program
# into this one so that I can have a much easier to understand code

# Defines the main function.
def main():
    
# x is used as a way to end the loop for when all
# 6 shots are fired, thus I set equal to 0 
   
    draw = input('Hit the key D to Draw ')
    if draw == 'd':
        start_time=time.time()
        fire = 'f'
        if fire == 'f':
            for index in range(5):
                index += 1
                fire = input('FIRE!')
                end_time = time.time() - start_time

            if end_time > 5:
                print('Dirty Joe killed you')
            else:
                print('You Won, Ready for round two')

        
main()
