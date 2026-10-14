int * __cdecl init_next_member_to_initialize(c1_symbol *obj,int *member)

{
  byte bVar1;
  int iVar2;
  
  do {
    if (member == (int *)0x0) {
      return (int *)0x0;
    }
    bVar1 = *(byte *)(member + -2) & 0x1f;
    if (bVar1 == 0) {
LAB_10448c99:
      iVar2 = member_is_copied_data((c1_symbol *)(member + -2));
      bVar1 = (byte)iVar2;
joined_r0x10448ca4:
      if (bVar1 != 0) {
        return member;
      }
    }
    else {
      if ((((0xe < bVar1) || (bVar1 == 5)) || ((void *)*member != g_name_alignment_member)) ||
         ((*(byte *)((int)member + -3) & 0x18) != 0)) {
        if (((bVar1 == 0) || (0xe < bVar1)) ||
           ((bVar1 == 5 || ((void *)*member != g_name_alignment_member)))) goto LAB_10448c99;
        if ((*(byte *)((int)member + -3) & 0x10) != 0) {
          return (int *)0x0;
        }
        bVar1 = *(byte *)((int)member + -3) & 8;
        goto joined_r0x10448ca4;
      }
      if (g_init_bitfield_unit_open != 0) {
        g_constant_value = g_init_bitfield_value;
        g_constant_value_high = g_init_bitfield_value_high;
        init_finish_array((int)obj);
        g_init_bitfield_unit_open = 0;
      }
      init_set_array_dimension((c1_symbol *)(member + -2));
    }
    member = (int *)member[1];
  } while( true );
}

