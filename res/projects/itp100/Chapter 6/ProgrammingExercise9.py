def main():
    try:
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
    except IOError:
        print('An error occured while trying to the file')
        print('Make sure the file exist')
    except ValueError:
        print('ERROR: This program only excepts numbers characters.')
        print('Anything that is not a number character will return this error.')
    except:
        print('An error Occured.')
main()
    
