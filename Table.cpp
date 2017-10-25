
//  Table.cpp
//  lab
//
//  Created by Sajid on 11/20/16.
//  Copyright © 2016 Sajid. All rights reserved.
//
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
#include "Table.hpp"

using namespace std;
Table t;
void Table:: setTableData(string file_name){
    
    vector<vector<double>> temp_vector;//to hold file data in a 2D vector
    
    fstream file(file_name);
    
    try{
        if(!file){
            throw 1;
        }
        vector<double> dim_ ;
        string item;
        double val;
        for (string line; getline(file, line); )
        {
            stringstream l(line);
            while (getline(l, item, ','))
            {
                val = atof(item.c_str());
                dim_.push_back(val);
                
            }
            
            
            temp_vector.push_back(dim_);
            dim_.clear();
            //
        }
        
        t.table_data=temp_vector;
    }catch(int i){cout<<"Exception No "<<i <<" catched wrong file name.."<<endl;}
}
/*1.Populate the table with the data from a CSV file.*/
void Table:: print_table(){
    try{
        if(t.table_data.size()==0){throw 2;}
        cout<<t.table_data.size()<<" rows printed successfully.."<<endl;
        for( int rows=0; rows<t.table_data.size(); rows++) {
            int rows_label=rows;
            cout<<"Row No. "<<rows_label+1;
            for( int columns=0; columns<t.table_data[rows].size(); columns++) {
                double cell=t.table_data[rows][columns];
                cout<<setw(12)<<cell;
            }
            cout<<endl;
            cout<<endl;
        }
    }catch(int i){cout<<"2 catched.. nofile to print...";}
}
/****************************************/
void Table::print_std_table(){
    try{
        if(t.std_table.size()==0){throw 3;}
        for( int rows=0; rows<t.std_table.size(); rows++) {
            int rows_label=rows;//just to show row index
            cout<<"Row No. "<<rows_label+1<<" ";
            for( int columns=0; columns<t.std_table[rows].size(); columns++) {
                double cell=t.std_table[rows][columns];
                cout<<setw(12)<<cell;
            }
            cout<<endl;
        }
    }catch(int i){cout<<"3 catched..no standardised table to print.."<<endl;}
}
/*2.Get the average of a column specified by the user*/
double Table:: getAverage_column(int column_number){
    
    int coln_number=column_number;coln_number-=1;
    double avg=0.0,total_sum = 0.0;
    try{    if(coln_number<0||coln_number>t.table_data[0].size()){throw 4;}
        for(int i=0; i<t.table_data.size(); i++) {
            total_sum=total_sum +t.table_data[i][coln_number];
        }
        avg=total_sum/t.table_data[0].size();
        t.average_column=avg;
    }catch(int i){cout<<"4 catched .. column number is not valid.."<<endl;}
    return t.average_column;
}


/*3.Get the corrected sample standard deviation of a column specified by the user.*/
double Table:: getSampleStdDevOfColumn(int column_number){
    
    int coln_number=column_number;
    double total_sum=0,avg=0,std=0.0,std1,inverse_n;
    coln_number=column_number-1;
    try{
        if(coln_number<0&&coln_number>t.table_data[0].size()){throw 5;}
        for(int i=0;i<t.table_data.size();i++){total_sum = total_sum + (t.table_data[i][coln_number]);}
        avg=total_sum/t.table_data.size();
        inverse_n = 1.0 / (t.table_data.size()-1);
        for(int i=0;i<t.table_data.size();i++){std1 += pow((t.table_data[i][coln_number])-avg, 2);}
        std=sqrt(inverse_n * std1);
        t.sample_std_dev=std;}catch(int i){cout<<"5 catched.. column number is not valid.."<<endl;}
    return t.sample_std_dev;
}

/*4.Get the number of rows in the table*/
int Table::getNumberOfRows(){
    try{
        t.number_of_rows=t.table_data.size();
        if(t.number_of_rows==0){throw 6;}
    }catch(int i){cout<<"6 catched..no rows available.."<<endl;}
    return t.number_of_rows;
}
/*Get the number of columns in the table.*/
int Table::getNumerOfColumns(){
    int no_columns=0;
    try{
        for (  ;no_columns<t.table_data[0].size();no_columns++){}
        t.number_of_columns=no_columns;
        if(t.number_of_columns==0){throw 7;}
    }
    catch(int i){cout<<"7 catched..no columns available.."<<endl;}
    return t.number_of_columns;
}
/*6.Get the value of a specific cell in the table.*/
double Table:: getCell(int xx,int yy){
    int x=xx,y=yy;
    x=x-1;y=y-1;
    try{
        if(x>t.table_data.size()||y>t.table_data[0].size()){throw 8;}
        t.current_cell=t.table_data[x][y];}catch(int i){cout<<"8 catched..row No. or column No. is not valid.."<<endl;}
    return t.current_cell;
}
/*7.Change the value of a specific cell in the table.*/
void Table:: changeCell(int x_row,int y_col,double new_value){
    int row,col;
    row=x_row-1;
    col=y_col-1;
    try{
        if(row>t.table_data.size()||col>t.table_data[0].size()){throw 9;}
        
        t.table_data[row][col]=new_value;
        
        cout<<endl;
        t.changed_cell=new_value;
        cout<<"Value in "<<"("<<x_row<<","<<y_col<<")"<<" has been changed to ==>"<<t.table_data[row][col]<<endl;
        t.print_table();}catch(int i){cout<<"9 catched..row No. or column No. is not valid.."<<endl;}
    
    
}
/*8.Call a method that standardises the data in the table*/
void Table:: methodStdTable(){
    vector<vector<double>> standardised_vector;
    double sub,standardised_cell;int col=0,row=0;
    standardised_vector.resize(t.table_data.size());
    try{
        if(t.std_table.size()==0){throw 9;}
        for( row=0;row<t.table_data.size();row++)
        {
            for( col=0;col<t.table_data[row].size();col++)
            {
                
                sub=t.table_data[row][col]-t.getAverage_column(col);
                standardised_cell = sub/t.getSampleStdDevOfColumn(col);
                standardised_vector[row].push_back(standardised_cell);
                
            }
            
        }
        
        t.std_table = standardised_vector;
        cout<<"Standardised Data ==> "<<endl;}catch(int i){cout<<"9 catched"<<endl;}
    
}
/*9.Remove a specific row from the table.*/
void Table:: removeRow(int row_num){
    int rowno=row_num;
    rowno-=1;
    try{
        if(rowno<0){throw 10;}
        
        if (rowno < t.table_data.size() )
        {
            t.table_data.erase( t.table_data.begin() + rowno );
        }
        
    }catch(int i ){cout<<"10 catched"<<endl;}
}
/*10.Remove a specific column from the table.*/
void Table:: removeColumn(int col_num){
    int colno=col_num;
    colno=colno-1;
    try{
        if(colno<0){throw 11;}
        if(colno<t.table_data[0].size())
        {
            
            for(int i=0;i<t.table_data.size();i++)
            {t.table_data[i].erase(t.table_data[i].begin() + colno);}
        }
    }catch(int ){cout<<"11 catched"<<endl;}
}
/*11.Add a column containing numbers to the table.*/
void Table:: addRow(){
    
    vector<double> new_row;
    
    for(int i=0;i<t.table_data[0].size();i++){
        new_row.push_back(i);
    }
    
    t.table_data.push_back(new_row);
    
}
/*12.Add a column containing numbers to the table.*/
void Table:: addColumn(){
    // double num;
    vector<double> new_col;
    for(int i=0;i<t.table_data.size();i++){
        new_col.push_back(i);
    }
    for(int col=0;col<t.table_data.size();col++)
    {
        t.table_data[col].push_back(new_col[col]);
    }
    
}
/*13.Add a column containing numbers to the table.*/
ostream  &operator<<(ostream &stream, Table &obj){
    obj.print_table();
    
    return stream;
}
