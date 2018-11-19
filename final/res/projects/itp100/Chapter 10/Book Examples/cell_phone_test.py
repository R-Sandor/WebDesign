# This program test the CellPhone class.

import cellphone

def main():
    # Get the phone data.
    man = input('Enter the manufacturer: ')
    mod = input('Enter the model number: ')
    retail = float(input('Enter the retail price: '))

    #Create an instance of the Cellphone class.
    phone = cellphone.CellPhone(man,mod,retail)

    print('Here is the data that you entered:')
    print('Manufacturer:', phone.get_manufact())
    print('Model Number:', phone.get_model())
    print('Retail Price $', format(phone.get_retail_price(), ',.2f'), sep = '')

    #Call the main function.
main()
