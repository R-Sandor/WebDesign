# This porgram passes a coin object  as
# an arguement to a function
import coin

#Main function
def main():
    #Create a coin object
    my_coin = coin.Coin()

    #This will display 'Heads'
    print(my_coin.get_sideup())

    #Pass the obect to the flip function
    flip(my_coin)

    #This might display 'Heads or, it might
    #display 'Tails'
    print(my_coin.get_sideup())

    #The flip function flips a coin.
def flip(coin_obj):
    coin_obj.toss()
    
# Call the main function.
main()
    
