c2_symbol * __fastcall operand_resolve_part(c2_operand *op)

{
  uint16_t type;
  c2_symbol *pcVar1;
  
  if (op->base_sym == (c2_symbol *)0x0) {
    return (c2_symbol *)op->base;
  }
  type._0_1_ = op->flags;
  type._1_1_ = op->flags11;
  pcVar1 = symbol_get_part(*(c2_symbol **)(*(int *)&op->kind + 0x28),type,(uint32_t)op->base_sym,
                           op->disp - *(int *)(*(int *)&op->kind + 0x24));
  return pcVar1;
}

