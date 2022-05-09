#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void cleanUp(ifstream& input, ofstream& output);

int main(int argc, char** argv)
{
    int i; 
    int size, sizeReal;
    ifstream fin;
    ofstream fout;
    string inputFile, outputFile;
    vector<float>::iterator fit; 
    vector<float> vector;

    //checking for arguements
    if (argc != 3)
    {
        cout << "Usage: m0051.exe inputfile outputfile" << endl;
        cleanUp(fin, fout);
    }

    //accessing the files and checking if they opened/exist
    inputFile = argv[1];
    outputFile = argv[2];
    fin.open(inputFile);
    fout.open(outputFile);
    if (fin.is_open() != true)
    {
        cout << "Unable to open input file: " << inputFile << endl;
        cleanUp(fin, fout);
    }
    if (fout.is_open() != true)
    {
        cout << "Unable to open output file: " << outputFile << endl;
        cleanUp(fin, fout);
    }

    //putting the values into the array and incrementing i to get the size
    fin >> size;
    vector.resize(size+10);
    i = 0; 
    while (fin >> vector[i] && i < size)
    {
        i++; 
    }
    //getting the actual size of the file 
    if (i > size)
    {
        sizeReal = size;
    }
    else
    {
        sizeReal = i;
    }
    vector.resize(sizeReal);

    fout << fixed << setprecision(3);
    //outputting the actual size and the min and max element 
    fout << sizeReal << endl;
    fout << *min_element(vector.begin(), vector.end()) << " - " << *max_element(vector.begin(), vector.end()) << endl;
    i = 0;
    //formatting the numbers
    for (fit = vector.begin(); fit != vector.end(); fit++)
    {
        if (fit == vector.end())
        {
            cleanUp(fin, fout);
        }
        if ((i % 5 == 0) && i != 0)
        {
            fout << endl;
        }
        fout << setw(15) << right << *fit;
        i++;
    } 
    fout << endl; 
    

    cleanUp(fin, fout);
    return 0;
}

//cleanUp function to close the files
void cleanUp(ifstream & input, ofstream & output)
{
    if (output.is_open() == true)
    {
        output.close();
    }
    if (input.is_open() == true)
    {
        input.close();
    }
    input.close();
    exit(0);
}
