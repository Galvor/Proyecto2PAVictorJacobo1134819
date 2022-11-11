// Proyecto2PAVictorJacobo1134819.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include "album.csv"

using namespace std;

string IngresarEstampa(string categoriaB, string stampB)
{
    fstream fout;
    fout.open("album.csv", ios::out | ios::app);
    fout << categoriaB << ",";
    fout << "\n";
    fout << stampB << ",";
    fout << "\n";
    cout << "===================================== \n";
    cout << "Estampa ingresada correctamente. \n";
    cout << "\n";
    Menu();

}

string LeerAlbum(int n)
{
    int j, i;
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    stack<string> album;
    stack<string> categoria;
    stack<string> stamp;
    string line, word, temp;
    fstream fin;
    fin.open("album.csv", ios::in);
    cout << "Estas son las estampas obtenidas: \n";
    cout << "\n";
    cout << "\n";
    while (fin >> temp)
    {

        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            album.push(word);
        }

    }
    j = 0;
    while (!album.empty())
    {

        cout << album.top() << "";
        i = j % 2;
        if (i = 0)
        {
            stamp.push(album.top());
        }
        else
        {
            categoria.push(album.top());
        }
        album.pop();

    }
    if (n = 1) 
    {
        Buscar(categoria, stamp);
    }
    else if(n = 2)
    {
        Mostrar(categoria, stamp);
    }

}

void Mostrar(stack<string>categoria, stack<string>stamp)
{
    int n, i;
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "===================================================\n";
    cout << "Estas son las categorias obtenidas\n";
    /*stack<string> album;
    stack<string> categoria;
    stack<string> stamp;
    string line, word, temp;
    fstream fin;
    fin.open("album.csv", ios::in);
    cout << "Estas son las estampas obtenidas: \n";
    cout << "\n";
    cout << "\n";
    while (fin >> temp)
    {
        
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            album.push(word);
        }

    }
    n = 0;
    while (!album.empty())
    {

        cout << album.top() << "";
        i = n % 2;
        if (i = 0)
        {
            stamp.push(album.top());
        }
        else 
        {
            categoria.push(album.top());
        }
        album.pop();

    }*/
    while (!categoria.empty())
    {
        cout << categoria.top() << " \n";
        cout << "\n";
        categoria.pop();

    }
    cout << "===================================================\n";
    cout << "Estas son las estampas obtenidas\n";
    while (!stamp.empty())
    {
        cout << stamp.top() << " \n";
        cout << "\n";
        stamp.pop();
    }
}
void Buscar(stack<string>categoria, stack<string>stamp)
{
    stack<string>categoria2 = categoria;
    stack<string>stamps2 = stamp;

    string categoriaB, stampB;

    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "======================================================\n";

    cout << "Ingrese el Categoria de la estampa: \n";
    cin >> categoriaB;
    cout << "Ingrese el nombre de la estampa: \n";
    cin >> stampB;

    while (!categoria2.empty())
    {
        if (categoriaB == categoria2.top())
        {
            categoriaB = categoria2.top();
            while (!stamps2.empty())
            {
                if (stampB == stamps2.top())
                {
                    stampB = stamps2.top();
                }
                stamps2.pop();
            }
        }
        else 
        {
            cout << "No se encontro la estampa. \n";
            cout << "Desea ingresar la estampa? \n";
            cout << "Presione 1 para ingresar la estampa \n";
            int x;
            cin >> x;
            if (x == 1)
            {
                IngresarEstampa(categoriaB, stampB);
            }
            else
            {
                Menu();

            }
        }
        
        categoria2.pop();
    }
    
   
}

void Menu() 
{
    int n;
    cout << "Para encontrar una estampa y marcar o desmarcar presione 1.\n";
    cout << "Para mostrar la lista de estampas presione 2.\n";
    cout << "\n";
    cin >> n;
    switch (n)
    {
    case 1:
        LeerAlbum(n);
        break;
    case 2:
        LeerAlbum(n);
        break;
    default:
        cout << "Ingrese un numero valido.\n";
        Menu();
        break;
    }
}

int main()
{
    cout << "==============================================================\n";
    cout << "               Bienvenido al Album Reader                     \n";
    cout << "==============================================================\n";
    cout << "\n";
    cout << "\n";
    Menu();
}


