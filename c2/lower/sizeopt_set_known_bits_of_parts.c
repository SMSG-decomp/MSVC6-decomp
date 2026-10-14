void __fastcall sizeopt_set_known_bits_of_parts(c2_tuple *t,int bits)

{
  ushort uVar1;
  int iVar2;
  c2_symbol *pcVar3;
  
  pcVar3 = t->dst->sym->storage;
  if (pcVar3 != (c2_symbol *)0x0) {
    uVar1 = t->dst->type;
    do {
      iVar2 = (uVar1 & 0xfff) - pcVar3->size;
      if ((pcVar3->offset == 0) && (-1 < iVar2)) {
        iVar2 = bits + iVar2 * -8;
        (pcVar3->u30).globopt.live = (iVar2 < 1) - 1U & (byte)iVar2;
      }
      pcVar3 = pcVar3->part_next;
    } while (pcVar3 != (c2_symbol *)0x0);
  }
  return;
}

