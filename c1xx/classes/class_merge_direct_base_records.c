void __cdecl class_merge_direct_base_records(c1_symbol *cls)

{
  byte bVar1;
  c1_sym_link *pcVar2;
  c1_sym_link *pcVar3;
  c1_sym_link *pcVar4;
  
  if ((cls->x28).members == (c1_sym_list *)0x0) {
    pcVar2 = (c1_sym_link *)0x0;
  }
  else {
    pcVar2 = ((cls->x28).members)->head;
  }
  pcVar4 = (c1_sym_link *)0x0;
  if (pcVar2 != (c1_sym_link *)0x0) {
    pcVar4 = pcVar2;
  }
  do {
    while( true ) {
      pcVar3 = pcVar4;
      if (pcVar3 == (c1_sym_link *)0x0) {
        return;
      }
      if ((pcVar2 == (c1_sym_link *)0x0) ||
         (pcVar4 = pcVar2->next, pcVar2 = pcVar4, pcVar4 == (c1_sym_link *)0x0)) {
        pcVar4 = (c1_sym_link *)0x0;
      }
      bVar1 = (byte)pcVar3[-1].position & 0x1f;
      if (bVar1 == 3) break;
      if ((((g_compile_flags_cc & 0x100000) == 0) || (bVar1 != 0xf)) ||
         (((uint)pcVar3[1].name & 0x20000) == 0)) {
        if ((pcVar3[-1].position & 0x1f) != 0xf) {
          return;
        }
        class_inherit_base_tables((c1_symbol *)&pcVar3[-1].position,cls);
      }
    }
  } while ((pcVar3->name == g_name_vbptr) || (pcVar3->name == g_name_vfptr));
  return;
}

