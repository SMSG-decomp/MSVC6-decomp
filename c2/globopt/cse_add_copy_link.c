void __fastcall cse_add_copy_link(c2_symbol *a,c2_symbol *b)

{
  c2_copy_link *pcVar1;
  c2_symbol_u38 cVar2;
  c2_copy_link *pcVar3;
  c2_bitset *pcVar4;
  
  pcVar1 = (a->u34).source_links;
  pcVar3 = pcVar1;
  while( true ) {
    if (pcVar3 == (c2_copy_link *)0x0) {
      pcVar3 = arena_alloc(0xd,0x10);
      cVar2 = b->u38;
      pcVar3->copy = b;
      pcVar3->next_of_source = pcVar1;
      (a->u34).source_links = pcVar3;
      pcVar3->source = a;
      pcVar3->next_of_copy = (c2_copy_link *)cVar2;
      (b->u38).copy_links = pcVar3;
      if (b->dependents == (c2_bitset *)0x0) {
        pcVar4 = bitset_new(0xd);
        b->dependents = pcVar4;
        bitset_set(pcVar4,b->id);
      }
      if (a->dependents == (c2_bitset *)0x0) {
        pcVar4 = bitset_new(0xd);
        a->dependents = pcVar4;
        bitset_set(pcVar4,a->id);
      }
      propagate_kill_sets(b);
      return;
    }
    if (pcVar3->copy == b) break;
    pcVar3 = pcVar3->next_of_source;
  }
  return;
}

