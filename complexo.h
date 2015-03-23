
#ifndef COMPLEXO_H
#define COMPLEXO_H

#include <QtWidgets/QPlainTextEdit>

//referência do editor para realizar a saída dos dados
extern QPlainTextEdit *Saida;

class Complexo
{
private:
    float valor;
    float valorImaginario;
public:
    void setValor(float valor);
    float getValor();
    float getValorImaginario();
    void print();
    Complexo add(const float valor);
    Complexo add(Complexo valor);
    Complexo sub(const float valor);
    Complexo sub(Complexo valor);
    Complexo mul(const float valor);
    Complexo mul(Complexo valor);
    Complexo(float valor, float valorImaginario);
    Complexo(float valor);
    /* Funcao para somar outro numero complexo */
    Complexo operator+(Complexo valor);
    Complexo operator+(const float valor);
    Complexo operator-(Complexo valor);
    Complexo operator*(Complexo valor);
    Complexo();
    ~Complexo();
};

#endif // COMPLEXO_H
