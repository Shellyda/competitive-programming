/*
Problem B. Take ABC
Time limit 2000 ms
Mem limit 1048576 kB

Problem Statement
You are given a string consisting of three different characters: A, B, and C.

As long as contains the string ABC as a consecutive substring, repeat the following operation:
Remove the leftmost occurrence of the substring ABC from.
Print the final string after performing the above procedure.

Constraints
is a string of length between and , inclusive, consisting of the characters A, B,
and C.

Input
The input is given from Standard Input in the following format: S

Output
Print the answer.

Sample 1
Input Output
BAABCBCCABCAC BCAC

For the given string BAABCBCCABCAC , the operations are performed as follows.
In the first operation, the ABC from the -rd to the -th character in BAABCBCCABCAC
is removed, resulting in BABCCABCAC.
In the second operation, the ABC from the -nd to the -th character in BABCCABCAC
is removed, resulting in BCABCAC.
In the third operation, the ABC from the -rd to the -th character in BCABCAC is
removed, resulting in BCAC.
Therefore, the final is BCAC.
*/
#include <iostream>
#include <string>

using namespace std;

struct Node
{
  char data;
  Node *next;
};

struct Stack
{
  Node *top;

  Stack() : top(nullptr) {}

  bool isEmpty()
  {
    return top == nullptr;
  }

  void push(char value)
  {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
  }

  void pop()
  {
    if (isEmpty())
    {
      return;
    }

    Node *elementToBeDeleted = top;
    top = top->next;
    delete elementToBeDeleted;
  }

  char peek()
  {
    if (isEmpty())
    {
      return '\0';
    }

    return top->data;
  }

  void clear()
  {
    while (!isEmpty())
    {
      pop();
    }
  }
};

int main(void)
{
  Stack stack;
  string result, userInput;

  cin >> userInput;

  for (char currentLetter : userInput)
  {
    bool isBLetterBeforeC = currentLetter == 'C' && !stack.isEmpty() && stack.peek() == 'B';

    if (isBLetterBeforeC)
    {
      stack.pop();

      bool isALetterBeforeBandC = !stack.isEmpty() && stack.peek() == 'A';

      if (isALetterBeforeBandC)
      {
        stack.pop();
        continue;
      }
      else
      {
        stack.push('B');
      }
    }
    stack.push(currentLetter);
  }

  while (!stack.isEmpty())
  {
    result = stack.peek() + result;
    stack.pop();
  }

  cout << result << endl;

  return 0;
}
