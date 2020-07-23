#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
    int member_id;
    string name;
    string gender;
    int age;
    
    struct node *next;
}*start;
 
/*
 * Class Declaration
 */
class single_llist
{
    public:
        node* create_node(int,string,string,int);
        void insert_begin();
        void insert_pos();
        void insert_last(); 
        void delete_pos();
        void sort();
        void search();
        void update();
        void reverse();
        void display();
        single_llist() 
        {
            start = NULL;
        }
};
 
/*
 * Main :contains menu 
 */
   int j=0;
main()
{
    int choice, nodes, element, position, i;
  
    single_llist sl;
    start = NULL;
    while (1)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"HOME MANAGEMENT"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        
        cout<<"1.JOINING A MEMBER"<<endl;
        cout<<"2.ADOPTED"<<endl;
        cout<<"3.UPDATE MEMBER DETAIL"<<endl;
        cout<<"4.SEARCH FOR A MEMBER"<<endl;
        cout<<"5.DISPLAY MEMBERS"<<endl;
        cout<<"6.REVERSE DISPLAY "<<endl;
        cout<<"7.EXIT "<<endl;
           cout<<endl<<"---------------------------------"<<endl;
        cout<<"ENTER YOUR CHOICE : ";
        cin>>choice;
        switch(choice)
        {
        
        case 1:
            cout<<"1.JOINING A MEMBER "<<endl;
            sl.insert_last();
            cout<<endl;
            break;
        
        
        case 2:
            cout<<"2.ADOPTED "<<endl;
            sl.delete_pos();
            break;
        case 3:
            cout<<"3.UPDATE A MEMBER DETAIL"<<endl;  
            sl.update();
            cout<<endl;
            break;
        case 4:
            cout<<"4.SEARCH FOR A MEMBER "<<endl;
            sl.search();
            cout<<endl;
            break;
        case 5:
            cout<<"5.DISPLAY MEMBERS"<<endl;
            sl.display();
            cout<<endl;
            break;
        case 6:
            cout<<"6.REVERSE DISPLAY"<<endl;
            sl.reverse();
            cout<<endl;
            break;
        case 7:
            cout<<"7.EXIT"<<endl;
            exit(1);
            break;  
        default:
            cout<<"WRONG CHOICE"<<endl;
        }
    }
}
 
/*
 * Creating Node
 */
node *single_llist::create_node(int value,string name,string gender,int age)
{
    struct node *temp, *s;
    temp = new(struct node); 
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->member_id = value;
        temp->name=name;
        temp->age=age;
        temp->gender=gender;
        temp->next = NULL;     
        return temp;
    }
}
 
/*
 * Inserting element in beginning
 */


void single_llist::insert_last()
{
	j++;
    int value=j;
    string name,gender;
    int age;
    cout<<"ENTER NAME,GENDER(M/F/O),AGE OF THE MEMBER JOINING"<<endl;
    cin>>name>>gender>>age;

    struct node *temp, *s;
    temp = create_node(value,name,gender,age);
    if(start==NULL)
    {
	
      start=temp;
      start->next=NULL;
  }
      else
      {
	  
    s = start;
    while (s->next != NULL)
    {         
        s = s->next;        
    }
    temp->next = NULL;
    s->next = temp;
 
}
}
 
/*
 * Insertion of node at a given position
 */


/*
 * Delete element at a given position
 */
void single_llist::delete_pos()
{
    int pos, i, counter = 0;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"ENTER THE MEMBER ID OF THE ADOPTED MEMBER";
    cin>>pos;
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;  
        }
        if (pos > 0 && pos <= counter)
        {
            s = start;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            cout<<"MEMBER ID NOT FOUND"<<endl;
        }
        free(s);
        cout<<"RECORD DELETED "<<endl;
    }
}
 
/*
 * Update a given Node
 */
void single_llist::update()
{
    int value, pos, i,age;
    string name,gender;
    if (start == NULL)
    {
        cout<<"EMPTY RECORDS"<<endl;
        return;
    }
    cout<<"ENTER THE MEMBER ID TO GET UPDATED ";
    cin>>pos;
    cout<<"ENTER THE NAME,GENDER(M/F/O),AGE: ";
    cin>>name>>gender,age;
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start->name = name;
		start->gender=gender;
	
		start->age=age; 
    }
    else
    {
        for (i = 0;i < pos - 1;i++)
        {
            if (s == NULL)
            {
                cout<<"THERE IS NO RECORD FOR MEMBER ID:"<<pos;
                return;
            }
            s = s->next;
        }
        s->member_id = value;  
    }
    cout<<"MEMBER DETAIL UPDATED"<<endl;
} 
 
/*
 * Searching an element
 */
void single_llist::search()
{
    int value, pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        cout<<"EMPTY RECORDS"<<endl;
        return;
    }
    cout<<"ENTER THE MEMBER ID TO BE SEARCHED: ";
    cin>>value;
    struct node *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->member_id == value)
        {
            flag = true;
            cout<<"MEMBER ID:"<<s->member_id<<endl;
           cout<<"NAME:"<<s->name<<endl;
           cout<<"AGE:"<<s->age<<endl;
           cout<<"GENDER:"<<s->gender<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"MEMBER ID:"<<value<<"NOT FOUND"<<endl;  
}
 
/*
 * Reverse Link List
 */
void single_llist::reverse()
{
    struct node *ptr1, *ptr2, *ptr3;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    if (start->next == NULL)
    {
        return;
    }  
    ptr1 = start;
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;         
    }
    start = ptr2;
}
 
/*
 * Display Elements of a link list
 */
void single_llist::display()
{
    struct node *temp;
    if (start == NULL)
    {
        cout<<"EMPTY RECORDS"<<endl;
        return;
    }
    temp = start;
    cout<<"DETAILS OF THE HOME ARE "<<endl;
     cout<<endl<<"---------------------------------"<<endl;
     cout<<"MEMBER ID"<<" "<<"NAME"<<"  "<<"AGE"<<" "<<"GENDER"<<endl;
    while (temp != NULL)
    {
        cout<<temp->member_id<<"      "<<temp->name<<"     "<<temp->age<<"      "<<temp->gender;
        cout<<endl;
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

