#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef struct Node* node;

//makenode
node makeNode(int x){
    node tmp = new Node;
    tmp -> data = x;
    tmp -> next = NULL;
    return tmp;
}
//check size list
int Size(node a){
    int cnt = 0;
    while (a != NULL)
    {
        ++cnt;
        a = a -> next;
    }
    return cnt;
}

void insertLast(node &a, int x){
    node tmp = makeNode(x);
    if (a == NULL)
    {
        a = tmp;
    }
    else{
        node p = a;
        while (p -> next != NULL)
        {
            p = p -> next;
        }
        p -> next = tmp;
    }
}

void insertFirst(node &a, int x){
    node tmp = makeNode(x);
    if (a == NULL)
    {
        a = tmp;
    }
    else{
        tmp -> next = a;
        a = tmp;
    }
}

// expand
void insertMiddle(node &a, int x, int pos){
    int n = Size(a);
    if (pos <= 0 || pos > n + 1)
    {
        cout << "Cu phap khong hop le !!! ";
    }
    node p = a;
    for (int i = 0; i < pos -1; i++)
    {
        p = p -> next;
    }
    node tmp = makeNode(x);
    tmp -> next = p -> next;
    p -> next = tmp;
}
// end

int search(node &a, int k){
    int pos = 0;
    for (node p = a; p != NULL; p = p -> next)
    {
        if (p -> data == k)
        {
            return pos + 1;
        }
        ++pos;
    }
    return -1;
}

//expand
void deleteFirst(node &a){
    if (a == NULL)
    {
        return;
    }
    a = a -> next;
}

void deleteLast(node &a){
    if (a == NULL)
    {
        return;
    }
    node truoc = NULL, sau = a;
    while (sau -> next != NULL)
    {
        truoc = sau;
        sau = sau -> next;
    }
    if (truoc == NULL)
    {
        a = NULL;
    }
    else{
        truoc -> next = NULL;
    }
}

//end
void deleteMiddle(node &a, int pos){
    if (pos <= 0 || pos > Size(a))
    {
        return;
    }
    node truoc = NULL, sau = a;
    for (int i = 0; i < pos; i++)
    {
        truoc = sau;
        sau = sau -> next;
    }
    if (truoc == NULL)
    {
        a = NULL;
    }
    else{
        truoc -> next = sau -> next;
    }
}

void reverse(node &a){
    node current = a;
    node prev = NULL, next = NULL;
    while (current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    a = prev;
    
}
//print list
void print(node a){
    while (a != NULL)
    {
        cout << a -> data << " ";
        a = a -> next;
    }
    cout << endl;
}

void destroyNode(node &a){
    int x;
    node p = a;
    while (p != NULL)
    {
        deleteFirst(a);
        p = p -> next;
    }
    a = NULL;
}

//fix bug and test case
//test
void copynode(node a){
    node b = a;
    while (b != NULL)
    {
        cout << b -> data << " ";
        b = b -> next;
    }
    cout << endl;
}

void copy(node a, int x){
    node tmp = makeNode(x);
    // node p = a;
    while (a != NULL)
    {
        tmp->data = a->data;
        cout << tmp->data << " ";
        a = a -> next;
    }
    cout << endl;
}


int main(){
    node head = NULL;
    while(1){
		cout << "-----------------MENU---------------\n";
		cout << "1. Chen phan tu vao dau danh sach\n";
		cout << "2. Chen phan tu vao cuoi danh sach\n";
		cout << "3. Chen phan tu vao bat ky vi tri nao trong danh sach\n";
		cout << "4. Tim kiem trong danh sach\n";
		cout << "5. Xoa phan tu o dau\n";
		cout << "6. Xoa phan tu o cuoi\n";
		cout << "7. Xoa phan tu o vi tri bat ki trong danh sach\n";
		cout << "8. In danh sach lien ket\n";
		cout << "9. Dao danh sach lien ket\n";
		cout << "10. Copy danh sach lien ket\n";
		cout << "11. Xoa danh sach lien ket\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
		int lc; cin >> lc;

        if(lc == 1){
			int x; 
            cout << "Nhap gia tri can chen: "; 
            cin >> x;
			insertFirst(head, x);
		}
		else if(lc == 2){
			int x; 
            cout << "Nhap gia tri can chen: "; 
            cin >> x;
			insertLast(head, x);
		}
        else if (lc == 3)
        {
            int x;
            cout << "Nhap gia tri can chen: ";
            cin >> x;
            int pos;
            cout << "Nhap vi tri can chen: ";
            cin >> pos;
            insertMiddle(head,x,pos);
        }
        
		else if (lc == 4)
        {
            int k;
            cout << "Nhap gia tri can tim ";
            cin >> k;
			cout << "Gia tri can tim o vi tri thu: " << search(head,k);
            cout << endl;
		}
        else if (lc == 5)
        {
            deleteFirst(head);
        }
        else if (lc == 6)
        {
            deleteLast(head);
        }
        else if (lc == 7)
        {
            int pos;
            cout << "Nhap vi tri can xoa: ";
            cin >> pos;
            deleteMiddle(head,pos);
        }
        else if (lc == 8)
        {
            print(head);
        }
        else if (lc == 9)
        {
            reverse(head);
        }
        else if (lc == 10)
        {
            int x;
            // copynode(head);
            copy(head,x);
        }
        else if (lc == 11)
        {
            destroyNode(head);
        }

        
        
    }
    
    return 0;
}