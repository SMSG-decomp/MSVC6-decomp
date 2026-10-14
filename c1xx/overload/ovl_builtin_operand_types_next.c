char __fastcall ovl_builtin_operand_types_next(int *iter)

{
  c1_type *type;
  char cVar1;
  c1_node *pcVar2;
  
  if (*(char *)((int)iter + 9) == '\0') {
    if (((c1_node *)*iter != (c1_node *)0x0) &&
       (((char)iter[2] == '\0' ||
        (pcVar2 = expr_lvalue_address((c1_node *)*iter,0), pcVar2 != (c1_node *)0x0)))) {
      type = *(c1_type **)(*iter + 4);
      iter[9] = (int)type;
      *iter = 0;
      cVar1 = ovl_type_matches_builtin_pattern(type,(c1_type *)iter[1],(char)iter[2],'\0');
      return cVar1;
    }
  }
  else {
    cVar1 = ovl_conversion_types_next((c1_conversion_type_iter *)(iter + 3));
    while (cVar1 != '\0') {
      cVar1 = ovl_type_matches_builtin_pattern
                        ((c1_type *)iter[7],(c1_type *)iter[1],(char)iter[2],'\x01');
      if (cVar1 != '\0') {
        iter[9] = iter[7];
        return '\x01';
      }
      cVar1 = ovl_conversion_types_next((c1_conversion_type_iter *)(iter + 3));
    }
  }
  return '\0';
}

