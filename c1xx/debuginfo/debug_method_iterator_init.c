c1xx_ovl_set_iter * __thiscall debug_method_iterator_init(c1xx_ovl_set_iter *iter,int *set_entry)

{
  byte bVar1;
  c1_symbol *pcVar2;
  fe_name *pfVar3;
  int iVar4;
  c1_sym_link *pcVar5;
  
  iter->next = (c1_sym_link *)0x0;
  iter->current = (c1_sym_link *)0x0;
  iter->start = (c1_sym_link *)set_entry;
  iter->vtbl = (c1xx_ovl_set_iter_vtbl *)&PTR_ovl_set_iter_next_104bcaf0;
  if (set_entry != (int *)0x0) {
    iVar4 = sym_is_data_or_function_2((c1_symbol *)(set_entry + -2));
    if (((char)iVar4 == '\0') && ((iter->start[-1].position & 0x1f) != 0x1a)) {
      iter->next = (c1_sym_link *)iter->start->type;
    }
    else {
      iter->next = iter->start;
    }
  }
  pcVar5 = iter->next;
  iter->vtbl = (c1xx_ovl_set_iter_vtbl *)&PTR_debug_member_iter_next_104bcbb8;
  if ((pcVar5[-1].position & 0x1f) == 0x1a) {
    if ((*(byte *)(set_entry + -2) & 0x1f) != 0x11) goto LAB_104649e6;
    do {
      pcVar5 = pcVar5->next;
      if (pcVar5 == (c1_sym_link *)0x0) goto LAB_104649d2;
    } while ((pcVar5[-1].position & 0x1f) == 0x1a);
    if (pcVar5 == (c1_sym_link *)0x0) {
LAB_104649d2:
      iter->next = (c1_sym_link *)0x0;
      return iter;
    }
  }
  pcVar2 = g_scope_vector->entries[*(short *)((int)&pcVar5[-1].type + 2)];
  pfVar3 = pcVar5->name;
  if ((((pfVar3 != g_name_ctor) ||
       (bVar1 = ((pcVar2->detail).cls)->implicit_state41, (bVar1 & 2) == 0)) || ((bVar1 & 4) == 0))
     && (((pfVar3 != g_name_operator_assign || ((((pcVar2->detail).cls)->implicit_state41 & 8) == 0)
          ) && ((pfVar3 != g_name_dtor || ((((pcVar2->detail).cls)->implicit_state41 & 0x10) == 0)))
         ))) {
    iter->next = pcVar5;
    return iter;
  }
LAB_104649e6:
  iter->next = (c1_sym_link *)0x0;
  return iter;
}

