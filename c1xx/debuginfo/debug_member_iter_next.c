char __fastcall debug_member_iter_next(c1xx_debug_method_iter *iter)

{
  c1_sym_link *pcVar1;
  int iVar2;
  
LAB_10464a03:
  do {
    if ((iter->start == (c1_sym_link *)0x0) || (iter->next == (c1_sym_link *)0x0)) {
      return '\0';
    }
    iter->current = iter->next;
    iVar2 = sym_is_data_or_function_2((c1_symbol *)&iter->start[-1].position);
    if (((char)iVar2 == '\0') && ((iter->start[-1].position & 0x1f) != 0x1a)) {
      iter->next = iter->next->next;
    }
    else {
      iter->next = (c1_sym_link *)0x0;
    }
    pcVar1 = iter->current;
    if (pcVar1->name == g_name_ctor) {
      if ((((*(byte *)&pcVar1[2].type & 0x20) != 0) &&
          ((((g_scope_vector->entries[*(short *)((int)&pcVar1[-1].type + 2)]->detail).cls)->
            implicit_state41 & 4) != 0)) ||
         (((*(byte *)&pcVar1[2].type & 0x10) != 0 &&
          ((((g_scope_vector->entries[*(short *)((int)&pcVar1[-1].type + 2)]->detail).cls)->
            implicit_state41 & 2) != 0)))) goto LAB_10464a03;
    }
    if (((pcVar1[-1].position & 0x1f) != 0x1a) &&
       ((*(byte *)((int)&pcVar1[2].type + 1) & 0x20) == 0)) {
      return '\x01';
    }
  } while( true );
}

