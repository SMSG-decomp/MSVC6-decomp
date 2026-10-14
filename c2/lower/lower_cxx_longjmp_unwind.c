c2_tuple * __fastcall
lower_cxx_longjmp_unwind(c2_tuple *t,c2_operand **fn,c2_operand **next,c2_operand **info)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  c2_symbol *sym;
  c2_fe_symbol *fs;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  
  insert_fn = tuple_insert_after;
  pcVar1 = operand_for_symbol_ref(g_ehfuncinfo_symbol);
  pcVar2 = tuple_new_unary_temp(0x15a,0x1004,pcVar1,insert_fn,t);
  pcVar1 = (c2_operand *)node_clone((c2_node *)pcVar2->dst);
  *info = pcVar1;
  lower_tuple(pcVar2);
  insert_fn = tuple_insert_after;
  sym = symbol_get_part(g_cxx_eh_record,0x1004,0,g_cxx_eh_next_offset + 8);
  pcVar1 = operand_new_sym(0x14a,0x1004,sym);
  pcVar2 = tuple_new_unary_temp(0x15a,0x1004,pcVar1,insert_fn,pcVar2);
  pcVar2->src->flags = pcVar2->src->flags | 0x40;
  pcVar1 = (c2_operand *)node_clone((c2_node *)pcVar2->dst);
  *next = pcVar1;
  lower_tuple(pcVar2);
  insert_fn_00 = tuple_insert_after;
  fs = fe_symbol_lookup_name("___CxxLongjmpUnwind@4");
  pcVar1 = operand_for_symbol_ref(fs);
  pcVar2 = tuple_new_unary_temp(0x15a,0x1004,pcVar1,insert_fn_00,pcVar2);
  pcVar1 = (c2_operand *)node_clone((c2_node *)pcVar2->dst);
  *fn = pcVar1;
  lower_tuple(pcVar2);
  return pcVar2;
}

