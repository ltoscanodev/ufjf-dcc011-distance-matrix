#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/*
    Descrição: Método que lê o arquivo que contêm a matriz
    Autor: Luis Augusto Toscano
*/
void readMatriz(string fileName)
{
    ifstream streamFile;
    streamFile.open(fileName.c_str());

    if (!streamFile.is_open())
        cout << "Erro ao carregar o arquivo da matriz!" << endl;
    else
    {
        int i = 1;
        int j = 0;
        string line;
        getline(streamFile, line);
        cout << line << endl;

        while (getline(streamFile, line))
        {
            istringstream streamLine(line);

            float val;

            while(streamLine>> val)
            {
                cout << "[" << i << j << "]:" << val << " ";
                j++;
            }

            cout << endl;
            j = 0;
            i++;
        }
    }

    streamFile.close();
}

int main()
{
    readMatriz("Matrizes/matriz.txt");
    return 0;
}
