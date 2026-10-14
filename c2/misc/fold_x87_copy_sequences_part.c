void __fastcall
fold_x87_copy_sequences_part
          (c2_tuple *t,c2_tuple *next,c2_tuple *saved_next,c2_function *fn,c2_tuple *end)

{
  uint8_t uVar1;
  ushort uVar2;
  uint uVar3;
  uint32_t uVar4;
  c2_operand *new_op;
  c2_tuple *pcVar5;
  c2_operand *pcVar6;
  
code_r0x1072119d:
  pcVar5 = x87_keep_float_temp_on_stack(t);
  if (pcVar5 != (c2_tuple *)0x0) {
    pcVar6 = t->dst;
    pcVar5->op = 1;
    tuple_replace_dst(pcVar5,pcVar5->dst,pcVar6);
    emit_float_move_as_integer(pcVar5);
    if (pcVar5->src->kind == '\x01') {
      operand_make_sym(pcVar5->src);
    }
    pcVar6 = pcVar5->dst;
    uVar1 = pcVar6->kind;
    goto joined_r0x10777232;
  }
  do {
    do {
      while( true ) {
        do {
          do {
            t = next;
            if (t == end) {
              return;
            }
            uVar2 = t->line;
            next = t->next;
            if (uVar2 != 0) {
              g_current_line_abs = fn->line_base + (uint)uVar2;
              g_cur_line = uVar2;
            }
          } while (t->kind != '\f');
          x87_legalize_and_fix_stack_dsts(t);
          uVar3 = t->op;
        } while (uVar3 < 0x5c);
        if (0x5e < uVar3) break;
        pcVar5 = t->prev;
        if (pcVar5->kind == '\f') {
          while (((((uVar4 = pcVar5->op, uVar4 == 0x76 || (uVar4 == 0x75)) || (uVar4 == 0x77)) ||
                  ((uVar4 == 0x89 || (uVar4 == 0x8c)))) || ((uVar4 == 0xd7 || (uVar4 == 0xd6))))) {
            if ((pcVar5->dst->sym != pcVar5->next->src->sym) ||
               (pcVar5 = pcVar5->prev, pcVar5->kind != '\f')) break;
          }
          if (((pcVar5->kind == '\f') &&
              ((((t->next->kind == '\f' && (pcVar5->op == 0x60)) && (t->next->op == 99)) &&
               (((pcVar6 = pcVar5->src, pcVar6->kind == '\x01' &&
                 ((pcVar6->u18).reg == g_reg_symbols + 0x1f)) &&
                ((next->dst->kind == '\x01' &&
                 (((next->dst->u18).reg == g_reg_symbols + 0x1f && (t->src->kind == '\x01'))))))))))
             && ((t->src->sym == pcVar5->dst->sym || (t->prev != pcVar5)))) {
            tuple_replace_src(pcVar5->next,pcVar5->next->src,pcVar6);
            pcVar6 = operand_new_reg(0x149,t->type,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f);
            tuple_append_dst(t,pcVar6);
            pcVar6 = t->src->next;
            if (pcVar6->kind == '\x01') {
              (pcVar6->u18).reg =
                   (c2_symbol *)(&g_pdb_il_module_index + ((pcVar6->u18).reg)->id * 0x15);
            }
            next = next->next;
            tuple_unlink_free(pcVar5);
            tuple_unlink_free(t->next);
          }
        }
      }
    } while ((uVar3 != 99) || (g_opt_float_consistency != 0));
    pcVar5 = t->prev;
    if ((pcVar5->kind != '\f') || (pcVar5->op != 0x60)) goto code_r0x1072119d;
    pcVar6 = pcVar5->src;
    if (pcVar6->kind == '\x01') goto code_r0x1072119d;
    new_op = t->dst;
    if (new_op->kind == '\x01') goto code_r0x1072119d;
    if ((((new_op->type != pcVar6->type) || ((g_opt_favor_speed == 0 && (pcVar5->type != 0x4004))))
        || ((pcVar6->kind == '\x06' && (pcVar6->index != (c2_operand *)0x0)))) ||
       ((new_op->kind == '\x06' && (new_op->index != (c2_operand *)0x0)))) {
      fold_x87_copy_sequences_part(t,next,next,fn,end);
      return;
    }
    pcVar5->op = 1;
    tuple_replace_dst(pcVar5,pcVar5->dst,new_op);
    emit_float_move_as_integer(pcVar5);
    if (pcVar5->src->kind == '\x01') {
      operand_make_sym(pcVar5->src);
    }
    pcVar6 = pcVar5->dst;
    uVar1 = pcVar6->kind;
joined_r0x10777232:
    if (uVar1 == '\x01') {
      operand_make_sym(pcVar6);
    }
    next = t->next;
    tuple_unlink_free(t);
    tuple_legalize_mem_operands(pcVar5);
    legalize_machine_tuple(pcVar5);
    if (pcVar5->type == 0x1008) {
      lower_int64_tuple(pcVar5);
    }
  } while( true );
}

