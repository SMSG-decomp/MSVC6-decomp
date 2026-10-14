c2_tuple * __fastcall legalize_machine_tuple(c2_tuple *t)

{
  uint uVar1;
  byte bVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  c2_operand *local_14;
  uint local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if ((t->flags & 1) == 0) {
    return t;
  }
  if (t->kind != '\x15') {
    zero_16_bytes(&local_10);
    compute_operand_constraints(t,&local_10);
    if (local_10 != 0) {
      if ((local_10 & 1) != 0) {
        bind_result_to_register(t,g_reg_symbols + local_c);
      }
      if ((local_10 & 2) != 0) {
        load_operand_into_register(t,t->src,g_reg_symbols + local_8);
      }
      if ((local_10 & 4) != 0) {
        load_operand_into_register(t,t->src->next,g_reg_symbols + local_4);
      }
      if (((local_10 & 8) != 0) ||
         ((((uVar1 = t->op, uVar1 != 0 && (uVar1 < 0x144)) && ((g_x86_op_flags[uVar1] & 0x40) != 0))
          && ((local_10 & 2) != 0)))) {
        enforce_two_address_form(t);
      }
      if ((local_10 & 0x10) != 0) {
        tuple_swap_first_srcs(t);
        if (t->op == 0x2f) {
          pcVar3 = find_next_use_of_dst(t,&local_14);
          bVar2 = x86_fixed_reg_class(pcVar3);
          set_condition_code(pcVar3,g_cond_swapped_operands[bVar2]);
          pcVar3 = pcVar3->next;
          if (pcVar3->kind == '\x11') {
            pcVar4 = find_src_overlapping_reg(pcVar3,g_reg_symbols + 0x42);
            if (pcVar4 != (c2_operand *)0x0) {
              bVar2 = x86_fixed_reg_class(pcVar3);
              set_condition_code(pcVar3,g_cond_swapped_operands[bVar2]);
            }
          }
        }
      }
    }
    pcVar3 = legalize_operand_forms(t);
    return pcVar3;
  }
  lower_call_results_and_clobbers(t);
  return t;
}

