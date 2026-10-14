uchar * __cdecl pragma_warn_expected_token(uchar want)

{
  byte bVar1;
  byte *token;
  int n;
  uint uVar2;
  
  token = token_next((c1_token_reader *)&g_token_position);
  bVar1 = *token;
  while (bVar1 == 0xf2) {
    token = token_next((c1_token_reader *)&g_token_position);
    bVar1 = *token;
  }
  bVar1 = *token;
  if (bVar1 == want) {
    return token;
  }
  if (bVar1 == 6) {
    uVar2 = *(uint *)(token + 8);
    n = 0x53;
  }
  else {
    uVar2 = (uint)bVar1;
    n = 0x51;
  }
  diag_warning(1,n,want,uVar2);
  pragma_skip_to_dash(token);
  return (uchar *)0x0;
}

