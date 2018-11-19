(* Author: Raphael J. Sandor *)
(* Class: CS355 - Principles of Programmming langauges *)
(* Professor: J. Morris*)
(*Last edited 10/10/2017 *)
(* Purpose: To run a simulation of what smallpox in a population *)


(* Starts population off as an empty list*)
val population = [];
val deadPeople = [];
val immuneList = [];
val infectedPeople = [];
val infectiousInfected = [];
val infectiousPeople=[];
val days = 0.0; 
(* Tried to set it up to use directory not sure if this works*)
val path = OS.FileSys.getDir();
val path = path^"/out.txt";

(* This the population data 
generated from the generate population.cpp*) 
use "pop_data.txt";


(* this allows us to extract the list from every person 
* without having to use # sign as this is more trouble 
* then it worth. *)
type aPerson = int * int * int * string * int * int * string * int * int list;
type aPopulation = (int * int * int * string * int * int * string * int * string *int list) list;



(*useful functions for retrieving information about a person *
 *all of which take a person (hd population) as  an arguement*)
(*************************************************************)
use "getGroup.sml";
use "getPID.sml";
use "getAge.sml";
use "getFID.sml";
use "getExposure.sml";
use "getDaysSinceExposure.sml";
use "getDaysOfIncubation.sml";
use "getDiagnosed.sml";
use "getDaysUntilDead.sml";
use "getInfected.sml";
use "getMixingGroups.sml";
(*******************************************************************)

(* This function goes through all the people                                         *) 
(* and allows their groups to be added to a list of mixing groups                    *)
(* Definition: fun goThroughGroups (population: aPopulation , x:int, mixgrps:int list*)
(*************************************************************************************)
use "goThroughGroups.sml";
val mixingGroups = goThroughGroups (population, population_size, []);

(* provides the remove duplicate function *)
use "removeCopy.sml";

(* merge sort because lists in order are nice *)
use "mergeSort.sml";

(* the isolate function removes duplicates in a list *)
val mixingGroups = isolate mixingGroups;
val mixingGroups = mergeSort mixingGroups;

(* Count the number of groups that are available *)
(* Takes a list as an argument *)
(* Definition fun listCounter (mixingGroups:int list) *) 
use "listCounter.sml";
(* lets the users know the number of groups in the population *)
val numberOfGroups = listCounter mixingGroups; 

(* this allows for data to be written out to a file *) 
use "writeFile.sml";

(* Turns mixing groups in to a list of lists *)
val mixingGroups = mixingGroups::[]; 
(* This function allows every person to get added to a group by creating the    *)
(* lists                                                                        *) 
(* Defintion fun createGroups(i:int , listOfGroups:int list ( hd mixingGroups)  *)
use "createGroups.sml";
val mixingGroups = createGroups (numberOfGroups,mixingGroups );

(* finds the location of a group in a mixingGroups                                     *)
(* Take a group that is being searched for, a location, and an another list            *)
(* Returns an int which is a location of the group inside of list                      *)
(* allows the user to decide to count from one or zero as there are times where both   *)
(* maybe a approriate, e.g. moving one past a list that you searched in side of to get *)
(* the location of a list.                                                             *)
(* Definition fun lookupList (orgGrpNumber:int, counter:int, aGroup:int list)          *)
use "lookupList.sml";

(* returns the PID of a person in a population *)
(* taks a person as an arguement               *) 
use "getPID.sml"; 

(* this function adds the person to each of the groups 
* that the person belongs *)
use "getListInList.sml";

(* This counts the number of lists that are in a list *) 
use "listOfListCounter.sml";

(* This adds a single person to a group *)
use "getFrontOfList.sml"; 
use "getBackOfList.sml"; 
use "addSinglePersonToGroup.sml";

(*This adds everyone in the population to a group using add single person.. *) 
use "addPeopleToGroups.sml";
val mixingGroups = addPeopleToGroups (population, mixingGroups);

(* This creates a random in the range of size of the group *) 
use "randvals.sml";
val selectedId = getRandom r; 

(* selects a group that will be infected *)
(* The group will have 1% of the population in the group *) 
use "selectGroupToInfect.sml";
val selectedId= selectGroupToInfect(selectedId);
val contaminated = getListInList(selectedId, mixingGroups);
val days=0; 

(* This returns the population after being checked *)
use "foundMember.sml";
use "foundPerson.sml";
use "populationListCounter.sml";
use "backOfPopulation.sml";
use "getFrontOfPopulation.sml";
use "contaminatePerson.sml";
use "contaminateGroup.sml";


(* adds the first contaminated individuals into population *)
val population = contaminateGroup(contaminated,population);
use "contaminatedList.sml";
use "contaminatePopulation.sml";
use "foundGroup.sml";
use "addToContaminated.sml";


(* unique the people that have been contaminated *)
val contaminated = mergeSort contaminated;
val contaminated = isolate contaminated; 

(* returns a group with all the contaminated people inside *)
val contaminatedGroups = contaminatePopulation(population,[] );
val contaminatedGroups = isolate contaminatedGroups;
val contaminatedGroups = mergeSort contaminatedGroups;

(* This looks for the members of a contaminated group *)
(* After which adds those people to this of contaminated individuals*)
val contaminated = addToContaminated(contaminatedGroups, population, []);
val population = contaminateGroup(contaminated,population);


(* place contaminated people in the population *)
val population = contaminateGroup(contaminated,population);
(*use "tryToInfectPopulation.sml";*)

(* Run again to get the groups that have been added *)

(* returns a group with all the infectious people inside *)
val contaminatedGroups = contaminatePopulation(population,[] );
val contaminatedGroups = isolate contaminatedGroups;
val contaminatedGroups = mergeSort contaminatedGroups;
(* This looks for the members of a contaminated group *)
(* After which adds those people to this of contaminated individuals*)
val contaminated = addToContaminated(contaminatedGroups, population, []);
(* unique the people that have been contaminated *)
val contaminated = mergeSort contaminated;
val contaminated = isolate contaminated; 

val population = contaminateGroup(contaminated,population);


(* returns people from a group *)
(* inputGroups:int list , findFromListOfPeople:int list, returnList *)
use "peopleInGroups.sml";

(* This finds a person in the list of the population given a PID *)
use "PIDtoPerson.sml";  

(* Take a list of of people and checks if the list of people match a single person:int 
from the first list provided *)
use "isInMixingGroup.sml";

(* Takes a list and searches if all possible people that the person comes in contact with are infectious and if 
any of the people that those people have contacted contaminated them *)
use "isInMixingGroup2.sml"; 

(* returns all the people that a person shares a group with that are also contaminated
 sharedGroups(aPerson:int (pid), contaminated(list of people who are contaminated ), [[]]); *)
use "sharedGroups.sml";

(*used by the the run probability function to decide if a person is in the family 
as family members increase the risk of contmaination *)
(* defination  fun isInFamily(p1, p2) (compares pids of two people)*)
use "isInFamily.sml";


(* runs probability on everyone in the population given there assocaition 
with people who are infected with smallpox *)
(* uses the following functions sharedGroups function, peopleInGroups, isInFamily *)
val r = Random.rand(0,100);

(* Does the same thing as contaminate group accept with the pid of a person and changes their    *
 * their status to infected and infectious                                                       *)
(* signature  fun infectIndividual (location , population) =                                     *)
use "infectIndividual.sml";

use "runProbability.sml";

use "tryToInfect.sml";

use "infectPopulation.sml";

(* Same functionality as getFrontOfList.sml except that it takes an int list rather than int list list *)
(* and returns an int list rather than int list list                                                   *)
(* Definition: fun getFrontOfIntList (position:int , inputlist:int list , outputList:int list   ) =    *)
use "getFrontOfIntList.sml";
use "getBackOfIntList.sml"; 


val infectedPeople = tryToInfect(contaminated, [], Real.fromInt(days) );
val infectedPeople = isolate infectedPeople;
val infectedPeople = mergeSort infectedPeople; 

use "removeFromList.sml";


(* places infected people in the population *)
val population =infectPopulation(infectedPeople, population); 

(* This function will remove PIDs that are in contamianted list that are also in infected list. *)
(*removeFromList(affectedList, listToCompare )*)
val contaminated = removeFromList(contaminated, infectedPeople, []); 
val infectious = addToContaminated(contaminatedGroups, population, []);
val infectious = isolate infectious;
val infectious = mergeSort infectious;
(*val population = contaminateGroup(infectious,population);
  I am not sure what this code does for me here hmm it did something that may useless now damn... *)


val infectious = mergeSort infectious;
use "randoms0to100.sml";

use "tryToKill.sml";

use "isInPopulation.sml";

use "updateListOfDead.sml";
(* removes the dead from the list *)
use "removeFromPopulation.sml";


(* given a location in a list, returns that location *)
use "getToSpot.sml";

(* Decontamiantes a person if contaminated status extends past 3 days *)
use "decontaminatePerson.sml";

(* changes a persons status who has been exposed for more than 3 days and not infected 
to not exposed and not infectious *)
use "changeContaminatedStatus.sml"; 

(* decides which people in the population are still contaminated *)
use "stillContaminated.sml";

(* puts a person's status to both infected and infectious *)
use "infectedInfectiousPerson.sml";


(* adds one todays of incubation for infected people*)
use "addToDaysOfIncubation.sml"; 

use "incrementInfectionDays.sml";

(* checks if a person is infected and infectious a.k.a status infected and incubation 7-14 days *)
use "infectedAndInfectious.sml"; 

(* puts a person's status to both infected and  not infectious *)
use "infectedNotInfectiousPerson.sml";

use "infectedNotInfectious.sml";

use "getInfectious.sml";

use "removeFromPopulation.sml";

(*sets a persons status to being immune *)
use "immune.sml";
use "getImmune.sml";
(* if a person is past 14 days of incubation and does not die they are immune *)
use "survivedSmallpox.sml";

use "addToDaysOfExposure.sml";
use "incrementDaysOfContamination.sml"; 
use "findInfectedPeople.sml";
(* use this function with infectedPeople to try to infect the population with infectious people*)
(*val infectedPeople = tryToInfect(infectiousPeople, []);*)

(* runs the simulation for 20+ after contamination *)
(* outputs a report at the bottom of the day *) 
use "infectWithInfectious.sml";

use "runSimulation.sml";
val no= writeFile path "The number of added people to each group at end of a day\n";

val aList = runSimulation(days, population, deadPeople, infectedPeople, infectiousPeople, contaminated, immuneList); 
