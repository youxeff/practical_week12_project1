#include <iostream>
#include "colors.h"
#include "TextTable.h"

using namespace std;


struct candidate{

     string name;
     float AmountOfVotes ;
     float percentage;
};

candidate insertData() {
    candidate can1;

    cout << " Enter Candidate name" << "\n";
    cin >> can1.name;
    cout << " Enter amount of votes" << "\n";
    cin >> can1.AmountOfVotes;


    return can1;
}


void DisplayCandidate(const candidate(&can1), TextTable &table);

void DisplayCandidate(const candidate &can1, TextTable &table) {

    table.add(can1.name);
    table.add(to_string(can1.AmountOfVotes));
    table.add(to_string(can1.percentage));
    table.endOfRow();
}


int main() {

    float total=0;
    vector<candidate> candlist;

    for (int i = 0; i < 2; ++i) {
        candidate emp = insertData();
        candlist.push_back(emp);
        for (int k=0;k<2;++k){
            cin>>candlist[k].AmountOfVotes;
            total = total + candlist[k].AmountOfVotes;
        }
        emp.percentage = (candlist[i].AmountOfVotes*100 )/ total;
        candlist.push_back(emp);
        emp={};
    }


    TextTable headerTable('-', '|', '+');
    headerTable.add("voting details ");
    headerTable.endOfRow();
    headerTable.setAlignment(2, TextTable::Alignment::RIGHT);
    cout << headerTable;

    TextTable table('*', '|', '+');
    table.add("  cand name  ");
    table.add("  cand vote no  ");
    table.add("  Percentage  ");
    table.endOfRow();

    for (const candidate &emp: candlist ) {
        DisplayCandidate(emp, table);
    }

    table.setAlignment(0, TextTable::Alignment::RIGHT);
    cout << table;
    return 0;
}
