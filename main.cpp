#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;

struct Data
{
    string name;
    tm date;

};

main()
{
  Data birthday;
  vector <Data> vec;
  
while(1)
{
    string name;
    cout << "enter name:";
    cin >> name;
    if(name == "end")
    {
        break;
    }
    birthday.name = name;
    cout << "enter birthday:";
    cin >> get_time(&birthday.date, "%Y/%m/%d");
    vec.push_back(birthday);
  
}

for(int i = 0; i < vec.size(); i ++)
{
    cout << vec[i].name << " ";
    cout << put_time(&vec[i].date, "%Y-%m-%d") << endl;
    // time_t local = mktime(&vec[i].date); 
    // cout << (unsigned long)local << std::endl;


    // Создаем структуру времени tm для текущей ды
    time_t today = time(nullptr);
    tm * now_tm = localtime(&today);

    // Создаем структуру времени tm для дня рождения
    tm * bday_tm = localtime(&today);
    bday_tm->tm_mon = vec[i].date.tm_mon - 1; // уменьшаем на 1, так как структура tm считает месяцы от  до 11
    bday_tm->tm_mday = vec[i].date.tm_mday;

    // Создаем структуру времени tm для дня рождения следующего года
    tm * bday_next_tm = localtime(&today);
    bday_next_tm->tm_mon = vec[i].date.tm_mon - 1; // уменьшаем на 1, так как структура tm считает месяцы от  до 11
    bday_next_tm->tm_mday = vec[i].date.tm_mday;
    bday_next_tm->tm_year += 1; // увеличиваем год на 1

     // Вычисляем разницу в днях между текущей датой и датой дня рождения текущего года
    time_t diff_bday = difftime(mktime(bday_tm), today) / 86400;
    // Вычисляем разницу в днях между текущей датой и датой дня рождения следующего года    
    time_t diff_bday_next = difftime(mktime(bday_next_tm), today) / 86400;

    // Если день рождения уже был в этом году, то пропускаем информацию о пользователе
    if(diff_bday )
    {
        continue;
    }

    // Сравниваем разницу сегодняшней даты и даты дня рождения текущегоода с разницей сегодняшней даты и даты дня рождения следующего года
    if(diff_bday_next < diff_bday)
    {
        bday_tm = bday_next_tm;
        diff_bday = diff_bday_next;
  
    }

     // Если день рождения сегодня, то выводим сообщение об этом на экран
    if(diff_bday == 0)
    {
        cout << vec[i].name << " : Happy Birthday!" << endl;
    }
    else // Иначе выводим ближайший день рождения в локальном формате (месяц/день)
    {
        cout << vec[i].name << " : ";
        cout << put_time(bday_tm, "%m/%d") << endl;
    }
}

 

return 0;

}


