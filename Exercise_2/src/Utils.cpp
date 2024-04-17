#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;

void retRate(string inputFile)
{
    string outputFile = "result.txt";
    ifstream ifstr(inputFile);
    ofstream ofstr(outputFile);

    if (ifstr.fail() || ofstr.fail()) {
        cout << "Errore apertura file" << endl;
        return;
    }

    string header;
    getline(ifstr,header);
    double S = 0;
    size_t pos = header.find(';');
    istringstream converter(header);

    if (pos != string::npos && pos + 1 < header.size()) {
        string numberStr = header.substr(pos + 1); //sottostringa dopo il ';'
        converter.str(numberStr);
        converter >> S;}

    converter.clear();

    string line;
    getline(ifstr, line);
    converter.str(line);
    int n = 0;
    pos = line.find(';'); //posizione del ; per la seconda riga
    if (pos != string::npos && pos + 1 < line.size()) { //sottostringa dopo il ';'
        string numberStr2 = line.substr(pos + 1);
        converter.str(numberStr2);
        converter >> n;}


    double *w = new double[n];
    double *r = new double[n];

    getline(ifstr, line); //salto la linea di w;r

    int riga = 0;
    while (getline(ifstr, line)) {
        stringstream valori(line);
        string token;

        if (std::getline(valori, token, ';')) {
            w[riga] = stod(token); //essendo un puntatore ad un array dinamico,
                                   //assegno i valori con w [ ];
        } else {
            break; //gestisco il caso in cui non ci sia il ;
        }

        // Read the second value after ';'
        if (std::getline(valori, token)) {
            r[riga] = stod(token);
        } else {
            break;
        }

        riga += 1;
    }


    double res = 0;
    double V = 0;
    for (int i = 0; i < n;i++){
        res += r[i]*w[i];
        V += (1+r[i])*(w[i]*1000);
    }

    ofstr << "S = " << fixed << setprecision(2) << S << ", " << "n = " << n << endl;
    cout << "S = " << fixed << setprecision(2) << S << ", " << "n = " << n << endl;
    ofstr << "w = [ ";
    cout << "w = [ ";
    for (int i = 0;i < n; i++){
        ofstr << w[i] << " ";
        cout << w[i] << " ";
    }
    ofstr << "]" << endl;
    cout << "]" << endl;

    ofstr << "r = [ ";
    cout << "r = [ ";
    for (int i = 0;i < n; i++){
        ofstr << r[i] << " ";
        cout << r[i] << " ";
    }
    ofstr << "]" << endl;
    cout << "]" << endl;

    ofstr << "Rate of return of the portfolio: " << fixed << setprecision(4) << res << endl;
    cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << res << endl;

    ofstr << "V: " << fixed << setprecision(2) << V << endl;
    cout << "V: " << fixed << setprecision(2) << V << endl;

    ifstr.close();
    ofstr.close();
    delete [] w; //devo ricordarmi di deallocare la memoria
    delete [] r;


}
