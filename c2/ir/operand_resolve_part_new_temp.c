c2_symbol * __fastcall operand_resolve_part_new_temp(c2_operand *op)

{
  uint16_t type;
  int iVar1;
  c2_symbol *pcVar2;
  
  iVar1 = *(int *)&op->kind;
  if (*(int *)(iVar1 + 0x28) == 0) {
    pcVar2 = symbol_new_temp(*(uint16_t *)(iVar1 + 0x10));
    *(c2_symbol **)(iVar1 + 0x28) = pcVar2;
  }
  if (op->base_sym == (c2_symbol *)0x0) {
    return *(c2_symbol **)(iVar1 + 0x28);
  }
  type._0_1_ = op->flags;
  type._1_1_ = op->flags11;
  pcVar2 = symbol_get_part(*(c2_symbol **)(iVar1 + 0x28),type,(uint32_t)op->base_sym,
                           op->disp - *(int *)(iVar1 + 0x24));
  return pcVar2;
}

