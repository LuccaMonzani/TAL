#include "Filtros.hpp"

namespace Filtros
{
    std::vector<float> media_movel_simples(std::vector<float> dados, int tamanho_da_amostra)
    /*Media movel simples para atenuar variações bruscas da amostragem*/
    {
        int tamanho_vetor_dados = dados.size();
        std::vector<float> vetor_retorno;

        float acc;

        for (int i = 0; i <= tamanho_vetor_dados - tamanho_da_amostra; i++)
        {
            acc = 0;

            for (int j = 0; j < tamanho_da_amostra; j++)
            {
                acc += dados[i + j];
            }

            acc /= tamanho_da_amostra;
            vetor_retorno.push_back(acc);
        }

        return vetor_retorno;
    }

    std::vector<float> media_movel_ponderada(std::vector<float> dados, std::vector<float> pesos)
    /*Media movel ponderada, onde pode-se escolher o quanto cada elemento*/
    {
        int tamanho_vetor_dados = dados.size();
        int tamanho_vetor_pesos = pesos.size();
        std::vector<float> vetor_retorno;

        float acc1, acc2;

        for (int i = 0; i <= tamanho_vetor_dados - tamanho_vetor_pesos; i++)
        {
            acc1 = 0;
            acc2 = 0;

            for (int j = 0; j < tamanho_vetor_pesos; j++)
            {
                acc1 += dados[i + j] * pesos[j];
                acc2 += pesos[j];
            }

            acc1 /= acc2;
            vetor_retorno.push_back(acc1);
        }

        return vetor_retorno;
    }

    std::vector<float> media_movel_exponencial(std::vector<float> dados, int tamanho_da_amostra)
    /*
    Media movel exponencial, um tipo de media onde os dados mais recentes possuem um peso maior
    */
    {

        int tamanho_vetor_dados = dados.size();
        float alpha = 2 / ((float)tamanho_da_amostra + 1);
        std::vector<float> vetor_retorno;

        float acc1, acc2;

        for (int i = 0; i <= tamanho_vetor_dados - tamanho_da_amostra; i++)
        {
            acc1 = 0;
            acc2 = 0;

            for (int j = 0; j < tamanho_da_amostra; j++)
            {
                acc1 += dados[i + j] * pow(1 - alpha, tamanho_da_amostra - j - 1);
                acc2 += pow(1 - alpha, tamanho_da_amostra - j - 1);
            }

            acc1 /= acc2;
            vetor_retorno.push_back(acc1);
        }

        return vetor_retorno;
    }
}