#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H
#define NULL    0
template <class T>
class ListaEncadeada
{
private:
    ListaEncadeada<T> *proximo;
    ListaEncadeada<T> *anterior;
    //O nó que se encontra na ultima posicao da lista
    ListaEncadeada<T> *ultimoNo;
    //O nó que se encontra na primeira posicao
    ListaEncadeada<T> *primeiroNo;
    T *objeto;
    unsigned int qtde;
public:
    ListaEncadeada();
    ~ListaEncadeada();
    unsigned int getQtde() const;
    void add(T *objeto);
    //Adiciona na posicao desejada
    void add(unsigned int posicao, T *objeto);
    ListaEncadeada<T> *getProximo() const;
    ListaEncadeada<T> *getAnterior() const;
    ListaEncadeada<T> *getUltimoNo() const;
    ListaEncadeada<T> *getPrimeiroNo() const;
    void setPrimeiroNo(ListaEncadeada<T> *value);
    T *getObjeto() const;
    void setObjeto(T *value);
};
#include "listaencadeada.cpp"
#endif // LISTAENCADEADA_H
