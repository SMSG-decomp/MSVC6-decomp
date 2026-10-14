int _InvokeCompilerPass_12(int argc,char **argv,char last_in_batch)

{
  int iVar1;
  int iVar2;
  
  iVar1 = c1xx_reset_data_section();
  if (iVar1 == 0) {
    g_last_in_batch = last_in_batch;
    iVar1 = c1xx_main_guarded(argc,argv);
    iVar2 = c1xx_run_exit_handlers();
    if (iVar2 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

