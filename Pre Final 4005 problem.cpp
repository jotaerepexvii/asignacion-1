#include <iostream>

using namespace std;

struct node
{
    int data;
    node *link;
};

class linked_list
{
  private:
    node *head; //se crea el pointer head de la lista encadenada

  public:
    void insert_node()     //crea un nuevo nodo y a su vez los organiza ascendentemente
    {
        int n;
        cin>>n;
        node *tmp = new node;   //se crea un pointer de tipo node llamado tmp y a este se le asigna que apunte a un nuevo nodo
        tmp->data = n;          //tmp apunta a la parte de data del nodo creado en la linea anterior y se le asigna n (valor insertado por el usuario)
        tmp->link = NULL;       //tmp apunta a la parte del link del nodo y le asigna un valor NULL

        if (head == NULL || head->data > n) //compara si head es null o si la data a la que apunta head es mayor que el numero insertado //head nunca sera igual a null?
        {
            tmp->link = head;
            head = tmp;
        }
            else
            {
            node *current = head; //se crea pointer current de tipo node al cual se le asigna la direccion que tiene head guardada. Asi nos ubicamos en la lista
            node *next = current->link; //se crea pointer next de tipo node al cual se le asigna el link de lo que current esta apuntando.
            while(current->link != NULL && current->link->data < n) //mientras el link al que apunta current no sea null y el dato insertado (n) sea mayor
            {                                                       //a la data guardada en el nodo que esta despues del que esta apuntando current entonces...
                current = current->link;    
            }
            tmp->link = current->link;
            current->link = tmp;
            }

    }


    void count(int q)  //cuenta el numero de veces que se repiten los valores insertados por el usuario
    {
        node *crrt = head;
        //node *temp = new node;
       // node *temp = head;

        int wdt=2, cnt=0; //largoArr sera la cantidad de nodos (datos), num sera el numero que esta en cada nodo
        //cout<<"Array size: "<<q<<" x "<<wdt<<endl;
        int arr[q][wdt];

        for(int k=0;k<q;k++) //guarda valores de la lista encadenada en un array
        {
        arr[k][0]=crrt->data;

            if (crrt->data==crrt->link->data) //quiero lograr com
                {
                cnt++;
                arr[k][1]=cnt;
                
                crrt=crrt->link->data;  //quiero lograr apuntar el pointer al siguiente nodo

                }
                else
                {
                crrt=crrt->link->data;
                }
                crrt=crrt;
        }

        cout<<"Lista y repeticiones de cada numero"<<endl;

        for (int prt=0; prt<q; prt++)
        {
            cout<<arr[prt][0]<<" "<<arr[prt][1];
        }

    }


    void print_list()   //imprime la lista encadenada
    {
        node *current = head;
        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->link;
        }
    }

};


int main()
{
    linked_list list;
    int j,val;
    cout<<"Cuantos valores desea guardar en la lista? ";
    cin>>j;

    for(int k=0;k<j;k++)
    {
        cout<<"Inserte un valor al nodo ";
        list.insert_node();
    }

    list.count(j);

    return 0;
}