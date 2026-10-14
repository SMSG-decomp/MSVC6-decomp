char __cdecl class_has_direct_base(c1_symbol *cls,c1_symbol *base)

{
  byte bVar1;
  c1_sym_link *pcVar2;
  c1_symbol *pcVar3;
  c1_sym_link *pcVar4;
  c1_sym_link *pcVar5;
  
  if ((cls->x28).members == (c1_sym_list *)0x0) {
    pcVar2 = (c1_sym_link *)0x0;
  }
  else {
    pcVar2 = ((cls->x28).members)->head;
  }
  pcVar5 = (c1_sym_link *)0x0;
  if (pcVar2 != (c1_sym_link *)0x0) {
    pcVar5 = pcVar2;
  }
  do {
    do {
      while( true ) {
        pcVar4 = pcVar5;
        if (pcVar4 == (c1_sym_link *)0x0) {
          return '\0';
        }
        if ((pcVar2 == (c1_sym_link *)0x0) ||
           (pcVar5 = pcVar2->next, pcVar2 = pcVar5, pcVar5 == (c1_sym_link *)0x0)) {
          pcVar5 = (c1_sym_link *)0x0;
        }
        bVar1 = (byte)pcVar4[-1].position & 0x1f;
        if (bVar1 != 3) break;
        if ((pcVar4->name != g_name_vbptr) && (pcVar4->name != g_name_vfptr)) {
          bVar1 = class_has_direct_base_stop();
          return bVar1;
        }
      }
    } while ((((g_compile_flags_cc & 0x100000) != 0) && (bVar1 == 0xf)) &&
            (((uint)pcVar4[1].name & 0x20000) != 0));
    if ((pcVar4[-1].position & 0x1f) != 0xf) {
      return '\0';
    }
    if (((uint)pcVar4[1].name & 0x20000) == 0) {
      pcVar3 = g_scope_vector->entries[*(short *)&pcVar4[1].name];
    }
    else {
      pcVar3 = (c1_symbol *)0x0;
    }
  } while (pcVar3 != base);
  return '\x01';
}

