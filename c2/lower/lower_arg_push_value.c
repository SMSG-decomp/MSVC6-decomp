c2_operand * __fastcall lower_arg_push_value(c2_tuple *call,c2_operand *op)

{
  byte bVar1;
  c2_tuple *t;
  c2_operand *op_00;
  uint32_t uVar2;
  int iVar3;
  c2_operand *op_01;
  ushort uVar4;
  
  uVar4 = op->type & 0xfff;
  t = op->sym->def;
  if (uVar4 == 2) {
    bVar1 = t->src->kind;
    if (bVar1 != 0) {
      if (bVar1 < 3) {
        iVar3 = operand_readable_as_dword(t->src);
      }
      else {
        iVar3 = g_opt_favor_speed;
        if (bVar1 != 7) goto LAB_1071fd9d;
      }
      if (iVar3 != 0) {
        set_op_width(t,4);
        uVar4 = 4;
      }
    }
  }
LAB_1071fd9d:
  op_00 = retarget_push_value_register(call,op);
  uVar2 = load_op_for_operand(t->src);
  t->op = uVar2;
  if (uVar4 == 8) {
    op_01 = split_int64_operand_half(call,op_00,(c2_operand *)0x0,(c2_operand *)0x0);
    tuple_append_src(call,op_01);
    retarget_push_value_register(call,op_01);
  }
  return op_00;
}

