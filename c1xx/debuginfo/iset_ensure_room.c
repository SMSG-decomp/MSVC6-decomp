int __thiscall iset_ensure_room(c1xx_pdb_array *set,uint n)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  c1_u32 *pcVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = set->count;
  do {
    if ((n >> 5) + 1 <= uVar2) {
      return 1;
    }
    uVar1 = uVar2 + 1;
    if (set->capacity < uVar1) {
      uVar3 = set->capacity * 3 >> 1;
      uVar6 = uVar1;
      if (uVar1 <= uVar3) {
        uVar6 = uVar3;
      }
      pcVar4 = __2_YAPAXI_Z(uVar6 * 4);
      if (pcVar4 == (c1_u32 *)0x0) {
        return 0;
      }
      if (set->data != (c1_u32 *)0x0) {
        uVar3 = 0;
        if (set->count != 0) {
          do {
            uVar5 = uVar3 + 1;
            pcVar4[uVar3] = set->data[uVar3];
            uVar3 = uVar5;
          } while (uVar5 < set->count);
        }
        __3_YAXPAX_Z(set->data);
      }
      set->data = pcVar4;
      set->capacity = uVar6;
    }
    set->count = uVar1;
    set->data[uVar2] = 0;
    uVar2 = set->count;
  } while( true );
}

