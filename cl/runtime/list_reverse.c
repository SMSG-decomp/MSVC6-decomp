node * __cdecl list_reverse(node *l)

{
  node *rev;
  cl_compile_node *next;
  
  rev = (node *)0x0;
  while (l != (node *)0x0) {
    next = l->next;
    l->next = rev;
    rev = l;
    l = next;
  }
  return rev;
}

