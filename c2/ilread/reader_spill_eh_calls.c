void __fastcall reader_spill_eh_calls(c2_tuple *t,c2_reader_cell *cell)

{
  byte bVar1;
  c2_operand *pcVar2;
  uint uVar3;
  c2_operand *pcVar4;
  c2_tuple *pcVar5;
  
  bVar1 = t->kind;
  while (uVar3 = 1 << (bVar1 & 0x1f), (uVar3 & 0xffe) != 0) {
    if ((uVar3 & 6) == 0) {
      return;
    }
    t = ((t->u14).expr)->def;
    if (t == (c2_tuple *)0x0) {
      return;
    }
    bVar1 = t->kind;
  }
  if (t->kind != '\x0e') {
    pcVar2 = t->src;
    while (pcVar4 = pcVar2, pcVar4 != (c2_operand *)0x0) {
      pcVar2 = pcVar4->next;
      if (((1 << (pcVar4->kind & 0x1f) & 6U) != 0) &&
         (pcVar5 = pcVar4->sym->def, pcVar5 != (c2_tuple *)0x0)) {
        reader_spill_eh_calls(pcVar5,cell);
      }
    }
    return;
  }
  reader_spill_eh_value(t);
  if (cell->tail == t) {
    pcVar5 = (c2_tuple *)node_clone((c2_node *)t->dst);
    tuple_splice_after(t,pcVar5);
    cell->tail = t->next;
    return;
  }
  pcVar5 = (c2_tuple *)list_last((c2_link *)t);
  cell->tail = pcVar5;
  return;
}

