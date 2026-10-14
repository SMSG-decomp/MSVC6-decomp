void __fastcall inline_mark_address_taken(c2_tuple *t)

{
  byte bVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  
  for (; t != (c2_tuple *)0x0; t = t->next) {
    if ((t->flags & 1) != 0) {
      for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        bVar1 = pcVar2->kind;
        if (bVar1 == 3) {
          for (pcVar3 = pcVar2->sym->storage; pcVar3 != (c2_symbol *)0x0; pcVar3 = pcVar3->part_next
              ) {
            pcVar3->flags5 = pcVar3->flags5 | 2;
          }
        }
        else if (((4 < bVar1) && (bVar1 < 7)) && (pcVar2->base_sym != (c2_symbol *)0x0)) {
          for (pcVar3 = pcVar2->base_sym->storage; pcVar3 != (c2_symbol *)0x0;
              pcVar3 = pcVar3->part_next) {
            pcVar3->flags5 = pcVar3->flags5 | 2;
          }
        }
      }
    }
  }
  return;
}

