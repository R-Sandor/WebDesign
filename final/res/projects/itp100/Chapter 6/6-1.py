def main ():
    # Open a file named philospophers.txt.
    outfile = open('philosophers.text', 'w')
    #write  the names of three philosphers
    #to the file

    outfile.write('John Locke\n')
    outfile.write('David Hume\n')
    outfile.write('Edmund Burke\n')

    #close the file
    outfile.close()

#call the main function
main()
