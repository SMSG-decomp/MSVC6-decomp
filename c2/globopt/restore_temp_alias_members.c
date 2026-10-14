void __fastcall restore_temp_alias_members(uint32_t cls,c2_bitset *set,c2_bitset *clear)

{
  c2_symbol_cell **ppcVar1;
  c2_symbol_cell *pcVar2;
  uint32_t uVar3;
  c2_symbol_cell *pcVar4;
  c2_symbol *pcVar5;
  c2_symbol_cell *pcVar6;
  
  pcVar2 = alias_class_members(cls);
  pcVar4 = (c2_symbol_cell *)0x0;
joined_r0x10710cf2:
  do {
    if (pcVar2 == (c2_symbol_cell *)0x0) {
      return;
    }
    do {
      pcVar5 = pcVar2->sym;
      pcVar6 = pcVar2;
      if (pcVar5->cls == '\f') {
        pcVar6 = (pcVar5->u30).members;
        pcVar4 = pcVar2;
        if (pcVar6 == (c2_symbol_cell *)0x0) {
          pcVar2 = pcVar2->next;
          goto joined_r0x10710cf2;
        }
        pcVar5 = pcVar6->sym;
      }
      if (pcVar5->def == (c2_tuple *)0x0) {
        uVar3 = bitset_test(set,pcVar5->id);
      }
      else {
        uVar3 = (uint32_t)(pcVar5->u30).globopt.live;
      }
      if (uVar3 == 0) {
        bitset_set(set,pcVar5->id);
      }
      for (pcVar5 = pcVar5->storage; pcVar5 != (c2_symbol *)0x0; pcVar5 = pcVar5->part_next) {
        bitset_clear(clear,pcVar5->id);
      }
      pcVar2 = pcVar6->next;
    } while (pcVar2 != (c2_symbol_cell *)0x0);
    if (pcVar4 == (c2_symbol_cell *)0x0) {
      return;
    }
    ppcVar1 = &pcVar4->next;
    pcVar4 = (c2_symbol_cell *)0x0;
    pcVar2 = *ppcVar1;
  } while( true );
}

