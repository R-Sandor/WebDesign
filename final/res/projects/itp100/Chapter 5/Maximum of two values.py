# Define the function of Max
# This program determines which number is larger
def max():
    again = 'y'
    while again == 'y' or again == 'Y':
        print ('This program Calculates the maximum of two numbers')
        first_number = int(input('Enter first number: '))

    #Get second Number
        second_number = int(input('Enter second number: '))

    #Determine which number is grater
        biggernum = bigger(first_number, second_number)

    #Display the bigger number
        print('The bigger number is', biggernum)
        again = input('Would you like to Calculate another maximum again? (y = yes): ')
def bigger (num1, num2):
    if num1 > num2:
        result = num1
        return result
    elif num2> num1:
        result = num2
        return result
    
#Call max
max()
