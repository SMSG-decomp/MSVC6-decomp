void __fastcall operand_set_fresh_temp(c2_operand *op)

{
  c2_symbol *pcVar1;
  
  pcVar1 = symbol_new_temp(op->type);
  op->sym = pcVar1;
  (op->u18).reg = pcVar1;
  return;
}

