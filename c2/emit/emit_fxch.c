void __fastcall emit_fxch(c2_tuple *anchor,uint16_t type)

{
  c2_operand *src;
  c2_operand *dst;
  c2_symbol **below_slot;
  c2_insert_fn *insert_fn;
  c2_symbol *top_sym;
  
  insert_fn = tuple_insert_before;
  src = operand_new_hardreg(0x20,type);
  dst = operand_new_hardreg(0x1f,type);
  tuple_new(0x5f,type,dst,src,insert_fn,anchor);
  top_sym = g_fp_lower_stack_syms[g_fp_lower_depth];
  below_slot = (c2_symbol **)(&g_fp_lower_depth + g_fp_lower_depth);
  g_fp_lower_stack_syms[g_fp_lower_depth] = (c2_symbol *)(&g_fp_lower_depth)[g_fp_lower_depth];
  *below_slot = top_sym;
  return;
}

