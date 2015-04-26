/******************************************************************************
* Patrick Thiesen                March 25,2015            fundraiser.cpp      *
* This program computes the amount of funds raised during a fundraising event *
* Input: id_num, num_sold, card_type, yesno                                   *
* Output: tot_dutch, tot_chip, tot_sand, tot_card, stu_raised, dutch_raised,  *
*         chip_raised, sand_raised, tot_raised                                *
**************************************   HISTORY   ****************************
*  Who   Date          Description                                            *
*******************************************************************************
*  PIT    03/25/2015  Created Program                                         *
*  PIT    04/08/2015  Update #1 - Added Arrays & Funds Calculation Processes  *
*  PIT    04/13/2015  Bugfixes and Expanded Output Screen Options             *
*  PIT    04/19/2015  Added zero cards sold option                            *
******************************************************************************/

#include <iomanip>
#include <iostream>
using namespace std;

#define DUTCH 1                 //amount earned on Dutch Brothers gift cards
#define CHIP 1.5                //amount earned on Chipotle gift cards
#define SAND 2                	//amount earned on Sandwich Spot gift cards
#define NAME "Patrick"          //someone's name. Mine, in this case
#define SIZE 50					//the maximum size of the participating students
#define SKOOL "Charter Middle"	//name of the school, cuz why not

void ClearScreen (int num);			//clears screen with a loop of "\n"
void BubbleSort (double stu_raised[], int id_num[], int num_sold[], int howmany, char card_type[]); //sorts the array least to greatest by amount stuent sold

int main()
{
    int     id_num[SIZE],      	//student's 5 digit id number
            num_sold[SIZE],    	//number of cards sold by an individual
            tot_dutch,          //total dutch bros cards sold
            tot_chip,           //total chipotle cards sold
            tot_sand,           //total sandwich spot cards sold
            tot_card,           //total number of all gift cards sold
            j, k, v;			//counters

    double  stu_raised[SIZE],  	//number an individual student raised
            dutch_raised,       //total amount from dutch brothers
            chip_raised,        //total amount from chipotle
            sand_raised,        //total amount from sandwich spot
            tot_raised,         //total amount raised
            tot_stu_raised,		//total of all values of stu_raised in array
            avg_stu_raised,		//average of all funds raised in the array
            min, max,			//assigns element to be highest or lowest value
            howmany;			//total number students

    char    card_type[SIZE],   	//the type of card sold: D/d dutch, C/c chipotle, S/s sandwich
            yesno;              //loop controller, loops when == y or Y

    //initilization of variables
    tot_dutch = 0;
    tot_chip = 0;
    tot_sand = 0;
    tot_card = 0;
    dutch_raised = 0;
    chip_raised = 0;
    sand_raised = 0;
    tot_raised = 0;
    k = 0;
    v = 0;
    tot_stu_raised = 0;
    avg_stu_raised = 0;
    
    ClearScreen (24);
    cout << "       ****************** " << NAME << "'s Fundraiser Program ******************\n" << fixed << setprecision(2);
    cout << "\n                     Fundraiser for: " << SKOOL << " School";
    ClearScreen(3);
    cout << "\n\n                              Press Enter to Begin";
    ClearScreen(11);
    cin.get();
    ClearScreen (24);

    do    //post check loop asking for ID, card type, and number sold for each individual
    {
    	cout << "                   ****** " << NAME << "'s Fundraiser Program ******\n";
        do
        {
            cout << "\nPlease enter 5 digit student ID number:\t\t\t\t" << setw(10); 
            cin >> id_num[k];
            if (!(id_num[k] >= 10000 && id_num[k] <= 99999))
                cout << "\n  ==ERROR== \n**Invalid ID**\n";
        }
        while (!(id_num[k] >= 10000 && id_num[k] <= 99999)); //data validation requiring 5 digit ID

        do
        {
            cout << "\nPlease enter the type of card sold";
            cout << "\n(D - Dutch Brothers, C - Chipotle, S - Sandwich Spot):\t\t";
            cin >> card_type[k];
            if (card_type[k] != 'D' && card_type[k] != 'd' && card_type[k] != 'S' && card_type[k] != 's' && card_type[k] != 'C' && card_type[k] != 'c')
                cout << "\n  ==ERROR== \n**Invalid Character**\n\n";
        }
        while (card_type[k] != 'D' && card_type[k] != 'd' && card_type[k] != 'S' && card_type[k] != 's' && card_type[k] != 'C' && card_type[k] != 'c'); //data validation allowing only the 6 possible letters
        
        do
        {
			cout << "\nPlease enter the number of cards sold: \t\t\t\t" << setw(10);
			cin >> num_sold[k];
			if (num_sold[k] <= 0)
				cout << "\n  ==ERROR== \n**Invalid Number**\n";
		}
        while (num_sold[k] <= 0); //data validation for int only

        switch (card_type[k]) //calculates values based upon char entered
        {
            case 'D': //dutch bros gift card calculations
            case 'd':
            {
                if (num_sold[k] <= 0)
                	stu_raised[k] = 0;
                else
                {              
                	tot_dutch = tot_dutch + num_sold[k];
                	stu_raised[k] = DUTCH * num_sold[k];               
                	dutch_raised = dutch_raised + stu_raised[k];
            	}
                break;
            }
            case 'C': //chipotle gift card calculations
            case 'c':
            {
                if (num_sold[k] <= 0)
                	stu_raised[k] = 0;
                else
                {              
                	tot_chip = tot_chip + num_sold[k];
                	stu_raised[k] = CHIP * num_sold[k];
                	chip_raised = chip_raised + stu_raised[k];
            	}               
                break;
            }
            case 'S': //sandwich spot gift card calculations
            case 's':
            {
                if (num_sold[k] <= 0)
                	stu_raised[k] = 0;
                else
                {              
                	tot_sand = tot_sand + num_sold[k];
                	stu_raised[k] = SAND * num_sold[k];            
                	sand_raised = sand_raised + stu_raised[k];
            	}               
                break;
            }
        }         

        cout << "\n========================================================================";
        cout << "\nStudent " << id_num[k] << " raised the following amount for the school:\t$" << stu_raised[k];

        yesno = 'x'; //requires entering the validation loop

        do
        {
        	cout << "\n\nDo you have another student sale to enter? (y = yes n = no) "; //determines value of loop controller
        	cin >> yesno;
        	if (!(yesno == 'Y' || yesno== 'y' || yesno == 'N' || yesno== 'n'))
        		cout << "\n  ==ERROR== \n**Invalid Character**\n";
    	}
        while (!(yesno == 'Y' || yesno== 'y' || yesno == 'N' || yesno== 'n'));   //validation loop for valid character

        k ++;	//new student prep

        if (k > SIZE)	//kill switch
        {
        	yesno = 'x';
            cout << "\n                                  ===ERROR===";
        	cout << "\n                   **Maximum data storage has been reached**";
            cout << "\n               Please contact the program creator for assistance.";
        	cout << "\n                    The end of run report will now print.";
            ClearScreen(3);
            cout << "\n                                 Press enter.";
        	cin.get();
        }

        ClearScreen (24);
    }
    while (yesno == 'Y' || yesno == 'y'); //condition to begin loop again
    cin.get();
    howmany = k;    //readablilty for later in program

    do
    {
        if (v > 0) //sort by student raised - completes second time through
            BubbleSort(stu_raised, id_num, num_sold, howmany, card_type);            
        else
            cout << "\t                   ***Raw Data Entered***\n\n";
        cout << "\tStudent ID    Card Type    Number Sold    Revenue Raised\n";

        for (j = 0; j < howmany; j++) //loop to display array
        {
            cout << "\t  " << id_num[j] << "\t\t  " << card_type[j] << "\t     " << setw(4) << num_sold[j] << "\t     " << setw(7) << stu_raised[j] <<"\n";
        }
        cout << "\n                          Press enter to continue";        
        cin.get();
        ClearScreen(24);
        v++;    
    }
    while(v == 1);

    max = stu_raised[0];	//initilizing min/max after array is filled
    min = stu_raised[0]; 

    for (j = 0; j < howmany; j++)	//processing used portion of array
    {	
    	tot_stu_raised += stu_raised[j];	//totaling all values of stu_raised in array
    	if (stu_raised[j] > max)	//finding the max value of student raised funds
    		max = stu_raised[j];
    	if (stu_raised[j] < min)	//finding the min value of student raised funds
    		min = stu_raised[j];            
    }
    ClearScreen(8);

    avg_stu_raised = tot_stu_raised / howmany;	//finds the average of all values of stu_raised in array
	tot_card = (tot_dutch + tot_chip + tot_sand); //increases total cards by sum of 3 seperate gift cards
    tot_raised = (dutch_raised + chip_raised + sand_raised); //increases total revenue by sum of 3 seperate revenues


    ClearScreen(24);
    cout << "\n\n         ****************** End of Run Report - List ******************"; 
    cout << "\n\n      Total number of Dutch Brothers gift cards sold\t\t" << setw(7)<< tot_dutch;
    cout << "\n      Total number of Chipotle gift cards sold\t\t\t" << setw(7)<< tot_chip;
    cout << "\n      Total number of Sandwich Spot gift cards sold\t\t" <<setw(7)<< tot_sand;
    cout << "\n      Total number of all gift cards sold\t\t\t" << setw (7) <<tot_card;
    cout << "\n\n      Largest amount of individual funds raised\t\t\t" << setw(7) << max;
    cout << "\n      Smallest amount of individual funds raised\t\t" << setw(7) << min;
    cout << "\n      Average funds raised by a student\t\t\t\t" << setw(7) << avg_stu_raised;
    cout << "\n\n      Total revenue from Dutch Brothers gift cards\t\t" <<setw(7)<< dutch_raised;
    cout << "\n      Total revenue from Chipotle gift cards\t\t\t" << setw(7) << chip_raised;
    cout << "\n      Total revenue from Sandwich Spot gift cards\t\t" << setw(7) << sand_raised;
    cout << "\n      Total revenue raised\t\t\t\t\t" << setw(7) << tot_raised;
    ClearScreen(7);
    cout << "\n                          Press enter to continue";
    cin.get();
    ClearScreen(24);
    		
	return 0;
}

void ClearScreen (int num)
{
	int i;		//counter
	for (i = 0; i < num; i++)
		cout << "\n";
	return;
}

void BubbleSort (double stu_raised[], int id_num[], int num_sold[], int howmany, char card_type[])
{
    int     int_temp,   //temp value for storing one integer
            u,  //counter   
            swap_flag,  //swapped if 1, no swap if 0
            left;   //number comparisons to make
    double  db_temp;    //temp value for storing one double
    char    ch_temp;    //temp value for storing one character


    left = howmany - 1;
    do 
    {
        swap_flag = 0;
        for (u = 0; u < left; u++)
        {
            if (stu_raised[u] > stu_raised[u+1]) //bubble condition
            {
                db_temp = stu_raised[u];    //moves the student raised
                stu_raised[u] = stu_raised[u+1];
                stu_raised[u+1] = db_temp;

                int_temp = id_num[u];   //moves the id num
                id_num[u] = id_num[u+1];
                id_num[u+1] = int_temp;

                int_temp = num_sold[u]; //moves the num sold
                num_sold[u] = num_sold[u+1];
                num_sold[u+1] = int_temp;

                ch_temp = card_type[u]; //moves the card type
                card_type[u] = card_type[u+1];
                card_type[u+1] = ch_temp;

                swap_flag = 1;
            }
        }
        left--;
    }
    while ((left > 0) && (swap_flag == 1));
        cout << "\t                ***Sorted Data - Revenue***\n\n";
    return;
}