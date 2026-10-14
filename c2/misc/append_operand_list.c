void __fastcall append_operand_list(c2_tuple *t,c2_tuple *t2)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  
  pcVar1 = t->src;
  if (t->src != (c2_operand *)0x0) {
    do {
      pcVar2 = pcVar1;
      pcVar1 = pcVar2->next;
    } while (pcVar2->next != (c2_operand *)0x0);
    if (pcVar2 != (c2_operand *)0x0) {
      pcVar1 = t2->src;
      t2->src = (c2_operand *)0x0;
      pcVar2->next = pcVar1;
      return;
    }
  }
  pcVar1 = t2->src;
  t2->src = (c2_operand *)0x0;
  t->src = pcVar1;
  return;
}

