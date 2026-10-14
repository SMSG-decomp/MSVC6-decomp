c2_operand * __fastcall
emit_load_into_register(uint32_t op,c2_tuple *t,c2_operand *src,c2_register_descriptor *reg)

{
  c2_tuple *t_00;
  c2_operand *pcVar1;
  uint16_t type;
  
  type = src->type;
  if (op == 1) {
    op = load_op_for_operand(src);
    if ((op == 0x12) && (t->op == 0x12)) {
      t->op = 1;
    }
  }
  else if (op == 0xc4) {
    type = 0x1004;
  }
  if ((((1 << (src->kind & 0x1f) & 0x18U) != 0) || (src->kind == 5)) && ((src->type & 0xfff) < 4)) {
    src = (c2_operand *)node_clone((c2_node *)src);
    type = 0x1004;
    src->type = 0x1004;
  }
  t_00 = emit_op_before_with_parts(op,type,src,(c2_operand *)0x0,t);
  if ((op == 0x7f) || (op == 0x94)) {
    tuple_remove_src(t_00,t_00->src);
  }
  pcVar1 = t_00->dst;
  if (reg->id != 0) {
    (pcVar1->u18).reg = reg;
  }
  if ((4 < (t_00->type & 0xfff)) && (op == 1)) {
    pcVar1 = (c2_operand *)node_clone((c2_node *)pcVar1);
    lower_int64_tuple(t_00);
    return pcVar1;
  }
  tuple_legalize_mem_operands(t_00);
  return pcVar1;
}

