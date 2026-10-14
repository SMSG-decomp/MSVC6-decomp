void __cdecl list_append(optrec **head,optrec *node)

{
  for (; *head != (optrec *)0x0; head = &(*head)->next) {
  }
  *head = node;
  return;
}

