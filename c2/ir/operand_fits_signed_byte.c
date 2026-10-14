int __fastcall operand_fits_signed_byte(c2_operand *op)

{
  byte bVar1;
  
  bVar1 = op->kind;
  if (bVar1 != 0) {
    if (bVar1 < 3) {
      return (op->sym->u30).sizeopt.width_facts >> 1 & 1;
    }
    if (bVar1 == 7) {
      return (uint)((c2_symbol *)(int)*(char *)&op->u18 == (op->u18).reg);
    }
  }
  return 0;
}

