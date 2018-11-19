#Tell user to enter a series of Positive numbers
print ('Enter a series of postive numbers.')
print ('To end enter a negative number.')
num= float (input(''))  #Gets input for a number
num1= num   #Sets this number equal to num1 
while num and num1 >= 0:    #States that num and num1 must greater than 0
    num1 = float(input('')) #for the following to happen
    num = num + num1        #num = num + num1
    total = num - num1      #when a negative is typed to end the program it 
else: print (total)
                            #it will subtract from the num so you have t
                            #minus from a minus (+)
                            #else comands states that if it isnt num > 0
                            #print total
