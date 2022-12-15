#include <stdio.h>

#define lengthString 100

//why its dont work((((

int  balanceCheck(char string[])
{
	int unBalanceCheck = 0;

	int openRound = 0, closeRound = 0, openSquare = 0, closeSquare = 0, openFigure = 0, closeFigure = 0;

	if (string[0] == '(')
		openRound++;
	if (string[0] == ')')
		closeRound++;

	if (string[0] == '[')
		openSquare++;
	if (string[0] == ']')
		closeSquare++;

	if (string[0] == '{')
		openFigure++;
	if (string[0] == '}')
		closeFigure++;

	for (int i = 1; i < lengthString; i++)
	{
		if (string[i - 1] == '(' && string[i] == ')')
			return 0;
		if (string[i] == '(')
			openRound++;
		if (string[i] == ')')
			closeRound++;
		if (closeRound > openRound)
			return 0;

		if (string[i - 1] == '[' && string[i] == ']')
			return 0;

		if (string[i] == '[')
			openSquare++;
		if (string[i] == ']')
			closeSquare++;
		if (closeSquare > openSquare)
			return 0;

		if (string[i - 1] == '{' && string[i] == '}')
			return 0;

		if (string[i] == '{')
			openFigure += 1;
		if (string[i] == '}')
			closeFigure++;
		if (closeFigure > openFigure)
			return 0;
	}

	if (closeRound == openRound && closeSquare == openSquare && closeFigure == openFigure)
		return 1;

	return 0;

}

int main()
{
	char stringBracket[lengthString] = { '\0' };


	printf("Enter bracket sequence (not more than %d):\n", lengthString);


	fgets(stringBracket, lengthString, stdin);

	int result = balanceCheck(stringBracket);

	printf(result);

	return 0;
}