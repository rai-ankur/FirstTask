#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

vector<int> factor(int number)
{
    vector<int> factor_store;
    for (int i=1; i<number; i++)
    {
        if (number%i == 0)
        {
            factor_store.push_back(i);
        }
    }
    return factor_store;
}


double score_count(int cnt)
{
    double val = 2*pow(cnt,1.34);
    if(val>100)
    val=100;
    return val;
}


class Hint
{
        int actual_number,user_number;
        vector<int> arr;
        int index,len;
        public:
                Hint(int actual_number,int user_number,vector<int> given,int cnt)
                {
                    this->user_number=user_number;
                    this->actual_number=actual_number;
                    arr=given; 
                    len = given.size();  
                    index = cnt;
                }
                int lcm();
                int hcf();
                int multiple();
                void campare();

};


int Hint::lcm()
{
        int gcd_value = gcd(actual_number,user_number);
        return (actual_number*user_number)/gcd_value;
}

int Hint:: hcf()
{
    int gcd_value = gcd(actual_number,user_number);
    return gcd_value;
}


int Hint:: multiple()
{
    if(len == 0 && index==0 && actual_number!=1)
    return 0;

    if(len<=index)
    return 1;
    return arr[index];
}


void Hint::campare()
{
          int diff = abs(actual_number-user_number);
          if(actual_number > user_number) 
          {
            if(diff > 2*user_number)
            {
                cout<<"The actual number is greater than twice of your previous guess number\n";
            }else{
                cout<<"The actual number is greater than your previous guess number\n";
            }
          }else{
            if(diff > 2*user_number)
            {
                cout<<"The actual number is lesser than twice of your previous guess number\n";
            }else{
                cout<<"The actual number is lesser than your previous guess number\n";
            }
          }
}
int main()
{
    srand(time(0));
    int actual_number = rand()%100+1;
    int user_number=0;
    bool quit = false;
    int index_cnt = 0,score_cnt=0;
    vector<int> factor_store = factor(actual_number);
    do{
        cout<<"guess the number between 1 to 100"<<endl;
        cin>>user_number;
        if(user_number<1 || user_number>100){
        cout<<"it is not a valid number!"<<endl;
        score_cnt = 34;
        break;
        }
        else if(user_number == actual_number)
        {
            cout<<"congratulations , you got right number that is"<<" "<<actual_number<<endl;
        }else{
                cout<<"This is not right guess"<<endl;
                cout<<"if you want hint then press 1 else you press 2 for quit"<<endl;
                int flag;
                cin>>flag;
                if(flag==2)
                {
                    cout<<"you have decided to quit!"<<endl;
                    cout<<"Actual answer is :"<<actual_number<<endl;
                    quit=true;
                    break;
                }
            Hint *obj = new Hint(actual_number,user_number,factor_store,index_cnt);
                int var = rand()%3;
                switch (var)
                {
                case 0:
                {
                    int lcm_val = obj->lcm();
                    cout<<"the lowest common multiple of actual number and your previous enter number is :"<<lcm_val<<endl;
                    break;
                }
                case 1:
                {
                    int hcf_val = obj->hcf();
                    cout<<"the highest common factor of actual number and your previous enter number is :"<<hcf_val<<endl;
                    break;
                }
                case 2:
                {
                    int ans = obj->multiple();
                    if(ans == 0){
                    cout<<"actual_number is a prime number"<<endl;
                    index_cnt++;
                    break;
                    }
                    if(ans!=1)
                    {
                        cout<<"actual number is a multiple of "<<ans<<endl;
                        index_cnt++;
                        break;
                    }
                }
                default:
                    obj->campare();
                    break;
                }
                delete obj;
                score_cnt++;
        }
    }while(actual_number!=user_number);
    double final_score = score_count(score_cnt);
    if(quit)
    cout<<"Your final score is Zero , Try next time!"<<endl;
    else{
        cout<<"Your final score is : "<<100 - final_score<<endl;
    }

    return 0;
}