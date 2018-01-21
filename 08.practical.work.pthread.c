#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 10


typedef struct{
    char type;
    // 0=fried chicken, 1=French fries
    int amount;
    // pieces or weight
    char unit;
    // 0=piece, 1=gram
    } item;

    item buffer[BUFFER_SIZE];
    int first = 0;
    int last = 0;

    void produce(item *i) {
    while
    ((first + 1) % BUFFER_SIZE == last) {
    // do nothing -- no free buffer item
    }
    memcpy(&buffer[first], i,sizeof(item));
    first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
    item *i = malloc(sizeof(item));
    while
    (first == last) {
    // do nothing -- nothing to consume
    }
    memcpy(i, &buffer[last],
    sizeof
    (item));
    last = (last + 1) % BUFFER_SIZE;
    return
    i;
}

int pthread_create(
    pthread_t *thread,// returns the thread identifier
    const pthread_attr_t *attr,// thread attributes
    void *(*start_routine) (void *),// thread function
    void *arg);// argument to thread function

void *threadFunction1(void *param) {
   item *pizza=(item*)malloc(sizeof(item));
   item *coke=(item*)malloc(sizeof(item));
   item *salad=(item*)malloc(sizeof(item));

   pizza->type='2';
   pizza->amount=1;
   pizza->unit='0';

   produce(pizza);
   printf("Pizza done!\n");
   printf("first = %d , last = %d\n\n",first,last);

   coke->type='3';
   coke->amount=180;
   coke->unit='1';
   produce(coke);
   printf("Coke done!\n");
   printf("first = %d , last = %d\n\n",first,last);
   
   salad->type='4';
   salad->amount=50;
   salad->unit='1';
   produce(salad);
   printf("Salad done!\n");
   printf("first = %d , last = %d\n\n",first,last);



}

void *threadFunction2(void *param) {
   item *eat1 = consume();
   printf("Eat pizza == %c\n",eat1->type);
   printf("first = %d , last = %d\n\n",first,last);
   item *drink = consume();
   printf("Drink coke == %c\n",drink->type);
   printf("first = %d , last = %d\n\n",first,last);
   
}


int main(){

    // create a background thread to execute threadFunction
    pthread_t tid,tid2;
    pthread_create(
    &tid,// get thread id
    NULL,// skip the attributes
    threadFunction1,// thread function name
    NULL);// argument to thread function

    pthread_create(
    &tid2,// get thread id
    NULL,// skip the attributes
    threadFunction2,// thread function name
    NULL);// argument to thread function

    // main thread execution continues here

    item *chicken=(item*)malloc(sizeof(item));
    item *potatoe=(item*)malloc(sizeof(item));
    chicken->type='0';
    chicken->amount=2;
    chicken->unit='0';

    potatoe->type='1';
    potatoe->amount=100;
    potatoe->unit='1';

    produce(chicken);
    printf("Spicy chickens well done!\n");
    printf("first = %d , last = %d\n\n",first,last);


    produce(potatoe);
    printf("French fries well done!\n");
    printf("first = %d , last = %d\n\n",first,last);

    item *eat=consume();
    printf("Delivered chicken == %c\n",eat->type);
    printf("first = %d , last = %d\n\n",first,last);

    pthread_join(tid,NULL);
    pthread_join(tid2,NULL);

    return 0;
}

