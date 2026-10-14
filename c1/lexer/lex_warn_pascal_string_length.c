void __cdecl lex_warn_pascal_string_length(c1_string_value *lit)

{
  ushort uVar1;
  
  uVar1 = lit->length - 2;
  if ((uVar1 & 0xff) != uVar1) {
    diag_warning(1,0x3b);
    *lit->text = (char)uVar1;
    return;
  }
  *lit->text = (char)uVar1;
  return;
}

