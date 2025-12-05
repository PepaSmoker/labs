#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Connection
{
    int to;
    int price;
};

struct Stop
{
    string name;
    vector<Connection> routes;
};

vector<Stop> stops;

void viewStop()
{
    int id;
    cout << "Введите номер остановки: ";
    cin >> id;

    if (id < 0 || id >= stops.size())
    {
        cout << "Ошибка!\n";
    }

    cout << "Остановка: " << stops[id].name << endl;

    if (stops[id].routes.empty())
    {
        cout << "Конечная. Автобус дальше не идет.\n";
    }

    cout << "Маршруты:\n";
    for (auto r : stops[id].routes)
    {
        cout << " -> " << stops[r.to].name
            << " (Цена: " << r.price << ")\n";
    }
}

void createStop() {
    Stop s;
    cout << "Введите название остановки: ";
    cin.ignore();
    getline(cin, s.name);
    stops.push_back(s);
    cout << "Остановка добавлена.\n";
}


bool dfs(int current, int target, vector<bool>& visited, int& cost) {
    if (current == target) return true;

    visited[current] = true;

    for (auto& r : stops[current].routes) {
        if (!visited[r.to]) {
            cost += r.price;
            if (dfs(r.to, target, visited, cost))
                return true;
            cost -= r.price;
        }
    }
    return false;
}

void findWay()
{
    int A, B;
    cout << "Введите A и B: ";
    cin >> A >> B;

    if (A < 0 || B < 0 || A >= stops.size() || B >= stops.size()) {
        cout << "Ошибка ввода!\n";
        return;
    }

    vector<bool> visited(stops.size(), false);
    int cost = 0;

    if (dfs(A, B, visited, cost)) {
        cout << "Путь найден! Стоимость: " << cost << endl;
        if (stops[A].routes.empty())
            cout << "Автобус дальше не идет.\n";
    }
    else {
        cout << "Пути нет.\n";
    }
}

void addStop() {
    int from;
    cout << "С какой остановки начать? ";
    cin >> from;

    if (from < 0 || from >= stops.size())
    {
        cout << "Ошибка!\n";
        return;
    }

    Stop newStop;
    cout << "Введите название новой остановки: ";
    cin.ignore();
    getline(cin, newStop.name);

    stops.push_back(newStop);
    int newID = stops.size() - 1;

    int price;
    cout << "Введите цену проезда: ";
    cin >> price;

    stops[from].routes.push_back({ newID, price });

    cout << "Остановка добавлена в конец маршрута.\n";
}


void printAll() {
    for (int i = 0; i < stops.size(); ++i) {
        cout << i << ") " << stops[i].name << endl;
    }
}

void init() {
    stops = {
        { "a1", {{1, 10}} },
        { "a2", {{2, 15}} },
        { "a3", {} },

        { "a4", {{4, 12}} },
        { "a5", {} },

        { "a6", {{6, 8}} },
        { "a7", {} }
    };
}


int main()
{
    setlocale(LC_ALL, "RU");

    init();

    int choice = 1;
    while (choice != 0)
    {
        cout << "0. Выход\n";
        cout << "1. Просмотр остановки\n";
        cout << "2. Создание новой остановки\n";
        cout << "3. Показать путь из A в B\n";
        cout << "4. Добавить остановку в конец маршрута\n";
        cout << "5. Показать все остановки\n";

        cin >> choice;

        switch (choice)
        {
        case 1: viewStop(); break;
        case 2: createStop(); break;
        case 3: findWay(); break;
        case 4: addStop(); break;
        case 5: printAll(); break;
        }
    }

    return 0;
}