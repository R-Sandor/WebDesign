def main():
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
