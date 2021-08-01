#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void tellUser();

double regular(int &);

int main()
{
   const int SZ = 55; // size of arrays to hold employees
   string firstname, lastname, fullname, employee; //name of golfer 

   float hours, rate, overtime; //scores of four golfer
  // int total; // total of four rounds of golfer
   bool screenonly = false;

   ifstream inputFile; //input filename in program
   ofstream outputFile;

   //read input from file employees.txt
     tellUser(); 
     inputFile.open("employees.txt");
     if (inputFile.fail())
     { 
       cout <<"Error! opening file golfers.txt\n\n";
       cout <<"end of program";
     }
     else
     {
       outputFile.open("payroll.txt");
       if (outputFile.fail())
       {
          screenonly = true;
          cout <<" output file did not open\n";
          cout <<" output file will only be sent to the screen\n";
       } 
     cout <<"   First        Last     Employee      Hours        Rate        Regular      Overtime     Gross\n";
     cout <<"   Name         Name      Number       Worked       of Pay       Pay           Pay        Pay\n";
     cout <<"==============================================================================================\n";
     
     outputFile <<" First      Last     Employee      Hours        Rate        Regular      Overtime     Gross\n";
     outputFile <<" Name       Name     Number        Worked       of Pay        Pay          Pay         Pay\n";
     outputFile <<"=========================================================================================\n";
     while (inputFile >> firstname) // there is a line of data to read
     {
        inputFile >> lastname; // read golf score
        inputFile >> employee; // read golf score
        inputFile >> hours; // read golf score
        inputFile >> rate; // read first name of golfer
  //    inputFile >> lastname[i];// read last name of golf
  //
      cout<< setw(7) <<  firstname << setw(13) << lastname;
      cout<< setw(12) << employee << " " << setw(10) << hours << " ";
      cout<< setw(11) << rate << " " << setw(11) << regular <<  " \n";
     // cout<< setw(5) << total << " " << setw(7) << fixed << setprecision(2) << average << " \n";
     // cout<< firstname << " " << lastname << "\n";
    // cout <<"===================================================================================================\n";
    // cout <<"                      Total Gross Pay                                                             \n";

      if (!screenonly)
        {
          fullname = firstname + " " + lastname;      
          outputFile << setw(14) << left << fullname << " ";
          outputFile << setw(4) << fixed << right << employee << " "; 
          outputFile << setw(4) << fixed << right << hours << " ";
          outputFile << setw(4) << fixed << right << rate << " \n";
        }
    }
     inputFile.close(); //close the file after reading it
     cout << "\nInput file closed\n\n";
     if (!screenonly) outputFile.close();
    } 
    return 0;

}
/*
 *function
 *
 */
void tellUser()
{
   cout<<"\nThis program reads a file called golfers.txt,\n";
   cout<<"and it calculates the total and average for each golfer.\n";
   cout<<"output is written to the screen. \n\n";              //tell user what program does
}

double regular(int &)
{
  int empCount;
  double grossPay;
  double hours, rate;
  if(hours <= 40)
      grossPay = hours * rate;
  
}
