c1xx_token * __cdecl token_static_for_code(uint code)

{
  return (c1xx_token *)(&g_token_static_records)[code & 0xff];
}

