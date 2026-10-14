char * __cdecl decorate_name_3(char *out,char *buffer,c1_type *type,char dot_prefix)

{
  char *pcVar1;
  
  if (type->code == 0x4082) {
    type = type_strip_code_variant_bits(type);
  }
  g_decorate_template_arg_backref_count = 0;
  g_decorate_output_base = buffer;
  g_decorate_arg_backref_count = 0;
  g_decorate_name_backref_count = 0;
  if (dot_prefix != '\0') {
    *out = '.';
    out = out + 1;
  }
  pcVar1 = decorate_return_type(out,type,1);
  if (0x7ff < (int)pcVar1 - (int)g_decorate_output_base) {
    diag_warning(1,0x1f7,0x54,type);
    pcVar1 = g_decorate_output_base + 0x7ff;
  }
  *pcVar1 = '\0';
  return pcVar1 + 1;
}

