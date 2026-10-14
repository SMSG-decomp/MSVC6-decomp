c2_tuple * __fastcall seh_emit_epilog(c2_tuple *anchor)

{
  c2_symbol *sym;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_fe_symbol *fs;
  c2_insert_fn *insert_fn;
  
  insert_fn = tuple_insert_after;
  sym = symbol_get_part(g_seh_record,0x1004,0,(-(uint)(g_opt_basic != 0) & 0xfffffff8) + 8);
  pcVar1 = operand_new_sym(0x14a,0x1004,sym);
  pcVar2 = operand_new_temp_in_reg(2,0x1004);
  pcVar3 = tuple_new(1,0x1004,pcVar2,pcVar1,insert_fn,anchor);
  fs = extern_symbol_lookup_or_create((uint8_t *)"__except_list");
  pcVar2 = operand_for_fe_symbol(fs);
  pcVar1 = pcVar3->dst;
  pcVar2->flags11 = pcVar2->flags11 & 0xfd | 5;
  pcVar3 = tuple_new(1,0x1004,pcVar2,pcVar1,tuple_insert_after,pcVar3);
  g_seh_record = (c2_symbol *)0x0;
  return pcVar3;
}

