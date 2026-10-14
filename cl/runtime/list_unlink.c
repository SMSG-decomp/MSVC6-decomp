optrec * __cdecl list_unlink(optrec **head,optrec *node)

{
  optrec *cur;
  optrec *cur_2;
  
  while( true ) {
    cur = *head;
    if (cur == (optrec *)0x0) {
      return (optrec *)0x0;
    }
    if (cur == node) break;
    head = &cur->next;
  }
  cur_2 = *head;
  *head = cur_2->next;
  cur_2->next = (cl_optrec *)0x0;
  return cur_2;
}

