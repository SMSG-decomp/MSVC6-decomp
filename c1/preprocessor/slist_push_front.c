void __thiscall slist_push_front(void **head,void **node)

{
  *node = *head;
  *head = node;
  return;
}

