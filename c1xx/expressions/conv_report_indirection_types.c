int __cdecl conv_report_indirection_types(uint op)

{
  diag_error(0xe6,op & 0xff);
  return 0;
}

