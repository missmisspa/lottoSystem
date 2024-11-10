#include <stdio.h>
#include <stdlib.h>

int winners(com1, com2, com3, com4, com5, com6,num1, num2, num3, num4, num5, num6){
			int count=0;
					if(com1==num1|| com1==num2 || com1==num3 || com1==num4 || com1==num5 || com1==num6)
						{
    						count++;  
						}
					if(com2==num1|| com2==num2 || com2==num3 || com2==num4 || com2==num5 || com2==num6)
						{
    						count++;  
						}
					if(com3==num1|| com3==num2 || com3==num3 || com3==num4 || com3==num5 || com3==num6)
						{
    						count++;  
						}
					if(com4==num1|| com4==num2 || com4==num3 || com4==num4 || com4==num5 || com4==num6)
						{
    						count++;  
						}
					if(com5==num1|| com5==num2 || com5==num3 || com5==num4 || com5==num5 || com5==num6)
						{
    						count++;  
						}
					if(com6==num1|| com6==num2 || com6==num3 || com6==num4 || com6==num5 || com6==num6)
						{
    						count++;  
						}
	return count;
}

void prizes(){
	int num1, num2, num3, num4, num5, num6, mm, dd, yyyy,s_outlet,serial_number; 
	double jackpot;
	
	FILE *lotto = fopen("lotto_results_58.txt","r");
	if(lotto==NULL)
			{
				printf("\n\t\t\t\t     Prizes\n");
				printf("\t\t______________________________________________\n");
				printf("\n\t\t\t\tFILE NOT FOUND!!!\n");
				printf("\n\n\n\t\t\tPress any key to continue... ");
				getch();
				system("cls");
			}
	else
		{
			fscanf(lotto, "%d %d %d %d %d %d %d %d %d %d %lf\n", &num1, &num2, &num3, &num4, &num5, &num6, &mm, &dd, &yyyy, &s_outlet, &jackpot);
			
			printf("\n\t\t\t\t     Prizes\n");
			printf("\t\t______________________________________________\n");
			printf("\n\t\t\t\t !!!JACKPOT!!!\n");
			printf("\n\t\t\t     ~~~PHP%.2lf!!!~~~\n",jackpot);
			printf("\n\t\t\t  !!!5-COMBINATION PRICE!!!\n");
			printf("\n\t\t\t\t~~~PHP120,000~~~\n");
			printf("\n\t\t\t  !!!4-COMBINATION PRICE!!!\n");
			printf("\n\t\t\t\t ~~~PHP2,000~~~\n");
			printf("\n\t\t\t  !!!3-COMBINATION PRICE!!!\n");
			printf("\n\t\t\t\t  ~~~PHP100~~~\n\n\n");
			
			fclose(lotto);
		}
	
		printf("\n\t\t\tPress any key to continue... ");
		getch();
		system("cls");
}

void check_winners(){

	int com1, com2, com3, com4, com5, com6, month, day, year; 
	int num1, num2, num3, num4, num5, num6, mm, dd, yyyy; 
	int outlet,s_outlet,serial_number; 
	int winner6=0, winner5=0, winner4=0, winner3=0;
	int count=0;
	
	double price5=120000,price4=2000,price3=100;
	double tp5,tp4,tp3,tjp;
	double jackpot;
	 
	FILE *bets = fopen("bets.txt", "r");
	FILE *lotto = fopen("lotto_results_58.txt","r");
		if(bets==NULL||lotto==NULL)
			{
				printf("\n\t\t\t\tWINNERS\n");
				printf("\t\t______________________________________________\n");
				printf("\n\t\t\t\tFILE NOT FOUND!!!\n");
				printf("\n\n\n\t\t\tPress any key to continue... ");
				getch();
				system("cls");
			}
		else
			{
				fscanf(lotto, "%d %d %d %d %d %d %d %d %d %d %lf\n", &num1, &num2, &num3, &num4, &num5, &num6, &mm, &dd, &yyyy, &s_outlet, &jackpot);
				
				while (!feof(bets))
				{ 
					fscanf(bets, "%d %d %d %d %d %d %d %d %d %d %d\n", &com1, &com2, &com3, &com4, &com5, &com6, &month, &day, &year, &outlet, &serial_number);
					count = winners(com1, com2, com3, com4, com5, com6,num1, num2, num3, num4, num5, num6);									
						if(count==6&&((month==mm)&&(day==dd)&&(year==yyyy)))
						{
							FILE *six;
							six = fopen("six_combi.out","a");
							fprintf(six,"%d %d %d %d %d %d %d %d\n",outlet,serial_number, com1, com2, com3, com4, com5, com6);
							fclose(six);
							winner6++;
						}
						if(count==5&&((month==mm)&&(day==dd)&&(year==yyyy)))
						{
							FILE *five;
							five = fopen("five_combi.out","a");
							fprintf(five,"%d %d %d %d %d %d %d %d\n",outlet,serial_number, com1, com2, com3, com4, com5, com6);
							fclose(five);
							winner5++;
						}
						if(count==4&&((month==mm)&&(day==dd)&&(year==yyyy)))
						{
							FILE *four;
							four = fopen("four_combi.out","a");
							fprintf(four,"%d %d %d %d %d %d %d %d\n",outlet,serial_number, com1, com2, com3, com4, com5, com6);
							fclose(four);
							winner4++;
						}
						if(count==3&&((month==mm)&&(day==dd)&&(year==yyyy)))
						{
							FILE *three;
							three = fopen("three_combi.out","a");
							fprintf(three,"%d %d %d %d %d %d %d %d\n",outlet,serial_number, com1, com2, com3, com4, com5, com6);
							fclose(three);
							winner3++;
						}						
				}
				
				tp5=price5*winner5;
				tp4=price4*winner4;
				tp3=price3*winner3;
				tjp=jackpot/winner6;
				
				FILE *total = fopen("total_winners.out","a");
				fprintf(total,"%d %d %d %d %d %d %d %d %d %d\n",mm,dd,yyyy,s_outlet,num1,num2,num3,num4,num5,num6);
				fprintf(total,"%.2lf %d\n",jackpot,winner6);
				fprintf(total,"%.2lf %d %.2lf\n",price5,winner5,tp5);
				fprintf(total,"%.2lf %d %.2lf\n",price4,winner4,tp4);
				fprintf(total,"%.2lf %d %.2lf\n\n",price3,winner3,tp3);
			
				fclose(total);
				fclose(bets);
				fclose(lotto);
				
				printf("\t\t__________________________________________________\n");	
				
				if(mm==1){
					printf("\t\t\tDRAW DATE : January  %d  %d\n",dd,yyyy);
					printf("\t\t  ______________________________________________\n");
				}
				if(mm==2){
					printf("\t\t\tDRAW DATE : February %d  %d\n",dd,yyyy);
					printf("\t\t  ______________________________________________\n");
				}
				if(mm==3){
					printf("\t\t\tDRAW DATE : March    %d  %d\n",dd,yyyy);
					printf("\t\t  ______________________________________________\n");
				}
				if(mm==4){
					printf("\t\t\tDRAW DATE : April    %d  %d\n",dd,yyyy);
					printf("\t\t  ______________________________________________\n");
				}
				if(mm==5){
					printf("\t\t\tDRAW DATE : May      %d  %d\n",dd,yyyy);
					printf("\t\t  ______________________________________________\n");
				}
				if(mm==6){
					printf("\t\t\tDRAW DATE : June     %d  %d\n",dd,yyyy);
					printf("\t\t  ______________________________________________\n");
				}
				if(mm==7){
					printf("\t\t\tDRAW DATE : July     %d  %d\n",dd,yyyy);
					printf("\t\t  ______________________________________________\n");
				}
				if(mm==8){
					printf("\t\t\tDRAW DATE : August   %d  %d\n",dd,yyyy);
					printf("\t\t  ______________________________________________\n");
				}
				if(mm==9){
					printf("\t\t\tDRAW DATE :September %d  %d\n",dd,yyyy);
					printf("\t\t  ______________________________________________\n");
				}
				if(mm==10){
					printf("\t\t\tDRAW DATE : October  %d  %d\n",dd,yyyy);
					printf("\t\t  ______________________________________________\n");
				}
				if(mm==11){
					printf("\t\t\tDRAW DATE : November %d  %d\n",dd,yyyy);
					printf("\t\t  ______________________________________________\n");
				}
				if(mm==12){
					printf("\t\t\tDRAW DATE : December %d  %d\n",dd,yyyy);
					printf("\t\t  ______________________________________________\n");
				}
						
				printf("\t\t\t\t   JACKPOT WINNERS\n\n");
				if(winner6==0){
					tjp=0;
				}
				printf("\t\tTotal winners: %d \tTotal winnings each: %.2lf\n\n",winner6,tjp);
				printf("\n\t\t\t     5-COMBINATION MATCH WINNERS\n\n");
				printf("\t\tTotal winners: %d \tTotal winnings     : %.2lf\n\n",winner5,(price5*winner5));
				printf("\n\t\t\t     4-COMBINATION MATCH WINNERS\n\n");
				printf("\t\tTotal winners: %d \tTotal winnings     : %.2lf\n\n",winner4,(price4*winner4));
				printf("\n\t\t\t     3-COMBINATION MATCH WINNERS\n\n");
				printf("\t\tTotal winners: %d \tTotal winnings     : %.2lf\n\n",winner3,(price3*winner3));
			}
			
		printf("\n\t\t\tPress any key to continue... ");
		getch();
		system("cls");	
}

void instructions(){
		printf("\n\t\t\t\tInstructions\n");
		printf("\t\t______________________________________________\n\n\n");
		printf("\n\tIn using bet search, Enter the 6-digit combination that you wanted\n\n");
		printf("\n\tto check on if it got betted on already after entering your 6-digit\n\n");
		printf("\n\tcombination if any of your bet matches it will show the 6-digit \n\n");
		printf("\n\tcombination, the date you've betted on that combination an its serial\n\n");
		printf("\n\tnumber.\n\n");
		printf("\n\n\n\t\t\tPress any key to continue... ");
		getch();
		system("cls");
}

void bet_search(){
	int com1, com2, com3, com4, com5, com6, month, day, year; 
	int num1, num2, num3, num4, num5, num6; 
	int outlet, serial_number; 
	int count,cnt;
	char cont,conti;  
	
		FILE *prev = fopen("lotto_prev_results_58.txt", "r");
		if(prev==NULL){
			printf("\n\t\t\t\tBet Search\n");
			printf("\t\t______________________________________________\n");
			printf("\n\t\t\t\tFILE NOT FOUND!!!\n");
			printf("\n\n\n\t\t\tPress any key to continue... ");
			getch();
			system("cls");
		}
		else{
		
		instructions();
		
		printf("\n\t\t\t\tBet Search\n");
		printf("\t\t______________________________________________\n");
		printf("\n\t\t\tContinue? (Y/N) : ");
		scanf(" %c", &conti);
		
		if(conti=='Y'||conti=='y'){
			system("cls");
			printf("\n\t\t\t\tBet Search\n");
			printf("\t\t______________________________________________\n");
			printf("\n\t\t6-Digit Combination to find: "); 
			scanf("%d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6);
			printf("\t\t______________________________________________\n");
			

			while (!feof(prev))
			{ 
				fscanf(prev, "%d %d %d %d %d %d %d %d %d %d %d\n", &com1, &com2, &com3, &com4, &com5, &com6, &month, &day, &year);
				
					if((com1==num1|| com1==num2 || com1==num3 || com1==num4 || com1==num5 || com1==num6)&&(com2==num1|| com2==num2 || com2==num3 || com2==num4 || com2==num5 || com2==num6)&&(com3==num1|| com3==num2 || com3==num3 || com3==num4 || com3==num5 || com3==num6)&&(com4==num1|| com4==num2 || com4==num3 || com4==num4 || com4==num5 || com4==num6)&&(com5==num1|| com5==num2 || com5==num3 || com5==num4 || com5==num5 || com5==num6)&&(com6==num1|| com6==num2 || com6==num3 || com6==num4 || com6==num5 || com6==num6))
						{
    						printf("\n\t\t6-Combination Digits: %d %d %d %d %d %d\n",com1,com2,com3,com4,com5,com6);
    						printf("\n\t\tDate	(MM/DD/YYYY): %d %d %d\n",month,day,year);
    						printf("\t\t______________________________________________\n");
						}
			}
							printf("\n\n\n\t\t\tYour bets had not been selected!... ");
							printf("\n\n\n\t\t\tPress any key to continue... ");
							getch();
							system("cls");
		}
		
		else
		{
			system("cls");
		}		
}
	}

void bet_history(){
	int com1, com2, com3, com4, com5, com6, month, day, year; 
	int num1, num2, num3, num4, num5, num6; 
	int outlet, serial_number; 
	int count; 

	printf("\n\t\t\t\tBET HISTORY\n");
	printf("\t\t______________________________________________\n");
	 
	FILE *bets = fopen("bets.txt", "r");
	while (!feof(bets)){ 
		fscanf(bets, "%d %d %d %d %d %d %d %d %d %d %d\n", &com1, &com2, &com3, &com4, &com5, &com6, &month, &day, &year, &outlet, &serial_number);
		
		printf("\n\n\t\tCombination : %d %d %d %d %d %d",com1, com2, com3, com4, com5, com6); 
		printf("\n\n\t\tSerial Number : %d",serial_number); 
		printf("\n\n\t\tDate :  %d %d %d", month, day, year); 
		printf("\n\t\t______________________________________________\n\n");
}		
		printf("\n\n\n\t\t\tPress any key to continue... ");
		getch();
		system("cls");
}

void combination_draw(){
	int com1,com2,com3,com4,com5,com6,month, day, year,outlet=58,n=6,i;
	double jackpot; 
	char another;
	char cont;
	
	system("cls");
	printf("\n\t\t\t\tULTRA LOTTO 6/58\n");
	printf("\t\t______________________________________________\n\n\n");
	printf("\n\t\t\t\tContinue? (Y/N) : ");
	scanf(" %c", &cont);
	
	if(cont=='Y' || cont=='y'){
			do
		{
			system("cls");
			FILE *lotto;
			FILE *prev;
			prev = fopen("lotto_prev_results_58.txt","a");
			lotto = fopen("lotto_results_58.txt","w");
	
		if(lotto==NULL)
		{
			printf("\n\t\t\t\tULTRA LOTTO 6/58\n");
			printf("\t\t______________________________________________\n\n\n");
			printf("\n\n\t\tFile not found!!!\n");
			printf("\n\n\t\t\tPress any key to continue.......");
		    getch();
		    system("cls");
		}
		else
		{
			if(prev==NULL)
			{
				printf("\n\t\t\t\tULTRA LOTTO 6/58\n");
				printf("\t\t______________________________________________\n\n\n");
				printf("\n\n\t\tFile not found!!!\n");
				printf("\n\n\t\t\tPress any key to continue.......");
    			getch();
    			system("cls");
			}
			else
			{
				system("cls");
				printf("\n\t\t\t\tULTRA LOTTO 6/58\n");
				printf("\t\t______________________________________________\n\n\n");
				printf("\n\n\t\tEnter date (MM/DD/YYYY): ");
				scanf("%d%d%d",&month,&day,&year);
				
				if((month<=0||month>12)||(day<=0||day>31)||(year!=2023))
				{
					printf("\n\n\t\t\t\tInvalid Date! Try Again...");
					getch();
					combination_draw();
				}
				
				printf("\n\n\t\tEnter Jackpot Prize: ");
				scanf("%lf",&jackpot);
	
				srand(time(NULL)); 
	    				int r1=(rand()%6);
	    				int rr1=(rand()%8+1);
	    				int r2=(rand()%6);
	    				int rr2=(rand()%8+1);
	    				int r3=(rand()%6);
	    				int rr3=(rand()%8+1);
	    				int r4=(rand()%6);
	    				int rr4=(rand()%8+1);
	    				int r5=(rand()%6);
	    				int rr5=(rand()%8+1);
	    				int r6=(rand()%6);
	    				int rr6=(rand()%8+1);
	    				
						fprintf(lotto,"%d%d %d%d %d%d %d%d %d%d %d%d ",r1,rr1,r2,rr2,r3,rr3,r4,rr4,r5,rr5,r6,rr6);
						fprintf(prev,"%d%d %d%d %d%d %d%d %d%d %d%d ",r1,rr1,r2,rr2,r3,rr3,r4,rr4,r5,rr5,r6,rr6);
	
				fprintf(prev,"\t%d %d %d \n",month,day,year);
				fprintf(lotto,"%d %d %d %d %.2lf\n",month,day,year,outlet,jackpot);
				fclose(lotto);
				fclose(prev);
				printf("\n\n\t\t\tGenerate another combination? (Y/N): ");
				scanf(" %c",&another);
			}
	}
}
	while(another=='Y'||another=='y');
	}	
		else
		{
			printf("\n\n\t\t\tPress any key to continue.......");
    	    getch();
    	    system("cls");
		}
}

void main(void){
	
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
	
	int choice;
    while(choice!=6){
	printf("\n\t\t\t    ULTRA LOTTO 6/58 PCSO MAIN\n");
	printf("\t\t______________________________________________\n\n\n");
    printf("\t\t\t1. Draw Winning Combination\n\n");
    printf("\t\t\t2. Check bet history\n\n");
    printf("\t\t\t3. Bet Search\n\n");
    printf("\t\t\t4. Check Winners\n\n");
    printf("\t\t\t5. Prizes\n\n");
    printf("\t\t\t6. Exit\n\n");
    printf("\t\t\t_____________________\n");
    printf("\n\t\t\tEnter what to do: ");
    scanf("%d",&choice);
	
	switch(choice){
    	case 1:
        system("cls");
        combination_draw();
        system("cls");
        break;
         
    	case 2: 
        system("cls");
        bet_history();
        system("cls");
        break;
         
    	case 3: 
        system("cls");
        bet_search();
        system("cls");  
        break;
         
    	case 4: 
        system("cls");
        check_winners();
        system("cls");  
        break;
		        
    	case 5:
        system("cls");
    	prizes();
    	system("cls");
        break;
        
        case 6:
        system("cls");
    	exit(0);
        break;
        
     default :
         system("cls");
         getch();
         printf("\n\tEnter a valid number\n\n");
         printf("\tPress any key to continue.......");
         getch();
        system("cls");
         break;
        }
	}
}

