#include <iostream>
#include <array>
#include <vector>
#include <math.h>
#include <stdint.h>

namespace Filtros
{
    // Media movel simples
    std::vector<float> medial_movel_simples(std::vector<float> vetor_dados, int tamanho_da_amostra);

    // Media movel ponderada, onde pode se escolher o quanto cada elemento
    // do vetor influencia no resultado da media
    std::vector<float> medial_movel_ponderada(std::vector<float> vetor_dados, std::vector<float> vetor_pesos);

    // Media movel exponencial, um tipo de media onde os dados mais recentes
    // possuem um peso maior
    std::vector<float> medial_movel_exponencial(std::vector<float> vetor_dados, int tamanho_da_amostra);
}
