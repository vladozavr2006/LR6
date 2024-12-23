#include <iostream>
int task_1(char* massive)
{

    std::cout << "Введите строку: ";
    int j = -1;
    do
    {
        ++j;
        massive[j] = getchar();
    } while (massive[j] != '\n');
    std::cout << "Выделенные числа: " << '\n';
    int i = -1;
    do
    {
        ++i;
        if (massive[i] == '1' || massive[i] == '2' || massive[i] == '3' || massive[i] == '4' || massive[i] == '5' || massive[i] == '6' || massive[i] == '7' || massive[i] == '8' || massive[i] == '9')
        {
            do 
            {
                std::cout << massive[i];
                ++i;
            } while (massive[i] == '1' || massive[i] == '2' || massive[i] == '3' || massive[i] == '4' || massive[i] == '5' || massive[i] == '6' || massive[i] == '7' || massive[i] == '8' || massive[i] == '9' || massive[i] == '0');
            std::cout << '\n';
        }
        if ((massive[i] == '-' || massive[i] == '+') && (massive[i + 1] == '1' || massive[i + 1] == '2' || massive[i + 1] == '3' || massive[i + 1] == '4' || massive[i + 1] == '5' || massive[i + 1] == '6' || massive[i + 1] == '7' || massive[i + 1] == '8' || massive[i + 1] == '9'))
        {
            std::cout << massive[i];
            ++i;
            do 
            {
                std::cout << massive[i];
                ++i;
            } while (massive[i] == '1' || massive[i] == '2' || massive[i] == '3' || massive[i] == '4' || massive[i] == '5' || massive[i] == '6' || massive[i] == '7' || massive[i] == '8' || massive[i] == '9' || massive[i] == '0');
            --i;
            std::cout << '\n';
        }
        if(massive[i] == '0' && (massive[i + 1] != '1' || massive[i + 1] != '2' || massive[i + 1] != '3' || massive[i + 1] != '4' || massive[i + 1] != '5' || massive[i + 1] != '6' || massive[i + 1] != '7' || massive[i + 1] != '8' || massive[i + 1] != '9' || massive[i + 1] != '0'))
        {
            std::cout << massive[i] << '\n';
        }
    } while (massive[i] != '\0');
    return 0;
}
int task_2(char* massive)
{
    char a;
    std::cout << "Введите текст: ";
    std::cin.getline(massive, 200, '\n');
    std::cout << "Введите символ, который нужно удалить: ";
    std::cin >> a;
    std::cout << "Преобразованная строка: ";
    std::cin.ignore(32767, '\n');
    int i = 0;
    int k;
    do
    {
        k = i;
        if (massive[i] == a)
        {
            do
            {
                massive[i] = massive[i + 1];
                ++i;
            } while (massive[i] != '\n');
            k = k - 2;
        }
        i = k;
        ++i;
    } while (massive[i] != '\n');
    std::cout << massive << '\n';
    return 0;
}
int task_3(char* massive)
{
    std::cout << "Введите строку: ";
    std::cin.getline(massive, 200, '\n');
    int n = 0;
    int i = 0;
    char t;
    int k, l, e;
    std::cout << "Преобразованная строка: ";
    do
    {
        ++i;
    } while (massive[i] != ' ');
    ++i;
    do
    {
        do
        {
            t = massive[i];
            massive[i] = massive[n];
            massive[n] = t;
            ++n;
            ++i;
        } while (massive[n] != ' ' && massive[i] != ' ' && massive[i] != '\0');
        if (massive[n] == ' ' && massive[i] == ' ')
        {
            ++i;
            n = i;
            do
            {
                ++i;
            } while (massive[i] != ' ' && massive[i] != '\0');
            if (massive[i] == '\0')
            {
                std::cout << massive;
                return 0;
            }
            else 
            {
                ++i;
            }
        }
        else if (massive[n] == ' ' && massive[i] =='\0')
        {
            std::cout << massive;
            return 0;
        }
        else if (massive[n] == ' ')
        {
            do
            {
                massive[n] = massive[i];
                k = i;
                while (i != n + 1)
                {
                    massive[i] = massive[i - 1];
                    --i;
                }
                massive[i] = ' ';
                i = k + 1;
                ++n;
            } while (massive[i] != '\0' && massive[i] != ' ');
            n = i;
        }
        else if (massive[i] == ' ' || massive[i] == '\0')
        {
            k = i;
            i = i - 1;
            l = n;
            do 
            {
                while (massive[i] != ' ')
                {
                    --i;
                }
                e = i;
                while (i + 1 != k)
                {
                    massive[i] = massive[i + 1];
                    ++i;
                }
                massive[i] = massive[n];
                while (n + 1 != e)
                {
                    massive[n] = massive[n + 1];
                    ++n;
                }
                massive[n] = ' ';
                n = l;
                i = k - 1;
            } while (massive[n] != ' ');
            i = k;
            n = k;     
        }
        if (massive[n] == '\0')
        {
            std::cout << massive;
            return 0;
        }
        else if (massive[n] == ' ')
        {
            ++i;
            while (massive[i] != ' ' && massive[i] != '\0')
            {
                ++i;
            }
            if (massive[i] == '\0')
            {
                std::cout << massive;
                return 0;
            }
            ++n;
            ++i;
        }
    } while(1 == 1);
    return 0;
}
int main()
{
    char* massive = new char[200];
    char q, a;
    std::cout << "Введите номер задания: ";
    std::cin >> q;
    std::cin.ignore(32767, '\n');
    do
    {
        if (q == '1')
        {
            task_1(massive);
            delete[] massive;
            std::cout << "Введите 1, если хотите продолжить, 0, если заверашете программу: ";
            std::cin >> a;
            if (a == '1')
            {
                std::cout << "Введите номер задания: ";
                std::cin.ignore(32767, '\n');
                massive = new char[200];
            }
            else if (a == '0')
            {
                return 0;
            }
        }
        else if (q == '2')
        {
            task_2(massive);
            delete[] massive;
            std::cout << "Введите 1, если хотите продолжить, 0, если заверашете программу: ";
            std::cin >> a;
            if (a == '1')
            {
                std::cout << "Введите номер задания: ";
                std::cin.ignore(32767, '\n');
                massive = new char[200];
            }
            else if (a == '0')
            {
                return 0;
            }
        }
        else if (q == '3')
        {
            task_3(massive);
            delete[] massive;
            std::cout << '\n';
            std::cout << "Введите 1, если хотите продолжить, 0, если заверашете программу: ";
            std::cin >> a;
            if (a == '1')
            {
                std::cout << "Введите номер задания: ";
                std::cin.ignore(32767, '\n');
                massive = new char[200];
            }
            else if (a == '0')
            {
                return 0;
            }
            else 
            {
                while (a != '0' && a != '1') 
                {
                    std::cout << "Некорректный ввод, введите 0 или 1: ";
                    std::cin.ignore(32767, '\n');
                    std::cin >> a;
                }
                std::cout << "Введите номер задания: ";
            }
        }
        else
        {          
            std::cout << "Неправильный ввод, введите 1, 2 или 3: ";
        }
        std::cin >> q;
        std::cin.ignore(32767, '\n');
    } while (a != '0');
    return 0;
}