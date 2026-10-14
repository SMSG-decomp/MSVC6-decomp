c2_tuple * __fastcall
emit_op_before_with_parts(uint32_t op,uint16_t type,c2_operand *a,c2_operand *b,c2_tuple *t)

{
  c2_operand *a_00;
  c2_operand *b_00;
  c2_tuple *pcVar1;
  c2_operand *local_c;
  c2_operand *local_8;
  
  pcVar1 = t;
  a_00 = a;
  local_c = (c2_operand *)0x0;
  local_8 = (c2_operand *)0x0;
  if (a->kind == '\x06') {
    local_c = extract_part_dst_of_mem(t,a,(int *)&a);
  }
  b_00 = b;
  if ((b != (c2_operand *)0x0) && (b->kind == '\x06')) {
    local_8 = extract_part_dst_of_mem(pcVar1,b,(int *)&t);
  }
  if (op == 0x2f) {
    pcVar1 = tuple_new_compare(0x17d,type,a_00,b_00,tuple_insert_before,pcVar1);
    pcVar1->op = 0x2f;
    (pcVar1->dst->u18).reg = g_reg_symbols + 0x42;
  }
  else if (b_00 == (c2_operand *)0x0) {
    pcVar1 = tuple_new_unary_temp(op,type,a_00,tuple_insert_before,pcVar1);
  }
  else {
    pcVar1 = tuple_new_binary_temp(op,type,a_00,b_00,tuple_insert_before,pcVar1);
  }
  if (local_c != (c2_operand *)0x0) {
    tuple_append_dst(pcVar1,local_c);
    local_c->sym->def = pcVar1;
  }
  if (local_8 != (c2_operand *)0x0) {
    tuple_append_dst(pcVar1,local_8);
    local_8->sym->def = pcVar1;
  }
  return pcVar1;
}

