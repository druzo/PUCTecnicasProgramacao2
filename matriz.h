#ifndef MATRIZ_H
#define MATRIZ_H
#include "QStandardItemModel"


template <class T>
class Matriz
{
private:
    T *matriz;
    unsigned int qtdeLinhas, qtdeColunas;
public:
    Matriz add(Matriz<T> &matriz);
    Matriz operator+(Matriz<T> &matriz);

    Matriz sub(Matriz<T> &matriz);
    Matriz operator-(Matriz<T> &matriz);

    Matriz mul(Matriz<T> &matriz);
    Matriz operator*(Matriz<T> &matriz);

    Matriz(const unsigned int qtdeLinhas, const unsigned int qtdeColunas);
    virtual ~Matriz();
    unsigned int getQtdeLinhas() const;
    unsigned int getQtdeColunas() const;
    T getValor(const unsigned int linha, const unsigned int coluna);
    T getValor(const unsigned int posicao);
    void setValor(const unsigned int linha, const unsigned int coluna, const T valor);
    void setValor(const unsigned int posicao,const T valor);
    void print(QStandardItemModel *modelo);
    void gerarValoresRandomicos();
};

template <class T>
class Vetor: private Matriz<T>
{
public:
    Vetor<T>(const unsigned int qtdeLinhas):Matriz<T>(qtdeLinhas, 1){}
    unsigned int getQtdeLinhas() const;
    T getValor(const unsigned int linha);
    void setValor(const unsigned int posicao,const T valor);
    void print(QStandardItemModel *modelo);
};
#include "matriz.cpp"
#endif // MATRIZ_H
