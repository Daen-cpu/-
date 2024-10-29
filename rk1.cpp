#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    char *title;
    char *author;
    int year;
    int copies;

    // конструктор
    Book(const char *t, const char *a, int y, int c) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        author = new char[strlen(a) + 1];
        strcpy(author, a);
        year = y;
        copies = c;
    }

    // деструктор
    ~Book() {
        delete[] title;
        delete[] author;
    }
};

// функция сортировки массива объектов Book на основе их названий(названия книг)
bool compareBooks(const Book *a, const Book *b) {
    return strcmp(a->title, b->title) < 0;
}

int main() {
    int amount_of_books_in_library;
    cout << "Введите количество книг в библиотеке: ";
    cin >> amount_of_books_in_library;

    // массив указателей на объект Book, где каждый объект инициализирован динамически
    Book **books = new Book*[amount_of_books_in_library];

    string *arr = new string[amount_of_books_in_library]; // названия книг
    string *arr1 = new string[amount_of_books_in_library]; // авторы
    int *arr2 = new int[amount_of_books_in_library]; // годы публикации
    int *arr3 = new int[amount_of_books_in_library]; // количество экземпляров

    
    for (int i = 0; i < amount_of_books_in_library; i++) {
        cout << "Введите название книги " << i + 1 << ": ";
        cin.ignore(); 
        getline(cin, *(arr + i));

        cout << "Введите автора книги " << i + 1 << ": ";
        getline(cin, *(arr1 + i));

        cout << "Введите год издания книги " << i + 1 << ": ";
        cin >> *(arr2 + i);

        cout << "Введите количество копий книги " << i + 1 << ": ";
        cin >> *(arr3 + i);

        
        books[i] = new Book(arr[i].c_str(), arr1[i].c_str(), arr2[i], arr3[i]); // Cоздание объектов Book с изменением типов с string на const char*, посредством метода .c_str()     
        cout << endl;
    }
// сортировка: books - book
    sort(books, books + amount_of_books_in_library, compareBooks);
// вывод по каждой из книг
    for (int i = 0; i < amount_of_books_in_library; i++) {
        cout << (i + 1) << ". " << books[i]->title << " - Автор: " << books[i]->author << ", Год издания: " << books[i]->year //
        		<< ", Количество копий: " << books[i]->copies << endl; // получаю доступ к объекту Book через указатель books[i]
    }
// чистка взятой динамической памяти у ос  
    for (int i = 0; i < amount_of_books_in_library; i++) {
        delete books[i]; 
    }
    delete[] books;
    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}
