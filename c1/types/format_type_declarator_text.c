int __cdecl format_type_declarator_text(int buf,c1_type *type)

{
  char cVar1;
  ushort uVar2;
  char local_50 [80];
  
  if (type != (c1_type *)0x0) {
    uVar2 = type->code;
    cVar1 = (char)uVar2;
    while (cVar1 < '\0') {
      switch(uVar2 & 0x8f) {
      case 0x81:
      case 0x85:
        format_buffer_append_char(buf,'(');
        format_parameter_list_text(buf,(int *)(type->extra).sym);
        format_buffer_append_char(buf,')');
        type = type->base;
        break;
      case 0x82:
      case 0x86:
        if (uVar2 == 0x4082) {
          format_buffer_append_char(buf,'[');
          format_buffer_append_char(buf,']');
          type = type->base;
        }
        else {
          format_pointer_layer_text(buf,type);
          type = type->base;
          if ((char)type->code < '\0') {
            uVar2 = type->code & 0x8f;
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
      case 0x83:
        format_buffer_append_char(buf,'[');
        if ((type->extra).sym != (c1_symbol *)0x0) {
          format_snprintf(local_50,"%d",0x50,(type->extra).sym);
          format_buffer_append_string(buf,local_50);
        }
        format_buffer_append_char(buf,']');
        type = type->base;
      }
      uVar2 = type->code;
      cVar1 = (char)uVar2;
    }
    return buf;
  }
  return buf;
}

