void __fastcall basic_mark_live_across_calls(c2_function *fn,uint32_t nbits,c2_bitvec **rows)

{
  c2_bitset *v;
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_symbol *pcVar4;
  uint32_t n;
  bool bVar5;
  c2_block *pcVar6;
  c2_bitvec *vec;
  int iVar7;
  c2_symbol_cell *pcVar8;
  c2_symbol *pcVar9;
  c2_symbol_cell *pcVar10;
  c2_symbol_cell *pcVar11;
  
  vec = bitvec_new(6,nbits);
  pcVar6 = fn->cfg->first;
  do {
    if (pcVar6 == (c2_block *)0x0) {
      return;
    }
    bitvec_copy(vec,(c2_bitvec *)pcVar6->live_out);
    v = (pcVar6->avail_in).set;
    iVar7 = bitvec_is_empty((c2_bitvec *)v);
    if (iVar7 == 0) {
      for (pcVar1 = pcVar6->head; (pcVar1 != pcVar6->end && (pcVar1->op != 0x19b));
          pcVar1 = pcVar1->next) {
      }
      if (pcVar1->op == 0x19b) goto LAB_10795433;
      bVar5 = false;
      bitvec_or_selected_rows(vec,(c2_bitvec *)v,rows);
    }
    else {
LAB_10795433:
      bVar5 = true;
    }
    pcVar2 = pcVar6->head;
    for (pcVar1 = pcVar6->end; pcVar1 != pcVar2; pcVar1 = pcVar1->prev) {
      if ((pcVar1->flags & 1) != 0) {
        if (pcVar1->op == 0x19b) {
          iVar7 = bitvec_is_empty((c2_bitvec *)v);
          if (iVar7 == 0) {
            bVar5 = false;
            bitvec_or_selected_rows(vec,(c2_bitvec *)v,rows);
          }
        }
        else {
          for (pcVar3 = pcVar1->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            if (pcVar3->kind == '\x02') {
              pcVar9 = pcVar3->sym;
              pcVar4 = pcVar9->storage;
              n = (pcVar4->u34).refs;
              if (n != 0) {
                iVar7 = bitvec_test(vec,n);
                if (iVar7 != 0) {
                  pcVar3->flags11 = pcVar3->flags11 | 8;
                }
                if (bVar5) {
                  if (pcVar9 != pcVar4) {
                    if ((pcVar4->offset < pcVar9->offset) ||
                       (pcVar9->size + pcVar9->offset < pcVar4->size + pcVar4->offset))
                    goto LAB_1079547e;
                  }
                  bitvec_clear(vec,n);
                }
              }
            }
            else if (pcVar3->kind == '\x06') {
              pcVar8 = alias_class_members(pcVar3->tag);
              pcVar11 = (c2_symbol_cell *)0x0;
joined_r0x10795464:
              if (pcVar8 != (c2_symbol_cell *)0x0) {
                do {
                  pcVar9 = pcVar8->sym;
                  pcVar10 = pcVar8;
                  if (pcVar9->cls == '\f') {
                    pcVar10 = (pcVar9->u30).members;
                    pcVar11 = pcVar8;
                    if (pcVar10 == (c2_symbol_cell *)0x0) {
                      pcVar8 = pcVar8->next;
                      goto joined_r0x10795464;
                    }
                    pcVar9 = pcVar10->sym;
                  }
                  if (((pcVar9->u34).refs != 0) &&
                     (iVar7 = bitvec_test(vec,(pcVar9->u34).refs), iVar7 != 0)) {
                    pcVar3->flags11 = pcVar3->flags11 | 8;
                    goto LAB_1079547e;
                  }
                  pcVar8 = pcVar10->next;
                } while (pcVar8 != (c2_symbol_cell *)0x0);
                if (pcVar11 == (c2_symbol_cell *)0x0) goto LAB_1079547e;
                pcVar8 = pcVar11->next;
                pcVar11 = (c2_symbol_cell *)0x0;
                goto joined_r0x10795464;
              }
            }
LAB_1079547e:
          }
        }
      }
    }
    pcVar6->de = (c2_bitset *)0x0;
    pcVar6->ue = (c2_bitset *)0x0;
    pcVar6->kill = (c2_bitset *)0x0;
    (pcVar6->avail_in).set = (c2_bitset *)0x0;
    (pcVar6->avail_out).set = (c2_bitset *)0x0;
    pcVar6->live_in = (c2_bitset *)0x0;
    pcVar6->live_out = (c2_bitset *)0x0;
    pcVar6 = pcVar6->next;
  } while( true );
}

