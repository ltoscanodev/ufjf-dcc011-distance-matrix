#include "TDistMat.h"
#include "TDistMat2.h"
#include "TList.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void clearScreen()
{
#ifdef _WIN32
      system ("cls");
#else
      system ("clear");
#endif
}

void waitToContinue()
{
    char wait;

    while(wait != 'c')
    {
        cout << "Digite 'c' para continuar..." << endl;
        cin >> wait;
        clearScreen();
    }
}

/*
    Descrição: Método que lê o arquivo que contêm a matriz
    Autor: Luis Augusto Toscano
*/
TDistMat* readMatriz(string fileName)
{
    ifstream streamFile;
    streamFile.open(fileName.c_str());

    if (!streamFile.is_open())
        cout << "Erro ao carregar o arquivo da matriz!" << endl;
    else
    {
        int i = 1;
        int j = 0;
        int readLength = 0;

        string line;
        getline(streamFile, line);
        istringstream streamLine(line);

        float ordem;
        streamLine >> ordem;

        if(streamLine && (ordem > 0))
        {
            TDistMat *distMat = new TDistMat(ordem);

            while (getline(streamFile, line))
            {
                float dist;
                istringstream streamLine(line);

                while(streamLine >> dist)
                {
                    distMat->setDist(i, j, dist);
                    j++;
                    readLength++;
                }

                j = 0;
                i++;
            }
            streamFile.close();

            if(readLength == ((ordem * (ordem - 1)) / 2))
                return distMat;
            else
                cout << "[ Erro: Arquivo da matriz corrompido ]" << endl;
        }
        else
            cout << "[ Erro: Ordem da matriz invalida ]" << endl;
    }

    return NULL;
}

void printMat(TDistMat *p)
{
    p->print();
    waitToContinue();
}

/*
    Descrição: Método que realiza a cosulta da matriz
    Autor: Igor Pires dos Santos
*/
void consultMat(TDistMat *p)
{
    int i = 0;
    int j = 0;

    cout << endl << " -- CONSULTAR ITEM DA MATRIZ DISTANCIA -- " << endl << endl;

    while(i != -1 && j != -1)
    {
        cout << "Insira i: ";
        cin >> i;
        cout << "Insira j: ";
        cin >> j;

        if(i != -1 && j != -1)
            cout << endl << "[" << i << "][" << j << "]: " << p->getDist(i, j) << endl << endl;
    }

    cout << endl << " -- FIM DA CONSULTA -- " << endl;
}

void parseOption(int op, TDistMat *mat)
{
    switch(op)
    {
        case 1:
            printMat(mat);
            break;
        case 2:
            consultMat(mat);
            break;
        case 0:
            exit(0);
        default:
            cout << "Opcao invalida!" << endl;
    }
}

int main()
{
//    TDistMat *distMat = readMatriz("Matrizes/teste1.txt");
//
//    if(distMat != NULL)
//    {
//        bool again = true;
//
//        while(again)
//        {
//            int op;
//
//            clearScreen();
//            cout << endl << "-- MATRIZ DE DISTANCIA --" << endl << endl;
//            cout << "[1] - Imprimir matriz" << endl;
//            cout << "[2] - Consultar da matriz" << endl;
//            cout << "[0] - Sair" << endl;
//            cout << "Opcao: ";
//            cin >> op;
//            parseOption(op, distMat);
//        }
//    }

    TList *l = new TList();

    for(int i = 0; i < 10; i++)
    {
        l->setDist(i, 10);
    }

    l->print();

    return 0;
}
