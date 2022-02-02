#include "Filtros.hpp"

namespace Filtros
{
    std::vector<float> MMS(std::vector<float> vetor_dados, int tamanho_da_amostra)
    {
        int tamanho_vetor_dados = vetor_dados.size();
        std::vector<float> vetor_retorno;

        for (int i = 0; i <= tamanho_vetor_dados - tamanho_da_amostra; i++)
        {
            float acc = 0;

            for (int j = 0; j < tamanho_da_amostra; j++)
            {
                acc += vetor_dados[i + j];
            }

            acc /= tamanho_da_amostra;
            vetor_retorno.push_back(acc);
        }

        return vetor_retorno;
    }

    std::vector<float> MMP(std::vector<float> vetor_dados, std::vector<float> vetor_pesos)
    {
        int tamanho_vetor_dados = vetor_dados.size();
        int tamanho_vetor_pesos = vetor_pesos.size();
        std::vector<float> vetor_retorno;

        for (int i = 0; i <= tamanho_vetor_dados - tamanho_vetor_pesos; i++)
        {
            float acc1 = 0;
            float acc2 = 0;

            for (int j = 0; j < tamanho_vetor_pesos; j++)
            {
                acc1 += vetor_dados[i + j] * vetor_pesos[j];
                acc2 += vetor_pesos[j];
            }

            acc1 /= acc2;
            vetor_retorno.push_back(acc1);
        }

        return vetor_retorno;
    }

    std::vector<float> MME(std::vector<float> vetor_dados, int tamanho_da_amostra)
    {

        int tamanho_vetor_dados = vetor_dados.size();
        float alpha = 2 / ((float)tamanho_da_amostra + 1);
        std::vector<float> vetor_retorno;

        for (int i = 0; i <= tamanho_vetor_dados - tamanho_da_amostra; i++)
        {
            float acc1 = 0;
            float acc2 = 0;

            for (int j = 0; j < tamanho_da_amostra; j++)
            {
                acc1 += vetor_dados[i + j] * pow(1 - alpha, tamanho_da_amostra - j - 1);
                acc2 += pow(1 - alpha, tamanho_da_amostra - j - 1);
            }

            acc1 /= acc2;
            vetor_retorno.push_back(acc1);
        }

        return vetor_retorno;
    }
}