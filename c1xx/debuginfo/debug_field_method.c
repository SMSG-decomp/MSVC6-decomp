uint __cdecl debug_field_method(int pass,byte *set,ushort *out,int *count,ushort *property)

{
  byte bVar1;
  fe_name *pfVar2;
  uint uVar3;
  void *pvVar4;
  char cVar5;
  uint uVar6;
  uint *puVar7;
  c1_symbol *pcVar8;
  int iVar9;
  c1_symbol *pcVar10;
  int local_14;
  c1xx_ovl_set_iter local_10;
  
  local_14 = 0;
  ovl_set_iter_init(&local_10,set + 8);
  local_10.vtbl = (c1xx_ovl_set_iter_vtbl *)&PTR_debug_member_iter_next_104bcbb8;
  pcVar10 = (c1_symbol *)pass;
  if ((local_10.next[-1].position & 0x1f) == 0x1a) {
    if ((*set & 0x1f) != 0x11) goto LAB_1043c5ff;
    do {
      local_10.next = (local_10.next)->next;
      if (local_10.next == (c1_sym_link *)0x0) goto LAB_10464315;
    } while ((local_10.next[-1].position & 0x1f) == 0x1a);
    if (local_10.next != (c1_sym_link *)0x0) goto LAB_1043c53a;
LAB_10464315:
    local_10.next = (c1_sym_link *)0x0;
  }
  else {
LAB_1043c53a:
    pfVar2 = (local_10.next)->name;
    pcVar8 = g_scope_vector->entries[*(short *)((int)&local_10.next[-1].type + 2)];
    if (((((pfVar2 == g_name_ctor) &&
          (bVar1 = ((pcVar8->detail).cls)->implicit_state41, (bVar1 & 2) != 0)) &&
         ((bVar1 & 4) != 0)) ||
        ((pfVar2 == g_name_operator_assign && ((((pcVar8->detail).cls)->implicit_state41 & 8) != 0))
        )) || ((pfVar2 == g_name_dtor && ((((pcVar8->detail).cls)->implicit_state41 & 0x10) != 0))))
    {
LAB_1043c5ff:
      local_10.next = (c1_sym_link *)0x0;
    }
  }
  while (cVar5 = ovl_set_iter_next(&local_10), cVar5 != '\0') {
    while ((((local_10.current)->name == g_name_ctor &&
            ((((*(byte *)&local_10.current[2].type & 0x20) != 0 &&
              ((((g_scope_vector->entries[*(short *)((int)&local_10.current[-1].type + 2)]->detail).
                cls)->implicit_state41 & 4) != 0)) ||
             (((*(byte *)&local_10.current[2].type & 0x10) != 0 &&
              ((((g_scope_vector->entries[*(short *)((int)&local_10.current[-1].type + 2)]->detail).
                cls)->implicit_state41 & 2) != 0)))))) ||
           (((local_10.current[-1].position & 0x1f) == 0x1a ||
            ((*(byte *)((int)&local_10.current[2].type + 1) & 0x20) != 0))))) {
      cVar5 = ovl_set_iter_next(&local_10);
      if (cVar5 == '\0') goto LAB_1043c585;
    }
    pcVar8 = (c1_symbol *)&local_10.current[-1].position;
    if ((local_10.current[-1].position & 0x1f) == 0x1a) {
      pcVar8 = (((local_10.current)->type).alias)->target;
    }
    if (((pcVar8->flags3 & 1) == 0) || ((pcVar8->flags2 & 4) != 0)) {
      local_14 = local_14 + 1;
      pcVar10 = pcVar8;
    }
  }
LAB_1043c585:
  puVar7 = (uint *)0x0;
  if (local_14 != 0) {
    if (local_14 == 1) {
      if (pass != 1) {
        *out = 0x140b;
        uVar6 = debug_method_field_attributes((int)pcVar10,out + 1,(uint *)(out + 4));
        uVar3 = *g_debug_index_queue;
        g_debug_index_queue = g_debug_index_queue + 1;
        *(uint *)(out + 2) = uVar3;
        iVar9 = debug_identifier_length_2((byte *)((uVar6 & 0xffff) + 8 + (int)out),pcVar10,'\0');
        uVar6 = iVar9 + 9 + uVar6;
LAB_1043c73c:
        *count = *count + local_14;
        if (pass != 2) {
          return uVar6;
        }
        *property = *property | (ushort)((pcVar10->tail).fn.op_token != '\x01') << 2;
        pvVar4 = *(void **)(set + 8);
        if ((pvVar4 != g_name_ctor) && (pvVar4 != g_name_dtor)) {
          *property = *property;
          return uVar6;
        }
        *property = *property | 2;
        return uVar6;
      }
      uVar6 = type_debug_member_function_index(pcVar10);
    }
    else {
      if (pass != 1) {
        *out = 0x1407;
        out[1] = (ushort)local_14;
        uVar6 = *g_debug_index_queue;
        g_debug_index_queue = g_debug_index_queue + 1;
        *(uint *)(out + 2) = uVar6;
        iVar9 = debug_identifier_length_2((byte *)(out + 4),pcVar10,'\0');
        uVar6 = iVar9 + 9;
        goto LAB_1043c73c;
      }
      uVar6 = debug_type_record_methodlist(set);
    }
    *g_debug_index_queue = uVar6;
    puVar7 = g_debug_index_queue + 1;
    g_debug_index_queue = puVar7;
  }
  return (uint)puVar7 & 0xffff0000;
}

