int __fastcall inline_unbind_written_formals(c2_tuple *entry,int count)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  
  for (pcVar1 = entry->next; pcVar1 != (c2_tuple *)0x0; pcVar1 = pcVar1->next) {
    if (((pcVar1->flags & 1) != 0) && (pcVar1->op != 0x17d)) {
      for (pcVar2 = pcVar1->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if (((pcVar2->kind == '\x02') && (pcVar2->sym->cls == '\x05')) &&
           (pcVar3 = pcVar2->sym->storage, pcVar3->order_next != (c2_symbol *)0x0)) {
          pcVar3->order_next = (c2_symbol *)0x0;
          count = count + -1;
        }
      }
      for (pcVar2 = pcVar1->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if (((pcVar2->kind == '\x03') && (pcVar2->sym->cls == '\x05')) &&
           (pcVar3 = pcVar2->sym->storage, pcVar3->order_next != (c2_symbol *)0x0)) {
          pcVar3->order_next = (c2_symbol *)0x0;
          count = count + -1;
        }
      }
    }
  }
  return count;
}

