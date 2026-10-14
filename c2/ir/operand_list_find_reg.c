c2_operand * __fastcall operand_list_find_reg(c2_operand *list,c2_symbol *reg)

{
  for (; (list != (c2_operand *)0x0 && ((list->kind != '\x01' || ((list->u18).reg != reg))));
      list = list->next) {
  }
  return list;
}

