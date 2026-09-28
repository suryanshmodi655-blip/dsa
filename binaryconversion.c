#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

struct stack
{
    int top;
};

int data[SIZE];
typedef struct stack STACK;

void push(STACK *s, int item)
{
    if (s->top == SIZE - 1)
        printf("\n Stack Overflow");
    else
        data[++(s->top)] = item;
}

int pop(STACK *s)
{
    if (s->top == -1)
    {
        printf("\n Stack Underflow");
        return -1;
    }
    return data[(s->top)--];
}

void decimaltobinary(STACK *s, int num)
{
    int rem;

    if (num == 0)
    {
        printf("\n The binary equivalent is 0\n");
        return;
    }

    while (num > 0)
    {
        rem = num % 2;
        push(s, rem);
        num = num / 2;
    }

    printf("\n The binary equivalent is: ");
    while (s->top != -1)
    {
        printf("%d", pop(s));
    }
    printf("\n");
}

int main()
{
    STACK s;
    s.top = -1;
    int num;

    printf("\n Read a decimal number: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("\n Invalid Input! Please enter a non-negative integer\n");
        return 0;
    }

    decimaltobinary(&s, num);

    return 0;
}
