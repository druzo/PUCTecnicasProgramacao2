#include "listaencadeada.h"
#define TEMPL template <class T>

TEMPL unsigned int ListaEncadeada<T>::getQtde() const
{
    return qtde;
}

TEMPL void ListaEncadeada<T>::add(T *objeto)
{
    //criando um nó para a lista
    ListaEncadeada<T> *node = new ListaEncadeada();
    if (qtde == 0)
    {
        node->proximo = NULL;
        node->anterior = NULL;
        node->objeto = objeto;
        ultimoNo = node;
        primeiroNo = node;
        qtde++;
    }
    else
    {
        ultimoNo->proximo = node;
        node->anterior = ultimoNo;
        ultimoNo = node;
    }
}

TEMPL void ListaEncadeada<T>::add(unsigned int posicao, T *objeto)
{
    ListaEncadeada *nodePosicao;
    //criando um nó para a lista
    ListaEncadeada<T> *newNode = new ListaEncadeada();

    //caso a posicao seja maior do que
    if (posicao > this->qtde)
    {
        posicao = qtde - 1;
    }

    unsigned int cont;
    //verificando se e mais rapido se movimentar pelo primeiro ou pelo ultimo
    //caso seja mais rapido ir pelo primeiro
    if (qtde - posicao -1 > posicao)
    {
        nodePosicao = primeiroNo;
        for (cont = 0; cont == posicao; ++cont)
        {
            nodePosicao->proximo;
        }
    }
    //caso seja mais rápido pelo último
    else
    {
        nodePosicao = ultimoNo;
        for (cont = qtde - 1; cont == posicao; --cont)
        {
            nodePosicao->anterior;
        }
    }
    newNode->objeto = objeto;
    newNode->proximo = nodePosicao;
    newNode->anterior = nodePosicao->anterior;
    nodePosicao->anterior = newNode;
    //caso possua um no anterior muda o seu proximo
    if (nodePosicao->anterior)
    {
        nodePosicao->anterior->proximo = newNode;
    }
}

TEMPL ListaEncadeada<T> *ListaEncadeada<T>::getProximo() const
{
    return proximo;
}

TEMPL ListaEncadeada<T> *ListaEncadeada<T>::getAnterior() const
{
    return anterior;
}

TEMPL ListaEncadeada<T> *ListaEncadeada<T>::getUltimoNo() const
{
    return ultimoNo;
}

TEMPL ListaEncadeada<T> *ListaEncadeada<T>::getPrimeiroNo() const
{
    return primeiroNo;
}

TEMPL ListaEncadeada<T>::ListaEncadeada()
{
    this->qtde = 0;
    proximo = NULL;
    anterior = NULL;
    primeiroNo = NULL;
    ultimoNo = NULL;
}
TEMPL ListaEncadeada<T>::~ListaEncadeada()
{

}

TEMPL T *ListaEncadeada<T>::getObjeto() const
{
    return objeto;
}

TEMPL void ListaEncadeada<T>::setObjeto(T *value)
{
    objeto = value;
}
