#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include "Classification.hpp"

using namespace std;

  

Classification C1,C2,C3,C4;


void Classification:: Classification_Read_CSV(string st_file,string nd_file,string rd_file,string th_file){
    
    fstream file1(st_file);
    try{
        if(!file1){throw 12;}
        
        vector<double> dim_1 ;
        string item;
        double val1;
        for (string line; getline(file1, line); )
        {
            stringstream l(line);
            while (getline(l, item, ','))
            {
                val1 = atof(item.c_str());
                dim_1.push_back(val1);
                
            }
            
            C1.data.push_back(dim_1);
            dim_1.clear();
            //
        }}catch(int i){cout<<"20 catched...wrong classification file name in first file.."<<endl;}
    cout<<st_file<<" read successfully"<<endl;
    
    
    
    fstream file2(nd_file);
    vector<double> dim_2 ;
    string item2;
    double val2;
    try{
        if(!file2){throw 20;}
        for (string line; getline(file2, line); )
        {
            stringstream l(line);
            while (getline(l, item2, ','))
            {
                val2 = atof(item2.c_str());
                dim_2.push_back(val2);
                
            }
            
            
            C2.data.push_back(dim_2);
            dim_2.clear();
            //
        }}catch(int i){cout<<"20 catched...wrong classification file name in second file.."<<endl;}
    
    
    cout<<nd_file<<" read successfully"<<endl;
    
    
    
    
    fstream file3(rd_file);
    vector<double> dim_3 ;
    string item3;
    double val3;
    try{
        if(!file3){throw 20;}
        for (string line; getline(file3, line); )
        {
            stringstream l(line);
            while (getline(l, item3, ','))
            {
                val3 = atof(item3.c_str());
                dim_3.push_back(val3);
                
            }
            
            
            C3.data.push_back(dim_3);
            dim_3.clear();
            
        }}catch(int i){cout<<"20 catched...wrong classification file name in third file.."<<endl;}
    cout<<rd_file<<" read successfully"<<endl;
    
    
    
    fstream file4(th_file);
    vector<double> dim_4 ;
    string item4;
    double val4;
    try{
        if(!file4){throw 20;}
        for (string line; getline(file4, line); )
        {
            stringstream l(line);
            while (getline(l, item4, ','))
            {
                val4 = atof(item4.c_str());
                dim_4.push_back(val4);
                
            }
            
            
            C4.data.push_back(dim_4);
            dim_4.clear();
            //
        }}catch(int i){cout<<"20 catched...wrong classification file name in fourth file.."<<endl;}
    
    cout<<th_file<<" read successfully"<<endl;
}
/*Check is Learning data match data  number of columns */

bool Classification::Is_Lerngdata_Cols_Match_Data_Cols(){
    if(C1.obj.getNumerOfColumns()==C2.obj.getNumerOfColumns())
    {
        cout<<"==>Learning_data and Data COLUMNs  are matched..."<<endl;
        return true;
        
    }else cout<<"nooooooo.....columns"<<endl;return false;
    
    
}



/*Check is Learning data match learning data labels number of rows*/
bool Classification::Is_Lerng_data_Rows_Match_Lear_Data_Label_Rows(){
    if(C2.obj.getNumberOfRows()==C3.obj.getNumberOfRows())
    {
        cout<<"==>learning_data and Learning Data Labels ROWs  are matched..."<<endl;
        return true;
        
    }else cout<<"nooooooo.....columns"<<endl;return false;
    
}


bool Classification::is_K_larger_Learning_Data(int k){
    
    if(k < C2.data.size()){cout<<"K is not larger than learning data table , Learning Data table size is "<<C2.data.size()<<" rows"<<endl;return true;}
    if(k > C2.data.size()){cout<< "K is larger than Learning Data table rows"<<endl;}
    if(k < 0){cout<< "K is less than 0 "<<endl;}
    else cout<<"K cannot be larger than learning data table"<<endl;return false;
    
}


void Classification::printFiles(){
    
    cout<<"Data table values:"<<endl;
    for( int rows=0; rows<C1.data.size(); rows++) {
        int rows_label=rows;
        cout<<"Row No. "<<rows_label+1;
        
        for(int j=0; j<C1.data[rows].size(); j++) {
            //	cout << data[i][j] <<"|";
            
            cout<<setw(12)<<C1.data[rows][j];
        }
        cout<<endl;
    }
    
    
    cout<<"Learning_Data table values:"<<endl;
    for( int rows=0; rows<C2.data.size(); rows++) {
        int rows_label=rows;
        cout<<"Row No. "<<rows_label+1;
        for(int j=0; j<C2.data[rows].size(); j++) {
            //	cout << data[i][j] <<"|";
            
            cout<<setw(12)<<C2.data[rows][j];
        }
        cout<<endl;
    }
    
    
    cout<<"Learning_Data_Labels table values:"<<endl;
    for( int rows=0; rows<C3.data.size(); rows++) {
        int rows_label=rows;
        cout<<"Row No. "<<rows_label+1;
        
        for(int j=0; j<C3.data[rows].size(); j++) {
            //	cout << data[i][j] <<"|";
            
            cout<<setw(12)<<C3.data[rows][j];
        }
        cout<<endl;
    }
    
    
    cout<<"Corrected_Data_Labels values"<<endl;
    for( int rows=0; rows<C4.data.size(); rows++) {
        int rows_label=rows;
        cout<<"Row No. "<<rows_label+1;
        
        for(int j=0; j<C4.data[rows].size(); j++) {
            //	cout << data[i][j] <<"|";
            
            cout<<setw(12)<<C4.data[rows][j];
        }
        cout<<endl;
    }
    
}



float Classification::Euclidean(int k){
    
    int checkK=k;
    C2.is_K_larger_Learning_Data(checkK);
    
    map<double,unsigned int > my_map;
    map<int, int > myp;
    
    vector<unsigned int> Kvect;
    vector<unsigned int> Kvect2;
    vector<int> data_label;
    //data_label.resize(C4.data.size());
    int i,j;
    //    Classification::is_K_larger_learning_data(k);
    
    for( i=0;i<C1.data.size();i++)
    {
        for(  j=0;j<C2.data.size();j++)
        {
            double temp=0;
            for(int s=0;s<C2.data[0].size();s++)
            {
                temp+=pow((C1.data[i][s] -C2.data[j][s]),2);
            }
            double distance =sqrt(temp);
            //cout<<i<<".."<<j<<endl;
            my_map.insert(pair<double, unsigned int>(distance,j));
        }
        for( map<double,unsigned>::iterator it = my_map.begin(); it != my_map.end(); ++it )
        {
            Kvect.push_back( it->second );
        }
        my_map.clear();
        Kvect.resize(k);//FINDING CLOSEST ROWS IN LEARNING DATA k rows distances rows has been saved here and ready to go to step 2.B
        //sort(Kvect.begin(),Kvect.end());
        for(int i=0;i<Kvect.size();i++){
            int val;
            val=C3.data[Kvect[i]][0];
            Kvect2.push_back(val);
        }
        Kvect.clear();
        ///get matched rows x from learning data label
        for (int h=0; h<Kvect2.size(); h++) {
            int con=0;
            con=(int)count(Kvect2.begin(), Kvect2.end(), Kvect2[h]);
            myp.insert(pair<int, int> (con,Kvect2[h]));
            
        }
        
        Kvect2.clear();
        //getting the highest frequency value
        int max=0;
        max= max_element(myp.begin(), myp.end())->first;
        data_label.push_back(myp[max]);
        
        myp.clear();
    }
    //getting the accuracy
    int acc=0;
    for(int u=0;u<data_label.size();u++){cout<<u<<" :";cout<<data_label[u]<<endl;}
    for(int u=0;u<data_label.size();u++){
        
        if(data_label[u]==C4.data[u][0])
        {acc=acc+1;}
        cout<<data_label[u]<<endl;}
    float accuracy=(acc*100)/C4.data.size();
    //  cout<<"Matched Values=>"<<acc<<"**"<<"Accuracy percentage using EUCLIDEAN formula "<<accuracy<<"%"<<endl;
    cout<<"Accuracy percentage using EUCLIDEAN formula "<<accuracy<<"%"<<endl;
    
    return accuracy;
}

float Classification:: Manhattan(int k){
    
    map<double,unsigned int > my_map;
    map<int, int > myp;
    
    vector<unsigned int> Kvect;
    vector<unsigned int> Kvect2;
    vector<int> data_label;
    //data_label.resize(C4.data.size());
    int i,j;
    //    Classification::is_K_larger_learning_data(k);
    
    for( i=0;i<C1.data.size();i++)
    {
        for(  j=0;j<C2.data.size();j++)
        {
            double temp=0;
            for(int s=0;s<C2.data[0].size();s++)
            {
                temp+=abs((C1.data[i][s] -C2.data[j][s]));
            }
            double distance =temp;
            //cout<<i<<".."<<j<<endl;
            my_map.insert(pair<double, unsigned int>(distance,j));
        }
        for( map<double,unsigned>::iterator it = my_map.begin(); it != my_map.end(); ++it )
        {
            Kvect.push_back( it->second );
        }
        my_map.clear();
        Kvect.resize(k);//FINDING CLOSEST ROWS IN LEARNING DATA k rows distances rows has been saved here and ready to go to step 2.B
        //sort(Kvect.begin(),Kvect.end());
        for(int i=0;i<Kvect.size();i++){
            int val;
            val=C3.data[Kvect[i]][0];
            Kvect2.push_back(val);
        }
        Kvect.clear();
        ///get matched rows x from learning data label
        for (int h=0; h<Kvect2.size(); h++) {
            int con=0;
            con=(int)count(Kvect2.begin(), Kvect2.end(), Kvect2[h]);
            myp.insert(pair<int, int> (con,Kvect2[h]));
            
        }
        
        Kvect2.clear();
        //getting the highest frequency value
        int max=0;
        int temp_max=max;
        
        max= max_element(myp.begin(), myp.end())->first;
        data_label.push_back(myp[max]);
        
        myp.clear();
    }
    //getting the accuracy
    int acc=0;
    for(int u=0;u<data_label.size();u++){cout<<u<<" :";cout<<data_label[u]<<endl;}
    for(int u=0;u<data_label.size();u++){
        
        if(data_label[u]==C4.data[u][0])
        {acc=acc+1;}
        cout<<data_label[u]<<endl;}
    float accuracy=(acc*100)/C4.data.size();
    cout<<"Matched Values=>"<<acc<<"**"<<"Accuracy percentage using MANHATTAN formula "<<accuracy<<"%"<<endl;
    
    return accuracy;
    
}
Classification C;

int (Classification::*pt) (int);





