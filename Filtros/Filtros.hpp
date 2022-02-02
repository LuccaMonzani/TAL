#include <iostream>
#include <array>
#include <vector>
#include <math.h>

namespace Filtros
{
    // Media movel simples
    std::vector<float> MMS(std::vector<float> vetor_dados, int tamanho_da_amostra);

    // Media movel ponderada, onde pode se escolher o quanto cada elemento
    // do vetor influencia no resultado da media
    std::vector<float> MMP(std::vector<float> vetor_dados, std::vector<float> vetor_pesos);

    // Media movel exponencial, um tipo de media onde os dados mais recentes
    // possuem um peso maior
    std::vector<float> MME(std::vector<float> vetor_dados, int tamanho_da_amostra);
}
