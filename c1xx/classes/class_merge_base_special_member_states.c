void __cdecl class_merge_base_special_member_states(c1_symbol *cls,c1_u8 *states)

{
  c1_u8 *pcVar1;
  byte bVar2;
  c1_sym_link *pcVar3;
  c1_symbol *sub;
  c1_sym_link *pcVar4;
  c1_sym_link *pcVar5;
  
  if ((cls->x28).members == (c1_sym_list *)0x0) {
    pcVar3 = (c1_sym_link *)0x0;
  }
  else {
    pcVar3 = ((cls->x28).members)->head;
  }
  pcVar5 = (c1_sym_link *)0x0;
  if (pcVar3 != (c1_sym_link *)0x0) {
    pcVar5 = pcVar3;
  }
  do {
    while( true ) {
      pcVar4 = pcVar5;
      if (pcVar4 == (c1_sym_link *)0x0) {
        return;
      }
      if ((pcVar3 == (c1_sym_link *)0x0) ||
         (pcVar5 = pcVar3->next, pcVar3 = pcVar5, pcVar5 == (c1_sym_link *)0x0)) {
        pcVar5 = (c1_sym_link *)0x0;
      }
      bVar2 = (byte)pcVar4[-1].position & 0x1f;
      if (bVar2 == 3) break;
      if ((((g_compile_flags_cc & 0x100000) == 0) || (bVar2 != 0xf)) ||
         (((uint)pcVar4[1].name & 0x20000) == 0)) {
        if ((pcVar4[-1].position & 0x1f) != 0xf) {
          return;
        }
        if (((uint)pcVar4[1].name & 0x20000) == 0) {
          sub = g_scope_vector->entries[*(short *)&pcVar4[1].name];
        }
        else {
          sub = (c1_symbol *)0x0;
        }
        class_check_subobject_special_members(cls,sub,states);
        pcVar1 = &((cls->detail).cls)->layout_flags3c;
        *pcVar1 = *pcVar1 & 0xfe;
      }
    }
  } while ((pcVar4->name == g_name_vbptr) || (pcVar4->name == g_name_vfptr));
  return;
}

