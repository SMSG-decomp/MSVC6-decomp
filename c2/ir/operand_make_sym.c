c2_operand * __fastcall operand_make_sym(c2_operand *op)

{
  (op->u18).reg = (c2_symbol *)0x0;
  op->kind = '\x02';
  op->op = g_symclass_operand_op[op->sym->cls];
  return op;
}

