#include <iostream>

using namespace std;

struct List {
    
    int id; 
    List *next;
    
};

void PushFront (List **begin, const int &item){
    
    List *newitem = new List;
    newitem->id = item;
    
    // if (begin == nullptr){
    //    newitem->next = nullptr;
    //}
    
    newitem->next = *begin;
    *begin = newitem;
    

}

void PushBack (List **begin, const int &item){
    
    List *p = *begin;
    
    List *newitem = new List;
    newitem->id = item;
    newitem->next = nullptr;
    
    while(1){
        
        if (p->next == nullptr){
            p->next = newitem;
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
    
    List *p = *b;
    
    while(p->next != nullptr){
        
        p = p->next;
        
    }
    
    delete p; // почему выводит 0 вместо пустоты
    
}

/*
void DeleteEl( List **b, const int &item ){// не доделал
    
    if (*b == nullptr){
        return;
    }
    
    List *p = *b;
    
    if ( p.id == item){
        
        DeleteFront(&begin);
        return;
    }
    
    while ( p.id != item ){
        
        p = p->next;
        
        if( *p == nullptr){
            return;
        }
        
    }
    
    
}
*/

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
    cout<<"0-выйти из меню;  1-печать списка; 3-вставить элемент в начало (4-в конец)"<<endl;
    cout<<"5-удалить первый элемент (6-последний,7-заданный)"<<endl;
    cout<<"8-удалить весь список"<<endl;
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
             case '8':
                Free(&begin);
                break;
        }

        
    } while (n !='0');
    


    return 0;

}