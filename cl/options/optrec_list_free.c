void __cdecl optrec_list_free(optrec *list)

{
  cl_optrec *next;
  
  while (list != (optrec *)0x0) {
    next = list->next;
    optrec_free(list);
    list = next;
  }
  return;
}

