//
// Created by Nawaraj Shahi on 5/1/20.
/*
Implement	a	number	guessing	game.	The	program	should	randomly	choose	an	integer	
between	1	and	100	(inclusive),	and	have	the	user	try	to	guess	that	number.	
Implementations	guidelines:
    1. The	user	can	guess	at	most	5	times.
    2. Before	each	guess	the	program	announces:
        • An	updated	guessing-range,	taking	in	to	account	previous	guesses	and	responses.
        • The	number	of	guesses	that	the	user	has	left.
    3. If	the	user	guessed	correctly,	the	program	should	announce	that,	and	also	tell	how	many	
        guesses	the	user	used.
    4. If	the	user	guessed	wrong,	and	there	are	still	guesses	left,	the	program	should	tell	the	
        user	if	the	number	(it chose)	is	bigger	or	smaller	than	the	number	that	the	user	guessed.
    5. If	the	user	didn’t	guess	the	number	in	all	of	the	5	tries,	the	program	should	reveal	the	
        number	it	chose
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int guess, lowerRange, upperRange, numGuessLeft;
    int randomVal, guessCounter;

    srand(time(0));
    randomVal = (rand() % 100) + 1;

    lowerRange = 1;
    upperRange = 100;
    numGuessLeft = 5;
    guessCounter = 1;
    bool guessed = false;

    cout << "Random value is: " << randomVal << endl;

    cout << "I thought of a number between 1 and 100! Try to guess it. " << endl;
    while ((numGuessLeft >0) && guessed == false){
        cout << "Range: [" << lowerRange << ", " << upperRange;
        cout << "], Number of guesses left: " << numGuessLeft << endl;

        //ask user to guess
        cout << "Your guess: ";
        cin >> guess;

        //check to see if guess is right
        if (guess == randomVal){
            cout << "Congrats! You guessed my number in " << guessCounter << " guesses." << endl;
            guessed = true;

            //check to see if guess is false
        }else{
            //checks if guess is out of range
            if (guessCounter >= 5){
                cout << "Out of guesses! My number is " << randomVal << endl;
            } else{
                //if guess is not right and not out of range then
                //program should update the range accordingly and
                //display the message to the user

                if (guess < randomVal){
                    if(guess >=lowerRange){  //checks if user guess is higher than lower range
                        cout << "Wrong! My number is bigger." << endl;
                        lowerRange = guess;
                    } else{  // checks if user keeps entering number less than previous lower range
                        cout << "Wrong! My number is bigger." << endl;
                    }
                }else {
                    if (guess <= upperRange){   //checks if user guess is lower than upper range
                        upperRange = guess;
                        cout << "Wrong! My number is smaller." << endl;
                    } else{         //checks if user keeps entering number higher than previous upper range
                        cout << "Wrong! My number is smaller." << endl;
                    }
                }
            }
        }
        guessCounter +=1;
        numGuessLeft -=1;
    }
    return 0;
}