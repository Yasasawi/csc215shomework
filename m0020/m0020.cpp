#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void cleanUp(ifstream& input, ofstream& output, float* ptr);
float *findMinimum(float* ptr, int size);
float *findMaximum(float* ptr, int size);


int main(int argc, char** argv)
{
    float *ftptr = nullptr;
    int size, sizeReal; 
    int i; 
    ifstream fin;
    ofstream fout; 
    string inputFile, outputFile; 

    if (argc != 3)
    {
        cout << "Usage: m0020.exe inputfile outputfile" << endl;
        cleanUp(fin, fout, ftptr);
    }

    inputFile = argv[1];
    outputFile = argv[2]; 
    fin.open(inputFile);
    fout.open(outputFile);
    if (fin.is_open() != true)
    {
        cout << "Unable to open input file: " << inputFile << endl;
        cleanUp(fin, fout, ftptr);
    }
    if (fout.is_open() != true)
    {
        cout << "Unable to open output file: " << outputFile << endl;
        cleanUp(fin, fout, ftptr);
    }
    
    fin >> size;
    ftptr = new (nothrow) float[size];
    if (ftptr == nullptr)
    {
        cout << "Unable to allocate memory" << endl; 
        cleanUp(fin, fout, ftptr);
    }
    i = 0;
    while (fin >> ftptr[i] && i < size)
    {
        i++;
    }
    
    if (i > size)
    {
        sizeReal = size;
    }
    else 
    {
        sizeReal = i; 
    }


    fout << fixed << setprecision(3); 

    fout << sizeReal << endl; 
    fout << *findMinimum(ftptr, sizeReal) << " - " << *findMaximum(ftptr, sizeReal) << endl; 

    for (i = 0; i < sizeReal; i++)
    {
        if ((i % 5 == 0) && i != 0)
        {
            fout << endl; 
        }
        fout << setw(15) << right << ftptr[i];
    }
    fout << endl;

    cleanUp(fin, fout, ftptr);
    return 0; 
}

void cleanUp(ifstream & input, ofstream & output, float* ptr)
{
    input.close();
    output.close();
    delete[] ptr;
    exit(0);
}

float *findMinimum(float* ptr, int size)
{
    int i;
    float *minLocation = nullptr;
    float min = ptr[0];
    minLocation = &ptr[0];
    for (i = 0; i < size; i++)
    {
        if (ptr[i] < min)
        {
            min = ptr[i];
            minLocation = &ptr[i];
        }
    }
    return minLocation;
}

float *findMaximum(float* ptr, int size)
{
    int i;
    float *maxLocation = nullptr;
    float max = ptr[0];
    maxLocation = &ptr[0];
    for (i = 0; i < size; i++)
    {
        if (ptr[i] > max)
        {
            max = ptr[i];
            maxLocation = &ptr[i];
        };
    }
    return maxLocation;
}