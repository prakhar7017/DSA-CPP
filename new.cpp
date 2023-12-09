#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Transaction {
    char type; // 'E' for expense, 'L' for loan repayment
    char from;
    char to;
    int amount;
};

struct Person {
    int balance;
    unordered_map<char, int> loans; // Amount borrowed from each person
};

unordered_map<char, Person> people;

void processTransaction(const Transaction& transaction) {
    if (transaction.type == 'E') {
        int splitAmount = transaction.amount / (transaction.to - transaction.from + 1);
        for (char i = transaction.from; i <= transaction.to; ++i) {
            people[i].balance -= splitAmount;
        }
    } else if (transaction.type == 'L') {
        people[transaction.from].loans[transaction.to] += transaction.amount;
    }
}

void calculateInterest(char person) {
    for (auto& loan : people[person].loans) {
        double interest = loan.second * 0.12;
        people[person].loans[loan.first] += static_cast<int>(interest);
    }
}

void reconcile() {
    vector<string> reconciliations;

    for (auto& person : people) {
        calculateInterest(person.first);

        for (auto& loan : person.second.loans) {
            char lender = loan.first;
            int amount = loan.second;
            int balance = people[person.first].balance;

            if (amount <= balance) {
                people[person.first].balance -= amount;
                people[lender].balance += amount;
                reconciliations.push_back(string(1, person.first) + "/" + string(1, lender) + "/" + to_string(amount));
                loan.second = 0;
            }
        }
    }

    sort(reconciliations.begin(), reconciliations.end());

    if (!reconciliations.empty()) {
        for (const string& reconciliation : reconciliations) {
            cout << reconciliation << endl;
        }
    } else {
        cout << "NO DUES." << endl;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;

        istringstream iss(line);
        char type;
        iss >> type;

        if (type == 'E') {
            char from, to;
            int amount;
            iss >> from >> amount >> to;
            Transaction transaction = {type, from, to, amount};
            processTransaction(transaction);
        } else if (type == 'L') {
            char from, to;
            int amount;
            iss >> from >> to >> amount;
            Transaction transaction = {type, from, to, amount};
            processTransaction(transaction);
        }
    }

    reconcile();

    return 0;
}
