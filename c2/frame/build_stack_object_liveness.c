void __fastcall build_stack_object_liveness(c2_function *fn)

{
  uint8_t uVar1;
  c2_cfg *pcVar2;
  c2_block *pcVar3;
  c2_tuple *pcVar4;
  c2_tuple *pcVar5;
  c2_operand *pcVar6;
  c2_symbol *pcVar7;
  c2_edge *pcVar8;
  bool bVar9;
  c2_symbol_cell **ppcVar10;
  byte bVar11;
  c2_bitset *bs;
  c2_bitset *pcVar12;
  c2_bitset *pcVar13;
  c2_bitset *bs_00;
  c2_bitset *dst;
  c2_bitset *bs_01;
  uint32_t uVar14;
  c2_symbol_cell *pcVar15;
  c2_symbol *pcVar16;
  uint32_t uVar17;
  c2_bitset *pcVar18;
  int iVar19;
  c2_symbol_cell *pcVar20;
  c2_symbol_cell *pcVar21;
  c2_block *pcVar22;
  c2_block *pcVar23;
  
  bs = bitset_new(6);
  pcVar2 = fn->cfg;
  pcVar3 = pcVar2->first;
  for (pcVar23 = pcVar3; pcVar23 != (c2_block *)0x0; pcVar23 = pcVar23->next) {
    pcVar12 = bitset_new(6);
    pcVar23->ue = pcVar12;
    pcVar13 = bitset_new(6);
    pcVar23->kill = pcVar13;
    pcVar13 = bitset_new(6);
    (pcVar23->avail_in).set = pcVar13;
    pcVar13 = bitset_new(6);
    (pcVar23->avail_out).set = pcVar13;
    bs_00 = bitset_new(6);
    pcVar23->set24 = bs_00;
    dst = bitset_new(6);
    pcVar23->set28 = dst;
    bs_01 = bitset_new(6);
    pcVar23->de = bs_01;
    if (pcVar23 == pcVar3) {
      bitset_copy(pcVar12,g_stack_param_set);
      bitset_copy(dst,g_stack_param_set);
    }
    pcVar5 = pcVar23->end;
    for (pcVar4 = pcVar23->head; pcVar4 != pcVar5; pcVar4 = pcVar4->next) {
      if ((pcVar4->flags & 1) != 0) {
        for (pcVar6 = pcVar4->src; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
          uVar1 = pcVar6->kind;
          if (uVar1 == '\x02') {
            uVar14 = (pcVar6->sym->storage->u38).index;
            if ((-1 < (int)uVar14) && (uVar17 = bitset_test(bs_01,uVar14), uVar17 == 0)) {
              bitset_set(bs_00,uVar14);
              uVar14 = bitset_test(dst,uVar14);
              if (uVar14 == 0) {
                bVar11 = pcVar6->flags11 | 0x80;
              }
              else {
                bVar11 = pcVar6->flags11 & 0x7f;
              }
              pcVar6->flags11 = bVar11;
            }
          }
          else if ((uVar1 == '\x06') || (uVar1 == '\v')) {
            if (uVar1 == '\x06') {
              pcVar16 = (c2_symbol *)pcVar6->tag;
            }
            else {
              pcVar16 = pcVar6->sym;
            }
            pcVar6->flags11 = pcVar6->flags11 & 0x7f;
            pcVar15 = alias_class_members((uint32_t)pcVar16);
            pcVar20 = (c2_symbol_cell *)0x0;
joined_r0x107261ae:
            if (pcVar15 != (c2_symbol_cell *)0x0) {
              do {
                pcVar16 = pcVar15->sym;
                pcVar21 = pcVar15;
                if (pcVar16->cls == '\f') {
                  pcVar21 = (pcVar16->u30).members;
                  pcVar20 = pcVar15;
                  if (pcVar21 == (c2_symbol_cell *)0x0) {
                    pcVar15 = pcVar15->next;
                    goto joined_r0x107261ae;
                  }
                  pcVar16 = pcVar21->sym;
                }
                uVar14 = (pcVar16->u38).index;
                if ((-1 < (int)uVar14) && (uVar17 = bitset_test(bs_01,uVar14), uVar17 == 0)) {
                  bitset_set(bs_00,uVar14);
                  uVar17 = bitset_test(dst,uVar14);
                  if (uVar17 == 0) {
                    if ((pcVar6->flags11 & 0x80) == 0) {
                      pcVar6->flags11 = pcVar6->flags11 | 0x80;
                      pcVar18 = bitset_new(6);
                      pcVar6->rank = (uint32_t)pcVar18;
                    }
                    bitset_set((c2_bitset *)pcVar6->rank,uVar14);
                  }
                }
                pcVar15 = pcVar21->next;
              } while (pcVar15 != (c2_symbol_cell *)0x0);
              if (pcVar20 == (c2_symbol_cell *)0x0) goto LAB_10726304;
              ppcVar10 = &pcVar20->next;
              pcVar20 = (c2_symbol_cell *)0x0;
              pcVar15 = *ppcVar10;
              goto joined_r0x107261ae;
            }
          }
LAB_10726304:
        }
        for (pcVar6 = pcVar4->dst; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
          uVar1 = pcVar6->kind;
          if (uVar1 == '\x02') {
            pcVar16 = pcVar6->sym;
            pcVar7 = pcVar16->storage;
            uVar14 = (pcVar7->u38).index;
            if (-1 < (int)uVar14) {
              uVar17 = bitset_test(dst,uVar14);
              if (uVar17 == 0) {
                pcVar6->flags11 = pcVar6->flags11 | 0x80;
                bitset_set(dst,uVar14);
              }
              else {
                pcVar6->flags11 = pcVar6->flags11 & 0x7f;
              }
              if ((pcVar7 == pcVar16) && (uVar17 = bitset_test(bs_00,uVar14), uVar17 == 0)) {
                bitset_set(bs_01,uVar14);
              }
            }
          }
          else if ((uVar1 == '\x06') || (uVar1 == '\v')) {
            if (uVar1 == '\x06') {
              pcVar16 = (c2_symbol *)pcVar6->tag;
            }
            else {
              pcVar16 = pcVar6->sym;
            }
            pcVar6->flags11 = pcVar6->flags11 & 0x7f;
            pcVar15 = alias_class_members((uint32_t)pcVar16);
            pcVar20 = (c2_symbol_cell *)0x0;
joined_r0x10726331:
            if (pcVar15 != (c2_symbol_cell *)0x0) {
              do {
                pcVar16 = pcVar15->sym;
                pcVar21 = pcVar15;
                if (pcVar16->cls == '\f') {
                  pcVar21 = (pcVar16->u30).members;
                  pcVar20 = pcVar15;
                  if (pcVar21 == (c2_symbol_cell *)0x0) {
                    pcVar15 = pcVar15->next;
                    goto joined_r0x10726331;
                  }
                  pcVar16 = pcVar21->sym;
                }
                uVar14 = (pcVar16->u38).index;
                if ((-1 < (int)uVar14) && (uVar17 = bitset_test(dst,uVar14), uVar17 == 0)) {
                  bitset_set(dst,uVar14);
                  if ((pcVar6->flags11 & 0x80) == 0) {
                    pcVar6->flags11 = pcVar6->flags11 | 0x80;
                    pcVar18 = bitset_new(6);
                    pcVar6->rank = (uint32_t)pcVar18;
                  }
                  bitset_set((c2_bitset *)pcVar6->rank,uVar14);
                }
                pcVar15 = pcVar21->next;
              } while (pcVar15 != (c2_symbol_cell *)0x0);
              if (pcVar20 == (c2_symbol_cell *)0x0) goto LAB_107262b0;
              ppcVar10 = &pcVar20->next;
              pcVar20 = (c2_symbol_cell *)0x0;
              pcVar15 = *ppcVar10;
              goto joined_r0x10726331;
            }
          }
LAB_107262b0:
        }
      }
    }
    bitset_copy(pcVar12,bs_00);
    bitset_copy(pcVar13,dst);
  }
  pcVar23 = pcVar2->last;
  do {
    bVar9 = false;
    pcVar22 = pcVar23;
    if (pcVar23 == (c2_block *)0x0) break;
    do {
      bitset_clear_all(bs);
      for (pcVar8 = pcVar22->succs; pcVar8 != (c2_edge *)0x0; pcVar8 = pcVar8->next_succ) {
        bitset_or(bs,pcVar8->to->ue);
      }
      pcVar12 = pcVar22->kill;
      iVar19 = bitset_equal(bs,pcVar12);
      if (iVar19 == 0) {
        bVar9 = true;
        bitset_copy(pcVar12,bs);
        bitset_assign_diff_union(pcVar22->ue,pcVar12,pcVar22->de,pcVar22->set24);
      }
      pcVar22 = pcVar22->prev;
    } while (pcVar22 != (c2_block *)0x0);
  } while (bVar9);
  do {
    bVar9 = false;
    pcVar23 = pcVar3;
    if (pcVar3 == (c2_block *)0x0) break;
    do {
      bitset_clear_all(bs);
      for (pcVar8 = pcVar23->preds; pcVar8 != (c2_edge *)0x0; pcVar8 = pcVar8->next_pred) {
        bitset_or(bs,(pcVar8->from->avail_out).set);
      }
      pcVar12 = (pcVar23->avail_in).set;
      iVar19 = bitset_equal(bs,pcVar12);
      if (iVar19 == 0) {
        bVar9 = true;
        bitset_copy(pcVar12,bs);
        bitset_assign_or((pcVar23->avail_out).set,pcVar12,pcVar23->set28);
      }
      pcVar23 = pcVar23->next;
    } while (pcVar23 != (c2_block *)0x0);
  } while (bVar9);
  for (; pcVar3 != (c2_block *)0x0; pcVar3 = pcVar3->next) {
    bitset_and(pcVar3->ue,(pcVar3->avail_in).set);
    bitset_and(pcVar3->kill,(pcVar3->avail_out).set);
  }
  bitset_free(bs);
  return;
}

