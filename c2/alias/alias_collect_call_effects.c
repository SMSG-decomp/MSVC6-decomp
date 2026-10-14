c2_alias_call_effect * __fastcall
alias_collect_call_effects
          (c2_alias_intrin_block *blocks,c2_bitset *escaped,uint32_t nsym_bits,c2_symbol **syms)

{
  uint16_t uVar1;
  c2_block *pcVar2;
  c2_bitset *bs;
  c2_operand *pcVar3;
  c2_symbol *pcVar4;
  int iVar5;
  uint32_t n;
  c2_bitset *pcVar6;
  uint uVar7;
  c2_alias_call_effect *pcVar8;
  c2_symbol *pcVar9;
  c2_tuple *local_1c;
  c2_alias_call_effect *local_10;
  c2_alias_intrin_block *local_c;
  uint32_t local_8;
  
  pcVar8 = (c2_alias_call_effect *)0x0;
  local_10 = (c2_alias_call_effect *)0x0;
  local_c = blocks;
  if (blocks == (c2_alias_intrin_block *)0x0) {
    return (c2_alias_call_effect *)0x0;
  }
  do {
    pcVar2 = local_c->block;
    local_8 = local_c->call_bit_end;
    local_1c = pcVar2->end;
    bs = pcVar2->live_out;
    if (local_1c != pcVar2->head) {
      do {
        if ((local_1c->flags & 1) != 0) {
          for (pcVar3 = local_1c->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            if (((pcVar3->kind == '\x02') && (pcVar4 = pcVar3->sym, (pcVar4->u34).refs != 0)) &&
               (pcVar9 = pcVar4->storage, pcVar9 != (c2_symbol *)0x0)) {
              iVar5 = pcVar4->offset;
              do {
                if ((iVar5 <= pcVar9->offset) &&
                   (pcVar9->size + pcVar9->offset <= pcVar4->size + iVar5)) {
                  bitset_clear(bs,(pcVar9->u34).refs);
                }
                pcVar9 = pcVar9->part_next;
              } while (pcVar9 != (c2_symbol *)0x0);
            }
          }
          for (pcVar3 = local_1c->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            if (pcVar3->kind == '\x02') {
              n = (pcVar3->sym->u34).refs;
              if (n != 0) {
                bitset_set(bs,n);
              }
            }
            else if (pcVar3->kind == '\x06') {
              bitset_or(bs,escaped);
            }
          }
          if (local_1c->kind == '\x0e') {
            local_8 = local_8 - 1;
            bitset_set(bs,local_8);
          }
          else {
            if (local_1c->kind != '\x12') goto LAB_1078adf9;
            uVar1 = (local_1c->u20).intrinsic.id;
            if ((uVar1 == 0xdb) || (uVar1 == 0x11e)) {
              pcVar8 = arena_alloc(4,0x14);
              pcVar8->intrin = local_1c;
              pcVar6 = bitset_clone(bs);
              pcVar8->live_across = pcVar6;
              uVar7 = bitset_iter_next(bs);
              while ((uVar7 != 0xffffffff && (uVar7 < nsym_bits))) {
                pcVar4 = syms[uVar7];
                for (pcVar9 = pcVar4->storage; pcVar9 != (c2_symbol *)0x0;
                    pcVar9 = pcVar9->part_next) {
                  if (pcVar4 == pcVar9) {
LAB_1078aeb8:
                    bitset_set(pcVar8->live_across,(pcVar9->u34).refs);
                  }
                  else if ((pcVar4->offset < pcVar9->size + pcVar9->offset) &&
                          (pcVar9->offset < pcVar4->size + pcVar4->offset)) goto LAB_1078aeb8;
                }
                uVar7 = bitset_iter_next((c2_bitset *)0x0);
              }
              pcVar8->next = local_10;
              local_10 = pcVar8;
            }
          }
          bitset_or(bs,escaped);
        }
LAB_1078adf9:
        local_1c = local_1c->prev;
        pcVar8 = local_10;
      } while (local_1c != pcVar2->head);
    }
    local_c = local_c->next;
    if (local_c == (c2_alias_intrin_block *)0x0) {
      return pcVar8;
    }
  } while( true );
}

