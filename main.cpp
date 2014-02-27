#include <iostream>

using namespace std;

int main()
{
    int casos, c, s, q, c1, c2, d, caso=1;
    cin >> casos;

    while(casos > 0){
        cin >> c >> s >> q;
        int arreglo[c][c];

        for (int i=0; i<c; i++)
            for (int j=0; j<c; j++){
                if(i == j)
                    arreglo[i][j]=0;
                else
                    arreglo[i][j] =  2000000000;
            }

        for(int i = 0; i < s; i++){
            cin >> c1 >> c2 >> d;
            arreglo[c1-1][c2-1] = d;
            arreglo[c2-1][c1-1] = d;
        }

        for (int k=0; k<c; k++)
            for (int i=0; i<c; i++)
                for (int j=0; j<c; j++)
                    arreglo[i][j] = min(arreglo[i][j], max(arreglo[i][k],arreglo[k][j]));

        cout << "Case " << caso << ":" << endl;

        for (int i=0; i<q; i++){
            cin >> c1 >> c2;
            if(arreglo[c1-1][c2-1]==2000000000)
                cout << "no path" << endl;
            else
                cout << arreglo[c1-1][c2-1] << endl;
        }
        casos--;
        caso++;
    }

    return 0;
}
