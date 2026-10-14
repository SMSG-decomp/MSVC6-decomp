c1_token * __cdecl pragma_warn_expected_token(uchar want)

{
  c1_u8 cVar1;
  byte bVar2;
  c1_token *token;
  int n;
  void *pvVar3;
  
  token = token_next(&g_token_position);
  cVar1 = token->code;
  while (cVar1 == 0xf2) {
    token = token_next(&g_token_position);
    cVar1 = token->code;
  }
  bVar2 = token->code;
  if (bVar2 == want) {
    return token;
  }
  if (bVar2 == 6) {
    pvVar3 = (token->value).ptr;
    n = 0x53;
  }
  else {
    pvVar3 = (void *)(uint)bVar2;
    n = 0x51;
  }
  diag_warning(1,n,want,pvVar3);
  pragma_skip_to_dash(token);
  return (c1_token *)0x0;
}

