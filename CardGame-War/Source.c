#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Define Variables for 2D array
#define card 13
#define suit 13
#define players 4
//i am defining player so 2d array will be 4X13. 
//doing this but only using as many players as told 

//Display- display Game Status
void Display(int numPlayers, int playerScores[players], int round)
{
	//Declare Variables
	int winner = 0, winScore = 0;

	//Display Score List
	printf("\nThe Score list is as shown:");

	//Loop for Scores
	for (int dis = 0; dis < numPlayers; dis++)
	{
		printf("\nPlayer %d:\t%d", (dis + 1),playerScores[dis]);

		//Find Winner
		if (playerScores[dis] > winScore)
		{
			//Set Winning Variables
			winScore = playerScores[dis];
			winner = (dis + 1);
		}
	}
	
	//if asked for display during a game
	if (round < 13)
	{
		printf("\nWinning Game by Round %d is:  %d", winner, round);
	}

	//If it was the last round display Game Winner
	else
	{
		printf("\nWinner of Game is:  %d", winner);
	}
	
	return 1;
	//Play game
	//PlayGame(playerCard, playerSuit, numPlayers, playerScores);
}

//----------------------------------------------------------------------------
//Save Game- Here will write to file
void SaveGame(int playerCard[players][card], int playerSuit[players][suit], int numPlayers, int playerScores[players])
{
	//declare File Name
	FILE* gameStatus;
	FILE* gameScores;

	//Open & Write to file
	gameStatus = fopen("GameSaved.txt", "w");
	gameScores = fopen("GameScore.txt", "w");

	//Check if file is open
	if (gameStatus == NULL || gameScores == NULL)
	{
		printf("Sorry File could not be opened\n");
	}

	else
	{
		for (int p = 0; p < numPlayers; p++)
		{
			//Generate Random cards
			for (int i = 0; i < 13; i++)
			{
				fprintf(gameStatus, "%d %d\n", playerCard[p][i], playerSuit[p][i]);
			}
		}

		for (int p = 0; p < numPlayers; p++)
		{
			fprintf(gameScores, "%d\n", playerScores[p]);
		}

		//Close File
		fclose(gameStatus);
		fclose(gameScores);
	}
}

//----------------------------------------------------------------------------
//Play Game- This is Seperate due to Continue Game Function
void PlayGame(int playerCard[players][card], int playerSuit[players][suit], int numPlayers, int playerScores[players])
{
	//Assign variables
	int menuChoice, cardChoice, player = 1, points = 0, chosenCard;
	int currentPlayer, winner = 0, winningCard = 0, roundNumber = 1;
	int playerSelectedCard[4][4], playerSelectedSuit[4][4];
	char exit = 'Y', round = 'Y';

	//Game goes on for 13 rounds
	do {
		//Next person has atleast 1 turn option
		do {
			printf("\nRound %d", roundNumber);

			//Update Current Player
			currentPlayer = (player - 1);

			//Display Player Cards
#pragma region DisplayCards

		//Display Card Numbers
			printf("\nPlayer %d's Cards are displayed below and number above them\n", player);
			printf("   1.       2.       3.       4.       5.       6.       7.       8.       9.       10.      11.      12.      13.   \n");

			//Display Top of Cards
			printf(" ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______\n");

			//Display Card Number at Top
			for (int c = 0; c < 13; c++)
			{
				if (playerCard[currentPlayer][c] > 1 && playerCard[currentPlayer][c] < 10)
				{
					printf("|%d     | ", playerCard[currentPlayer][c]);
				}

				else if (playerCard[currentPlayer][c] == 1)
				{
					printf("|A     | ");
					playerCard[currentPlayer][c] = 14;
				}

				else if (playerCard[currentPlayer][c] == 10)
				{
					printf("|%d    | ", playerCard[currentPlayer][c]);
				}

				else if (playerCard[currentPlayer][c] == 11)
				{
					printf("|J     | ");
				}

				else if (playerCard[currentPlayer][c] == 12)
				{
					printf("|Q     | ");
				}

				else if (playerCard[currentPlayer][c] == 13)
				{
					printf("|K     | ");
				}
			}

			//Skip to new line
			printf("\n");

			//Display Card Suit
			for (int c = 0; c < 13; c++)
			{
				switch (playerSuit[currentPlayer][c])
				{
				case 1:
					printf("|   H  | ");
					break;

				case 2:
					printf("|   D  | ");
					break;

				case 3:
					printf("|   S  | ");
					break;

				case 4:
					printf("|   C  | ");
					break;
				}
			}

			//Skip to new line
			printf("\n");

			//Display Card Number at Bottom
			for (int c = 0; c < 13; c++)
			{
				if (playerCard[currentPlayer][c] > 1 && playerCard[currentPlayer][c] < 10)
				{
					printf("|     %d| ", playerCard[currentPlayer][c]);
				}

				else if (playerCard[currentPlayer][c] == 1)
				{
					printf("|     A| ");
				}

				else if (playerCard[currentPlayer][c] == 10)
				{
					printf("|    %d| ", playerCard[currentPlayer][c]);
				}

				else if (playerCard[currentPlayer][c] == 11)
				{
					printf("|     J| ");
				}

				else if (playerCard[currentPlayer][c] == 12)
				{
					printf("|     Q| ");
				}

				else if (playerCard[currentPlayer][c] == 13)
				{
					printf("|     K| ");
				}
			}


			//Display Bottom of Cards
			printf("\n|______| |______| |______| |______| |______| |______| |______| |______| |______| |______| |______| |______| |______|\n");
#pragma endregion

			//Ask Player to select card
			printf("\nPlease Select Card you wish to Play (Or 0 to exit)\nChoice: ");
			scanf("%d", &cardChoice);

			//Set choice to players card
#pragma region SavePlayerChoice
			//Save Player Select Card # and Suit
			switch (cardChoice)
			{
			case 1:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][0];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][0];
				break;
			case 2:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][1];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][1];
				break;
			case 3:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][2];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][2];
				break;
			case 4:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][3];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][3];
				break;
			case 5:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][4];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][4];
				break;
			case 6:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][5];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][5];
				break;
			case 7:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][6];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][6];
				break;
			case 8:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][7];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][7];
				break;
			case 9:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][8];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][8];
				break;
			case 10:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][9];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][9];
				break;
			case 11:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][10];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][10];
				break;
			case 12:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][11];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][11];
				break;
			case 13:
				playerSelectedCard[currentPlayer][currentPlayer] = playerCard[currentPlayer][12];
				playerSelectedSuit[currentPlayer][currentPlayer] = playerSuit[currentPlayer][12];
				break;
			}
#pragma endregion

			//Add chosen card to points for round
#pragma region AddCardToPoints
		//Save Card choice to Variable
			chosenCard = playerSelectedCard[currentPlayer][currentPlayer];

			//Set point decide by Card Choice
			switch (chosenCard)
			{
			case 14:
				points += 14;
				break;
			case 2:
				points += 2;
				break;
			case 3:
				points += 3;
				break;
			case 4:
				points += 4;
				break;
			case 5:
				points += 5;
				break;
			case 6:
				points += 6;
				break;
			case 7:
				points += 7;
				break;
			case 8:
				points += 8;
				break;
			case 9:
				points += 9;
				break;
			case 10:
				points += 10;
				break;
			case 11:
				points += 11;
				break;
			case 12:
				points += 12;
				break;
			case 13:
				points += 13;
				break;
			}
#pragma endregion

			printf("%d %d %d", playerSelectedCard[currentPlayer][currentPlayer], playerSelectedSuit[currentPlayer][currentPlayer], points);

			//If a minus number entered exit loop
			if (cardChoice == 0)
			{
				//Exit Round loop
				round = 'R';

				//Exit Loop using R and Enter Menu using exit
				exit = 'N';
			}

			//If Player count is over amount of Players playing
			if (player >= numPlayers)
			{
				//Reset Count
				player = 0;

				//Exit Loop
				round = 'R';
			}

			//Update Player Counter
			player++;
		} while (round != 'R');

		//If Exit to menu selected
		if(exit != 'N')
		{
			//Update Round Number
			roundNumber++;

			//End Of Round- Find Winner
	#pragma region EndOfRound
	#pragma region FindWinner
			//Check if any players have the same card
			for (int f = 0; f < numPlayers; f++)
			{
				for (int ff = f + 1; ff < numPlayers; ff++)
				{
					if (playerSelectedCard[f][f] == playerSelectedCard[ff][ff])
					{
						playerSelectedCard[f][f] = 0;
						playerSelectedCard[ff][ff] = 0;
					}
				}
			}

			//Find Winner
			for (int w = 0; w < numPlayers; w++)
			{
				if (playerSelectedCard[w][w] > winningCard)
				{
					winningCard = playerSelectedCard[w][w];
					winner = (w + 1);
					printf("\n%d", winner);
				}
			}
	#pragma endregion

			//If Round is a Draw
			if (winner == 0)
			{
				if (roundNumber < 13)
				{
					//Display Round is a draw
					printf("\n\n************************************************************************");
					printf("\nThis Rounds was a draw!");
					printf("\nPoints rolled over to next round");
					printf("\n************************************************************************");
				}
				
				//If last round is a draw
				else if (roundNumber == 13) 
				{
					printf("\n\n************************************************************************");
					printf("\nLast Round was a draw!");
					printf("\nPoints Lost to Game!!");
					printf("\n************************************************************************");
				}
			}

			//If the round has a winner
			else if (winner > 0)
			{
				//Display Winner or round Screen
				printf("\n\n************************************************************************");
				printf("\nThis Rounds winner is Player: %d", winner);
				printf("\nTheyve scored this rounds points of %d", points);
				printf("\n************************************************************************");

				//Add Points to Players Score
				playerScores[(winner-1)] += points;
				printf("\n%d", playerScores[winner]);

				//Reset Points
				points = 0;
			}

			//If 13th round is over
			if (roundNumber == 13)
			{
				printf("\n\n**************************************************************************************************************");
				printf("\n\t\t\tEND OF GAME");
				Display(numPlayers, playerScores, 13);
				exit = 'N';
			}

			else
			{
				//Reset Round Loop
				round = 'Y';
				winningCard = 0;
				winner = 0;
			}
		}
#pragma endregion
	}while(exit != 'N');

	//If player Enters a minus number at any point of game Menu is shown
	//Menu to decide what to do
#pragma region Menu
	if (exit == 'N')
	{
		printf("\n\n************************************************************************");
		printf("\n\t\t\t\tMenu");
		printf("\n\t\t    Please Select an Option below");
		printf("\n    1- Continue\t   2-Exit\t3-Exit & Save\t4-Display Status\n");
		scanf("%d", &menuChoice);
		printf("\n************************************************************************");

		//Selected Menu Option
		switch (menuChoice)
		{
		case 1:
			return 1;
			break;
		case 2:
			return 0;
			break;
		case 3:
			SaveGame(playerCard, playerSuit, numPlayers, playerScores);
			break;
		case 4:
			Display(numPlayers, playerScores, (roundNumber-1));
			break;
		}
	}
#pragma endregion
}

//----------------------------------------------------------------------------
//New Game
void NewGame()
{
	//Declare Variables
	int numPlayers, cardNum, cardSuit;

#pragma region Declare Arrays
	//Declare Arrays
	//Card array is for numbered 1-13, repeated 4 times for suits
	int cards[52] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,
					  1,2,3,4,5,6,7,8,9,10,11,12,13,
					  1,2,3,4,5,6,7,8,9,10,11,12,13,
					  1,2,3,4,5,6,7,8,9,10,11,12,13 };

	//suit array is to assign the cards to the suits
	int suits[52] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,    //Diamonds
					  2,2,2,2,2,2,2,2,2,2,2,2,2,    //Hearts
					  3,3,3,3,3,3,3,3,3,3,3,3,3,    //Spades
					  4,4,4,4,4,4,4,4,4,4,4,4,4 };  //Clubs

	//Player 1-4 array to store player cards.
	int playerCard[players][card];
	int playerSuit[players][suit];

	//Player Score Array
	int playerScore[players] = { 0,0,0,0 };
#pragma endregion

	//Ask how many Players
	printf("Please enter number of players.Min 2 & Max 4:\t\t");
	scanf("%d", &numPlayers);

	//If too many players entered
	if (numPlayers > 4)
	{
		//Display that num over Max players
		printf("\nNumber entered is over MAX players allowed!!");
		printf("\nNumber of players changed to MAX of 4");

		//Change Number of Players to MAX
		numPlayers = 4;
	}

	//If too little players entered
	if (numPlayers < 2)
	{
		//Display that num over Max players
		printf("\nNumber entered is under MIN players allowed!!");
		printf("\nNumber of players changed to MIN of 2");

		//Change Number of Players to MAX
		numPlayers = 2;
	}

	//Assign player cards in player array
	for (int p = 0; p < numPlayers; p++)
	{
		//Generate Random cards
		for (int i = 0; i < 13; i++)
		{
			//Use Random class to pick player cards
			cardNum = cards[rand() % 52];
			cardSuit = suits[rand() % 52];

			//Assign card and suit to player
			playerCard[p][i] = cardNum;
			playerSuit[p][i] = cardSuit;
		}

		//Reset Random Class
		rand(time(NULL));
	}

	//Start Game
	PlayGame(playerCard, playerSuit, numPlayers, playerScore);
}

//----------------------------------------------------------------------------
//Continue Game- Here will read from file
void ContinueGame()
{
	//Create Arrays
	int playerCardLoad[players][card];
	int playerSuitLoad[players][suit];
	int playerScores[players];
	int winning, roundNum;

	//Declare Variables
	int numPlayers, numLines = 0;

	//Load Game details
#pragma region ReadFromFile
	//declare File Name
	FILE* gameStatus;
	FILE* gameScores;

	//Read
	gameStatus = fopen("gameStatus.txt", "r");
	gameScores = fopen("GameScore.txt", "r");

	// Check if File is Open
	if (gameStatus == NULL)
	{
		printf("Sorry File could not be opened\n");
	}

	else
	{
		//Read to end of file
		while (!feof(gameStatus))
		{
			for (int p = 0; p < numPlayers; p++)
			{
				//Generate Random cards
				for (int i = 0; i < 13; i++)
				{
					fscanf(gameStatus, "%d %d\n", &playerCardLoad[p][i], &playerSuitLoad[p][i]);
				}
			}

			//Close File
			fclose(gameStatus);
		}

		//Game Player Scores
		while (!feof(gameScores))
		{
			//Assign read scores to array
			for (int p = 0; p < numPlayers; p++)
			{
				fprintf(gameScores, "%d", playerScores[p]);
			}

			//Close File
			fclose(gameScores);
		}
	}
#pragma endregion

	//Display Game Status
	Display(numPlayers, playerScores, winning, roundNum);
}

//----------------------------------------------------------------------------
//Main
void main()
{
	//Declare Variables
	int initialise;

	//Title
	printf("*********** Welcome to the CardGame of War ***********");

	//Ask if starting a new game or loading one
	printf("\nPlease Enter 1 to start a New Game or 2 to Load a Saved Game:\t");
	scanf("%d", &initialise);

	//If Statement to use new or load game methods
	if (initialise == 2)
	{
		ContinueGame();
	}
	else
	{
		NewGame();
	}
}