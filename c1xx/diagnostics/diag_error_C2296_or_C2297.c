void __cdecl diag_error_C2296_or_C2297(c1_u8 op,int operand,c1_type *type)

{
  diag_error((operand != 1) + 0x128,op,type);
  return;
}

