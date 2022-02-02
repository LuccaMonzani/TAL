#include <iostream>
#include <array>
#include <vector>
#include <math.h>
#include <stdint.h>

namespace Filtros
{
    // Media movel simples
    std::vector<float> media_movel_simples(std::vector<float> dados, int tamanho_da_amostra);

    // Media movel ponderada, onde pode se escolher o quanto cada elemento
    // do vetor influencia no resultado da media
    std::vector<float> media_movel_ponderada(std::vector<float> dados, std::vector<float> pesos);

    // Media movel exponencial, um tipo de media onde os dados mais recentes
    // possuem um peso maior
    std::vector<float> media_movel_exponencial(std::vector<float> dados, int tamanho_da_amostra);
}
