c2_tuple * __fastcall
emit_alloca_stack_adjust(c2_operand *size,c2_insert_fn *insert_fn,c2_tuple *anchor)

{
  c2_operand *op;
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_fe_symbol *sym;
  c2_operand *pcVar3;
  char *name;
  uint8_t call_conv;
  c2_insert_fn *insert_fn_00;
  
  op = operand_new_hardreg(5,0x1004);
  if (g_force_stack_probe == 0) {
    if (((int)size->tag <= g_opt_stack_probe_size >> 0x1f) &&
       (((int)size->tag < g_opt_stack_probe_size >> 0x1f ||
        ((size->u18).reg < (uint)g_opt_stack_probe_size)))) {
      pcVar1 = tuple_new_binary(0x32,0x1004,op,op,size,insert_fn,anchor);
      return pcVar1;
    }
  }
  pcVar3 = size;
  insert_fn_00 = insert_fn;
  pcVar1 = anchor;
  pcVar2 = operand_new_hardreg(1,0x1004);
  tuple_new(1,0x1004,pcVar2,pcVar3,insert_fn_00,pcVar1);
  name = "__chkstk";
  if (g_opt_basic != 0) {
    name = "___vbaChkstk";
  }
  call_conv = '\x04';
  sym = fe_symbol_lookup_name(name);
  pcVar3 = operand_new_codeaddr(0x153,sym);
  pcVar2 = operand_new_hardreg(1,0x1004);
  pcVar1 = tuple_new_call(0xe,0x1004,pcVar2,pcVar3,call_conv,insert_fn,anchor);
  pcVar3 = operand_new_hardreg(1,0x1004);
  tuple_append_src(pcVar1,pcVar3);
  tuple_append_src(pcVar1,op);
  tuple_append_dst(pcVar1,op);
  (pcVar1->u20).visit_stamp = -(size->u18).lo;
  return pcVar1;
}

