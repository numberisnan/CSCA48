/*
   Implementation of a linked-list for robot commands
   
   Demo for CSC A48
   (c) 1029 F. Estrada
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct robot_command_struct
{
    int command;
    float length;
    struct robot_command_struct *next;
} commandNode;

commandNode *new_commandNode(void)
{
  // Allocate and initialize a new commandNode
  
    commandNode *new_command=NULL;

    // TO DO - complete this function to allocate and initialize a commandNode 
    new_command = (commandNode*)calloc(1, sizeof(commandNode));
    new_command->command = -1; //Command -1 is uninitialised
  
    return new_command;  
}

commandNode *insert_command(commandNode *head, commandNode *new)
{
  // Insert the new command into the list * AT THE END *
  // This is because commands are sequenced, each new command
  // must be executed after the previous ones
  
    commandNode *p=NULL;
  
    // TO DO: Complete this function to insert a new commandNode into the list
    // DO NOT worry about duplicates!

    if (head == NULL) return new;

    p = head;
    while(p->next!=NULL) {
      p = p->next;
    }

    p->next = new;

    return head;
}

void updateCommand(commandNode *head, int which)
{
  // Find the command whose position in the list is 
  // given by 'which' (starting at 0 for head), and
  // update its contents to the desired values.
  
    commandNode *p=NULL;
    int c, com;
    float len;
  
    // TO DO: Complete code here to find the specified
    // command in the list, if found, the counter c should
    // be equal to the user's desired command 'which', and
    // the pointer p should be pointing to the node for
    // this command.

    c = which;
    p = head;
    for (c = 0; c < which; c++) {
      p = p->next;
    }
 

    // The code below simply updates the values in this node. 
    if (c==which)
    {
      printf("Enter the new command type\n");
      printf("    0 - Move Forward\n");
      printf("    1 - Rotate (turn) right\n");
      printf("    2 - Rotate (turn) left\n");
      printf("    3 - Move Backward\n");
      printf("    4 - Beep!\n");
      scanf("%d",&com);
      getchar();
      printf("Enter the new command length\n");
      scanf("%f",&len);
      getchar();
      p->command=com;
      p->length=len;
      printf("Updated command is type %d, with length %f\n",p->command,p->length);
    }  
}

commandNode *deleteCommand(commandNode *head, int which)
{
  // Remove the command whose position in the list is
  // given by 'which'
  
    commandNode *p=NULL;
    commandNode *q=NULL;
    int c;

    // TO DO: Implement code to delete the command at
    // position 'which' in the list.

    if (head==NULL) return NULL;

    p = head;
    for (c=0; c < which; c++) {
      p = p->next;
    }

    q = p->next;
    p->next = p->next->next;
    free(q);

    return head;
}

void deleteCommandList(commandNode *head)
{
  // Free up space taken by the linked list of commands
  
  // TO DO: Implement code to delete the entire list of commands!

}

void printCommandList(commandNode *head)
{
    commandNode *p=NULL;
    int c;
    
    p=head;
    c=0;
    
    printf("\n--------> Current command queue\n");
    while(p!=NULL)
    {
      printf("%d - ",c);
      switch (p->command)
      {
	case 0:
	    printf("Move forward, length %f\n",p->length);
	    break;
	case 1:
	    printf("Rotate (turn) right, length %f\n",p->length);
	    break;
	case 2:
	    printf("Rotate (turn) left, length %f\n",p->length);
	    break;
	case 3:
	    printf("Move backward, length %f\n",p->length);
	    break;
	case 4:
	    printf("Beep!, length %f\n",p->length);
	    break;
	default:
	    printf("Invalid command type! - fix this!\n");
	    break;	
      }
      p=p->next;
      c++;
    }
    printf("--------> End of current queue\n\n");
    
}

int main() {
  return 0;
}
