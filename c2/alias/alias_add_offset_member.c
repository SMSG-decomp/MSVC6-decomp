void __fastcall alias_add_offset_member(c2_symbol *cls,int off)

{
  c2_symbol *pcVar1;
  c2_symbol *pcVar2;
  c2_symbol *pcVar3;
  c2_symbol *pcVar4;
  
  pcVar1 = cls->storage;
  pcVar4 = pcVar1;
  pcVar3 = (c2_symbol *)0x0;
  while( true ) {
    pcVar2 = pcVar4;
    if (pcVar2 == (c2_symbol *)0x0) {
      pcVar4 = arena_alloc(4,0x54);
      pcVar4->cls = '\x0e';
      (pcVar4->u34).refs = g_alias_symbol_number_count;
      g_alias_symbol_number_count = g_alias_symbol_number_count + 1;
      pcVar4->storage = pcVar1;
      pcVar4->offset = off;
      pcVar3->part_next = pcVar4;
      return;
    }
    if (pcVar2->offset == off) break;
    pcVar4 = pcVar2->part_next;
    pcVar3 = pcVar2;
  }
  return;
}

