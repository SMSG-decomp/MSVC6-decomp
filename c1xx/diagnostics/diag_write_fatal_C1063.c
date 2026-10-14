void __cdecl diag_write_fatal_C1063(char print_message)

{
  int iVar1;
  char *pcVar2;
  char **ppcVar3;
  
  if (print_message != '\0') {
    pcVar2 = "fatal error C1063:\r\n";
    ppcVar3 = &g_opt_ef;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppcVar3 = *(char **)pcVar2;
      pcVar2 = pcVar2 + 4;
      ppcVar3 = ppcVar3 + 1;
    }
    *(char *)ppcVar3 = *pcVar2;
    _write(1,&g_opt_ef,0x15);
  }
  c1xx_cleanup();
  c1xx_raise_exit(3);
}

