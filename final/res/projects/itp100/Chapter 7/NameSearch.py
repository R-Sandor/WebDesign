def main():
    search = input('Enter a name: ')
    infile = open('BoyNames.txt', 'r')
    infile2 = open('GirlNames.txt', 'r')
    boy_names = infile.readlines()
    girl_names = infile2.readlines()
    both_name = boy_names + girl_names
    index = 0
    while index < len(both_name):
        both_name[index] = both_name[index].rstrip('\n')
        index +=1

    if search in both_name:
        print('The name was found')
    else:
        print('The name was not found')

 
    
    


main()
