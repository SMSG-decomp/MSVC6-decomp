void __fastcall build_stack_object_interference(c2_function *fn)

{
  uint8_t uVar1;
  c2_block *pcVar2;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  c2_symbol_cell **ppcVar6;
  c2_bitset *dst;
  c2_bitset *dst_00;
  c2_bitset *dst_01;
  uint32_t uVar7;
  c2_symbol *pcVar8;
  c2_symbol_cell *pcVar9;
  c2_symbol *pcVar10;
  uint32_t uVar11;
  c2_symbol_cell *pcVar12;
  c2_symbol_cell *pcVar13;
  
  dst = bitset_new(6);
  dst_00 = bitset_new(6);
  dst_01 = bitset_new(6);
  uVar7 = bitset_iter_next(g_stack_param_set);
  while (uVar7 != 0xffffffff) {
    bitset_or(g_stack_interference[uVar7],g_stack_param_set);
    bitset_clear(g_stack_interference[uVar7],uVar7);
    uVar7 = bitset_iter_next((c2_bitset *)0x0);
  }
  pcVar2 = fn->cfg->first;
  do {
    if (pcVar2 == (c2_block *)0x0) {
      bitset_free(dst);
      bitset_free(dst_00);
      bitset_free(dst_01);
      return;
    }
    bitset_copy(dst,pcVar2->kill);
    bitset_assign_andnot(dst_00,pcVar2->set24,pcVar2->ue);
    bitset_assign_andnot(dst_01,pcVar2->set28,(pcVar2->avail_in).set);
    pcVar4 = pcVar2->head;
    for (pcVar3 = pcVar2->end; pcVar3 != pcVar4; pcVar3 = pcVar3->prev) {
      if ((pcVar3->flags & 1) != 0) {
        if ((pcVar3->kind == '\x15') || (pcVar3->kind == '\x0e')) {
          for (pcVar5 = pcVar3->src; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
            uVar1 = pcVar5->kind;
            if (uVar1 == '\x02') {
              uVar7 = (pcVar5->sym->storage->u38).index;
              if ((-1 < (int)uVar7) &&
                 ((uVar11 = bitset_test(dst_00,uVar7), uVar11 == 0 ||
                  ((pcVar5->flags11 & 0x80) == 0)))) {
                bitset_set(dst,uVar7);
              }
            }
            else if ((uVar1 == '\x06') || (uVar1 == '\v')) {
              if (uVar1 == '\x06') {
                pcVar10 = (c2_symbol *)pcVar5->tag;
              }
              else {
                pcVar10 = pcVar5->sym;
              }
              pcVar9 = alias_class_members((uint32_t)pcVar10);
              pcVar12 = (c2_symbol_cell *)0x0;
joined_r0x10726698:
              if (pcVar9 != (c2_symbol_cell *)0x0) {
                do {
                  pcVar10 = pcVar9->sym;
                  pcVar13 = pcVar9;
                  if (pcVar10->cls == '\f') {
                    pcVar13 = (pcVar10->u30).members;
                    pcVar12 = pcVar9;
                    if (pcVar13 == (c2_symbol_cell *)0x0) {
                      pcVar9 = pcVar9->next;
                      goto joined_r0x10726698;
                    }
                    pcVar10 = pcVar13->sym;
                  }
                  if (-1 < (pcVar10->u38).index) {
                    bitset_set(dst,(pcVar10->u38).index);
                  }
                  pcVar9 = pcVar13->next;
                } while (pcVar9 != (c2_symbol_cell *)0x0);
                if (pcVar12 == (c2_symbol_cell *)0x0) goto LAB_107266bc;
                ppcVar6 = &pcVar12->next;
                pcVar12 = (c2_symbol_cell *)0x0;
                pcVar9 = *ppcVar6;
                goto joined_r0x10726698;
              }
            }
LAB_107266bc:
          }
        }
        for (pcVar5 = pcVar3->dst; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
          uVar1 = pcVar5->kind;
          if (uVar1 == '\x02') {
            pcVar10 = pcVar5->sym;
            pcVar8 = pcVar10->storage;
            uVar7 = (pcVar8->u38).index;
            if ((-1 < (int)uVar7) &&
               ((bitset_or(g_stack_interference[uVar7],dst), pcVar10 == pcVar8 ||
                (((pcVar5->flags11 & 0x80) != 0 && (uVar11 = bitset_test(dst_01,uVar7), uVar11 != 0)
                 ))))) {
              bitset_clear(dst,uVar7);
            }
          }
          else if ((uVar1 == '\x06') || (uVar1 == '\v')) {
            if (uVar1 == '\x06') {
              pcVar10 = (c2_symbol *)pcVar5->tag;
            }
            else {
              pcVar10 = pcVar5->sym;
            }
            pcVar9 = alias_class_members((uint32_t)pcVar10);
            pcVar12 = (c2_symbol_cell *)0x0;
joined_r0x10726753:
            if (pcVar9 != (c2_symbol_cell *)0x0) {
              do {
                pcVar8 = pcVar9->sym;
                pcVar13 = pcVar9;
                if (pcVar8->cls == '\f') {
                  pcVar13 = (pcVar8->u30).members;
                  pcVar12 = pcVar9;
                  if (pcVar13 == (c2_symbol_cell *)0x0) {
                    pcVar9 = pcVar9->next;
                    goto joined_r0x10726753;
                  }
                  pcVar8 = pcVar13->sym;
                }
                uVar7 = (pcVar8->u38).index;
                if (-1 < (int)uVar7) {
                  bitset_or(g_stack_interference[uVar7],dst);
                  bitset_set(dst,uVar7);
                }
                pcVar9 = pcVar13->next;
              } while (pcVar9 != (c2_symbol_cell *)0x0);
              if (pcVar12 == (c2_symbol_cell *)0x0) goto LAB_10726780;
              ppcVar6 = &pcVar12->next;
              pcVar12 = (c2_symbol_cell *)0x0;
              pcVar9 = *ppcVar6;
              goto joined_r0x10726753;
            }
LAB_10726780:
            pcVar9 = alias_class_members((uint32_t)pcVar10);
            pcVar12 = (c2_symbol_cell *)0x0;
joined_r0x1072678d:
            if (pcVar9 != (c2_symbol_cell *)0x0) {
              do {
                pcVar10 = pcVar9->sym;
                pcVar13 = pcVar9;
                if (pcVar10->cls == '\f') {
                  pcVar13 = (pcVar10->u30).members;
                  pcVar12 = pcVar9;
                  if (pcVar13 == (c2_symbol_cell *)0x0) {
                    pcVar9 = pcVar9->next;
                    goto joined_r0x1072678d;
                  }
                  pcVar10 = pcVar13->sym;
                }
                uVar7 = (pcVar10->u38).index;
                if ((((-1 < (int)uVar7) && ((pcVar5->flags11 & 0x80) != 0)) &&
                    (uVar11 = bitset_test(dst_01,uVar7), uVar11 != 0)) &&
                   (uVar11 = bitset_test((c2_bitset *)pcVar5->rank,uVar7), uVar11 != 0)) {
                  bitset_clear(dst,uVar7);
                }
                pcVar9 = pcVar13->next;
              } while (pcVar9 != (c2_symbol_cell *)0x0);
              if (pcVar12 == (c2_symbol_cell *)0x0) goto LAB_107267ba;
              ppcVar6 = &pcVar12->next;
              pcVar12 = (c2_symbol_cell *)0x0;
              pcVar9 = *ppcVar6;
              goto joined_r0x1072678d;
            }
LAB_107267ba:
            if ((pcVar5->flags11 & 0x80) != 0) {
              bitset_free((c2_bitset *)pcVar5->rank);
            }
          }
        }
        for (pcVar5 = pcVar3->src; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
          uVar1 = pcVar5->kind;
          if (uVar1 == '\x02') {
            uVar7 = (pcVar5->sym->storage->u38).index;
            if ((-1 < (int)uVar7) &&
               ((uVar11 = bitset_test(dst_00,uVar7), uVar11 == 0 || ((pcVar5->flags11 & 0x80) == 0))
               )) {
              bitset_set(dst,uVar7);
            }
          }
          else if ((uVar1 == '\x06') || (uVar1 == '\v')) {
            if (uVar1 == '\x06') {
              pcVar10 = (c2_symbol *)pcVar5->tag;
            }
            else {
              pcVar10 = pcVar5->sym;
            }
            pcVar9 = alias_class_members((uint32_t)pcVar10);
            pcVar12 = (c2_symbol_cell *)0x0;
joined_r0x10726987:
            if (pcVar9 != (c2_symbol_cell *)0x0) {
              do {
                pcVar10 = pcVar9->sym;
                pcVar13 = pcVar9;
                if (pcVar10->cls == '\f') {
                  pcVar13 = (pcVar10->u30).members;
                  pcVar12 = pcVar9;
                  if (pcVar13 == (c2_symbol_cell *)0x0) {
                    pcVar9 = pcVar9->next;
                    goto joined_r0x10726987;
                  }
                  pcVar10 = pcVar13->sym;
                }
                uVar7 = (pcVar10->u38).index;
                if ((-1 < (int)uVar7) &&
                   (((uVar11 = bitset_test(dst_00,uVar7), uVar11 == 0 ||
                     ((pcVar5->flags11 & 0x80) == 0)) ||
                    (uVar11 = bitset_test((c2_bitset *)pcVar5->rank,uVar7), uVar11 == 0)))) {
                  bitset_set(dst,uVar7);
                }
                pcVar9 = pcVar13->next;
              } while (pcVar9 != (c2_symbol_cell *)0x0);
              if (pcVar12 == (c2_symbol_cell *)0x0) goto LAB_107269ac;
              ppcVar6 = &pcVar12->next;
              pcVar12 = (c2_symbol_cell *)0x0;
              pcVar9 = *ppcVar6;
              goto joined_r0x10726987;
            }
LAB_107269ac:
            if ((pcVar5->flags11 & 0x80) != 0) {
              bitset_free((c2_bitset *)pcVar5->rank);
            }
          }
        }
      }
    }
    bitset_free(pcVar2->ue);
    bitset_free(pcVar2->kill);
    bitset_free((pcVar2->avail_in).set);
    bitset_free((pcVar2->avail_out).set);
    bitset_free(pcVar2->set24);
    bitset_free(pcVar2->set28);
    bitset_free(pcVar2->de);
    pcVar2 = pcVar2->next;
  } while( true );
}

