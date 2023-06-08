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
    
   cout << put_time(&vec[i].date, "%Y/%m/%d") << endl;

}




return 0;

}


