void __fastcall cxx_eh_emit_handler_thunk(c2_function *fn)

{
  c2_fe_symbol *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  code *insert_fn_00;
  c2_tuple *pos;
  c2_insert_fn *insert_fn;
  
  for (pos = fn->cfg->last->end; (pos != (c2_tuple *)0x0 && (pos->kind != '\x18')); pos = pos->prev)
  {
  }
  pcVar1 = get_ehhandler_symbol();
  pcVar2 = tuple_new_label(pcVar1);
  tuple_insert_before(pos,pcVar2);
  g_current_line_abs = 0;
  insert_fn = tuple_insert_before;
  g_cur_line = 0;
  pcVar2 = pos;
  pcVar3 = operand_for_symbol_ref(g_ehfuncinfo_symbol);
  pcVar4 = operand_new_hardreg(1,0x1004);
  tuple_new(1,0x1004,pcVar4,pcVar3,insert_fn,pcVar2);
  insert_fn_00 = tuple_insert_before;
  pcVar2 = (c2_tuple *)0x0;
  pcVar4 = (c2_operand *)0x0;
  pcVar1 = fe_symbol_lookup_name("___CxxFrameHandler");
  pcVar3 = operand_for_symbol_ref(pcVar1);
  tuple_new_branch(0x10,'\0',(c2_node *)pcVar3,pcVar4,pcVar2,insert_fn_00,pos);
  g_cxx_eh_record = (c2_symbol *)0x0;
  g_ehfuncinfo_symbol = (c2_fe_symbol *)0x0;
  g_cxx_eh_prolog_emitted = 0;
  return;
}

