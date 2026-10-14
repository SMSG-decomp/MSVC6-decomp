c2_bitset * __fastcall collect_remat_dependencies(c2_tuple *def,c2_live_range *lr,int *eligible)

{
  c2_operand *pcVar1;
  c2_live_range *pcVar2;
  c2_bitset *bs;
  
  pcVar1 = def->src;
  bs = (c2_bitset *)0x0;
  *eligible = 1;
  do {
    if (pcVar1 == (c2_operand *)0x0) {
      return bs;
    }
    if ((pcVar1->flags & 0x20) != 0) {
      pcVar2 = (pcVar1->u18).range;
      if (pcVar2->kind != '\x02') {
LAB_107683c9:
        if (pcVar1 == (c2_operand *)0x0) {
          return bs;
        }
        if (bs != (c2_bitset *)0x0) {
          bitset_free(bs);
        }
        return (c2_bitset *)0x0;
      }
      if ((pcVar2 != lr) && (pcVar2->colour == (c2_register_descriptor *)0x0)) {
        *eligible = 0;
      }
      if ((pcVar1->flags11 & 0x10) != 0) goto LAB_107683c9;
      if (bs == (c2_bitset *)0x0) {
        bs = bitset_new(6);
      }
      bitset_set(bs,pcVar2->id);
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

