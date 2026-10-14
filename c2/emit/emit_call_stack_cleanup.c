c2_tuple * __fastcall emit_call_stack_cleanup(c2_tuple *call,uint8_t callee_pops)

{
  c2_fe_symbol *pcVar1;
  uint32_t lo;
  c2_operand *pcVar2;
  c2_const_operand *src2;
  c2_tuple *pcVar3;
  c2_insert_fn *insert_fn;
  
  pcVar1 = call_target_function_symbol(call);
  lo = sum_call_arg_bytes((c2_node *)call);
  if ((callee_pops == '\0') && ((pcVar1 == (c2_fe_symbol *)0x0 || ((pcVar1->attrs & 0x80) == 0)))) {
    (call->u20).cond_cells = (c2_cond_cell *)0x0;
    if (lo != 0) {
      pcVar2 = operand_new_hardreg(5,0x1004);
      insert_fn = tuple_insert_after;
      src2 = operand_new_intconst(0x1004,lo,(int)lo >> 0x1f);
      pcVar3 = tuple_new_binary(0x2d,0x1004,pcVar2,pcVar2,src2,insert_fn,call);
      return pcVar3;
    }
  }
  else {
    (call->u20).visit_stamp = lo;
    pcVar2 = operand_new_hardreg(5,0x1004);
    tuple_append_dst(call,pcVar2);
  }
  return (c2_tuple *)0x0;
}

