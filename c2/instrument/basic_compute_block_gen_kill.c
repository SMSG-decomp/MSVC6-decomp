void __fastcall basic_compute_block_gen_kill(c2_function *fn,uint32_t nbits)

{
  uint8_t uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  c2_symbol *pcVar5;
  uint32_t uVar6;
  c2_block *pcVar7;
  c2_bitset *pcVar8;
  c2_bitset *v;
  c2_symbol_cell *pcVar9;
  c2_symbol *pcVar10;
  uint32_t alias_class;
  c2_symbol_cell *pcVar11;
  c2_symbol_cell *pcVar12;
  
  pcVar7 = fn->cfg->first;
  do {
    if (pcVar7 == (c2_block *)0x0) {
      return;
    }
    pcVar8 = (c2_bitset *)bitvec_new(6,nbits);
    pcVar7->ue = pcVar8;
    v = (c2_bitset *)bitvec_new(6,nbits);
    pcVar2 = pcVar7->head;
    pcVar7->kill = v;
    for (pcVar3 = pcVar7->end; pcVar3 != pcVar2; pcVar3 = pcVar3->prev) {
      if ((pcVar3->flags & 1) != 0) {
        for (pcVar4 = pcVar3->dst; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if (pcVar4->kind == '\x02') {
            pcVar10 = pcVar4->sym;
            pcVar5 = pcVar10->storage;
            uVar6 = (pcVar5->u34).refs;
            if (uVar6 != 0) {
              if (pcVar10 != pcVar5) {
                if ((pcVar5->offset < pcVar10->offset) ||
                   (pcVar10->size + pcVar10->offset < pcVar5->size + pcVar5->offset))
                goto LAB_10794ed8;
              }
              bitvec_clear((c2_bitvec *)pcVar8,uVar6);
              bitvec_set((c2_bitvec *)v,uVar6);
            }
          }
LAB_10794ed8:
        }
        for (pcVar4 = pcVar3->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          uVar1 = pcVar4->kind;
          if (uVar1 == '\x02') {
            uVar6 = (pcVar4->sym->storage->u34).refs;
            if (uVar6 != 0) {
              bitvec_set((c2_bitvec *)pcVar8,uVar6);
            }
          }
          else if ((uVar1 == '\x06') || (uVar1 == '\v')) {
            if (uVar1 == '\x06') {
              alias_class = pcVar4->tag;
            }
            else {
              alias_class = (uint32_t)pcVar4->sym;
            }
            pcVar9 = alias_class_members(alias_class);
            pcVar12 = (c2_symbol_cell *)0x0;
joined_r0x10794f22:
            if (pcVar9 != (c2_symbol_cell *)0x0) {
              do {
                pcVar10 = pcVar9->sym;
                pcVar11 = pcVar9;
                if (pcVar10->cls == '\f') {
                  pcVar11 = (pcVar10->u30).members;
                  pcVar12 = pcVar9;
                  if (pcVar11 == (c2_symbol_cell *)0x0) {
                    pcVar9 = pcVar9->next;
                    goto joined_r0x10794f22;
                  }
                  pcVar10 = pcVar11->sym;
                }
                if ((pcVar10->u34).refs != 0) {
                  bitvec_set((c2_bitvec *)pcVar8,(pcVar10->u34).refs);
                }
                pcVar9 = pcVar11->next;
              } while (pcVar9 != (c2_symbol_cell *)0x0);
              if (pcVar12 == (c2_symbol_cell *)0x0) goto LAB_10794f3c;
              pcVar9 = pcVar12->next;
              pcVar12 = (c2_symbol_cell *)0x0;
              goto joined_r0x10794f22;
            }
          }
LAB_10794f3c:
        }
      }
    }
    pcVar8 = (c2_bitset *)bitvec_clone((c2_bitvec *)pcVar8);
    pcVar7->live_in = pcVar8;
    pcVar8 = (c2_bitset *)bitvec_new(6,nbits);
    pcVar7->live_out = pcVar8;
    pcVar7->flags = pcVar7->flags & 0xfffffffe;
    pcVar7 = pcVar7->next;
  } while( true );
}

