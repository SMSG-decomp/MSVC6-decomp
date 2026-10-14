int * __cdecl init_skip_padding_members(int sym,int *member)

{
  byte bVar1;
  void *pvVar2;
  
  pvVar2 = g_name_alignment_member;
  if (member != (int *)0x0) {
    while( true ) {
      bVar1 = *(byte *)(member + -2) & 0x1f;
      if (bVar1 == 0) break;
      if ((((bVar1 < 0xf) && (bVar1 != 5)) && ((void *)*member == pvVar2)) &&
         ((*(byte *)(member + -1) & 0x18) == 0)) {
        if (g_init_bitfield_unit_open != 0) {
          g_constant_value = g_init_bitfield_value;
          g_constant_value_high = g_init_bitfield_value_high;
          init_finish_array(sym);
          g_init_bitfield_unit_open = 0;
        }
        init_set_array_dimension((c1_symbol *)(member + -2));
        pvVar2 = g_name_alignment_member;
      }
      else {
        if (bVar1 == 0) {
          return member;
        }
        if (0xe < bVar1) {
          return member;
        }
        if (bVar1 == 5) {
          return member;
        }
        if ((void *)*member != pvVar2) {
          return member;
        }
        if ((*(byte *)(member + -1) & 0x10) != 0) {
          return (int *)0x0;
        }
        if ((*(byte *)(member + -1) & 8) != 0) {
          return member;
        }
      }
      member = (int *)member[1];
      if (member == (int *)0x0) {
        return (int *)0x0;
      }
    }
  }
  return member;
}

