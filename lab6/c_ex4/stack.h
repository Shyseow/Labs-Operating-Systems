typedef struct node{
char *str;
struct node *next;
}Node;

typedef struct{
Node *top;
int number;
}Stack;

Stack *create_stack();
void push_stack(Stack *stack, char *str);
char *pop_stack(Stack *stack);
int size_of_stack(Stack *stack);
int empty_stack(Stack *stack);
