void __cdecl class_check_unnamed_class_member(c1xx_decl_specifiers *spec)

{
  c1_symbol *pcVar1;
  char cVar2;
  c1_symbol *pcVar3;
  c1_sym_link *first;
  int iVar4;
  c1_member_iter local_28;
  c1xx_ovl_set_iter local_10;
  
  if ((((g_compile_flags_c4 & 0x200) == 0) && ((spec->type->code & 0x200) != 0)) &&
     (pcVar1 = (spec->type->extra).cls, (pcVar1->flags3 & 1) != 0)) {
    if ((pcVar1->x28).members == (c1_sym_list *)0x0) {
      first = (c1_sym_link *)0x0;
    }
    else {
      first = ((pcVar1->x28).members)->head;
    }
    list_cursor_init(&local_28,first);
    local_28.current = (c1_u8 *)0x0;
    local_28.next = (void *)0x0;
    local_28.filter = 2;
    if (local_28.cursor.valid != '\0') {
      local_28.next = local_28.cursor.current;
    }
    local_28.cls = &pcVar1->name;
    ovl_set_iter_init(&local_10,(void *)0x0);
    while( true ) {
      while( true ) {
        cVar2 = (*(local_10.vtbl)->ovl_set_iter_next)(&local_10);
        if (cVar2 == '\0') break;
        pcVar3 = (c1_symbol *)&local_10.current[-1].position;
        if ((local_10.current[-1].position & 0x1f) == 0x1a) {
          pcVar3 = (((local_10.current)->type).alias)->target;
        }
        if ((pcVar3->flags3 & 1) == 0) {
          diag_error(0x273);
          return;
        }
      }
      cVar2 = class_member_iter_next(&local_28);
      if (cVar2 == '\0') break;
      sym_overload_iter_init(&local_10,local_28.current);
    }
    iVar4 = 1;
    while (((uint)((pcVar1->detail).cls)->implicit_state42 & 1 << ((byte)iVar4 & 0x1f)) == 0) {
      iVar4 = iVar4 + 1;
      if (4 < iVar4) {
        return;
      }
    }
    diag_error(0x27f,g_implicit_member_kind_names[iVar4]);
  }
  return;
}

