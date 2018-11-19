import pet

# Get the pet's name, type, and age
name = input("What is your pet's name? ")
animal_type = input("What type of animal is that? ")
age = input("How old is your pet?")

# Create an instance of the Pet class.
my_pet = pet.Pet(name, animal_type, age)

print("Here is the information you entered:")
print("Pet name:", my_pet.get_name())
print("Animal type:", my_pet.get_animal_type())
print("Age:", my_pet.get_age())
