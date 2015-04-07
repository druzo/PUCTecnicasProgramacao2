#include "matriz.h"


template <class T>
unsigned int Matriz<T>::getQtdeLinhas() const
{
    return qtdeLinhas;
}

template <class T>
unsigned int Matriz<T>::getQtdeColunas() const
{
    return qtdeColunas;
}

//funcao responsavel para pegar o valor de uma matriz
template <class T>
T Matriz<T>::getValor(const unsigned int linha, const unsigned int coluna)
{
    //Validações
    if(linha > qtdeLinhas - 1)
    {
        throw "Essa matriz não possui essa linha!";
    }

    if(coluna > qtdeColunas - 1)
    {
        throw "Essa matriz não possui essa coluna!";
    }

    return this->matriz[linha * this->qtdeColunas + coluna];
}

template <class T>
T Matriz<T>::getValor(const unsigned int posicao)
{
    if(posicao > (this->qtdeColunas * this->qtdeLinhas) - 1)
    {
        throw "Posição inválida";
    }
    return this->matriz[posicao];
}

//funcao responsável por atribuir um valor na matriz
template <class T>
void Matriz<T>::setValor(const unsigned int linha, const unsigned int coluna, const T valor)
{
    //Validações
    if(linha > qtdeLinhas - 1)
    {
        throw "Essa matriz não possui essa linha!";
    }

    if(coluna > qtdeColunas - 1 )
    {
        throw "Essa matriz não possui essa coluna!";
    }

    this->matriz[linha * this->qtdeColunas + coluna] = valor;
}

template <class T>
void Matriz<T>::setValor(const unsigned int posicao, const T valor)
{
    if(posicao > (this->qtdeColunas * this->qtdeLinhas) - 1)
    {
        throw "Posição inválida";
    }
    this->matriz[posicao] = valor;
}

template <class T>
void Matriz<T>::print(QStandardItemModel *modelo)
{
    modelo->clear();
    modelo->setRowCount(qtdeLinhas);
    modelo->setColumnCount(qtdeColunas);

    QStandardItem *celula;
    for (unsigned int i = 0; i < this->qtdeLinhas; ++i)
    {
        for (unsigned int j = 0; j < this->qtdeColunas; ++j)
        {
            QString str = QString::number(this->matriz[i * this->qtdeColunas + j]);
            celula = new QStandardItem(str);
            modelo->setItem(i, j, celula);
        }
    }
}

template <class T>
void Matriz<T>::gerarValoresRandomicos()
{
    for (unsigned int i = 0; i < (qtdeLinhas * qtdeColunas); ++i)
    {
        this->matriz[i] = rand() % 100;
    }
}

template <class T>
Matriz<T> Matriz<T>::add(Matriz<T> &matriz)
 {
     if (matriz.getQtdeLinhas() != this->qtdeLinhas)
     {
         throw "Para realiar a soma, a matriz passada no parâmetro deve possuir a mesma quantidade de colunas";
     }

     if (matriz.getQtdeColunas() != this->qtdeColunas)
     {
         throw "Para realiar a soma, a matriz passada no parâmetro deve possuir a mesma quantidade de colunas";
     }
     Matriz<T> resultado(this->qtdeLinhas, this->qtdeColunas);

     for (unsigned int i = 0; i < (qtdeLinhas * qtdeColunas); ++i)
     {
        resultado.setValor(i, this->matriz[i] + matriz.getValor(i));
     }

     return resultado;
 }

template <class T>
Matriz<T> Matriz<T>::operator+(Matriz<T> &matriz)
 {
     return this->add(matriz);
 }

template <class T>
Matriz<T> Matriz<T>::sub(Matriz<T> &matriz)
 {
     if (matriz.getQtdeLinhas() != this->qtdeLinhas)
     {
         throw "Para realiar a soma, a matriz passada no parâmetro deve possuir a mesma quantidade de colunas";
     }

     if (matriz.getQtdeColunas() != this->qtdeColunas)
     {
         throw "Para realiar a soma, a matriz passada no parâmetro deve possuir a mesma quantidade de colunas";
     }
     Matriz<T> resultado(this->qtdeLinhas, this->qtdeColunas);

     for (unsigned int i = 0; i < (qtdeLinhas * qtdeColunas); ++i)
     {
        resultado.setValor(i, this->matriz[i] - matriz.getValor(i));
     }

     return resultado;
 }

template <class T>
Matriz<T> Matriz<T>::operator-(Matriz<T> &matriz)
 {
     return sub(matriz);
 }

template <class T>
Matriz<T> Matriz<T>::mul(Matriz<T> &matriz)
 {
     if (matriz.getQtdeLinhas() != this->qtdeColunas)
     {
         throw "A quantidade de colunas da matriz A tem que ser igual a quantidade de linhas da Matriz B";
     }
     Matriz<T> resultado(this->qtdeLinhas, matriz.getQtdeColunas());

     for (unsigned int linha = 0; linha < this->qtdeLinhas; linha++)
     {
         for (unsigned int coluna = 0; coluna < matriz.getQtdeColunas(); coluna++)
         {
            int somaprod = 0;
            for(unsigned int i = 0; i < this->qtdeLinhas; i++)
            {
                somaprod += this->getValor(linha, i) * matriz.getValor(i, coluna);
            }
            resultado.setValor(linha, coluna, somaprod);
         }
     }
     return resultado;
 }

template <class T>
Matriz<T> Matriz<T>::operator*(Matriz<T> &matriz)
 {
    return mul(matriz);
 }

template <class T>
Matriz<T>::Matriz(const unsigned int qtdeLinhas, const unsigned int qtdeColunas)
{
    if (qtdeLinhas <= 0)
    {
        throw "A quantidade de linhas da matriz deve ser maior do que zero";
    }

    if (qtdeColunas <= 0)
    {
        throw "A quantidade de colunas da matriz deve ser maior do que zero";
    }
    this->qtdeLinhas = qtdeLinhas;
    this->qtdeColunas = qtdeColunas;
    matriz = new int[qtdeLinhas * qtdeColunas];
    //inicializando valores da matriz
    for (unsigned int i = 0; i < (qtdeLinhas * qtdeColunas); ++i)
    {
        matriz[i] = 0;
    }
}

template <class T>
Matriz<T>::~Matriz()
{
    delete []matriz;
}

template <class T>
unsigned int Vetor<T>::getQtdeLinhas() const
{
    return Matriz<T>::getQtdeLinhas();
}

template <class T>
T Vetor<T>::getValor(const unsigned int linha)
{
    return Matriz<T>::getValor(linha);
}

template <class T>
void Vetor<T>::setValor(const unsigned int posicao, const T valor)
{
    Matriz<T>::setValor(posicao, valor);
}

template <class T>
void Vetor<T>::print(QStandardItemModel *modelo)
{
    Matriz<T>::print(modelo);
}
