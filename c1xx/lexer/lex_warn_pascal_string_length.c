void __cdecl lex_warn_pascal_string_length(int *lit)

{
  ushort uVar1;
  
  uVar1 = (short)lit[1] - 2;
  if ((uVar1 & 0xff) != uVar1) {
    diag_warning(1,0x3b);
    *(char *)*lit = (char)uVar1;
    return;
  }
  *(char *)*lit = (char)uVar1;
  return;
}

