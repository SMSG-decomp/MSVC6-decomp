void __fastcall rewrite_live_range_operands(c2_function *fn)

{
  c2_block *pcVar1;
  c2_loop *loop;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  uint32_t uVar5;
  int bitoff;
  c2_symbol *pcVar6;
  c2_tuple *reload;
  int iVar7;
  c2_ra_candidate *cand;
  
  pcVar1 = fn->cfg->first;
  do {
    if (pcVar1 == (c2_block *)0x0) {
      return;
    }
    reload = pcVar1->head;
    if (pcVar1->head != pcVar1->end) {
      do {
        pcVar3 = reload->next;
        if ((reload->flags & 1) == 0) {
          if (reload->kind == '\x1b') {
LAB_10733f12:
            tuple_unlink_free(reload);
          }
        }
        else {
          if (reload->op == 0x164) {
            pcVar4 = reload->dst;
            loop = pcVar1->loop;
            pcVar6 = pcVar4->sym;
            if (((((loop != (c2_loop *)0x0) &&
                  (cand = (pcVar6->u30).ra, cand != (c2_ra_candidate *)0x0)) &&
                 (uVar5 = bitset_test(loop->candidates,cand->id), uVar5 == 0)) &&
                ((g_opt_favor_speed != 0 || (loop->exits->next == (c2_loop_exit *)0x0)))) &&
               (((pcVar4->flags11 & 8) == 0 &&
                (iVar7 = rewrite_place_loop_reloads(loop,reload,pcVar6,fn), iVar7 != 0))))
            goto LAB_10733f12;
          }
          iVar7 = 0;
          do {
            if (iVar7 == 0) {
              pcVar4 = reload->dst;
            }
            else {
              pcVar4 = reload->src;
            }
            for (; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
              if ((pcVar4->kind == '\x01') && (((pcVar4->u18).range)->kind == '\x02')) {
                pcVar2 = (pcVar4->sym->u34).lcse_values;
                if (pcVar2 == (c2_operand *)0x0) {
                  bitoff = 0;
                }
                else {
                  bitoff = (pcVar4->sym->offset - pcVar2->disp) * 8;
                }
                pcVar6 = reg_find_subreg(((pcVar4->u18).range)->colour,(pcVar4->type & 0xfff) << 3,
                                         bitoff);
                (pcVar4->u18).reg = pcVar6;
              }
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < 2);
          if (reload->op == 0x163) {
            convert_to_mov(reload);
          }
          else if (reload->op == 0x164) {
            convert_to_mov(reload);
          }
        }
        reload = pcVar3;
      } while (pcVar3 != pcVar1->end);
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

