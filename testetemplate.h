#ifndef TESTETEMPLATE_H
#define TESTETEMPLATE_H

template <class T>
class TesteTemplate
{
private:
    T *vetor;
public:
    TesteTemplate();
    ~TesteTemplate();
    T *getVetor() const;
    void setVetor(T *value);
};

#include "testetemplate.cpp"
#endif // TESTETEMPLATE_H
