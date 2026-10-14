c1_symbol * __thiscall block_scope_find_tag(c1_sym_list *list,int name)

{
  c1_sym_link *pcVar1;
  byte bVar2;
  
  pcVar1 = list->head;
  while( true ) {
    if (pcVar1 == (c1_sym_link *)0x0) {
      return (c1_symbol *)0x0;
    }
    if ((pcVar1->name == (fe_name *)name) &&
       ((bVar2 = (byte)pcVar1[-1].position & 0x1f, bVar2 == 4 || (bVar2 == 0x19)))) break;
    pcVar1 = pcVar1->next;
  }
  return (c1_symbol *)&pcVar1[-1].position;
}

