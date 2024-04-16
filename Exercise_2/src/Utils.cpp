#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Utils.hpp"


using namespace std;

void RetRate(string nameFileI)
{
    string nameFileO = "result.txt";
    ifstream fstr(nameFileI);
    ofstream ostr(nameFileO);

    if (fstr.fail() || ostr.fail()) {
        cout << "Errore nell'apertura file" << endl;
        return;
    }

    string line;

    getline(fstr, line);
    stringstream valori(line);
    string token;
    getline(valori, token, ';');
    string nameS = token;
    getline(valori,token);
    double valueS = stod(token);


    getline(fstr, line);
    stringstream valN(line);
    string tokN;
    getline(valN, tokN, ';');
    string nameN = tokN;
    getline(valN,tokN);
    double n = stod(tokN);


    vector<double> w(n);
    vector<double> r(n);

    getline(fstr, line);  // salta una linea

    int k = 0;
    while (getline(fstr, line)) {
        stringstream valori(line);
        string token;

        getline(valori, token, ';');
        w[k] = stod(token);
        getline(valori, token);
        r[k] = stod(token);
        k+=1;
    }


    double sumR = 0;
    for (int i = 0; i < n;i++){
        sumR += r[i]*w[i];
    }

    double V = 0;
    for (int i = 0; i < n;i++){
        V += (1+r[i])*(w[i]*1000);
    }

    ostr << nameS << fixed << setprecision(2) << " = " << valueS << ", " << nameN << " = " << n << endl;
    cout << nameS << fixed << setprecision(2) << " = " << valueS << ", " << nameN << " = " << n << endl;
    ostr << "w = [ ";
    cout << "w = [ ";
    for (int i = 0;i < n; i++){
        ostr << w[i] << " ";
        cout << w[i] << " ";
    }
    ostr << "]" << endl;
    cout << "]" << endl;

    ostr << "r = [ ";
    cout << "r = [ ";
    for (int i = 0;i < n; i++){
        ostr << r[i] << " ";
        cout << r[i] << " ";
    }
    ostr << "]" << endl;
    cout << "]" << endl;

    ostr << "Rate of return of the portfolio: " << fixed << setprecision(4) << sumR << endl;
    cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << sumR << endl;

    ostr << "V: " << fixed << setprecision(2) <<V << endl;
    cout << "V: " << fixed << setprecision(2) <<V << endl;

    fstr.close();
    ostr.close();
}
