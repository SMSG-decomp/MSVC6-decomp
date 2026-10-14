void __fastcall basic_solve_reaching(c2_function *fn,uint32_t nbits)

{
  short sVar1;
  ushort uVar2;
  c2_edge *pcVar3;
  c2_bitset *pcVar4;
  c2_bitvec *vec;
  c2_tuple *pcVar5;
  int iVar6;
  c2_cfg *pcVar7;
  c2_symbol *pcVar8;
  c2_block *pcVar9;
  int local_8;
  c2_cfg *local_4;
  
  pcVar7 = fn->cfg;
  pcVar9 = pcVar7->first;
  local_4 = pcVar7;
  do {
    if (pcVar9 == (c2_block *)0x0) {
      vec = bitvec_new(6,nbits);
      do {
        local_8 = 0;
        pcVar9 = pcVar7->first->next;
        if (pcVar9 == (c2_block *)0x0) {
          return;
        }
        do {
          pcVar5 = pcVar9->head;
          if ((pcVar5->flags & 1) == 0) {
            do {
              if ((pcVar5 == pcVar9->end) || (pcVar5->kind == '\x1a')) break;
              pcVar5 = pcVar5->next;
            } while ((pcVar5->flags & 1) == 0);
          }
          if ((pcVar5->kind != '\x1a') ||
             (pcVar8 = (c2_symbol *)pcVar5->src, ((uint)pcVar8->copy_equivs & 0x10000) == 0)) {
            pcVar8 = (c2_symbol *)0x0;
          }
          bitvec_clear_words(vec);
          for (pcVar3 = pcVar9->preds; pcVar3 != (c2_edge *)0x0; pcVar3 = pcVar3->next_pred) {
            if (pcVar8 == (c2_symbol *)0x0) {
LAB_10794d29:
              bitvec_or(vec,(c2_bitvec *)(pcVar3->from->avail_out).set);
            }
            else {
              pcVar5 = pcVar3->from->end;
              if ((pcVar5->flags & 1) == 0) {
                do {
                  if (pcVar5 == pcVar3->from->head) break;
                  pcVar5 = pcVar5->prev;
                } while ((pcVar5->flags & 1) == 0);
              }
              if ((pcVar5->op != 0x18b) || (pcVar5->src->sym != pcVar8)) goto LAB_10794d29;
            }
          }
          iVar6 = bitvec_equal(vec,(c2_bitvec *)(pcVar9->avail_in).set);
          if (iVar6 == 0) {
            bitvec_copy((c2_bitvec *)(pcVar9->avail_in).set,vec);
            bitvec_transfer_in_kill_gen
                      ((c2_bitvec *)(pcVar9->avail_out).set,(c2_bitvec *)pcVar9->de,vec,
                       (c2_bitvec *)pcVar9->kill,&local_8);
          }
          pcVar9 = pcVar9->next;
        } while (pcVar9 != (c2_block *)0x0);
        pcVar7 = local_4;
        if (local_8 == 0) {
          return;
        }
      } while( true );
    }
    pcVar4 = (c2_bitset *)bitvec_new(6,nbits);
    pcVar9->de = pcVar4;
    pcVar4 = (c2_bitset *)bitvec_new(6,nbits);
    pcVar5 = pcVar9->head;
    pcVar9->kill = pcVar4;
    if (pcVar5 != pcVar9->end) {
      do {
        if (pcVar5->op == 0x18b) {
          sVar1._0_1_ = pcVar5->flags12;
          sVar1._1_1_ = pcVar5->flags13;
          if (sVar1 != 0) {
            bitvec_clear_words((c2_bitvec *)pcVar9->de);
            uVar2._0_1_ = pcVar5->flags12;
            uVar2._1_1_ = pcVar5->flags13;
            bitvec_set((c2_bitvec *)pcVar9->de,(uint)uVar2);
LAB_10794c58:
            bitvec_fill((c2_bitvec *)pcVar9->kill,nbits);
          }
        }
        else if (pcVar5->op == 0x19b) {
          bitvec_clear_words((c2_bitvec *)pcVar9->de);
          goto LAB_10794c58;
        }
        pcVar5 = pcVar5->next;
      } while (pcVar5 != pcVar9->end);
    }
    pcVar4 = (c2_bitset *)bitvec_new(6,nbits);
    (pcVar9->avail_in).set = pcVar4;
    pcVar4 = (c2_bitset *)bitvec_clone((c2_bitvec *)pcVar9->de);
    (pcVar9->avail_out).set = pcVar4;
    pcVar9 = pcVar9->next;
  } while( true );
}

