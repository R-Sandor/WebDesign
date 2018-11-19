 # Get a product number to search for.
def main():
    search = input('Enter a name you would like to check.' '\n'
                       'This program will tell you if it is among the top 200 names'
                       '\n'  'from the year 2000 to 2009: ')
    if search in boy_names_index:
        print('The name is the top 200')
    else:
        print('The name was not found')


        #Open Text Files
        infile = open('BoyNames.txt', 'r')
        infile2 = open('GirlNames.txt', 'r')

        #Creates the Vairables boy_names and girl_names
        #So that it may be referenced by the while function
        boy_names = infile.readlines()
        girl_names = infile2.readlines()

        #Create a while function to read all lines in the text file
        #Then place these lines into a index

    
        #Creates search for user to search the index for the names
        search = input('Enter a name you would like to check.' '\n'
                       'This program will tell you if it is among the top 200 names'
                       '\n'  'from the year 2000 to 2009: ')

    
    
        
        # Add the contents to a list
    
 


    # Close the file.
    infile.close()
    infile2.close()

# Call Main Function
main()
