c2_tuple * __fastcall cxx_eh_emit_epilog(c2_tuple *anchor)

{
  c2_symbol *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_fe_symbol *fs;
  c2_insert_fn *insert_fn;
  
  insert_fn = tuple_insert_after;
  pcVar1 = symbol_get_part(g_cxx_eh_record,0x1004,0,g_cxx_eh_next_offset);
  pcVar2 = operand_new_sym(0x14a,0x1004,pcVar1);
  pcVar3 = operand_new_temp_in_reg(2,0x1004);
  pcVar4 = tuple_new(1,0x1004,pcVar3,pcVar2,insert_fn,anchor);
  fs = extern_symbol_lookup_or_create((uint8_t *)"__except_list");
  pcVar1 = fe_symbol_get_storage(fs);
  pcVar3 = operand_new_sym(0x14b,0x1004,pcVar1);
  pcVar2 = pcVar4->dst;
  pcVar3->flags11 = pcVar3->flags11 & 0xfd | 5;
  pcVar4 = tuple_new(1,0x1004,pcVar3,pcVar2,tuple_insert_after,pcVar4);
  return pcVar4;
}

