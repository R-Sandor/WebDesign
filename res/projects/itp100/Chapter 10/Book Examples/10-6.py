# This porgram imports the coin module and
# Creates an instance of the Coin Class.

import coin

def main():
    #Create an object from the coin class.
    my_coin = coin.Coin()

    #Display the side of the coin that is facing up.
    print('This is up:', my_coin.get_sideup())

    #Toss the coin.
    print('I am goin to toss the coin ten times:')
    for count in range(10):
        my_coin.toss()
        print(my_coin.get_sideup())

# Call the main function.
main()
    
