# This program creates five CellPhone objects.

import cellphone

def main():
    # Get the list of Cellphone objects.
    phones = make_list()

    #Display the data in the list
    print ('Here is the data you entered:')
    display_list(phones)

    #The make_list function gets the data from the user
    #for five phones. The function return a list
    #of CellPhone objects containing the data.
def make_list():
    phone_list = []

    #Add five Cellpone objects to the list.
    for count in range(1,6):
        print ('phone number ' + str(count) + ':')
        man = input('Enter Manufacturer: ')
        mod = input('Enter the model number: ')
        retail = float(input('Enter the retail price: '))
        print()

    #Create a new CellPhone object in memory and
    #assign it to the variable.
    phone = cellphone.CellPhone(man,mod, retail)

    #Add the object to the list.
    phone_list.append(phone)
    return phone_list

    #The display_list function accepts a list containing
    #Cellphone objects as an arguement and displays the
    #data stored in each object.

def display_list(phone_list):
    for item in phone_list:
        print(item.get_manufact())
        print(item.get_model())
        print(item.get_retail_price())
        print()

    #Call the main function.
main()
