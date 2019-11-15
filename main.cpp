#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <algorithm>
// ѕузырЄк
#define NU 250000

using namespace std;
//unsigned long int count = 0;
int stop = 0; int step = 5000;
long int NUM = NU; int rr = 0; long double ce=0; long double ca=0;
vector <long int> a; vector <long int> b;

int main()
{
    ofstream fout("cppstudio.txt");
    long double count = 0;
    fout<< " pyz";
    a.reserve(NU+5);    b.reserve(NU+5);
    cout << " start massiv base" << endl;
    for (long int i = 0; i < NUM; i++) {
        a.push_back  (i);
        b.push_back  (i);
    }

    random_shuffle(b.begin(), b.end());

    do{

    for (long int i = 0; i < NUM; i++) a[i]= b[i];
    long int j = 0; long int te =0; bool tt = 0;
    bool k = 0;

    do{
            if (j == 0) { k = 0; te=0; }
            if (j == NUM) { k = 1; te=0; }
            tt=0;
            switch (k) {
        case 0:
            ca++;
            if (a[j] > a[j+1]) { /////////////////////////
                count+=3;
                ce++; swap (a[j], a [j+1]);////////////////////////
                tt = 1; te=0;
            }
            else {j++; te++; tt=0;count++; }
        break;

        case 1:
            ca++;
            if (a[j] < a[j-1]) {///////////////////////
                count +=3;
                ce++; swap (a[j], a [j-1]);/////////////////////
                tt = 0; te = 0;
            }
            else {j--;te++; tt=1; count ++;}
        break;
            }

            k = tt; //NUM = NUM/2;
    } while (te!=(NUM-1));

    ///cout << " Number of operation = " << count<< endl ;
    fout << ce<< "    "<< ca +ce<< "    " << NUM<< endl; ca=ce=0;
    count =0;
    stop++;
    NUM = NUM/2;
    } while (NUM >500);

    fout.close();

    return 0;
}
