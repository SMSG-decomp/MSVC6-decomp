void __fastcall reader_spill_eh_value(c2_tuple *t)

{
  uint8_t *puVar1;
  c2_operand *new_op;
  c2_tuple *t_00;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  c2_fe_symbol *fs;
  c2_operand *local_4;
  
  pcVar2 = t->dst;
  local_4 = (c2_operand *)t;
  if ((t->type & 0xf000) == 0x5000) {
    fs = fe_symbol_new_local(g_reading_function->scope,6,t->type & 0xfff,1,1,'\x04',0);
    new_op = operand_for_fe_symbol(fs);
  }
  else {
    new_op = operand_new_temp_sym(pcVar2->type);
    puVar1 = &new_op->sym->flags7;
    *puVar1 = *puVar1 | 2;
  }
  t_00 = find_next_use_of_dst(t,&local_4);
  tuple_replace_dst(t,pcVar2,new_op);
  pcVar2 = operand_claim(new_op);
  if (local_4 != (c2_operand *)0x0) {
    pcVar3 = symbol_get_part(pcVar2->sym,local_4->type,local_4->type & 0xfff,0);
    pcVar2->sym = pcVar3;
    pcVar2->type = local_4->type;
    if (t_00 == (c2_tuple *)0x0) {
      tuple_insert_before((c2_tuple *)local_4,(c2_tuple *)pcVar2);
      tuple_unlink((c2_tuple *)local_4);
      node_free((c2_node *)local_4);
      return;
    }
    tuple_replace_src(t_00,local_4,pcVar2);
  }
  return;
}

