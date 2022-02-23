#ifndef FILTROS
#define FILTROS

#include <vector>
#include <math.h>
#include <stdint.h>

namespace Filtros
{
    // Media movel simples
    template <typename T>
    std::vector<T> media_movel_simples(std::vector<T> dados, uint8_t tamanho_da_amostra);

    // Media movel ponderada, onde pode se escolher o quanto cada elemento
    // do vetor influencia no resultado da media
    template <typename T>
    std::vector<T> media_movel_ponderada(std::vector<T> dados, std::vector<float> pesos);

    // Media movel exponencial, um tipo de media onde os dados mais recentes
    // possuem um peso maior
    template <typename T>
    std::vector<T> media_movel_exponencial(std::vector<T> dados, uint8_t tamanho_da_amostra);
}

#endif
