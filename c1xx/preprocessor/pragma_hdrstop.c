void __cdecl pragma_hdrstop(char **name)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar1 = token_next((c1_token_reader *)&g_token_position);
  if (*pbVar1 == 0x2d) {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar1);
    return;
  }
  if (*pbVar1 == 0x76) {
    g_compile_flags_c4 = g_compile_flags_c4 | 0x2000;
    pbVar1 = token_next((c1_token_reader *)&g_token_position);
    g_compile_flags_c4 = g_compile_flags_c4 & 0xffffdfff;
    if (*pbVar1 == 7) {
      if ((name != (char **)0x0) && (*name == (char *)0x0)) {
        pbVar1 = (byte *)_strdup(*(char **)(pbVar1 + 8));
        iVar2 = isspace((uint)*pbVar1);
        while (iVar2 != 0) {
          pbVar1 = pbVar1 + 1;
          iVar2 = isspace((uint)*pbVar1);
        }
        pbVar3 = str_find_trailing_space(pbVar1,(byte *)0x0);
        *pbVar3 = 0;
        *name = (char *)pbVar1;
      }
      pbVar1 = token_next((c1_token_reader *)&g_token_position);
      if (*pbVar1 == 0x7e) {
        return;
      }
    }
    else if (*pbVar1 == 0x7e) {
      return;
    }
  }
  diag_error(0x356);
  pragma_skip_to_dash(pbVar1);
  return;
}

