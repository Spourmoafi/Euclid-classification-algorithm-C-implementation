
#ifndef Table_hpp
#define Table_hpp
#include <fstream>
//
//  Table.hpp
//  lab
//
//  Created by Sajid on 11/20/16.
//  Copyright © 2016 Sajid. All rights reserved.
//
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

class Table{
protected:
    vector<vector<double>> table_data,std_table;//Represent The main vector in the class
    double average_column,sample_std_dev,number_of_rows,number_of_columns,current_cell,changed_cell;
public:
    // vector<vector<double>> MainMain;
    void setTableData(string file_name);
    void print_table();//1.Populate the table with the data from a CSV file.
    void print_std_table();//1.Populate the table with the data from a CSV file.
    
    double getAverage_column(int column_number);//2.Get the average of a column specified by the user
    double getSampleStdDevOfColumn(int column_number);//3.Get the corrected sample standard deviation of a column specified by the user.
    int getNumberOfRows();//4.Get the number of rows in the table
    int getNumerOfColumns();//5.Get the number of columns in the table.
    double getCell(int x,int y) ;//6.Get the value of a specific cell in the table.
    void changeCell(int x_row,int y_col,double new_value);//7.Change the value of a specific cell in the table.
    void methodStdTable();            //8.Call a method that standardises the data in the table
    void removeRow(int row_num);//9.Remove a specific row from the table.
    void removeColumn(int col_num);//10.Remove a specific column from the table.
    void addRow();//11.Add a column containing numbers to the table.
    void addColumn();//12.Add a column containing numbers to the table.
    friend ostream &operator<<(ostream &stream, Table &obj);//13.Add a column containing numbers to the table
    
};
#endif
