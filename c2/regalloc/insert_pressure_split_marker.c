c2_tuple * __fastcall
insert_pressure_split_marker(c2_tuple *pos,c2_bitset *bs,c2_bitset *src,c2_bitset *src2)

{
  c2_operand *pcVar1;
  c2_bitset *bs_00;
  c2_tuple *t;
  int iVar2;
  
  if (bs == (c2_bitset *)0x0) {
    bs_00 = bitset_new(6);
  }
  else {
    bs_00 = bitset_clone(bs);
    iVar2 = 0;
    do {
      if (iVar2 == 0) {
        pcVar1 = pos->dst;
      }
      else {
        pcVar1 = pos->src;
      }
      for (; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        if ((pcVar1->kind == '\x01') && (((pcVar1->u18).reg)->cls == '\x02')) {
          bitset_clear(bs_00,((pcVar1->u18).reg)->id);
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 2);
  }
  if (src != (c2_bitset *)0x0) {
    bitset_andnot(bs_00,src);
  }
  if (src2 != (c2_bitset *)0x0) {
    bitset_or(bs_00,src2);
  }
  if (bs_00->chunks != (c2_bitset_chunk *)0x0) {
    t = (c2_tuple *)new_split_marker(bs_00);
    tuple_insert_after(pos,t);
    return t;
  }
  bitset_free(bs_00);
  return (c2_tuple *)0x0;
}

