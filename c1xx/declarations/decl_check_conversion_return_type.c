void __thiscall decl_check_conversion_return_type(c1_decl_record *rec,c1xx_decl_specifiers *spec)

{
  int iVar1;
  uint *dst_2;
  uint *dst;
  
  if (rec->spec_type == (c1_type *)0x0) {
    rec->spec_type = spec->type;
    dst_2 = rec->spec;
    for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
      *dst_2 = *(uint *)spec->spec;
      spec = (c1xx_decl_specifiers *)(spec->spec + 4);
      dst_2 = dst_2 + 1;
    }
    return;
  }
  if ((spec->spec[0] & 0x10) == 0) {
    if ((rec->flags & 0x20) != 0) {
      diag_error(0x225);
    }
    rec->flags = rec->flags | 1;
  }
  dst = rec->spec;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *dst = *(uint *)spec->spec;
    spec = (c1xx_decl_specifiers *)(spec->spec + 4);
    dst = dst + 1;
  }
  return;
}

