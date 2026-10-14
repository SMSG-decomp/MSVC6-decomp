void __fastcall symbol_remove_use(c2_symbol *s,void *v)

{
  c2_list_cell *pcVar1;
  c2_list_cell *pcVar2;
  c2_list_cell *pcVar3;
  c2_list_cell *pcVar4;
  
  pcVar1 = s->uses;
  pcVar2 = pcVar1;
  pcVar4 = (c2_list_cell *)0x0;
  if (pcVar1 != (c2_list_cell *)0x0) {
    while (pcVar3 = pcVar2, (pcVar3->u04).tuple != v) {
      pcVar2 = pcVar3->next;
      pcVar4 = pcVar3;
      if (pcVar3->next == (c2_list_cell *)0x0) {
        s->uses = pcVar1;
        return;
      }
    }
    if (pcVar4 == (c2_list_cell *)0x0) {
      s->uses = pcVar3->next;
      return;
    }
    pcVar4->next = pcVar3->next;
  }
  s->uses = pcVar1;
  return;
}

