void __fastcall set_operand_home(c2_operand *op,c2_symbol *sym)

{
  op->kind = '\x01';
  op->op = 0x149;
  (op->u18).reg = sym;
  return;
}

