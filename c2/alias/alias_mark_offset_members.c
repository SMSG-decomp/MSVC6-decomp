void __fastcall alias_mark_offset_members(c2_symbol *s,c2_bitvec *v,int off,int size)

{
  int iVar1;
  c2_symbol *pcVar2;
  
  if ((off < 0) || (iVar1 = s->offset, iVar1 < 0)) {
    for (; s != (c2_symbol *)0x0; s = s->part_next) {
      bitvec_set(v,(s->u34).refs);
    }
  }
  else {
    if (size == 0) {
      bitvec_set(v,(s->u34).refs);
      return;
    }
    pcVar2 = s->storage->part_next;
    if (pcVar2 != (c2_symbol *)0x0) {
      do {
        if ((iVar1 <= pcVar2->offset) && (pcVar2->offset < iVar1 + size)) {
          bitvec_set(v,(pcVar2->u34).refs);
        }
        pcVar2 = pcVar2->part_next;
      } while (pcVar2 != (c2_symbol *)0x0);
      return;
    }
  }
  return;
}

