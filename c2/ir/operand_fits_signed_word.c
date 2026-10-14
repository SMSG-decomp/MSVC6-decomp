int __fastcall operand_fits_signed_word(c2_operand *op)

{
  byte bVar1;
  
  bVar1 = op->kind;
  if (bVar1 != 0) {
    if (bVar1 < 3) {
      return (op->sym->u30).sizeopt.width_facts & 1;
    }
    if (bVar1 == 7) {
      return (uint)((c2_symbol *)(int)*(short *)&op->u18 == (op->u18).reg);
    }
  }
  return 0;
}

