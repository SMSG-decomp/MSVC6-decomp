int __cdecl conv_report_indirection_levels(uint op,c1_type *type,c1_type *type2)

{
  diag_error(0x28,0x4c,op & 0xff,type,type2);
  return 0;
}

