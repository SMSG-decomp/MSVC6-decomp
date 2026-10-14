void __thiscall list_push_front(void **head,void **cell)

{
  *cell = *head;
  *head = cell;
  return;
}

