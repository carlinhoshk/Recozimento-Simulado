#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits.h>
#include <numeric>
#include <vector>

using namespace std;

double calcularDistanciaTotal(const vector<int> &caminho,
                              const vector<vector<double>> &distancias) {
  double distancia = 0.0;
  for (size_t i = 0; i < caminho.size() - 1; ++i) {
    distancia += distancias[caminho[i]][caminho[i + 1]];
  }
  distancia += distancias[caminho.back()][caminho.front()];

  return distancia;
}

vector<int> gerarVizinho(const vector<int> &caminhoAtual) {
  vector<int> novoCaminho = caminhoAtual;
  int i = rand() % novoCaminho.size();
  int j = rand() % novoCaminho.size();
  swap(novoCaminho[i], novoCaminho[j]);

  return novoCaminho;
}
// comeco do algoritmo de cozimento
vector<int> recozimentoSimulado(const vector<vector<double>> &distancias,
                                double tempInicial, double taxaResfriamento,
                                int iteracoesPorTemperatura) {
  int n = distancias.size();
  vector<int> melhorCaminho(n);
  iota(melhorCaminho.begin(), melhorCaminho.end(), 0);
  random_shuffle(melhorCaminho.begin(), melhorCaminho.end());

  vector<int> caminhoAtual = melhorCaminho;
  double melhorCusto = calcularDistanciaTotal(melhorCaminho, distancias);
  double custoAtual = melhorCusto;

  double temperatura = tempInicial;

  while (temperatura > 1e-3) {
    for (int iter = 0; iter < iteracoesPorTemperatura; ++iter) {
      vector<int> novoCaminho = gerarVizinho(caminhoAtual);
      double novoCusto = calcularDistanciaTotal(novoCaminho, distancias);

      double delta = novoCusto - custoAtual;

      if (delta < 0 || exp(-delta / temperatura) > (double)rand() / RAND_MAX) {
        caminhoAtual = novoCaminho;
        melhorCusto = custoAtual;
      }
    }
  }
  temperatura *= taxaResfriamento;

  return melhorCaminho;
}

int main() {
  srand(time(0));

  vector<vector<double>> distancias = {{1, 10, 15, 20, 25},
                                       {10, 0, 35, 25, 15},
                                       {15, 35, 0, 30, 20},
                                       {20, 25, 30, 0, 10},
                                       {25, 15, 20, 10, 0}};

  double tempInicial = 10000.0;
  double taxaResfriamento = 0.995;
  int iteracoesPorTemperatura = 100;

  vector<int> melhorCaminho = recozimentoSimulado(
      distancias, tempInicial, taxaResfriamento, iteracoesPorTemperatura);

  cout << "melhor caminho encontrado: ";
  for (int cidade : melhorCaminho) {
    cout << cidade << " ";
  }
  cout << melhorCaminho.front() << endl;

  cout << "Custo total: " << calcularDistanciaTotal(melhorCaminho, distancias)
       << endl;

  return 0;
}
