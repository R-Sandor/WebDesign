# This program calculates saldes commissions.

# Create a variable to control the loop.
keep_going = 'y'

# Calculate a series of commissions.
while keep_going == 'y' :
    #Ger a salesperson's sales and commission rate.
    sales = float(input('Enter the amount of sales:'))
    comm_rate = float (input('Enter the commissioon rate:'))

    # Calculate the commission.
    commission = sales * comm_rate

    #Display the commision.
    print ('The commission is $',\
           format(commission, ',.2f'), sep='')

    #See if the user want do another one.
    keep_going = input('Do you want to calculate another' + \
                       ' commission (Enter y for yes): ')
    
