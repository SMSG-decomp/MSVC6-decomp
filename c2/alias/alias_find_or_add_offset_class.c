c2_symbol * __fastcall alias_find_or_add_offset_class(c2_symbol *s,int off)

{
  c2_symbol *pcVar1;
  c2_symbol *pcVar2;
  c2_symbol *pcVar3;
  
  pcVar1 = (s->u30).order_prev;
  pcVar3 = pcVar1->part_next;
  if (pcVar3 == (c2_symbol *)0x0) {
    pcVar3 = alias_new_class_record();
    pcVar3->storage = pcVar3;
    pcVar3->offset = -1;
    pcVar1->part_next = pcVar3;
    pcVar2 = alias_new_class_record();
    pcVar3 = pcVar1->part_next;
    pcVar2->storage = pcVar3;
    pcVar3->part_next = pcVar2;
  }
  pcVar1 = (c2_symbol *)0x0;
  pcVar2 = pcVar3;
  while( true ) {
    if (pcVar2 == (c2_symbol *)0x0) {
      pcVar2 = alias_new_class_record();
      pcVar2->storage = pcVar3;
      pcVar2->offset = off;
      pcVar1->part_next = pcVar2;
      return pcVar2;
    }
    if (pcVar2->offset == off) break;
    pcVar1 = pcVar2;
    pcVar2 = pcVar2->part_next;
  }
  return pcVar2;
}

