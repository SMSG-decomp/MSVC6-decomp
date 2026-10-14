int __fastcall invert_loop(c2_loop *loop,c2_function *fn)

{
  c2_block *from;
  c2_tuple *label;
  c2_edge *pcVar1;
  int iVar2;
  c2_edge *pcVar3;
  uint32_t uVar4;
  c2_fe_symbol *label_sym;
  c2_tuple *pcVar5;
  c2_tuple *pcVar6;
  c2_block *pcVar7;
  c2_block *pcVar8;
  c2_tuple *pcVar9;
  c2_block *loop_first;
  c2_tuple *t2;
  c2_loop *pcVar10;
  
  if (((loop != (c2_loop *)0x0) && (g_loop_inversion_enabled != 0)) && ((loop->flags & 1) == 0)) {
    pcVar8 = loop->first;
    pcVar7 = loop->last;
    from = pcVar8->prev;
    for (pcVar9 = from->head->next; pcVar9 != from->end; pcVar9 = pcVar9->next) {
    }
    pcVar9 = pcVar8->end->prev;
    if (((pcVar9->kind == '\x11') &&
        (((pcVar9->u20).cond_cells != (c2_cond_cell *)0x0 || (pcVar9->op == 0x18b)))) &&
       ((pcVar9->flags & 8) == 0)) {
      pcVar3 = pcVar8->succs;
      if (pcVar3 != (c2_edge *)0x0) {
        do {
          if (pcVar3->to == *(c2_block **)(*(int *)((int)&pcVar9->src->sym->u30 + 2) + 0x14)) break;
          pcVar3 = pcVar3->next_succ;
        } while (pcVar3 != (c2_edge *)0x0);
      }
      loop_first = pcVar8;
      pcVar10 = loop;
      iVar2 = loop_is_within(pcVar3->to->loop,loop);
      if ((((iVar2 == 0) && ((loop->parent == (c2_loop *)0x0 || (pcVar3->to->loop == loop->parent)))
           ) && (pcVar6 = pcVar7->end->prev, pcVar6->kind == '\x11')) &&
         (((((pcVar6->u20).cond_cells == (c2_cond_cell *)0x0 && (pcVar6->op != 0x18b)) &&
           (pcVar3 = flow_edge_find(pcVar7,pcVar8), pcVar3 != (c2_edge *)0x0)) &&
          (uVar4 = block_blocks_loop_inversion(pcVar8), uVar4 == 0)))) {
        label = pcVar8->head->next;
        pcVar9->next = (c2_tuple *)0x0;
        t2 = label;
        tuple_splice_after(from->end->prev,label->next);
        pcVar5 = pcVar8->end;
        pcVar3 = pcVar8->succs;
        label->next = pcVar5;
        pcVar5->prev = label;
        if (pcVar3 != (c2_edge *)0x0) {
          pcVar8 = pcVar8->next;
          do {
            pcVar1 = pcVar3->next_succ;
            if (pcVar3->to != pcVar8) {
              flow_edge_move_src(pcVar3,from,fn);
            }
            pcVar3 = pcVar1;
          } while (pcVar1 != (c2_edge *)0x0);
        }
        pcVar5 = pcVar7->head->next;
        if ((pcVar5->kind != '\x1a') || (pcVar6->prev != pcVar5)) {
          label_sym = label_symbol_new();
          pcVar5 = tuple_new_label(label_sym);
          tuple_insert_before(pcVar6,pcVar5);
          (pcVar5->u14).block = pcVar7;
        }
        pcVar8 = pcVar7;
        if (pcVar5 != pcVar7->head->next) {
          pcVar8 = block_split_before(fn,pcVar7,pcVar5);
          pcVar3 = pcVar7->succs;
          pcVar8->loop = pcVar7->loop;
          while (pcVar3 != (c2_edge *)0x0) {
            pcVar1 = pcVar3->next_succ;
            flow_edge_move_src(pcVar3,pcVar8,fn);
            pcVar3 = pcVar1;
          }
          cfg_add_edge(fn,pcVar7,pcVar8);
        }
        tuple_unlink_free(pcVar6);
        pcVar6 = from->head->next;
        pcVar9->next = (c2_tuple *)0x0;
        pcVar6 = clone_tuple_list(pcVar6->next);
        pcVar9->next = from->end;
        tuple_splice_after(pcVar5,pcVar6);
        pcVar6 = pcVar8->end->prev;
        tuple_retarget(pcVar6,(c2_node *)label,0);
        branch_invert_condition(pcVar6);
        pcVar6->flags = pcVar6->flags | 0x80;
        pcVar3 = loop_first->preds;
        do {
          pcVar1 = pcVar3;
          if (pcVar1 == (c2_edge *)0x0) {
            loop_set_latch(pcVar10,pcVar8);
            pcVar9 = *(c2_tuple **)((int)&pcVar9->src->sym->u30 + 2);
            pcVar6 = tuple_new_jmp_before(pcVar9,pcVar8->end);
            pcVar7 = block_split_before(fn,pcVar8,pcVar6);
            pcVar10 = pcVar10->parent;
            pcVar7->loop = pcVar10;
            if ((pcVar10 != (c2_loop *)0x0) && (pcVar10->last == pcVar8)) {
              loop_set_latch(pcVar10,pcVar7);
            }
            cfg_add_edge(fn,pcVar8,pcVar7);
            cfg_add_edge(fn,pcVar7,(pcVar9->prev->u14).block);
            return 1;
          }
          pcVar3 = pcVar1->next_pred;
        } while (((pcVar1->from == pcVar8) || (pcVar1->from == loop_first->prev)) ||
                (uVar4 = redirect_branch_edge(pcVar1,pcVar5,t2,fn), uVar4 != 0));
        cfg_edge_redirect(pcVar1,pcVar8,fn);
        iVar2 = invert_loop_part(pcVar3,pcVar8,pcVar5,fn,pcVar9,loop_first,t2,pcVar10);
        return iVar2;
      }
    }
  }
  return 0;
}

