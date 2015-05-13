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
*  PIT    05/04/2015  Update #4 - So Much to Delete AKA File Input/Output     *
*  PIT    05/11/2015  Continue Work on Update #4                              *
******************************************************************************/

#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

#define DUTCH 1                 //amount earned on Dutch Brothers gift cards
#define CHIP 1.5                //amount earned on Chipotle gift cards
#define SAND 2                	//amount earned on Sandwich Spot gift cards
#define NAME "Patrick"          //someone's name. Mine, in this case
#define SIZE 50                 //max value of data entered

//function prototypes - variables beginning with f are pulled from main but specific to the individual function
double StudentRaised (int fnum_sold, double price);

int main()
{
    int     id_num[SIZE],      	//student's 5 digit id number
            num_sold[SIZE],    	//number of cards sold by an individual
            tot_dutch,          //total dutch bros cards sold
            tot_chip,           //total chipotle cards sold
            tot_sand,           //total sandwich spot cards sold
            tot_card,           //total number of all gift cards sold
            j, k, u,   			//counters
            int_temp,           //temp value for storing one integer
            swap_flag,          //in bubble sort - swapped if 1, no swap if 0
            input_num;          //number being processed

    double  stu_raised[SIZE],  	//number an individual student raised
            dutch_raised,       //total amount from dutch brothers
            chip_raised,        //total amount from chipotle
            sand_raised,        //total amount from sandwich spot
            tot_raised,         //total amount raised
            tot_stu_raised,		//total of all values of stu_raised in array
            avg_stu_raised,		//average of all funds raised in the array
            min, max,			//assigns element to be highest or lowest value
            howmany,			//total number students
            db_temp,            //temp value for storing one double
            left;               //in bubble sort - number comparisons to make

    char    card_type[SIZE],   	//the type of card sold: D/d dutch, C/c chipotle, S/s sandwich
            ch_temp;            //temp value for storing one character

    ifstream    input;
    ofstream    output;

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
    tot_stu_raised = 0;
    avg_stu_raised = 0;
    input_num = 1;

    //open up files
    input.open("sales.txt");
    output.open("report.txt");
    
    cout << "                   ****** " << NAME << "'s Fundraiser Program ******\n";
    cout << "\n                       Press Enter to Generate Output File\n\n";
    cin.get();

    if(!input.is_open())
        cout << "ERROR: Unable to open input file.";
    else if (!output.is_open())
        cout << "ERROR: Unable to open output file.";
    else
    {
        output << "\t                ***Raw Data ***\n";
        output << "Student ID    Card Type    Number Sold    Revenue Raised\n" << fixed << setprecision(2);
        input >> id_num[k] >> card_type[k] >> num_sold[k];
        while (!input.eof())
        {
            cout << "Processing student " << input_num <<"...";
            switch (card_type[k]) //calculates values based upon char entered
            {
                case 'D': //dutch bros gift card calculations
                case 'd':
                {
                	tot_dutch = tot_dutch + num_sold[k];
                    stu_raised[k] = StudentRaised(num_sold[k], DUTCH);            
                    dutch_raised = dutch_raised + stu_raised[k];
                    break;
                }
                case 'C': //chipotle gift card calculations
                case 'c':
                {        
                    tot_chip = tot_chip + num_sold[k];
                    stu_raised[k] = StudentRaised(num_sold[k], CHIP);            
                    chip_raised = chip_raised + stu_raised[k];              
                    break;
                }
                case 'S': //sandwich spot gift card calculations
                case 's':
                {             
                	tot_sand = tot_sand + num_sold[k];
                    stu_raised[k] = StudentRaised(num_sold[k], SAND);            
                    sand_raised = sand_raised + stu_raised[k];           
                    break;
                }
            }
            
            output << id_num[k] << "\t\t\t" << card_type[k] << "\t\t\t" << setw(4) << num_sold[k] << "\t\t\t" << setw(7) << stu_raised[k] <<"\n";
            cout << "Done\n";
            k++;
            input_num++;
            input >> id_num[k] >> card_type[k] >> num_sold[k];
        }        
        cout << "\n\nProcessing Completed. Thank you.\n\n";
        howmany = k;    //readablilty
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

        output << "\n\n                ***Sorted Data - Revenue***\n";                
        output << "Student ID    Card Type    Number Sold    Revenue Raised\n";

        for (j = 0; j < howmany; j++) //loop to display array
        {
            output << id_num[j] << "\t\t\t" << card_type[j] << "\t\t\t" << setw(4) << num_sold[j] << "\t\t\t" << setw(7) << stu_raised[j] <<"\n";
        }
        

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

        avg_stu_raised = tot_stu_raised / howmany;	//finds the average of all values of stu_raised in array
        tot_card = (tot_dutch + tot_chip + tot_sand); //increases total cards by sum of 3 seperate gift cards
        tot_raised = (dutch_raised + chip_raised + sand_raised); //increases total revenue by sum of 3 seperate revenues

        output << "\n\n****************** End of Run Report ******************";
        output << "\n\nTotal number of Dutch Brothers gift cards sold\t" << setw(7)<< tot_dutch;
        output << "\nTotal number of Chipotle gift cards sold\t\t" << setw(7)<< tot_chip;
        output << "\nTotal number of Sandwich Spot gift cards sold\t" <<setw(7)<< tot_sand;
        output << "\nTotal number of all gift cards sold\t\t\t\t" << setw (7) << tot_card;
        output << "\n\nLargest amount of individual funds raised\t\t" << setw(7) << max;
        output << "\nSmallest amount of individual funds raised\t\t" << setw(7) << min;
        output << "\nAverage funds raised by a student\t\t\t\t" << setw(7) << avg_stu_raised;
        output << "\n\nTotal revenue from Dutch Brothers gift cards\t" <<setw(7)<< dutch_raised;
        output << "\nTotal revenue from Chipotle gift cards\t\t\t" << setw(7) << chip_raised;
        output << "\nTotal revenue from Sandwich Spot gift cards\t\t" << setw(7) << sand_raised;
        output << "\nTotal revenue raised\t\t\t\t\t\t\t" << setw(7) << tot_raised;

        input.close();
        output.close();
    }
	return 0;
}

double StudentRaised (int fnum_sold, double price)
{
    double fstu_raised;
    fstu_raised = fnum_sold * price;
    return fstu_raised;
}