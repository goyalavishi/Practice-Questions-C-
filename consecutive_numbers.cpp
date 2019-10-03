//Practice More Everyday
#include <string.h>
#include<ctype.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> split_string(string);

void consecutive_numbers(vector<int> q)
{
    sort(q.begin(), q.end());
  
    int count=1,count_temp=1;
    for(int i=0;i<q.size();i++)
    {
        if(i!=q.size()-1)
        {
            if(q[i]==q[i+1])
            {
                continue;
            }
            
            if(q[i]+1==q[i+1])
            {
                count_temp++;
            }
            
            else
            {
                count=std::max(count,count_temp);
                count_temp=1;
            }
        }
        
        else
        {
                count=std::max(count,count_temp);
                count_temp=1;
        }
        
    }
    
    cout<<count<<endl;
}

int main() {    
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);
        char ch=q_temp_temp.at(0);
        
        if(isspace(ch))
            q_temp_temp.replace(0,1,"");
        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        consecutive_numbers(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
