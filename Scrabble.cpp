#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string tab[10000][110];
int main () {
    string line;
    int x = 0;
    int y = 0;
    ifstream myfile ("PlikWejsciowy.csv");

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            std::string slowo = "";
            y = 0;
            for(int i = 0; i < line.size(); i++)
            {

                if(line[i] == ';')
                {
                    tab[x][y] = slowo;
                    y++;
                    slowo = "";
                }
                else slowo += line[i];
            }
            tab[x][y] = slowo;
            x++;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    x = 0;
    y = 0;

    ofstream file ("PlikWyjsciowy.csv");
    while(tab[x][0] != "")
    {
        y  = 1;
        while(tab[x][y] != "") {
            cout << tab[x][y] << endl;
            file << tab[x][0] + "," + tab[x][y] + "\n";
            y++;
        }
        x++;
    }
    file.close();
    return 0;
}