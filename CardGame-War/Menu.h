#pragma once
#include <stdio.h>
class Menu()
{
	//Menu- Select what you wish to do
	void Menu(int playerCard[players][card], int playerSuit[players][suit], int numPlayers, int playerScores[players], int roundNum, int playerUsedCards[players][card])
	{
		//Variables
		int menuChoice;

		//Display Menu
		printf("\n\n************************************************************************");
		printf("\n\t\t\t\tMenu");
		printf("\n\t\t    Please Select an Option below");
		printf("\n    1- Continue\t   2-Exit\t3-Exit & Save\t4-Display Status\n");
		scanf("%d", &menuChoice);
		printf("\n************************************************************************");

		//Selected Menu Option
		switch (menuChoice)
		{
			//Continue Game
		case 1:
			PlayGame(playerCard, playerSuit, numPlayers, playerScores, (roundNum - 1), playerUsedCards);
			break;

			//Exit without saving
		case 2:
			exit(0);
			break;

			//Save Game and Exit
		case 3:
			SaveGame(playerCard, playerSuit, numPlayers, playerScores, (roundNum - 1), playerUsedCards);
			break;

			//Display Status of Game
		case 4:
			Display(playerCard, playerSuit, numPlayers, playerScores, (roundNum - 1), playerUsedCards);
			break;
		}
	}

};

