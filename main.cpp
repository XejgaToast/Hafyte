#include <iostream>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>

using namespace std;

int main()
{
    string input;
    long double dhash;
    string shash = "";

    int hashLaenge = 16;

    while(true)
    {
        dhash = 0;
        cout << "Hello world!" << endl;
        cout << "Input: ";
        cin >> input;
        for(int j=0; j<hashLaenge;j++)
        {
            for(unsigned int i=0; i<input.size();i++)
            {
                dhash += sqrt(abs((int)input[i]/(int)input[i]-(int)input[i+1]*(int)input[i+1]+(int)input[i-1]*(int)input[i-1])); //Irgendeine Zahl berechnen, die sehr chaotisch auf Änderungen reagiert!
            }
            dhash = sin(dhash); //Davon Sinus, damit man später die länge selber bestimmen kann
            ostringstream test;
            test << std::dec << abs((int)(dhash*1000000000)); //Habe ich im Internet gefunden -> int to string
            input = test.str(); //Damit haben wir ein neues Input und somit ein neues nächstes Hash-Zeichen
            dhash = abs((int)(dhash*100));
            if(dhash>=33) //33 ist der erste Ascii Wert, der ein sinnvolles Zeichen ergibt
            {
                shash += (char)dhash;
            }
            else
            {
                j--;        //Wenn nicht, dann mit dem neuen Input eine neue Zahl berechnen und j--, damit die 16 Zeichen bleiben
            }
        }
        cout << shash << endl << endl;
        shash = "";
    }
}
