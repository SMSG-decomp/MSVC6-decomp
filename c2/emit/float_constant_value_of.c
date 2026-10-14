c2_float_const * __fastcall float_constant_value_of(c2_operand *op)

{
  uint8_t uVar1;
  c2_float_const *pcVar2;
  
  if (op->kind == 9) {
    return (c2_float_const *)op->sym;
  }
  if ((1 << (op->kind & 0x1f) & 6U) != 0) {
    uVar1 = op->sym->cls;
    if ((uVar1 == '\a') || (uVar1 == '\b')) {
      pcVar2 = float_constant_pool_lookup(op->sym->fe);
      return pcVar2;
    }
  }
  return (c2_float_const *)0x0;
}

