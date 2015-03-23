#include "complexo.h"

void Complexo::setValor(float valor)
{
    this->valor = valor;
}

float Complexo::getValor()
{
    return this->valor;
}

float Complexo::getValorImaginario()
{
    return this->valorImaginario;
}

void Complexo::print()
{
    QString b = QString::number(valor);
    QString i = QString::number(this->valorImaginario);
    Saida->appendPlainText(b + " "+ i + "i");
}

Complexo Complexo::add(const float valor)
{
    this->valor += valor;
    return Complexo(this->valor, this->valorImaginario);
}

Complexo Complexo::add(Complexo valor)
{
    this->valor += valor.getValor();
    this->valorImaginario += valor.getValorImaginario();
    return Complexo(this->valor, this->valorImaginario);
}

Complexo Complexo::sub(const float valor)
{
    this->valor -= valor;
    return Complexo(this->valor, this->valorImaginario);
}

Complexo Complexo::sub(Complexo valor)
{
    this->valor -= valor.getValor();
    this->valorImaginario -= valor.getValorImaginario();
    return Complexo(this->valor, this->valorImaginario);
}

Complexo Complexo::mul(const float valor)
{
    float valorReal = this->valor * valor;
    float valorImaginario = valor * this->valorImaginario;
    valorImaginario += this->valorImaginario;
    valorReal -= this->valorImaginario;
    this->valor = valorReal;
    this->valorImaginario = valorImaginario;
    return Complexo(valorReal, valorImaginario);
}

Complexo Complexo::mul(Complexo valor)
{
    float valorReal = this->valor * valor.getValor();
    float valorImaginario = this->valorImaginario * valor.getValor();
    valorImaginario += (this->valor * valor.getValorImaginario());
    valorReal += ( (this->valorImaginario * valor.getValorImaginario()) * -1);
    this->valor = valorReal;
    this->valorImaginario = valorImaginario;
    return Complexo(valorReal, valorImaginario);
}

Complexo::Complexo(float valor, float valorImaginario)
{
    this->valor = valor;
    this->valorImaginario = valorImaginario;
}

Complexo::Complexo(float valor)
{
    this->valor = valor;
    this->valorImaginario = 1;
}

Complexo Complexo::operator+(Complexo valor)
{
    return this->add(valor);
}

Complexo Complexo::operator+(const float valor)
{
    return this->add(valor);
}

Complexo Complexo::operator-(Complexo valor)
{
    return this->sub(valor);
}

Complexo Complexo::operator*(Complexo valor)
{
    return this->mul(valor);
}

Complexo::Complexo()
{         
    valor = 0;
    this->valorImaginario = 1;
}

Complexo::~Complexo()
{

}

