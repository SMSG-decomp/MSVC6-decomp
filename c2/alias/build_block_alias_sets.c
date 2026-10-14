c2_alias_ref * __fastcall build_block_alias_sets(c2_block *first,uint32_t nfixed,uint32_t nrefs)

{
  c2_bitset *src;
  c2_operand *pcVar1;
  c2_block *pcVar2;
  c2_alias_ref *refs;
  c2_tuple *pcVar3;
  c2_bitset *de_nodes;
  c2_bitset *kill_nodes;
  c2_symbol *pcVar4;
  c2_alias_ref *row;
  int iVar5;
  uint32_t uVar6;
  c2_symbol *pcVar7;
  c2_symbol_chunk *chunk;
  
  refs = arena_alloc(4,nrefs * 0x14);
  for (pcVar2 = first; pcVar2 != (c2_block *)0x0; pcVar2 = pcVar2->next) {
    de_nodes = bitset_new(6);
    pcVar2->de = de_nodes;
    kill_nodes = bitset_new(6);
    pcVar2->kill = kill_nodes;
    if ((pcVar2 == first) && (uVar6 = 1, 1 < nfixed)) {
      do {
        bitset_set(de_nodes,uVar6);
        uVar6 = uVar6 + 1;
      } while (uVar6 < nfixed);
    }
    pcVar3 = pcVar2->head;
    while( true ) {
      if ((pcVar3->flags & 1) != 0) {
        for (pcVar1 = pcVar3->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
          if (pcVar1->rank != 0) {
            pcVar4 = pcVar1->sym;
            pcVar7 = pcVar4->storage;
            if (pcVar7 != (c2_symbol *)0x0) {
              iVar5 = pcVar4->offset;
              do {
                if ((iVar5 <= pcVar7->offset) &&
                   (pcVar7->size + pcVar7->offset <= pcVar4->size + iVar5)) {
                  src = ((pcVar7->u30).alias_info)->ref_nodes;
                  bitset_andnot(de_nodes,src);
                  bitset_or(kill_nodes,src);
                }
                pcVar7 = pcVar7->part_next;
              } while (pcVar7 != (c2_symbol *)0x0);
            }
            uVar6 = pcVar1->rank;
            bitset_set(de_nodes,uVar6);
            refs[uVar6].def = pcVar3;
            refs[uVar6].sym = pcVar4;
          }
        }
      }
      if (pcVar3 == pcVar2->end) break;
      pcVar3 = pcVar3->next;
    }
  }
  solve_availability(first,0);
  iVar5 = 1;
  for (chunk = g_symbol_chunks; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    pcVar7 = chunk->cursor;
    pcVar4 = chunk->syms;
    if (pcVar4 < pcVar7) {
      row = refs + iVar5;
      do {
        if ((pcVar4->cls != '\x10') && ((pcVar4->flags5 & 8) != 0)) {
          row->sym = pcVar4;
          iVar5 = iVar5 + 1;
          row = row + 1;
        }
        pcVar4 = pcVar4 + 1;
      } while (pcVar4 < pcVar7);
    }
  }
  return refs;
}

