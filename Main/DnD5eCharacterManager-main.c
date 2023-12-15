#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define d4 (srand(time(NULL)),rand() % 4 + 1)
#define d6 (srand(time(NULL)),rand() % 6 + 1)
#define d8 (srand(time(NULL)),rand() % 8 + 1)
#define d10 (srand(time(NULL)),rand() % 10 + 1)
#define d12 (srand(time(NULL)),rand() % 12 + 1)
#define d20 (srand(time(NULL)),rand() % 20 + 1)
#define d100 (srand(time(NULL)),rand() % 100 + 1)

struct CharacterData //The main struct for Character data
{

    char name[51], race, background, alignment, class, classSub; //Basic strings
    int characterLevel, exp, age; //basic nums
    int speed, initiative, armorClass, deathSaves, proficiencyBonus;//things that need to be calculated

    struct CharacterAttributes //Struct to keep track of al of the stats
    {int attributeValue, attributeModifier, savingthrow;}//I can't find a way to store the modifier value in the struct yet, so I'll have the call the modifier calc everytime :(
    Strength, Constitiution, Dexterity, Charsima, Wisdom, Inteligence;
                  
}PlayerCharacter;




int abilityModifierCalc(int attributeValue)//Array function to get stat modifier
{
    int modifier;
    int attributeMod[31] = {-5, -4, -4, -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10};
    attributeMod[modifier];
    int abilCalcReturn = modifier -1;
    if (abilCalcReturn <= -5 && abilCalcReturn>=10 ) {
        return abilCalcReturn;
    };
};


int proficiencyBonusCalc(int num)//Fucntion to determine the prof. bonus of the character
{
    int profBonusReturn;
    if ( num <= 1 || num <= 4)
    {
        return profBonusReturn = 2;
    }
    else if ( num <= 5 || num <= 8)
    {
        return profBonusReturn = 3;
    }
    else if ( num <= 9 || num <= 12)
    {
        return profBonusReturn = 4;
    }
    else if ( num <= 13 || num <= 16)
    {
        return profBonusReturn = 5;
    }
    else if ( num <= 17 || num <= 20)
    {
        return profBonusReturn = 6;
    }
};

//initialization of functions
int dieRoller(char userInput[150]);
int abilityModifierCalc(int);
int proficiencyBonusCalc(int);
void menu(char userInput);

//Gobal Variables
char userInput[150];


// TODO - Refractor the main menu out of the main function
int main() //
{
//File managing
    
    // For the banner
    FILE *banner = NULL;
    banner = fopen(".//ASCII//Banner.txt", "r");//read the banner file
    char bannerBuffer[1500];
    if (banner == NULL) //If the banner file doesn't exist
    {
        printf("Banner file not found");//error
        exit(-1);
    }
    
        
    
    //Prints banner
    while (fgets(bannerBuffer, 1500, banner) != NULL)
    {
        printf("%s", bannerBuffer);
    }
    fclose(banner);
    //Prints menu and asks for input
    printf("\nWelcome to the DnD character creator. What would you like to do?"); //Welcome message 
    
    
    while (1) // While loop for the main UI
    {  
        printf("\nEnter N to create a new character\nEnter L to load a character\nEnter D for the Die roller\nEnter 'X' to exit");
        printf("\n:");
        scanf(" %c", userInput); // Read a single character using %1s
        
        if (userInput[0] == 'N') // Compare the first character of userInput
        {
            // TODO
            printf("Not Completed");

        }
        else if (userInput[0] == 'L')
        {
            // TODO
            printf("Not Completed");
            
        }
        else if (userInput[0] == 'D')//Die Roller UI
        {
            dieRoller(userInput);
        }
        else if (userInput[0] == 'X')
        {
            printf("Are you sure you wish to exit? Y/N");
            printf(": ");
            scanf(" %c", userInput); // Read a single character using %1s
            
            if (userInput[0] == 'Y') // Compare the first character of userInput
            {
                exit(0);
            }
            else if (userInput[0] == 'N')
            {
                continue;
            }
            
        }
    }   
    
    return 0;
};


//Functions 
int dieRoller(char userInput[150])
{
  printf("What die would you like to roll?");
  printf("\nEnter 1 for d4\nEnter 2 for d6\nEnter 3 for d8\nEnter 4 for d10\nEnter 5 for d12\nEnter 6 for d20\nEnter 7 for d100\nEnter 'X' to exit");
  printf("\n: ");
  scanf(" %c", &userInput[0]);
  
  if (userInput[0] == '1')
  {
    printf("Rolling d4");
    printf("\nYou got %d",d4);
    printf("Would you like to roll again? Y/N");
    printf(": ");
    scanf(" %c", &userInput[0]);
    
    if (userInput[0] == 'Y')
    {
      dieRoller(userInput);
    }
    else if (userInput[0] == 'N')
    {
      //menu(userInput);
    }
  }
  else if (userInput[0] == '2')
  {
    printf("Rolling d6");
    printf("\nYou got %d",d6);
    printf("Would you like to roll again? Y/N");
    printf(": ");
    scanf(" %c", &userInput[0]);
    
    if (userInput[0] == 'Y')
    {
      dieRoller(userInput);
    }
    else if (userInput[0] == 'N')
    {
      //menu(userInput);
    }
  }
  else if (userInput[0] == '3')
  {
    printf("Rolling d8");
    printf("\nYou got %d",d8);
  }
  else if (userInput[0] == '4')
  {
    printf("Rolling d10");
    printf("\nYou got %d",d10);
  }
  else if (userInput[0] == '5')
  {
    printf("Rolling d12");
    printf("\nYou got %d",d12);
  }
  else if (userInput[0] == '6')
  {
    printf("Rolling d20");
    printf("\nYou got %d",d20);
  }
  else if (userInput[0] == '7')
  {
    printf("Rolling d100");
    printf("\nYou got %d",d100);
  }
  else
  {
    printf("Error");
  }
}