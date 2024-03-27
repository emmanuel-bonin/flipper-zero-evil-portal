#pragma once

#ifndef __COMMAND_QUEUE_H__
# define __COMMAND_QUEUE_H__

/**
* A Command is an object that can be used to communicate
* between the flipper and the esp32 in both sides.
*
* TODO: it's a basic idea, let's check how it goes.
*/

// Structure representing a Command with an optional argument.
typedef struct s_cmd {
  const char *cmd;
  const char *val;
} Cmd;

// Linked list of Commands
typedef struct s_cmd_q {
  Cmd *cmd;
  struct s_cmd_q *next;
} CmdQueue;

/**
* Push a Cmd pointer in the queue.
*/
void push_cmd(Cmd *c, CmdQueue **q);

/**
* Create a new Cmd object from the command string to push in queue.
* If a is not NULL, it is added as the arg.
*/
void push(const char *c, CmdQueue **q);

/**
* Return the first element of the Command queue.
* Reset the next pointer of the returned element
* to avoid circularity if element is pushed again in queue.
*/
Cmd *pop(CmdQueue **q);

#endif