#ifndef MATRIZ_H
#define MATRIZ_H
#include "QStandardItemModel"


class Matriz
{
private:
    int *matriz;
    unsigned int qtdeLinhas, qtdeColunas;
public:
    Matriz add(Matriz &matriz);
    Matriz operator+(Matriz &matriz);


    Matriz sub(Matriz &matriz);
    Matriz operator-(Matriz &matriz);

    Matriz mul(Matriz &matriz);
    Matriz operator*(Matriz &matriz);

    Matriz(const unsigned int qtdeLinhas, const unsigned int qtdeColunas);
    ~Matriz();
    unsigned int getQtdeLinhas() const;
    unsigned int getQtdeColunas() const;
    int getValor(const unsigned int linha, const unsigned int coluna);
    int getValor(const unsigned int posicao);
    void setValor(const unsigned int linha, const unsigned int coluna, const int valor);
    void setValor(const unsigned int posicao,const int valor);
    void print(QStandardItemModel *modelo);
    void gerarValoresRandomicos();
};

#endif // MATRIZ_H
