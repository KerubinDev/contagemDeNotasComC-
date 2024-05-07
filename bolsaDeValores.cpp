#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Definindo uma estrutura para armazenar as informações de uma ação
struct Stock {
    string symbol;
    double price;
    double change;
};

// Função fictícia para obter os dados da bolsa de valores
vector<Stock> getStockData() {
    // Suponha que aqui haja código para obter os dados da bolsa de valores
    // Por simplicidade, vou criar alguns dados fictícios
    vector<Stock> stocks = {
        {"AAPL", 150.25, 1.50},
        {"GOOG", 2750.50, -2.25},
        {"MSFT", 300.75, 0.75},
        {"AMZN", 3450.20, -3.10}
    };
    return stocks;
}

// Função para imprimir os dados das ações
void printStockData(const vector<Stock>& stocks) {
    cout << "Últimas informações da bolsa de valores:\n";
    for (const auto& stock : stocks) {
        cout << "Ação: " << stock.symbol << "\n";
        cout << "Preço: $" << stock.price << "\n";
        cout << "Variação: " << stock.change << "%\n";
        cout << "-----------------------------\n";
    }
}

int main() {
    // Obtendo os dados da bolsa de valores
    vector<Stock> stocks = getStockData();

    // Exibindo os dados na tela
    printStockData(stocks);

    return 0;
}
