//
// Created by JPascual on 14/10/2019.
//
#include <iostream>
#ifndef STOCKCONTROL_FILA_H
#define STOCKCONTROL_FILA_H


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
#endif //STOCKCONTROL_FILA_H
