#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
using namespace std;

int main() {

    srand(time(0));

    int n, m, i(0), j, t, x, idx, c, b, inizio, fine, medio;
    bool scambi(true);

    do {
        cout<<"Inserire il numero di cifre da generare"<<endl;
        cin>>n;
    } while (n<=0);

    vector <int> V1(n);
    vector <int> V2(m);
    vector <int> V3(n+m);
    while (i<=n-1) {

        V1[i]=rand() % (n*10+1);
        i=i+1;
    }

    while (j<=n-1) {

        V2[j]=rand() % (n*10+1);
        j=j+1;
    }

    i=0;
    while (i<=n-1 && scambi) {
        scambi=false;

        j=0;
        while (j<(n-1)-i) {
           
            if (V1[j]>V1[j+1]) {
                
                t=V1[j];
                V1[j]=V1[j+1];
                V1[j+1]=t;

                scambi=true;

            }
            j=j+1;
        }
        i=i+1;
    }

    j=0;
    i=0;
    scambi=true;
    while (i<=n-1 && scambi) {
        scambi=false;

        j=0;
        while (j<(n-1)-i) {
           
            if (V2[j]>V2[j+1]) {
                
                t=V2[j];
                V2[j]=V2[j+1];
                V2[j+1]=t;

                scambi=true;

            }
            j=j+1;
        }
        i=i+1;
    }

    //merge
    i=0;
    j=0;
    k=0;
    while (i<=n-1 && j<=m-1) {
        if (V1[i]<V2[j]) {
            
            V3[k]=V1[i];
            i=i++;

        }
        else
        {
            V3[k]=V1[j];
            j=j++;
        }
        k=k++;
    }

    while (i<=n-1) {

        V3[k]=V1[i];
        i=i++;
        k=++;
    }

    while (j<=n-1) {

        V3[k]=V1[j];
        j=j++;
        k=k++;
    }

    i=0;
    c=0;
    cout<<"V3: ";
    while ((n+m)-1) {

        cout<<V3[c]<<"; ";
        c=c++;
    }

    i=0;
    b=0;
    idx=-1;
    while (i<=n-1 && idx=-1)
    {
        b=b++;

        if (V3[i]==x) {
            idx=i;
        }

        i=i++;
    }

    cout<<"Ricereca sequenziale: sono state effettuate "<<b<<" operazioni"<<endl;
    if (idx=-1) {
        cout<<"Non ho trovato il numero"<<endl;
    }
    else
    {
        cout<<"Ho trovato il numero "<<x<<" nella cella "<<idx<<endl;
    }
    // Fine ricerca sequenziale

    // ricerca binaria
    c=0;
    i=0;
    idx=-1;
    inizio=0;
    fine=n-1;
    while (inizio<=fine && idx=-1) {
        c=c++;

        medio=inizio+((fine-inizio)/2);

        if (V3[medio]==x) {
            idx=medio;
        }
        else
        {
            if (V3[medio]>x) {
                fine=medio-1;
            }
            else
            {
                inizio=medio+1;
            }
        }
        i=i+1;
    }
    cout<<"Ricereca sequenziale: sono state effettuate "<<c<<" operazioni"<<endl;
    if (idx=-1) {
        cout<<"Non ho trovato il numero"<<endl;
    }
    else
    {
        cout<<"Ho trovato il numero "<<x<<" nella cella "<<idx<<endl;
    }
    // Fine ricerca binaria   
}