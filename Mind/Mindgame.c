#include <stdio.h>
#include <time.h>
typedef enum {TRUE = 1, FALSE = 0} bool;

typedef struct node {
        int val;
        struct node * next;
    } list;

static int score = 1;
static bool isGameOn = FALSE;
static int buttonValue;
static list * inputList;
static list * sequenceList;

void setUpMenu(){
printf("Press proper button:\n");
printf("Press 5 to start a game\n");
printf("Press 6 to interrupt game\n");

recogniseStartStopButton();
}

void recogniseStartStopButton(){
    scanf("%d", &buttonValue);
    switch(buttonValue){
case 5:
    isGameOn = TRUE;
    break;
case 6:
    exit(0);
    break;
default:
    system("cls");
    setUpMenu();
    }
}

int generateSequenceElement(){
    return (rand()%4 +1);
}

void setUpGame(){
    int i;
    while(isGameOn){
            displayList(sequenceList);
            addListElement(sequenceList, generateSequenceElement());
            for(i = score; i>0; i--){
                    if(i==score){
                    inputList->next = NULL;
                    scanf("%d", &buttonValue);
                    inputList->val = buttonValue;
                    }
                    if(i!=score){
                    recogniseUserInput();
                    }
            }
            compareLists();
            cleanInputList();
            score++;
   }
}
void addListElement(list * head, int newSequenceElement){
 list * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(list));
    current->next->val = newSequenceElement;
    current->next->next = NULL;
}

void cleanInputList(){
    deleteList(&inputList);
    inputList = malloc(sizeof(list));
}
void deleteList(struct node** head_ref)
{
   struct node* current = *head_ref;
   struct node* next;

   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }
   *head_ref = NULL;
}

void compareLists(){
    list * input = inputList;
    list *sequence = sequenceList;

    while (input != NULL ) {
        if(input->val!=sequence->val){
            isGameOn=FALSE;}
            input = input->next;
            sequence = sequence->next;
}
}
void displayList(list * head){
    list * current = head;
    while (current != NULL) {
        handleElementDisplay(current->val);
        current = current->next;
}
        printf("\n");
}
void handleElementDisplay(int val){
        system("cls");
        printf("Score:%d\n", score);
        printf("%d", val);
        displayForTime(2);
        system("cls");
        displayForTime(1);
        system("cls");
}
void displayForTime (unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}



void recogniseUserInput(){
     scanf("%d", &buttonValue);
    switch(buttonValue){
case 1:
    addListElement(inputList, buttonValue);
    break;
case 2:
    addListElement(inputList, buttonValue);
    break;
case 3:
    addListElement(inputList, buttonValue);
    break;
case 4:
    addListElement(inputList, buttonValue);
    break;
case 6:
    exit(0);
    break;
    }
}

void setUpLists(){
    inputList = malloc(sizeof(list));

    sequenceList = malloc(sizeof(list));
    sequenceList->next = NULL;
    sequenceList->val = generateSequenceElement();
}

int main() {
    srand( time( NULL ) );
    setUpMenu();
    setUpLists();
    setUpGame();


   return 0;
}
