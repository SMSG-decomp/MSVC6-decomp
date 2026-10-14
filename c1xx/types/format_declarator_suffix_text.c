int __cdecl format_declarator_suffix_text(int buf,ushort *type)

{
  char cVar1;
  ushort uVar2;
  char local_50 [80];
  
  if (type == (ushort *)0x0) {
    return buf;
  }
  uVar2 = *type;
  cVar1 = (char)uVar2;
  while (cVar1 < '\0') {
    switch(uVar2 & 0x8f) {
    case 0x80:
    case 0x82:
    case 0x84:
    case 0x86:
    case 0x8a:
    case 0x8e:
      if (uVar2 == 0x4082) {
        format_buffer_append_char(buf,'[');
        format_buffer_append_char(buf,']');
        type = &((c1_type *)type)->base->code;
      }
      else {
        format_pointer_declarator_text(buf,(c1_type *)type);
        type = &((c1_type *)type)->base->code;
        if ((char)((c1_type *)type)->code < '\0') {
          uVar2 = ((c1_type *)type)->code & 0x8f;
          if ((((uVar2 == 0x86) || (uVar2 == 0x82)) || (uVar2 == 0x8a)) || (uVar2 == 0x8e)) {
            format_buffer_append_char(buf,' ');
          }
          else {
            format_buffer_append_char(buf,')');
            format_buffer_prepend_char(buf,'(');
          }
        }
      }
      break;
    case 0x81:
    case 0x85:
      format_buffer_append_char(buf,'(');
      decl_format_parameter_list((void *)buf,(((c1_type *)type)->extra).params,(c1_type *)type);
      format_buffer_append_char(buf,')');
      if ((((((c1_type *)type)->extra).params)->flags & 1) == 0) {
        format_cv_suffix(buf,((((c1_type *)type)->extra).params)->this_type);
      }
      type = &((c1_type *)type)->base->code;
      break;
    case 0x83:
      format_buffer_append_char(buf,'[');
      if ((((c1_type *)type)->extra).cls != (c1_symbol *)0x0) {
        format_snprintf(local_50,"%d",0x50,(((c1_type *)type)->extra).cls);
        format_buffer_append_string(buf,local_50);
      }
      format_buffer_append_char(buf,']');
      type = &((c1_type *)type)->base->code;
    }
    uVar2 = ((c1_type *)type)->code;
    cVar1 = (char)uVar2;
  }
  return buf;
}

