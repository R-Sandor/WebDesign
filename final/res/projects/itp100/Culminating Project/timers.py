# I am importing the time function so that I measure how long
# it takes to fire 6 rounds.
import time

# I may end up trying to come up with a way to summon the program
# into this one so that I can have a much easier to understand code
import Graphicaluserinterface

# Defines the main function.
def main():
    if end_time > 5:
        print('Dirty Joe killed you')
    else:
        print('You Won, Ready for round two')
    
# x is used as a way to end the loop for when all
# 6 shots are fired, thus I set equal to 0 
    
    def draw(fire):
        x = 0
        while x < 200 :
            draw = input('Hit the key D to Draw ')
            if draw == 'd':
                start_time=time.time()

        def fire(end_time):
            x = 0
            fire = input('Hit F to fire')
            if fire == 'f':
                for index in range(5):
                    index += 1
                    fire = input('FIRE!')
                    end_time = time.time() - start_time
                    x += 200
                    return x
                    return end_time

            

        
main()
