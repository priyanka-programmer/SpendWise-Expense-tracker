#include <iostream>
#include <fstream>
using namespace std;

float budget = 0;

class Expense
{
public:
    string date;
    string category;
    string description;
    float amount;

    void addExpense()
    {
        ofstream file("expenses.txt", ios::app);

        cout<<"Enter Date (dd/mm/yyyy): ";
        cin>>date;

        cout<<"Enter Category (Food/Travel/Shopping/Education): ";
        cin>>category;

        cout<<"Enter Amount: ";
        cin>>amount;

        cout<<"Enter Description: ";
        cin>>description;

        file<<date<<" "<<category<<" "<<amount<<" "<<description<<endl;

        file.close();

        cout<<"Expense Added Successfully\n";
    }
};

void viewExpenses()
{
    ifstream file("expenses.txt");

    string date,category,description;
    float amount;

    cout<<"\n------ EXPENSE LIST ------\n";

    while(file>>date>>category>>amount>>description)
    {
        cout<<"Date: "<<date<<endl;
        cout<<"Category: "<<category<<endl;
        cout<<"Amount: "<<amount<<endl;
        cout<<"Description: "<<description<<endl;
        cout<<"-------------------------\n";
    }

    file.close();
}

void searchExpense()
{
    string searchCategory;

    cout<<"Enter category to search: ";
    cin>>searchCategory;

    ifstream file("expenses.txt");

    string date,category,description;
    float amount;

    cout<<"\nResults:\n";

    while(file>>date>>category>>amount>>description)
    {
        if(category == searchCategory)
        {
            cout<<date<<" "<<category<<" "<<amount<<" "<<description<<endl;
        }
    }

    file.close();
}

void monthlyReport()
{
    ifstream file("expenses.txt");

    string date,category,description;
    float amount;

    float total=0;

    while(file>>date>>category>>amount>>description)
    {
        total += amount;
    }

    cout<<"\nTotal Expenses: "<<total<<endl;

    if(budget > 0 && total > budget)
    {
        cout<<"⚠ Warning: Budget exceeded!\n";
    }

    file.close();
}

void setBudget()
{
    cout<<"Enter Monthly Budget: ";
    cin>>budget;

    cout<<"Budget Set Successfully\n";
}

int main()
{
    int choice;
    Expense e;

    while(true)
    {
        cout<<"\n===== SPENDWISE EXPENSE TRACKER =====\n";
        cout<<"1 Add Expense\n";
        cout<<"2 View Expenses\n";
        cout<<"3 Search Expense by Category\n";
        cout<<"4 Monthly Report\n";
        cout<<"5 Set Budget\n";
        cout<<"6 Exit\n";

        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                e.addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                searchExpense();
                break;

            case 4:
                monthlyReport();
                break;

            case 5:
                setBudget();
                break;

            case 6:
                exit(0);

            default:
                cout<<"Invalid Choice\n";
        }
    }

    return 0;
}