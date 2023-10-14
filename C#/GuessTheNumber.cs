using System;

class Program
{
    static void Main()
    {
        Random random = new Random();
        int minRange = 1;
        int maxRange = 100;
        int numberToGuess = random.Next(minRange, maxRange + 1);
        int numberOfTries = 0;
        int playerGuess = 0;

        Console.WriteLine("Welcome to Guess the Number Game!");
        Console.WriteLine($"I've selected a number between {minRange} and {maxRange}. Try to guess it.");

        while (playerGuess != numberToGuess)
        {
            Console.Write("Enter your guess: ");

            if (!int.TryParse(Console.ReadLine(), out playerGuess))
            {
                Console.WriteLine("Please enter a valid number.");
                continue;
            }

            numberOfTries++;

            if (playerGuess < minRange || playerGuess > maxRange)
            {
                Console.WriteLine($"Your guess should be between {minRange} and {maxRange}.");
            }
            else if (playerGuess < numberToGuess)
            {
                Console.WriteLine("Try a higher number.");
            }
            else if (playerGuess > numberToGuess)
            {
                Console.WriteLine("Try a lower number.");
            }
            else
            {
                Console.WriteLine($"Congratulations! You've guessed the number {numberToGuess} in {numberOfTries} tries.");
            }
        }

        Console.WriteLine("Thanks for playing!");
    }
}
