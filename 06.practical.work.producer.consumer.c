#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct
{
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

int main(){
int first,last;
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

produce(potatoe);
printf("French fries well done!\n");

item *eat=consume();
printf("Delivered chicken == %c\n",eat->type);


return 0;
}

