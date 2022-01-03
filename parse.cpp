#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

string reg[150] = 
{
    "Вне конкурса", "Республика Адыгея", "Республика Башкортостан", "Республика Бурятия", "Республика Алтай", "Республика Дагестан", "Республика Ингушетия", "Кабардино-Балкарская Республика", "Республика Калмыкия", "Карачаево-Черкесская Республика", "Республика Карелия", "Республика Коми", "Республика Марий Эл", "Республика Мордовия", "Республика Саха", "Республика Северная Осетия", "Республика Татарстан", "Республика Тыва", "Удмуртская Республика", "Республика Хакасия", "Чеченская Республика", "Чувашская Республика", "Алтайский край", "Краснодарский край", "Красноярский край", "Приморский край", "Ставропольский край", "Хабаровский край", "Амурская область", "Архангельская область", "Астраханская область", "Белгородская область", "Брянская область", "Владимирская область", "Волгоградская область", "Вологодская область", "Воронежская область", "Ивановская область", "Иркутская область", "Калининградская область", "Калужская область", "Камчатский край", "Кемеровская область", "Кировская область", "Костромская область", "Курганская область", "Курская область", "Ленинградская область", "Липецкая область", "Магаданская область", "Московская область", "Мурманская область", "Нижегородская область", "Новгородская область", "Новосибирская область", "Омская область", "Оренбургская область", "Орловская область", "Пензенская область", "Пермский край", "Псковская область", "Ростовская область", "Рязанская область", "Самарская область", "Саратовская область", "Сахалинская область", "Свердловская область", "Смоленская область", "Тамбовская область", "Тверская область", "Томская область", "Тульская область", "Тюменская область", "Ульяновская область", "Челябинская область", "Забайкальский край", "Ярославская область", "Москва", "Санкт-Петербург", "Еврейская автономная область", "80", "81", "82", "Ненецкий автономный округ", "84", "85", "Ханты-Мансийский автономный округ", "Чукотский автономный округ", "88", "Ямало-Ненецкий автономный округ", "Не РФ", "Неизвестный"
};

struct child
{
    int a[15];
};


int stoy(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
        ans = ans * 10 + (s[i] - '0');
    //cout << ans << '\n';
    return ans;
}

string s;
map <string, child> m;
vector <pair <string, vector <int> > > fin;

bool cmp(pair <string, vector <int> > x, pair <string, vector <int> > y)
{
    return x.second[10] > y.second[10];
}
int main(){
    ifstream cin("short.html");
    ifstream din("stand.html");
    ofstream cout("members.txt");
    bool ok = 0;
    string user;
    string tag;
    int re, gr;
    while (getline(cin, s)){
        if (s.find("<td  class=\"st_team\">") != string::npos){
            int st = s.find("<td  class=\"st_team\">") + 21, en = s.length();
            if (s.find("<", st) != string::npos)
                en = s.find("<", st);
            user = s.substr(st, en - st);
            ok = 1;
        }
        if (s.find("<td class=\"st_extra\">") != string::npos){
            int st = s.find("<td class=\"st_extra\">") + 21, en = s.length();
            string r, g;
            r = s.substr(st, 2);
            g = s.substr(s.length() - 7, 2);
            if (g[0] == ' ')
                g.erase(g.begin());
            if (g[1] == ' ')
                g.erase(1);
            if (r[1] == ' ')
                r.erase(1);
            if (r != ":")
                re = stoy(r);
            else
                re = 91;
            if (g != ",")
                gr = stoy(g);
            else
                gr = 0;
            tag = user + ", " + to_string(gr) + " класс, " + reg[min(re, 91)];
        }
        if (s.find("<td  class=\"st_score\">") != string::npos){
            int st = s.find("<td  class=\"st_score\">") + 22, en = s.length();
            if (s.find("<", st) != string::npos)
                en = s.find("<", st);
            m[tag].a[9] = stoi(s.substr(st, en - st));
        }
    }
    int cnt = 0;
    ok = 0;
    while (getline(din, s)){
        if (s.find("<td  class=\"st_team\">") != string::npos){
            cnt = 0;
            int st = s.find("<td  class=\"st_team\">") + 21, en = s.length();
            if (s.find("<", st) != string::npos)
                en = s.find("<", st);
            user = s.substr(st, en - st);
            ok = 1;
        }
        if (s.find("<td class=\"st_extra\">") != string::npos){
            int st = s.find("<td class=\"st_extra\">") + 21, en = s.length();
            string r, g;
            r = s.substr(st, 2);
            g = s.substr(s.length() - 7, 2);
            if (g[0] == ' ')
                g.erase(g.begin());
            if (g[1] == ' ')
                g.erase(1);
            if (r[1] == ' ')
                r.erase(1);
            if (r != ":")
                re = stoy(r);
            else
                re = 91;
            if (g != ",")
                gr = stoy(g);
            else
                gr = 0;
            tag = user + ", " + to_string(gr) + " класс, " + reg[min(re, 91)];
        }
        if (s.find("<td  class=\"st_prob\">") != string::npos){
            int st = s.find("<td  class=\"st_prob\">") + 21, en = s.length();
            if (s[st] == '<'){
                st += 3;
                en = s.find("<", st);
                m[tag].a[cnt] = stoi(s.substr(st, en - st));
                cnt++;
            }
            else if (s[st] == '&'){
                m[tag].a[cnt] = -1;
                cnt++;
            }
            else {
                en = s.find("(", st);
                m[tag].a[cnt] = stoi(s.substr(st, en - st));
                cnt++;
            }
        }
    }
    for (auto it : m){
        int sum = 0;
        vector <int> bruh;
        for (int i = 0; i <= 9; i++){
            bruh.push_back(m[it.first].a[i]);
            if (m[it.first].a[i] != -1)
                m[it.first].a[10] += m[it.first].a[i];
        }
        bruh.push_back( m[it.first].a[10]);
        fin.push_back({it.first, bruh});
    }
    /*
    for (int i = 0; i < fin.size(); i++){
        for (int)
    }
    */
    sort(fin.begin(), fin.end(), cmp);
    for (int i = 2; i < fin.size(); i++){
        cout << fin[i].first;
        for (int j = 0; j <= 10; j++)
            cout << "#;" << fin[i].second[j];
        cout << '\n';
    }
    return 0;
}