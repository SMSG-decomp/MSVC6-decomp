int __cdecl parse_translation_unit(void)

{
  int *stack;
  int iVar1;
  int iVar2;
  uint *dst;
  uint *src;
  uint *src_2;
  uint *dst_2;
  uint saved_state [10];
  void *local_14;
  void *seh_handler;
  void *seh_scope_table;
  int seh_state;
  
  seh_state = -1;
  seh_scope_table = &g_parse_translation_unit_scopetable;
  seh_handler = &_except_handler3;
  local_14 = ExceptionList;
  dst = (uint *)&g_yy_val;
  src_2 = saved_state;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *src_2 = *dst;
    dst = dst + 1;
    src_2 = src_2 + 1;
  }
  ExceptionList = &local_14;
  stack = __2_YAPAXI_Z(0xb018);
  if (stack == (int *)0x0) {
    g_yy_parser = (c1_yy_parser *)0x0;
  }
  else {
    g_yy_parser = parser_stack_construct(stack);
  }
  seh_state = 0;
  iVar1 = yyparse_cpp(g_yy_parser);
  seh_state = -1;
  parse_translation_unit_cleanup((c1_parse_translation_unit_frame *)&stack0xfffffffc);
  src = saved_state;
  dst_2 = (uint *)&g_yy_val;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *dst_2 = *src;
    src = src + 1;
    dst_2 = dst_2 + 1;
  }
  ExceptionList = local_14;
  return iVar1;
}

