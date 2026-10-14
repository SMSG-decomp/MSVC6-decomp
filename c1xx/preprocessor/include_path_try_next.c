int __fastcall include_path_try_next(int *iter)

{
  int iVar1;
  c1_u8 *pcVar2;
  
  iVar1 = *iter;
  if (iVar1 != 0) {
    *iter = *(int *)(iVar1 + 0xc);
  }
  iter[2] = iVar1;
  if (iVar1 == 0) {
    return g_token_newline;
  }
  g_compile_flags_cc = g_compile_flags_cc | 0x1000000;
  pcVar2 = pp_include_open_and_push(*(byte **)(*(int *)iter[2] + 4),'\0');
  g_compile_flags_cc = g_compile_flags_cc & 0xfeffffff;
  return (int)pcVar2;
}

