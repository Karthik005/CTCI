#include<vector>
#include<stdexcept>
#include<iostream>
using namespace std;
typedef signed short int sint;

class CircQueue{

    private:
    int *queue, front, rear, size;
    
    public:

    CircQueue(int size_){
        front = rear = -1;
        queue = new int [size_];
        size = size_;
    }

    ~CircQueue(){
        delete queue;
    }

    void enqueue(int val){
        
        rear = (rear+1)%size;

        cout << "Rear, Val" << rear <<" " << val<< endl;
        if (front == rear){
            cout << "Queue Overflow" << endl;
                return;
        }
        
        if (front == -1){
            front = 0; 
            rear = 0;
        }
        cout<<"Here"<<endl;
        queue[rear] = val;
    }

    int dequeue(){
        if (front == -1){
            cerr << "Queue Underflow" << endl;
            return -1;
        }

        int val = queue[front];
        if ( (front = (front +1) % size)  == rear){
            front = rear = -1;
        }
        return val; 
    }

    void print_queue(){
        cout<<front<<"  "<<rear<<endl;
        int i = front;
        for (; i != rear; i = (i+1)%size){
            cout << queue[i] << endl;
        }
        cout << queue[i]<<endl;
    }
};

// class NWCircQueue : public CircQueue {
    
//     public:
//         NWCircQueue(int i){
            
//         }
// };

int main(int argc, char* argv[]){
    CircQueue que(10);
    // CircQueue* qwe = new NWCircQueue(19);
    for (int i=0; i<10; ++i){
        que.enqueue(i);
    }
    for (int i = 0; i<5 ; i++){
        que.dequeue();
    }
    que.print_queue();
    for (int i = 0; i < 5; i++)
    {
        que.enqueue(i);
    }
    que.print_queue();
}