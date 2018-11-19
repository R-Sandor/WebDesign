#This program saves numbers to a file then opens the file
#Adds up the numbers and gives an average

def main():
    #This program will also handle all errors
    try:
        HowManyNumbers = int(input('How many numbers would you like to average: '))
        numbersfile = open('numbers.txt', 'w')
        for count in range (1, HowManyNumbers + 1):
            numbers = float(input('Enter #'  + \
                                  str(count) + ': '))
        
            numbersfile.write(str(numbers)+'\n')
        numbersfile.close()
        print('Data written to numbers.txt')
        ave()
    except IOError:
        print('An error occured while trying to find the file')
        print('Make sure the file exist')
    except ValueError:
        print('ERROR: This program only excepts numbers characters.')
        print('Anything that is not a number character will return this error.')
    except:
        print('An error Occured.')

def ave():
    numbersfile = open('numbers.txt', 'r')
    total = 0
    count = 0
    for line in numbersfile:
        numbers = float(line)
        count += 1
        total += numbers
        ave = total / count
    numbersfile.close()
    print ('total of numbers is', total) 
    print ('and the average of you numbers is', ave)

    
main()
