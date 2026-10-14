int __cdecl format_basic_type_name(int buf,c1_type *type,char declarator_follows)

{
  c1_type **ppcVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  ushort code;
  c1_u16 quals;
  c1_type *pcVar5;
  c1_type *pcVar6;
  int buf_00;
  char *s;
  c1_symbol *pcVar7;
  
  if (buf == 0) {
    buf = format_buffer_alloc();
  }
  uVar4 = type->code;
  if ((uVar4 == 0x80c) || (uVar4 == 0x80e)) {
    return buf;
  }
  pcVar6 = type;
  if ((uVar4 >> 7 & 1) != 0) {
    do {
      pcVar6 = pcVar6->base;
    } while ((char)pcVar6->code < '\0');
  }
  code = pcVar6->code;
  pcVar6 = type;
  if ((uVar4 >> 7 & 1) != 0) {
    do {
      pcVar6 = pcVar6->base;
    } while ((char)pcVar6->code < '\0');
  }
  quals = pcVar6->flags;
  if ((code & 0x2000) != 0) {
    format_buffer_prepend_string(buf,"unsigned ");
  }
  if ((code & 0x1000) != 0) {
    format_buffer_prepend_string(buf,"signed ");
  }
  buf_00 = decorate_cv_text(buf,quals);
  s = type_keyword_text(code);
  format_buffer_append_string(buf_00,s);
  if ((*s != '\0') &&
     ((declarator_follows != '\0' ||
      (((type->code & 0x300) != 0 && ((g_format_omit_tag_keyword & 1) == 0)))))) {
    format_buffer_append_char(buf_00,' ');
  }
  cVar3 = (char)type->code;
  pcVar6 = type;
  cVar2 = cVar3;
  while (cVar2 < '\0') {
    pcVar6 = pcVar6->base;
    cVar2 = (char)pcVar6->code;
  }
  if (((pcVar6->code & 0x300) != 0) &&
     (pcVar5 = type, cVar2 = cVar3, (pcVar6->extra).sym != (c1_symbol *)0x0)) {
    while (cVar2 < '\0') {
      ppcVar1 = &pcVar5->base;
      pcVar5 = *ppcVar1;
      cVar2 = (char)(*ppcVar1)->code;
    }
    if ((pcVar5->code & 0x300) == 0) {
      pcVar7 = (c1_symbol *)0x0;
    }
    else {
      pcVar7 = (pcVar5->extra).sym;
    }
    if (pcVar7->name == g_name_unnamed) {
      while (cVar3 < '\0') {
        type = type->base;
        cVar3 = (char)type->code;
      }
      if ((type->code & 0x300) == 0) {
        pcVar7 = (c1_symbol *)0x0;
      }
      else {
        pcVar7 = (type->extra).sym;
      }
      pcVar6 = pcVar7->type;
      cVar2 = (char)pcVar6->code;
      while (cVar2 < '\0') {
        pcVar6 = pcVar6->base;
        cVar2 = (char)pcVar6->code;
      }
      g_zg_unnamed_tag_keyword = type_keyword_text(pcVar6->code);
      return buf_00;
    }
    while (cVar3 < '\0') {
      type = type->base;
      cVar3 = (char)type->code;
    }
    if ((type->code & 0x300) == 0) {
      pcVar7 = (c1_symbol *)0x0;
    }
    else {
      pcVar7 = (type->extra).sym;
    }
    format_buffer_append_string(buf_00,pcVar7->name->text);
    if (declarator_follows != '\0') {
      format_buffer_append_char(buf_00,' ');
    }
  }
  return buf_00;
}

