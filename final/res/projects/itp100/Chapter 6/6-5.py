# This porgram calculates the average
# of numbers in numbers.txt
def main():
    HowManyNumbers = int(input('How many numbers would you like to average: '))
    numbersfile = open('numbers.txt', 'w')
    for count in range (1, HowManyNumbers + 1):
        numbersEntered = int(input('Enter #' + str(count) + ': '))
        numbersEntered.write(str(count)
        numbersfile.close()
        fileopen()
def fileopen():
    numbersfile = open('numbers.txt', 'r')
    file_content = numbersfile.read()
    numbersfile.close()
    print('The numbers entered are', file_content)

main()
