
#include <Arduino.h>

// ============================================================
// Circular Queue
// ============================================================

#define MAX_QUEUE_SIZE 10

typedef struct
{
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int count;
} Queue;


// ------------------------------------------------------------
// Initialize queue
// ------------------------------------------------------------

void initializeQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}


// ------------------------------------------------------------
// Check if queue is empty
// ------------------------------------------------------------

bool isEmpty(Queue *q)
{
    return q->count == 0;
}


// ------------------------------------------------------------
// Check if queue is full
// ------------------------------------------------------------

bool isFull(Queue *q)
{
    return q->count == MAX_QUEUE_SIZE;
}


// ------------------------------------------------------------
// Add element to rear of queue
// ------------------------------------------------------------

bool enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        Serial.println("Error: Queue is full. Cannot enqueue.");
        return false;
    }

    // Move rear circularly
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;

    q->items[q->rear] = value;
    q->count++;

    Serial.print("Enqueued: ");
    Serial.println(value);

    return true;
}


// ------------------------------------------------------------
// Add element to front of queue
//
// The name "enqueueToOppositeEnd" emphasizes that this
// operation adds an element at the opposite end from enqueue().
// ------------------------------------------------------------

bool enqueueToOppositeEnd(Queue *q, int value)
{
    if (isFull(q))
    {
        Serial.println(
            "Error: Queue is full. Cannot enqueueToOppositeEnd."
        );

        return false;
    }

    // Move front one position backwards circularly
    q->front = (q->front - 1 + MAX_QUEUE_SIZE)
               % MAX_QUEUE_SIZE;

    q->items[q->front] = value;
    q->count++;

    Serial.print("Enqueued to opposite end: ");
    Serial.println(value);

    return true;
}


// ------------------------------------------------------------
// Remove element from front of queue
// ------------------------------------------------------------

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        Serial.println(
            "Error: Queue is empty. Cannot dequeue."
        );

        return -1;
    }

    int item = q->items[q->front];

    // Move front circularly
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;

    q->count--;

    Serial.print("Dequeued: ");
    Serial.println(item);

    return item;
}


// ------------------------------------------------------------
// Get front element without removing it
// ------------------------------------------------------------

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        Serial.println(
            "Error: Queue is empty. Cannot peek."
        );

        return -1;
    }

    return q->items[q->front];
}


// ------------------------------------------------------------
// Destroy / reset queue
// ------------------------------------------------------------

void destroyQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;

    Serial.println("Queue destroyed.");
}


// ============================================================
// Example
// ============================================================

//This function checks if queue is empty
//if not empty it will return the last element and not remove it
int peekRear(Queue *q){
 if (isEmpty(q))
    {
        Serial.println(
            "Error: Queue is empty."
        );

        return -1;
    }

    return q->items[q->rear];
}

void setup()
{
    Serial.begin(9600);
    //initialises my date of birth and the current date
    int temp = 0; //used to hold values temporarily 
    int my_dd = 16;
    int my_mm = 4;
    int my_yyyy = 2002;
    int curr_dd = 15;
    int curr_mm = 10;
    int curr_yyyy = 2026;

    Queue Q1;
    Queue Q2;
    Queue Q3;
//initialises Q1 and orders my birthdate as, day, month, year onto the queue
    initializeQueue(&Q1);
    enqueue(&Q1, my_dd);
    enqueue(&Q1, my_mm);
    enqueue(&Q1, my_yyyy);
    
//initialises Q2 and orders the current date as, day, month, year onto the queue
    initializeQueue(&Q2);
    enqueue(&Q2, curr_dd);
    enqueue(&Q2, curr_mm);
    enqueue(&Q2, curr_yyyy);

//swaps the elements between Q1 and Q2
//removes a value and adds it to the other queue
//repeats 3 times as there are 3 values to swap
    for(int i = 0; i<3; i++){
          temp = dequeue(&Q1);
          enqueue(&Q2, temp);

          temp = dequeue(&Q2);
          enqueue(&Q1, temp);
    }
//stores my birthdate in reverse order
//Q2, which now contains date of birth, is added onto Q3

    initializeQueue(&Q3);
//adds the first element normally, while other elements get added to the front
//each element that was removed gets added back onto Q2 to keep the same values
    for(int i = 0; i<3; i++){
          temp = dequeue(&Q2);
          if(i == 0){
            enqueue(&Q3, temp);
          }else{
            enqueueToOppositeEnd(&Q3, temp);
          }
          enqueue(&Q2, temp);
    }
    //Q1 are displayed in order
    Serial.print("Q1: ");
    for(int i = 0; i<3; i++){
     Serial.print("[");   
     Serial.print(Q1.items[(Q1.front + i)% MAX_QUEUE_SIZE]);
     Serial.print("] ");
    }
    
    Serial.println(); 
    //Q2 are displayed in order
     Serial.print("Q2: ");
    for(int i = 0; i<3; i++){
     Serial.print("[");   
     Serial.print(Q2.items[(Q2.front + i)% MAX_QUEUE_SIZE]);
     Serial.print("] ");
    }
    
    Serial.println(); 
    //Q3 are displayed in order
     Serial.print("Q3: ");
    for(int i = 0; i<3; i++){
     Serial.print("[");   
     Serial.print(Q3.items[(Q3.front + i)% MAX_QUEUE_SIZE]);
     Serial.print("] ");
    }
    
    Serial.println(); 
//This displays only the front element of the each queue and does not remove it
    Serial.print("Q1: Front element = "); 
    Serial.println(peek(&Q1));
    Serial.print("Q2: Front element = "); 
    Serial.println(peek(&Q2));
    Serial.print("Q3: Front element = "); 
    Serial.println(peek(&Q3));
    Serial.println();
//This displays only the rear element of the each queue and does not remove it
    Serial.print("Q1: Rear element = "); 
    Serial.println(peekRear(&Q1));
    Serial.print("Q2: Rear element = "); 
    Serial.println(peekRear(&Q2));
    Serial.print("Q3: Rear element = "); 
    Serial.println(peekRear(&Q3));
//this loop removes all the elements in Q1 
    for(int i = 0; i<3; i++){
        dequeue(&Q1);
    }
 //Checks if Q1 is either empty or not and prints accordingly 
  if(isEmpty(&Q1) == true){
    Serial.println("Queue Q1 is empty.");
  }else{
    Serial.println("Queue Q1 is not empty.");
  }
   //this will calculate the total days between my birthdate and current date
   //which also includes years that may have an extra day(leap year)  
    int totalDays = 0;

    for(int year = my_yyyy; year< curr_yyyy; year++){
         if((year%4 == 0 && year%100!=0)||(year%400 == 0)){
           totalDays = totalDays + 366;
         }else{
            totalDays = totalDays + 365;
         }
    }
 //stores the amount of days in each month in an array 
 
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int totalDaysSub = 0;
    int totalDaysAdd = 0;
//this will loop to count the days before my birthdate in the year i was born
//Subtract one from day because count starts from january 1st
    for(int month = 0; month < my_mm - 1; month++){
          //will check if the year is a leap year or not and
          //change February whether it is a leap year or not
           if((my_yyyy%4 == 0 && my_yyyy% 100 != 0)||(my_yyyy% 400 == 0)){
            daysInMonth[1] = 29;
           }else{
            daysInMonth[1] = 28;
           }
          
           totalDaysSub = totalDaysSub + daysInMonth[month];
    }
    //finds total number of days when i was not born yet
    totalDaysSub = totalDaysSub + (my_dd - 1);
//this will count the days passed in the current year
     for(int month = 0; month < curr_mm - 1; month++){
           //will check if the year is a leap year or not and
          //change February whether it is a leap year or not
           if((curr_yyyy%4 == 0 && curr_yyyy% 100 != 0)||(curr_yyyy% 400 == 0)){
            daysInMonth[1] = 29;
           }else{
            daysInMonth[1] = 28;
           }

           totalDaysAdd = totalDaysAdd + daysInMonth[month];
    }
    //finds the total number of days passed in the current year
       totalDaysAdd = totalDaysAdd + (curr_dd -1);
    //finds the total days between birth date and current date by counting 
    //totalDays minus total days before my birth plus total days passed this year
       int finalTotalDays = totalDays - totalDaysSub+ totalDaysAdd;
       //prints the final result
       Serial.print("Number of days between current date and date of birth is: ");
       Serial.println(finalTotalDays);
}


void loop()
{
    
}

