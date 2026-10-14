uint32_t __fastcall cross_jump_complementary_branches(c2_tuple *fn,c2_tuple *t)

{
  uint16_t uVar1;
  c2_tuple *pcVar2;
  int iVar3;
  c2_fe_symbol *label_sym;
  int iVar4;
  c2_tuple *pcVar5;
  c2_tuple *pcVar6;
  c2_operand *pcVar7;
  
  if (g_opt_favor_speed == 0) {
    pcVar5 = *(c2_tuple **)((int)&t->src->sym->u30 + 2);
    pcVar2 = find_complementary_branch_before(pcVar5,t);
    if (pcVar2 == (c2_tuple *)0x0) {
      pcVar7 = pcVar5->dst;
      if (pcVar7 == (c2_operand *)0x0) {
        return 0;
      }
      do {
        pcVar5 = (c2_tuple *)pcVar7->rank;
        if ((((pcVar5->kind == '\x11') && ((pcVar5->u20).cond_cells == (c2_cond_cell *)0x0)) &&
            (pcVar5->op != 0x18b)) &&
           (pcVar2 = find_complementary_branch_before(pcVar5,t), pcVar2 != (c2_tuple *)0x0)) {
          pcVar5 = *(c2_tuple **)pcVar7->rank;
          break;
        }
        pcVar7 = pcVar7->next;
        pcVar5 = fn;
      } while (pcVar7 != (c2_operand *)0x0);
    }
    else {
      pcVar5 = (c2_tuple *)0x0;
    }
    if (pcVar2 != (c2_tuple *)0x0) {
      if (pcVar5 == (c2_tuple *)0x0) {
        pcVar5 = pcVar2->next;
      }
      else {
        for (pcVar6 = pcVar2->next; pcVar6 != pcVar5; pcVar6 = pcVar6->next) {
          if (pcVar6->kind != '\x11') {
            return 0;
          }
        }
      }
      pcVar6 = t->prev;
      pcVar2 = pcVar2->prev;
      iVar4 = 0;
      if (pcVar6->kind != '\x1a') {
        do {
          if (((pcVar2->kind == '\x1a') || (pcVar2 == t)) ||
             (iVar3 = tuples_equal(pcVar6,pcVar2), iVar3 == 0)) break;
          pcVar6 = pcVar6->prev;
          pcVar2 = pcVar2->prev;
          iVar4 = iVar4 + 1;
        } while (pcVar6->kind != '\x1a');
        if (iVar4 != 0) {
          uVar1 = pcVar5->prev->line;
          if (uVar1 != 0) {
            g_current_line_abs = (int)&((fn->u24).cases)->next + (uint)pcVar5->prev->line;
            g_cur_line = uVar1;
          }
          tuple_range_free(pcVar2->next,pcVar5);
          label_sym = label_symbol_new();
          pcVar2 = tuple_new_label(label_sym);
          tuple_insert_after(pcVar6,pcVar2);
          tuple_new_jmp_before(pcVar2,pcVar5);
          return 1;
        }
      }
    }
  }
  return 0;
}

