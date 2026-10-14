c1_type * __cdecl decl_basic_type_from_specifiers_fragment(c1_u16 code)

{
  c1_type *pcVar1;
  c1_type *pcStack00000004;
  c1_type_x08 cStack00000008;
  c1_u32 cStack0000000c;
  
  pcStack00000004 = (c1_type *)0x0;
  cStack0000000c = 0;
  cStack00000008.sym = (c1_symbol *)0x0;
  pcVar1 = type_intern((c1_type *)&stack0x00000000);
  return pcVar1;
}

