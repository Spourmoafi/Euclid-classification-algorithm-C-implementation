#include "Table.hpp"
#include "Classification.hpp"
#include <iomanip>
#include <vector>
#include <iomanip>
#include <assert.h>

using namespace std;

int main(){
    
    Table t;
    Classification c;
    
    
    t.setTableData("Data.csv");
    t.print_table();
    t.getAverage_column(13);
    t.getSampleStdDevOfColumn(5);
    t.getNumberOfRows();
    t.getNumerOfColumns();
    t.getCell(2,4);
    t.changeCell(36, 13, 0);
    t.methodStdTable();
    t.print_std_table();
    t.removeRow(5);
    
    t.removeColumn(3);
    
    t.addRow();
    
    t.addColumn();
    cout<<t;
    
    
    c.Classification_Read_CSV("Data.csv", "Learning_Data.csv", "Learning_Data_Labels.csv", "Correct_Data_Labels.csv");
    
    c.printFiles();
    
    c.checkMatches_R_C();
    c.Is_Lerngdata_Cols_Match_Data_Cols();
    c.Is_Lerng_data_Rows_Match_Lear_Data_Label_Rows();
    c.is_K_larger_Learning_Data(177);
    c.Euclidean(141);
    c.Manhattan(1);
    return 0;
}
