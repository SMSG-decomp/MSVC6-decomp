c2_tuple * __fastcall lower_eh_handler_thunk(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_fe_symbol *fs;
  c2_tuple *cond_def;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  
  insert_fn = tuple_insert_after;
  pcVar3 = t;
  pcVar1 = operand_for_symbol_ref(g_ehfuncinfo_symbol);
  pcVar2 = operand_new_hardreg(1,0x1004);
  pcVar3 = tuple_new(1,0x1004,pcVar2,pcVar1,insert_fn,pcVar3);
  insert_fn_00 = tuple_insert_after;
  cond_def = (c2_tuple *)0x0;
  pcVar2 = (c2_operand *)0x0;
  fs = fe_symbol_lookup_name("___CxxFrameHandler");
  pcVar1 = operand_for_symbol_ref(fs);
  tuple_new_branch(0x10,'\0',(c2_node *)pcVar1,pcVar2,cond_def,insert_fn_00,pcVar3);
  t->op = 0x145;
  return t;
}

