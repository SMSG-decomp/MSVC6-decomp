c2_symbol * __fastcall find_restorable_temp(c2_bitset *a,c2_bitset *b,c2_symbol *s)

{
  uint32_t uVar1;
  uint32_t uVar2;
  c2_symbol *pcVar3;
  
  pcVar3 = (c2_symbol *)0x0;
  while( true ) {
    if (s == (c2_symbol *)0x0) {
      return pcVar3;
    }
    uVar2 = s->id;
    uVar1 = bitset_test(a,uVar2);
    if ((uVar1 != 0) &&
       (((pcVar3 != (c2_symbol *)0x0 || (uVar2 = bitset_test(b,uVar2), uVar2 == 0)) ||
        (pcVar3 = s, s->defs == (c2_list_cell *)0x0)))) break;
    s = s->part_next;
  }
  return (c2_symbol *)0x0;
}

