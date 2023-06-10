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

// time_t t = time(NULL);
// tm *local = localtime(&t);
// local->tm_mon = 9;
// local->tm_mday = 23;
// local->tm_hour = 15;
// cout << local->tm_hour << endl;
// cout << asctime(local);


// time_t t = time(NULL);
// tm *local = localtime(&t);
// cout << put_time(local, "%Y-%m-%d");

// time_t t = time(NULL);
// tm local = *localtime(&t);
// cout << "enter";
// cin >> get_time(&local, "%H:%M");
// // cout << asctime(&local) << endl;
// // cout << put_time(&local, "%H:%M");

// time_t d = time(NULL);
// tm local2 = *localtime(&d);
// cout << "enter";
// cin >> get_time(&local2, "%H:%M");
// cout << asctime(&local) << endl;
// cout << put_time(&local, "%H:%M");





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
    cout <<"dates of birth: " << vec[i].name << " ";
    cout << put_time(&vec[i].date, "%Y-%m-%d") << endl;
    // time_t local = mktime(&vec[i].date); 
    // cout << (unsigned long)local << std::endl;
}

for(int i = 0; i < vec.size(); i ++)
{

//     // Создаем структуру времени tm для текущей ды
//     time_t today = time(nullptr);
//     tm * now_tm = localtime(&today);

      time_t today = time(NULL);
      tm * now_time = localtime(&today);
      cout << "today: "<< put_time(now_time, "%Y-%m-%d") << endl;

//     // Создаем структуру времени tm для дня рождения
//     tm * bday_tm = localtime(&today);
//     bday_tm->tm_mon = vec[i].date.tm_mon - 1; // уменьшаем на 1, так как структура tm считает месяцы от  до 11
//     bday_tm->tm_mday = vec[i].date.tm_mday;

       tm * bday = localtime(&today);
       bday->tm_mon = vec[i].date.tm_mon;
       bday->tm_mday = vec[i].date.tm_mday;
       
       double checkout = difftime(mktime(bday), today);
       if(!checkout)
       {
         cout << vec[i].name << " happy birthday!" << endl;
       }

//     // Создаем структуру времени tm для дня рождения следующего года
//     tm * bday_next_tm = localtime(&today);
//     bday_next_tm->tm_mon = vec[i].date.tm_mon - 1; // уменьшаем на 1, так как структура tm считает месяцы от  до 11
//     bday_next_tm->tm_mday = vec[i].date.tm_mday;
//     bday_next_tm->tm_year += 1; // увеличиваем год на 1

//      // Вычисляем разницу в днях между текущей датой и датой дня рождения текущего года
//     time_t diff_bday = difftime(mktime(bday_tm), today) / 86400;
//     // Вычисляем разницу в днях между текущей датой и датой дня рождения следующего года    
//     time_t diff_bday_next = difftime(mktime(bday_next_tm), today) / 86400;

//     // Если день рождения уже был в этом году, то пропускаем информацию о пользователе
//     if(diff_bday )
//     {
//         continue;
//     }

//     // Сравниваем разницу сегодняшней даты и даты дня рождения текущегоода с разницей сегодняшней даты и даты дня рождения следующего года
//     if(diff_bday_next < diff_bday)
//     {
//         bday_tm = bday_next_tm;
//         diff_bday = diff_bday_next;
  
//     }

//      // Если день рождения сегодня, то выводим сообщение об этом на экран
//     if(diff_bday == 0)
//     {
//         cout << vec[i].name << " : Happy Birthday!" << endl;
//     }
//     else // Иначе выводим ближайший день рождения в локальном формате (месяц/день)
//     {
//         cout << vec[i].name << " : ";
//         cout << put_time(bday_tm, "%m/%d") << endl;
//     }
 }

//  time_t a = time(NULL);
//  int n;
//  cin >> n;
//  time_t b = time(NULL);
//  double d = difftime(b, a);
//  cout << d;

return 0;

}


