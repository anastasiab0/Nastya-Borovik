#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>

template <typename T>//шаблон класса
class Set {//класс множество
private:
    std::vector<T> elements;//вектор с элементами множества

public:
    // Проверка наличия элемента
    bool exist(const T& element) const{
        return std::find(elements.begin(), elements.end(), element) != elements.end();
    }

    // Добавление элемента
    void add(const T& element) {
        if (!exist(element)) {
            elements.push_back(element);
        }
    }

    // Удаление элемента
    void remove(const T& element) {
        auto it = std::remove(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            elements.erase(it, elements.end());
        }
    }

    // Вывод множества
    void print() const
    {
        for (const auto& elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    // Пересечение множеств
    Set<T> intersection(const Set<T>& other) const {
        Set<T> result;
        for (const auto& elem : elements) {
            if (other.exist(elem)) {
                result.add(elem);
            }
        }
        return result;
    }

    // Объединение множеств
    Set<T> unionSet(const Set<T>& other) const {
        Set<T> result = *this;
        for (const auto& elem : other.elements) {
            result.add(elem);
        }
        return result;
    }

    // Разность множеств
    Set<T> difference(const Set<T>& other) const {
        Set<T> result;
        for (const auto& elem : elements) {
            if (!other.exist(elem)) {
                result.add(elem);
            }
        }
        return result;
    }
};

void displayMenu() {//меню работы с программой
    std::cout << "\nМеню работы с множествами:\n";
    std::cout << "1. Добавить элемент в 1 множество\n";
    std::cout << "2. Добавить элемент во 2 множество\n";
    std::cout << "3. Удалить элемент из 1 множества\n";
    std::cout << "4. Удалить элемент из 2 множества\n";
    std::cout << "5. Вывод 1 множества\n";
    std::cout << "6. Вывод 2 множества\n";
    std::cout << "7. Пересечение двух множеств\n";
    std::cout << "8. Объединение двух множеств\n";
    std::cout << "9. Разность двух множеств\n";
    std::cout << "10. Добавить элемента из файла в 1 множество\n";
    std::cout << "11. Добавить элементы из файла во 2 множество\n";
    std::cout << "0. Выход\n";
    std::cout << "Введите вариант работы с программой: ";
}

template<typename T>//шаблон функции для правильного ввода данных, проверка на символы
T getInput() {
    T input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Неправильный ввод. Попробуйте снова: ";
        }
        else {
            return input;
        }
    }
}

template<typename T>//шаблон функции для добавления элементов множества из файла
void loadSetFromFile(Set<T>& set, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {//проверка на существование файла
        std::cerr << "Файл не найден!" << std::endl;
        return;
    }

    T element;
    while (file >> element) {
        set.add(element);//добавление элементов в 1 множество
    }
    file.close();
    std::cout << "Множество загружено из файла.\n";
}

template<typename T>//шаблон функции работы с файлом
void addElementsToSet(Set<T>& set) {
   
        std::cout << "Введите название файл с расширением: ";
        std::string filename;
        std::cin >> filename;
        loadSetFromFile(set, filename);
   }

int main() {
    setlocale(LC_ALL, "Russian");
    Set<int> set1, set2;//1 и 2 множества
    int choice;//вариант работы программы
    int element;//элемент множества

    while (true) {
        displayMenu();//вывод меню
        choice = getInput<int>();

        switch (choice) {
        case 1://добавление элемента с консоли в 1 мн-во
            std::cout << "Введите элемент, который хотите добавить в 1 множество: ";
            element = getInput<int>();
            set1.add(element);
            break;
        case 2://добавление элемента с консоли во 2 мн-во
            std::cout << "Введите элемент, который хотите добавить в 1 множество: ";
            element = getInput<int>();
            set2.add(element);
            break;
        case 3://удаление элемента из 1 мн-ва
            std::cout << "Введите элемент, который хотите удалить из 1 множества: ";
            element = getInput<int>();
            set1.remove(element);
            break;
        case 4://удаление элемента из 2 мн-ва
            std::cout << "Введите элемент, который хотите удалить из 2 множества: ";
            element = getInput<int>();
            set2.remove(element);
            break;
        case 5://вывод 1 мн-ва
            std::cout << "Множество 1: ";
            set1.print();
            break;
        case 6://вывод 2 мн-ва
            std::cout << "Множество 2: ";
            set2.print();
            break;
        case 7: {//пересечение множеств
            Set<int> intersect = set1.intersection(set2);
            std::cout << "Пересечение: ";
            intersect.print();
            break;
        }
        case 8: {//объединение множеств
            Set<int> unionSet = set1.unionSet(set2);
            std::cout << "Объединение: ";
            unionSet.print();
            break;
        }
        case 9: {//разность между 1 и 2 множествами
            Set<int> difference = set1.difference(set2);
            std::cout << "Разность: ";
            difference.print();
            break;
        }
        case 10://добавление элементов из файла в 1 мн-во
            addElementsToSet(set1);
            break;
        case 11://добавление элементов из файла во 2 мн-во
            addElementsToSet(set2);
            break;
       
        case 0:
            std::cout << "Выход из программы.\n";
            return 0;
        default:
            std::cout << "Неправильный ввод данных. Попробуйте снова.\n";
        }
    }
    return 0;
}