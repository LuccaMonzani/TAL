#include "Filtros.hpp"
#include <iostream>
#include <vector>

void print_vetor(std::vector<float> vetor_impressao)
{
    std::cout << "{ ";
    for (int i = 0; i < vetor_impressao.size(); i++)
    {
        printf("%.4f,", vetor_impressao[i]);
    }
    std::cout << "}" << std::endl;
}

int main()
{
    std::vector<float> vetor_teste{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<float> vetor_pesos{0.2, 0.3, 0.5};

    std::vector<float> vetor_resultado_mms = Filtros::MMS(vetor_teste, 3);
    std::vector<float> vetor_resultado_mmp = Filtros::MMP(vetor_teste, vetor_pesos);
    std::vector<float> vetor_resultado_mme = Filtros::MME(vetor_teste, 3);

    print_vetor(vetor_teste);
    print_vetor(vetor_resultado_mms);
    print_vetor(vetor_resultado_mmp);
    print_vetor(vetor_resultado_mme);
}