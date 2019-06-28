#include <bits/stdc++.h>
using namespace std;

int main () {

        int numb;

        while (cin >> numb) {

                int v[(numb*numb)]={0}, ind[numb], perdx=0, cont=0; // Versão 2.0
                char eq, op[numb], operacao;
                string jog[numb], perd[numb], jogadores;
                bool result[numb]={0};

                for (int i=0; i<numb*3; i+=3) {
                        cin >> v[i] >> v[i+1] >> eq >> v[i+2];
                }

                for (int i=0; i<numb; i++) {
                        cin >> jogadores >> ind[i] >> operacao;
                        ind[i]--;
                        perd[i] = "~";
                        jog[ind[i]] = jogadores;
                        op[ind[i]] = operacao;
                }

                sort(ind,ind+numb);

                for (int i=0; i<numb; i++) {

                        if (op[i] == '+') {
                                if (v[cont] + v[cont+1] == v[cont+2])
                                        result[i] = 1;
                        }

                        else if (op[i] == '-') {
                                if (v[cont] - v[cont+1] == v[cont+2])
                                        result[i] = 1;
                        }

                        else if (op[i] == '*') {
                                if (v[cont] * v[cont+1] == v[cont+2])
                                        result[i] = 1;
                        }

                        else if (op[i] == 'I') {
                                if (v[cont] + v[cont+1] != v[cont+2] && v[cont] - v[cont+1] != v[cont+2] && v[cont] * v[cont+1] != v[cont+2])
                                        result[i] = 1;
                        }
                        cont+=3;
                }

                for (int i = 0; i<numb; i++) {
                        if (result[i] == 0) {
                                perdx++;
                                perd[i] = jog[i];
                        }
                }

                sort(perd,perd+numb);

                if (perdx == 0)
                        cout << "You Shall All Pass!\n";
                else if (perdx == numb)
                        cout << "None Shall Pass!\n";
                else{
                        for (int i=0; i<perdx-1; i++)
                                cout << perd[i] << " ";
                        cout << perd[perdx-1] << endl;
                }
        }
        return 0;
}
