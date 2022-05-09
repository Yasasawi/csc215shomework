#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
void permute(int* p, int* used, int n, int k, string items[], int pos);
void cleanUp(fstream& fin);
int main(int argc, char* argv[])
{
    int i;
    string fileName;
    fstream file;
    int p[100] = { 0 };
    int used[100] = { 0 };
    string items[100];
    int n, k, pos;
    string sN, sK;
    pos = 0;

    sN = "100000";
    sK = "99999";

    if (argc != 2)
    {
        cout << "Usage: m0101.exe itemfile.txt" << endl;
        return 0;
    }

    fileName = argv[1];
    file.open(fileName, ios::in || ios::out || ios::app);

    if (file.is_open() != true)
    {
        cout << "Unable to open file: " << fileName << endl;
        file.close();
        return 0;
    }

    getline(file, sN, ' ');
    getline(file, sK);

    n = stoi(sN);
    k = stoi(sK);

    for (i = 0; i < n; i++)
    {
        getline(file, items[i]);
    }

    permute(p, used, n, k, items, pos);

    return 0; 



    return 0;
}

void cleanUp(fstream& fin)
{
    if (fin.is_open() == true)
    {
        fin.close();
    }
    exit(0);
}


void permute(int* p, int* used, int n, int k, string items[], int pos)
{
    int i;

    if (pos == k)
    {
        for (i = 0; i < k; i++)
        {
            cout << items[p[i]] << " ";
        }
        cout << endl;
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            p[pos] = i;
            used[i] = 1;
            permute(p, used, n, k, items, pos + 1);
            used[i] = 0;
        }
    }
}
