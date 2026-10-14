void __fastcall local_color_registers(c2_function *fn)

{
  ushort uVar1;
  c2_tuple *t;
  c2_bitset *pcVar2;
  int iVar3;
  c2_bitset **ppcVar4;
  c2_symbol **ppcVar5;
  
  ppcVar4 = g_local_conflicts + 1;
  ppcVar5 = g_register_holders;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppcVar5 = (c2_symbol *)0x0;
    ppcVar5 = ppcVar5 + 1;
  }
  do {
    pcVar2 = bitset_new(6);
    *ppcVar4 = pcVar2;
    ppcVar4 = ppcVar4 + 1;
  } while ((int)ppcVar4 < 0x1079d6ec);
  if ((g_opt_global == 0) || (g_local_register_order[6] = 6, g_ebp_allocatable == 0)) {
    g_local_register_order[6] = 0;
  }
  if ((g_opt_global == 0) || (g_no_global_candidates != 0)) {
    compute_local_conflicts_forward(fn);
  }
  else {
    compute_local_conflicts_backward(fn);
    x87_block_fxch_scheduling(fn);
  }
  g_local_rotation_cursor = g_local_register_order;
  for (t = fn->cfg->first->head; t != (c2_tuple *)0x0; t = t->next) {
    if ((t->flags & 1) != 0) {
      uVar1 = t->line;
      if (uVar1 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar1;
        g_cur_line = uVar1;
      }
      assign_source_operand_registers(t);
      assign_destination_operand_registers(t);
    }
  }
  if ((g_opt_global != 0) && (g_no_global_candidates == 0)) {
    cache_loop_memory_base();
    finalize_callee_saved_registers(fn);
  }
  arena_reset(6);
  return;
}

