void __fastcall insert_penter_call(c2_function *fn)

{
  ushort uVar1;
  c2_tuple *pcVar2;
  c2_fe_symbol *sym;
  c2_operand *pcVar3;
  c2_operand *dst;
  uint8_t call_conv;
  c2_insert_fn *insert_fn;
  
  if ((g_cur_func_sym->attrs & 0x400) == 0) {
    pcVar2 = find_tuple_of_kind(fn->cfg->first->head,'\x17');
    uVar1 = pcVar2->line;
    if (uVar1 != 0) {
      g_current_line_abs = fn->line_base + (uint)uVar1;
      g_cur_line = uVar1;
    }
    insert_fn = tuple_insert_after;
    call_conv = '\x04';
    sym = fe_symbol_lookup_name("__penter");
    pcVar3 = operand_new_codeaddr(0x153,sym);
    dst = operand_new_hardreg(1,0x1004);
    pcVar2 = tuple_new_call(0xe,0x1004,dst,pcVar3,call_conv,insert_fn,pcVar2);
    pcVar3 = operand_new_hardreg(5,0x1004);
    tuple_append_src(pcVar2,pcVar3);
    pcVar3 = operand_new_hardreg(5,0x1004);
    tuple_append_dst(pcVar2,pcVar3);
    pcVar3 = operand_new_hardreg(0x42,0x8000);
    tuple_append_dst(pcVar2,pcVar3);
  }
  return;
}

