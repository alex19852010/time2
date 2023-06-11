#include<iostream>
#include<string>
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
  vector <Data> vec2; // в этом векторе хранится люди у которых небыло еще дня рождения в этом году
  int count = 0; // переменная подсчитывает количество человек у которых сегодня день рождения

while(1)
{

count = 0;
vec.clear();
vec2.clear();

  
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
    cout <<"dates of birth: " << vec[i].name << " ";  // выводим всех людей(их имена и даты рождения)
    cout << put_time(&vec[i].date, "%Y-%m-%d") << endl;
    
}

      time_t today = time(NULL);
      tm * now_time = localtime(&today);
      cout << "today: "<< put_time(now_time, "%Y-%m-%d") << endl; // выводим сегодняшнюю дату

for(int i = 0; i < vec.size(); i ++)
{

       tm * bday = localtime(&today);
       bday->tm_mon = vec[i].date.tm_mon;
       bday->tm_mday = vec[i].date.tm_mday;
       
       double checkout = difftime(mktime(bday), today);
       if(!checkout)
        {
         cout << vec[i].name << " happy birthday!" << " "; 
         cout << put_time(&vec[i].date, "%Y-%m-%d") << endl; // выводим имя и дату друга у которого сегодня день рождения
         count ++;
        }

        if(checkout > 0)
         {
         
            vec2.push_back(vec[i]);
            
         }
      
 }

  if (count)
      {
        continue; 
      }

       tm * nday = localtime(&today);
       nday->tm_mon = vec[0].date.tm_mon;
       nday->tm_mday = vec[0].date.tm_mday;      
       double check = difftime(mktime(nday), today) ; 
  
      double min = check; // с помощью этой переменной вычисляем ближайший день рождения
  for(int i = 0; i < vec2.size(); i ++)
  {
       tm * nday = localtime(&today);
       nday->tm_mon = vec[i].date.tm_mon;
       nday->tm_mday = vec[i].date.tm_mday;
       
        check = difftime(mktime(nday), today);

        if(min > check)
        {
          min = check;
        }
      
      
  }
  
   for(int i = 0; i < vec2.size(); i ++)
  {
       tm * nday = localtime(&today);
       nday->tm_mon = vec[i].date.tm_mon;
       nday->tm_mday = vec[i].date.tm_mday;
       
        check = difftime(mktime(nday), today);

        if(min == check)
        {
          cout << "next birthday: " << vec[2].name << " ";
          cout << put_time(&vec2[i].date, "%Y-%m-%d") << endl;
          
        }
      
      
  }
   
}

return 0;

}


