int __fastcall operand_is_const_value(c2_operand *op,int v)

{
  uint64_t uVar1;
  
  if (op->kind == '\a') {
    uVar1 = const_normalize(op->type,v,v >> 0x1f);
    if ((op->u18).reg == (c2_symbol *)uVar1) {
      return 1;
    }
  }
  return 0;
}

