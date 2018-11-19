import time

def main():
    index = 1
    count = 0
    draw = input('Hit the key D to Draw ')
    
    if draw == 'd':
        start_time=time.time()
        fire = 'f'
        if fire == 'f':
            while index != 0:
                index += 1
                count += 1
                fire = input('FIRE!')
                end_time = time.time() - start_time
                
                if count == 5: index = 0
            
        if end_time > 5:
            print('Dirty Joe killed you')
            index -= 1
        else:
            print('You Won, Ready for round two')
            index = 0

        
main()
