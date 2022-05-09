#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std; 

//place prototypes here
void printFile(fstream& record);
bool applyRaise(fstream& record, int identify, double raise);
void cleanUp(fstream& fout);

//structure
struct empData
{
    int id; 
    char firstName[20];
    char lastName[40];
    double salary;
    double bonus; 
};

//main
int main(int argc, char *argv[])
{
    string fileName; 
    fstream bin; 
    int id; 
    double raise; 
    if (argc != 4)
    {
        cout << "Usage: m0041.exe binaryData employeeID salaryRaise" << endl; 
        cleanUp(bin);
    }

    fileName = argv[1];
    id = stoi(argv[2]);
    raise = stod(argv[3]);


    bin.open(fileName,ios::in|ios::out|ios::binary);
    if(bin.is_open() != true) 
    {
        cout << "Unable to open binary file: " << fileName << endl; 
        cleanUp(bin);
    }
     
    printFile(bin);
    bin.seekp(0, ios::beg); 
    if (applyRaise(bin, id, raise) == false)
    {
        cout << "\n" << "Employee ID " << id << " was not found." << endl << endl; 
        bin.seekp(0, ios::beg);
        bin.clear();
        printFile(bin);
    }
    else
    {
        cout << "\n" << "Employee ID " << id << " has been updated." << endl << endl;
        bin.seekp(0, ios::beg);
        bin.clear(); 
        printFile(bin);
    }


    cleanUp(bin);
    
    return 0; 
}

//functions
void printFile(fstream& record)
{
    empData emp;
    cout << setprecision(2) << fixed; 
    while(record.read((char*)&emp, sizeof(empData)))
    {
        cout << setw(7) << emp.id << " "
            << left << setw(20) << emp.firstName
            << setw(40) << emp.lastName << right
            << " Salary: " << setw(10) << emp.salary
            << " Bonus: " << setw(10) << emp.bonus << endl;
    }
    record.seekp(0, ios::beg);
    record.clear();
}

bool applyRaise(fstream& record, int identify, double raise)
{
    empData emp; 
    cout << setprecision(2) << fixed; 
    while(record.read((char*)&emp, sizeof(empData)))
    {
        if (emp.id == identify)
        {
            record.seekp(sizeof(empData)*((record.tellg()/sizeof(empData))-1),ios::beg);
            emp.salary += raise; 
            emp.salary = trunc(emp.salary);
            record.write((char*)&emp, sizeof(empData));
            record.seekp(0, ios::beg);
            record.clear(); 
            return true; 
        }
    }
    record.seekp(0, ios::beg);
    record.clear();
    return false; 
}

void cleanUp(fstream& fout)
{
    fout.close();
    exit(0);
}