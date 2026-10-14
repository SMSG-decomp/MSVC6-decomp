int __cdecl expr_check_illegal_for_type(c1_u8 op,char form,c1_node *left,c1_node *right)

{
  bool bVar1;
  c1_type *pcVar2;
  int is_left;
  
  if ((left == (c1_node *)0x0) || ((left->type->code & 0x200) == 0)) {
    is_left = 0;
    if ((right->type->code & 0x200) == 0) {
      return 1;
    }
  }
  else {
    is_left = 1;
  }
  bVar1 = expr_builtin_operator_valid_for_class(op,form,is_left);
  if (bVar1) {
    return 1;
  }
  if (is_left == 0) {
    pcVar2 = right->type;
  }
  else {
    pcVar2 = left->type;
  }
  diag_error(0x58,op,pcVar2);
  return 0;
}

