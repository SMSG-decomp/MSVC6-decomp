void __fastcall replace_loop_exit_tests(c2_loop *loop,c2_function *fn)

{
  ushort uVar1;
  uint16_t type;
  c2_cse_expr *pcVar2;
  c2_symbol *sym;
  c2_tuple *pcVar3;
  c2_list_cell *pcVar4;
  c2_tuple *pcVar5;
  c2_operand *src1;
  c2_operand *pcVar6;
  uint32_t uVar7;
  c2_operand *local_4;
  
  set_preheader_insert_point(loop);
  pcVar3 = tuple_next_real(loop->guard->head);
  uVar1 = pcVar3->line;
  reset_iv_worklists();
  pcVar4 = collect_iv_candidates(loop,2);
  if (pcVar4 != (c2_list_cell *)0x0) {
    pcVar3 = iv_worklist_pop();
    while (sym = g_derived_iv_head, pcVar3 != (c2_tuple *)0x0) {
      pcVar5 = find_next_use_of_dst(pcVar3,&local_4);
      if (pcVar5->kind == '\x11') {
        if (pcVar3->line != 0) {
          g_current_line_abs = fn->line_base + (uint)pcVar3->line;
          g_cur_line = pcVar3->line;
        }
        rewrite_exit_test_with_derived_iv(pcVar3,loop,fn);
      }
      pcVar3 = iv_worklist_pop();
    }
    for (; sym != (c2_symbol *)0xffffffff; sym = sym->order_next) {
      if (uVar1 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar1;
        g_cur_line = uVar1;
      }
      pcVar2 = (sym->u18).expr;
      type = pcVar2->type;
      uVar7 = pcVar2->op;
      pcVar6 = pcVar2->operands->next;
      src1 = materialize_value_in_preheader(type,pcVar2->operands,g_preheader_insert_point,0);
      pcVar6 = materialize_value_in_preheader(type,pcVar6,g_preheader_insert_point,0);
      uVar7 = map_iv_update_opcode(uVar7);
      pcVar3 = tuple_new_binary_temp
                         (uVar7,type,src1,pcVar6,tuple_insert_before,g_preheader_insert_point);
      pcVar6 = operand_new_sym(0x14a,type,sym);
      tuple_new(0x15b,type,pcVar6,pcVar3->dst,tuple_insert_before,g_preheader_insert_point);
    }
  }
  return;
}

