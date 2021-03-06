// INFO450PLATIN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int translatetoPigLatin(char phrase[51], char newPhrase[53]);

/*This is the main loop of the program. We have a variable that determines if we keep asking for words to translate
based on user input, and of course ask for a word to translate with the translatetoPigLatin function. If that function
returns a -1, it means an invalid input was received and we try again.*/
int main()
{
	bool translating = true;
	do
	{
		char again;
		char phrase[51] = "";
		char newPhrase[53] = "";
		cout << "Please enter a word, no more than 50 characters, to be translated into Pig Latin." << endl;
		cin.getline(phrase, 51);
		cout << "Your word is " << phrase << "." << endl;
		if (translatetoPigLatin(phrase, newPhrase) == 0)
		{
			cout << "Your translated word is " << newPhrase << ". Enter Y if you would like to translate another word." << endl;
			cin >> again;
			cout << endl;
			if (again == 'y' || again == 'Y')
			{
				translating = true;
			}
			else
			{
				translating = false;
			}
		}
		else
		{
			cout << "Sorry, your word was either empty or began with a number. Please try again." << endl;
			translating = true;
		}
		//Calling cin.ignore lets this loop continue using cin.getLine without running into bugs due to previous input.
		cin.ignore(51, '\n');
	} while (translating == true);
	return 0;
}

/*The meat of the program. We take in phrase as the original word and newPhrase so we can spit back the modified version.*/
int translatetoPigLatin(char phrase[51], char newPhrase[53])
{
	//If the first character is null or a number, we return a -1 because the input is invalid.
	if (phrase[0] == '\0')
	{
		return -1;
	}
	else if (phrase[0] == '1' || phrase[0] == '2' || phrase[0] == '3' || phrase[0] == '4' ||
		phrase[0] == '5' || phrase[0] == '6' || phrase[0] == '7' || phrase[0] == '8' || phrase[0] == '0')
	{
		return -1;
	}
	//If the third character is null, the word is only 2 characters, so the translated version is the same.
	else if (phrase[2] == '\0')
	{
		strcpy(newPhrase, phrase);
	}
	//We check for articles and conjunctions because they remain the same.
	else if (phrase == "the" || phrase == "a" || phrase == "an" || phrase == "but" || phrase == "and" ||
		phrase == "for" || phrase == "so" || phrase == "nor" || phrase == "yet" || phrase == "or" ||
		phrase == "The" || phrase == "A" || phrase == "An" || phrase == "But" || phrase == "And" ||
		phrase == "For" || phrase == "So" || phrase == "Nor" || phrase == "Yet" || phrase == "Or")
	{
		strcpy(newPhrase, phrase);
	}
	//If the first character is a vowel, we simply add 'ay' to the end of the word for the translation.
	else if (phrase[0] == 'a' || phrase[0] == 'e' || phrase[0] == 'i' || phrase[0] == 'o' || phrase[0] == 'u' ||
		phrase[0] == 'A' || phrase[0] == 'E' || phrase[0] == 'I' || phrase[0] == 'O' || phrase[0] == 'U')
	{
		strcat(newPhrase, phrase);
		strcat(newPhrase, "ay");
	}
	/*If the first character is not a vowel, a number, or null, it's probably a consonant, so we copy everything from that\
	first character, reattach, the first character, and add 'ay' to complete the translation.*/
	else
	{
		int i = 1;
		int end = strlen(phrase) - 1;
		for (; i <= end; i++)
		{
			newPhrase[i - 1] = phrase[i];
		}
		newPhrase[strlen(phrase) - 1] = phrase[0];
		strcat(newPhrase, "ay");
	}
	//Returning a 0 shows that the input was valid so that the main function can proceed normally.
	return 0;
}

