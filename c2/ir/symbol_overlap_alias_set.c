c2_bitset * __fastcall symbol_overlap_alias_set(c2_symbol *sym,c2_bitset *mask)

{
  c2_bitset *dst;
  c2_bitset *dst_00;
  c2_symbol *pcVar1;
  
  dst = bitset_new(6);
  pcVar1 = sym->storage;
  if (pcVar1 == (c2_symbol *)0x0) {
    return dst;
  }
  do {
    if (sym == pcVar1) {
LAB_1072c04a:
      dst_00 = bitset_clone(((pcVar1->u30).alias_info)->ref_nodes);
      bitset_and(dst_00,mask);
      bitset_or(dst,dst_00);
      bitset_free(dst_00);
    }
    else if ((sym->offset < pcVar1->size + pcVar1->offset) &&
            (pcVar1->offset < sym->size + sym->offset)) goto LAB_1072c04a;
    pcVar1 = pcVar1->part_next;
    if (pcVar1 == (c2_symbol *)0x0) {
      return dst;
    }
  } while( true );
}

