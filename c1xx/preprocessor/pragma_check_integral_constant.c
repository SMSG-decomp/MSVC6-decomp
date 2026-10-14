int __cdecl pragma_check_integral_constant(void)

{
  c1xx_token *pcVar1;
  
  pcVar1 = pragma_parse_identifier(0x65);
  pragma_expect_dash_token();
  if (pcVar1 != (c1xx_token *)0x0) {
    if ((*(byte *)pcVar1->value & 0x10) != 0) {
      return pcVar1->value2;
    }
    diag_warning(1,0xbc);
  }
  return 0;
}

