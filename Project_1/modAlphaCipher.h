/** @file modAlphaCipher.h 
* @author Прозоров В.Е. 
* @version 1.0 
* @date 17.06.2019 
* @copyright ИБСТ ПГУ 
* @warning Это учебный пример 
* @brief Заголовочный файл для модуля Gronsfeld 
*/ 
#pragma once
#include <vector>
#include <string>
#include <codecvt>
#include <locale>
#include <map>
using namespace std;
/** @brief Шифрование методом Гронсфельда 
* @details Ключ устанавливается в конструкторе.Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt. 
* @warning Реализация только для русского языка 
*/ 
class modAlphaCipher 
{ 
private:
    wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Русский алфавит 
    map alphaNum; ///< Ассоциативный массив"номер по символу" 
    std::vector key; ///< Ключ 
/** @brief Преобразование строка-вектор 
* @param [in] ws Строка в кодировке UTF-32 
* @return Целочисленный вектор 
*/ 
	vector<int> convert(const wstring& ws);
/** @brief Преобразование вектор-строка 
* @param [in] v Целочисленный вектор 
* @return Строка в кодировке UTF-8 
	*/ 
string convert(const vector& v); 
/** @brief Валидация ключа 
* @param [in] ws Ключ в кодировке UTF-32. Не должен быть пустой строкой. 
* Строчные символы автоматически преобразуются к прописным. 
* @return Валидный ключ в кодировке UTF-32 
* @throw cipher_error ключ пустой или содержит недопустимые символы 
*/ 
wstring getValidKey(const wstring & ws); 
/** @brief Валидация открытого текста 
* @param [in] ws Открытый текст в кодировке UTF-32. Не должен быть пустой строкой. 
* Строчные символы автоматически преобразуются к прописным. 
* @return Валидный открытый текст в кодировке UTF-32 
* @throw cipher_error текст пустой или содержит недопустимые символы 
*/ 
inline wstring getValidOpenText(const wstring & ws); 
/** @brief Валидация зашифрованного текста 
* @param [in] ws Зашифрованный текст в кодировке UTF-32. Не должен быть пустой строкой. 
* Не должен содержать строчные символы и не-буквы. 
* @return Валидный зашифрованный текст в кодировке UTF-32
* @throw cipher_error текст пустой или содержит недопустимые символы. 
*/ 
inline wstring getValidCipherText(const wstring & ws);
public: 
/** @brief Конструктор без параметров 
* @details Запрещен 
*/ 
modAlphaCipher()=delete; 
/** @brief Конструктор для установки ключа 
* @details Ключ проверяется на валидность. Переводится в кодировку UTF-32. 
* Формируется вектор-ключ. 
* @param [in] skey Ключ в кодировке UTF-8 
* @throw cipher_error ключ вырожденный 
*/
modAlphaCipher(const string& skey); 
/** @brief Зашифровывание 
* @param [in] open_text Открытый текст в кодировке UTF-8. Не  должен быть пустой строкой. 
* Строчные символы автоматически преобразуются к прописным.Все не-буквы удаляются. 
* @return Зашифрованная строка в кодировке UTF-8 
* @throw cipher_error текст пустой 
*/ 
string encrypt(const string& open_text); 
/** @brief Расшифровывание 
* @param [in] cipher_text Зашифрованный текст в кодировке UTF-8. Не должен быть пустой строкой. 
* Не должен содержать строчные символы и не-буквы. 
* @return Расифрованная строка в кодировке UTF-8 
* @throw cipher_error текст пустой 
*/
string decrypt(const string& cipher_text); 
/** @brief Перевод из кодировки UTF-8 в UTF-32 
* @param [in] s Строка в кодировке UTF-8 
* @return Строка в кодировке UTF-32 
*/
wstring towstr(const string& s); 
/** @brief Перевод из кодировки UTF-32 в UTF-8 
* @param [in] s Строка в кодировке UTF-32 
* @return Строка в кодировке UTF-8 
*/
string fromwstr(const wstring& ws); 
};    
/** @brief Класс-исключение. 
* @details Призводный от класса invalid_argument. 
* При перегрузке конструкторов явно указаны вызов конструктора базового класса с параметром. 
*/
class cipher_error: public std::invalid_argument 
{ 
public: 
    explicit cipher_error (const string& what_arg):invalid_argument(what_arg) {} 
    explicit cipher_error (const char* what_arg):invalid_argument(what_arg) {} 
}; 
