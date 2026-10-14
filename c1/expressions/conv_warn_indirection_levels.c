int __cdecl conv_warn_indirection_levels(c1_u8 op,c1_type *type1,c1_type *type2)

{
  diag_warning(1,0x2f,op,type1,type2);
  return 0;
}

