#include "testetemplate.h"

template <class T>
T *TesteTemplate<T>::getVetor() const
{
    return vetor;
}

template <class T>
void TesteTemplate<T>::setVetor(T *value)
{
    vetor = value;
}

template <class T>
TesteTemplate<T>::TesteTemplate()
{

}

template <class T>
TesteTemplate<T>::~TesteTemplate()
{

}

