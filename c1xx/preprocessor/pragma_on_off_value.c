void __cdecl pragma_on_off_value(void)

{
  int iVar1;
  byte *token;
  c1_u8 *pcVar2;
  uchar *puVar3;
  
  token = token_next((c1_token_reader *)&g_token_position);
  if (*token == 0x37) {
    pcVar2 = pragma_check_on_off();
    if (pcVar2 != (c1_u8 *)0x0) {
      iVar1 = *(int *)(pcVar2 + 8);
      puVar3 = pragma_warn_expected_token('~');
      if ((puVar3 != (uchar *)0x0) && (g_minimal_rebuild != '\0')) {
        if (iVar1 == 0) {
          g_minimal_rebuild_tracker->current->minrebuild_off = 1;
          return;
        }
        g_minimal_rebuild_tracker->current->minrebuild_off = 0;
      }
    }
  }
  else if (*token != 0x7e) {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token);
    pragma_warn_expected_token('7');
    return;
  }
  return;
}

