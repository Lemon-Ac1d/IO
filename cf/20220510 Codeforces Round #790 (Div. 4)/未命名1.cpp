#include<bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 40;

void getwords(vector<string> &vec){
    ifstream infile("test.txt");
    char str[MAX_SIZE];
    //vec.push_back(" ");
    while(!infile.eof()){
        infile.getline(str,MAX_SIZE);
        vec.push_back(str);
        //vec.push_back("\n");
    }
    vec.pop_back();
}


void exact_search(int opt2,string keywords ,vector<string> &vec ){
    switch (opt2)
    {
    case 1:{
        int start= 0,end,mid,cnt=0;
        vec.resize(end);
        mid = ( start + end )/2;
        for(;start<end;start++){
            cnt++;
            if(vec[mid]==keywords){
                printf("Output: “The search results are: %s (1 occurrence; %d comparisons)”",keywords,cnt);
                break;
            }
            else if (vec[mid]>keywords){
                end=mid-1;
            }
            else   
                start = mid + 1; 
        }
    }break;
    case 2:{
        int start= 0,end,mid,cnt=0,ocur=0;
        vec.resize(end);
        mid = ( start + end )/2;
        for(;start<end;start++){
            cnt++;
            if(vec[mid]==keywords){
                ocur++;
                break;
            }
            else if (vec[mid]>keywords){
                end=mid-1;
            }
            else   
                start = mid + 1; 
        }
        start = mid-1;end=mid + 1;
        while(vec[start]==keywords)start--,cnt++;
        while(vec[end]==keywords)end++,cnt++;
        ocur=start-end-1;
        printf("Output: “The search results are: %s (%d occurrence; %d comparisons)”",keywords,ocur,cnt);
        
    } break;
    default:
        break;
    }
}

void substring_search(int opt2, string keywords,vector<string> &vec){

}

int main(){
    vector<string> vec;
    map<string,int> words;
    getwords(vec);
    sort(vec.begin(),vec.end());
    // for(auto it = vec.begin(); it < vec.end(); ++it){
    //     cout<<*it<<" ";
    // } 
    cout<<endl;
    do{
        string keywords;
        int opt1,opt2;
        cout << "./mygoogle\n" << "Please specify the term:";
        cin>>keywords;
        if(keywords=="Q")break;
        cout << "Please specify the type of search (1: exact search, 2: substring search):";
        cin >> opt1;
        cout << "Please specify the mode of search (1: single occurrence, 2: multiple occurrences):";
        cin >> opt2;

        switch (opt1)
        {
        case 1:exact_search(opt2,keywords,vec);
            break;
        
        case 2:substring_search(opt2,keywords,vec);
        default:
            break;
        }
    }while(1);
    
    
    return 0;
}