//  File Name: Assignment7.cpp
//  Name: Artem Kerutis
//  StudentID: 1211285618
//  Arizona State University CSE100 Fall 2016
//  Description:  rain calculator
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
int size=12;
double rain[12];
string smallName;
string names[12]={"Janurary", "February", "March", "April","May","June","July", "August","September","October","November", "December"};

void getData(double array[]){
 string fileName;
 ifstream datafile;
 int counter = 0;
 cout << "Please enter the file's name: "<<endl<<endl;
 cin >> fileName;
    datafile.open(fileName.c_str());
    if(!datafile)
     cout << "Error opening file, please check file name.\n";
 else
 {
      while (counter < size && datafile >> array[counter])
         counter++;
         datafile.close();
     }
}


double getTotal(double array[]){
 double total=0;
 for(int x=0;x<12;x++){
      total+=array[x];
 }
  return total;
}


double getAverage(double array[]){
     double total=0;
 for(int x=0;x<12;x++){
      total+=array[x];
 }
 return (total/12);


}

int getLargest(double array[])
{
    double highest = array[0];
    int i=0;
    int highestMonth=i;
    for (int i=0; i< 12; i++)
    {
        if(array[i] > highest){
            highest = array[i];
     highestMonth=i;
        }
    }
    return highestMonth;
}




int getSmallest(double array[])
{
    double lowest = array[0];
    int i=0;
    int lowestMonth=i;
    for (int i=0; i< 12; i++)
    {
        if(array[i] < lowest){
            lowest = array[i];
            lowestMonth=i;}
    }



return lowestMonth;
}

int main()
{
int smallestRain=getSmallest(rain);
int largestRain=getLargest(rain);
 
cout << smallestRain;
 
getData(rain);
cout<<"=== 2015 Rain Report for Phoenix AZ ==="<<endl<<endl;
cout<<setprecision(2)<<fixed<<"Total rainfall: "<<getTotal(rain)<<" inches."<<endl;
cout<<setprecision(2)<<fixed<<"Average monthly rainfall: "<<getAverage(rain)<<" inches."<<endl;
cout<<setprecision(2)<<fixed<<"The least rain fell in "<<names[smallestRain]<<" with "<<rain[smallestRain]<<" inches."<<endl;
cout<<setprecision(2)<<fixed<<"The most rain fell in "<<names[largestRain]<<" with "<<rain[largestRain]<<" inches."<<endl;

}
