/* Harriet Odiete
*  Maze Solver Program
*/
#include "stack.h"

#define MAXSIZE 5000
#define START 'S'
#define FINISH 'F'
#define PATH ' '

Stack * path;
int row = 0;
int column = 0;

/*Function prototypes*/
char * readFile(char * input);

void solver(Node * node[], int size);

bool findNext(Node ** node[], int size, char * neighbour, int * count);

void checkForUp(Node ** node[], int size, int * count);

void checkForLeft(Node ** node[], int size, int * count);

void checkForDown(Node ** node[], int size, int * count);

int main(int argc, char * argv[])
{
    /*Structures and Variables declaration*/
    Node * list[MAXSIZE];
    char * maze;
    int i = 0;
    int j = 0;
    int nodeCount = 0;
    if(argc != 2){
        printf("No text file given\n");
        exit(1);
    }
    maze = readFile(argv[1]);

    path = createStack();

    /* Add available paths to the array*/
    for(i = 0; i<row; i++){
        for(j=0; j<column; j++){
            if(*(maze + i*column + j) == PATH || *(maze + i*column + j) == START || *(maze + i*column + j) == FINISH){
                list[nodeCount] = initNode(*(maze + i*column + j), i, j);
                nodeCount++;
            }
        }
    }

    solver(list, nodeCount);

    /*Mark path with a # as route*/
    while(path != NULL){
         *(maze + path->block->x*column + path->block->y) = '#';
         path = path->next;
    }
    printf("\n");
    /*Print out maze solution to terminal*/
    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            printf("%c", *(maze + i*column + j));
        }
        printf("\n");
    }
    return 0;
}

/*Function definitions*/
char * readFile(char * input)
{
    FILE * file;
    char * arr;
    char (*data)[MAXSIZE] = NULL;
    int i = 0;
    int j = 0;

    file =fopen(input, "r");
    if(file == NULL)
    {
        printf("Error reading file\n");
        exit(1);
    }
    else
    {
        data = malloc(sizeof(char)*50);
        /* Read first line to get the number of columns for the 2D array */
        fgets(data[row], MAXSIZE, file);
        data[row][strlen(data[row]) - 1] = '\0';
        column = strlen(data[row]);;
        row++;
        while(fgets(data[row], MAXSIZE, file) != NULL)
        {
            data[row][strlen(data[row]) - 1] = '\0';
            row++;
            
        }
        fclose(file);

        arr = (char*)malloc(row*column*sizeof(char));
        for(i=0; i<row; i++){
            for(j=0; j<column; j++){
                *(arr + i*column + j) = data[i][j];
            }
        }
    }
    return arr;
    
}

void solver(Node * node[], int size)
{
    int count = 0;
    Node * currCell = NULL;
    /* Push Start into stack and mark as visited in the list of available paths*/
    push(&path, node[count]);
    node[count]->visited = true;
    currCell = node[0];
    count++;
    
    while(currCell->ch != 'F'){
        /*printf("top of stack: x: %d, y: %d, visited %s\n",currCell->x, currCell->y, currCell->visited ? "true" :"false");
        printf("present node: x: %d, y: %d, visited %s\n",node[c]->x, node[c]->y, node[c]->visited ? "true" :"false");*/
        if(node[count]->y == currCell->y+1){ 
            /*If next node is the right neighbour of the current node on the stack*/
            if(node[count]->visited == false){
                push(&path, node[count]);
                node[count]->visited = true;
                count++;
            }
            else{
                checkForDown(&node, size, &count);
            }
        }
        else{
            /*Check for down neighbour*/
            checkForDown(&node, size, &count);

        }
        currCell = peek(path);
    }
}

/*Check for available neighbour*/
bool findNext(Node ** node[], int size, char * neighbour, int * count){
    bool found = false;
    int trace = *count;
    Node * top = peek(path);
    if(strcmp(neighbour, "down") == 0){
        while(*count != size){
            if((*node)[*count]->x == top->x+1 && (*node)[*count]->y == top->y){
                found = true;
                break;
            }
            if((*node)[*count]->x == top->x+1 && (*node)[*count]->y > top->y){
                break;
            }
            (*count)++;
        }
    }
    else if(strcmp(neighbour, "left") == 0){
        /*Assuming it takes the right node as the next node to current*/
        while(trace != 0){
            if((*node)[trace]->x == top->x && (*node)[trace]->y == top->y-1){
                found = true;
                *count = trace;
                break;
            }
            if((*node)[trace]->x == top->x && (*node)[trace]->y < top->y-1){
                break;
            }
            trace--;
        }
    }
    else if(strcmp(neighbour, "up") == 0){
        while(trace != 0){
            if((*node)[trace]->x == top->x-1 && (*node)[trace]->y == top->y){
                found = true;
                *count = trace;
                break;
            }
            if((*node)[trace]->x == top->x-1 && (*node)[trace]->y < top->y){
                break;
            }
            trace--;
         }
    }
    return found;

}

void checkForUp(Node ** node[], int size, int * count){
    bool found = false;
    found = findNext(node, size, "up", count);
    if(found == true){
        if((*node)[*count]->visited == false){
            /* Push up neighbour on stack*/
            push(&path, (*node)[*count]);
            (*node)[*count]->visited = true;
            (*count)++; /* Go to next in list*/
        }
        else{
            /*If up is visited, remove current cell from path*/
            pop(&path);
        }
    }
    else{
        /*If no right, down, left and up neighbour, that means no more neighbours*/
        pop(&path);
    }
}

void checkForLeft(Node ** node[], int size, int * count){
    bool found = false;
    found = findNext(node, size, "left", count);
    if(found == true){
        if((*node)[*count]->visited == false){
            /* Push up neighbour on stack*/
            push(&path, (*node)[*count]);
            (*node)[*count]->visited = true;
            (*count)++; /* Go to next in list*/
        }
        else{
            /*If left is visited, check for up neighbour*/
            checkForUp(node, size, count);
        }
    }
    else{
        /*If no right, down and left neighbour, check for up neighbour*/
        checkForUp(node, size, count);
    }

}

void checkForDown(Node ** node[], int size, int * count)
{
    bool found = false;
    int tracker = *count;
    found = findNext(node, size, "down", count);
    if(found == true){
        if((*node)[*count]->visited == false){
            /* Push down neighbour on stack*/
            push(&path, (*node)[*count]);
            (*node)[*count]->visited = true;
            (*count)++; /* Go to next in list*/
        }
        else{
            /*Down is visited, check for left neighbour*/
            checkForLeft(node, size, count);
        }
    }
    else{
        /* If no down neighbour found, check for left neighbour*/
        *count = tracker;
        checkForLeft(node, size, count);
    }
}

