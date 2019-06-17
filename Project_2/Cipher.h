           /** 
* @file Cipher.h 
* @author Прозоров В.Е. 
* @date 17.06.2019 
* @copyright ИБСТ ПГУ 
* @warning Это учебный пример 
* @brief Шифрование методом маршрутной перестановки 
*/ 
#pragma once 
           #include <string>
#include <stdexcept>
using namespace std; 
/** @brief Шифрование методом маршрутной перестановки 
* @details Ключ устанавливается в конструкторе. 
* Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt. 
* @warning Реализация только для английского языка 
*/ 
class Cipher 
{ 
char** value; 
int m, n; 
/** @brief Валидация текста 
* @param [in] s Строка для шифрования или расшифровывания
* @return Валидная строка 
* @throw Error текст пустой, содержит недопустимые символы или ее длина короче ключа 
*/
public: 
/** @brief Конструктор по умолчанию 
* @details Запрещен 
*/ 
Cipher() = delete; 
/** @brief Конструктор для установки ключа 
* @param [in] key Целочисленный ключ 
* @throw Error ключ вырожденный 
*/ 
Cipher(int key, const string& s); 
/** @brief Зашифровывание 
* @details По ключу строит таблицу. Заполняет текстом слева направо, сверху вниз. 
* Считывает - сверху вниз, справа налево. 
* @param [in] open_text Открытый текст. Не должен быть пустой строкой и короче значения ключа. 
* @return Зашифрованная строка 
* @throw Error текст пустой, содержит недопустимые символы или ее длина короче ключа 
*/ 
string encrypt(const string& open_text); 
/** @brief Расшифровывание 
* @details По ключу строит таблицу. Заполняет текстом сверху вниз, справа налево. 
* Считывает - слева направо, сверху вниз. 
* @param [in] open_text Открытый текст. Не должен быть пустой строкой и короче значения ключа. 
* @return Расшифрованная строка 
* @throw Error текст пустой, содержит недопустимые символы или ее длина короче ключа 
*/
string decrypt(const string& cipher_text); 
/** @brief Класс-исключение. 
* @details Призводный от класса invalid_argument. 
* При перегрузке конструкторов явно указаны вызов конструктора базового класса с параметром. 
*/ 
~Cipher();
}; 
class Error: public invalid_argument 
{ 
public: 
   explicit Error (const string& what_arg): invalid_argument(what_arg) {} 
   explicit Error (const char* what_arg): invalid_argument(what_arg) {} 
}; 