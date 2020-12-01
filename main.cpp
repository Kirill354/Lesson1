#include <iostream>

using namespace std;

struct List {
    
    int id; 
    List *next;
    
};

void PushFront (List **begin, const int &item){
    
    List *newitem = new List;
    newitem->id = item;
    newitem->next = *begin;
    *begin = newitem;
    

}

void PushBack (List **begin, const int &item){
    
    if (*begin == nullptr){
        
        List *newitem1 = new List;
        newitem1->id = item;
        newitem1->next = *begin;
        *begin = newitem1;
        
        return;
    }
    
    List *p = *begin;
    
    List *newitem = new List;
    newitem->id = item;
    newitem->next = nullptr;

    
    while(1){
        
        if (p->next == nullptr){
            p->next = newitem;
            newitem->id = item;
            newitem->next = nullptr;
            break;
        }
        
        p = p->next;
    }
    
    
}

void DeleteFront (List **b){
    
    if (*b == nullptr){
        return;
    }
    
    List *p = *b;
    
    *b = p->next;
    
    delete p;
    
}

void DeleteBack (List **b){
    
    if (*b == nullptr){
        return;
    }

    if ((*b)->next == nullptr){
        DeleteFront(b);
        return;
    }
    
    List *p = *b;
    List *temp;
    
    while(p->next != nullptr){
        
        temp = p;
        p = p->next;
        
    }
    
    delete p;
    temp->next = nullptr;
    
}

void DeleteZad( List **b, const int &item ){


    if (item == 1){
        DeleteFront(b);
        return;
    }
    
    if (*b == nullptr){
        return;
    }
    
    if ((*b)->next == nullptr){
    
        List *p = *b;
        *b = p->next;
        delete p;
        
        return;
    }

    List *temp0 = *b;
    List *temp = *b;
    List *temp1 = *b;

    for (int i = 0; i<item-1; i++){
        
        temp1 = temp;
        temp  = temp->next;
    
    }
    
    temp1->next = temp->next;
    *b = temp0;
    delete temp;

}

void PrintSize(List *b){
    int size = 0;
    List *p = b;
    while (p != nullptr){
        size++;
        p = p->next;
    }
    
    cout<<"размер списка = "<<size<<endl<<endl;
}

void Print(List *b){
    List *temp = b;
    while (temp != nullptr){
        cout<<temp->id<<" ";
        temp = temp->next;
    }
}

void Free(List **b){
    
    if (*b == nullptr){
        return;
    }
    
    List *p = *b;
    List *t;
    
    while ( p != nullptr){
        
        t = p;
        p = p->next;
        delete t;
        
    }
    
    *b = nullptr;
    
}

void menu(){
    
    cout<<"Какое действие вы хотите сделать?"<<endl;
    cout<<"0-выйти из меню"<<endl;
    cout<<"1-печать списка"<<endl;
    cout<<"3-вставить элемент в начало"<<endl;
    cout<<"4-вставить элемент в конец"<<endl;
    cout<<"5-удалить первый элемент"<<endl;
    cout<<"6-удалить последний элемент"<<endl;
    cout<<"7-удалить заданный элемент"<<endl;
    cout<<"8-удалить весь список"<<endl;
    cout<<"9-узнать размер списка"<<endl;
    cout<<endl;

}

int main()
{
    setlocale(LC_ALL, "Russian"); 
    
    List *begin = nullptr;
    
    char n;
    
    do{
        menu();
       
        cin>>n;
        
        switch(n){
            case '0':
                break;
            case '1':
                cout<<"Ваш список: ";
                Print(begin);
                cout<<'\n';
                break;
            case '3':
                cout<<"Введите элемент: ";
                int k; cin>>k;
                PushFront(&begin, k);
                break;
            case '4':
                cout<<"Введите элемент: ";
                int q; cin>>q;
                PushBack(&begin,q);
                break;
            case '5':
                DeleteFront(&begin);
                break;
            case '6':
                DeleteBack(&begin);
                break;
            case '7':
                cout<<"Введите элемент: ";
                int p; cin>>p;
                DeleteZad(&begin, p);
                break;
            case '8':
                Free(&begin);
                break;
            case '9':
                PrintSize(begin);
                break;
        }

        
    } while (n !='0');

    return 0;

}