void __fastcall pass_select_address_modes(c2_function *fn)

{
  ushort uVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  bool bVar4;
  int iVar5;
  c2_tuple *def_tuple;
  c2_tuple *cur;
  int32_t disp;
  c2_operand *opnd;
  c2_replace_fn *replace_fn;
  
  if (g_opt_basic != 0) {
    basic_clear_symbol_fold_links();
  }
  cur = fn->cfg->last->end;
  if (cur != (c2_tuple *)0x0) {
    do {
      if ((cur->flags & 1) != 0) {
        uVar1 = cur->line;
        if (uVar1 != 0) {
          g_current_line_abs = fn->line_base + (uint)uVar1;
          g_cur_line = uVar1;
        }
        opnd = cur->dst;
        if (opnd != (c2_operand *)0x0) {
          iVar5 = is_foldable_memory_operand(opnd);
          if (iVar5 == 0) {
            if ((((1 << (byte)(cur->type >> 0xc) & 0xeU) != 0) && ((cur->type & 0xfff) == 4)) &&
               ((opnd->kind == '\x01' &&
                ((g_opt_basic == 0 || (opnd->sym->defs == (c2_list_cell *)0x0)))))) {
              replace_fn = (c2_replace_fn *)0x0;
              disp = 0;
              opnd = (c2_operand *)0x0;
              def_tuple = cur;
LAB_10719d80:
              fold_address_expression
                        (cur,def_tuple,opnd,disp,(fold_address_expression_replace_fn *)replace_fn);
            }
          }
          else {
            pcVar2 = opnd->base;
            if (((pcVar2 != (c2_operand *)0x0) && ((1 << (pcVar2->kind & 0x1f) & 6U) != 0)) &&
               (def_tuple = pcVar2->sym->def, def_tuple != (c2_tuple *)0x0)) {
              disp = opnd->disp;
              replace_fn = tuple_replace_dst;
              goto LAB_10719d80;
            }
          }
        }
        bVar4 = false;
        if ((cur->op == 0x15b) && (cur->src->kind == '\x05')) {
          operand_to_memory_form(cur->src);
          bVar4 = true;
        }
        opnd = cur->src;
        if (opnd != (c2_operand *)0x0) {
          iVar5 = is_foldable_memory_operand(opnd);
          if ((((iVar5 != 0) && (pcVar2 = opnd->base, pcVar2 != (c2_operand *)0x0)) &&
              ((1 << (pcVar2->kind & 0x1f) & 6U) != 0)) &&
             (def_tuple = pcVar2->sym->def, def_tuple != (c2_tuple *)0x0)) {
            fold_address_expression(cur,def_tuple,opnd,opnd->disp,tuple_replace_src);
          }
          pcVar2 = cur->src->next;
          if (((pcVar2 != (c2_operand *)0x0) &&
              (iVar5 = is_foldable_memory_operand(pcVar2), iVar5 != 0)) &&
             ((pcVar3 = pcVar2->base, pcVar3 != (c2_operand *)0x0 &&
              (((1 << (pcVar3->kind & 0x1f) & 6U) != 0 &&
               (def_tuple = pcVar3->sym->def, def_tuple != (c2_tuple *)0x0)))))) {
            fold_address_expression(cur,def_tuple,pcVar2,pcVar2->disp,tuple_replace_src);
          }
        }
        if (bVar4) {
          operand_to_address_form(cur->src);
          cur->op = 0x12;
        }
        if ((cur->op == 0x178) && (pcVar2 = cur->src, (1 << (pcVar2->kind & 0x1f) & 6U) != 0)) {
          def_tuple = pcVar2->sym->def;
          if (def_tuple != (c2_tuple *)0x0) {
            if ((cur->type & 0xf000) == 0x4000) {
              if (((def_tuple->op == 0x15b) &&
                  (pcVar3 = def_tuple->src, (1 << (pcVar3->kind & 0x1f) & 6U) != 0)) &&
                 (pcVar3->sym->def != (c2_tuple *)0x0)) {
                tuple_replace_src(cur,pcVar2,pcVar3);
                tuple_unlink_free(def_tuple);
              }
            }
            else {
              pcVar2->sym->defs = (c2_list_cell *)cur;
            }
          }
        }
      }
      cur = cur->prev;
    } while (cur != (c2_tuple *)0x0);
  }
  return;
}

