#include <cctype>
#include <cstddef>
#include "stdafx.h"

char* strtrim(char str[])
{
	char * pointerToOriginalArray = str;

	if (str == nullptr || str[0] == '\0' || str == "")
	{
		return pointerToOriginalArray;
	}

	//Counter
	int index = 0;
	int startingIndexOfValidCharacters = 0;
	bool doValidCharactersExistYet = false;
	int lastValidCharacterThatIsKnown = -1;
	char currentCharacter = ' ';
	do
	{
		currentCharacter = str[index];

		if (currentCharacter != ' '
			&& currentCharacter != '\n'
			&& currentCharacter != '\t'
			&& currentCharacter != '\f'
			&& currentCharacter != '\v'
			&& currentCharacter != '\r'
			&& currentCharacter != '\0')
		{
			lastValidCharacterThatIsKnown = index;
			
			if (doValidCharactersExistYet == false)
			{
				startingIndexOfValidCharacters = index;
				doValidCharactersExistYet = true;
			}
		}
		
		index++;
	} while (currentCharacter != '\0');

	//Fill Array
	index = startingIndexOfValidCharacters;
	int indexOfWhereToPlaceCharacter = 0;
	if (doValidCharactersExistYet == true)
	{
		do
		{
			currentCharacter = str[index];

			str[indexOfWhereToPlaceCharacter] = currentCharacter;

			indexOfWhereToPlaceCharacter++;
			index++;
		} while (index <= lastValidCharacterThatIsKnown);
	}
	
	str[indexOfWhereToPlaceCharacter] = '\0';

	return pointerToOriginalArray;
}
