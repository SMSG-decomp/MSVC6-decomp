int __fastcall param_list_contains(c2_symbol *storage,c2_tuple *entry,int clear_unused)

{
  uint32_t *puVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  
  pcVar2 = entry->src;
  do {
    if (pcVar2 == (c2_operand *)0x0) {
      return 0;
    }
    pcVar3 = pcVar2->sym->storage;
    if (clear_unused == 0) {
      if (pcVar3 == storage) {
        return 1;
      }
    }
    else if (((pcVar3->flags5 & 2) == 0) && ((pcVar3->flags6 & 0x10) == 0)) {
      puVar1 = &pcVar3->fe->attrs;
      *puVar1 = *puVar1 & 0xfffffeff;
    }
    pcVar2 = pcVar2->next;
  } while( true );
}

