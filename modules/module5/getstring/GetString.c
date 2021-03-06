#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

//Prototypes for the functions we need
string GetString(void);
void append(int c);

//Node structure definition
typedef struct node
{
    // the value to store in this node
    int n;

    // the link to the next node in the list
    struct node* next;
    struct node* prev;
}
node;

//A simple main method to test our function
int main(void)
{
    printf("Please give me a string: \n");
    string x = GetString();
    printf("Thanks for the %s!\n", x);
}

//The head of our linked list
node* head = NULL;

string GetString(void)
{

    // number of chars actually in buffer
    unsigned int n = 0;

    // character read or EOF
    int c;

    // iteratively get chars from standard input
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        //append the character to our linked list
        append(c);
        //update the number of characters
        n++;
    }

    // return NULL if user provided no input
    if (n == 0 && c == EOF)
    {
        return NULL;
    }

    //create a string to hold our result
    string minimal = malloc((n + 1) * sizeof(char));

    //iterate through the list, adding each character to the string
    node * curr = head;
    for(int i = 0; i < n; i++)
    {
        minimal[i] = curr->n;
        curr = curr->prev;
    }
    
    for (int i = 0; i < n/2; i++){
        char temp;
        temp = minimal[i];
        minimal[i] = minimal[n-1-i];
        minimal[n-1-i] = temp;
    }

    // terminate string
    minimal[n] = '\0';

    // return string
    return minimal;
}

void append(int c)
{
    //create a new node
    node* newNode = malloc(sizeof(node));
    newNode->n = c;
    newNode->next = NULL;
    newNode->prev = NULL;

    //if the list is empty, our node is the only node
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        node* curr = head;
        curr->next = newNode;
        newNode->prev = curr;
        head = newNode;
    }
}