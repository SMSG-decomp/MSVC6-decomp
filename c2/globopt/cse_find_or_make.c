c2_symbol * __fastcall cse_find_or_make(uint32_t op,uint16_t type,c2_operand *a,c2_operand *b)

{
  int iVar1;
  c2_symbol *pcVar2;
  
  iVar1 = is_compare_branch_op(op);
  if (iVar1 == 0) {
    cse_set_key_operands(2,a,b);
    pcVar2 = (c2_symbol *)cse_find_or_insert(op,type);
    return pcVar2;
  }
  pcVar2 = get_compare_expression_symbol(op,type,a,b);
  return pcVar2;
}

