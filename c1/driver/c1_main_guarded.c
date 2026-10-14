int __cdecl c1_main_guarded(int argc,char **argv)

{
  int iVar1;
  void *local_14;
  undefined *puStack_10;
  sehtable_entry *psStack_c;
  int try_level;
  
  psStack_c = &g_main_guarded_scope_table;
  puStack_10 = &_except_handler3;
  local_14 = ExceptionList;
  try_level = 0;
  ExceptionList = &local_14;
  iVar1 = c1_main(argc,argv);
  ExceptionList = local_14;
  return iVar1;
}

