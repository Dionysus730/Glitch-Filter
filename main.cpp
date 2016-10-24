/*

Program to simulate filtering out glitches in sensor readings.

 */


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <deque>

using namespace std;


int main()
{

   deque <int> GlitchyData;  // glitchy data
   deque <int> WindowArray;  // the last 7 sensor readings
   deque <int> SortArray;    // sort array for sensor readings

   //  load up some glitchy data
   GlitchyData.push_back(10);
   GlitchyData.push_back(20);
   GlitchyData.push_back(17);
   GlitchyData.push_back(2000);// glitch
   GlitchyData.push_back(15);
   GlitchyData.push_back(14);
   GlitchyData.push_back(20);
   GlitchyData.push_back(6000);// glitch
   GlitchyData.push_back(11);
   GlitchyData.push_back(12);
   GlitchyData.push_back(15);
   GlitchyData.push_back(22);
   GlitchyData.push_back(4000);// glitch
   GlitchyData.push_back(11);
   GlitchyData.push_back(20);
   GlitchyData.push_back(15);
   GlitchyData.push_back(3000);// glitch
   GlitchyData.push_back(14);
   GlitchyData.push_back(15);
   GlitchyData.push_back(16);
   GlitchyData.push_back(17);
   GlitchyData.push_back(1000);// glitch
   GlitchyData.push_back(15);
   GlitchyData.push_back(10);
   GlitchyData.push_back(11);
   GlitchyData.push_back(15);
   GlitchyData.push_back(2000);// glitch
   GlitchyData.push_back(10);

   // loop through the glitch data and get a running list
   // of the last 7 readings
   for(int i=0; i< (int)GlitchyData.size(); i++)
   {
       // add a reading to back of array
       WindowArray.push_back(GlitchyData[i]);

       // if we don't have 7 reading yet, go back to the top
       // of the loop for more
       if(i<6)
       {
           continue;
       }

       // copy the glitch data window to a sorting array
       SortArray.clear();
       for(int j=0; j< (int)WindowArray.size(); j++)
       {
           SortArray.push_back(WindowArray[j]);
       }

       // sort the data
       sort(SortArray.begin(),SortArray.end());

       // the middle element is the median which filters out the glitches
       int MedianIndex = SortArray.size()/2;

       // show the data
       for(int j=0; j< (int)SortArray.size(); j++)
       {
           if(j==MedianIndex)
           {
               cout << setw(6) << WindowArray[j] << setw(6) << SortArray[j] << "  Median" <<endl;
           }
           else
           {
               cout << setw(6) << WindowArray[j] << setw(6) << SortArray[j] << endl;
           }
       }
       cout << "-------------" << endl;

       // pop the first element in the window data to keep a fixed number of elements
       // for the next time a reading is added to the back
       WindowArray.pop_front();

   }  // endfor

   return(0);
}//endmain
