#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
 
using namespace std;
bool sortByVal(const pair<string, int>& a,
    const pair<string, int>& b)
{
    return (a.second > b.second);
}
int main()
{
    setlocale(LC_ALL, "rus");
    string str;
    ifstream fin;
    fin.open("file1.log");
    if (!fin)
    {
        cout << "Файл не открыт\n";
    
    }
    else
    {
        cout << "Файл открыт!\n";
    }
    map <string, int> zapros;//словарь для хранения статуса запроса и кол-во 
    while (!fin.eof())
    {
        str = "";
        getline(fin,str);
        if (str == "") break;
        str=str.substr(str.find("HTTP")+10,3);
        ++zapros[str];//создание или добавление в словарь
        
    }
    fin.close();
    cout<<"Файл прочитан!"<<endl;
    vector<pair<string, int>> vec;// пустой вектор чтобы сделать сортировку по значению в словаре
    map<string, int> ::iterator it2;
    for (it2 = zapros.begin(); it2 != zapros.end(); it2++)
    {
        vec.push_back(make_pair(it2->first, it2->second));
    }
    sort(vec.begin(), vec.end(), sortByVal);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].first << ": " << vec[i].second << endl;
    }
    system("pause");
    return 0;
 
}
