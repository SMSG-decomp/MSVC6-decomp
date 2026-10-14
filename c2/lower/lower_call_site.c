void __fastcall lower_call_site(c2_tuple *call)

{
  byte callee_pops;
  c2_operand *pcVar1;
  c2_tuple *local_4;
  
  local_4 = call;
  if (call->src->kind == '\x03') {
    pcVar1 = emit_load_into_register(1,call,call->src,g_reg_symbols);
    tuple_replace_src(call,call->src,pcVar1);
  }
  pcVar1 = operand_list_find_reg(call->src,g_reg_symbols + 5);
  if (pcVar1 == (c2_operand *)0x0) {
    if (g_opt_runtime_checks != 0) {
      emit_chkesp_check(call);
    }
    callee_pops = (call->u24).call.conv;
    if (((callee_pops == 4) || (callee_pops == 0x14)) || (callee_pops == 0x18)) {
      local_4 = (c2_tuple *)0x0;
      pcVar1 = call->src->next;
      if (pcVar1 != (c2_operand *)0x0) {
        do {
          assign_register_argument
                    ((c2_function *)0x0,(uint32_t *)&local_4,pcVar1,(uint)callee_pops,0);
          pcVar1 = pcVar1->next;
        } while (pcVar1 != (c2_operand *)0x0);
      }
    }
    emit_call_stack_cleanup(call,callee_pops);
    convert_arg_copies_to_push(call);
    add_call_clobbers(call);
    if ((call->src->kind != '\x04') || (((uint)call->src->sym->def & 0x10000) == 0)) {
      note_call_target_frame(call);
    }
  }
  g_cur_function->flags = g_cur_function->flags | 0x200;
  return;
}

