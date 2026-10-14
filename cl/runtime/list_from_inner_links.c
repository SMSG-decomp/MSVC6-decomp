node * __cdecl list_from_inner_links(cl_mre_srctarg *l)

{
  node *list;
  node *head;
  node *last;
  char **n;
  
  list = (node *)0x0;
  head = list;
  last = (node *)0x0;
  if (l != (cl_mre_srctarg *)0x0) {
    do {
      n = &l[-1].options;
      list = (node *)n;
      if (last != (node *)0x0) {
        last->next = (cl_compile_node *)n;
        list = head;
      }
      if (l == (cl_mre_srctarg *)0x0) {
        l = (cl_mre_srctarg *)0x0;
      }
      else {
        l = l->next;
      }
      head = list;
      last = (node *)n;
    } while (l != (cl_mre_srctarg *)0x0);
    if (n != (char **)0x0) {
      *n = (char *)0x0;
    }
  }
  return list;
}

