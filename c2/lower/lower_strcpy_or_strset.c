void __fastcall lower_strcpy_or_strset(c2_tuple *t,c2_operand **args,int is_strset)

{
  c2_tuple *pcVar1;
  c2_operand *dst;
  c2_operand *dst_00;
  c2_operand *op;
  c2_operand *local_10;
  c2_operand *local_c;
  c2_operand *local_8;
  c2_tuple *local_4;
  
  local_4 = t;
  if (is_strset == 0) {
    op = args[1];
    local_10 = op;
  }
  else {
    local_10 = *args;
    op = args[1];
    pcVar1 = op->sym->def;
    if ((pcVar1->type & 0xfff) != 1) {
      set_op_width(pcVar1,1);
    }
    operand_retype(op,0x1001,0);
  }
  local_c = emit_repne_scasb_strlen(t,local_10,&local_8,1,0);
  pcVar1 = emit_string_op_step(0x32,0x1004,&local_8,&local_c,t->prev,2);
  if (is_strset == 0) {
    pcVar1 = tuple_new_unary_temp(1,0x1004,local_8,tuple_insert_after,pcVar1);
    op = pcVar1->dst;
    dst_00 = *args;
  }
  else {
    local_10 = operand_new_intconst(0x1004,0xffffffff,-1);
    pcVar1 = emit_string_op_step(0x2d,0x1004,&local_c,&local_10,pcVar1,1);
    dst_00 = local_8;
  }
  dst = operand_new_temp(0x1004);
  build_fill_pattern(1,0x1004,dst,&local_c,pcVar1);
  emit_string_block_op(0,local_c,dst,dst_00,op,1,(c2_operand *)0x0,1,is_strset,1,1,local_4,0);
  return;
}

