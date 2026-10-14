void __cdecl class_append_member(c1_symbol *sym)

{
  uint *puVar1;
  c1_sym_list *pcVar2;
  fe_name **ppfVar3;
  
  ppfVar3 = &sym->name;
  if (*ppfVar3 != (fe_name *)0x0) {
    puVar1 = &(*ppfVar3)->flags;
    *puVar1 = *puVar1 | 0x40000;
  }
  pcVar2 = ((g_class_def_stack[g_class_depth].cls)->x28).members;
  sym->next = (c1_symbol *)0x0;
  if (pcVar2->tail != (c1_sym_link *)0x0) {
    pcVar2->tail->next = (c1_sym_link *)ppfVar3;
    pcVar2->tail = (c1_sym_link *)ppfVar3;
    return;
  }
  pcVar2->head = (c1_sym_link *)ppfVar3;
  pcVar2->tail = (c1_sym_link *)ppfVar3;
  return;
}

