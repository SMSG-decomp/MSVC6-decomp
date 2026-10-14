int __cdecl debug_type_record_methodlist(byte *set)

{
  byte bVar1;
  fe_name *pfVar2;
  uint *puVar3;
  ushort *puVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  c1_symbol *pcVar8;
  uint offset;
  c1xx_ovl_set_iter local_20;
  c1xx_ovl_set_iter local_10;
  
  puVar4 = g_cv_record_body;
  puVar3 = g_debug_index_queue;
  offset = 0;
  ovl_set_iter_init(&local_20,set + 8);
  local_20.vtbl = (c1xx_ovl_set_iter_vtbl *)&PTR_debug_member_iter_next_104bcbb8;
  if ((local_20.next[-1].position & 0x1f) == 0x1a) {
    if ((*set & 0x1f) == 0x11) {
      do {
        local_20.next = (local_20.next)->next;
        if (local_20.next == (c1_sym_link *)0x0) goto LAB_1046434d;
      } while ((local_20.next[-1].position & 0x1f) == 0x1a);
      if (local_20.next == (c1_sym_link *)0x0) {
LAB_1046434d:
        local_20.next = (c1_sym_link *)0x0;
        goto LAB_1043e444;
      }
      goto LAB_1043e36a;
    }
  }
  else {
LAB_1043e36a:
    pfVar2 = (local_20.next)->name;
    pcVar8 = g_scope_vector->entries[*(short *)((int)&local_20.next[-1].type + 2)];
    if (((((pfVar2 != g_name_ctor) ||
          (bVar1 = ((pcVar8->detail).cls)->implicit_state41, (bVar1 & 2) == 0)) ||
         ((bVar1 & 4) == 0)) &&
        ((pfVar2 != g_name_operator_assign || ((((pcVar8->detail).cls)->implicit_state41 & 8) == 0))
        )) && ((pfVar2 != g_name_dtor || ((((pcVar8->detail).cls)->implicit_state41 & 0x10) == 0))))
    goto LAB_1043e444;
  }
  local_20.next = (c1_sym_link *)0x0;
LAB_1043e444:
  while (cVar5 = ovl_set_iter_next(&local_20), cVar5 != '\0') {
    while ((((local_20.current)->name == g_name_ctor &&
            ((((*(byte *)&local_20.current[2].type & 0x20) != 0 &&
              ((((g_scope_vector->entries[*(short *)((int)&local_20.current[-1].type + 2)]->detail).
                cls)->implicit_state41 & 4) != 0)) ||
             (((*(byte *)&local_20.current[2].type & 0x10) != 0 &&
              ((((g_scope_vector->entries[*(short *)((int)&local_20.current[-1].type + 2)]->detail).
                cls)->implicit_state41 & 2) != 0)))))) ||
           (((local_20.current[-1].position & 0x1f) == 0x1a ||
            ((*(byte *)((int)&local_20.current[2].type + 1) & 0x20) != 0))))) {
      cVar5 = ovl_set_iter_next(&local_20);
      if (cVar5 == '\0') goto LAB_1043e3e2;
    }
    pcVar8 = (c1_symbol *)&local_20.current[-1].position;
    if ((local_20.current[-1].position & 0x1f) == 0x1a) {
      pcVar8 = (((local_20.current)->type).alias)->target;
    }
    uVar6 = type_debug_member_function_index(pcVar8);
    *g_debug_index_queue = uVar6;
    g_debug_index_queue = g_debug_index_queue + 1;
  }
LAB_1043e3e2:
  g_debug_index_queue = puVar3;
  *puVar4 = 0x1206;
  debug_method_iterator_init(&local_10,(int *)(set + 8));
  do {
    cVar5 = ovl_set_iter_next(&local_10);
    while( true ) {
      if (cVar5 == '\0') {
        g_debug_index_queue = puVar3;
        iVar7 = cvserver_emit_type((short)offset + 2);
        return iVar7;
      }
      if ((((local_10.current)->name != g_name_ctor) ||
          ((((*(byte *)&local_10.current[2].type & 0x20) == 0 ||
            ((((g_scope_vector->entries[*(short *)((int)&local_10.current[-1].type + 2)]->detail).
              cls)->implicit_state41 & 4) == 0)) &&
           (((*(byte *)&local_10.current[2].type & 0x10) == 0 ||
            ((((g_scope_vector->entries[*(short *)((int)&local_10.current[-1].type + 2)]->detail).
              cls)->implicit_state41 & 2) == 0)))))) &&
         (((local_10.current[-1].position & 0x1f) != 0x1a &&
          ((*(byte *)((int)&local_10.current[2].type + 1) & 0x20) == 0)))) break;
      cVar5 = ovl_set_iter_next(&local_10);
    }
    pcVar8 = (c1_symbol *)&local_20.current[-1].position;
    if ((local_20.current[-1].position & 0x1f) == 0x1a) {
      pcVar8 = (((local_20.current)->type).alias)->target;
    }
    offset = debug_methodlist_entry((int)pcVar8,(int)(puVar4 + 1),offset);
  } while( true );
}

