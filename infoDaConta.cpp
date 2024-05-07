#include <iostream>
#include <string>
using namespace std;

// Definindo uma estrutura para armazenar as informações da conta do cliente
struct CustomerAccount {
    string accountNumber;
    double balance;
    string lastTransaction;
};

// Função para obter os dados da conta do cliente
CustomerAccount getCustomerAccountData() {
    // Suponha que aqui haja código para obter os dados da conta do cliente
    // Por simplicidade, vou criar alguns dados fictícios
    CustomerAccount account;
    account.accountNumber = "123456789";
    account.balance = 5000.0;
    account.lastTransaction = "Depósito de $1000.00 em 2024-05-05";
    return account;
}

// Função para imprimir os dados da conta do cliente
void printCustomerAccountData(const CustomerAccount& account) {
    cout << "Últimas informações da conta do cliente:\n";
    cout << "Número da conta: " << account.accountNumber << "\n";
    cout << "Saldo: $" << account.balance << "\n";
    cout << "Última transação: " << account.lastTransaction << "\n";
}

int main() {
    // Obtendo os dados da conta do cliente
    CustomerAccount account = getCustomerAccountData();

    // Exibindo os dados na tela
    printCustomerAccountData(account);

    return 0;
}
