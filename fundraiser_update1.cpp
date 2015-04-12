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
******************************************************************************/

#include <iomanip>
#include <iostream>
using namespace std;

#define DUTCH 1                 //amount earned on Dutch Brothers gift cards
#define CHIP 1.5                //amount earned on Chipotle gift cards
#define SAND 2                	//amount earned on Sandwich Spot gift cards
#define NAME "Patrick"          //someone's name. Mine, in this case
#define SIZE 50					//the maximum size of the participating students

void ClearScreen (int);			//clears screen with a loop of "\n"

int main()
{
    int     id_num[SIZE],      //student's 5 digit id number
            num_sold[SIZE],    //number of cards sold by an individual
            tot_dutch,          //total dutch bros cards sold
            tot_chip,           //total chipotle cards sold
            tot_sand,           //total sandwich spot cards sold
            tot_card,           //total number of all gift cards sold
            j, k,				//counters
            howmany;			//total number students

    double  stu_raised[SIZE],  	//number an individual student raised
    		avg_raised,			//average of all funds raised in the array
            dutch_raised,       //total amount from dutch brothers
            chip_raised,        //total amount from chipotle
            sand_raised,        //total amount from sandwich spot
            tot_raised;         //total amount raised

    char    card_type[SIZE],   	//the type of card sold: D/d dutch, C/c chipotle, S/s sandwich
            yesno;              //loop controller, loops when = y or Y

    tot_dutch = 0;
    tot_chip = 0;
    tot_sand = 0;
    tot_card = 0;
    dutch_raised = 0;
    chip_raised = 0;
    sand_raised = 0;
    tot_raised = 0;
    id_num = 0;
    card_type = 0;
    num_sold = 0;
    k = 0;
    
    cout << "******************" << NAME << "'s Fundraiser Program******************\n" << fixed << setprecision(2);

    do    //post check loop asking for ID, card type, and number sold for each individual
    {
        while (!(id_num >= 10000 && id_num <=99999)) //data validation requiring 5 digit ID
        {
            cout << "\nPlease enter student ID number:\t\t\t\t\t" << setw(10); 
            cin >> id_num[k];
            if (!(id_num >= 10000 && id_num <=99999))
                cout << "Please enter a valid 5 digit ID\n";
        }

        while (card_type != 'D' && card_type != 'd' && card_type != 'S' && card_type != 's' && card_type != 'C' && card_type != 'c') //data validation allowing only the 6 possible letters
        {
            cout << "Please enter the type of card sold";
            cout << "\n(D - Dutch Brothers, C - Chipotle, S - Sandwich Spot):\t\t";
            cin >> card_type[k];
            if (card_type != 'D' && card_type != 'd' && card_type != 'S' && card_type != 's' && card_type != 'C' && card_type != 'c')
                cout << "Please enter a valid letter\n";
        }

        while (num_sold <= 0) //data validation for int only
        {
            cout << "Please enter the number of cards sold: \t\t\t\t" << setw(10); 
            cin >> num_sold[k];
            if (num_sold <= 0)
                cout << "Please enter a valid number greater than 0\n";
        }

        switch (card_type) //calculates values based upon char entered
        {
            case 'D': //dutch bros gift card calculations
            case 'd':
            {
                tot_dutch = tot_dutch + num_sold[k];
                stu_raised[k] = DUTCH * num_sold[k];
                dutch_raised = dutch_raised + stu_raised[k];
                break;
            }
            case 'C': //chipotle gift card calculations
            case 'c':
            {
                tot_chip = tot_chip + num_sold[k];
                stu_raised[k] = CHIP * num_sold[k];
                chip_raised = chip_raised + stu_raised[k];
                break;
            }
            case 'S': //sandwich spot gift card calculations
            case 's':
            {
                tot_sand = tot_sand + num_sold[k];
                stu_raised[k] = SAND * num_sold[k];
                sand_raised = sand_raised + stu_raised[k];
                break;
            }
        }

        cout << "\nStudent " << id_num << " raised the following amount for the school:\t$" << stu_raised;

        yesno = 'x' //requires entering the validation loop

        while (!(yesno == 'Y' || yesno== 'y')&&(yesno == 'N' || yesno== 'n'))	//validation loop for valid character
        {
        	cout << "\n\nDo you have another student sale to enter? (y = yes n = no)"; //determines value of loop controller
        	cin >> yesno;
        	if (!(yesno == 'Y' || yesno== 'y')&&(yesno == 'N' || yesno== 'n'))
        		cout << "\nThat is not a valid answer.";
    	}
        
        if (yesno == 'Y' || yesno== 'y')   //resets the values for the data validation loops at the beginning if loop controller positive
        {
            id_num = 0;         
            card_type = 0;     
            num_sold = 0;
        }

        k ++;	//new student prep

        if (k >= SIZE)	//kill switch
        	yesno = 'x';
        	cout << "\nMaximum data storage has been reached. \nPlease contact the program creator for assistance.";
        	cout <<  "\nThe end of run report will now print. \nPress enter.";
        	cin.get();

        ClearScreen (24);
    }
    while (yesno == 'Y' || yesno == 'y'); //condition to begin loop again

    howmany = k;	//readablilty

    for (j = 0; j < howmany; j++)	//calculations of used portion of the array
    {	

    }

    tot_card = (tot_dutch + tot_chip + tot_sand); //increases total cards by sum of 3 seperate gift cards
    tot_raised = (dutch_raised + chip_raised + sand_raised); //increases total revenue by sum of 3 seperate revenues






    cout << "\n******************End of Run Report******************"; //prints all values that have been totaled in the loop
    cout << "\n\nTotal number of Dutch Brothers gift cards sold\t\t" << setw(7)<< tot_dutch;
    cout << "\nTotal number of Chipotle gift cards sold\t\t" << setw(7)<< tot_chip;
    cout << "\nTotal number of Sandwich Spot gift cards sold\t\t" <<setw(7)<< tot_sand;
    cout << "\nTotal number of all gift cards sold\t\t\t" << setw (7) <<tot_card;
    cout << "\n\nTotal revenue from Dutch Brothers gift cards\t\t" <<setw(7)<< dutch_raised;
    cout << "\nTotal revenue from Chipotle gift cards\t\t\t" << setw(7) << chip_raised;
    cout << "\nTotal revenue from Sandwich Spot gift cards\t\t" << setw(7) << sand_raised;
    cout << "\nTotal revenue raised\t\t\t\t\t" << setw(7) << tot_raised;
    cout << "\n\n\n";

    return 0;
}

void ClearScreen (int num)
{
	int i;		//counter
	for (i = 0; i < num: i++)
		cout << "\n";
	return;
}