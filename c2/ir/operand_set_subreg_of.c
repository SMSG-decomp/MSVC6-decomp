void __fastcall operand_set_subreg_of(c2_operand *op,c2_symbol *reg)

{
  c2_symbol *pcVar1;
  
  pcVar1 = reg_find_subreg(reg,(op->type & 0xfff) << 3,0);
  (op->u18).reg = pcVar1;
  return;
}

