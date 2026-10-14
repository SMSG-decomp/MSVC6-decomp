c2_operand * __fastcall
emit_repne_scasb_strlen
          (c2_tuple *t,c2_operand *str,c2_operand **str_reg,int mode,uint16_t result_type)

{
  int iVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  uint32_t src_alias;
  uint32_t local_c;
  c2_operand *local_8;
  c2_const_operand *local_4;
  
  iVar1 = mode;
  if (mode == 0) {
    local_c = 4;
  }
  else if (mode == 1) {
    local_c = 0x104;
  }
  else {
    local_c = 0x100;
  }
  pcVar2 = lower_value_into_register(t,str,g_reg_symbols + 8);
  *str_reg = pcVar2;
  if (((iVar1 == 2) && (pcVar2 = t->dst, pcVar2 != (c2_operand *)0x0)) && (pcVar2->kind != '\v')) {
    build_fill_pattern(1,0x1004,pcVar2,str_reg,t->prev);
    tuple_remove_dst(t,pcVar2);
  }
  mode = (int)operand_new_temp_in_reg(2,0x1004);
  pcVar3 = build_zero_extend_int64((c2_operand *)mode,t->prev,0xffffffff,1);
  local_8 = operand_new_temp_in_reg(1,0x1004);
  pcVar3 = build_zero_extend_int64(local_8,pcVar3,0,1);
  if (g_opt_global == 0) {
    src_alias = 0;
  }
  else if (iVar1 == 2) {
    src_alias = tuple_second_memeffect_src_value(t);
  }
  else {
    src_alias = tuple_get_memeffect_alias(t);
  }
  pcVar3 = emit_string_insn(0x110,1,str_reg,&local_8,(c2_operand **)&mode,pcVar3,local_c,0,src_alias
                           );
  pcVar2 = operand_new_hardreg(0x48,0x8000);
  tuple_append_dst(pcVar3,pcVar2);
  if (iVar1 != 2) {
    pcVar3 = emit_string_op_step(0x24,0x1004,(c2_operand **)&mode,(c2_operand **)0x0,pcVar3,1);
  }
  if (iVar1 == 0) {
    local_4 = operand_new_intconst(0x1004,0xffffffff,-1);
    emit_string_op_step(0x2d,0x1004,(c2_operand **)&mode,&local_4,pcVar3,1);
  }
  return (c2_operand *)mode;
}

