void __fastcall fold_x87_copy_sequences(c2_function *fn)

{
  uint8_t uVar1;
  ushort uVar2;
  uint uVar3;
  uint32_t uVar4;
  c2_operand *new_op;
  c2_tuple *t;
  c2_operand *pcVar5;
  c2_tuple *pcVar6;
  c2_tuple *pcVar7;
  c2_tuple *t_00;
  c2_tuple *end;
  
  end = fn->cfg->last->end;
  t_00 = fn->cfg->first->head->next;
  if (t_00 != end) {
    do {
      uVar2 = t_00->line;
      pcVar6 = t_00->next;
      if (uVar2 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      if (t_00->kind == '\f') {
        pcVar7 = pcVar6;
        x87_legalize_and_fix_stack_dsts(t_00);
        uVar3 = t_00->op;
        if (0x5b < uVar3) {
          if (uVar3 < 0x5f) {
            pcVar7 = t_00->prev;
            if (pcVar7->kind == '\f') {
              while (((((uVar4 = pcVar7->op, uVar4 == 0x76 || (uVar4 == 0x75)) || (uVar4 == 0x77))
                      || ((uVar4 == 0x89 || (uVar4 == 0x8c)))) ||
                     ((uVar4 == 0xd7 || (uVar4 == 0xd6))))) {
                if ((pcVar7->dst->sym != pcVar7->next->src->sym) ||
                   (pcVar7 = pcVar7->prev, pcVar7->kind != '\f')) break;
              }
              if (((pcVar7->kind == '\f') &&
                  ((((t_00->next->kind == '\f' && (pcVar7->op == 0x60)) && (t_00->next->op == 99))
                   && (((pcVar5 = pcVar7->src, pcVar5->kind == '\x01' &&
                        ((pcVar5->u18).reg == g_reg_symbols + 0x1f)) &&
                       ((pcVar6->dst->kind == '\x01' &&
                        (((pcVar6->dst->u18).reg == g_reg_symbols + 0x1f &&
                         (t_00->src->kind == '\x01')))))))))) &&
                 ((t_00->src->sym == pcVar7->dst->sym || (t_00->prev != pcVar7)))) {
                tuple_replace_src(pcVar7->next,pcVar7->next->src,pcVar5);
                pcVar5 = operand_new_reg(0x149,t_00->type,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f)
                ;
                tuple_append_dst(t_00,pcVar5);
                pcVar5 = t_00->src->next;
                if (pcVar5->kind == '\x01') {
                  (pcVar5->u18).reg =
                       (c2_symbol *)(&g_pdb_il_module_index + ((pcVar5->u18).reg)->id * 0x15);
                }
                pcVar6 = pcVar6->next;
                tuple_unlink_free(pcVar7);
                tuple_unlink_free(t_00->next);
              }
            }
          }
          else if ((uVar3 == 99) && (g_opt_float_consistency == 0)) {
            t = t_00->prev;
            if ((t->kind == '\f') && (t->op == 0x60)) {
              pcVar5 = t->src;
              if (pcVar5->kind == '\x01') goto code_r0x1072119d;
              new_op = t_00->dst;
              if (new_op->kind == '\x01') goto code_r0x1072119d;
              if ((((new_op->type != pcVar5->type) ||
                   ((g_opt_favor_speed == 0 && (t->type != 0x4004)))) ||
                  ((pcVar5->kind == '\x06' && (pcVar5->index != (c2_operand *)0x0)))) ||
                 ((new_op->kind == '\x06' && (new_op->index != (c2_operand *)0x0)))) {
                fold_x87_copy_sequences_part(t_00,pcVar7,pcVar7,fn,end);
                return;
              }
              t->op = 1;
              tuple_replace_dst(t,t->dst,new_op);
              emit_float_move_as_integer(t);
              if (t->src->kind == '\x01') {
                operand_make_sym(t->src);
              }
              pcVar5 = t->dst;
              uVar1 = pcVar5->kind;
            }
            else {
code_r0x1072119d:
              t = x87_keep_float_temp_on_stack(t_00);
              if (t == (c2_tuple *)0x0) goto LAB_107211ae;
              pcVar5 = t_00->dst;
              t->op = 1;
              tuple_replace_dst(t,t->dst,pcVar5);
              emit_float_move_as_integer(t);
              if (t->src->kind == '\x01') {
                operand_make_sym(t->src);
              }
              pcVar5 = t->dst;
              uVar1 = pcVar5->kind;
            }
            if (uVar1 == '\x01') {
              operand_make_sym(pcVar5);
            }
            pcVar6 = t_00->next;
            tuple_unlink_free(t_00);
            tuple_legalize_mem_operands(t);
            legalize_machine_tuple(t);
            if (t->type == 0x1008) {
              lower_int64_tuple(t);
            }
          }
        }
      }
LAB_107211ae:
      t_00 = pcVar6;
    } while (pcVar6 != end);
  }
  return;
}

