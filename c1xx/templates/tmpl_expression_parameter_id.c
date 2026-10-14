short __cdecl tmpl_expression_parameter_id(char *expr,short param_id)

{
  short sVar1;
  char *pcVar2;
  
  pcVar2 = tree_find_template_parameter_use(expr);
  if ((((pcVar2 == (char *)0x0) || (*pcVar2 != 'e')) ||
      (sVar1 = *(short *)(pcVar2 + 0x10), sVar1 == 0)) || ((param_id != 0 && (param_id != sVar1))))
  {
    sVar1 = 0;
  }
  return sVar1;
}

