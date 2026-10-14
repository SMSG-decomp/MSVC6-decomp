int __cdecl c1xx_main_guarded(int argc,char **argv)

{
  int iVar1;
  void *local_14;
  void *seh_handler;
  c1_seh_scope *seh_scope_table;
  int seh_try_level;
  
  seh_scope_table = &g_main_guarded_scope_table;
  seh_handler = &_except_handler3;
  local_14 = ExceptionList;
  seh_try_level = 0;
  ExceptionList = &local_14;
  iVar1 = c1xx_main(argc,argv);
  ExceptionList = local_14;
  return iVar1;
}

