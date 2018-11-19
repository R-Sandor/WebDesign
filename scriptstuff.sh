#!/bin/bash

echo "Copying objects for you"

counter=4
while [ $counter -le 9 ]
do
	echo "hey"	
	cp assignment4.html assignment$counter.html
	((counter=$counter+1))
	
done 

cp assignment4.html finalProject.html
