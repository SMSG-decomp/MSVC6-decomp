void __cdecl diag_write_fatal_C1063(char enabled)

{
  int iVar1;
  uint *puVar2;
  uint *dst;
  
  if (enabled != '\0') {
    puVar2 = (uint *)"fatal error C1063:\r\n";
    dst = &g_opt_ef;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *dst = *puVar2;
      puVar2 = puVar2 + 1;
      dst = dst + 1;
    }
    *(char *)dst = (char)*puVar2;
    _write(1,&g_opt_ef,0x15);
  }
  c1_cleanup();
  c1_raise_exit(3);
}

