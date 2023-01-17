/*
    author: David Allen Stephan Marino
    date: Jan 16th, 2023
    assignment: Project 0 - REVIEW OF CS1250
    link: https://umsystem.instructure.com/courses/155907/assignments/1683539
*/
#include <iostream>
#include <cstdlib>
using namespace std;
bool determineGuessWithinRange(int guess, int min, int max)
{
    if (guess < min)
    {
        cout << "Guess too low, out of range!";
        cout << "\n";
        return false;
    }
    if (guess > max)
    {
        cout << "Guess too high, out of range!";
        cout << "\n";
        return false;
    }
    return true;
}
void determineWarmerColder(int prevDifference, int difference)
{
    if (difference > prevDifference)
    {
        cout << "Getting colder!";
        cout << "\n";
    }
    else if (difference < prevDifference)
    {
        cout << "Getting warmer!";
        cout << "\n";
    }
    else if (difference == prevDifference)
    {
        cout << "Same temperature!";
        cout << "\n";
    }
}
int distanceToClosest(const int solutions[], int SIZE, int guess)
{
    int smallestDifference = abs(solutions[0] - guess);
    for (int i = 0; i < SIZE; i++)
    {
        int difference = abs(solutions[i] - guess);
        if (difference < smallestDifference)
        {
            smallestDifference = difference;
        }
    }
    return smallestDifference;
}
int makeGuess()
{
    int guess = 0;
    cout << "Please make a guess: ";
    cin >> guess;
    int isValid = determineGuessWithinRange(guess, 1, 1000);
    if (isValid)
    {
        return guess;
    }
    return makeGuess();
}
int runGame(const int solutions[], int SIZE, int prevDifference)
{
    int guess = makeGuess();
    int difference = distanceToClosest(solutions, SIZE, guess);
    if (difference == 0)
    {
        cout << "Success!";
        return 1;
    }
    determineWarmerColder(prevDifference, difference);
    return runGame(solutions, SIZE, difference);
}
int main()
{
    const int SIZE = 5;
    int solutions[SIZE] = {100, 250, 310, 413, 565};
    cout << "Hello please try and guess one of my numbers between 1 and 1000";
    cout << "\n";
    int guess = makeGuess();
    int difference = distanceToClosest(solutions, SIZE, guess);
    if (difference == 0)
    {
        cout << "Success!";
        return 1;
    }
    cout << "I am sorry, that is incorrect!";
    cout << "\n";
    runGame(solutions, SIZE, difference);

    return 0;
}