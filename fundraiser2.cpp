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
*  PIT    03/26/2015  Changed to remember individual users                    *
******************************************************************************/

#include <iomanip>
#include <iostream>
#include <stream>
#include <fstream>
using namespace std;

#define DUTCH 1                 //amount earned on Dutch Brothers gift cards
#define CHIP 1.5                //amount earned on Chipotle gift cards
#define SAND 2.5                //amount earned on Sandwich Spot gift cards
#define NAME "Patrick"          //someone's name. Mine, in this case

//create functions to run data validation loops?

int main()
{
    int     id_num,             //student's 5 digit id number
            num_sold,           //number of cards sold by an individual
            tot_dutch,          //total dutch bros cards sold
            tot_chip,           //total chipotle cards sold
            tot_sand,           //total sandwich spot cards sold
            tot_card;           //total number of all gift cards sold

    double  //stu_raised,         //number an individual student raised
            dutch_raised,       //total amount from dutch brothers
            chip_raised,        //total amount from chipotle
            sand_raised,        //total amount from sandwich spot
            tot_raised;         //total amount raised

    char    card_type,          //the type of card sold: D/d dutch, C/c chipotle, S/s sandwich
            yesno,              //if statement controller, if == true when y or Y
            yesno_loop;         //loop controller, loops when y or Y

    string  admin_pass;         //password provided to admin to allow additional queries to database

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

    cout << "******************" << NAME << "'s Fundraiser Program******************\n" << fixed << setprecision(2);
    while (!(id_num >= 10000 && id_num <=99999)) //data validation requiring 5 digit ID
        {
            cout << "\nWhat is your student ID number:\t\t\t\t\t" << setw(10); 
            cin >> id_num;
            if (!(id_num >= 10000 && id_num <=99999))
                cout << "Please enter a valid 5 digit ID\n";
        }
    if (id_num //matches the name of a txt file)
    {
        cout << "Would you like to see your previous sales? (y = yes n = no)";
        cin >> yesno;
        if (yesno == 'Y' || yesno == 'y')
        {
            yesno = x;
            string line;
            ifstream myfile (std::string(id_num+ ".txt").c_str());
            if (myfile.is_open())
            {
                while ( getline (myfile,line) )
                {
                    cout << line << '\n';
                }
                myfile.close();
            }
        }    
        else
        {
            cout << "Do you have new data to enter? (y = yes n = no)";
            cin >> yesno;
            if (yesno == 'y' || yesno == 'Y')
            {
                yesno = x;
                //go to do loop?
            }
            else
            {
                cout << "Well then there's nothing for you here then. Goodbye.";
                //return 0; ?? Press any key to continue?
            }
        }
    }
    else
    {
        cout << "There is no record of this ID logged. \nWould you like to try a different ID? (y = yes n = no)";
        cin >> yesno;
        if (yesno == 'Y' || yesno == 'y')
        {
            yesno = x;
            id_num = 0;
            if //(id_num != file name in database)
            {
                while (!(id_num >= 10000 && id_num <=99999)) //data validation requiring 5 digit ID
                {
                    cout << "\nWhat is your student ID number:\t\t\t\t\t" << setw(10); 
                    cin >> id_num;
                    if (!(id_num >= 10000 && id_num <=99999))
                        cout << "Please enter a valid 5 digit ID\n";
                }
                if //(id_num != file name in database)
                    cout << "There is no record of this ID. Please enter password to try again"
            }

        }
    }
        else
        {
            cout << "A new entry with your ID will be entered to store your sales." << endl; //or something like that
            cout << "Press enter to continue"
            //command to contine on press of enter
        }

  



    do    //post check loop asking for ID, card type, and number sold for each individual
    {
        while (card_type != 'D' && card_type != 'd' && card_type != 'S' && card_type != 's' && card_type != 'C' && card_type != 'c') //data validation allowing only the 6 possible letters
        {
            cout << "Please enter the type of card sold" << endl;
            cout << "(D - Dutch Brothers, C - Chipotle, S - Sandwich Spot):\t\t";
            cin >> card_type;
            if (card_type != 'D' && card_type != 'd' && card_type != 'S' && card_type != 's' && card_type != 'C' && card_type != 'c')
                cout << "Please enter a valid letter\n";
        }

        while (num_sold <= 0) //data validation for int only
        {
            cout << "Please enter the number of cards sold: \t\t\t\t" << setw(10); 
            cin >> num_sold;
            if (num_sold <= 0)
                cout << "Please enter a valid number greater than 0\n";
        }

        switch (card_type) //calculates values based upon char entered
        {
            case 'D': //dutch bros gift card calculations
            case 'd':
            {
                tot_dutch = tot_dutch += num_sold;
                stu_raised = DUTCH * num_sold;
                dutch_raised = dutch_raised = +stu_raised;
                break;
            }
            case 'C': //chipotle gift card calculations
            case 'c':
            {
                tot_chip = tot_chip += num_sold;
                stu_raised = CHIP * num_sold;
                chip_raised = chip_raised += stu_raised;
                break;
            }
            case 'S': //sandwich spot gift card calculations
            case 's':
            {
                tot_sand = tot_sand += num_sold;
                stu_raised = SAND * num_sold;
                sand_raised = sand_raised += stu_raised;
                break;
            }
        }

        tot_card = tot_card += (tot_dutch + tot_chip + tot_sand); //increases total cards by sum of 3 seperate gift cards
        tot_raised = tot_raised += (dutch_raised + chip_raised + sand_raised); //increases total revenue by sum of 3 seperate revenues

        cout << "\nStudent " << id_num << " raised the following amount for the school:\t$" << stu_raised;
        cout << "\n\nDo you have another student sale to enter? (y = yes n = no)"; //determines value of loop controller
        cin >> yesno_loop;
        
        if (yesno_loop == 'Y' || yesno_loop == 'y')   //resets the values for the data validation loops at the beginning if loop controller positive
        {
            id_num = 0;         
            card_type = 0;     
            num_sold = 0;
        }  
    }
    while (yesno_loop == 'Y' || yesno_loop == 'y'); //condition to begin loop again

    ofstream myfile (std::string(sample_num + ".txt").c_str());
    if (myfile.is_open())
    {
        myfile << tot_dutch << endl;
        myfile << tot _chip << endl;
        myfile << tot_sand << endl;
        myfile << tot_card << endl;
        myfile << dutch_raised << endl;
        myfile << chip_raised << endl;
        myfile << sand_raised << endl;
        myfile << tot_raised << endl;
        myfile.close();
  }

    cout << "******************End of Run Report******************"; //prints all values that have been totaled in the loop
    cout << "\n\nTotal number of Dutch Brothers gift cards sold\t\t" << setw(6)<< tot_dutch;
    cout << "\nTotal number of Chipotle gift cards sold\t\t" << setw(6)<< tot_chip;
    cout << "\nTotal number of Sandwich Spot gift cards sold\t\t" <<setw(6)<< tot_sand;
    cout << "\nTotal number of all gift cards sold\t\t\t" << setw (6) <<tot_card;
    cout << "\n\nTotal revenue from Dutch Brothers gift cards\t\t" <<setw(6)<< dutch_raised;
    cout << "\nTotal revenue from Chipotle gift cards\t\t\t" << setw(6) << chip_raised;
    cout << "\nTotal revenue from Sandwich Spot gift cards\t\t" << setw(6) << sand_raised;
    cout << "\nTotal revenue raised\t\t\t\t\t" << setw(6) << tot_raised;
    cout << "\n\n\n";

    return 0;
}