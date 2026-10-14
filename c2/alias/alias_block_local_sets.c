c2_alias_intrin_block * __fastcall
alias_block_local_sets
          (c2_block *first,uint32_t first_call_bit,c2_bitset *escaped,c2_symbol **syms,
          c2_bitset *unwritten_params)

{
  uint16_t uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  uint32_t uVar5;
  int iVar6;
  c2_symbol *pcVar7;
  c2_bitset *escaped_live;
  c2_bitset *block_de;
  c2_bitset *block_ue;
  c2_bitset *block_kill;
  uint32_t uVar8;
  c2_alias_intrin_block *pcVar9;
  c2_symbol *pcVar10;
  c2_alias_intrin_block *intrin_blocks;
  uint32_t call_bit;
  c2_symbol_chunk *chunk;
  
  for (chunk = g_symbol_chunks; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    pcVar10 = chunk->cursor;
    for (pcVar7 = chunk->syms; pcVar7 < pcVar10; pcVar7 = pcVar7 + 1) {
      if ((pcVar7->cls != '\x10') && ((pcVar7->u34).refs != 0)) {
        syms[(pcVar7->u34).refs] = pcVar7;
      }
    }
  }
  escaped_live = bitset_new(6);
  pcVar9 = (c2_alias_intrin_block *)0x0;
  intrin_blocks = (c2_alias_intrin_block *)0x0;
  call_bit = first_call_bit;
  do {
    if (first == (c2_block *)0x0) {
      bitset_free(escaped_live);
      return pcVar9;
    }
    block_de = bitset_new(6);
    first->de = block_de;
    block_ue = bitset_new(6);
    first->ue = block_ue;
    block_kill = bitset_new(6);
    pcVar2 = first->end;
    first->kill = block_kill;
    for (pcVar3 = first->head; pcVar3 != pcVar2; pcVar3 = pcVar3->next) {
      if ((pcVar3->flags & 1) != 0) {
        for (pcVar4 = pcVar3->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if (pcVar4->kind == '\x02') {
            uVar5 = (pcVar4->sym->u34).refs;
            if (uVar5 != 0) {
              bitset_set(block_de,uVar5);
              uVar8 = bitset_test(block_kill,uVar5);
              if (uVar8 == 0) {
                bitset_set(block_ue,uVar5);
              }
            }
          }
          else if (pcVar4->kind == '\x06') {
            bitset_or(block_de,escaped);
            bitset_copy(escaped_live,escaped);
            bitset_andnot(escaped_live,block_kill);
            bitset_or(block_ue,escaped_live);
          }
          pcVar9 = intrin_blocks;
        }
        for (pcVar4 = pcVar3->dst; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if (pcVar4->kind == '\x02') {
            pcVar7 = pcVar4->sym;
            uVar5 = (pcVar7->u34).refs;
            if (uVar5 != 0) {
              pcVar10 = pcVar7->storage;
              if (pcVar10 != (c2_symbol *)0x0) {
                iVar6 = pcVar7->offset;
                do {
                  if ((iVar6 <= pcVar10->offset) &&
                     (pcVar10->size + pcVar10->offset <= pcVar7->size + iVar6)) {
                    uVar8 = (pcVar10->u34).refs;
                    bitset_set(block_kill,uVar8);
                    bitset_clear(block_de,uVar8);
                  }
                  bitset_clear(unwritten_params,(pcVar10->u34).refs);
                  pcVar10 = pcVar10->part_next;
                } while (pcVar10 != (c2_symbol *)0x0);
              }
              bitset_set(block_de,uVar5);
            }
          }
          pcVar9 = intrin_blocks;
        }
        if (pcVar3->kind == '\x0e') {
          bitset_set(block_ue,call_bit);
          call_bit = call_bit + 1;
        }
        else {
          if (pcVar3->kind != '\x12') goto LAB_1078ac2a;
          uVar1 = (pcVar3->u20).intrinsic.id;
          if (((uVar1 == 0xdb) || (uVar1 == 0x11e)) &&
             ((pcVar9 == (c2_alias_intrin_block *)0x0 || (pcVar9->block != first)))) {
            intrin_blocks = arena_alloc(4,0xc);
            intrin_blocks->next = pcVar9;
            intrin_blocks->block = first;
          }
        }
        bitset_or(block_de,escaped);
        bitset_copy(escaped_live,escaped);
        bitset_andnot(escaped_live,block_kill);
        bitset_or(block_ue,escaped_live);
      }
LAB_1078ac2a:
      pcVar9 = intrin_blocks;
    }
    if ((pcVar9 != (c2_alias_intrin_block *)0x0) && (pcVar9->block == first)) {
      pcVar9->call_bit_end = call_bit;
    }
    first = first->next;
  } while( true );
}

