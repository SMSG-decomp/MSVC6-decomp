int * __thiscall class_scope_find_link(c1xx_class_scope *class_scope,int *entry)

{
  int *link;
  c1_sym_link *pcVar1;
  int *link_2;
  
  link = (int *)&((class_scope->cls->x28).members)->head;
  pcVar1 = (c1_sym_link *)*link;
  if (pcVar1->name != (fe_name *)*entry) {
    while( true ) {
      link_2 = (int *)&pcVar1->next;
      pcVar1 = pcVar1->next;
      if (pcVar1 == (c1_sym_link *)0x0) break;
      if (pcVar1->name == (fe_name *)*entry) {
        return link_2;
      }
    }
    link = (int *)0x0;
  }
  return link;
}

