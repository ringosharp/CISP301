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
*  PIT    04/13/2015  Bugfixes                                                *
*  PIT    04/20/2015  Update #2 - Bubble Sort Added                           *
*  PIT    04/25/2015  Made Bubble Sort a Function                             *
*  PIT    04/27/2015  Update #3 - Everything is Functions                     *
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

//function prototypes - variables beginning with f are pulled from main but specific to the individual function
void ClearScreen (int num);		//clears screen with a loop of "\n"
void DashedLine (void);     //outputs
int IdNumber (void);    //gets the id number, includes data validation
char CardType (void);   //gets card type, includes data validation
int CardSold (void);    //gets num sold, includes data validation
double StudentRaised (int fnum_sold, char fcard_type);   //calculates the funds raised by a student
void BubbleSort (double fstu_raised[], int fid_num[], int fnum_sold[], int fhowmany, char fcard_type[]); //sorts the array least to greatest by amount stuent sold
void ReportCardSold (int ftot_dutch, int ftot_chip, int ftot_sand, int ftot_card);
void ReportSimpleCalcFunds (double fmax, double fmin, double favg_stu_raised);
void ReportRevenue (double fdutch_raised, double fchip_raised, double fsand_raised, double ftot_raised);

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
        DashedLine();
        id_num[k] = IdNumber();
        card_type[k] = CardType();
        num_sold[k] = CardSold();

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
                    stu_raised[k] = StudentRaised(num_sold[k], card_type[k]);            
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
                    stu_raised[k] = StudentRaised(num_sold[k], card_type[k]);            
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
                	stu_raised[k] = StudentRaised(num_sold[k], card_type[k]);            
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
    ReportCardSold(dutch_raised, chip_raised, sand_raised, tot_raised);
    ReportSimpleCalcFunds(max, min, avg_stu_raised);
    ReportRevenue(tot_dutch, tot_chip, tot_sand, tot_raised);
    ClearScreen(7);
    cout << "\n                          Press enter to continue";
    cin.get();
    ClearScreen(24);
    		
	return 0;
}

//Inserts a new line to clear the screen
void ClearScreen (int num)
{
	int i;		//counter
	for (i = 0; i < num; i++)
		cout << "\n";
	return;
}

//Outputs a dashed line
void DashedLine (void)
{
    cout << "\n--------------------------------------\n";
}

//Asks user for and validates the 5 digit student ID number
int IdNumber (void)
{
    int id_num;
    do
    {
        cout << "\nPlease enter 5 digit student ID number:\t\t\t\t" << setw(10); 
        cin >> id_num;
        if (!(id_num >= 10000 && id_num <= 99999))
            cout << "\n  ==ERROR== \n**Invalid ID**\n";
    }
    while (!(id_num >= 10000 && id_num <= 99999));
    return id_num;
}

//Asks user for and validates the card type
char CardType (void)
{
    char fcard_type;
    do
    {
        cout << "\nPlease enter the type of card sold";
        cout << "\n(D - Dutch Brothers, C - Chipotle, S - Sandwich Spot):\t\t";
        cin >> fcard_type;
        if (fcard_type != 'D' && fcard_type != 'd' && fcard_type != 'S' && fcard_type != 's' && fcard_type != 'C' && fcard_type != 'c')
            cout << "\n  ==ERROR== \n**Invalid Character**\n\n";
    }
    while (fcard_type != 'D' && fcard_type != 'd' && fcard_type != 'S' && fcard_type != 's' && fcard_type != 'C' && fcard_type != 'c');
    return fcard_type;
}

//Asks user for and validates the number of cards sold
int CardSold (void)
{
    int fnum_sold;
    do
    {
        cout << "\nPlease enter the number of cards sold: \t\t\t\t" << setw(10);
        cin >> fnum_sold;
        if (fnum_sold <= 0)
            cout << "\n  ==ERROR== \n**Invalid Number**\n";
    }
    while (fnum_sold <= 0);
    return fnum_sold;
}

//
double StudentRaised (int fnum_sold, char fcard_type)
{
    double fstu_raised;
    if (fcard_type == 'd' || fcard_type == 'D')
        fstu_raised = fnum_sold * DUTCH;
    else if (fcard_type == 'c' || fcard_type == 'C')
        fstu_raised = fnum_sold * CHIP;
    else
        fstu_raised = fnum_sold * SAND;
    return fstu_raised;
}

//Sorts the array of used values from least to greatest amount raised by student
void BubbleSort (double fstu_raised[], int fid_num[], int fnum_sold[], int fhowmany, char fcard_type[])
{
    int     int_temp,   //temp value for storing one integer
            u,          //counter   
            swap_flag,  //swapped if 1, no swap if 0
            left;       //number comparisons to make
    double  db_temp;    //temp value for storing one double
    char    ch_temp;    //temp value for storing one character


    left = fhowmany - 1;
    do 
    {
        swap_flag = 0;
        for (u = 0; u < left; u++)
        {
            if (fstu_raised[u] > fstu_raised[u+1]) //bubble condition
            {
                db_temp = fstu_raised[u];    //moves the student raised
                fstu_raised[u] = fstu_raised[u+1];
                fstu_raised[u+1] = db_temp;

                int_temp = fid_num[u];   //moves the id num
                fid_num[u] = fid_num[u+1];
                fid_num[u+1] = int_temp;

                int_temp = fnum_sold[u]; //moves the num sold
                fnum_sold[u] = fnum_sold[u+1];
                fnum_sold[u+1] = int_temp;

                ch_temp = fcard_type[u]; //moves the card type
                fcard_type[u] = fcard_type[u+1];
                fcard_type[u+1] = ch_temp;

                swap_flag = 1;
            }
        }
        left--;
    }
    while ((left > 0) && (swap_flag == 1));
        cout << "\t                ***Sorted Data - Revenue***\n\n";
    return;
}

//Outputs the cards sold
void ReportCardSold (int ftot_dutch, int ftot_chip, int ftot_sand, int ftot_card)
{
    cout << "\n\n      Total number of Dutch Brothers gift cards sold\t\t" << setw(7)<< ftot_dutch;
    cout << "\n      Total number of Chipotle gift cards sold\t\t\t" << setw(7)<< ftot_chip;
    cout << "\n      Total number of Sandwich Spot gift cards sold\t\t" <<setw(7)<< ftot_sand;
    cout << "\n      Total number of all gift cards sold\t\t\t" << setw (7) << ftot_card;
}

//Outputs the largest, smallest, and avg funds raised
void ReportSimpleCalcFunds (double fmax, double fmin, double favg_stu_raised)
{
    cout << "\n\n      Largest amount of individual funds raised\t\t\t" << setw(7) << fmax;
    cout << "\n      Smallest amount of individual funds raised\t\t" << setw(7) << fmin;
    cout << "\n      Average funds raised by a student\t\t\t\t" << setw(7) << favg_stu_raised;
}

//Outputs the revenue raised
void ReportRevenue (double fdutch_raised, double fchip_raised, double fsand_raised, double ftot_raised)
{
    cout << "\n\n      Total revenue from Dutch Brothers gift cards\t\t" <<setw(7)<< fdutch_raised;
    cout << "\n      Total revenue from Chipotle gift cards\t\t\t" << setw(7) << fchip_raised;
    cout << "\n      Total revenue from Sandwich Spot gift cards\t\t" << setw(7) << fsand_raised;
    cout << "\n      Total revenue raised\t\t\t\t\t" << setw(7) << ftot_raised;
}