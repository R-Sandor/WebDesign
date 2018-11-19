#include <iostream>
#include <random>
#include <ctime>
#include <queue>
#include <stack>

using namespace std;

// prototype for the factory engine
void factory();
// prototype for displyQueues
void displayQueues();
// prototype for displaying stacks
void displayStack();
void pickQueue(int qNum);
// Global variable for the sequential count
// I know this could be considered poor form
// however this is not a large program
int seqCount =1;
int whosNext =0;

// This is an int distribution used for the generation
// of seq nums
uniform_int_distribution<int> seqDist(1,5);

// four priority queues
priority_queue<int, vector<int>, greater<int>> q0;
priority_queue<int, vector<int>, greater<int>> q1;
priority_queue<int, vector<int>, greater<int>> q2;
priority_queue<int, vector<int>, greater<int>> q3;

// a stack
stack<int> myStack;

default_random_engine randEng = default_random_engine(time(NULL));
int main ()
{
	bool play = true;
	int count =0;
	while (play)
	{
		if (count < 5)
		{
			factory();
		}
		else
		{
			cout << "run five more times? (Y/n)" << endl;
			string userInput;

			cin >> userInput;
			if (userInput == "y" || userInput == "yes" || userInput== "Yes" || userInput == "y" )
				count =0;
			else
				play = false;
		}
		count++;
	}

	return 0;
}

void factory()
{
	int numsToGen = seqDist(randEng);
	cout << "Factory generates: ";
	for(int i =0; i < numsToGen; i++)
	{

		if ((whosNext % 4) ==0)
		{
			cout << seqCount<< " " ;
			q0.push(seqCount);
			whosNext++;
			seqCount++;
		}
		else if ((whosNext % 4) == 1)
		{
			cout << seqCount<< " ";
			q1.push(seqCount);
			whosNext++;
			seqCount++;
		}
		else if ((whosNext % 4) ==2)
		{
			cout << seqCount<< " ";
			q2.push(seqCount);
			whosNext++;
			seqCount++;
		}
		else if ((whosNext % 4 ) == 3)
		{
			cout << seqCount<< " ";
			q3.push(seqCount);
			whosNext++;
			seqCount++;
		}

	}
		cout << endl;
		uniform_int_distribution<int> intDist(0,3);
		int selectedQ = intDist(randEng);
		displayQueues();
		pickQueue(intDist(randEng));
		displayStack();
}

void displayQueues()
{
	vector<int> tempVect;
	cout << "Q0: ";
	while(!q0.empty())
	{
		tempVect.push_back(q0.top());
		cout << q0.top() << " ";
		q0.pop();
	}
	for (auto aInt : tempVect )
	{
		q0.push(aInt);
	}
	cout << endl;
	tempVect.clear();
	cout << "Q1: ";
	while(!q1.empty())
	{
		tempVect.push_back(q1.top());
		cout << q1.top() << " ";
		q1.pop();
	}
	for (auto aInt : tempVect )
	{
		q1.push(aInt);
	}
	cout << endl;
	tempVect.clear();
	cout << "Q2: ";
	while(!q2.empty())
	{
		tempVect.push_back(q2.top());
		cout << q2.top() << " ";
		q2.pop();
	}
	for (auto aInt : tempVect )
	{
		q2.push(aInt);
	}
	cout << endl;
	tempVect.clear();
	cout << "Q3: ";
	while(!q3.empty())
	{
		tempVect.push_back(q3.top());
		cout << q3.top() << " ";
		q3.pop();
	}
	for (auto aInt : tempVect )
	{
		q3.push(aInt);
	}
	cout << endl;

}

void displayStack()
{
	vector<int> tempVect;
	if (myStack.empty())
	{
		cout << "Stack: empty";
		cout << endl;
	}
	else
	{
		while (!myStack.empty())
		{
			int aInt = myStack.top();
			myStack.pop();
			tempVect.push_back(aInt);
		}
		cout << "Stack: ";
		for (int aInt : tempVect)
		{
			cout<< aInt << " ";
		}
		cout << endl;
		for (vector<int>::const_iterator it= tempVect.cbegin(); it !=tempVect.cend(); it++ )
		{
			myStack.push(*it);
		}
		cout << endl;

	}

}

void pickQueue(int qNum)
{
		switch(qNum)
		{
		case 0:
				cout << "Reciever choice: 0\n";
				if (!q0.empty())
				{
				myStack.push(q0.top());
				q0.pop();
				}
				break;
		case 1:
            if (!q1.empty())
                {
				cout << "Reciever choice: 1\n";
				myStack.push(q1.top());
				q1.pop();
				}
				break;
		case 2:
				cout << "Reciever choice: 2\n";
				if (!q2.empty())
				{
				myStack.push(q2.top());
				q2.pop();
				}
				break;
		case 3:
                if (!q3.empty())
                {
				cout << "Reciever choice: 3\n";
				myStack.push(q3.top());
				q3.pop();
				}
				break;
		}
}
