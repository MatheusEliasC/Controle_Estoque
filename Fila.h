//
// Created by JPascual on 14/10/2019.
//

#ifndef STOCKCONTROL_FILA_H
#define STOCKCONTROL_FILA_H
#include <iostream>
using namespace std;

template <typename T>
class IFila {
public:
    virtual bool Enfileira (T valor) = 0;
    virtual T Desenfileira (bool* ok) = 0;
    virtual void Imprime () = 0;
    virtual ~IFila () {
    }
};

template <typename T>
class FilaCircular : IFila<T> {
private:
    T* v;
    int Max;
    int i;
    int f;

public:
    explicit FilaCircular (int Max);                     //implementar
    virtual ~FilaCircular ();                            //implementar
    bool Enfileira (T valor) override;                   //implementar
    void Imprime () override;                            //implementar
    T Desenfileira (bool* ok = NULL) override;           //implementar
    FilaCircular (const FilaCircular& outra);            //implementar
    FilaCircular& operator= (const FilaCircular& outra); //implementar
};

int main (int argc, char* argv[]) {
    FilaCircular<float> f (3);
    f.Enfileira (5.2);
    f.Enfileira (2.2);
    f.Enfileira (3.2);
    f.Enfileira (9.2);
    f.Enfileira (5.1);

    bool ok = false;
    do {
        float r = f.Desenfileira (&ok);
        if (ok)
            cout << r << endl;
    } while (ok); // Deve Imprimir somente 5.2, 2.2 e 3.2

    f.Enfileira (3);
    f.Enfileira (2);
    f.Enfileira (1);
    FilaCircular<float> f2 (10);
    f2 = f;

    cout << f.Desenfileira ()  << endl; // Deve Imprimir 3
    cout << f2.Desenfileira () << endl; // Deve Imprimir 3
    cout << f2.Desenfileira () << endl; // Deve Imprimir 2
    cout << f.Desenfileira ()  << endl; // Deve Imprimir 2

    return 0;
}

#endif //STOCKCONTROL_FILA_H
