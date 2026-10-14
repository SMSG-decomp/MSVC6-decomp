c1_u8 __cdecl access_member_through_path(c1_keyed_cell *cell)

{
  byte bVar1;
  c1_keyed_cell *pcVar2;
  c1_keyed_cell *pcVar3;
  byte bVar4;
  
  pcVar2 = cell->key;
  bVar1 = cell->sym->flags2;
  pcVar3 = pcVar2->key;
  bVar4 = bVar1 & 3;
  cell = (c1_keyed_cell *)(bVar1 & 0xffffff03);
  while ((pcVar3 != (c1_keyed_cell *)0x0 && ((pcVar3->sym->kind & 0x1f) == 0xf))) {
    bVar4 = access_compose((byte)cell,pcVar2->sym->flags2 & 3);
    pcVar2 = pcVar2->key;
    cell = (c1_keyed_cell *)(uint)bVar4;
    pcVar3 = pcVar2->key;
  }
  return bVar4;
}

