#include "stdafx.h"

// Trims whitespace from the front and back of each string of characters
char* strtrim(char str[])
{
	char* pointerToOriginalArray = str;

	if (str == nullptr || str[0] == '\0')
	{
		return pointerToOriginalArray;
	}
	
	int readingIndex = 0;
	int writingIndex = 0;
	bool doValidCharactersExistYet = false;
	int lastValidCharacterThatIsKnown = -1;
	char currentCharacter;
	do
	{
		currentCharacter = str[readingIndex];

		if (currentCharacter != ' '
			&& currentCharacter != '\n'
			&& currentCharacter != '\t'
			&& currentCharacter != '\f'
			&& currentCharacter != '\v'
			&& currentCharacter != '\r'
			&& currentCharacter != '\0')
		{
			// found a valid character. Need to tell \0 where to go
			lastValidCharacterThatIsKnown = writingIndex;
			
			doValidCharactersExistYet = true;
		}

		if (doValidCharactersExistYet == true)
		{
			// fill original array until \0 read
			str[writingIndex] = currentCharacter; 
			writingIndex++;
		}

		readingIndex++;
	} while (currentCharacter != '\0');

	// Add 1 spot for \0 to go behind last valid character
	str[lastValidCharacterThatIsKnown + 1] = '\0';

	return pointerToOriginalArray;
}
