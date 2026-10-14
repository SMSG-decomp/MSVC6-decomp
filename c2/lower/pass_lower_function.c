void __fastcall pass_lower_function(c2_function *fn)

{
  uint8_t *puVar1;
  ushort uVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  c2_tuple *t;
  c2_tuple *pcVar5;
  c2_fe_symbol *pcVar6;
  c2_symbol *pcVar7;
  c2_operand *pcVar8;
  
  reset_lowering_state();
  if ((fn->fsym->fn_flags & 0x300) != 0) {
    lower_1aa_markers(fn);
  }
  pcVar3 = fn->cfg->first->head;
  pcVar5 = pcVar3;
  while (t = pcVar5, t != (c2_tuple *)0x0) {
    uVar2 = t->line;
    if (uVar2 != 0) {
      g_current_line_abs = fn->line_base + (uint)uVar2;
      g_cur_line = uVar2;
    }
    pcVar5 = t->next;
    if (((t->flags & 1) != 0) &&
       (((t->type & 0xf000) == 0x4000 || ((t->op != 0x15a && (t->op != 0x16a)))))) {
      pcVar5 = lower_tuple(t);
    }
  }
  while (pcVar5 = pcVar3, pcVar5 != (c2_tuple *)0x0) {
    pcVar3 = pcVar5->next;
    if ((pcVar5->flags & 1) != 0) {
      uVar2 = pcVar5->line;
      if (uVar2 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      propagate_lowered_copy(pcVar5);
      set_flags_effects(pcVar5);
      if (pcVar5->op == 0x145) {
        tuple_unlink_free(pcVar5);
      }
      else {
        pcVar4 = pcVar5->src;
        if (pcVar4 != (c2_operand *)0x0) {
          if (pcVar4->op == 0x148) {
            pcVar6 = materialize_float_constant(pcVar4);
            pcVar7 = fe_symbol_get_storage(pcVar6);
            pcVar8 = operand_new_sym(0x14b,pcVar4->type,pcVar7);
            tuple_replace_src(pcVar5,pcVar4,pcVar8);
            puVar1 = &pcVar5->src->sym->flags5;
            *puVar1 = *puVar1 | 4;
          }
          else if (pcVar4->op == 0x14c) {
            fold_address_into_indirection(pcVar5,pcVar4);
          }
          pcVar4 = pcVar5->src->next;
          if (pcVar4 != (c2_operand *)0x0) {
            if (pcVar4->op == 0x148) {
              pcVar6 = materialize_float_constant(pcVar4);
              pcVar7 = fe_symbol_get_storage(pcVar6);
              pcVar8 = operand_new_sym(0x14b,pcVar4->type,pcVar7);
              tuple_replace_src(pcVar5,pcVar4,pcVar8);
              puVar1 = &pcVar5->src->next->sym->flags5;
              *puVar1 = *puVar1 | 4;
            }
            else if (pcVar4->op == 0x14c) {
              fold_address_into_indirection(pcVar5,pcVar4);
            }
          }
        }
        pcVar4 = pcVar5->dst;
        if ((pcVar4 != (c2_operand *)0x0) && (pcVar4->op == 0x14c)) {
          fold_address_into_indirection(pcVar5,pcVar4);
        }
      }
    }
  }
  return;
}

