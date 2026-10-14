c2_live_range * __fastcall
x87_prune_unprofitable_ranges(c2_function *fn,c2_live_range *queue,c2_bitset *spared)

{
  ushort uVar1;
  c2_symbol *pcVar2;
  c2_function *pcVar3;
  c2_bitset *bs;
  c2_tuple *pcVar4;
  c2_tuple *pcVar5;
  c2_operand *op;
  uint32_t uVar6;
  uint32_t uVar7;
  c2_block *block;
  int iVar8;
  c2_live_range *head;
  c2_live_range *new_head;
  c2_tuple *t;
  
  head = queue;
  new_head = queue;
  if (queue == (c2_live_range *)0x0) {
    return (c2_live_range *)0x0;
  }
LAB_1075deb4:
  pcVar2 = (c2_symbol *)((c2_symbol *)queue)->def;
  if (((int)((c2_symbol *)queue)->copy_equivs < 1) &&
     ((spared == (c2_bitset *)0x0 ||
      (uVar7 = bitset_test(spared,((c2_symbol *)queue)->id), uVar7 == 0)))) {
    if (queue == head) {
      new_head = (c2_live_range *)pcVar2;
      if (pcVar2 != (c2_symbol *)0x0) {
        (pcVar2->u18).expr = (c2_cse_expr *)0x0;
      }
    }
    else {
      pcVar3 = (((c2_symbol *)queue)->u18).inline_callee;
      pcVar3->seh_try_scopes = (c2_seh_try_scope *)pcVar2;
      if (pcVar2 != (c2_symbol *)0x0) {
        pcVar2->u18 = (c2_symbol_u18)pcVar3;
      }
    }
    block = (c2_block *)(((c2_symbol *)queue)->u28).free_next;
    do {
      bs = block->live;
      uVar7 = ((c2_symbol *)queue)->id;
      uVar6 = bitset_test(bs,uVar7);
      if (uVar6 != 0) {
        bitset_clear(bs,uVar7);
        bitset_clear(block->live_in,uVar7);
        bitset_clear(block->live_out,uVar7);
        pcVar4 = block->end;
        pcVar5 = block->head;
        while (t = pcVar5, t != pcVar4) {
          pcVar5 = t->next;
          if (((t->flags & 1) != 0) && ((t->type & 0xf000) == 0x4000)) {
            uVar1 = t->line;
            if (uVar1 != 0) {
              g_current_line_abs = fn->line_base + (uint)uVar1;
              g_cur_line = uVar1;
            }
            if (t->op == 0x163) {
              if ((t->dst->u18).reg == (c2_symbol *)queue) {
                tuple_unlink_free(t);
              }
            }
            else if (t->op == 0x164) {
              if ((t->src->u18).reg == (c2_symbol *)queue) {
                tuple_unlink_free(t);
              }
            }
            else {
              iVar8 = 0;
              do {
                if (iVar8 == 0) {
                  op = t->dst;
                }
                else {
                  op = t->src;
                }
                for (; op != (c2_operand *)0x0; op = op->next) {
                  if ((((op->kind == '\x01') && ((op->u18).reg == (c2_symbol *)queue)) &&
                      (operand_make_sym(op), iVar8 == 0)) && (t->flags13 != '\0')) {
                    sink_fp_copy_run_to_fp_def(t);
                  }
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 < 2);
            }
          }
        }
        if (block == (c2_block *)(((c2_symbol *)queue)->u30).order_prev) goto code_r0x1075df48;
      }
      block = block->next;
    } while( true );
  }
  goto LAB_1075dec2;
code_r0x1075df48:
  free_split_cell_list((((c2_symbol *)queue)->u34).source_links);
  free_split_cell_list((((c2_symbol *)queue)->u38).copy_links);
  free_live_range(queue,0);
  head = new_head;
LAB_1075dec2:
  queue = (c2_live_range *)pcVar2;
  if (pcVar2 == (c2_symbol *)0x0) {
    return head;
  }
  goto LAB_1075deb4;
}

