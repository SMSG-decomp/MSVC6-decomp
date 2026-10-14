cl_mre_srctarg * __cdecl list_to_inner_links(node *l)

{
  cl_mre_srctarg *list;
  cl_mre_srctarg *head;
  cl_mre_srctarg *last;
  cl_mre_srctarg *rec;
  
  list = (cl_mre_srctarg *)0x0;
  head = list;
  last = (cl_mre_srctarg *)0x0;
  if (l != (node *)0x0) {
    do {
      rec = &l->mre;
      list = rec;
      if (last != (cl_mre_srctarg *)0x0) {
        last->next = rec;
        list = head;
      }
      l = l->next;
      head = list;
      last = rec;
    } while (l != (cl_compile_node *)0x0);
    if (rec != (cl_mre_srctarg *)0x0) {
      rec->next = (cl_mre_srctarg *)0x0;
    }
  }
  return list;
}

