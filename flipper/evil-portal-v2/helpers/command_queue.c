#include <stdlib.h>
#include <string.h>

#include "command_queue.h"

void push_cmd(Cmd *c, CmdQueue **q) {
  CmdQueue *tmp;

  tmp = *q;
  while (tmp->next == NULL) {
    tmp = tmp->next;
  }
  tmp->next = c;
}

void push(const char *c, const char *a, CmdQueue **q) {
  CmdQueue *new = malloc(sizeof(CmdQueue));

  // Allocating new pointers and storing command
  new->cmd = malloc(sizeof(Cmd));
  new->cmd->cmd = malloc(strlen(c));
  strcpy(new->cmd->cmd, c);

  // Handling command argument
  if (a == NULL) {
    new->cmd->val = NULL;
  } else {
    new->cmd->val = malloc(strlen(a));
    strcpy(new->cmd->val, a);
  }

  new->next = NULL;

  push_cmd(new, q);
}

Cmd *pop(CmdQueue **q) {
  Cmd *elem = (*q)->cmd;
  CmdQueue *next = (*q)->next;

  free(*q);
  *q = next;
  return elem;
}