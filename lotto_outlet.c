#include <stdio.h>

/*usage of void functions is because:
1. It accomplishes its task and then returns control to the caller. 
2. The void function call is a stand-alone statement. (able to operate independently)*/

void instructions(){
 	printf("\n\t=================================================================\n");
	printf("\t==                        LOTTO CRAZE                          ==\n");
	printf("\t=================================================================\n");
	printf("\n\tHOW-TO-PLAY-GUIDE\n");
	printf("\n\tSelect six numbers from 1 to 58. Six random numbers from 1 to 58");
	printf("\n\n\twill be drawn and you win the jackpot prize by matching all of  ");
	printf("\n\n\tthe drawn numbers, in any order. If two or more persons win the ");
	printf("\n\n\tjackpot, payment for each winner is determined by dividing equally");
	printf("\n\n\tthe jackpot amount. You also win prizes if you match any 3, 4,  ");
	printf("\n\n\tor 5 numbers of the winning 6-number combination, in any order.");
	printf("\n\n\tIn entering the bet make sure you enter the right date!");
	printf("\n\n\t\t    Good luck on playing Ultra Lotto 6/58!");
	printf("\n");
	printf("\n\t=================================================================");
	printf("\n\n\t\t\tPress any key to continue... ");	
	
	/* getch() method pauses the Output Console until a key is pressed.
	It does not use any buffer to store the input character.*/
	getch();
	/* system() is a library function of stdlib.h header file. 
	This function is used to run system/ command prompt commands 
	and here cls is a command to clear the output screen.*/
	system("cls");
}

void ultra(){
	int outlet1,outlet2,outlet3;
	int serial1,serial2,serial3,serial4;
	int month,day,year;
	int c1, c2, c3, c4, c5, c6;
	char choice;
		system("cls");
		
		printf("\n\t\t\t    ULTRA LOTTO 6/58 OUTLET\n");
		printf("\t\t______________________________________________\n\n");
		printf("\n\t\t\t    Continue? (Y/N) : ");
		scanf(" %c",&choice);
		
		/* In order to generate random-like numbers, srand is usually 
		initialized to some distinctive runtime value, like 
		the value returned by function 'time' 
		This is distinctive enough for most trivial randomization needs.
		 */
		//This function returns the time since 00:00:00 UTC, January 1, 1970 (Unix timestamp) in seconds. 
		srand(time(NULL));
		/* rand()%10 to limit the max random number to be presented. 
		In this case modulo 10 to limit the random number produced to 9.
		since the rand func starts its counting from 0 */
		serial1=((rand()%9)+1);
		serial2=((rand()%9)+1);
		serial3=((rand()%9)+1);
		serial4=((rand()%9)+1);
		
		outlet1=((rand()%9)+1);
		outlet2=((rand()%9)+1);
		outlet3=((rand()%9)+1);
		
		if(choice=='Y'||choice=='y')
	{
		system("cls");
		printf("\n\t\t\t    ULTRA LOTTO 6/58 OUTLET\n");
		printf("\t\t______________________________________________\n\n");
		printf("\n\n\t\tEnter date (MM/DD/YYYY): ");
		scanf("%d%d%d",&month,&day,&year);
		
			if((month<=0||month>12)||(day<=0||day>31)||(year!=2023))
				{
					printf("\n\n\t\t\t\tInvalid Date! Try Again...");
					getch();
					ultra();
				}
			else
				{
					printf("\n\n\t\t\tEnter your bets: ");
					scanf("%d%d%d%d%d%d", &c1, &c2, &c3, &c4, &c5,&c6);
		
					FILE *lotto = fopen("bets.txt","a");
					fprintf(lotto,"%d %d %d %d %d %d %d %d %d %d%d%d %d%d%d%d\n",c1,c2,c3,c4,c5,c6,month,day,year,outlet1,outlet2,outlet3,serial1,serial2,serial3,serial4);
					fclose(lotto);
				
					printf("\n\n\t\t\tBets had been saved!");
					printf("\n\n\n\t\t\tPress any key to continue... ");
					getch();
					system("cls");
				}
	}
		else
	{
		system("cls");
	}
		
			
}		

void main(void){	
	//Introduction
    printf("\n\t\t\t\tULTRA LOTTO 6/58\n");
    printf("\t\t______________________________________________\n\n\n");
	printf("\tThis lotto program is created by a group of students from Bicol\n");
	printf("\tUniversity in compliance to the course IT101-Computer Programming\n");
	printf("\tas our project.\n\n");
	
	printf("\t\t\t____________________________\n\n");
	printf("\t\t\tTERRENZE JOSH M. BINAMIRA\n");
	printf("\t\t\t____________________________\n\n");
	printf("\t\t\tCHRISTIAN JOE B. BONEO\n");
	printf("\t\t\t____________________________\n\n");
	printf("\t\t\tMIZPA MAE B. CANCHELA\n");
	printf("\t\t\t____________________________\n");
	//Continue to the next part
	printf("\n\n\n\t\t     Press any key to continue.........");
	getch();
	system("cls");
	
	//MENU
    int choice;
    while(choice!=5){
        
	printf("\n\t\t\t    ULTRA LOTTO 6/58 OUTLET\n");
	printf("\t\t______________________________________________\n\n\n");
    printf("\t\t\t1. How-to-play\n\n");
    printf("\t\t\t2. Enter bet\n\n");
    printf("\t\t\t3. Exit\n\n");
    printf("\t\t\t_____________________\n");
    printf("\n\t\t\tEnter what to do: ");
    scanf("%d",&choice);
    
   switch(choice){
       case 1:
        system("cls");
        instructions();
        system("cls");
         break;
     case 2: 
        system("cls");
        ultra();
        system("cls");
          
         break;
        
     case 3:
          system("cls");
          printf("\n\n\n\n\t\t\tThank you, for playing with us! \n\n");
          exit(0);
        break;

    /*The default statement is executed if no case constant-expression 
	value is equal to the value of expression .*/
     default :
         printf("\n\n\n\t\t\t  Enter a valid number!!! \n\n");
         printf("\n\t\t\tPress any key to continue.......");
         getch();
    	 system("cls");
         break;
        }
  
        }
  
        getch();
     }
